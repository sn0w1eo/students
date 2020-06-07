#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"

#include "phonebook.h"
#include "memory.h"

//====================================================РАБОТА С МАССИВОМ phoneBook====================================================

//Добавить новый контакт.
PhoneBook* AddContact(PhoneBook* phoneBook, const string name, const string phoneNumber, const string email, const string zip)
{
	PhoneBook* freeSlot = NULL;

	//Проверить корректность аргументов
	if (CheckArguments(phoneBook, name, phoneNumber, email) == False)
	{
		printf("Invalid arguments!");
		return phoneBook;
	}

	switch (IsFreeSpace(phoneBook))             //Проверить есть ли свободное место.
	{
	case True:                                  //Если есть,
		freeSlot = GetFreeSpace(phoneBook);     //то получить адресс ячейки в которую можно записать новые данные.
		break;
	case False:                                 //Если нету,
		phoneBook = ReallocMemory(phoneBook);   //то перераспределить память
		freeSlot = GetFreeSpace(phoneBook);     //и затем получить адресс ячейки в которую можно записать новые данные.
		break;
	}

	//Записать новые данные.
	SetName(freeSlot, name);
	SetPhoneNumber(freeSlot, phoneNumber);
	SetEmail(freeSlot, email);
	SetZipCode(freeSlot, zip);

	return phoneBook;
}

void UpdateContact(PhoneBook* phoneBook, const string name, const string phoneNumber, const string email, const string zip, const int contactIndex)
{
	if (CheckArguments(phoneBook, name, phoneNumber, email) == False)
	{
		printf("Invalid arguments!");
		return;
	}

	FreeContactMemory(phoneBook, contactIndex);

	//Обновить данные в полях структуры.
	SetName(&phoneBook[contactIndex], name);
	SetPhoneNumber(&phoneBook[contactIndex], phoneNumber);
	SetEmail(&phoneBook[contactIndex], email);
	SetZipCode(&phoneBook[contactIndex], zip);
}

//Удалить контакты.
void DeleteContacts(PhoneBook* phoneBook, int argumentsCount, ...)
{
	int contactIndex;
	int size = GetSize(phoneBook);;

	va_list vl;
	va_start(vl, argumentsCount);                         //Установить указатель на первый аргумент.
	while (argumentsCount--)
	{
		contactIndex = va_arg(vl, int);                   //Получить значение аргумента.
		if (contactIndex >= size || contactIndex < 0)     //Защита от выхода за границы доступной памяти.
		{
			continue;
		}
		FreeContactMemory(phoneBook, contactIndex);
		SetName(&phoneBook[contactIndex], NULL);          //Очистить имя.
		SetPhoneNumber(&phoneBook[contactIndex], NULL);   //Очистить номер телефона.
		SetEmail(&phoneBook[contactIndex], NULL);         //Очистить email.
		SetZipCode(&phoneBook[contactIndex], NULL);       //Очистить zipcode.
	}
	va_end(vl);
}

int GetContactsCount(PhoneBook* phoneBook)
{
	int contactsCounter = 0;
	for (int i = 0; i < GetSize(phoneBook); i++)
	{
		if (phoneBook[i].name != NULL)
		{
			contactsCounter++;
		}
	}
	return contactsCounter;
}

//Отобразить все контакты.
void PrintContacts(PhoneBook* phoneBook)
{
	int size = GetSize(phoneBook);

	for (int i = 0; i < size; i++)
	{
		//Пропустить итерацию если поле в структуре содержит NULL.
		if (GetName(phoneBook[i]) == NULL)
		{
			continue;
		}
		else
		{
			printf(" %15s ", GetName(phoneBook[i]));
			printf(" %15s ", GetPhoneNumber(phoneBook[i]));
			printf(" %10s ", GetEmail(phoneBook[i]));
			printf("\t%5s \n\n", GetZipCode(phoneBook[i]));
		}
	}
}

//====================================================СОРТИРОВКА=================================================

int AscendingCompareByName(void *a, void *b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook1->name, ptrBook2->name);
}

int AscendingCompareByPhoneNumber(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook1->phoneNumber, ptrBook2->phoneNumber);
}

int AscendingCompareByEmail(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook1->email, ptrBook2->email);
}

int AscendingCompareByZipCode(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook1->zip, ptrBook2->zip);
}

int DiscendingCompareByName(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook2->name, ptrBook1->name);
}

int DiscendingCompareByPhoneNumber(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook2->phoneNumber, ptrBook1->phoneNumber);
}

int DiscendingCompareByEmail(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook2->email, ptrBook1->email);
}

int DiscendingCompareByZipCode(void* a, void* b)
{
	const PhoneBook* ptrBook1 = a;
	const PhoneBook* ptrBook2 = b;

	return strcmp(ptrBook2->zip, ptrBook1->zip);
}

//====================================================ГЕТТЕРЫ====================================================

//Найти свободное место для записи новых данных.
PhoneBook* GetFreeSpace(PhoneBook* phoneBook)
{
	int size = GetSize(phoneBook);

	int index = 0;
	for (; index < size; index++)
	{
		//Если в поле структуры содержит NULL, значит ячейка структуры свободна.
		if (GetName(phoneBook[index]) == NULL)
		{
			break;
		}
	}

	return &phoneBook[index];
}

int GetSize(PhoneBook* phoneBook)
{
	return *((char*)phoneBook - sizeof(int));
}

//Получить данные с поля name.
string GetName(const PhoneBook phoneBook)
{
	return phoneBook.name;
}

//Получить данные с поля phoneNumber.
string GetPhoneNumber(const PhoneBook phoneBook)
{
	return phoneBook.phoneNumber;
}

//Получить данные с поля email.
string GetEmail(const PhoneBook phoneBook)
{
	return phoneBook.email;
}

//Получить данные с поля zip.
string GetZipCode(const PhoneBook phoneBook)
{
	return phoneBook.zip;
}

//====================================================СЕТТЕРЫ====================================================

void SetSize(PhoneBook* phoneBook, const int size)
{
	*(int*)phoneBook = size;
}

//Установить новое имя в поле структуры name.
void SetName(PhoneBook* phoneBook, const string name)
{
	phoneBook->name = _strdup(name);
}

//Установить новый номер телефона в поле структуры phoneNumber.
void SetPhoneNumber(PhoneBook* phoneBook, const string phoneNumber)
{
	phoneBook->phoneNumber = _strdup(phoneNumber);
}

//Установить новый email в поле структуры email.
void SetEmail(PhoneBook* phoneBook, const string email)
{
	phoneBook->email = _strdup(email);
}

//Установить новый zipcode в поле структуры zip.
void SetZipCode(PhoneBook* phoneBook, const string zipCode)
{
	phoneBook->zip = _strdup(zipCode);
}

//====================================================ЧЕКЕРЫ====================================================

//Проверить корректность аргументов.
int CheckArguments(PhoneBook* phoneBook, const string name, const string phoneNumber, const string email)
{
	if (phoneBook == NULL)
	{
		return False;
	}
	else if (name == NULL)
	{
		return False;
	}
	else if (phoneNumber == NULL)
	{
		return False;
	}
	else if (email == NULL)
	{
		return False;
	}
	else
	{
		return True;
	}
}

//Проверить если ли место.
int IsFreeSpace(PhoneBook* phoneBook)
{
	int size = GetSize(phoneBook);

	int counter = 0;
	for (; counter < size; counter++)
	{
		if (GetName(phoneBook[counter]) == NULL)
		{
			return True;
		}
	}

	//Если цикл завершился, значит мест больше нет.
	return False;
}
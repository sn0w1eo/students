#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"



//Добавить новый контакт.
PHONEBOOK* AddContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const ulong zip)
{	
	PHONEBOOK* freeSlot = NULL;

	//Проверить корректность аргументов
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return phoneBook;
	}

	switch (IsFreeSpace(phoneBook))              //Проверить есть ли свободное место.
	{
	case TRUE:                                  //Если есть,
		freeSlot = GetFreeSpace(phoneBook);     //то получить адресс ячейки в которую можно записать новые данные.
		break;
	case FALSE:                                 //Если нету,
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

//Проверить если ли место.
int IsFreeSpace(PHONEBOOK* phoneBook)
{
	int counter = 0;

	for (; counter < phoneBook->size; counter++)
	{
		if (phoneBook[counter].name == NULL)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//Найти свободное место для записи новых данных.
PHONEBOOK* GetFreeSpace(PHONEBOOK* phoneBook)
{
	int counter = 0;
	for (; counter < phoneBook->size; counter++)
	{
		if (phoneBook[counter].name == NULL)
		{
			break;
		}
	}
	return &phoneBook[counter];
}

void UpdateContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const ulong zip, const int contactIndex)
{
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return;
	}

	SetName(&phoneBook[contactIndex], name);
	SetPhoneNumber(&phoneBook[contactIndex], phoneNumber);
	SetEmail(&phoneBook[contactIndex], email);
	SetZipCode(&phoneBook[contactIndex], zip);
}

void DeleteContact(PHONEBOOK* phoneBook, int contactIndex)
{
	SetName(&phoneBook[contactIndex], NULL);
	SetPhoneNumber(&phoneBook[contactIndex], NULL);
	SetEmail(&phoneBook[contactIndex], NULL);
	SetZipCode(&phoneBook[contactIndex], 0);
}

//Установить новое имя в поле структуры name.
void SetName(PHONEBOOK* phoneBook, const string name)
{
	phoneBook->name = _strdup(name);
}

//Установить новый номер телефона в поле структуры phoneNumber.
void SetPhoneNumber(PHONEBOOK* phoneBook, const string phoneNumber)
{
	phoneBook->phoneNumber = _strdup(phoneNumber);
}

//Установить новый email в поле структуры email.
void SetEmail(PHONEBOOK* phoneBook, const string email)
{
	phoneBook->email = _strdup(email);
}

//Установить новый zipcode в поле структуры zip.
void SetZipCode(PHONEBOOK* phoneBook, const ulong zipCode)
{
	phoneBook->zip = zipCode;
}

//Получить данные с поля name.
string GetName(const PHONEBOOK phoneBook)
{
	return phoneBook.name;
}

//Получить данные с поля phoneNumber.
string GetPhoneNumber(const PHONEBOOK phoneBook)
{
	return phoneBook.phoneNumber;
}

//Получить данные с поля email.
string GetEmail(const PHONEBOOK phoneBook)
{
	return phoneBook.email;
}

//Получить данные с поля zip.
ulong GetZipCode(const PHONEBOOK phoneBook)
{
	return phoneBook.zip;
}

//Проверить корректность аргументов.
int CheckArguments(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email)
{
	if (phoneBook == NULL)
	{
		return FALSE;
	}
	else if (name == NULL)
	{
		return FALSE;
	}
	else if (phoneNumber == NULL)
	{
		return FALSE;
	}
	else if (email == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

//Отобразить все контакты
void PrintContacts(PHONEBOOK* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		else
		{
			printf(" %15s ", GetName(phoneBook[i]));
			printf(" %15s ", GetPhoneNumber(phoneBook[i]));
			printf(" %10s ", GetEmail(phoneBook[i]));
			printf("\t%5lld \n\n", GetZipCode(phoneBook[i]));
		}
	}
}

//Поиск по имени
PHONEBOOK** FindByName(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string name)
{
	
	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].name, name) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//Поиск по номеру телефона
PHONEBOOK** FindByPhoneNumber(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string phoneNumber)
{

	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].phoneNumber, phoneNumber) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//Поиск по email
PHONEBOOK** FindByEmail(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string email)
{
	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].email, email) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//Поиск по zipcode
PHONEBOOK** FindByZipCode(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, ulong zip)
{

	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (phoneBook[i].zip == zip)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//Отобразить найденные контакты
void PrintSeachResults(PHONEBOOK** searchBook, int size)
{
	for (int counter = 0; counter < size; counter++)
	{
		if (searchBook[counter] == NULL)
		{
			continue;
		}
		printf(" %15s ", GetName(*searchBook[counter]));
		printf(" %15s ", GetPhoneNumber(*searchBook[counter]));
		printf(" %10s ", GetEmail(*searchBook[counter]));
		printf("\t%5lld \n\n", GetZipCode(*searchBook[counter]));
	}
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"

#include "phonebook.h"
#include "memory.h"

//Добавить новый контакт.
PHONEBOOK* AddContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const string zip)
{	
	PHONEBOOK* freeSlot = NULL;
	
	//Проверить корректность аргументов
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return phoneBook;
	}

	switch (IsFreeSpace(phoneBook))             //Проверить есть ли свободное место.
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
	int size = GetSize(*phoneBook);

	int counter = 0;
	for (; counter < size; counter++)
	{
		if (GetName(phoneBook[counter]) == NULL)
		{
			return TRUE;
		}
	}
	//Если цикл завершился, значит мест больше нет.
	return FALSE;
}

//Найти свободное место для записи новых данных.
PHONEBOOK* GetFreeSpace(PHONEBOOK* phoneBook)
{
	int size = GetSize(*phoneBook);

	int counter = 0;
	for (; counter < size; counter++)
	{
		//Если в поле структуры содержит NULL, значит ячейка структуры свободна.
		if (GetName(phoneBook[counter]) == NULL)
		{
			break;
		}
	}

	return &phoneBook[counter];
}

void UpdateContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const string zip, const int contactIndex)
{
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return;
	}
	//Обновить данные в полях структуры.
	SetName(&phoneBook[contactIndex], name);
	SetPhoneNumber(&phoneBook[contactIndex], phoneNumber);
	SetEmail(&phoneBook[contactIndex], email);
	SetZipCode(&phoneBook[contactIndex], zip);
}

//Удалить контакты.
void DeleteContacts(PHONEBOOK* phoneBook, int argumentsCount, ...)
{
	int contactIndex;
	int size = GetSize(*phoneBook);;
	
	va_list vl;
	va_start(vl, argumentsCount);                         //Установить указатель на первый аргумент.
	while (argumentsCount--)
	{
		contactIndex = va_arg(vl, int);                   //Получить значение аргумента.
		if (contactIndex >= size || contactIndex < 0)     //Защита от выхода за границы доступной памяти.
		{
			continue;
		}
		SetName(&phoneBook[contactIndex], NULL);          //Очистить имя.
		SetPhoneNumber(&phoneBook[contactIndex], NULL);   //Очистить номер телефона.
		SetEmail(&phoneBook[contactIndex], NULL);         //Очистить email.
		SetZipCode(&phoneBook[contactIndex], NULL);       //Очистить zipcode.
	}
	va_end(vl);
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
void SetZipCode(PHONEBOOK* phoneBook, const string zipCode)
{
	phoneBook->zip = _strdup(zipCode);
}

void SetSize(PHONEBOOK* phoneBook, const int size)
{
	phoneBook->size = size;
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
string GetZipCode(const PHONEBOOK phoneBook)
{
	return phoneBook.zip;
}

//Получить данные с поля size.
int GetSize(const PHONEBOOK phoneBook)
{
	return phoneBook.size;
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

//Отобразить все контакты.
void PrintContacts(PHONEBOOK* phoneBook)
{
	int size = GetSize(*phoneBook);

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

//Поиск по имени.
PHONEBOOK** FindByName(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string name)
{
	int size = GetSize(*phoneBook);                               //Получить размер массива типа PHONEBOOK.
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));   //Выделить память под массив типа PHONEBOOK*

	for (int i = 0; i < size; i++)
	{
		if (GetName(phoneBook[i]) == NULL)                        //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}  
		if (strcmp(GetName(phoneBook[i]), name) == 0)             //Проверить равен ли аргумент name 
		{														  //содержимому в поля name.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
																  //в массив типа PHONEBOOK*.
		}
	}

	return searchBook;
}

//Поиск по номеру телефона.
PHONEBOOK** FindByPhoneNumber(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string phoneNumber)
{
	int size = GetSize(*phoneBook);                                   //Получить размер массива типа PHONEBOOK.
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));       //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetPhoneNumber(phoneBook[i]) == NULL)                     //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetPhoneNumber(phoneBook[i]), phoneNumber) == 0)   //Проверить равен ли аргумент phoneNumber
		{														      //содержимому в поля phoneNumber.
			searchBook[i] = &phoneBook[i];                            //Если равен, то записать адрес ячейки типа PHONEBOOK
		}                                                             //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

//Поиск по email.
PHONEBOOK** FindByEmail(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string email)
{
	int size = GetSize(*phoneBook);                               //Получить размер массива типа PHONEBOOK.
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));   //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetEmail(phoneBook[i]) == NULL)                       //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetEmail(phoneBook[i]), email) == 0)           //Проверить равен ли аргумент email
		{														  //содержимому в поля email.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
		}														  //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

//Поиск по zipcode.
PHONEBOOK** FindByZipCode(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string zip)
{
	int size = GetSize(*phoneBook);                               //Получить размер массива типа PHONEBOOK
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));   //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetZipCode(phoneBook[i]) == NULL)                     //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetZipCode(phoneBook[i]), zip) == 0)           //Проверить равен ли аргумент zip
		{                                                         //содержимому в поля zip.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
		}														  //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

PHONEBOOK** DoSearch(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string parametr, PHONEBOOK**(*callback)(PHONEBOOK*, PHONEBOOK**, string))
{
	return callback(phoneBook, searchBook, parametr);
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
		printf("\t%5s \n\n", GetZipCode(*searchBook[counter]));
	}
}
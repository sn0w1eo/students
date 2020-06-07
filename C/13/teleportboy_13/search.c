#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "phonebook.h"
#include "search.h"


//Поиск по имени.
PhoneBook** FindByName(PhoneBook* phoneBook, PhoneBook** searchBook, string name)
{
	int size = GetSize(phoneBook);                                //Получить размер массива типа PHONEBOOK.
	searchBook = (PhoneBook**)calloc(size, sizeof(PhoneBook*));   //Выделить память под массив типа PHONEBOOK*

	for (int i = 0; i < size; i++)
	{
		if (GetName(phoneBook[i]) == NULL)                        //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetName(phoneBook[i]), name) == 0)             //Проверить равен ли аргумент name 
		{                                                         //содержимому в поля name.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
                                                                  //в массив типа PHONEBOOK*.
		}
	}

	return searchBook;
}

//Поиск по номеру телефона.
PhoneBook** FindByPhoneNumber(PhoneBook* phoneBook, PhoneBook** searchBook, string phoneNumber)
{
	int size = GetSize(phoneBook);                                    //Получить размер массива типа PHONEBOOK.
	searchBook = (PhoneBook**)calloc(size, sizeof(PhoneBook*));       //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetPhoneNumber(phoneBook[i]) == NULL)                     //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetPhoneNumber(phoneBook[i]), phoneNumber) == 0)   //Проверить равен ли аргумент phoneNumber
		{                                                             //содержимому в поля phoneNumber.
			searchBook[i] = &phoneBook[i];                            //Если равен, то записать адрес ячейки типа PHONEBOOK
		}                                                             //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

//Поиск по email.
PhoneBook** FindByEmail(PhoneBook* phoneBook, PhoneBook** searchBook, string email)
{
	int size = GetSize(phoneBook);                                //Получить размер массива типа PHONEBOOK.
	searchBook = (PhoneBook**)calloc(size, sizeof(PhoneBook*));   //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetEmail(phoneBook[i]) == NULL)                       //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetEmail(phoneBook[i]), email) == 0)           //Проверить равен ли аргумент email
		{                                                         //содержимому в поля email.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
		}                                                         //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

//Поиск по zipcode.
PhoneBook** FindByZipCode(PhoneBook* phoneBook, PhoneBook** searchBook, string zip)
{
	int size = GetSize(phoneBook);                                //Получить размер массива типа PHONEBOOK
	searchBook = (PhoneBook**)calloc(size, sizeof(PhoneBook*));   //Выделить память под массив типа PHONEBOOK*.

	for (int i = 0; i < size; i++)
	{
		if (GetZipCode(phoneBook[i]) == NULL)                     //Пропустить итерацию если поле в структуре содержит NULL.
		{
			continue;
		}
		if (strcmp(GetZipCode(phoneBook[i]), zip) == 0)           //Проверить равен ли аргумент zip
		{                                                         //содержимому в поля zip.
			searchBook[i] = &phoneBook[i];                        //Если равен, то записать адрес ячейки типа PHONEBOOK
		}                                                         //в массив типа PHONEBOOK*.
	}

	return searchBook;
}

PhoneBook** DoSearch(PhoneBook* phoneBook, PhoneBook** searchBook, string parametr, PhoneBook** (*callback)(PhoneBook*, PhoneBook**, string))
{
	return callback(phoneBook, searchBook, parametr);
}

//Отобразить найденные контакты
void PrintSeachResults(PhoneBook** searchBook, int size)
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
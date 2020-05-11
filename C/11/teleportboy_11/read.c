/*/——————————————————————————————————————————————\
 |                                                |
 | Функции выводят в stdout информацию хранящуюся |
 | в полях структуры.                             |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"

#include "phonebook.h"
#include "read.h"

//Отобразить все контакты
void DisplayAllContacts(phonebook* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
	{
		DisplayName(phoneBook, i);
		DisplayPhoneNumber(phoneBook, i);
		DisplayEmail(phoneBook, i);
		DisplayZipCode(phoneBook, i);
	}
}

//Отобразить имя.
void DisplayName(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].name != NULL)
	{
		printf("%d-th contact: %s ", contactIndex + 1, phoneBook[contactIndex].name);
	}
	else
	{
		printf("%d-th contact: deleted ", contactIndex + 1);
	}
}

//Отобразить номер телефона.
void DisplayPhoneNumber(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].phoneNumber != NULL)
	{
		printf("%s ", phoneBook[contactIndex].phoneNumber);
	}
	else
	{
		printf("deleted ");
	}
}

//Отобразить email.
void DisplayEmail(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].email != NULL)
	{
		printf("%s ", phoneBook[contactIndex].email);
	}
	else
	{
		printf("deleted ");
	}
}

//Отобразить ZipCodeб.
void DisplayZipCode(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].zipCode != 0)
	{
		printf("%lld ", phoneBook[contactIndex].zipCode);
		printf("\n====================================================================================\n");
	}
	else
	{
		printf("deleted ");
		printf("\n====================================================================================\n");
	}
}
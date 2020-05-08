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
		printf("%s ", phoneBook[contactIndex].name);
	}
}

//Отобразить номер телефона.
void DisplayPhoneNumber(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].phoneNumber != NULL)
	{
		printf("%s ", phoneBook[contactIndex].phoneNumber);
	}
}

//Отобразить email.
void DisplayEmail(phonebook* phoneBook, int contactIndex)
{
	if (phoneBook[contactIndex].email != NULL)
	{
		printf("%s ", phoneBook[contactIndex].email);
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
}
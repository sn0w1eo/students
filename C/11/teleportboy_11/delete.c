/*/——————————————————————————————————————————————\
 |                                                |
 | Функции освобождают раннее выделенную память   |
 | тем самым удаляя все данные в определенных     |
 | блоках памяти.                                 |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"

#include "phonebook.h"

//Удалить имя.
void DeleteName(phonebook* phoneBook, int contactIndex)
{
	free(phoneBook[contactIndex].name);
	phoneBook[contactIndex].name = NULL;
}

//Удалить номер телефона.
void DeletePhoneNumber(phonebook* phoneBook, int contactIndex)
{
	free(phoneBook[contactIndex].phoneNumber);
	phoneBook[contactIndex].phoneNumber = NULL;
}

//Удалить email.
void DeleteEmail(phonebook* phoneBook, int contactIndex)
{
	free(phoneBook[contactIndex].email);
	phoneBook[contactIndex].email = NULL;
}

//Удалить ZipCode.
void DeleteZipCode(phonebook* phoneBook, int contactIndex)
{
	phoneBook[contactIndex].zipCode = 0;
}

//Удалить контакт.
void DeleteContact(phonebook* phoneBook, int contactIndex)
{
	DeleteName(phoneBook, contactIndex);
	DeletePhoneNumber(phoneBook, contactIndex);
	DeleteEmail(phoneBook, contactIndex);
	DeleteZipCode(phoneBook, contactIndex);
	
	printf("\nContact deleted");
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"

//TO DO
//Выделить память.
PhoneBook* GetMemory(int size)
{
	PhoneBook* phoneBook = NULL;

	//Выделить память.
	phoneBook = calloc(size, sizeof(PhoneBook) + sizeof(int));
	if (phoneBook == NULL)
	{
		return NULL;
	}

	//for (int i = 0; i < size; i++)
	//{
	//	SetName(&phoneBook[i], NULL);
	//	SetPhoneNumber(&phoneBook[i], NULL);
	//	SetEmail(&phoneBook[i], NULL);
	//	SetZipCode(&phoneBook[i], NULL);
	//}

	//Сохранить текущей размер блока памяти.
	SetSize(phoneBook, size);

	//"Сдвинуть" указатель на 4 байта, т.к. в первых четырёх байтах хранится размер всего блока памяти.
	(char*)phoneBook = (char*)phoneBook + sizeof(int);

	return (PhoneBook*)phoneBook;
}

//Перераспределить память, увеличив её размер вдвое. 
PhoneBook* ReallocMemory(PhoneBook* phoneBook)
{
	PhoneBook* phoneBookRealloc = (PhoneBook*)((char*)phoneBook - sizeof(int));
	
	int newSize = GetSize(phoneBook) * 2;
	SetSize(phoneBookRealloc, newSize);
	
	//Перераспределить память.
	phoneBookRealloc = (PhoneBook*)realloc(phoneBookRealloc, newSize * sizeof(PhoneBook) + sizeof(int));
	if (phoneBookRealloc == NULL)
	{
		return NULL;
	}	
	
	phoneBook = (PhoneBook*)((char*)phoneBookRealloc + sizeof(int));

	//Костыль что бы в будущем было проще работать над этими полями.
	for (int i = newSize / 2; i < newSize; i++)
	{
		SetName(&phoneBook[i], NULL);
		SetPhoneNumber(&phoneBook[i], NULL);
		SetEmail(&phoneBook[i], NULL);
		SetZipCode(&phoneBook[i], NULL);
	}

	return phoneBook;
}

//Освободить память.
void FreeMemory(PhoneBook* phoneBook, PhoneBook* PhoneBookFromTXT, PhoneBook** searchBook)
{
	int size = GetSize(phoneBook);
	for (int i = 0; i < size; i++)
	{
		FreeContactMemory(phoneBook, i);
	}

	//Освободить основной блок памяти.
	if (phoneBook != NULL)
	{
		free((char*)phoneBook - sizeof(int));
	}

	size = GetSize(PhoneBookFromTXT);
	for (int i = 0; i < size; i++)
	{
		FreeContactMemory(PhoneBookFromTXT, i);
	}
	if (PhoneBookFromTXT != NULL)
	{
		free((char*)PhoneBookFromTXT - sizeof(int));
	}

	if (searchBook != NULL)
	{
		free(searchBook);
		searchBook = NULL;
	}

	printf("\n\tMemory freed!");
}

void FreeContactMemory(PhoneBook* phoneBook, int contactIndex)
{
	//Освободить память поля name.
	if (phoneBook[contactIndex].name != NULL)
	{
		free(phoneBook[contactIndex].name);
		phoneBook[contactIndex].name = NULL;
	}

	//Освободить память поля phoneNumber.
	if (phoneBook[contactIndex].phoneNumber != NULL)
	{
		free(phoneBook[contactIndex].phoneNumber);
		phoneBook[contactIndex].phoneNumber = NULL;
	}
	
	//Освободить память поля email.
	if (phoneBook[contactIndex].email != NULL)
	{
		free(phoneBook[contactIndex].email);
		phoneBook[contactIndex].email = NULL;
	}
	
	//Освободить память поля zip.
	if (phoneBook[contactIndex].zip != NULL)
	{
		free(phoneBook[contactIndex].zip);
		phoneBook[contactIndex].zip = NULL;
	}

}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"

//Выделить память.
PHONEBOOK* GetMemory(int size)
{
	PHONEBOOK* phoneBook = NULL;
	
	//Защита от формошлёпов.
	if (size <= 0)
	{
		size = 5;
	}
	
	//Выделить память. 
	if (phoneBook == NULL)
	{
		phoneBook = (PHONEBOOK*)calloc(size, sizeof(PHONEBOOK));
		if (phoneBook == NULL)
		{
			return NULL;
		}
		SetSize(phoneBook, size);     //Сохранить текущей размер блока памяти.
	}

	return phoneBook;
}

//Перераспределить память, увеличив её размер вдвое. 
PHONEBOOK* ReallocMemory(PHONEBOOK* phoneBook)
{
	int size = GetSize(*phoneBook) * 2;
	SetSize(phoneBook, size);        //Сохранить текущей размер блока памяти.
	//Перераспределить память.
	phoneBook = realloc(phoneBook, size * sizeof(PHONEBOOK));
	
	//Костыль что бы в будущем было проще работать над этими полями.
	for (int i = size / 2; i < size; i++)
	{
		SetName(&phoneBook[i], NULL);
		SetPhoneNumber(&phoneBook[i], NULL);
		SetEmail(&phoneBook[i], NULL);
		SetZipCode(&phoneBook[i], NULL);
	}

	return phoneBook;
}

//Освободить память.
void FreeMemory(PHONEBOOK* phoneBook)
{
	int size = GetSize(*phoneBook);
	for (int i = 0; i < size; i++)
	{
		//Очистить имя.
		if (phoneBook[i].name != NULL)
		{
			free(phoneBook[i].name);
			phoneBook[i].name = NULL;
		}

		//Очитить номер телефона.
		if (phoneBook[i].phoneNumber != NULL)
		{
			free(phoneBook[i].phoneNumber);
			phoneBook[i].phoneNumber = NULL;
		}

		//Очистить email.
		if (phoneBook[i].email != NULL)
		{
			free(phoneBook[i].email);
			phoneBook[i].email = NULL;
		}

		//Очситить zip.
		if (phoneBook[i].zip != NULL)
		{
			free(phoneBook[i].zip);
			phoneBook[i].zip = NULL;
		}
	}

	//Очистить основной блок памяти.
	if (phoneBook != NULL)
	{
		free(phoneBook);
		phoneBook = NULL;
	}

	printf("\n\tMemory freed!");
}
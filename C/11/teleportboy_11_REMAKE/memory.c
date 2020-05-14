#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"

//Выделить память.
PHONEBOOK* GetMemory(int size)
{
	PHONEBOOK* phoneBook = NULL;
	
	//Защита
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
		phoneBook->size = size;     //Сохранить текущей размер блока памяти.
	}

	return phoneBook;
}

//Перераспределить память, увеличив её размер вдвое. 
PHONEBOOK* ReallocMemory(PHONEBOOK* phoneBook)
{
	int size = phoneBook->size * 2;
	phoneBook->size = size;        //Сохранить текущей размер блока памяти.
	//Перераспределить память.
	phoneBook = realloc(phoneBook, size * sizeof(PHONEBOOK));
	
	//Костыль что бы в будущем было проще работать над этими полями.
	for (int i = size / 2; i < size; i++)
	{
		phoneBook[i].name = NULL;
		phoneBook[i].phoneNumber = NULL;
		phoneBook[i].email = NULL;
	}

	return phoneBook;
}

//Освободить память.
void FreeMemory(PHONEBOOK* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
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
	}

	//Очистить основной блок памяти.
	if (phoneBook != NULL)
	{
		free(phoneBook);
		phoneBook = NULL;
	}

	printf("\n\tMemory freed!");
}
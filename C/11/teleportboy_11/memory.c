
#include "stdio.h"
#include "stdlib.h"

#include "phonebook.h"

//Выделить или перераспределить память.
phonebook* GetMemory(phonebook* phoneBook)
{
	//Выделить память при первом запуске.
	if (phoneBook == NULL)
	{
		phoneBook = (phonebook*)calloc(1, sizeof(phonebook));
		if (phoneBook == NULL)
		{
			return NULL;
		}
		phoneBook->size = 1;     //Сохранить текущей размер блока памяти.
	}

	else
	{
		phoneBook->size++;       //Сохранить текущей размер блока памяти.
		phoneBook = (phonebook*)realloc(phoneBook, phoneBook->size * sizeof(phonebook));
	}

	return phoneBook;
}

//Освободить память.
void FreeMemory(phonebook* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
	{
		//Очистить имя.
		if (phoneBook[i].name  != NULL)
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

	printf("\nMemory freed!");
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"

//�������� ������.
PHONEBOOK* GetMemory(int size)
{
	PHONEBOOK* phoneBook = NULL;
	
	//������
	if (size <= 0)
	{
		size = 5;
	}
	
	//�������� ������. 
	if (phoneBook == NULL)
	{
		phoneBook = (PHONEBOOK*)calloc(size, sizeof(PHONEBOOK));
		if (phoneBook == NULL)
		{
			return NULL;
		}
		phoneBook->size = size;     //��������� ������� ������ ����� ������.
	}

	return phoneBook;
}

//���������������� ������, �������� � ������ �����. 
PHONEBOOK* ReallocMemory(PHONEBOOK* phoneBook)
{
	int size = phoneBook->size * 2;
	phoneBook->size = size;        //��������� ������� ������ ����� ������.
	//���������������� ������.
	phoneBook = realloc(phoneBook, size * sizeof(PHONEBOOK));
	
	//������� ��� �� � ������� ���� ����� �������� ��� ����� ������.
	for (int i = size / 2; i < size; i++)
	{
		phoneBook[i].name = NULL;
		phoneBook[i].phoneNumber = NULL;
		phoneBook[i].email = NULL;
	}

	return phoneBook;
}

//���������� ������.
void FreeMemory(PHONEBOOK* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
	{
		//�������� ���.
		if (phoneBook[i].name != NULL)
		{
			free(phoneBook[i].name);
			phoneBook[i].name = NULL;
		}

		//������� ����� ��������.
		if (phoneBook[i].phoneNumber != NULL)
		{
			free(phoneBook[i].phoneNumber);
			phoneBook[i].phoneNumber = NULL;
		}

		//�������� email.
		if (phoneBook[i].email != NULL)
		{
			free(phoneBook[i].email);
			phoneBook[i].email = NULL;
		}
	}

	//�������� �������� ���� ������.
	if (phoneBook != NULL)
	{
		free(phoneBook);
		phoneBook = NULL;
	}

	printf("\n\tMemory freed!");
}
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"



//�������� ����� �������.
PHONEBOOK* AddContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const ulong zip)
{	
	PHONEBOOK* freeSlot = NULL;

	//��������� ������������ ����������
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return phoneBook;
	}

	switch (IsFreeSpace(phoneBook))              //��������� ���� �� ��������� �����.
	{
	case TRUE:                                  //���� ����,
		freeSlot = GetFreeSpace(phoneBook);     //�� �������� ������ ������ � ������� ����� �������� ����� ������.
		break;
	case FALSE:                                 //���� ����,
		phoneBook = ReallocMemory(phoneBook);   //�� ���������������� ������
		freeSlot = GetFreeSpace(phoneBook);     //� ����� �������� ������ ������ � ������� ����� �������� ����� ������.
		break;
	}

	//�������� ����� ������.
	SetName(freeSlot, name);
	SetPhoneNumber(freeSlot, phoneNumber);
	SetEmail(freeSlot, email);
	SetZipCode(freeSlot, zip);

	return phoneBook;
}

//��������� ���� �� �����.
int IsFreeSpace(PHONEBOOK* phoneBook)
{
	int counter = 0;

	for (; counter < phoneBook->size; counter++)
	{
		if (phoneBook[counter].name == NULL)
		{
			return TRUE;
		}
	}
	return FALSE;
}

//����� ��������� ����� ��� ������ ����� ������.
PHONEBOOK* GetFreeSpace(PHONEBOOK* phoneBook)
{
	int counter = 0;
	for (; counter < phoneBook->size; counter++)
	{
		if (phoneBook[counter].name == NULL)
		{
			break;
		}
	}
	return &phoneBook[counter];
}

void UpdateContact(PHONEBOOK* phoneBook, const string name, const string phoneNumber, const string email, const ulong zip, const int contactIndex)
{
	if (CheckArguments(phoneBook, name, phoneNumber, email) == FALSE)
	{
		printf("Invalid arguments!");
		return;
	}

	SetName(&phoneBook[contactIndex], name);
	SetPhoneNumber(&phoneBook[contactIndex], phoneNumber);
	SetEmail(&phoneBook[contactIndex], email);
	SetZipCode(&phoneBook[contactIndex], zip);
}

void DeleteContact(PHONEBOOK* phoneBook, int contactIndex)
{
	SetName(&phoneBook[contactIndex], NULL);
	SetPhoneNumber(&phoneBook[contactIndex], NULL);
	SetEmail(&phoneBook[contactIndex], NULL);
	SetZipCode(&phoneBook[contactIndex], 0);
}

//���������� ����� ��� � ���� ��������� name.
void SetName(PHONEBOOK* phoneBook, const string name)
{
	phoneBook->name = _strdup(name);
}

//���������� ����� ����� �������� � ���� ��������� phoneNumber.
void SetPhoneNumber(PHONEBOOK* phoneBook, const string phoneNumber)
{
	phoneBook->phoneNumber = _strdup(phoneNumber);
}

//���������� ����� email � ���� ��������� email.
void SetEmail(PHONEBOOK* phoneBook, const string email)
{
	phoneBook->email = _strdup(email);
}

//���������� ����� zipcode � ���� ��������� zip.
void SetZipCode(PHONEBOOK* phoneBook, const ulong zipCode)
{
	phoneBook->zip = zipCode;
}

//�������� ������ � ���� name.
string GetName(const PHONEBOOK phoneBook)
{
	return phoneBook.name;
}

//�������� ������ � ���� phoneNumber.
string GetPhoneNumber(const PHONEBOOK phoneBook)
{
	return phoneBook.phoneNumber;
}

//�������� ������ � ���� email.
string GetEmail(const PHONEBOOK phoneBook)
{
	return phoneBook.email;
}

//�������� ������ � ���� zip.
ulong GetZipCode(const PHONEBOOK phoneBook)
{
	return phoneBook.zip;
}

//��������� ������������ ����������.
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

//���������� ��� ��������
void PrintContacts(PHONEBOOK* phoneBook)
{
	for (int i = 0; i < phoneBook->size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		else
		{
			printf(" %15s ", GetName(phoneBook[i]));
			printf(" %15s ", GetPhoneNumber(phoneBook[i]));
			printf(" %10s ", GetEmail(phoneBook[i]));
			printf("\t%5lld \n\n", GetZipCode(phoneBook[i]));
		}
	}
}

//����� �� �����
PHONEBOOK** FindByName(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string name)
{
	
	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].name, name) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//����� �� ������ ��������
PHONEBOOK** FindByPhoneNumber(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string phoneNumber)
{

	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].phoneNumber, phoneNumber) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//����� �� email
PHONEBOOK** FindByEmail(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, string email)
{
	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (strcmp(phoneBook[i].email, email) == 0)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//����� �� zipcode
PHONEBOOK** FindByZipCode(PHONEBOOK* phoneBook, PHONEBOOK** searchBook, ulong zip)
{

	int size = phoneBook->size;
	searchBook = (PHONEBOOK**)calloc(size, sizeof(PHONEBOOK*));

	for (int i = 0; i < size; i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		if (phoneBook[i].zip == zip)
		{
			searchBook[i] = &phoneBook[i];
		}
	}

	return searchBook;
}

//���������� ��������� ��������
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
		printf("\t%5lld \n\n", GetZipCode(*searchBook[counter]));
	}
}
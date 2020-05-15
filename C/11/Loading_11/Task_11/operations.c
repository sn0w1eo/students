#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "operations.h"

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}


myStruct addContact(myStruct temp, char name[100], char number[100], char email[100], char zipCode[100])
{
	{
		size_t len = strlen(name);
		temp.name = (char*)malloc(len + 1);
		if (temp.name == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(temp.name, name);
		}
	}
	{

		size_t len = strlen(number);
		temp.phone = (char*)malloc(len + 1);
		if (temp.phone == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.phone, number);
		}
	}
	{
		size_t len = strlen(email);
		temp.email = (char*)malloc(len + 1);
		if (temp.email == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.email, email);
		}
	}
	{
		size_t len = strlen(zipCode);
		temp.zipCode = (char*)malloc(len + 1);
		if (temp.zipCode == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.zipCode, zipCode);
		}
	}
	return temp;
}

myStruct updateContact(myStruct temp, char name[100], char number[100], char email[100], char zipCode[100])
{
	{
		size_t len = strlen(name);
		temp.name = (char*)realloc(temp.name, len + 1);
		if (temp.name == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(temp.name, name);
		}
	}
	{

		size_t len = strlen(number);
		temp.phone = (char*)realloc(temp.phone, len + 1);
		if (temp.phone == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.phone, number);
		}
	}
	{
		size_t len = strlen(email);
		temp.email = (char*)realloc(temp.email, len + 1);
		if (temp.email == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.email, email);
		}
	}
	{
		size_t len = strlen(zipCode);
		temp.zipCode = (char*)realloc(temp.zipCode, len + 1);
		if (temp.zipCode == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(temp.zipCode, zipCode);
		}
	}
	return temp;
}

myStruct deleteContact(myStruct temp)
{
	free(temp.name);
	temp.name = NULL;
	free(temp.phone);
	temp.phone = NULL;
	free(temp.email);
	temp.email = NULL;
	free(temp.zipCode);
	temp.zipCode = NULL;
	return temp;
}

void searchByName(myStruct temp, char name[100])
{

	if (strcmp(temp.name, name) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", temp.name, temp.phone, temp.email, temp.zipCode);
		printf("\n");
	}
	return;
}

void searchByPhone(myStruct temp, char phone[100])
{
	if (strcmp(temp.phone, phone) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", temp.name, temp.phone, temp.email, temp.zipCode);
		printf("\n");
	}
	return;
}

void searchByEmail(myStruct temp, char email[100])
{
	if (strcmp(temp.email, email) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", temp.name, temp.phone, temp.email, temp.zipCode);
		printf("\n");
	}
	return;
}

void searchByZipCode(myStruct temp, char zipCode[100])
{
	if (strcmp(temp.zipCode, zipCode) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", temp.name, temp.phone, temp.email, temp.zipCode);
		printf("\n");
	}
	return;
}
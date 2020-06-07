#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "Data.h"

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}

MyStruct addContact( MyStruct person,  char name[50],  char phone[50],  char email[50],  char zipCode[50]) {
	// memory for name
	size_t n = strlen(name);
	person.name = (char*)malloc(n + 1);
	if (person.name == NULL)
		printf("failed");
	else
		strcopy(person.name, name);
	// memory for phone	
	n = strlen(phone);
	person.phone = (char*)malloc(n + 1);
	if (person.phone == NULL)
		printf("failed");
	else
		strcopy(person.phone, phone);
	// memory for email 
	n = strlen(email);
	person.email = (char*)malloc(n + 1);
	if (person.email == NULL)
		printf("failed");
	else
		strcopy(person.email, email);
	// memory for zipCode
	n = strlen(zipCode);
	person.zipCode = (char*)malloc(n + 1);
	if (person.zipCode == NULL)
		printf("failed");
	else
		strcopy(person.zipCode, zipCode);
	return person;
}

MyStruct updateContact(MyStruct person, char name[50], char phone[50], char email[50], char zipCode[50]) {
	{
		size_t len = strlen(name);
		person.name = (char*)realloc(person.name, len + 1);
		if (person.name == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(person.name, name);
		}
	}
	{

		size_t len = strlen(phone);
		person.phone = (char*)realloc(person.phone, len + 1);
		if (person.phone == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(person.phone, phone);
		}
	}
	{
		size_t len = strlen(email);
		person.email = (char*)realloc(person.email, len + 1);
		if (person.email == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(person.email, email);
		}
	}
	{
		size_t len = strlen(zipCode);
		person.zipCode = (char*)realloc(person.zipCode, len + 1);
		if (person.zipCode == NULL)
		{
			printf("Not memory");
		}
		else
		{
			strcopy(person.zipCode, zipCode);
		}
	}
	return person;
}

MyStruct deleteContact(MyStruct person) {
	free(person.name);
	person.name = NULL;
	free(person.phone);
	person.phone = NULL;
	free(person.email);
	person.email = NULL;
	free(person.zipCode);
	person.zipCode = NULL;
	return person;
}

void searchByName(MyStruct person, char name[50]) {
	if (strcmp(person.name, name) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", person.name, person.phone, person.email, person.zipCode);
		printf("\n");
	}
	return;
}

void searchByPhone(MyStruct person, char phone[50]) {
	if (strcmp(person.phone, phone) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", person.name, person.phone, person.email, person.zipCode);
		printf("\n");
	}
	return;
}

void searchByEmail(MyStruct person, char email[50]) {
	if (strcmp(person.email, email) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", person.name, person.phone, person.email, person.zipCode);
		printf("\n");
	}
	return;
}

void searchByZipCode(MyStruct person, char zipCode[50]) {
	if (strcmp(person.zipCode, zipCode) == 0)
	{
		printf(" Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", person.name, person.phone, person.email, person.zipCode);
		printf("\n");
	}
	return;
}


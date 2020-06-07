#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Data.h"

void read(MyStruct* storage)
{
	for (int i = 0; i < 20; i++) {
		if (storage[i].name == NULL)
		{
			continue;
		}
		printf("%d| Name: %s  \n"
			"Phone: %s  \n"
			"Email: %s  \n"
			"zipCode: %s  \n", i, storage[i].name, storage[i].phone, storage[i].email, storage[i].zipCode);
		printf("\n");
	}
}
int main() {
	MyStruct storage[20] = {0x00};
	storage[0] = addContact(storage[0], "Safi",  "20020", "Safi@mail",  "12");
	storage[1] = addContact(storage[1], "Dima",  "25484", "Dima@mail",  "42");
	storage[2] = addContact(storage[2], "Masha", "46857", "Masha@mail", "35");
	storage[3] = addContact(storage[3], "Sanya", "07542", "Sanya@mail", "71");
	storage[4] = addContact(storage[4], "Max",   "95865", "Max@mail",   "36");
	read(storage);
	getch();
	printf("-------------------------------------------------------------\n");
	storage[3] = updateContact(storage[3], "Sanya", "54930", "Sanya@mail", "52");
	read(storage);
	getch();
	printf("-------------------------------------------------------------\n");
	storage[3] = deleteContact(storage[3]);
	storage[1] = deleteContact(storage[1]);
	read(storage);
	getch();

	printf("\nSearch by name \n"
		"-------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByName(storage[i], "Masha");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by phone \n"
		"-------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByPhone(storage[i], "25484");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by email \n"
		"-------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByEmail(storage[i], "Safi@mail");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by zipCode \n"
		"-------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByZipCode(storage[i], "36");
		}
		else
		{
			continue;
		}
	}

	for (int i = 0; i < 20; i++)
	{
		free(storage[i].name);
		storage[i].name = NULL;
		free(storage[i].phone);
		storage[i].phone = NULL;
		free(storage[i].email);
		storage[i].email = NULL;
		free(storage[i].zipCode);
		storage[i].zipCode = NULL;
	}

}
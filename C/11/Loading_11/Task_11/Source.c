#include "stdio.h"
#include "stdlib.h"
#include "operations.h"


void read(myStruct* storage)
{
	for (int i = 0; i < 20; i++) {
		if (storage[i].name == NULL)
		{
			continue;
		}
		printf("%d) Name: %s  "
			"Phone: %s  "
			"Email: %s  "
			"zipCode: %s  ", i, storage[i].name, storage[i].phone, storage[i].email, storage[i].zipCode);
		printf("\n");
	}
}

int main() {
	myStruct storage[20] = { 0x00 };
	printf("Successfully added\n"
		"-------------------------------------------------------------------\n");
	storage[0] = addContact(storage[0], "Nurik", "0709233778", "nurchik@mail.com", "720000");
	storage[1] = addContact(storage[1], "Dima", "07777777", "asfdsadfk@mail.com", "720012");
	storage[2] = addContact(storage[2], "Nastya", "888444", "asdfsdf@", "720012");
	storage[3] = addContact(storage[3], "Kirill", "99996666", "kjljkl@", "720012");
	storage[4] = addContact(storage[4], "Bogdan", "11112222", "hjkljkl@", "720012");
	storage[5] = addContact(storage[5], "Kostya", "8889999", "hjkljkl@", "720012");
	read(storage);
	printf("\nSuccessfully update\n"
		"-------------------------------------------------------------------\n");
	storage[0] = updateContact(storage[0], "Nurik", "3778", "nur@mail.com", "7200");
	storage[4] = updateContact(storage[4], "Bermet", "11112222", "hjkljkl@", "720012");
	storage[5] = updateContact(storage[5], "Nurik", "8889999", "hjkljkl@", "720012");
	read(storage);
	printf("\nSuccessfully deleted\n"
		"-------------------------------------------------------------------\n");
	storage[4] = deleteContact(storage[4]);
	read(storage);
	printf("\nSearch by name \n"
		"-------------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByName(storage[i], "Nurik");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by phone \n"
		"-------------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByPhone(storage[i], "888444");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by email \n"
		"-------------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByEmail(storage[i], "kjljkl@");
		}
		else
		{
			continue;
		}
	}
	printf("\nSearch by zipCode \n"
		"-------------------------------------------------------------------\n");
	for (size_t i = 0; i < 20; i++)
	{
		if (storage[i].name != NULL)
		{
			searchByZipCode(storage[i], "720012");
		}
		else
		{
			continue;
		}
	}
	//--------------Free memory---------------------------
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
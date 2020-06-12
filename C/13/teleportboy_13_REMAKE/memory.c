#include "stdio.h"
#include "stdlib.h"

#include "phonebook.h"
#include "memory.h"

//Выделить память под массив типа ContactData.
ContactData* InitStorageForContacts(int contactsCount)
{
	//Выделить память и сохранить ко-во контактов в ней.
	ContactData* contacts = malloc(contactsCount * sizeof(ContactData) + sizeof(int));
	if (contacts == NULL)
	{
		printf("Memory aalocated falied in InitStorageForContacts");
		exit(1);
	}
	
	SetSize(contacts, contactsCount);

	//"Сдвинуть" указатель на 4 байта, т.к. в первых четырёх байтах хранится размер всего блока памяти.
	contacts = MoveByFourBytes(contacts);

	//Установить "метку" на все пустые контакты.
	for (int i = 0; i < contactsCount; i++)
	{
		SetContactStatus(&contacts[i], Blank);
	}

	return (ContactData*)contacts;
}

//Перераспределить память, увеличив её размер вдвое.
ContactData* ReallocStorageForContacts(ContactData* contacts)
{
	//Установить указатель на первый байт блока памяти.
	ContactData* firstByteOfContacts = GetFirstByteOfContacts(contacts);

	//Вычислить новый размер блока памяти и сохранить его.
	int newSize = GetSize(contacts) * 2;
	SetSize(firstByteOfContacts, newSize);

	//Перераспределить память.
	firstByteOfContacts = (ContactData*)realloc(firstByteOfContacts, newSize * sizeof(ContactData) + sizeof(int));
	if (contacts == NULL)
	{
		printf("Memory allocated falied in ReallocStorageForContacts");
		exit(1);
	}

	//"Сдвинуть" указатель на 4 байта, т.к. в первых четырёх байтах хранится размер всего блока памяти.
	contacts = MoveByFourBytes(firstByteOfContacts);
	
	//Установить "метку" на все пустые контакты.
	for (int i = newSize / 2; i < newSize; i++)
	{
		SetContactStatus(&contacts[i], Blank);
	}

	return contacts;
}

//Освободить всю память выделенную ранее.
void FreeMemory(PhoneBook* phoneBook, PhoneBook* searchResults, PhoneBook* readingFromTXT, Contact* readingFromDAT)
{
	int size = GetSize(phoneBook->contacts);
	void* tempPtrToContacts = NULL;
	
	for (int i = 0; i < size; i++)
	{
		if (GetContactStatus(phoneBook->contacts[i]) == Existing)
		{
			FreeContactMemory(&phoneBook->contacts[i]);
		}
	}

	tempPtrToContacts = GetFirstByteOfContacts(phoneBook->contacts);
	free(tempPtrToContacts);
	tempPtrToContacts = NULL;

	free(phoneBook);
	phoneBook = NULL;

	tempPtrToContacts = GetFirstByteOfContacts(searchResults->contacts);
	free(tempPtrToContacts);
	tempPtrToContacts = NULL;

	free(searchResults);
	searchResults = NULL;

	size = GetSize(readingFromTXT->contacts);
	for (int i = 0; i < size; i++)
	{
		if (GetContactStatus(readingFromTXT->contacts[i]) == Existing)
		{
			FreeContactMemory(&readingFromTXT->contacts[i]);
		}
	}

	tempPtrToContacts = GetFirstByteOfContacts(readingFromTXT->contacts);
	free(tempPtrToContacts);
	tempPtrToContacts = NULL;

	free(readingFromTXT);
	readingFromTXT = NULL;

	free(readingFromDAT);
	readingFromDAT = NULL;
}

void FreeContactMemory(ContactData* contact)
{
	if (GetContactStatus(*contact) == Blank)
	{
		return;
	}

	//Освободить память поля name.
	if (contact->name != NULL)
	{
		free(contact->name);
		contact->name = NULL;
	}

	//Освободить память поля phoneNumber.
	if (contact->phone != NULL)
	{
		free(contact->phone);
		contact->phone = NULL;
	}

	//Освободить память поля email.
	if (contact->email != NULL)
	{
		free(contact->email);
		contact->email = NULL;
	}

	//Освободить память поля zip.
	if (contact->zip != NULL)
	{
		free(contact->zip);
		contact->zip = NULL;
	}

	contact->contactStatus = Blank;
}
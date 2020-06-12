#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "fileio.h"
#include "phonebook.h"
#include "memory.h"

//Ввод в файл в бинарном режиме. 
void BinaryRecordInfoToDAT(PhoneBook* phoneBook)
{
	FILE* datPhoneBook = fopen("phonebook2.dat", "wb");
	ContactData* contacts = phoneBook->contacts;

	for (int i = 0; i < GetSize(contacts); i++)
	{
		if (GetContactStatus(contacts[i]) == Blank)
		{
			continue;
		}
		else
		{
			fprintf(datPhoneBook, "%-30s %-30s %-30s %-10s", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].zip);
		}
	}

	fclose(datPhoneBook);
	datPhoneBook = NULL;
}

//Вывод из файла в бинарном режиме.
void BinaryReadInfoFromFile(Contact* contacts, int contactsCount)
{
	FILE* datPhoneBook = fopen("phonebook2.dat", "rb");

	for (int i = 0; i < contactsCount; i++)
	{
		fread(&contacts[i], sizeof(Contact), 1, datPhoneBook);
		contacts[i].name[30] = '\0';
		contacts[i].phone[30] = '\0';
		contacts[i].email[30] = '\0';
		contacts[i].zip[9] = '\0';
	}

	fclose(datPhoneBook);
	datPhoneBook = NULL;
}

void PrintContactsBinMode(Contact* contacts, int contactsCount)
{
	for (int i = 0; i < contactsCount; i++)
	{
		printf("%s %s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].zip);
	}
}


//Записать всю информацию с phoneBook в txt файл.
void RecordInfoToTXT(PhoneBook* phoneBook)
{
	FILE* txtPhoneBook = fopen("phonebook.txt", "w");
	ContactData* contacts = phoneBook->contacts;

	for (int i = 0; i < GetSize(contacts); i++)
	{
		if (GetContactStatus(contacts[i]) == Blank)
		{
			continue;
		}
		else
		{
			fprintf(txtPhoneBook, "%s %s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].zip);
		}
	}

	fclose(txtPhoneBook);
	txtPhoneBook = NULL;
}

//Читать файл.
void ReadInfoFromFile(PhoneBook* emptyPhoneBook)
{
	FILE* txtPhoneBook = fopen("phonebook.txt", "r");
	int currentIndex = 0, contactIndex = 0;
	int linesCount = GetLinesCount(txtPhoneBook);

	emptyPhoneBook->contacts = InitStorageForContacts(linesCount);
	if (emptyPhoneBook->contacts == NULL)
	{
		exit(1);
	}

	char* buffer = calloc(200, sizeof(char));
	if (buffer == NULL)
	{
		exit(1);
	}

	while (contactIndex != linesCount)
	{
		fgets(buffer, 200, txtPhoneBook);
		CopyContactFromBuffer(buffer, &currentIndex, (GetContacts(emptyPhoneBook) + contactIndex));
		currentIndex = 0;
		contactIndex++;
	}
	fclose(txtPhoneBook);
	txtPhoneBook = NULL;
	free(buffer);
}

int GetLinesCount(FILE* txtPhoneBook)
{
	int linesCounter = 0;

	while (!feof(txtPhoneBook))
	{
		if (fgetc(txtPhoneBook) == '\n')
		{
			linesCounter++;
		}
	}

	rewind(txtPhoneBook);

	return linesCounter;
}

//Вычислить длину строки в буффере.
int GetStringLengthFromBuffer(char* buffer, int* currentIndex)
{
	int counter = 0;

	while (buffer[(*currentIndex)++] != ' ')
	{
		counter++;

		if (buffer[(*currentIndex)] == '\n')
		{
			break;
		}
	}

	return counter;
}

//Скопировать имя с буффера.
void CopyNameFromBuffer(char* buffer, int* currentIndex, ContactData* contact)
{	
	int nameLength = GetStringLengthFromBuffer(buffer, currentIndex);   //Получить длину строки "имя" в буффере.

	contact->name = calloc(nameLength + 1, sizeof(char));               //Зная длину строки выделить память под неё и записать.
	if (contact->name == NULL)
	{
		printf("Memory allocate falied!");
		exit(1);
	}

	strncpy(contact->name, &buffer[0], nameLength);
	contact->name[nameLength] = '\0';
}

//Скопировать телефон с буффера.
void CopyPhoneFromBuffer(char* buffer, int* currentIndex, ContactData* contact)
{	
	int phoneNumberLength = GetStringLengthFromBuffer(buffer, currentIndex);
	
	//Основываясь на длине строки "имя" в буффере, определить число, на которое надо сдвинуться что бы получить аддрес начала следующей строки в буфере.
	int shift = strlen(contact->name) + 1;

	contact->phone = calloc(phoneNumberLength + 1, sizeof(char));
	if (contact->phone == NULL)
	{
		printf("Memory allocate falied!");
		exit(1);
	}

	strncpy(contact->phone, &buffer[shift], phoneNumberLength);
	contact->phone[phoneNumberLength] = '\0';
}

//Скопировать email с буффера
void CopyEmailFromBuffer(char* buffer, int* currentIndex, ContactData* contact)
{
	int emailLength = GetStringLengthFromBuffer(buffer, currentIndex);	
	int shift = strlen(contact->name) + strlen(contact->phone) + 2;

	contact->email = calloc(emailLength + 1, sizeof(char));
	if (contact->email == NULL)
	{
		printf("Memory allocate falied!");
		exit(1);
	}

	strncpy(contact->email, &buffer[shift], emailLength);
	contact->email[emailLength] = '\0';
}

//Скопировать Zip с буффера.
void CopyZipCodeFromBuffer(char* buffer, int* currentIndex, ContactData* contact)
{
	int zipCodeLength = GetStringLengthFromBuffer(buffer, currentIndex);
	int shift = strlen(contact->name) + strlen(contact->phone) + strlen(contact->email) + 3;

	contact->zip = calloc(zipCodeLength + 1, sizeof(char));
	if (contact->zip == NULL)
	{
		printf("Memory allocate falied!");
		exit(1);
	}
	
	strncpy(contact->zip, &buffer[shift], zipCodeLength);
	contact->zip[zipCodeLength] = '\0';
}

void CopyContactFromBuffer(char* buffer, int* currentIndex, ContactData* contact)
{
	CopyNameFromBuffer(buffer, currentIndex, contact);
	CopyPhoneFromBuffer(buffer, currentIndex, contact);
	CopyEmailFromBuffer(buffer, currentIndex, contact);
	CopyZipCodeFromBuffer(buffer, currentIndex, contact);
	SetContactStatus(contact, Existing);
}
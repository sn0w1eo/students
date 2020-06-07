#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"

//Записать всю информацию с phoneBook в txt файл.
void RecordInfoToTXT(PhoneBook* phoneBook)
{
	FILE* txtPhoneBook = fopen("phonebook.txt", "w");

	for (int i = 0; i < GetSize(phoneBook); i++)
	{
		if (phoneBook[i].name == NULL)
		{
			continue;
		}
		else
		{
			fprintf(txtPhoneBook, "%s %s %s %s\n", phoneBook[i].name, phoneBook[i].phoneNumber, phoneBook[i].email, phoneBook[i].zip);
		}
	}

	fclose(txtPhoneBook);
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

//Скопировать имя с буфера.
void CopyNameFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook)
{
	int nameLength = GetStringLengthFromBuffer(buffer, currentIndex);

	emptyPhoneBook->name = calloc(nameLength + 1, sizeof(char));
	strncpy(emptyPhoneBook->name, &buffer[0], nameLength);
	emptyPhoneBook->name[nameLength] = '\0';
}

void CopyPhoneNumberFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook)
{
	int phoneNumberLength = GetStringLengthFromBuffer(buffer, currentIndex);
	int shift = strlen(emptyPhoneBook->name) + 1;

	emptyPhoneBook->phoneNumber = calloc(phoneNumberLength + 1, sizeof(char));
	strncpy(emptyPhoneBook->phoneNumber, &buffer[shift], phoneNumberLength);
	emptyPhoneBook->phoneNumber[phoneNumberLength] = '\0';
}

void CopyEmailFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook)
{
	int emailLength = GetStringLengthFromBuffer(buffer, currentIndex);
	int shift = strlen(emptyPhoneBook->name) + strlen(emptyPhoneBook->phoneNumber) + 2;

	emptyPhoneBook->email = calloc(emailLength + 1, sizeof(char));
	strncpy(emptyPhoneBook->email, &buffer[shift], emailLength);
	emptyPhoneBook->email[emailLength] = '\0';
}

void CopyZipCodeFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook)
{
	int zipCodeLength = GetStringLengthFromBuffer(buffer, currentIndex);
	int shift = strlen(emptyPhoneBook->name) + strlen(emptyPhoneBook->phoneNumber) + strlen(emptyPhoneBook->email) + 3;

	emptyPhoneBook->zip = calloc(zipCodeLength + 1, sizeof(char));
	strncpy(emptyPhoneBook->zip, &buffer[shift], zipCodeLength);
	emptyPhoneBook->zip[zipCodeLength] = '\0';
}

void CopyContactFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook)
{
	CopyNameFromBuffer(buffer, currentIndex, emptyPhoneBook);
	CopyPhoneNumberFromBuffer(buffer, currentIndex, emptyPhoneBook);
	CopyEmailFromBuffer(buffer, currentIndex, emptyPhoneBook);
	CopyZipCodeFromBuffer(buffer, currentIndex, emptyPhoneBook);
}

//Читать файл.
PhoneBook* ReadInfoFromFile(PhoneBook* emptyPhoneBook)
{
	FILE* txtPhoneBook = fopen("phonebook.txt", "r+");
	int currentIndex = 0, phoneBookIndex = 0;
	int linesCount = GetLinesCount(txtPhoneBook);
	
	emptyPhoneBook = GetMemory(linesCount);
	if (emptyPhoneBook == NULL)
	{
		return NULL;
	}
	char* buffer = calloc(200, sizeof(char));
	
	if (buffer == NULL)
	{
		return NULL;
	}
	

	while (phoneBookIndex != linesCount)
	{
		fgets(buffer, 200, txtPhoneBook);
		CopyContactFromBuffer(buffer, &currentIndex, &emptyPhoneBook[phoneBookIndex]);
		currentIndex = 0;
		phoneBookIndex++;
	}
	fclose(txtPhoneBook);
	free(buffer);

	return emptyPhoneBook;
}
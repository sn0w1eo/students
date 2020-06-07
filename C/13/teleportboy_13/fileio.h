#ifndef FILEIO_H
#define FILEIO_H

#include "stdio.h"

#include "phonebook.h"

PhoneBook* ReadInfoFromFile(PhoneBook* phoneBook);
void RecordInfoToTXT(PhoneBook* phoneBook);

int GetStringLengthFromBuffer(char* buffer, int* currentIndex);
int GetLinesCount(FILE* txtPhoneBook);

void CopyContactFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook);
void CopyNameFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook);
void CopyPhoneNumberFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook);
void CopyEmailFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook);
void CopyZipCodeFromBuffer(char* buffer, int* currentIndex, PhoneBook* emptyPhoneBook);


#endif // !FILEIO_H
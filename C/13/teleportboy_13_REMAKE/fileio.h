#ifndef FILEIO_H
#define FILEIO_H

#include "stdio.h"

#include "phonebook.h"
#include "memory.h"

//=========================================================ОБЫЧНЫЙ РЕЖИМ=========================================================
void RecordInfoToTXT(PhoneBook* _Source);
int GetLinesCount(FILE* _StreamTXT);
int GetStringLengthFromBuffer(char* _Buffer, int* currentIndex);
void CopyNameFromBuffer(char* _Buffer, int* currentIndex, ContactData* _PointerToContact);
void CopyPhoneFromBuffer(char* _Buffer, int* currentIndex, ContactData* _PointerToContact);
void CopyEmailFromBuffer(char* _Buffer, int* currentIndex, ContactData* _PointerToContact);
void CopyZipCodeFromBuffer(char* _Buffer, int* currentIndex, ContactData* _PointerToContact);
void CopyContactFromBuffer(char* _Buffer, int* currentIndex, ContactData* _PointerToContact);
void ReadInfoFromFile(PhoneBook* _Destination);

//=========================================================БИНАРНЫЙ РЕЖИМ=========================================================
void BinaryRecordInfoToDAT(PhoneBook* _Source);
void BinaryReadInfoFromFile(Contact* _Destination, int contactsCount);

void PrintContactsBinMode(Contact* _Source, int _ElementsCount);

#endif // !FILEIO_H
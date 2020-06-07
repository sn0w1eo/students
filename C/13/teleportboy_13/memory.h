#ifndef MEMORY_H
#define MEMORY_H

#include "phonebook.h"

//Выделить/перераспределить память.
PhoneBook* GetMemory(int size);

//Перераспределить память.
PhoneBook* ReallocMemory(PhoneBook*);

//Осовободить память.
void FreeMemory(PhoneBook*, PhoneBook*, PhoneBook**);

void FreeContactMemory(PhoneBook* phoneBook, int contactIndex);

#endif // !MEMORY_H
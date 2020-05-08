#ifndef MEMORY_H
#define MEMORY_H

#include "phonebook.h"

//Выделить/перераспределить память.
phonebook* GetMemory(phonebook* phoneBook);

//Осовободить память.
void FreeMemory(phonebook* phoneBook);

#endif // !MEMORY_H
#ifndef MEMORY_H
#define MEMORY_H

#include "phonebook.h"

//Выделить/перераспределить память.
PHONEBOOK* GetMemory(int);

//Перераспределить память.
PHONEBOOK* ReallocMemory(PHONEBOOK*);

//Осовободить память.
void FreeMemory(PHONEBOOK*);

#endif // !MEMORY_H

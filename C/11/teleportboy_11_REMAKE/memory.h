#ifndef MEMORY_H
#define MEMORY_H

#include "phonebook.h"

//��������/���������������� ������.
PHONEBOOK* GetMemory(int);

//���������������� ������.
PHONEBOOK* ReallocMemory(PHONEBOOK*);

//����������� ������.
void FreeMemory(PHONEBOOK*);

#endif // !MEMORY_H

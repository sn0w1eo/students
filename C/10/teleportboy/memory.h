#ifndef MEMORY_H
#define MEMORY_H

//Cиноним к unsigned char.
typedef unsigned char uchar;

//Перераспределить память "основного блока памяти" (массив указателей на указатели).
void* GetMemory(uchar** list);

//Очистить всю выделенную для программы память.
void FreeMemory(uchar** list);

#endif // !MEMORY_H

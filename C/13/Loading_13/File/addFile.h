#ifndef ADDFILE_H
#define ADDFILE_H

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "windows.h"

typedef struct
{
	char* name;
	int age;
	char* number;
}MyStructFile;


void writeFile(FILE* stream, MyStructFile*);

#endif // !ADDFILE_H


#ifndef ADDCONSOLE_H
#define ADDCONCOLE_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct
{
	char* name;
	int age;
	char* number;
}MyStruct;

void add(MyStruct* contact, char name[50], int age, char number[50]);

void compare(FILE* ,MyStruct*);
void strcopy(char*, const char*);
// ASC
int compareName(const void*, const void*);
int compareInteger(const void*, const void*);
int compareNumber(const void*, const void*);
// DESC
int compareName1(const void*, const void*);
int compareInteger1(const void*, const void*);
int compareNumber1(const void*, const void*);
// Show
void read(MyStruct*);


#endif // !PHONE_H


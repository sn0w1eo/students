#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct
{
	char* name;
	int  integer;
	double double1;
}MyStruct;

void add(MyStruct*, char name[100], int, double);
void compare(MyStruct*);
void strcopy(char*, const char*);
// ASC
int compareName(const void*, const void*);
int compareInteger(const void*, const void*);
int compareDouble(const void*, const void*);
// DESC
int compareName1(const void*, const void*);
int compareInteger1(const void*, const void*);
int compareDouble1(const void*, const void*);
// Show
void read(MyStruct* );

#endif // !OPERATIONS_H
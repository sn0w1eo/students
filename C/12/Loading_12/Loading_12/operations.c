#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "operations.h"

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}

void add(MyStruct *temp, char name[100],int number, double number1)
{
	{
		size_t len = strlen(name);
		temp->name = malloc(len + 1);
		if (temp->name == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(temp->name, name);
		}
	}
	{
		temp->integer = number;
	}
	{
		temp->double1 = number1;
	}
}
// ASC
int compareName(const void* a,const void* b) 
{
	const MyStruct* name1 = a;
	const MyStruct* name2 = b;
	return strcmp(name1->name, name2->name);
}

int compareInteger(const void* a, const void* b)
{
	const MyStruct* integer1 = a;
	const MyStruct* integer2 = b;
	return integer1->integer - integer2->integer;
}

int compareDouble(const void* a, const void* b)
{
	double result;
	const MyStruct* double1 = a;
	const MyStruct* double2 = b;
	result = double1->double1 - double2->double1;
	if (result > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 0;
}

// DESC
int compareName1(const void* a, const void* b)
{
	const MyStruct* name1 = a;
	const MyStruct* name2 = b;
	return strcmp(name2->name, name1->name);
}

int compareInteger1(const void* a, const void* b)
{
	const MyStruct* integer1 = a;
	const MyStruct* integer2 = b;
	return integer2->integer - integer1->integer;
}

int compareDouble1(const void* a, const void* b)
{
	double result;
	const MyStruct* double1 = a;
	const MyStruct* double2 = b;
	result = double2->double1 - double1->double1;
	if (result > 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
	return 0;
}
// Show
void read(MyStruct* temp)
{
	for (int i = 0; i <5; i++)
	{
		printf("%d    %s    %5d    %lf\n", i, temp[i].name, temp[i].integer, temp[i].double1);
	}
}

void compare(MyStruct* temp)
{
	printf("----------------------------------------");
	printf("\nASC\n");
	printf("----------------------------------------");
	printf("\nbyNAME\n");
	qsort(temp, 5, sizeof(MyStruct), compareName);
	read(temp);
	printf("\nbyINTEGER\n");
	qsort(temp, 5, sizeof(MyStruct), compareInteger);
	read(temp);
	printf("\nbyDOUBLE\n");
	qsort(temp, 5, sizeof(MyStruct), compareDouble);
	read(temp);
	printf("----------------------------------------");
	printf("\nDESC\n");
	printf("----------------------------------------");
	printf("\nbyNAME\n");
	qsort(temp, 5, sizeof(MyStruct), compareName1);
	read(temp);
	printf("\nbyINTEGER\n");
	qsort(temp, 5, sizeof(MyStruct), compareInteger1);
	read(temp);
	printf("\nbyDOUBLE\n");
	qsort(temp, 5, sizeof(MyStruct), compareDouble1);
	read(temp);
}


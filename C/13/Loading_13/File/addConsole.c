#include "addFile.h"
#include "addConsole.h"

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}


void add(MyStruct* contact , char name[50], int age, char number[50])
{
	// add name
	{
		size_t len = strlen(name);
		contact->name = malloc(len + 1);
		if (contact->name == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(contact->name, name);
		}
	}

	// add age
	contact->age = age;

	// add number
	{
		size_t len = strlen(number);
		contact->number = malloc(len + 1);
		if (contact->number == NULL)
		{
			printf("Not mamory");
		}
		else
		{
			strcopy(contact->number, number);
		}
	}
}

// ASC
int compareName(const void* a, const void* b)
{
	const MyStruct* name1 = a;
	const MyStruct* name2 = b;
	return strcmp(name1->name, name2->name);
}

int compareInteger(const void* a, const void* b)
{
	const MyStruct* integer1 = a;
	const MyStruct* integer2 = b;
	return integer1->age - integer2->age;
}

int compareNumber(const void* a, const void* b)
{
	const MyStruct* number1 = a;
	const MyStruct* number2 = b;
	return strcmp(number1->number, number2->number);
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
	return integer2->age - integer1->age;
}

int compareNumber1(const void* a, const void* b)
{
	const MyStruct* number1 = a;
	const MyStruct* number2 = b;
	return strcmp(number2->number, number1->number);
}

// Show
void read(MyStruct* temp)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d    %s    %5d    %s\n", i, temp[i].name, temp[i].age, temp[i].number);
	}
}

void compare(FILE* stream, MyStruct* temp)
{
	qsort(temp, 5, sizeof(MyStruct), compareName);

	fprintf(stream, "----------------------------------------");
	fprintf(stream, "\nASC\n");
	fprintf(stream, "----------------------------------------");
	fprintf(stream, "\nbyNAME\n");
	writeFile(stream, temp);
	fprintf(stream, "\nbyINTEGER\n");
	qsort(temp, 5, sizeof(MyStruct), compareInteger);
	writeFile(stream, temp);
	fprintf(stream, "\nbyNUMBER\n");
	qsort(temp, 5, sizeof(MyStruct), compareNumber);
	writeFile(stream, temp);
	fprintf(stream, "----------------------------------------");
	fprintf(stream, "\nDESC\n");
	fprintf(stream, "----------------------------------------");
	fprintf(stream, "\nbyNAME\n");
	qsort(temp, 5, sizeof(MyStruct), compareName1);
	writeFile(stream, temp);
	fprintf(stream, "\nbyINTEGER\n");
	qsort(temp, 5, sizeof(MyStruct), compareInteger1);
	writeFile(stream, temp);
	fprintf(stream, "\nbyNUMBER\n");
	qsort(temp, 5, sizeof(MyStruct), compareNumber1);
	writeFile(stream, temp);
}

void compareConsole(MyStruct* temp)
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
	printf("\nbyNumber\n");
	qsort(temp, 5, sizeof(MyStruct), compareNumber);
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
	printf("\nbyNUMBER\n");
	qsort(temp, 5, sizeof(MyStruct), compareNumber1);
	read(temp);
}

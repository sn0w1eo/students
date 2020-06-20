#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "operations.h"
#include "compare.h"

// Compare string  (ASC) 
int compareNameASC(const void* a, const void* b)
{
	const contact* name1 = a;
	const contact* name2 = b;
	return strcmp(name1->name, name2->name);
}

int compareNumberASC(const void* a, const void* b)
{
	const contact* number1 = a;
	const contact* number2 = b;
	return strcmp(number1->number, number2->number);
}

int compareAgeASC(const void* a, const void* b)
{
	const contact* integer1 = a;
	const contact* integer2 = b;
	return strcmp(integer1->age, integer2->age);
}

// Compare string (DESC) 
int compareNameDESC(const void* a, const void* b)
{
	const contact* name1 = a;
	const contact* name2 = b;
	return strcmp(name2->name, name1->name);
}

int compareNumberDESC(const void* a, const void* b)
{
	const contact* number1 = a;
	const contact* number2 = b;
	return strcmp(number2->number, number1->number);
}

int compareAgeDESC(const void* a, const void* b)
{
	const contact* integer1 = a;
	const contact* integer2 = b;
	return strcmp(integer2->age, integer1->age);
}

/*----------------------SORT---- ASC--------------------------------*/
void sortByNameASC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream, "----------------------");
	fprintf(stream, "\nASC\n");
	fprintf(stream, "----------------------");
	fprintf(stream, "\nbyNAME\n");

	qsort(person, 5, sizeof(contact), compareNameASC);
	writeToText(stream, person);           // Output to Text File
	changeZeroToSpace(person);             // Change zero '\0' to ' ' for binary
	writeToBinary(streamBin, person);      // Output to Binary File
	changeSpaceToZero(person);             // Change space ' ' to '\0' 

	fclose(stream);
	fclose(streamBin);
}

void sortByNumberASC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream,"\nbyNumber\n");

	qsort(person, 5, sizeof(contact), compareNumberASC);
	writeToText(stream, person);        // Output to Text File
	changeZeroToSpace(person);          // Change zero '\0' to ' ' for binary
	writeToBinary(streamBin, person);   // Output to Binary File
	changeSpaceToZero(person);          // Change space ' ' to '\0' 

	fclose(stream);
	fclose(streamBin);
}

void sortByAgeASC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream, "\nbyAge\n");

	qsort(person, 5, sizeof(contact), compareAgeASC);
	writeToText(stream, person);
	changeZeroToSpace(person);
	writeToBinary(streamBin, person);
	changeSpaceToZero(person);

	fclose(stream);
	fclose(streamBin);
}

/*----------------------SORT----DESC--------------------------------*/
void sortByNameDESC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream, "----------------------");
	fprintf(stream, "\nDESC\n");
	fprintf(stream, "----------------------");
	fprintf(stream, "\nbyNAME\n");

	qsort(person, 5, sizeof(contact), compareNameDESC);
	writeToText(stream, person);
	changeZeroToSpace(person);
	writeToBinary(streamBin, person);
	changeSpaceToZero(person);

	fclose(stream);
	fclose(streamBin);
}

void sortByNumberDESC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream, "\nbyNumber\n");

	qsort(person, 5, sizeof(contact), compareNumberDESC);
	writeToText(stream, person);
	changeZeroToSpace(person);
	writeToBinary(streamBin, person);
	changeSpaceToZero(person);

	fclose(stream);
	fclose(streamBin);
}

void sortByAgeDESC(contact* person)
{
	FILE* stream = fopen("phoneBook.txt", "a");
	FILE* streamBin = fopen("phoneBookBin.dat", "ab+");
	if (stream == NULL || streamBin == NULL) {
		printf("ooops open file failed\n");
	}
	fprintf(stream, "\nbyAge\n");

	qsort(person, 5, sizeof(contact), compareAgeDESC);
	writeToText(stream, person);
	changeZeroToSpace(person);
	writeToBinary(streamBin, person);
	changeSpaceToZero(person);

	fclose(stream);
	fclose(streamBin);
}

	
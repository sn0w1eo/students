#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "operations.h"
#include "compare.h"

int main()
{
	FILE* stream = fopen("phoneBook.txt","w");
	FILE* streamBin = fopen("phoneBookBin.dat", "wb+");
	if (stream == NULL || streamBin == NULL){
		printf("ooops open file failed\n");
		return -1;
	}
	contact person[5] = { 0x00 };

	// Add person to array 
	add(&person[0], "Nurik ", "0700561232", "20");
	add(&person[1], "Dima  ", "0550988552", "25");
	add(&person[2], "Kirill", "0755122356", "22");
	add(&person[3], "Nastya", "0500575859", "30");
	add(&person[4], "Kostya", "0900536332", "28");

	fprintf(stream, "Ordinary list\n----------------------\n");  // TXT FAIL

	// Write persons to text FILE
	writeToText(stream, person);
	
	// Change zero at the end of the string to space ' ' 
	changeZeroToSpace(person);

	// Write persons to binary FILE
	writeToBinary(streamBin,person);

	// Change space ' ' to zero '\0'
	changeSpaceToZero(person);

	// Sort by name (ASC)
	sortByNameASC(person);

	// Sort by number (ASC)
	sortByNumberASC(person);

	// Sort by age (ASC)
	sortByAgeASC(person);
	
	// Sort by name (DESC)
	sortByNameDESC(person);

	// Sort by number (DESC)
	sortByNumberDESC(person);

	// Sort by age (DESC)
	sortByAgeDESC(person);

	// Read from Binary FILE to array
	readFileToArray();

	fclose(stream);
	fclose(streamBin);
}
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "operations.h"


// Add person to array
void add(contact* person, char name[30], char number[30], char age[5])
{
	strcpy(person->name, name);
	strcpy(person->number, number);
	strcpy(person->age, age);
}

// Write persons to text FILE
void writeToText(FILE* stream, contact* person)
{
	for (int i = 0; i < 5; i++) {
		fprintf(stream, "%s  %s  %s\n", person[i].name, person[i].number, person[i].age);
	}
	fclose(stream);
}

// Change zero at the end of the string to space ' ' 
void changeZeroToSpace(contact* person)
{
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 30; i++)
		{
			if (person[k].name[i] == 0x00)    // If the line ends with zero 
				person[k].name[i] = ' ';      //  then we change to a space
			if (person[k].number[i] == 0x00)  //
				person[k].number[i] = ' ';    //
		}
		for (int j = 0; j < 5; j++)
		{
			if (person[k].age[j] == 0x00)     // in age we have only 5 bytes
				person[k].age[j] = ' ';       //  if some bytes ends with zero  we change to a space
		}
	}
}

// Change space ' ' at the end of the string to zero '\0'
void changeSpaceToZero(contact* person)
{
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 30; i++)
		{
			if (person[k].name[i] == ' ')      // If the line ends with space ' ' 
				person[k].name[i] = 0x00;      //  then we change to zero '\0'
			if (person[k].number[i] == ' ')    //
				person[k].number[i] = 0x00;    //
		}
		for (int j = 0; j < 5; j++)
		{
			if (person[k].age[j] == ' ')       // in age we have only 5 bytes
				person[k].age[j] = 0x00;       //  if some bytes ends with space' ' we change it to zero '\0'
		}
	}

}

// Write persons to binary FILE
void writeToBinary(FILE* streamBin ,contact* person)
{
	fwrite(person, sizeof(contact), 5, streamBin); 
	fclose(streamBin);
}

// Read from BIN FILE to array
void readFileToArray()
{
	contact person[5];                               // Array to write value 
	FILE* stream = fopen("phoneBookBin.dat", "rb");  // Open file to read
	if (stream == NULL) {
		printf("ooops open file failed\n");
	}
	for (int i = 0; i < 7; i++ ) {
		switch (i)
		{
		case 1:	printf("----------------------");
				printf("\nASC\n");
				printf("----------------------");
				printf("\nbyNAME\n");
				break;
		case 2: printf("\nbyNumber\n");
				break;
		case 3: printf("\nbyAge\n");
				break;
		case 4: printf("----------------------");
				printf("\nDESC\n");
				printf("----------------------");
				printf("\nbyNAME\n");
				break;
		case 5: printf("\nbyNumber\n");
			    break;
		case 6: printf("\nbyAge\n");
				break;
		}
		fseek(stream, 0, SEEK_CUR);                 // Current position of the file pointer
		fread(person, sizeof(contact), 5, stream);  // Read from File to array
		changeSpaceToZero(person);                  // Change space ' ' to zero '\0'
		for (int i = 0; i < 5; i++)
		{
			printf("%s %s %s", person[i].name, person[i].number, person[i].age);
			printf("\n");
		}
	}
	fclose(stream);
}



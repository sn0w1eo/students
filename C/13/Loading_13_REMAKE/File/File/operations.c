#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "operations.h"

static int arrayCount = 0; // Variable to count an array of structure
                           // we use it in readFromFileToArray(mode == Text) function
                           // to count for loop end put this variable bufferToArrayStruct func!

void addPerson(contact* persons, char name[10], char phone[15], char age[5]){
	for (int i = 0; i < persons->size ; i++)
	{
		if (persons[i].name[0] == 0x00) { // If the name is zero then write the person
			strcpy(persons[i].name, name);
			strcpy(persons[i].phone, phone);
			strcpy(persons[i].age, age);
			break;
		}
	}
}

void writeToFile(contact* persons, int mode)
{
	if (mode == Binary) { // From ENUM mode == Binary == 0
		FILE* streamBin = fopen("phoneBook.dat", "wb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		fwrite(persons, sizeof(contact), persons->size, streamBin);
		fclose(streamBin);
		streamBin = NULL;
	} 
	else // mode == Text == 1 
	{
		FILE* streamText = fopen("phoneBook.txt", "w"); 
		if (streamText == NULL) {
			printf("Open file failed\n");
		}
		for (int i = 0; i < persons->size ; i++)
		{
			fprintf(streamText, "%s %s %s\n", persons[i].name, persons[i].phone, persons[i].age);
		}
		fclose(streamText);
		streamText = NULL;
	}
}

void readFromFileToArray(contact* persons, int mode)
{
	if (mode == Binary) { // From ENUM mode == Binary == 0
		FILE* streamBin = fopen("phoneBook.dat", "rb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		fread(persons, sizeof(contact), persons->size, streamBin);
		fclose(streamBin);
		streamBin = NULL;
	}
	else // mode == Text == 1
	{
		FILE* streamText = fopen("phoneBook.txt", "r");
		if (streamText == NULL) {
			printf("Open file failed\n");
		}
		char buffer[BUFFER_SIZE];
		for (; arrayCount < persons->size; arrayCount++) // static int arrayCount
		{
			fgets(buffer, BUFFER_SIZE, streamText);     // BUFFER_SIZE == 100;
			bufferToArrayStruct(buffer, persons);
		}
		fclose(streamText);
		streamText = NULL;
	}
}

void printDataToConsole(contact* persons, int mode) {  
	if (mode == Binary) { // From ENUM mode == Binary == 0x00
		printf("---ReadFromBinary---\n");
		for (int i = 0; i < persons->size; i++)
		{
			printf("%s %s %s\n", persons[i].name, persons[i].phone, persons[i].age);
		}
	}
	else  // mode == Text == 0x01 
	{
		printf("----ReadFromText----\n");
		for (int i = 0; i < persons->size; i++)
		{
			printf("%s%s%s\n", persons[i].name, persons[i].phone, persons[i].age);
		}
	}
}

// write to Array struct from buffer (buffer from text file)
void bufferToArrayStruct(char buffer[BUFFER_SIZE], contact* persons)                    // BUFFER_SIZE == 100;
{	
	int getch = 0,                                                                     // Count (switch)
		sizeName = 0,                                                                  // To know how many bytes takes "NAME"
		sizePhone = 0,                                                                 // To know how many bytes takes "PHONE"
	    sizeAge = 0;                                                                   // To know how many bytes takes "AGE"
	for (int i = 0; i < BUFFER_SIZE; i++) {
		if (buffer[i] == ' ')                                                          // if we find ' ' we find out  
                                                                                       // first string is "Name" 
                                                                                       // second string is "Phone"
		{                                                                              // third string is "Age"
			getch++;
			switch (getch)
			{
			case Name:
				sizeName = i;
				strncpy(persons[arrayCount].name, &buffer[0], sizeName);                // Copies up to sizeName characters 
				break;                                                                 // from buffer to person->name 
			case Phone:
				sizePhone = i - sizeName;
				strncpy(persons[arrayCount].phone, &buffer[sizeName], sizePhone);       // Copies up to sizeName characters
				break;                                                                 // from buffer to person->phone 
			}
		}
		else if (buffer[i] == '\n')
		{
			sizeAge = i - sizeName - sizePhone;
			strncpy(persons[arrayCount].age, &buffer[sizePhone + sizeName], sizeAge);   // Copies up to sizeName characters
			break;                                                                     // from buffer to person->age 
		}
	}
}
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "operations.h"

static int arrayCount = 0; // Variable to count an array of structure
                           // we use it in readFromFileToArray(mode == Text) function
                           // to count for loop end put this variable bufferToArrayStruct func!

void addPerson(contact* person, char name[10], char phone[15], char age[5]){
	for (int i = 0; i < person->size ; i++)
	{
		if (person[i].name[0] == 0x00) { // If the name is zero then write the person
			strcpy(person[i].name, name);
			strcpy(person[i].phone, phone);
			strcpy(person[i].age, age);
			break;
		}
	}
}

void writeToFile(contact* person, int mode)
{
	if (mode == Binary) { // From ENUM mode == Binary == 0
		FILE* streamBin = fopen("phoneBook.dat", "wb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		fwrite(person, sizeof(contact), person->size, streamBin);
		fclose(streamBin);
		streamBin = NULL;
	} 
	else // mode == Text == 1 
	{
		FILE* streamText = fopen("phoneBook.txt", "w"); 
		if (streamText == NULL) {
			printf("Open file failed\n");
		}
		for (int i = 0; i < person->size ; i++)
		{
			fprintf(streamText, "%s %s %s\n", person[i].name, person[i].phone, person[i].age);
		}
		fclose(streamText);
		streamText = NULL;
	}
}

void readFromFileToArray(contact* person, int mode)
{
	if (mode == Binary) { // From ENUM mode == Binary == 0
		FILE* streamBin = fopen("phoneBook.dat", "rb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		fread(person, sizeof(contact), person->size, streamBin);
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
		for (; arrayCount < person->size; arrayCount++) // static int arrayCount
		{
			fgets(buffer, BUFFER_SIZE, streamText);     // BUFFER_SIZE == 100;
			bufferToArrayStruct(buffer, person);
		}
		fclose(streamText);
		streamText = NULL;
	}
}

void printDataToConsole(contact* person, int mode) {  
	if (mode == Binary) { // From ENUM mode == Binary == 0x00
		printf("---ReadFromBinary---\n");
		for (int i = 0; i < person->size; i++)
		{
			printf("%s %s %s\n", person[i].name, person[i].phone, person[i].age);
		}
	}
	else  // mode == Text == 0x01 
	{
		printf("----ReadFromText----\n");
		for (int i = 0; i < person->size; i++)
		{
			printf("%s%s%s\n", person[i].name, person[i].phone, person[i].age);
		}
	}
}

// write to Array struct from buffer (buffer from text file)
void bufferToArrayStruct(char buffer[BUFFER_SIZE], contact* person)                    // BUFFER_SIZE == 100;
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
				strncpy(person[arrayCount].name, &buffer[0], sizeName);                // Copies up to sizeName characters 
				break;                                                                 // from buffer to person->name 
			case Phone:
				sizePhone = i - sizeName;
				strncpy(person[arrayCount].phone, &buffer[sizeName], sizePhone);       // Copies up to sizeName characters
				break;                                                                 // from buffer to person->phone 
			}
		}
		else if (buffer[i] == '\n')
		{
			sizeAge = i - sizeName - sizePhone;
			strncpy(person[arrayCount].age, &buffer[sizePhone + sizeName], sizeAge);   // Copies up to sizeName characters
			break;                                                                     // from buffer to person->age 
		}
	}
}
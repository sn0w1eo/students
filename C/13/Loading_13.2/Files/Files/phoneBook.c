#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "phoneBook.h"

contact* initStorage(contact* person)
{
	person = realloc(person, (++(person->size)) * sizeof(contact));
	person[person->size - 1].name = NULL;
	return person;
}

contact* addPerson(contact* person, char name[100], char phone[100], char age[100])
{
	for (int i = 0; i < person->size; i++)
	{
		if (person[i].name == NULL) {
			person[i].name = malloc(strlen(name) + 1);
			strcpy(person[i].name, name);
			person[i].phone = malloc(strlen(phone) + 1);
			strcpy(person[i].phone, phone);
			person[i].age = malloc(strlen(age) + 1);
			strcpy(person[i].age, age);
			break;
		}
	}
	return person = initStorage(person);  
}

void writeToFile(contact* person, int mode)
{
	if (mode == Binary){
		FILE* streamBin = fopen("phoneBook.dat", "wb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		for (int i = 0; i < (person->size - 1); i++)
		{
			fprintf(streamBin,"%s %s %s ", person[i].name, person[i].phone, person[i].age);
		}
		fclose(streamBin);
	}
	else if (mode == Text) {
		FILE* stream = fopen("phoneBook.txt", "w");
		if (stream == NULL) {
			printf("Open file failed\n");
		}
		for (int i = 0; i < (person->size - 1); i++)
		{
			fprintf(stream, "%s %s %s\n", person[i].name, person[i].phone, person[i].age);
		}
		fclose(stream);
	}
}

void readFromFile(contact* person, int mode)
{
	if (mode == Binary) {
		FILE* streamBin = fopen("phoneBook.dat", "rb");
		if (streamBin == NULL) {
			printf("Open file failed\n");
		}
		printf("---ReadFromBinary---\n");
		for (int i = 0; i < (person->size - 1); i++)
		{
			int len = strlen(person[i].name) + strlen(person[i].phone) + strlen(person[i].age);
			contact temp;
			fread(&temp, sizeof(len), 1, streamBin);
			fprintf(stdout, "%s %s %s\n", person[i].name, person[i].phone, person[i].age);
		}
		fclose(streamBin);
	}
	else if (mode == Text) {
		FILE* stream = fopen("phoneBook.txt", "r");
		if (stream == NULL) {
			printf("Open file failed\n");
		}
		printf("----ReadFromText----\n");
		for (int i = 0; i < (person->size - 1); i++)
		{
			int len = strlen(person[i].name) + strlen(person[i].phone) + strlen(person[i].age);
			contact temp;
			fread(&temp, sizeof(len), 1, stream);
			fprintf(stdout, "%s %s %s\n", person[i].name, person[i].phone, person[i].age);
		}
		fclose(stream);
	}
}

void freeMemory(contact* person)
{
	for (int i = 0; i < (person->size - 1); i++)
	{
		free(person[i].phone);
		person[i].phone = NULL;
		free(person[i].name);
		person[i].name = NULL;
		free(person[i].age);
		person[i].age = NULL;
	}
	free(person);
	person = NULL;
}
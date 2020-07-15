#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

typedef struct {
	char name[10];
	int phone;
	int age;
}PhoneBook;

void textFile(FILE* readPtr);
void binaryFile(FILE* cfPtr);



int main() {
	FILE* file;
	PhoneBook contact;

	if ((file = fopen("file.dat", "rb+")) == NULL) {		//open file txt
		puts("File not found!");
	}
	else {
		while (!feof(stdin)) {
			fprintf(file, "%s %d %d\n", contact.name, contact.phone, contact.age);
		}
		fclose(file);
	}

	return 0;
}

void binaryFile(FILE* cfPtr) {
	FILE* cfPtr;
	PhoneBook contact;
	if ((cfPtr = fopen("binary_file.dat", "wb")) == NULL) {
		puts("ERROR!");
	}
	else {
		for (int i = 1; i <= 100; i++) {						//додумать надо 
			fwrite(&contact, sizeof(PhoneBook), 1, cfPtr);

		}

		fclose(cfPtr);
	}
}

void textFile(FILE* readPtr ) {
	FILE* writePtr;
	PhoneBook contact;
	if ((writePtr = fopen("contacts.txt", "w")) == NULL) {
		puts("ERROR!");
	}
	else {
		rewind(readPtr);		// возвращает указатель файла на начало 
		fprintf(writePtr, "%s-%d-%d\n", contact.name, contact.phone, contact.age);

		while (!feof(readPtr)) {
			fread(&contact, sizeof(PhoneBook), 1, readPtr);
			if (contact.name != 0) {
				fprintf(writePtr, "%s-%d-%d", contact.name, contact.phone, contact.age);
			}
		}
		fclose(writePtr);
	}
}


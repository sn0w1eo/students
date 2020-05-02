//PONE BOOK

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "windows.h"
#include "string.h"
#include "stdlib.h"

#define RED			0x0E
#define DARK_WHITE	0x08
#define WHITE		0x07
#define GREEN		0x0A
#define YELLOW		0x06

#define SIZE_STORAGE 20

#define NAME_LEN	20
#define PHONE_LEN	15
#define YEAR_LEN	15


void setColor(ColorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}


void* initStorage(size_t size){

	void** storage = malloc(sizeof(char*) * (size + 1));

	if (storage == NULL) {
		setColor(RED);
		printf("faild");
		return NULL;
	}
	storage[0] = malloc(sizeof(int));
	if (storage[0] == NULL) {
		return NULL;
	}
	*((int*)(storage[0])) = size;
	for (size_t i = 1; i <= size; i++) {
		storage[i] = NULL;
	}
	return storage;
}


int addNumber(void *storage, const char* name, const char* number, const char* year) {

	char** storagePtr = storage;
	int* sizePtr = (int*)(storagePtr[0]);

	for (int i = 1; i <= *sizePtr; i++) {
		if (storagePtr[i] == NULL) {
			storagePtr[i] = malloc(NAME_LEN + PHONE_LEN + YEAR_LEN + 1);
			if (storagePtr[i] == NULL) {
				return -1;
			}
			strncpy(storagePtr[i], name, NAME_LEN - 1);
			storagePtr[i][NAME_LEN] = '\0';
			strncpy(&storagePtr[i][NAME_LEN], number, PHONE_LEN);
			storagePtr[i][NAME_LEN + PHONE_LEN] = '\0';
			strncpy(&storagePtr[i][NAME_LEN + PHONE_LEN], year, YEAR_LEN);
			storagePtr[i][NAME_LEN + PHONE_LEN + YEAR_LEN] = '\0';
			setColor(GREEN);
			printf("number added\n");
			setColor(WHITE);
			getch();
			return 1;
		}
	}
	return -1;
}


void printNumbers(void* storage) {

	char** storagePtr = storage;
	unsigned int* sizePtr = (int*)(storagePtr[0]);

	setColor(GREEN);
	printf("Contacts:\n");
	setColor(WHITE);
	for (size_t i = 1; i <= *sizePtr; i++) {
		if (storagePtr[i] != NULL) {
			printf("Name:   %s\n", storagePtr[i]);
			printf("Number: %s\n", &storagePtr[i][NAME_LEN]);
			printf("Year:   %s\n\n", &storagePtr[i][NAME_LEN + PHONE_LEN]);
		}
	}
}


void printInstruction() {

	printf("PHONE BOOK\n");
	printf("___________________________________________\n");
	setColor(DARK_WHITE);
	printf("<a> - add new number\n");
	printf("<s> - show numbers\n");
	printf("<d> - delete number\n");
	printf("<q> - exit");
}

int deleteNumber(void *storage, const char* nameDelete) {

	char** storagePtr = storage;
	unsigned int* size = (int*)(storagePtr[0]);

	for (size_t i = 1; i <= *size; i++) {
		if (storagePtr[i] == NULL) {
			continue;
		}
		if (strcmp(&storagePtr[i][0], nameDelete) == 0) {
			free(storagePtr[i]);
			storagePtr[i] = NULL;
			setColor(YELLOW);
			printf("\ncontact deleted");
			setColor(WHITE);
			getch();
			return 1;
		}
	}
	return 1;
}


void freeStorage(void *storage){

	char** storagePtr = storage;
	int size = ((int*)storagePtr[0])[0];

	for (size_t i = 0; i != size; i++) {
		
		free(storagePtr[i]);
		storagePtr[i] = NULL;
		printf("%d free\n", i);
		
	}
	free(*storagePtr);
	*storagePtr = NULL;
	free(storage);
	storage = NULL;
	getch();
}

int main() {

	void* storage = initStorage(SIZE_STORAGE);

	char key;
	char inputName[NAME_LEN] = { 0x00 };
	char inputNumber[PHONE_LEN] = { 0x00 };
	char inputYear[YEAR_LEN] = { 0x00 };
	char inputDelete[NAME_LEN] = { 0x00 };

	do {
		system("cls");
		printInstruction();
		setColor(WHITE);
		key = getch();
		switch (key) {

		case 'a':
		case 'A':
			system("cls");
			printf("Name: ");
			scanf_s("%s", inputName, NAME_LEN);
			printf("Phone: ");
			scanf_s("%s", inputNumber, PHONE_LEN);
			printf("Year: ");
			scanf_s("%s", inputYear, YEAR_LEN);

			addNumber(storage, inputName, inputNumber, inputYear);
			break;

		case 'd':
		case 'D':
			system("cls");
			printNumbers(storage);
			printf("\n\nWhat contact do you want to delete?\n");
			scanf_s("%s", inputDelete, NAME_LEN);
			deleteNumber(storage, inputDelete);
			break;
		 
		case 's':
		case 'S':
			system("cls");
			printNumbers(storage);
			getch();
			break;

		case 'q':
		case 'Q':
			system("cls");
			freeStorage(storage);
			break;
		}
	}while (1);

	getch();
}
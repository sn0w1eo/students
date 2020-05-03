#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

#define INIT_SIZE 20	//количество контактов, на которое выделяем память

#define RED				0x0C //красный
#define WHITE			0x07 //белый
#define LIGHTBLUE		0x0B //светло-голубой
#define YELLOW			0x06 //жёлтый
#define GREEN			0x02 //зелёный
#define CYAN			0x03 //голубой
#define LIGHTMAGENTA	0x0D //светло-лиловый

#define DATA_SIZE 30	//длина одного контакта имя+номер+год (в байтах)

// функция выбора цвета
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// функция выделения памяти
void *initStorage(size_t size) {
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	void *storagePtr = calloc(1, totalSizeInBytes);
	if (storagePtr==NULL)
	{
		return NULL;
	}
	size_t* sizePtr = storagePtr;
	*sizePtr = size;
	return storagePtr;
}

// функция создания контакта по имени, номеру телефона и году рождения
void createContact(void *storage, const char *name, const unsigned long long int number, const unsigned short year) {
	size_t size = *(size_t *)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	char *charStoragePtr = storage;

	unsigned long long int *phonePtr = NULL;
	unsigned short *yearPtr = NULL;

	for (unsigned int i = 4; i < totalSizeInBytes; i = i + DATA_SIZE)
	{
		if (charStoragePtr[i] == 0x00) {
			strcpy_s(&charStoragePtr[i], 19, name);
			charStoragePtr[i + 19] = 0x00;
			phonePtr = (unsigned long long int*)&charStoragePtr[i + 20];
			*phonePtr = number;
			yearPtr = (unsigned short*)&charStoragePtr[i + 28];
			*yearPtr = year;
			break;
		}
	}
}

// функция удаления контакта по порядковому номеру 
void deleteContact(void* storage) {
	size_t size = *(size_t*)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	char* charStoragePtr = storage;

	unsigned long long int* phonePtr = NULL;
	unsigned short* yearPtr = NULL;
	unsigned int k;
	scanf_s("%u", &k);

	for (unsigned int i = 4; i < DATA_SIZE * k; i = i++)
	{
		if (((i - 4) / DATA_SIZE) + 1 == k) {
			charStoragePtr[i] = 0x00;
			break;
		}
	}
}

// функция распечатки списка
void printContacts(void *storage) {
	size_t size = *(size_t *)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);

	char *charStoragePtr = storage;

	for (unsigned int i = 4; i < totalSizeInBytes; i = i + DATA_SIZE)
	{
		if (charStoragePtr[i] != 0x00)	
		{
			printf("%d.", ((i-4)/ DATA_SIZE)+1);
			printf("Name: %s\n", &charStoragePtr[i]);
			printf("Phone number: %llu\n", *((unsigned long long*)&charStoragePtr[i+20]));
			printf("Birth year: %hu\n", *((unsigned short*)&charStoragePtr[i + 28]));
		}
	}
}

// функция распечатки одного контакта по порядковому номеру
void printOneContact(void* storage) {
	size_t size = *(size_t*)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	unsigned int k;
	scanf_s("%u", &k);
	char* charStoragePtr = storage;
	for (unsigned int i = 4; i < totalSizeInBytes; i = i + DATA_SIZE)
	{
	
			if (((i - 4) / DATA_SIZE) + 1==k)
			{
				printf("%d.", ((i - 4) / DATA_SIZE) + 1);
				printf("Name: %s\n", &charStoragePtr[i]);
				printf("Phone number: %llu\n", *((unsigned long long*) & charStoragePtr[i + 20]));
				printf("Birth year: %hu\n", *((unsigned short*)&charStoragePtr[i + 28]));
			}
	}
}

void updateContact(void* storage, unsigned int k, const unsigned long long int newNumber, const unsigned short newYear) {
	size_t size = *(size_t*)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	char* charStoragePtr = storage;

	unsigned long long int* phonePtr = NULL;
	unsigned short* yearPtr = NULL;
	
	for (unsigned int i = (DATA_SIZE * k) - 10; i < DATA_SIZE * k; i = i++)
	{
		if (((i - 20) / DATA_SIZE) + 1 == k) {
			charStoragePtr[i] = 0x00;
			break;
		}
	}
	for (unsigned int i = (DATA_SIZE*k)-26; i < DATA_SIZE * k; i = i++)
	{
		phonePtr = (unsigned long long int*) & charStoragePtr[i + 20];
		*phonePtr = newNumber;
		yearPtr = (unsigned short*)&charStoragePtr[i + 28];
		*yearPtr = newYear;
		break;
	}

}
void updateNameOfContact(void* storage, unsigned int k, const char* newName) {
	size_t size = *(size_t*)storage;
	size_t totalSizeInBytes = size * DATA_SIZE + sizeof(size_t);
	char* charStoragePtr = storage;

	unsigned long long int* phonePtr = NULL;
	unsigned short* yearPtr = NULL;

	for (unsigned int i = (DATA_SIZE * k) - 26; i < (DATA_SIZE * k) - 10; i = i++)
	{
		if (((i - 4) / DATA_SIZE) + 1 == k) {
			charStoragePtr[i] = 0x00;
			break;
		}
	}
	for (unsigned int i = (DATA_SIZE * k) - 26; i < DATA_SIZE * k; i = i + DATA_SIZE)
	{
		strcpy_s(&charStoragePtr[i], 19, newName);
		charStoragePtr[i + 19] = 0x00;
		break;
	}
}


void getInt(int* x, int min, int max) {
	*x = 0;
	char ch = ' ';
	int skip, st = 0;
	int b = 0, i;
	do
	{
		st = i = skip = 0;
		for (; b = ((ch = getchar()) != '\n'); i++)
		{
			if (ch == EOF) return;
			if ((atoi(&ch)) == 0 && ch != '0') skip = 1;
			else if (b && !skip) { *x *= 10; *x += atoi(&ch); }
			if (*x < min || *x > max) skip = 1;
			if (skip) { *x = 0; st++; }
		}
		if (!b && !i) skip = 1;
	} while (skip || b);
}

int main()
{
	void *storage = initStorage(INIT_SIZE);
	if (storage==NULL)
	{
		printf("memory allocation failed");
		return 0;
	}

	unsigned char buff[20];
	unsigned char newBuff[20];
	unsigned long long int phone = 0;
	unsigned short year;
	unsigned long long int newPhone = 0;
	unsigned short newYear;
	int ch;
	unsigned int k;

	/*получение дескриптора*/
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	/*цвет символов - светло-лиловый. Цвет фона - желтый*/
	SetConsoleTextAttribute(hConsole, (WORD)((YELLOW << 4) | LIGHTMAGENTA));
	/*меню кнопок 0-4 ВЫХОД, ДОБАВЛЕНИЕ КОНТАКТА, ИЗМЕНЕНИЕ КОНТАКТА, ЧТЕНИЕ СПИСКА, УДАЛЕНИЕ КОНТАКТА*/
	printf("Hi! This is a phone book.\nIf you would like to use it, press the corresponding key;)");

	do
	{
		printf("\n0.EXIT\n1.ADD\n2.EDIT PHONE NUMBER AND BIRTH YEAR\n3.EDIT NAME OF CONTACT\n4.READ\n5.DELETE\n");
		getInt(&ch, 0, 5);
		if (ch == 1)
		{
			printf("Name: ");
			scanf_s("%s", buff, 20);
			printf("Phone number: ");
			scanf_s("%llu", &phone);
			printf("Birth year: ");
			scanf_s("%hu", &year);
			createContact(storage, buff, phone, year);
			printf("Contact is added\n");
		}
		else if (ch == 2)
		{
			printf("Enter contact number you want to edit: ");
			scanf_s("%u", &k);
			printf("Enter correct phone number: ");
			scanf_s("%llu", &newPhone);
			printf("And birth year: ");
			scanf_s("%hu", &newYear);
			updateContact(storage, k, newPhone, newYear);
			printf("Contact is edited\n");
		}
		else if (ch == 3)
		{
			printf("Enter contact number you want to edit: ");
			scanf_s("%u", &k);
			printf("Enter true name: ");
			scanf_s("%s", newBuff, 20);
			updateNameOfContact(storage, k, newBuff);
			printf("Contact is edited\n");
		}
		else if (ch == 4)
		{
			printf("All contacts:\n");
			printContacts(storage);
		}
		else if (ch == 5)
		{	
			printf("Enter contact number you want to delete: ");
			deleteContact(storage);
			printf("Deleted!\n");
		}
	}
		while (ch);
	
	free(storage);
	storage = NULL;
	return 0;

}
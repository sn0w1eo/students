
#include "stdio.h"
#include "stdlib.h"
#include "database.h"
#include "string.h"

//размер всей книжки
size_t size = 1;

//выделение памяти (спиздил у Кирилла)
person* initStorage(person* book) {
	//первое выделение памяти
	if (book == NULL) {
		book = calloc(size, sizeof(person));
		if (book == NULL) {
			printf("faild");
			return NULL;
		}
	}
	//последующее выделение
	else {
		size++;
		book = realloc(book, sizeof(person) * size);
		if (book == NULL) {
			printf("faild");
			return NULL;
		}
	}
	return book;
}

//нахер я эту функцию писал 
void addNumber(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {
	dataInput(book, inputName, inputNumber, inputEmail, inputZip);
}

//ввод данных
void dataInput(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {

		setName(&book[size-1], inputName);
		setNumber(&book[size-1], inputNumber);
		setEmail(&book[size-1], inputEmail);
		setZip(&book[size-1], inputZip);
}

//ввод имени
void setName(person* book, char* inputName) {
	book->name = _strdup(inputName);
}

//ввод номера
void setNumber(person* book, char* inputNumber) {
	book->number = _strdup(inputNumber);
}

//ввод мыла
void setEmail(person* book, char* inputEmail) {
	book->email = _strdup(inputEmail);
}

//ввод зипа
void setZip(person* book, char* inputZip) {
	book->zip = _strdup(inputZip);
}



//печать всех контактов
void printContacts(person* book) {
	for (size_t i = 0; i < size; i++) {
		printf("\nName  : %s\n", book[i].name);
		printf("Number: %s\n", book[i].number);
		printf("Email : %s\n", book[i].email);
		printf("ZIP   : %s\n", book[i].zip);
	}
}

//шапка программы
void printInstruction() {
	printf("PHONE BOOK v 2\n"
		"_______________________\n"
		"<a> - add new contact\n"
		"<s> - show contacts\n"
		"<w> - find contact\n"
		"<d> - delete contact\n"
		"<q> - exit\n"
		
		"_______________________\n");
}

//при выходе очистка памяти
void freeContacts(person* book) {
	for (size_t i = 0; i < size; i++) {
		if (&book[i] != NULL) {
			free(book[i].name);
			free(book[i].number);
			free(book[i].email);
			free(book[i].zip);
		}
	}
	free(book);
	book = NULL;
}

//находит в нашем блоке памяти соответствующее имя и возвращает ИНДЕКС этого блока(структуры)
//если не найдено возвращает -1
int findName(person* book) {
	char findName[20] = { 0x00 };

	printf("Name: ");
	scanf_s("%s", findName, 20);

	for (size_t i = 0; i < size; i++) {
		if (book[i].name == NULL) {
			continue;
		}
		if (strcmp(findName, book[i].name) == 0) {
			return i;
		}
	}
	return -1;
}

int findNumber(person* book) {
	char findNumber[20] = { 0x00 };

	printf("Number: ");
	scanf_s("%s", findNumber, 20);

	for (size_t i = 0; i < size; i++) {
		if (book[i].number == NULL) {
			continue;
		}
		if (strcmp(findNumber, book[i].number) == 0) {
			return i;
		}
	}
	return-1 ;
}

int findEmail(person* book) {
	char findEmail[20] = { 0x00 };

	printf("Email: ");
	scanf_s("%s", findEmail, 20);

	for (size_t i = 0; i < size; i++) {
		if (book[i].email == NULL) {
			continue;
		}
		if (strcmp(findEmail, book[i].email) == 0) {
			return i;
		}
	}
	return-1;
}

int findZip(person* book) {
	char findZip[20] = { 0x00 };

	printf("ZIP: ");
	scanf_s("%s", findZip, 20);

	for (size_t i = 0; i < size; i++) {
		if (book[i].zip == NULL) {
			continue;
		}
		if (strcmp(findZip, book[i].zip) == 0) {
			return i;
		}
	}
	return-1;
}

//Callback функция которая выводит найденый контакт
void showContact(person* book, int i) {
	//если контакт не найден
	if (i == -1) {
		printf("not found\n");
	}
	else {
		printf("\nName: %s\n", book[i].name);
		printf("Number: %s\n", book[i].number);
		printf("Email: %s\n", book[i].email);
		printf("ZIP: %s\n", book[i].zip);
	}
}

//Callback функция которая удаляет найденый контакт
void deleteContact(person* book, int i) {
	if (i == -1) {
		printf("notFound\n");
	}
	else {
		book[i].name = NULL;
		free(book[i].name);
		book[i].number = NULL;
		free(book[i].number);
		book[i].email = NULL;
		free(book[i].email);
		book[i].zip = NULL;
		free(book[i].zip);
	}
}
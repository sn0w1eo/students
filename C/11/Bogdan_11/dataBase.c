
#include "stdio.h"
#include "stdlib.h"
#include "database.h"
#include "string.h"

//������ ���� ������
size_t size = 1;

//��������� ������ (������� � �������)
person* initStorage(person* book) {
	//������ ��������� ������
	if (book == NULL) {
		book = calloc(size, sizeof(person));
		if (book == NULL) {
			printf("faild");
			return NULL;
		}
	}
	//����������� ���������
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

//����� � ��� ������� ����� 
void addNumber(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {
	dataInput(book, inputName, inputNumber, inputEmail, inputZip);
}

//���� ������
void dataInput(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {

		setName(&book[size-1], inputName);
		setNumber(&book[size-1], inputNumber);
		setEmail(&book[size-1], inputEmail);
		setZip(&book[size-1], inputZip);
}

//���� �����
void setName(person* book, char* inputName) {
	book->name = _strdup(inputName);
}

//���� ������
void setNumber(person* book, char* inputNumber) {
	book->number = _strdup(inputNumber);
}

//���� ����
void setEmail(person* book, char* inputEmail) {
	book->email = _strdup(inputEmail);
}

//���� ����
void setZip(person* book, char* inputZip) {
	book->zip = _strdup(inputZip);
}



//������ ���� ���������
void printContacts(person* book) {
	for (size_t i = 0; i < size; i++) {
		printf("\nName  : %s\n", book[i].name);
		printf("Number: %s\n", book[i].number);
		printf("Email : %s\n", book[i].email);
		printf("ZIP   : %s\n", book[i].zip);
	}
}

//����� ���������
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

//��� ������ ������� ������
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

//������� � ����� ����� ������ ��������������� ��� � ���������� ������ ����� �����(���������)
//���� �� ������� ���������� -1
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

//Callback ������� ������� ������� �������� �������
void showContact(person* book, int i) {
	//���� ������� �� ������
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

//Callback ������� ������� ������� �������� �������
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
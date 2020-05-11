#ifndef DATABASE_H
#define DATABASE_H

typedef struct person {
	char* name;
	char* number;
	char* email;
	char* zip;
}person;

enum iterrate {
	NAME = 1,
	NUMBER,
	EMAIL,
	ZIP
};

person* initStorage(person* book);
void addNumber(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip);
void printContacts(person* book);
void setNumber(person* book, char* inputName);
void dataInput(person* book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip);
void setName(person* book, char* inputName);
void setNumber(person* book, char* inputNumber);
void setEmail(person* book, char* inputEmail);
void setZip(person* book, char* inputZip);
void printInstruction();
void freeContacts(person* book);
int findName(person* book);
int findNumber(person* book);
int findEmail(person* book);
int findZip(person* book);
void showContact(person* book, int i);
void deleteContact(person*, int i);

#endif
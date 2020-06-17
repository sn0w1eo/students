#ifndef FILE_H
#define FILE_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef unsigned char* string;

typedef struct {
	string name;
	int phone;
	int age;
}phoneBook;

// open file
void writeDataInFileTxt(FILE* stream, const phoneBook* contact);



//setters
void setName(phoneBook* phonebook, const string name);
void setPhone(phoneBook* phonebook, int phone);
void setAge(phoneBook* phonebook, int age);

//getters
string getName(phoneBook const phonebook);
int getAge(phoneBook const phonebook);
int getPhone(phoneBook const phonebook);

//hz.... set person
void addPerson(phoneBook* const phonebook, const string name, int const phone, int const age);

//asc
int sortNameAsc(const void* firstValue, const void* secondValue);
int sortAgeAsc(const void* firstValue, const void* secondValue);
int sortPhoneAsc(const void* firstValue, const void* secondValue);

//desc
int sortNameDesc(const void* firstValue, const void* secondValue);
int sortAgeDesc(const void* firstValue, const void* secondValue);
int sortPhoneDesc(const void* firstValue, const void* secondValue);

//print all persons
void PrintPhoneBook(const phoneBook* contact, int const p);


#endif

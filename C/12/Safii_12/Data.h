#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef unsigned char* string;
typedef struct  {
	string name; 
}Name;

typedef struct  {
	int phone;
	int age;
}phoneNum;

typedef struct  {
	Name personName; 
	phoneNum personNum; 
} phoneBook;

void PrintPhoneBooks(const phoneBook* allList, int const p);

void setName(phoneBook* phonebook, const string name);
void setPhone(phoneBook* phonebook, int phone);
void setAge(phoneBook* phonebook, int age);

string getName(phoneBook const phonebook);
int getAge(phoneBook const phonebook);
int getPhone(phoneBook const phonebook);


void SetPhoneBook(phoneBook* const phonebook, const string name, int const phone, int const age);

int sortNameToAsc(const void* a, const void* b);
int sortAgeToAsc(const void* a, const void* b);
int sortPhoneToAsc(const void* a, const void* b);


int sortNameToDesc(const void* a, const void* b);
int sortAgeToDesc(const void* a, const void* b);
int sortPhoneToDesc(const void* a, const void* b);


#endif
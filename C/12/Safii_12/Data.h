#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef unsigned char* string;

typedef struct {
	string name;
	double double_num;
	int phone;
} phoneBook;




void PrintPhoneBooks(const phoneBook* allList, int const p);
void SetPhoneBook(phoneBook* const phonebook, const string name, double const double_num, int const phone);



void setName(phoneBook* phonebook, const string name);
void setDouble(phoneBook* phonebook, const double double_num);
void setPhone(phoneBook* phonebook, int phone);


string getName(phoneBook const phonebook);
double getDouble(phoneBook const phonebook);
int getPhone(phoneBook const phonebook);



int sortNameToAsc(const void* a, const void* b);
int sortDoubleToAsc(const void* a, const void* b);
int sortPhoneToAsc(const void* a, const void* b);


int sortNameToDesc(const void* a, const void* b);
int sortDoubleToDesc(const void* a, const void* b);
int sortPhoneToDesc(const void* a, const void* b);


#endif
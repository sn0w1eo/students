#ifndef FUNC_H
#define FUNC_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef  unsigned char* string;

typedef struct {
	int size;
	string name;
	string email;
	string number;
	string zipCode;
}contact;

typedef struct
{
	unsigned char name[31];
	unsigned char phone[31];
	unsigned char email[31];
	unsigned char zip[10];

}binContact;

enum SaveTo {
	Binary = 0,
	Text
};

enum sortBy {
	asc = 0,
	desc
};

enum boolean
{
	false = 0,
	true
};

contact* initStorage(size_t);
contact* reallocStorage(contact*);
contact* freeMemory(contact* strg);


string getZip(contact strg);
string getName(contact strg);
string getNumber(contact strg);
string getMail(contact strg);



void setUser(contact* strg, const string name, const string number, const string email, const string zip);
void setZip(contact* strg, const string zip);
void setMail(contact* strg, const string email);
void setNumber(contact* strg, const string number);
void setName(contact* strg, const string name);
void setSize(contact* storage, size_t);



contact* addNewContact(contact* strg, const string name, const string number, const string email, const string zip);
contact* update(contact* strg, const string name, const string number, const string email, const string zip, int index);
contact* updateZip(contact* strg, const string zip, int index);
contact* updateMail(contact* strg, const string mail, int index);
contact* updateNumber(contact* strg, const string number, int index);
contact* updateName(contact* strg, const string name, int index);
void srhName(contact* strg, string name);
void srhNumber(contact* strg, string number);
void srhZip(contact* strg, string zip);
void srhMail(contact* strg, string mail);
void show(contact* strg);
contact* getAdress(contact* strg);
contact* delete(contact* strg, int index);

void saveToText(contact* strg);
void saveToBin(contact* strg);
int readTextFile( contact* strg);
void readDAT( binContact* contacts);
void overwriteFromFile(FILE* st, contact* strg);
void save(FILE* stream, contact* strg, int param);
void read(FILE* stream, contact* strg, int param);

int freePlace(contact* phoneBook);
void wait();
void sortShow(contact* strg);


/*sorting*/
int namesrt_a(const void* a, const void* b);	
int namesrt_d(const void* a, const void* b);
void sortByName(contact* strg, int in_order);
	
#endif // !FUNC_H


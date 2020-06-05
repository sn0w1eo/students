#ifndef FUNC_H
#define FUNC_H

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef  unsigned char* str;
typedef const  cstr;
typedef struct {
	int size;
	str name;
	str email;
	str number;
	str zipCode;
}contact;

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


str getZip(contact strg);
str getName(contact strg);
str getNumber(contact strg);
str getMail(contact strg);


void setUser(contact* strg, const str name, const str number, const str email, const str zip);
void setZip(contact* strg, const str zip);
void setMail(contact* strg, const str email);
void setNumber(contact* strg, const str number);
void setName(contact* strg, const str name);
void setSize(contact* storage, size_t);



contact* add(contact* strg, const str name, const str number, const str email, const str zip);
contact* update(contact* strg, const str name, const str number, const str email, const str zip, int index);
contact* updateZip(contact* strg, const str zip, int index);
contact* updateMail(contact* strg, const str mail, int index);
contact* updateNumber(contact* strg, const str number, int index);
contact* updateName(contact* strg, const str name, int index);
void srhName(contact* strg, str name);
void srhNumber(contact* strg, str number);
void srhZip(contact* strg, str zip);
void srhMail(contact* strg, str mail);
void show(contact* strg);
contact* getAdress(contact* strg);
contact* delete(contact* strg, int index);

void saveToText(contact* strg, FILE* stream);
void saveToBin(contact* strg, FILE* stream);
void ReadText(FILE* stream, contact* strg);
void readBinary(contact* stream, FILE* strg);
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


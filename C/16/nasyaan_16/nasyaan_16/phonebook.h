#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"
#include "sqlite3.h"

typedef struct {
	sqlite3* db; // дескриптор соединения к базе данных
	int rc;
	char* err_msg;
} PhoneDB;

int InitDB(const char*, PhoneDB*);
void CloseDB(PhoneDB*);
int callback(void*, int, char**, char**);

//DDL
int DropTable(PhoneDB*);
int CreateTable(PhoneDB*);

//DML
int InsertContact(PhoneDB*, const char*, const char*);
int SelectTable(PhoneDB*);
char* SelectContact(PhoneDB* pdb, int ID, char* criterion);
int DeleteContact(PhoneDB*, const int);
int UpdateContact(PhoneDB*, const int, const char*, const char*);
wchar_t* SelectPhone(PhoneDB* handle, int id);
#endif // !PHONEBOOK_H

#ifndef PHONEBOOKFUNC_H
#define PHONEBOOKFUNC_H
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
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
int DeleteContact(PhoneDB*, const int);
int UpdateContact(PhoneDB*, const char*, const char*, const char*);
#endif // !PHONEBOOKFUNC_H

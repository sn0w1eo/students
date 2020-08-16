#ifndef OPERATIONS_H
#define OPERATIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include "sqlite3.h"

static sqlite3* db;     // handle BD
static char *errMsg;	// variable for error

enum UpdateField {
	NAME = 1,
	PHONE,
	ID
};

void initDB(const char* filename);       // open DB file
int checkDataBaseFunctionResult(int rc); // check DB Function Result if we have problem we will write to txt file 

// DDL(Data Definition Language)
void createTable(char* sql);
void dropTable();

// DML(Data Manipulation Language)
void insertPersonToDB(char* name, char* phone);
void deletePersonFromDB(int mood, char* value);
void updatePersonFromDB(char* name, int mood, char* value);
void selectPersonsFromDB();

#endif // !OPERATIONS_H


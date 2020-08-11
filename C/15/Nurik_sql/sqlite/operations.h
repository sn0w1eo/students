#ifndef OPERATIONS_H
#define OPERATIONS_H

#define _CRT_SECURE_NO_WARNINGS

#include "sqlite3.h"

static sqlite3* db;     // handle BD
static char *errMsg;	// variable for error

void initDB(const char* filename);       // open DB file
int checkDataBaseFunctionResult(int rc); // check DB Function Result if we have problem we will write to txt file 

// DDL(Data Definition Language)
void createTable(char* sql);
void dropTable(char* query);

// DML(Data Manipulation Language)
void insertPersonToDB(char* sql);
void deletePersonFromDB(char* sql);
void updatePersonFromDB(char* sql);
void selectPersonsFromDB(char* sql);

#endif // !OPERATIONS_H


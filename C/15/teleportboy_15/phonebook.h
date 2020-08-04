#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "sqlite3.h"

#define ARRAY_SIZE_150 150

static sqlite3* dataBase = 0;               //Хэндл базы данных.
static sqlite3_stmt* statement;             //Строка запроса к базе данных.

//В случае ошибки:
static char* dataBaseError = 0;
static char errorInfo[ARRAY_SIZE_150];

int InitDataBase();
void CloseDataBase();

//DDL
int CreateTable();
int DropTable();

//DML
void AddRecordToDataBase(int contactCode, char* name, char* phone, char* email);
int LoadRecordsFromDataBaseToArray(char* buffer);
void UpdateRecordInDataBase(int contactCode, char* name, char* phone, char* email);
void DeleteRecordInDataBase(int contactCode);

#endif // !PHONEBOOK_H

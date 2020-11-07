#include "sqlite3.h"
#ifndef FUNCTIONS
#define FUNCTIONS

//ошибки нет
#define OK 0
//ошибка есть
#define ERROR 1


typedef struct {
	sqlite3* db;
	int rc;
	char* sql;
	char* err_msg;
}database;

enum deletOrUpdate {
	ID = 0,
	NAME,
	PHONE
};

int openDatabase(database* phoneDB, char* nameDatabase);
int createTable(database* phoneDB);
int addPerson(database* phoneDB, const char* name, const unsigned int phone);
int printPersons(database* phoneDB);
int dropTable(database* phoneDB);
int deletePerson(database* phoneDB, enum deletOrUpdate column, const char* text);
int updatePerson(database* phoneDB, enum deletOrUpdate column, const char* text, const char* inDB);
int clouseDB(database* phoneDB);

#endif

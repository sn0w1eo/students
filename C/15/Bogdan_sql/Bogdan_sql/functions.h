#include "sqlite3.h"
#ifndef FUNCTIONS
#define FUNCTIONS

typedef struct {
	sqlite3* db;
	int exit;
	char* sql;
	char* err_msg;
}database;

enum delet {
	ID = 0,
	NAME,
	PHONE
};

int openDatabase(database* phoneDB, char* nameDatabase);
int createTable(database* phoneDB);
int addPerson(database* phoneDB, const char* name, const unsigned int phone);
int printPersons(database* phoneDB);
int dropTable(database* phoneDB);
int deletePerson(database* phoneDB, enum delet idOrNameOrPhone, const int id, const char* name, const int phone);
int updatePerson(database* phoneDB, const char* nameInDB, const int phoneInDB, const char* nameUpdate, const int phoneUpdate);

#endif

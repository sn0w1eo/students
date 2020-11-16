#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "sqlite3.h"

struct phoneDB
{
	sqlite3* db;   
	char* errMsg;

};

int initDB(struct phoneDB* ,char* );

// DDL(Data Definition Language)
int createTable(struct phoneDB*, char*);
int dropTable(struct phoneDB* pdb, char* query);

// DML(Data Manipulation Language)
int deletePersonFromDB(struct phoneDB* pdb, char* query);
int insertPersonToDB(struct phoneDB* pdb, char* query);
int selectPersonsFromDB(struct phoneDB* pdb, char* query);
int updatePersonFromDB(struct phoneDB* pdb, char* query);

#endif // !PHONEBOOK_H

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "sqlite3.h"

#define ARRAY_SIZE 150

#define CORRECT_FUNC_EXEC 1
#define INCORRECT_FUNC_EXEC 0

typedef struct {
	sqlite3* dataBase;
	sqlite3_stmt* statement;
	char* dbError;
	char errorInfo;
}DBInfo;

int VacuumDB(DBInfo* db);

int InitDB(DBInfo* db);
void CloseDB(DBInfo* db);

int CreateTable(DBInfo* db);
int DropTable(DBInfo* db);

int AddRecordToDB(DBInfo* db, char* name, char* phone, char* email, char* photoPath);
int UpdateDBRecord(DBInfo* db, int contactCode, char* name, char* phone, char* email);
int UpdatePhotoColumn(DBInfo* db, int contactCode, char* photoPath);
int DeleteDBRecord(DBInfo* db, int contactCode);
char* SelectDBRecord(DBInfo* db, int contactCode, char* criterion);

#endif // !PHONEBOOK_H
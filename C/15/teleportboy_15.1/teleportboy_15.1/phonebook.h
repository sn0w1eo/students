#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "sqlite3.h"

#define ARRAY_SIZE 150

#define CORRECT_FUNC_EXEC 1
#define INCORRECT_FUNC_EXEC -1

typedef struct {
	sqlite3* dataBase;
	sqlite3_stmt* statement;
	char* dbError;
	char errorInfo;
}DBInfo;

int InitDB(DBInfo* db);
void ClodeDB(DBInfo* db);

int CreateTable(DBInfo* db);
int DropTable(DBInfo* db);

int AddRecordToDB(DBInfo* db, int contactCode, char* name, char* phone, char* email);
int UpdateDBRecord(DBInfo* db, int contactCode, char* name, char* phone, char* email);
int DeleteDBRecord(DBInfo* db, int contactCode);

#endif // !PHONEBOOK_H


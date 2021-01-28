#define _CRT_SECURE_NO_WARNINGS
#include "sqlite3.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#define ID_ARRAY_COUNT     128  
#define COLUMN_ARRAY_COUNT 32   
#define SQL_QUERY_COUNT    256  

#define DB_OK	 0

#define DB_OPEN_FAILED   -1  // DB open \ initialization error //
#define DB_CREATE_FAILED  1  // DB create new table error //
#define DB_DROP_FAILED    2  // DB delete table error //
#define DB_UINSERT_FAILED 3  // Error adding record to DB //
#define DB_UDELETE_FAILED 4  // Error deleting record to DB //
#define DB_USELECT_FAILED 5  // Error selecting record from DB //
#define DB_UUPDATE_FAILED 6  // Error updating record to DB //


typedef struct {
	int rc;
	int userID;
	sqlite3* db ;
	char* error;
}DBase;

enum UpdateBy
{
	NAME = 1,
	PHONE,
	AGE
};

//--------------------------------------Functions--------------------------------------//
__declspec(dllexport) int initDB(DBase* handle);
__declspec(dllexport) int createNewTable(DBase* handle);
__declspec(dllexport) int delTable(DBase* handle);
__declspec(dllexport) int addUser(DBase* hande, char* Name, char* Phone, int Age);
__declspec(dllexport) int delUser(DBase* handle, int index);
__declspec(dllexport) int selUsers(DBase* handle);
__declspec(dllexport) int updUser(DBase* handle, enum UpdateBy update, int index, char* value);
__declspec(dllexport) void closeDB(DBase* handle);
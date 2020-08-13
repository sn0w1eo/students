#define _CRT_SECURE_NO_WARNINGS
#include "sqlite3.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct {
	sqlite3* db;
	char* error;
}dataBase;

enum UpdateBy
{
	NAME = 1,
	PHONE,
	AGE
};

int initDataBase(char* filename, dataBase* handle);

int createNewTable(dataBase* handle);
int deleteTable(dataBase* handle);

int addUser(dataBase* hande, char* Name, char* Phone,int Age);
int deleteUser(dataBase* handle, int index);
int selectUsers(dataBase* handle);
int updateUser(dataBase* handle, enum UpdateBy update, int index, char* value);

int main() {
	dataBase phoneBook ;
	initDataBase("phoneDB.db", &phoneBook);
	createNewTable(&phoneBook);
	addUser(&phoneBook, "LOQIE", "123123", 15);
	addUser(&phoneBook, "ATL", "12223333", 32);
	addUser(&phoneBook, "OXXXY", "5523453", 56);
	updateUser(&phoneBook, NAME, 2, "SCRIP");
	updateUser(&phoneBook, AGE, 3, "12");
	selectUsers(&phoneBook);
	deleteUser(&phoneBook, 3);
	deleteTable(&phoneBook);

}

int initDataBase(char* filename, dataBase* handle) {
	if (sqlite3_open(filename, &handle->db) != SQLITE_OK) {
		printf("Open failed!");
		sqlite3_close(handle->db);
		return -1;
	}
	else {
		printf("DB initialized!\n");
		return 0;
	}
}
//---------------------------------------------DDL---------------------------------------------------------------------//

int createNewTable(dataBase* handle) {
	if (sqlite3_exec(handle->db, "CREATE TABLE IF NOT EXISTS phoneBook(ID INTEGER PRIMARY KEY, Name TEXT, Phone TEXT, Age INTEGER);", NULL, NULL, &handle->error) != SQLITE_OK) {
		printf("\nCreation failed!");
		sqlite3_free(handle->error);
		sqlite3_close(handle->db);
		return -1;
	}
	else
	{
		printf("\nTable created!");
		return 0;
	}
}

int deleteTable(dataBase* handle) {
	if (sqlite3_exec(handle->db, "DROP TABLE phoneBook", NULL, NULL, &handle->error) == SQLITE_OK) {
		printf("Table deleted!");
		return 0;
	}
	else {
		printf("Deleted failed!");
		return -1;
	}
}
//---------------------------------------------DML---------------------------------------------------------------------//
int addUser(dataBase* handle, char* Name, char* Phone, int Age) {
	sqlite3_stmt* stmt;
	if (sqlite3_prepare(handle->db, "INSERT INTO phoneBook(Name, Phone, Age) VALUES(?, ?, ?);",-1, &stmt, NULL) == SQLITE_OK) {
		sqlite3_bind_text(stmt, 1, Name, (int)strlen(Name), SQLITE_TRANSIENT);
		sqlite3_bind_text(stmt, 2, Phone, (int)strlen(Phone), SQLITE_TRANSIENT);
		sqlite3_bind_int(stmt, 3, Age);
		sqlite3_step(stmt);
		return sqlite3_finalize(stmt);
	}
	return sqlite3_prepare(handle->db, "INSERT INTO phoneBook(Name, Phone, Age) VALUES(?, ?, ?);", -1, &stmt, NULL);
}

int deleteUser(dataBase* handle, int index) {
	char sql[128];
	sprintf(sql, "DELETE FROM phoneBook WHERE ID = %d", index);
	sqlite3_exec(handle->db, sql, NULL, NULL, &handle->error);
	return 0;
}

int selectUsers(dataBase* handle) {
	sqlite3_stmt* stmt;
	if (sqlite3_prepare(handle->db, "SELECT * FROM phoneBook", -1, &stmt, NULL) != SQLITE_OK) {
		return -1;
	}
	while (1) {
		int rc = sqlite3_step(stmt);
		if ( rc == SQLITE_ROW) {
			printf("\n%2d %24s %12s %3d\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_text(stmt, 2), sqlite3_column_int(stmt, 3));
		}
		else if (rc == SQLITE_DONE) {
			break;
		}
		else{
			printf("Error!\n");
			sqlite3_finalize(stmt);	
			break;
		}
	}
	sqlite3_finalize(stmt);
}

int updateUser(dataBase* handle, enum UpdateBy update, int index, char* value) {
	char column[32];
	char sql[100];
	switch (update)
	{
	case NAME:
		sprintf(column, "Name");
		sprintf(sql, "UPDATE phoneBook SET \"%s\" = \"%s\" WHERE \"ID\" = \"%d\";", column, value, index);
		break;
	case PHONE:
		sprintf(column, "Phone");
		sprintf(sql, "UPDATE phoneBook SET \"%s\" = \"%s\" WHERE \"ID\" = \"%d\";", column, value, index);
		break;
	case AGE:
		sprintf(column, "Age");
		int age;
		age = atoi(value);
		sprintf(sql, "UPDATE phoneBook SET \"%s\" = \"%d\" WHERE \"ID\" = \"%d\";", column, age, index);
		break;
	default:
		return SQLITE_ABORT;
		break;
	}
	sqlite3_exec(handle->db, sql, NULL, NULL, &handle->error);
}
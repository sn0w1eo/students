#define _CRT_SECURE_NO_WARNINGS

#include "stdlib.h"
#include "stdio.h"

#include "sqlite3.h"

#include "phonebook.h"

int InitDB(DBInfo* db)
{
	if (sqlite3_open("phonebook.db", &db->dataBase)) {
		sprintf(db->errorInfo, "error: %s\n", sqlite3_errmsg(db->dataBase));
		return INCORRECT_FUNC_EXEC;
	}
	return CORRECT_FUNC_EXEC;
}

void ClodeDB(DBInfo* db)
{
	sqlite3_close(db->dataBase);
}

int CreateTable(DBInfo* db)
{
	char* query = "CREATE TABLE Phonebook(ContactCode, Name, Phone, Email);";

	if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) { 
		sprintf(db->errorInfo, "error: %s\n", db->dbError);
		sqlite3_free(db->dbError);
		return INCORRECT_FUNC_EXEC;
	}
	return CORRECT_FUNC_EXEC;
}

int DropTable(DBInfo* db)
{
	char* query = "DROP TABLE IF EXISTS Phonebook";

	if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
		sprintf(db->errorInfo, "error: %s\n", &db->dbError);
		sqlite3_free(db->dbError);
		return INCORRECT_FUNC_EXEC;
	}
	return CORRECT_FUNC_EXEC;
}

int AddRecordToDB(DBInfo* db, int contactCode, char* name, char* phone, char* email)
{
	char* query = calloc(ARRAY_SIZE, sizeof(char));

	if (query) {
		sprintf(query, "INSERT INTO Phonebook VALUES(%d, '%s', '%s', '%s')", contactCode, name, phone, email);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sprintf(db->errorInfo, "error: %s\n", db->dbError);
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);

		return CORRECT_FUNC_EXEC;

	} else return INCORRECT_FUNC_EXEC;
}

int UpdateDBRecord(DBInfo* db, int contactCode, char* name, char* phone, char* email)
{
	char* query = calloc(ARRAY_SIZE, sizeof(char));
	if (query) {
		sprintf(query, "UPDATE Phonebook \
		SET Name = '%s', Phone = '%s', Email = '%s' WHERE [ContactCode] = %d",
			name, phone, email, contactCode);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sprintf(db->errorInfo, "error: %s\n", db->dbError);
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);

		return CORRECT_FUNC_EXEC;

	} else return INCORRECT_FUNC_EXEC;
}

int DeleteDBRecord(DBInfo* db, int contactCode)
{
	char* query = calloc(ARRAY_SIZE, sizeof(char));
	if (query) {
		sprintf(query, "DELETE FROM Phonebook WHERE [ContactCode] = %d", contactCode);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sprintf(db->errorInfo, "error: %s\n", db->dbError);
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);

		return CORRECT_FUNC_EXEC;

	} else return INCORRECT_FUNC_EXEC;
}

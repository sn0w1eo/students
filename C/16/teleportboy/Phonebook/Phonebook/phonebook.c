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

void CloseDB(DBInfo* db)
{
	sqlite3_close(db->dataBase);
}

int CreateTable(DBInfo* db)
{
	char* query = "CREATE TABLE Phonebook(Name, Phone, Email, Photo);";

	if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
		sqlite3_free(db->dbError);
		return INCORRECT_FUNC_EXEC;
	}
	return CORRECT_FUNC_EXEC;
}

int DropTable(DBInfo* db)
{
	char* query = "DROP TABLE IF EXISTS Phonebook";

	if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
		sqlite3_free(db->dbError);
		return INCORRECT_FUNC_EXEC;
	}
	return CORRECT_FUNC_EXEC;
}

int VacuumDB(DBInfo* db)
{
	char* query = "VACUUM";

	if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
		sqlite3_free(db->dbError);
		return INCORRECT_FUNC_EXEC;
	}
	else return CORRECT_FUNC_EXEC;
}

int AddRecordToDB(DBInfo* db, char* name, char* phone, char* email, char* photoPath)
{
	char* query = (char*)calloc(ARRAY_SIZE, sizeof(char));

	if (query) {
		sprintf(query, "INSERT INTO Phonebook VALUES('%s', '%s', '%s', '%s')",
			name, phone, email, photoPath);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);
		query = NULL;

		return CORRECT_FUNC_EXEC;

	}
	else return INCORRECT_FUNC_EXEC;
}

int UpdateDBRecord(DBInfo* db, int contactID, char* name, char* phone, char* email)
{
	char* query = (char*)calloc(ARRAY_SIZE, sizeof(char));
	if (query) {
		sprintf(query, "UPDATE Phonebook SET Name = '%s', Phone = '%s', Email = '%s' WHERE [rowid] = %d",
			name, phone, email, contactID);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);
		query = NULL;

		return CORRECT_FUNC_EXEC;

	}
	else return INCORRECT_FUNC_EXEC;
}

int UpdatePhotoColumn(DBInfo* db, int contactID, char* photoPath)
{
	char* query = (char*)calloc(ARRAY_SIZE, sizeof(char));
	if (query) {
		sprintf(query, "UPDATE Phonebook SET Photo = '%s' WHERE [rowid] = %d", photoPath, contactID);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		free(query);
		query = NULL;

		return CORRECT_FUNC_EXEC;

	}
	else return INCORRECT_FUNC_EXEC;
}

int DeleteDBRecord(DBInfo* db, int contactID)
{
	char* query = (char*)calloc(ARRAY_SIZE, sizeof(char));
	if (query) {
		sprintf(query, "DELETE FROM Phonebook WHERE [rowid] = %d", contactID);

		if (sqlite3_exec(db->dataBase, query, 0, 0, &db->dbError)) {
			sqlite3_free(db->dbError);
			return INCORRECT_FUNC_EXEC;
		}

		VacuumDB(db);

		free(query);
		query = NULL;

		return CORRECT_FUNC_EXEC;

	}
	else return INCORRECT_FUNC_EXEC;
}

//Взависимости от имени столбца таблицы БД функция и id переданому ей возращает строку
char* SelectDBRecord(DBInfo* db, int contactID, char* criterion)
{
	char* query = (char*)calloc(ARRAY_SIZE, sizeof(char));
	static char selectResult[ARRAY_SIZE] = { 0 };
	if (query) {
		sprintf(query, "SELECT %s FROM Phonebook WHERE rowid = %d", criterion, contactID);

		int rc = sqlite3_prepare_v2(db->dataBase, query, -1, &db->statement, 0);
		if (rc != SQLITE_OK) return NULL;

		if (sqlite3_step(db->statement) == SQLITE_ROW) {
			sprintf(selectResult, "%s", sqlite3_column_text(db->statement, 0));
		}

		sqlite3_finalize(db->statement);

		free(query);
		query = NULL;

		return selectResult;

	}
	else return NULL;
}
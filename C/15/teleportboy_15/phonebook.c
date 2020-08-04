#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "phonebook.h"

//Инициализация БД.
int InitDataBase()
{
	if (sqlite3_open("phonebook.db", &dataBase)) {
		sprintf(errorInfo, "error: %s\n", sqlite3_errmsg(dataBase));
		return 0;
	}
	return 1;
}

//Закрыть БД.
void CloseDataBase()
{
	sqlite3_close(dataBase);
}

//Создание таблицы.
int CreateTable()
{
	char* query = "CREATE TABLE Phonebook(ContactCode, Name, Phone, Email);";

	//Для сброса данных в таблице при каждом запуске программы.
	DropTable();

	//Выполнить SQL запрос.
	if (sqlite3_exec(dataBase, query, 0, 0, &dataBaseError)) {
		sprintf(errorInfo, "error: %s\n", dataBaseError);
		sqlite3_free(dataBaseError);
		return 0;
	}
	return 1;
}

//Сбросить данные в таблице.
int DropTable()
{
	char* query = "DROP TABLE IF EXISTS Phonebook";

	//Выполнить SQL запрос.
	if (sqlite3_exec(dataBase, query, 0, 0, &dataBaseError)) {
		sprintf(errorInfo, "error: %s\n", dataBaseError);
		sqlite3_free(dataBaseError);
		return 0;
	}
	return 1;
}


void AddRecordToDataBase(int contactCode, char* name, char* phone, char* email)
{
	int stringLength = 0;
	char* queryBuffer = calloc(ARRAY_SIZE_150, sizeof(char));

	//Образовать SQL запрос.
	stringLength += sprintf(queryBuffer, "INSERT INTO Phonebook VALUES(");
	sprintf(queryBuffer + stringLength, "%d, '%s', '%s', '%s');", contactCode, name, phone, email);

	//Выполнить SQL запрос.
	if (sqlite3_exec(dataBase, queryBuffer, 0, 0, &dataBaseError)) {
		sprintf(errorInfo, "error: %s\n", dataBaseError);
		sqlite3_free(dataBaseError);
	}

	free(queryBuffer);
	queryBuffer = NULL;
}

int LoadRecordsFromDataBaseToArray(char* buffer)
{
	int rc = 0, stringLength = 0;
	char* query = "SELECT ContactCode, Name, Phone, Email FROM Phonebook";

	//Подготовить SQL запрос.
	if (sqlite3_prepare_v2(dataBase, query, -1, &statement, NULL) != SQLITE_OK) {
		sprintf(errorInfo, "error: %s\n", sqlite3_errmsg(dataBase));
		sqlite3_finalize(statement);
		sqlite3_close(dataBase);
		return -1;
	}

	//Записать данные таблицы в массив.
	while ((rc = sqlite3_step(statement)) == SQLITE_ROW) {
		stringLength += sprintf(buffer + stringLength, "ContactCode = %d", sqlite3_column_int(statement, 0));
		stringLength += sprintf(buffer + stringLength, " Name = %s,", sqlite3_column_text(statement, 1));
		stringLength += sprintf(buffer + stringLength, " Phone = %s,", sqlite3_column_text(statement, 2));
		stringLength += sprintf(buffer + stringLength, " Email = %s\n", sqlite3_column_text(statement, 3));
	} if (rc != SQLITE_DONE) {
		sprintf(errorInfo, "error: %s\n", sqlite3_errmsg(dataBase));
		sqlite3_finalize(statement);
		sqlite3_close(dataBase);
		return -2;
	}

	sqlite3_finalize(statement);

	sqlite3_close(dataBase);
	
	return 1;
}

void UpdateRecordInDataBase(int contactCode, char* name, char* phone, char* email)
{
	int stringLength = 0;
	char* queryBuffer = calloc(ARRAY_SIZE_150, sizeof(char));

	//Образовать SQL запрос.
	stringLength += sprintf(queryBuffer, "UPDATE Phonebook SET Name = ");
	sprintf(queryBuffer + stringLength, "'%s', Phone = '%s', Email = '%s' WHERE [ContactCode] = %d;", name, phone, email, contactCode);

	//Выполнить SQL запрос.
	if (sqlite3_exec(dataBase, queryBuffer, 0, 0, &dataBaseError)) {
		sprintf(errorInfo, "error: %s\n", dataBaseError);
		sqlite3_free(dataBaseError);
	}

	free(queryBuffer);
	queryBuffer = NULL;
}

void DeleteRecordInDataBase(int contactCode)
{
	char* queryBuffer = calloc(ARRAY_SIZE_150, sizeof(char));

	//Образовать SQL запрос.
	sprintf(queryBuffer, "DELETE FROM Phonebook WHERE [ContactCode] = %d;", contactCode);

	//Выполнить SQL запрос.
	if (sqlite3_exec(dataBase, queryBuffer, 0, 0, &dataBaseError)) {
		sprintf(errorInfo, "error: %s\n", dataBaseError);
		sqlite3_free(dataBaseError);
	}

	free(queryBuffer);
	queryBuffer = NULL;
}
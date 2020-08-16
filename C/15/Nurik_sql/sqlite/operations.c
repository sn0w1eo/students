#include "operations.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//-------------------------------- open DB file -------------------

void initDB(const char* filename){
	int rc = sqlite3_open(filename, &db); 
	checkDataBaseFunctionResult(rc);
}

//-------------------------------- DDL ------------------------------

void createTable(char* temp){
	errMsg = NULL;
	char sql[100];
	sprintf(sql, "CREATE TABLE IF NOT EXISTS %s(ID INTEGER PRIMARY KEY, Name TEXT, Phone TEXT);", temp);
	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void dropTable(){
	errMsg = NULL;
	int rc = sqlite3_exec(db, "DROP TABLE IF EXISTS PhoneBook;", NULL, NULL, &errMsg);
	checkDataBaseFunctionResult(rc);
}

//-------------------------------- DML ------------------------------

void insertPersonToDB(char* name, char* phone) {
	errMsg = NULL;
	sqlite3_stmt* st;
	char sql[100];
	sprintf(sql, "INSERT INTO PhoneBook(name, phone) VALUES(?, ?);");
	int rc = sqlite3_prepare(db, sql, -1, &st, NULL);
	if (rc == SQLITE_OK)
	{
		sqlite3_bind_text(st, 1, name, (int)strlen(name), SQLITE_TRANSIENT);
		sqlite3_bind_text(st, 2, phone, (int)strlen(phone), SQLITE_TRANSIENT);
		sqlite3_step(st);
	}
	else if(rc != SQLITE_OK){
		printf("Insert not working");
	}
}

void deletePersonFromDB(int mood, char* value) {
	errMsg = NULL;
	char sql[100];
	switch (mood)
	{
	case NAME: sprintf(sql, "DELETE FROM PhoneBook WHERE \"Name\" = \"%s\";", value);
		break;
	case PHONE: sprintf(sql, "DELETE FROM PhoneBook WHERE \"Phone\" = \"%s\";", value);
		break;
	case ID: sprintf(sql, "DELETE FROM PhoneBook WHERE Id = %d;", atoi(value));
		break;
	default:
		SQLITE_ABORT;
		printf("DELETE not working");
		break;
	}

	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void updatePersonFromDB(char* name , int mood, char* value){
	char columnName[20];
	char sql[200];
	switch (mood)
	{
	case NAME:
		sprintf(columnName, "Name");
		break;
	case PHONE:
		sprintf(columnName, "Phone");
		break;
	default:
		SQLITE_ABORT;
		printf("UPDATE not working");
		break;
	}
	sprintf(sql, "UPDATE PhoneBook SET \"%s\" = \"%s\" WHERE \"Name\" = \"%s\";", columnName, value, name);
	int rc = sqlite3_exec(db, sql, NULL, NULL, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void selectPersonsFromDB() {
	sqlite3_stmt* st;
	char sql[100] = "SELECT * FROM PhoneBook;";
	int rc = sqlite3_prepare(db, sql, -1, &st, NULL);
	checkDataBaseFunctionResult(rc);
	printf(" ID| Name                | Age\n");
	while (1) {
		rc = sqlite3_step(st);
		if (rc == SQLITE_ROW) {
			printf("%3d| %-20s| %-10s\n", sqlite3_column_int(st, 0), sqlite3_column_text(st, 1), sqlite3_column_text(st, 2));
		}
		else if (rc == SQLITE_DONE) {
			break;
		}
		else {
			sqlite3_finalize(st);
			printf("Error occured\n");
			break;
		}
	}
	sqlite3_finalize(st);
}

//----- check DB Function Result if we have problem we will write to txt File -----

int checkDataBaseFunctionResult(int rc){
	if (rc != SQLITE_OK) {
		FILE* streamText = fopen("errorMsg.txt", "a");
		if (streamText == NULL) {
			printf("Open file failed\n");
		}
		fprintf(streamText, "Cannot open database: %s\n", sqlite3_errmsg(db));

		fclose(streamText);
		streamText = NULL;

		return 1;
	}
	return 0;
}
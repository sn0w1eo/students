#include "operations.h"
#include "stdio.h"

//-------------------------------- open DB file -------------------

void initDB(const char* filename){
	int rc = sqlite3_open(filename, &db);
	checkDataBaseFunctionResult(rc);
}

//-------------------------------- DDL ------------------------------

void createTable(char* sql){
	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void dropTable(char* query){
	int rc = sqlite3_exec(db, query, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

//-------------------------------- DML ------------------------------

void insertPersonToDB(char* sql){
	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void deletePersonFromDB(char* sql) {
	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void updatePersonFromDB(char* sql) {
	int rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
	checkDataBaseFunctionResult(rc);
}

void selectPersonsFromDB(char* sql) {
	sqlite3_stmt* st;
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
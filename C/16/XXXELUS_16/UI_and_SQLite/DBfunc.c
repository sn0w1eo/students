#include "DBfunc.h"

void closeDB(DBase* handle) {
	sqlite3_close(handle->db);
}

int initDB( DBase* handle) {
	handle->rc = sqlite3_open("Dbase.db", &handle->db);
	if (handle->rc != SQLITE_OK) {
		sprintf(handle->error, "Can not open DB: %s\n",sqlite3_errmsg(handle->error));
		return DB_OPEN_FAILED;
	}
	else {
		return DB_OK;
	}
}
//---------------------------------------------DDL---------------------------------------------------------------------//

int createNewTable(DBase* handle) {
	char* sql_query = "CREATE TABLE IF NOT EXISTS phnBook(ID INT PRIMARY KEY, Name TEXT, Age INT , Phone_Number TEXT)";
	handle->rc = sqlite3_exec(handle->db, sql_query, 0, 0, &handle->error);
	if (handle->rc != SQLITE_OK) {
		sprintf(handle->error, "Error DB: %s\n", handle->error);
		return DB_CREATE_FAILED;
	}
	else
	{
		handle->userID = 1;
		return DB_OK;
	}
}

int delTable(DBase* handle) {
	char* sql_query = "DROP TABLE IF EXISTS phnBook";
	handle->rc = sqlite3_exec(handle->db, sql_query, 0, 0, handle->error);
	if (handle->rc != SQLITE_OK) {
		sprintf(handle->error, "Error DB: %s\n", handle->error);
		return DB_DROP_FAILED;
	}
	else
	{
		return DB_OK;
	}

}
//---------------------------------------------DML---------------------------------------------------------------------//
int addUser(DBase* handle, char* Name, char* Phone, int Age) {

	
	sqlite3_stmt* stmt;

	handle->rc = sqlite3_prepare(handle->db, "INSERT INTO phnBook(ID, Name, Age, Phone_Number) VALUES(?,?,?,?);", -1, &stmt, NULL);
	if(handle->rc != SQLITE_OK){
		sprintf(handle->error, "Error insert: %s\n", handle->error);
		return DB_UINSERT_FAILED;
	}
	else
	{
		sqlite3_bind_int(stmt, 1,handle->userID);
		handle->userID = handle->userID++;
		sqlite3_bind_text(stmt, 2, Name, (int)strlen(Name), SQLITE_TRANSIENT);
		sqlite3_bind_int(stmt, 3, Age);
		sqlite3_bind_text(stmt, 4, Phone, (int)strlen(Phone), SQLITE_TRANSIENT);
		sqlite3_step(stmt);
	
		return DB_OK;
	}
}

int delUser(DBase* handle, int index) {
	char* sql_query = (char*)calloc(ID_ARRAY_COUNT,sizeof(char));
	sprintf(sql_query, "DELETE FROM phnBook WHERE ID = %d", index);

	handle->rc = sqlite3_exec(handle->db, sql_query, NULL, NULL, &handle->error);
	if (handle->rc != SQLITE_OK) {
		sprintf(handle->error, "Delete User Error : %s\n", handle->error);
		return DB_UDELETE_FAILED;
	}
	else
	{
		handle->userID = handle->userID--;
		free(sql_query);
		return DB_OK;
	}
}

int selUsers(DBase* handle) {
	FILE* fstream;
	sqlite3_stmt* stmt;
	fstream = fopen("DBase.txt", "w");
	fprintf(fstream, "%2s|%-17s|%-4s|%-17s|\n", "ID", "Name", "Age", "Phone number");
	handle->rc = sqlite3_prepare(handle->db, "SELECT * FROM phnBook", -1, &stmt, NULL);
	if (handle->rc != SQLITE_OK)
	{
		return DB_USELECT_FAILED;
	}
	while (1) {
		handle->rc = sqlite3_step(stmt);
		if (handle->rc == SQLITE_ROW) {
			fprintf(fstream,"\n%-2d|%-17s|%-4d|%-17s|\n", sqlite3_column_int(stmt, 0), sqlite3_column_text(stmt, 1), sqlite3_column_int(stmt, 2), sqlite3_column_text(stmt, 3));
		}
		else if (handle->rc == SQLITE_DONE) {
			fclose(fstream);
			sqlite3_finalize(stmt);
			return DB_OK;
			break;
		}
		else {
			sprintf(handle->error, "Error!: %s\n", handle->error);
			fclose(fstream);
			sqlite3_finalize(stmt);
			return DB_USELECT_FAILED;
			break;
		}
	}
}

int updUser(DBase* handle, enum UpdateBy update, int index, char* value) {
	char* column = calloc(COLUMN_ARRAY_COUNT, sizeof(char));
	char* sql_query = calloc(SQL_QUERY_COUNT, sizeof(char));
	switch (update)
	{
	case NAME:
		sprintf(column, "Name");
		sprintf(sql_query, "UPDATE phnBook SET \"%s\" = \"%s\" WHERE \"ID\" = \"%d\";", column, value, index);
		break;
	case PHONE:
		sprintf(column, "Phone_Number");
		sprintf(sql_query, "UPDATE phnBook SET \"%s\" = \"%s\" WHERE \"ID\" = \"%d\";", column, value, index);
		break;
	case AGE:
		sprintf(column, "Age");
		int age;
		age = atoi(value);
		sprintf(sql_query, "UPDATE phnBook SET \"%s\" = \"%d\" WHERE \"ID\" = \"%d\";", column, age, index);
		break;
	default:
		return SQLITE_ABORT;
		break;
	}
	handle->rc = sqlite3_exec(handle->db, sql_query, NULL, NULL, &handle->error);
	if (handle->rc != SQLITE_OK) {
		sprintf(handle->error, "Error: %s", handle->error);
		free(column);
		free(sql_query);
		return DB_UUPDATE_FAILED;
	}
	else
	{
		free(column);
		free(sql_query);
		return DB_OK;
	}
}

wchar_t* selRecord(DBase* handle, int id)
{
	sqlite3_stmt* stmt;
	
	

	char* query = (char*)calloc(SQL_QUERY_COUNT, sizeof(char));
	wchar_t* selectResult = (wchar_t*)calloc(RECORD_SIZE, sizeof(wchar_t));
	
	sprintf(query, "SELECT Name, Age, Phone_Number FROM phnBook WHERE ID = %d",  id);

	int rc = sqlite3_prepare_v2(handle->db, query, -1, &stmt, 0);
	if (rc != SQLITE_OK) return NULL;


	if (sqlite3_step(stmt) == SQLITE_ROW) {
		
		swprintf(selectResult,RECORD_SIZE,L"%-17s  %-4d  %-17s", (wchar_t*)sqlite3_column_text16(stmt, 0), sqlite3_column_int(stmt, 1), (wchar_t*)sqlite3_column_text16(stmt, 2));
	}
	
	sqlite3_finalize(stmt);

	free(query);
	query = NULL;

	return selectResult;
}
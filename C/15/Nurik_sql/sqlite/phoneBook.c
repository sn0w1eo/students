#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "phoneBook.h"
#include "windows.h"

// open DB
int initDB(struct phoneDB* pdb, char* sql) {
	int rc = sqlite3_open(sql, &pdb->db);
	return rc;
}

// create table named "PhoneBook" if not exists
int createTable(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	return rc;	
}

// add contact to.db
int insertPersonToDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	return rc;
}

// delete contact where id = 2
int deletePersonFromDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	return rc;
}

// update first value
int updatePersonFromDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	return rc;
}

// read from BD
int selectPersonsFromDB(struct phoneDB* pdb, char* query) {
	sqlite3_stmt* st;
	int rc = sqlite3_prepare(pdb->db, query, -1, &st, NULL);
	if (rc != SQLITE_OK) {
		return rc;
	}
	printf(" ID| Name                | Age\n");
	while (1) {
		rc = sqlite3_step(st);
		if (rc == SQLITE_ROW) {
			printf("%3d| %-20s| %-10s \n", sqlite3_column_int(st, 0), sqlite3_column_text(st, 1), sqlite3_column_text(st, 2));
		}
		else if (rc == SQLITE_DONE) {
			break;
		}
	}
	return 0;
}

// delete if we have a table named "PhoneBook"
int dropTable(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	return rc;
}
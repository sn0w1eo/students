#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "windows.h"
#include "phoneBook.h"

// open DB
int initDB(struct phoneDB* pdb, char* sql) {
	int rc = sqlite3_open(sql, &pdb->db);
	return rc;
}

// create table named "PhoneBook" if not exists
int createTable(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	pdb->errMsg = NULL;
	return rc;	
}

// add contact to.db
int insertPersonToDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	pdb->errMsg = NULL;
	return rc;
}

// delete contact where id = 2
int deletePersonFromDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	pdb->errMsg = NULL;
	return rc;
}

// update first value
int updatePersonFromDB(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	pdb->errMsg = NULL;
	return rc;
}

// delete if we have a table named "PhoneBook"
int dropTable(struct phoneDB* pdb, char* query) {
	int rc = sqlite3_exec(pdb->db, query, 0, 0, &pdb->errMsg);
	pdb->errMsg = NULL;
	return rc;
}
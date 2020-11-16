#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "phoneBook.h"

#define DB_OK 0
#define DB_ERR -1

int main() {
	struct phoneDB pdb;
	int rc = 0;

	// open DB
	rc = initDB(&pdb, "MyPhoneBook.db");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "DB not opened: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// create table named "PhoneBook" if not exists
	rc = createTable(&pdb, "CREATE TABLE IF NOT EXISTS PhoneBook(Id INT, Name TEXT, Phone TEXT);");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Table can not created: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// add contact to .db
	rc = insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(1, 'David', '0709565645');");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Person isn't added to table: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// add contact to .db
	rc = insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(2, 'Thomas', '0555555555');");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Person isn't added to table: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// add contact to .db
	rc = insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(3, 'Daniel', '0789456123');");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Person isn't added to table: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// delete contact where id = 2
	rc = deletePersonFromDB(&pdb, "DELETE FROM PhoneBook WHERE Id = 2;");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Can not delete from DB: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}
	
	// update first value
	rc = updatePersonFromDB(&pdb, "UPDATE PhoneBook SET Name = 'Raman', Phone = '0999999999' WHERE id = 1;");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Can not update data: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// read from BD
	rc = selectPersonsFromDB(&pdb, "SELECT * FROM PhoneBook;");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Can not select data: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	// delete if we have a table named "PhoneBook"
	rc = dropTable(&pdb, "DROP TABLE IF EXISTS PhoneBook;");
	if (rc != DB_OK) {
		sprintf(pdb.errMsg, "Drop is not wrking: %s", sqlite3_errmsg(pdb.db));
		sqlite3_close(pdb.db);
		return DB_ERR;
	}

	sqlite3_close(pdb.db);                                                             
	return 0;
}
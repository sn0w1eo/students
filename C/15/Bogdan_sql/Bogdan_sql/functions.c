#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//�������� �� ������
int errorCheck(database* phoneDB) {
	//���� ������ �� ������� ���������, ������� ������
	if (phoneDB->exit != SQLITE_OK) {	
		printf("ERROR: %d %s\n", phoneDB->exit, sqlite3_errmsg(phoneDB->db));
		sqlite3_close(phoneDB->db);	//��������� ���������� 
		sqlite3_free(phoneDB->err_msg);	//������� ��������� �� ������
		if (phoneDB->sql != NULL) {
			free(phoneDB->sql);
		}
		return -1;
	}
	return 0;
}


int openDatabase(database* phoneDB, char* nameDatabase) {

	phoneDB->exit = sqlite3_open(nameDatabase, phoneDB);	//��������� ��� ������� ���� 
	//�������� �� ���������� SQL �������
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	printf("database created\n\n");
	return 0;
}

int createTable(database* phoneDB) {
	//� ����� ��������� SQL �������
	phoneDB->sql = "CREATE TABLE IF NOT EXISTS phoneBook(Id INTEGER PRIMARY KEY, Name TEXT NOT NULL UNIQUE, Phone INT);";	//������� ������� � ������(��� ����������)
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);			//����������� SQL �������
	// �������� �� ���������� � �������
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	return 0;
}

//�������� ������� � �������
int addPerson(database* phoneDB, const char* name, const unsigned int phone) {

	//������� �����
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	//������� � ����� ������� SQL
	sprintf(phoneDB->sql, "INSERT OR IGNORE INTO phoneBook (Name, Phone) VALUES('%s', %d);", name,phone);  //���� ��� ����������� �� �� ������� � ��

	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);	//����������� 
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);			//������� �����
	return 0;
}

//������� ��������� ������ ������������ � ������� sqlite3_exec()
//������� ������� � ������� ���� ��
int callback(void* NotUsed,		//������ �� ������������ (���������� 4� �������� ������� sqlite3_exec)
	int numberOfElements,		//���������� ��������� � ������
	char** arrayOfText,			//������ � ������� ������������ ������ ������
	char** azColName)			//������ � ������� ������������ ����� �����
{
	NotUsed = 0;
	for (int i = 0; i < numberOfElements; i++) {
		printf("%-10s   ", arrayOfText[i]);
	}
	printf("\n");
	return 0;
}

//������� � ������� ���� ��
int printPersons(database* phoneDB) {

	phoneDB->sql = "SELECT * FROM phoneBook";
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, callback, 0, phoneDB->err_msg);
	
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	return 0;
}

int dropTable(database* phoneDB) {
	 phoneDB->exit = sqlite3_exec(phoneDB->db, "DROP TABLE IF EXISTS phoneBook;", NULL, NULL, phoneDB->err_msg);
	 if (errorCheck(phoneDB) != 0) {
		 return -1;
	 }
	 sqlite3_close(phoneDB->db);	//��������� ���������� 
	 sqlite3_free(phoneDB->err_msg);	//������� ��������� �� ������
	 return 0;
}

int deletePerson(database* phoneDB, enum delet idOrNameOrPhone, const int id, const char* name, const int phone) {
	//������� �����
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(100, sizeof(char));
	//������� � ����� ��� 
	switch (idOrNameOrPhone)
	{
	case ID:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Id = %d;", id);
		break;

	case NAME:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Name = '%s';\n", name);
		break;

	case PHONE:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Phone = %d;\n", phone);
		break;
	}
	//����������� ���
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);//������� �����
	return 0;
}

int updatePerson(database* phoneDB, const char* nameInDB, const int phoneInDB,
	 const char* nameUpdate, const int phoneUpdate) {

	int stringLength = 0;
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	if (nameInDB != NULL) {
		stringLength += sprintf(phoneDB->sql, "UPDATE phoneBook SET Name = '%s' WHERE Name = '%s';\n", nameUpdate, nameInDB);
	}
	
	if (phoneInDB != NULL) {
		stringLength += sprintf(phoneDB->sql + stringLength, "UPDATE phoneBook SET Phone = %d WHERE Phone = %d;", phoneUpdate, phoneInDB);
	}

	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);
	return 0;
}
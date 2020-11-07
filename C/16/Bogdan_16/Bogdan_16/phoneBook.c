#define _CRT_SECURE_NO_WARNINGS
#include "phoneBook.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"


int openDatabase(database* phoneDB, char* nameDatabase) {

	phoneDB->rc = sqlite3_open(nameDatabase, phoneDB);	//��������� ��� ������� ���� 
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}

int createTable(database* phoneDB) {
	//� ����� ��������� SQL �������
	phoneDB->sql = "CREATE TABLE IF NOT EXISTS phoneBook(Id INTEGER PRIMARY KEY, Name TEXT NOT NULL UNIQUE, Phone INT);";	//������� ������� � ������(��� ����������)
	phoneDB->rc = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);			//����������� SQL �������
	
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}

//�������� ������� � �������
int addPerson(database* phoneDB, const char* name, const unsigned int phone) {

	//������� �����
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	//������� � ����� ������� SQL
	sprintf(phoneDB->sql, "INSERT OR IGNORE INTO phoneBook (Name, Phone) VALUES('%s', %d);", name, phone);  //���� ��� ����������� �� �� ������� � ��

	phoneDB->rc = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);	//����������� 
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	free(phoneDB->sql);			//������� �����
	return OK;
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
	phoneDB->rc = sqlite3_exec(phoneDB->db, phoneDB->sql, callback, 0, phoneDB->err_msg);
	
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}

int dropTable(database* phoneDB) {
	 phoneDB->rc = sqlite3_exec(phoneDB->db, "DROP TABLE IF EXISTS phoneBook;", NULL, NULL, phoneDB->err_msg);
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}

int clouseDB(database* phoneDB) {
	sqlite3_close(phoneDB->db);	//��������� ���������� 
	sqlite3_free(phoneDB->err_msg);	//������� ��������� �� ������
	
	return 0;
}

int deletePerson(database* phoneDB, enum deletOrUpdate column, const char* text) {
	//������� �����
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(100, sizeof(char));
	
	//������� � ����� ��� 
	switch (column)
	{
	case ID:
		
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Id = %s;", text);
		break;

	case NAME:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Name = '%s';", text);
		break;

	case PHONE:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Phone = %s;", text);
		break;
	}
	//����������� ���
	phoneDB->rc = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	free(phoneDB->sql);//������� �����
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}

int updatePerson(database* phoneDB, enum deletOrUpdate column, const char* inDB, const char* text) {

	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	switch (column)
	{
	case NAME:
		sprintf(phoneDB->sql, "UPDATE phoneBook SET Name = '%s' WHERE Name = '%s';\n", inDB, text);
		break;

	case PHONE:
		sprintf(phoneDB->sql, "UPDATE phoneBook SET Phone = %s WHERE Phone = %s;", inDB, text);
	}

	phoneDB->rc = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	free(phoneDB->sql);//������� �����
	if (phoneDB->rc != SQLITE_OK) {
		return ERROR;
	}
	return OK;
}
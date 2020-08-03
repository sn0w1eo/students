#include "sqlite3.h"
#include "stdio.h"
//http://zetcode.com/db/sqlitec/ ���� ���� �����
//������� ��������� ������ ������������ � ������� sqlite3_exec()
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

int main() {
	sqlite3* db;			//���������� �� ���� ������
	char* err_msg = NULL;	//��������� �� ������

	int exit = sqlite3_open("database.db", &db);	//��������� ��� ������� ���� 
	
	if (exit != SQLITE_OK) {	//�������� �� �������� �����
		printf("Error, can't open: %d %s\n", exit, sqlite3_errmsg(db));
		sqlite3_close(db);	//��������� ���������� 
		return -1;
	}
	else {
		printf("database created\n\n");
	}

	//��� SQL ������� ����� �������� � ��������
	char* sql = "CREATE TABLE IF NOT EXISTS phoneBook(Id INTEGER PRIMARY KEY, Name TEXT, Phone INT);"	//������� ������� � ������
		"INSERT INTO phoneBook VALUES(1, 'Dima', 123);"					//��������� ���������� � �������
		"INSERT INTO phoneBook (Name, Phone) VALUES('Kirill', 3456);"	//PRIMARY KEY ����������� �������������
		"INSERT INTO phoneBook VALUES(3, 'Bogdan', 4423);"
		"INSERT INTO phoneBook VALUES(4, 'Nastya', 6223);"
		"INSERT INTO phoneBook VALUES(5, 'Lera', 2334);"
		"INSERT INTO phoneBook VALUES(6, 'Bob', 357);"
		"INSERT INTO phoneBook VALUES(7, 'Boris', 3736);"
		"INSERT INTO phoneBook VALUES(8, 'Lola', 2562);";
	//��������� ��� SQL
	exit = sqlite3_exec(db, sql, 0, 0, &err_msg);
	// �������� �� ���������� � �������
	if (exit != SQLITE_OK) {
		printf("table not created: %d %s\n", exit, sqlite3_errmsg(db));
		sqlite3_free(err_msg);	//������� ��������� �� ������
		sqlite3_close(db);	//��������� ���������� 
		return -1;
	}
	sql = "SELECT * FROM phoneBook";
	//��������� ��� SQL
	exit = sqlite3_exec(db, sql, callback, 0, &err_msg);
	// �������� 
	if (exit != SQLITE_OK) {
		printf("failed to withdraw: %d %s\n", exit, sqlite3_errmsg(db));
		sqlite3_free(err_msg);	//������� ��������� �� ������
		sqlite3_close(db);	//��������� ���������� 
		return -1;
	}
	exit = sqlite3_exec(db, "DROP TABLE IF EXISTS phoneBook;", NULL, NULL, err_msg);
	if (exit != SQLITE_OK) {
		printf("failed to DROP DB: %d %s\n", exit, sqlite3_errmsg(db));
		sqlite3_free(err_msg);	//������� ��������� �� ������
		sqlite3_close(db);	//��������� ���������� 
		return -1;
	}
	sqlite3_free(err_msg);
	sqlite3_close(db);
	return 0;
}
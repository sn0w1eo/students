#include "functions.h"
//http://zetcode.com/db/sqlitec/ ���� ���� �����


int main() {

	database phoneDB;		//������� ��������� � ������� �� ��� SQL ����
	phoneDB.err_msg = NULL;
	phoneDB.sql = NULL;

	
	//������ ��������� �������� �� ������������ ���������� ���������
	if (openDatabase(&phoneDB, "database.db") != 0) {//��������� (������) ���� ��� ����� ���� ��
		return -1;
	}
	if (createTable(&phoneDB) != 0){			//������� �������
		return -1;
	}

	//� ������� ������ ������(��� � �������)
	if (addPerson(&phoneDB, "Dima", 123) != 0) return -1;
	if (addPerson(&phoneDB, "Kril", 156) != 0) return -1;
	if (addPerson(&phoneDB, "Nastya", 8674) != 0) return -1;
	if (addPerson(&phoneDB, "Konstantin", 58557) != 0) return -1;
	if (addPerson(&phoneDB, "Bogdan", 165848) != 0) return -1;
	if (addPerson(&phoneDB, "Nurdoolot", 44574) != 0) return -1;
	if (addPerson(&phoneDB, "Safi", 598) != 0) return -1;

	//������� ����� �� ��
	//����� ������� �� (Id, Name, Phone)
	if (deletePerson(&phoneDB, ID, 5, NULL, NULL) !=0) return -1;		
	if (deletePerson(&phoneDB, NAME, NULL, "Bogdan", NULL) != 0) return -1;
	if (deletePerson(&phoneDB, PHONE, NULL, NULL, 123) != 0) return -1;

	//��������� ���� � ��
	//updatePerson(1. ��������� �� ���������, 2. ��� ������� ����� ��������. 3. ����� ������� ����� ��������. 4 � 5 �� ��� ����� ��������)
	if (updatePerson(&phoneDB, "Nastya", 8674, "Anastasiya", 123) != 0) return -1;
	if (updatePerson(&phoneDB, "Kril", 156, "Kirill", NULL) != 0) return -1;

	//������� �� ������� ��
	if (printPersons(&phoneDB) != 0) return -1;
	
	//������� ������� � �� � ������� ������
	if (dropTable(&phoneDB) != 0) return -1;
	return 0;
}
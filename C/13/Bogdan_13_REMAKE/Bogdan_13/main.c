
#include "stdio.h"
#include "algorithm.h"




int main() {
	

	data db = initStorage(10);			//�������� ������

	//��������� ����������
	addPerson(&db, "Bogdan", 29, 1123);	
	addPerson(&db, "Dima", 13, 13123);
	addPerson(&db, "Artur", 234, 5123);
	addPerson(&db, "Ira", 45, 1233);
	addPerson(&db, "Kirill", 5, 14123);

	//���������
	//sortStorage(&db, byName, descending);         // byName, byAge, byEarnings //ascending ,descending 

	//���� ���� ��� ������ Txt
	//{
	//	writeToFileTxt(&db);								//������� � ���������� � ����
	//	freeStorage(&db);									//�������� ������
	//	size_t numberOfPerson = readNumberFromFileTxt();	//�������� ���������� ���������� � �����
	//	data database = initStorage(numberOfPerson);		//�������� ������ 
	//	readPersonsFromFileTxt(&database);					//������ � ������� � ������ ���������� � �����
	//	printStorage(&database);							//������� �� ��� ����� � ������
	//	freeStorage(&database);								//�������� ������
	//}
	//����� �����
	

	//���� ���� ��� ������ bin
	{
		writeToFileBin(&db);				// ������� ���� � ���������� ���� ������ � ������������ ������ 
		freeStorage(&db);					// ������� ������������ ������ 
		data database = initStorage(10);	// �������� ������������ ������ 
		readPersonFromFileBin(&database);	// ������ ������� � ����� � ���������� � ������������ ������
		printStorage(&database);			//������� � ������� ��� ����� � ������������ ������
		freeStorage(&database);				// ������� ������
	}
	getch();
	return 0;
}
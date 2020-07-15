#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "algorithm.h"

int count = 0;


//�������������� ������ 
data initStorage(size_t size) {
	data db;
	db.size = size;
	db.persons = calloc(size, sizeof(person));
	if (db.persons == NULL) {
		printf("fucked up");
		return db;
	}
	return db;
}

//�������� ���������
void addPerson(data* db, char* name, int age, int earnings) {
	for (size_t i = 0; i < db->size - 1; i++) {
		if (db->persons[i].name[0] != '\0') continue;
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		count++;
		break;
	}
}

//�������� � ������ (��������)
void setEarnings(person* per, int earnings) {
	per->earnings = earnings;
}

//�������� � ������ (�������)
void setAge(person* per, int age) {
	per->age = age;
}

//�������� � ������ (���)
void setName(person* per, char* name) {
	memcpy(per->name, name, 50);
}

//��������  (���)
int getName(person* per) {
	return per->name;
}

//�������� (�������)
int getAge(person* per) {
	return per->age;
}

//�������� (��������)
int getEarnings(person* per) {
	return per->earnings;
}

//����� �� ������� ����� ������
void printStorage(data* db) {
	for (size_t i = 0; i < db->size; i++) {
		if (db->persons[i].name[0] != NULL) {
			printf("name: %s\n", getName(&db->persons[i]));
			printf("age: %d\n", getAge(&db->persons[i]));
			printf("earnings: %d\n\n", getEarnings(&db->persons[i]));
		}
	}
}

//������������ ������
void freeStorage(data* db) {
	for (size_t i = 0; i < db->size - 1; i++) {
		db->persons[i].age = 0;
		db->persons[i].earnings = 0;
	}
	free(db->persons);
	db->persons = NULL;
	db->size = 0;
}

//���������� �� ����������� ��� ��������
int compByNameDescending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return -strcmp(per->name, vtor->name);
}


int compByNameAscending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return strcmp(per->name, vtor->name);
}

int compByAgeDescending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return -((per->age) - (vtor->age));
}

int compByAgeAscending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return (per->age) - (vtor->age);
}

int compByEarningsDescending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return -((per->earnings) - (vtor->earnings));
}

int compByEarningsAscending(const void* a, const void* b) {
	const person* per = a;
	const person* vtor = b;
	return (per->earnings) - (vtor->earnings);
}


void sortStorage(data* db, int parametr, int sequence) {
	switch (parametr)
	{
	case byName:
		if (sequence == descending) {
			qsort(db->persons, count, sizeof(person), compByNameDescending);
		}
		else {
			qsort(db->persons, count, sizeof(person), compByNameAscending);
		}
		break;
	case byAge:
		if (sequence == descending) {
			qsort(db->persons, count, sizeof(person), compByAgeDescending);
		}
		else {
			qsort(db->persons, count, sizeof(person), compByAgeAscending);
		}
		break;
	case byEarnings:
		if (sequence == descending) {
			qsort(db->persons, count, sizeof(person), compByEarningsDescending);
		}
		else {
			qsort(db->persons, count, sizeof(person), compByEarningsAscending);
		}
		break;
	}
}


//�������� � �������� ����
int writeToFileBin(data* db){

	//��������� ��� ������� ����
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "wb");

	//�������� ������ �� ����
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	//���������� ������ � ����
	for (int i = 0; i < db->size; i++)
	{		
		fprintf(stream, "%-49s %-d  %-d  ", db->persons[i].name, db->persons[i].age, db->persons[i].earnings);
	}
	fclose(stream);
	return 0;
}

// ���������� ������ � ����� � ������������ ������
int readPersonFromFileBin(data* db) {
	
	// ������� ������
	int age = 0;
	int earnings = 0;
	char name[50] = { 0x00 };

	//��������� ��� ������� ����
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "rb");

	//�������� ������ �� ����
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	int i = 0;					//��� ������������ ����� persons
	while (!feof(stream)) {		//���� �� ����� �����
		
		// ������ � ����� � ������
		fscanf(stream, "%s %d %d", name, &age, &earnings);

		// ���������� � ������������ ������
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		i++;					//��������� � ���������� person
	}
	return 0;
}


//�������� � ���� ���� txt
int writeToFileTxt(data* db) {

	//��������� ��� ������� ���� 
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "w");

	//�������� �������� �� ����
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	//�������� � ���� ������
	for (size_t i = 0; i < count; i++) {
		fprintf(stream, "%s %d %d\n", getName(&db->persons[i]), getAge(&db->persons[i]), getEarnings(&db->persons[i]));
	}
	fclose(stream);		//������� ����
	return 0;
}

//������� ���������� ���������� ���������� ���������� � �����
size_t readNumberFromFileTxt() {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "r");

	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	int ch;
	size_t numberOfPerson = 0;

	while ((ch = fgetc(stream)) != EOF) {
		if (ch == '\n') {
			numberOfPerson++;
		}
	}
	fclose(stream);
	return numberOfPerson + 1;
}

//��������� ���������� � ����� � ������������ ������
int readPersonsFromFileTxt(data* db) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "r");
	
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}
	//������ 
	unsigned char name[50];
	int earnings = 0;
	int age = 0;
	
	int i = 0;   //��� �������� ����� �����������

	//�������� ������ � ����� � ������� � ������������ ������
	while ((fscanf(stream, "%s%d%d", name, &age, &earnings)) != EOF) {
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		i++;
	}
	fclose(stream);
	return 0;
}

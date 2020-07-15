#ifndef ALGORITM_H
#define ALGORITM_H

//��������� ������� ���������
typedef struct Person {
	unsigned char name[50];
	int earnings;
	int age;
} person;


typedef struct Data {
	size_t size;
	person* persons;
}data;

enum parametr {
	byName = 0,
	byAge,
	byEarnings
};

enum sequence {
	ascending = 0,
	descending
};


data initStorage(size_t size);										//��������� ������
void addPerson(data* database, char* name, int age, int earnings);	//�������� ��������� � ������

//�������� � ������ (��������, �������, ���)
void setEarnings(person* person, int earnings);
void setAge(person* person, int age);
void setName(person* person, char* name);

//���������� (���, �������, ��������)
int getName(person* person);
int getAge(person* person);
int getEarnings(person* person);

void printStorage(data* database);	//������� �� ������� ������ � ������������ ������
void freeStorage(data* database);	//�������� ������������ ������

void sortStorage(data* database, int parametr, int sequence);	// ����������� ������ ������������ ������

//���������� �� (����������� � �������� (���, �������, ��������))
int compByNameAscending(const void* person1, const void* person2);	
int compByNameDescending(const void* person1, const void* person2);

int compByAgeDescending(const void* person1, const void* person2);
int compByAgeAscending(const void* person1, const void* person2);

int compByEarningsDescending(const void* person1, const void* person2);
int compByEarningsAscending(const void* person1, const void* person2);

//���������� � ���� ������ � ���������� ������
int writeToFileBin(data* db);
int writeToFileTxt(data* database);

//������� ���������� ��������� ������ � ��������� �����
size_t readNumberFromFileTxt();

//�������� � ������������ ������ ������ � �����
int readPersonsFromFileTxt(data* db);
int readPersonFromFileBin(data* db);
#endif

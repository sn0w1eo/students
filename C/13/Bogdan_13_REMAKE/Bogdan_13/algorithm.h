#ifndef ALGORITM_H
#define ALGORITM_H

//file
//��������� ��������� ��� ������

typedef struct {
	char name[30];
	char earnings[20];
	char age[4];
}personFromFile;

typedef struct {
	size_t size;
	personFromFile* person;
}dataFile;
/// 
/// 
/// 
typedef struct Person {
	double earnings;
	char* name;
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

data initStorage(size_t size);
void addPerson(data* database, char* name, int age, double earnings);

void setEarnings(person* person, double earnings);
void setAge(person* person, int age);
void setName(person* person, char* name);


int getName(person* person);
int getAge(person* person);
double getEarnings(person* person);

void printStorage(data* database);
void freeStorage(data* database);
void sortStorage(data* database, int parametr, int sequence);


int compByNameAscending(const void* person1, const void* person2);
int compByNameDescending(const void* person1, const void* person2);

int compByAgeDescending(const void* person1, const void* person2);
int compByAgeAscending(const void* person1, const void* person2);

int compByEarningsDescending(const void* person1, const void* person2);
int compByEarningsAscending(const void* person1, const void* person2);

//���������� � ���� ������ � ���������� ������
int writeToFileBin(data* database); 
int writeToFileTxt(data* database);

//��������� ���������� ����� ���������� � ����
size_t readNumberFromFileDat(data* database);
size_t readNumberFromFileTxt(data* database);

// �������� ������ ��� ������ � ����� 
dataFile initStorageForFile(size_t numberOfPerson);

//��������� � ���������� ������ ������ � �����
int addPersonsFromFileBin(dataFile* databaseFile);
int addPersonsFromFileTxt(dataFile* databaseFile);

//������� �� ����� ���������� ������ 
void printStorageFromFile(dataFile* db);

//����������� ������
void freeStorageFile(dataFile* db);
#endif

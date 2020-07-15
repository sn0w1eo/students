#ifndef ALGORITM_H
#define ALGORITM_H

//структура каждого персонажа
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


data initStorage(size_t size);										//выделение пам€ти
void addPerson(data* database, char* name, int age, int earnings);	//добавить персонажа в пам€ть

//добавл€т в пам€ть (зарплату, возрвст, им€)
void setEarnings(person* person, int earnings);
void setAge(person* person, int age);
void setName(person* person, char* name);

//возвращает (им€, возраст, зарплату)
int getName(person* person);
int getAge(person* person);
int getEarnings(person* person);

void printStorage(data* database);	//вывести на консоль данные в динамической пам€ти
void freeStorage(data* database);	//очистить динамическую пам€ть

void sortStorage(data* database, int parametr, int sequence);	// сортировать данные динамической пам€ти

//сортировка по (возрастанию и убыванию (им€, возраст, зарплата))
int compByNameAscending(const void* person1, const void* person2);	
int compByNameDescending(const void* person1, const void* person2);

int compByAgeDescending(const void* person1, const void* person2);
int compByAgeAscending(const void* person1, const void* person2);

int compByEarningsDescending(const void* person1, const void* person2);
int compByEarningsAscending(const void* person1, const void* person2);

//записывает в файл данные с выделенной пам€ти
int writeToFileBin(data* db);
int writeToFileTxt(data* database);

//функци€ возвращает количесто персон в текстовом файле
size_t readNumberFromFileTxt();

//записать в динамическую пам€ть данные с файла
int readPersonsFromFileTxt(data* db);
int readPersonFromFileBin(data* db);
#endif

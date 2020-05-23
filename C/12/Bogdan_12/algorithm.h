#ifndef ALGORITM_H
#define ALGORITM_H

typedef struct Person {
	double earnings;
	char* name;
	int age;
} person;



typedef struct Data {
	size_t size;
	person* persons;
}data;


enum parametr{
	byName = 0,
	byAge,
	byEarnings
};

enum sequence {
	ascending = 0,
	descending
};

data initStorage(size_t size);
void addPerson(data* db, char* name, int age, double earnings);

void setEarnings(person* per, double earnings);
void setAge(person* per, int age);
void setName(person* per, char* name);


int getName(person* per);
int getAge(person* per);
double getEarnings(person* per);

void printStorage(data* db);
void freeStorage(data* db);
void sort(data* db, int parametr, int sequence);


int compByNameAscending(const void* a, const void* b);
int compByNameDescending(const void* a, const void* b);

int compByAgeDescending(const void* a, const void* b);
int compByAgeAscending(const void* a, const void* b);

int compByEarningsDescending(const void* a, const void* b);
int compByEarningsAscending(const void* a, const void* b);
#endif

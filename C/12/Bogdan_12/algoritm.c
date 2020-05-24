
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "algorithm.h"

int count = 0;



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


void addPerson(data* db, char* name, int age, double earnings) {
	for (size_t i = 0; i < db->size - 1; i++) {
		if (db->persons[i].name != NULL) continue;
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		count++;
		break;
	}
}

void setEarnings(person* per, double earnings) {
	per->earnings = earnings;
}

void setAge(person* per, int age) {
	per->age = age;
}

void setName(person* per, char* name) {
	per->name = _strdup(name);
}

int getName(person* per) {
	return per->name;
}

int getAge(person* per) {
	return per->age;
}

double getEarnings(person* per) {
	return per->earnings;
}

void printStorage(data* db) {
	for (size_t i = 0; i < db->size - 1; i++) {
		if (db->persons[i].name != NULL) {
			printf("name: %s\n", getName(&db->persons[i]));
			printf("age: %d\n", getAge(&db->persons[i]));
			printf("earnings: %.3f\n\n", getEarnings(&db->persons[i]));
		}
	}
}

void freeStorage(data* db) {
	for (size_t i = 0; i < db->size - 1; i++) {
		free(db->persons[i].name);
		db->persons[i].age = 0;
		db->persons[i].earnings = 0;
	}
	free(db->persons);
	db->persons = NULL;
	db->size = 0;

}

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

void sort(data* db, int parametr, int sequence) {
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
	


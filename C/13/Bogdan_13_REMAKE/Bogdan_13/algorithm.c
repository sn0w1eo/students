#define _CRT_SECURE_NO_WARNINGS
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

int writeToFileBin(data* db){
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "wb");

	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	for (size_t i = 0; i < count; i++) {
		fprintf(stream, "%s %d %.3f\n", getName(&db->persons[i]), getAge(&db->persons[i]), getEarnings(&db->persons[i]));
	}
	fclose(stream);
	return 0;
}


int writeToFileTxt(data* db) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "w");

	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	for (size_t i = 0; i < count; i++) {
		fprintf(stream, "%s %d %.3f\n", getName(&db->persons[i]), getAge(&db->persons[i]), getEarnings(&db->persons[i]));
	}
	fclose(stream);
	return 0;
}


size_t readNumberFromFileDat(data* db) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "rb");

	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	freeStorage(db);

	int ch;
	size_t numberOfPerson = 0;

	while ((ch = fgetc(stream)) != EOF) {
		if (ch == '\n') {
			numberOfPerson++;
		}
	}
	fclose(stream);
	return numberOfPerson;
}

size_t readNumberFromFileTxt(data* db) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "r");

	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	freeStorage(db);

	int ch;
	size_t numberOfPerson = 0;

	while ((ch = fgetc(stream)) != EOF) {
		if (ch == '\n') {
			numberOfPerson++;
		}
	}
	fclose(stream);
	return numberOfPerson;
}

dataFile initStorageForFile(size_t numberOfPerson){
	dataFile databaseFile;
	databaseFile.size = numberOfPerson;
	databaseFile.person = calloc(numberOfPerson, sizeof(personFromFile));
	if (databaseFile.person == NULL) {
		printf("memore not alloc");
		return databaseFile;
	}
	return databaseFile;
}

int addPersonsFromFileTxt(dataFile* databaseFile) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "r");

	char name[30];
	char earnings[20];
	char age[4];
	int i = 0;

	while (fscanf(stream, "%s%s%s", name, age, earnings) != EOF) {
		setNameForFile(&databaseFile->person[i], name);
		setAgeForFile(&databaseFile->person[i], age);
		setEarningsForFile(&databaseFile->person[i], earnings);
		i++;
	}
	fclose(stream);
	return 0;
}

int addPersonsFromFileBin(dataFile* databaseFile) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "rb");

	char name[30];
	char earnings[20];
	char age[4];
	int i = 0;

	while (fscanf(stream, "%s%s%s", name, age, earnings) != EOF) {
		setNameForFile(&databaseFile->person[i], name);
		setAgeForFile(&databaseFile->person[i], age);
		setEarningsForFile(&databaseFile->person[i], earnings);
		i++;
	}
	fclose(stream);
	return 0;
}

int setNameForFile(personFromFile* person, char* name) {
	memcpy(person->name, name,30);
}

int setAgeForFile(personFromFile* person, char* age) {
	memcpy(person->age, age, 4);
}

int setEarningsForFile(personFromFile* person, char* earnings) {
	memcpy(person->earnings, earnings, 20);
}


void printStorageFromFile(dataFile* db){
	for (size_t i = 0; i < db->size ; i++) {
		printf("name: %s\n", getNameFile(&db->person[i]));
		printf("age: %s\n", getAgeFile(&db->person[i]));
		printf("earnings: %s\n\n", getEarningsFile(&db->person[i]));
	}
}

int getNameFile(personFromFile* person) {
	return person->name;
}

int getAgeFile(personFromFile* person) {
	return person->age;
}

int getEarningsFile(personFromFile* person) {
	return person->earnings;
}

void freeStorageFile(dataFile* db) {
	free(db->person);
	db->person = NULL;
}
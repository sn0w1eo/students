#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#include "algorithm.h"

int count = 0;


//инициализируем память 
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

//добавить персонажа
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

//добавить в память (зарплату)
void setEarnings(person* per, int earnings) {
	per->earnings = earnings;
}

//добавить в память (возраст)
void setAge(person* per, int age) {
	per->age = age;
}

//добавить в память (имя)
void setName(person* per, char* name) {
	memcpy(per->name, name, 50);
}

//получить  (имя)
int getName(person* per) {
	return per->name;
}

//получить (возраст)
int getAge(person* per) {
	return per->age;
}

//получить (зарплату)
int getEarnings(person* per) {
	return per->earnings;
}

//вывод на консоль всего списка
void printStorage(data* db) {
	for (size_t i = 0; i < db->size; i++) {
		if (db->persons[i].name[0] != NULL) {
			printf("name: %s\n", getName(&db->persons[i]));
			printf("age: %d\n", getAge(&db->persons[i]));
			printf("earnings: %d\n\n", getEarnings(&db->persons[i]));
		}
	}
}

//освобождение памяти
void freeStorage(data* db) {
	for (size_t i = 0; i < db->size - 1; i++) {
		db->persons[i].age = 0;
		db->persons[i].earnings = 0;
	}
	free(db->persons);
	db->persons = NULL;
	db->size = 0;
}

//сортировка по возрастанию или убыванию
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


//записать в бинарный файл
int writeToFileBin(data* db){

	//открываем или создаем файл
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "wb");

	//проверка открыт ли файл
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	//записываем данные в файл
	for (int i = 0; i < db->size; i++)
	{		
		fprintf(stream, "%-49s %-d  %-d  ", db->persons[i].name, db->persons[i].age, db->persons[i].earnings);
	}
	fclose(stream);
	return 0;
}

// записывает данные с файла в динамическую память
int readPersonFromFileBin(data* db) {
	
	// создаем буферы
	int age = 0;
	int earnings = 0;
	char name[50] = { 0x00 };

	//открываем или создаем файл
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneDAT.dat", "rb");

	//проверка открыт ли файл
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	int i = 0;					//для передвижения между persons
	while (!feof(stream)) {		//пока не конец файла
		
		// читаем с файла в буферы
		fscanf(stream, "%s %d %d", name, &age, &earnings);

		// записываем в динамическую память
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		i++;					//переходим к следующему person
	}
	return 0;
}


//записать в файл типа txt
int writeToFileTxt(data* db) {

	//открываем или создаем файл 
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "w");

	//проверка открылся ли файл
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}

	//записать в файл данные
	for (size_t i = 0; i < count; i++) {
		fprintf(stream, "%s %d %d\n", getName(&db->persons[i]), getAge(&db->persons[i]), getEarnings(&db->persons[i]));
	}
	fclose(stream);		//закрыть файл
	return 0;
}

//функция возвращает количество персонажей записанных в файле
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

//считывает информацию с файла в динамическую память
int readPersonsFromFileTxt(data* db) {
	FILE* stream = NULL;
	errno_t error = fopen_s(&stream, "phoneTXT.txt", "r");
	
	if (stream == NULL || error) {
		printf("fuck you\n");
		getch();
		return -1;
	}
	//буферы 
	unsigned char name[50];
	int earnings = 0;
	int age = 0;
	
	int i = 0;   //для смещения между персонажами

	//получаем данные с файла и заносим в динамическую память
	while ((fscanf(stream, "%s%d%d", name, &age, &earnings)) != EOF) {
		setName(&db->persons[i], name);
		setAge(&db->persons[i], age);
		setEarnings(&db->persons[i], earnings);
		i++;
	}
	fclose(stream);
	return 0;
}

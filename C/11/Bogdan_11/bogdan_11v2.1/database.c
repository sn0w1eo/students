
#include "stdio.h"
#include "stdlib.h"
#include "database.h"
#include "string.h"





book addNumber(book book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {
	book = initStorage(book);
	dataInput(book, inputName, inputNumber, inputEmail, inputZip);
	return book;
}

book initStorage(book book) {
	if (book.size == 0) {
		book.size = 1;
		book.persons = calloc(book.size, sizeof(person));
		if (book.persons == NULL) {
			printf("faild");
			return book;
		}
	}
	else {
		void* ptr;
		book.size++;
		ptr = realloc(book.persons, sizeof(person) * book.size);
		if (ptr != NULL) {
			book.persons = ptr;
		}
		if (book.persons == NULL) {
			printf("faild");
			return book;
		}
	}
	return book;
}

//ввод данных
void dataInput(book book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip) {

	setName(&book.persons[book.size - 1], inputName);
	setNumber(&book.persons[book.size - 1], inputNumber);
	setEmail(&book.persons[book.size - 1], inputEmail);
	setZip(&book.persons[book.size - 1], inputZip);
}

//ввод имени
void setName(person* book, char* inputName) {
	book->name = _strdup(inputName);
}

//ввод номера
void setNumber(person* book, char* inputNumber) {
	book->number = _strdup(inputNumber);
}

//ввод мыла
void setEmail(person* book, char* inputEmail) {
	book->email = _strdup(inputEmail);
}

//ввод зипа
void setZip(person* book, char* inputZip) {
	book->zip = _strdup(inputZip);
}




char* getName(person* persons) {
	return persons->name;
}

char* getNumber(person* persons) {
	return persons->number;
}

char* getEmail(person* persons) {
	return persons->email;
}
char* getZip(person* persons) {
	return persons->zip;
}


//при выходе очистка памяти
void freeContacts(book book) {
	for (size_t i = 0; i < book.size; i++) {
		if (book.persons[i].name != NULL) {
			free(book.persons[i].name);
			free(book.persons[i].number);
			free(book.persons[i].email);
			free(book.persons[i].zip);
		}
	}
	book.persons = NULL;
}


person* findName(book book, const char* inputName) {

	if (inputName == NULL) {
		return NULL;
	}

	if (book.persons == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < book.size; i++) {
		if (book.persons[i].name == NULL) {
			continue;
		}
		if (strcmp(inputName, book.persons[i].name) == 0) {
			return &book.persons[i];
		}
	}
	return NULL;
}

person* findNumber(book book, const char* inputNumber) {

	if (inputNumber == NULL) {
		return NULL;
	}

	if (book.persons == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < book.size; i++) {
		if (book.persons[i].number == NULL) {
			continue;
		}
		if (strcmp(inputNumber, book.persons[i].number) == 0) {
			return &book.persons[i];
		}
	}
	return NULL;
}

person* findEmail(book book, const char* inputEmail) {

	if (inputEmail == NULL) {
		return NULL;
	}

	if (book.persons == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < book.size; i++) {
		if (book.persons[i].email == NULL) {
			continue;
		}
		if (strcmp(inputEmail, book.persons[i].email) == 0) {
			return &book.persons[i];
		}
	}
	return NULL;
}

person* findZip(book book, const char* inputZip) {

	if (inputZip == NULL) {
		return NULL;
	}

	if (book.persons == NULL) {
		return NULL;
	}

	for (size_t i = 0; i < book.size; i++) {
		if (book.persons[i].zip == NULL) {
			continue;
		}
		if (strcmp(inputZip, book.persons[i].zip) == 0) {
			return &book.persons[i];
		}
	}
	return NULL;
}

int deleteContact(person* person) {

	if (person == NULL) {
		return 0;
	}
	person->name = NULL;
	free(person->name);
	person->number = NULL;
	free(person->number);
	person->email = NULL;
	free(person->email);
	person->zip = NULL;
	free(person->zip);
	person = NULL;
	return 0;
}


void iteratePersons(book book, void(callback)(person*), enum iterrate iterateOption) {
	for (size_t i = 0; i < book.size; i++) {
		switch (iterateOption)
		{
		case ITERATE_ALL:
			callback(&book.persons[i]);
			break;
		case ITERATE_FREE:
			if (book.persons[i].name == NULL) callback(&book.persons[i]);
			break;
		case ITERATE_NON_FREE:
			if (book.persons[i].name != NULL) callback(&book.persons[i]);
		}
	}
}



void printContacts(person* person) {
	
	printf("\nName  : %s\n", getName(person));
	printf("Number: %s\n", getNumber(person));
	printf("Email : %s\n", getEmail(person));
	printf("ZIP   : %s\n", getZip(person));
}


struct MatchPersons findPersonsByName(book book, const char* name) {

	struct MatchPersons rez = { 0 };
	for (size_t i = 0; i < book.size; i++) {
		if (name == NULL) {
			return rez;
		}
		if (book.persons[i].name == NULL)continue;
		if (strcmp(book.persons[i].name, name) == 0) {
			rez.findPersons[rez.size] = &book.persons[i];
			rez.size++;
		}
	}
	return rez;
}

struct MatchPersons findPersonsByNumber(book book, const char* number) {

	struct MatchPersons rez = { 0 };
	for (size_t i = 0; i < book.size; i++) {
		if (number == NULL) {
			return rez;
		}
		if (book.persons[i].name == NULL)continue;
		if (strcmp(book.persons[i].number, number) == 0) {
			rez.findPersons[rez.size] = &book.persons[i];
			rez.size++;
		}
	}
	return rez;
}

struct MatchPersons findPersonsByEmail(book book, const char* email) {

	struct MatchPersons rez = { 0 };
	for (size_t i = 0; i < book.size; i++) {
		if (email == NULL) {
			return rez;
		}
		if (book.persons[i].name == NULL)continue;
		if (strcmp(book.persons[i].email, email) == 0) {
			rez.findPersons[rez.size] = &book.persons[i];
			rez.size++;
		}
	}
	return rez;
}


struct MatchPersons findPersonsByZip(book book, const char* zip) {

	struct MatchPersons rez = { 0 };
	for (size_t i = 0; i < book.size; i++) {
		if (zip == NULL) {
			return rez;
		}
		if (book.persons[i].name == NULL)continue;
		if (strcmp(book.persons[i].zip, zip) == 0) {
			rez.findPersons[rez.size] = &book.persons[i];
			rez.size++;
		}
	}
	return rez;
}
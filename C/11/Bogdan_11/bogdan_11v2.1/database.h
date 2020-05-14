
#ifndef DATABASE_H
#define DATABASE_H




typedef struct person {
	char* name;
	char* number;
	char* email;
	char* zip;
} person;

typedef struct book {
	size_t size;
	person* persons;
} book;

enum itterate {
	ITERATE_ALL = 0,
	ITERATE_NON_FREE,
	ITERATE_FREE,
};

struct MatchPersons {
	size_t size;
	struct person* findPersons[50];
};

book initStorage(book book);
book addNumber(book book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip);

void printContacts(person* person);
void dataInput(book book, char* inputName, char* inputNumber, char* inputEmail, char* inputZip);


void setName(person* book, char* inputName);
void setNumber(person* book, char* inputNumber);
void setEmail(person* book, char* inputEmail);
void setZip(person* book, char* inputZip);
char* getName(person* persons);
char* getNumber(person* persons);
char* getEmail(person* persons);
char* getZip(person* persons);


void freeContacts(book book);

person* findName(book book, const char* inputName);
person* findNumber(book book, const char* inputNumber);
person* findEmail(book book, const char* inputEmail);
person* findZip(book book, const char* inputZip);

void iteratePersons(book book, void(callback)(person*), enum iterrate iterateOption);

struct MatchPersons findPersonsByName(book book, const char* name);
struct MatchPersons findPersonsByNumber(book book, const char* number);
struct MatchPersons findPersonsByZip(book book, const char* zip);
struct MatchPersons findPersonsByEmail(book book, const char* email);


int deleteContact(person* person);

#endif
#ifndef DATABASE_H
#define DATABASE_H

struct Database {
	struct Contact* contacts;
	size_t size;
};

struct Contact {
	long long phone;
	int       zipCode;
	char* name;
	char* email;
};

struct MatchContacts {
	size_t size;
	struct Contact* contacts[100];
};


enum IterrateFor {
	ITERATE_ALL = 0,
	ITERATE_NON_FREE,
	ITERATE_FREE,
};

struct Database newDatabase(size_t);
void deleteDatabase(struct Database*);
struct Contact* addContact(struct Database, const char*, const long long, const char*, const int);
struct Contact* findContactByPhone(const struct Database, const long long);
struct Contact* findContactByZipCode(const struct Database, const int);
struct Contact* findContactByName(const struct Database, const char*);
struct Contact* findContactByEmail(const struct Database, const char*);
void removeContact(struct Database, struct Contact*);
void iterateContacts(const struct Database, void(*callback)(struct contact*), enum IterrateFor iterateOption);

void deleteContact(struct Contact*);
void setName(struct Contact*, const char*);
void setZipCode(struct Contact*, const int);
void setPhone(struct Contact*, const long long);
void updateContact(struct Contact*, const long long, const int, const char*, const char*);
char* getName(const struct Contact*);
char* getEmail(const struct Contact*);
long long getPhone(const struct Contact*);
int getZipCode(const struct Contact* );

struct MatchContacts findContactsByName(const struct Database, const char*);
struct MatchContacts findContactsByPhone(const struct Database, const long long); 
struct MatchContacts findContactsByEmail(const struct Database, const char*);
struct MatchContacts findContactsByZipCode(const struct Database, const int);
#endif
#include "db.h"
#include "newfile.h"


struct Database newDatabase(size_t size) {
	struct Database db;
	db.size = size;
	db.contacts = calloc(sizeof(struct Contact), db.size);
	return db;
}

void deleteDatabase(struct Database* database) {
	for (int i = 0; i < database->size; i++) {
		if (database->contacts[i].name != NULL) {
			free(database->contacts[i].name);
		}
	}
	free(database->contacts);
	database->contacts = NULL;
	database->size = 0;
}

struct Contact* addContact(struct Database database, const char* name, const long long phone, const char* email, const int zipCode) {
	if (database.contacts == NULL) return NULL;
	if (name == NULL) return NULL;
	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name != NULL) continue;
		updateContact(&database.contacts[i], phone, zipCode, name, email);
		return &database.contacts[i];
	}
	return NULL;
}

void removeContact(struct Database database, struct Contact* contact) {
	if (contact == NULL) return;
	deleteContact(contact);
}


struct Contact* findContactByName(const struct Database database, const char* name) {
	if (name == NULL) return NULL;
	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (strcmp(database.contacts[i].name, name) == 0) return &database.contacts[i];
	}
	return NULL;
}

struct Contact* findContactByEmail(const struct Database database, const char* email) {
	if (email == NULL) return NULL;
	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].email == NULL) continue;
		if (strcmp(database.contacts[i].email, email) == 0) return &database.contacts[i];
	}
	return NULL;
}

struct Contact* findContactByZipCode(const struct Database database, const int zipCode) {
	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (database.contacts[i].zipCode == zipCode) return &database.contacts[i];
	}
	return NULL;
}

struct Contact* findContactByPhone(const struct Database database, const long long phone) {
	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (database.contacts[i].phone == phone) return &database.contacts[i];
	}
	return NULL;
}

void iterateContacts(const struct Database database, void(*callback)(struct Contact*), enum IterrateFor iterateOption) {
	for (int i = 0; i < database.size; i++) {
		switch (iterateOption)
		{
		case ITERATE_ALL:
			callback(&database.contacts[i]);
			break;
		case ITERATE_FREE:
			if (database.contacts[i].name == NULL) callback(&database.contacts[i]);
			break;
		case ITERATE_NON_FREE:
			if (database.contacts[i].name != NULL) callback(&database.contacts[i]);
		}
	}
}


void deleteContact(struct Contact* contact) {
	contact->zipCode = 0;
	contact->phone = 0;
	free(contact->name);
	contact->name = NULL;
	contact->email = NULL;
}

void setName(struct Contact* contact, const char* name) {
	if (contact->name != NULL) {
		free(contact->name);
	}
	contact->name = _strdup(name);
	return;
}

void setEmail(struct Contact* contact, const char* email) {
	if (contact->email != NULL) {
		free(contact->email);
	}
	contact->email = _strdup(email);
	return;
}

void setZipCode(struct Contact* contact, const int zipCode) {
	contact->zipCode = zipCode;
}

void setPhone(struct Contact* contact, const long long phone) {
	contact->phone = phone;
}

void updateContact(struct Contact* contact, const long long phone, const int zipCode, const char* name, const char* email) {
	setPhone(contact, phone);
	setZipCode(contact, zipCode);
	setName(contact, name);
	setEmail(contact, email);
}

char* getName(const struct Contact* contact) {
	return contact->name;
}

char* getEmail(const struct Contact* contact) {
	return contact->email;
}

long long getPhone(const struct Contact* contact) {
	return contact->phone;
}

int getZipCode(const struct Contact* contact) {
	return contact->zipCode;
}


struct MatchContacts findContactsByName(const struct Database database, const char* name) {
	struct MatchContacts result = { 0 };
	struct Contact** ptrcontact = result.contacts;

	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (!strcmp(database.contacts[i].name, name)) {
			*ptrcontact = &database.contacts[i];
			ptrcontact++;
			result.size++;
		}
	}
	return result;
}

struct MatchContacts findContactsByEmail(const struct Database database, const char* email) {
	struct MatchContacts result = { 0 };
	struct Contact** ptrcontact = result.contacts;

	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].email == NULL) continue;
		if (!strcmp(database.contacts[i].email, email)) {
			*ptrcontact = &database.contacts[i];
			ptrcontact++;
			result.size++;
		}
	}
	return result;
}

struct MatchContacts findContactsByPhone(const struct Database database, const long long phone) {
	struct MatchContacts result = { 0 };
	size_t counter = 0;

	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (database.contacts[i].phone == phone) {
			result.contacts[counter] = &database.contacts[i];
			counter++;
			result.size++;
		}
	}
	return result;
}

struct MatchContacts findContactsByZipCode(const struct Database database, const int zipCode) {
	struct MatchContacts result = { 0 };
	size_t counter = 0;

	for (int i = 0; i < database.size; i++) {
		if (database.contacts[i].name == NULL) continue;
		if (database.contacts[i].zipCode == zipCode) {
			result.contacts[counter] = &database.contacts[i];
			counter++;
			result.size++;
		}
	}
	return result;
}
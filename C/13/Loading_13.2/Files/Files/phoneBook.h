#ifndef PHONEBOOK_H
#define PHONEBOOK_H

typedef	struct
{
	int size;
	char* name;
	char* phone;
	char* age;
}contact;

enum modeFile{
	Binary,
	Text
};

contact* initStorage(contact* person);

contact* addPerson(contact* , char name[100], char phone[100], char age[100]);

void writeToFile(contact* person, int mode);

void readFromFile(contact* person, int mode);

void freeMemory(contact* person);

#endif // !PHONEBOOK_H


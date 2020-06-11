#include "file.h"

//files
void wFile(FILE* fin, phoneBookFile* p) {
	for (int i = 0; i < 5; i++) {
		fprintf(fin, "%d. %s"
			"    %d"
			"    %s", p[i].personName.name, p[i].personNum.age, p[i].personNum.phone);
	}

};




void PrintPhoneBooks(const phoneBook* allList, int const p) {
	for (int i = 0; i < p; i++)
	{
		printf("%d.  Name: %s  \n"
			"      Age: %d  \n"
			"    Phone: %d  \n", i, getName(allList[i]), getAge(allList[i]), getPhone(allList[i]));
		printf("\n");
	}
}

//setter

void setName(phoneBook* phonebook, const string name) {
	phonebook->personName.name = _strdup(name);
}

void setPhone(phoneBook* phonebook, int phone) {
	phonebook->personNum.phone = phone;
}

void setAge(phoneBook* phonebook, int age) {
	phonebook->personNum.age = age;
}

//getter

string getName(phoneBook const phonebook) {
	return phonebook.personName.name;
}

int getPhone(phoneBook const phonebook) {
	return phonebook.personNum.phone;
}

int getAge(phoneBook const phonebook) {
	return phonebook.personNum.age;
}



void SetPhoneBook(phoneBook* const phonebook, const string name, int const phone, int const age) {
	setName(phonebook, name);
	setPhone(phonebook, phone);
	setAge(phonebook, age);
}


int sortNameToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return strcmp(ptra->personName.name, ptrb->personName.name);
}

int sortPhoneToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptra->personNum.phone - ptrb->personNum.phone;
}

int sortAgeToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptra->personNum.age - ptrb->personNum.age;
}


int sortNameToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return strcmp(ptrb->personName.name, ptra->personName.name);
}

int sortPhoneToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptrb->personNum.phone - ptra->personNum.phone;
}

int sortAgeToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptrb->personNum.age - ptra->personNum.age;
}
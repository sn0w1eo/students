#include "file.h"
#include "stdlib.h"

//----------------------------------------------write date in file .txt--------------------------------------
void writeDataInFileTxt(FILE* stream, const phoneBook* contact) {
	for (int i = 0; i < 6; i++)
	{
		fprintf(stream, "%d. %s	 %d	 %d\n", i, contact[i].name, contact[i].age, contact[i].phone);
	}
};


//----------------------------------------------setters------------------------------------------------------
void setName(phoneBook* phonebook, const string name) {
	phonebook->name = _strdup(name);
}
void setPhone(phoneBook* phonebook, int phone) {
	phonebook->phone = phone;
}
void setAge(phoneBook* phonebook, int age) {
	phonebook->age = age;
}

//----------------------------------------------getters------------------------------------------------------
string getName(phoneBook const phonebook) {
	return phonebook.name;
}
int getPhone(phoneBook const phonebook) {
	return phonebook.phone;
}
int getAge(phoneBook const phonebook) {
	return phonebook.age;
}

//----------------------------------------------set person---------------------------------------------------

void addPerson(phoneBook* const phonebook, const string name, int const phone, int const age) {
	setName(phonebook, name);
	setPhone(phonebook, phone);
	setAge(phonebook, age);
}


//----------------------------------------------sort asc-----------------------------------------------------

int sortNameAsc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return strcmp(ptrFirstValue->name, ptrSecondValue->name);
}

int sortPhoneAsc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return ptrFirstValue->phone - ptrSecondValue->phone;
}

int sortAgeAsc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return ptrFirstValue->age - ptrSecondValue->age;
}

//----------------------------------------------sort desc----------------------------------------------------
int sortNameDesc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return strcmp(ptrSecondValue->name, ptrFirstValue->name);
}

int sortPhoneDesc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return ptrSecondValue->phone - ptrFirstValue->phone;
}

int sortAgeDesc(const void* firstValue, const void* secondValue) {
	phoneBook* ptrFirstValue = firstValue;
	phoneBook* ptrSecondValue = secondValue;
	return ptrSecondValue->age - ptrFirstValue->age;
}

//----------------------------------------------print all persons--------------------------------------------
void PrintPhoneBook(const phoneBook* contact, int const p) {
	for (int i = 0; i < p; i++) {
		printf("%d.  Name: %s  \n"
			    "     Age: %d  \n"
                "   Phone: %d", i, getName(contact[i]), getAge(contact[i]), getPhone(contact[i]));
		printf("\n");
	}
}

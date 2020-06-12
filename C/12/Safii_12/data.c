#include "data.h"

void PrintPhoneBooks(const phoneBook* allList, int const p) {
	for (int i = 0; i < p; i++)
	{
		printf("%d.  Name: %s  \n"
			"   Double: %2lf  \n"
			"    Phone: %d  \n", i, getName(allList[i]), getDouble(allList[i]), getPhone(allList[i]));
		printf("\n");
	}
}

//setter

void setName(phoneBook* phonebook, const string name) {
	phonebook->name = _strdup(name);
}

void setDouble(phoneBook* phonebook, const double double_num) {
	phonebook->double_num = double_num;
}

void setPhone(phoneBook* phonebook, int phone) {
	phonebook->phone = phone;
}


//getter

string getName(phoneBook const phonebook) {
	return phonebook.name;
}

double getDouble(phoneBook const phonebook) {
	return phonebook.double_num;
}

int getPhone(phoneBook const phonebook) {
	return phonebook.phone;
}



void SetPhoneBook(phoneBook* const phonebook, const string name, double const double_num, int const phone){
	setName(phonebook, name);
	setDouble(phonebook, double_num);
	setPhone(phonebook, phone);

}


int sortNameToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return strcmp(ptra->name, ptrb->name);
}

int sortDoubleToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptra->double_num - ptrb->double_num;
}

int sortPhoneToAsc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptra->phone - ptrb->phone;
}



int sortNameToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return strcmp(ptrb->name, ptra->name);
}

int sortDoubleToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptrb->double_num - ptra->double_num;
}

int sortPhoneToDesc(const void* a, const void* b) {
	phoneBook* ptra = a;
	phoneBook* ptrb = b;
	return ptrb->phone - ptra->phone;
}

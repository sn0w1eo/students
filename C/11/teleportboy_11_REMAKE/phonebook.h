#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//Синоним unsigned long long int
typedef unsigned long long int ulong;

//Синоним unsigned char
typedef unsigned char uchar;

//Синоним к указатель на unsigned char
typedef unsigned char* string;

typedef struct phonebook
{
	int size;            //Размер массива типа phonebook
	ulong zip;
	string name;
	string email;
	string phoneNumber;
	
}PHONEBOOK;

enum Search
{
	BY_NAME = 1,
	BY_NUMBER,
	BY_EMAIL,
	BY_ZIPCODE,
};

enum Boolean
{
	FALSE = 0,
	TRUE,
};

PHONEBOOK* AddContact(PHONEBOOK*, const string, const string, const string, const ulong);
void SetName(PHONEBOOK*, const string);
void SetPhoneNumber(PHONEBOOK*, const string);
void SetEmail(PHONEBOOK*, const string);
void SetZipCode(PHONEBOOK*, const ulong);

void UpdateContact(PHONEBOOK*, const string, const string, const string, const ulong, int);

void DeleteContact(PHONEBOOK*, int);

void PrintSeachResults(PHONEBOOK**, int);
PHONEBOOK** FindByName(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByPhoneNumber(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByEmail(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByZipCode(PHONEBOOK*, PHONEBOOK**, ulong);

int CheckArguments(PHONEBOOK*, const string, const string, const string);
int IsFreeSpace(PHONEBOOK*);
PHONEBOOK* GetFreeSpace(PHONEBOOK*);

void PrintContacts(PHONEBOOK*);
string GetName(const PHONEBOOK);
string GetPhoneNumber(const PHONEBOOK);
string GetEmail(const PHONEBOOK);
ulong GetZipCode(const PHONEBOOK);

#endif // !PHONEBOOK_H

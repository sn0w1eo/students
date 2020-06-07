#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//Синоним unsigned char
typedef unsigned char uchar;

//Синоним к указатель на unsigned char
typedef unsigned char* string;

typedef struct
{
	string name;
	string phoneNumber;
	string email;
	string zip;

}PhoneBook;

enum Search
{
	ByName = 1,
	ByNumber,
	ByEmail,
	ByZipCode,
};

enum Boolean
{
	False = 0,
	True,
};

PhoneBook* AddContact(PhoneBook*, const string _StringName, const string _StringNumber, const string _StringEmail, const string _StringZipCode);
void UpdateContact(PhoneBook* _PhoneBookArray, const string name, const string phoneNumber, const string email, const string zip, const int contactIndex);
void DeleteContacts(PhoneBook* _PhoneBookArray, int argumentsCount, ...);
void PrintContacts(PhoneBook* _PhoneBookArray);
int GetContactsCount(PhoneBook* phoneBook);

void SetSize(PhoneBook* _PhoneBookArray, const int size);
void SetName(PhoneBook* _PhoneBookArray, const string name);
void SetPhoneNumber(PhoneBook* _PhoneBookArray, const string phoneNumber);
void SetEmail(PhoneBook* _PhoneBookArray, const string email);
void SetZipCode(PhoneBook* _PhoneBookArray, const string zipCode);

int GetSize(PhoneBook* _PhoneBookArray);
string GetName(const PhoneBook _PhoneBookArray);
string GetPhoneNumber(const PhoneBook _PhoneBookArray);
string GetEmail(const PhoneBook _PhoneBookArray);
string GetZipCode(const PhoneBook _PhoneBookArray);

int CheckArguments(PhoneBook* _PhoneBookArray, const string, const string, const string);
int IsFreeSpace(PhoneBook* _PhoneBookArray);
PhoneBook* GetFreeSpace(PhoneBook* _PhoneBookArray);

int AscendingCompareByName(void* a, void* b);
int AscendingCompareByPhoneNumber(void* a, void* b);
int AscendingCompareByEmail(void* a, void* b);
int AscendingCompareByZipCode(void* a, void* b);
int DiscendingCompareByName(void* a, void* b);
int DiscendingCompareByPhoneNumber(void* a, void* b);
int DiscendingCompareByEmail(void* a, void* b);
int DiscendingCompareByZipCode(void* a, void* b);


#endif // !PHONEBOOK_H

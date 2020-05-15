#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//Синоним unsigned char
typedef unsigned char uchar;

//Синоним к указатель на unsigned char
typedef unsigned char* string;

typedef struct phonebook
{
	int size;            //Размер массива типа phonebook
	string zip;
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

//Добавить контакт.
PHONEBOOK* AddContact(PHONEBOOK*, const string, const string, const string, const string);

//Изменить контакт.
void UpdateContact(PHONEBOOK*, const string, const string, const string, const string, int);

//Удалить контакт.
void DeleteContacts(PHONEBOOK*, int, ...);

//Вывод содержимого полей структуры в stdout.
void PrintSeachResults(PHONEBOOK**, int);
void PrintContacts(PHONEBOOK*);

//Сетеры
void SetName(PHONEBOOK*, const string);
void SetPhoneNumber(PHONEBOOK*, const string);
void SetEmail(PHONEBOOK*, const string);
void SetZipCode(PHONEBOOK*, const string);
void SetSize(PHONEBOOK*, const int);

//Гетеры
string GetName(const PHONEBOOK);
string GetPhoneNumber(const PHONEBOOK);
string GetEmail(const PHONEBOOK);
string GetZipCode(const PHONEBOOK);
int GetSize(const PHONEBOOK);
PHONEBOOK* GetFreeSpace(PHONEBOOK*);


//Поиск
PHONEBOOK** DoSearch(PHONEBOOK*, PHONEBOOK**, string, PHONEBOOK** (*callback)(PHONEBOOK*, PHONEBOOK**, string));
PHONEBOOK** FindByName(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByPhoneNumber(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByEmail(PHONEBOOK*, PHONEBOOK**, string);
PHONEBOOK** FindByZipCode(PHONEBOOK*, PHONEBOOK**, string);

//Чекеры :D
int CheckArguments(PHONEBOOK*, const string, const string, const string);
int IsFreeSpace(PHONEBOOK*);





#endif // !PHONEBOOK_H

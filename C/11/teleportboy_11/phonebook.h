#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//Синоним к unsigned char
typedef unsigned char uchar;

//Синоним к unsigned long long int
typedef unsigned long long int ulong;

typedef struct
{
	int size;             //Размер выделенных "ячеек" памяти под массив типа phonebook.
	uchar* name;          //Указатель на строку предназначенной для имени.
	uchar* email;         //Указатель на строку предназначенной для email.
	uchar* phoneNumber;   //Указатель на строку предназначенной для номера телефона.
	ulong zipCode;
	
}phonebook;

enum Search
{
	BY_NAME = 1,
	BY_NUMBER,
	BY_EMAIL,
	BY_ZIPCODE,
};

enum bool
{
	FALSE = 0,
	TRUE,
};
#endif // !PHONEBOOK_H
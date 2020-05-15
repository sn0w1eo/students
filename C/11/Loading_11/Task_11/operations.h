#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct
{
	char* name;
	char* phone;
	char* email;
	char* zipCode;
}myStruct;

myStruct addContact(myStruct temp, char name[100], char number[100], char email[100], char zipCode[100]);
myStruct updateContact(myStruct temp, char name[100], char number[100], char email[100], char zipCode[100]);
myStruct deleteContact(myStruct temp);
void searchByName(myStruct temp, char name[100]);
void searchByPhone(myStruct temp, char phone[100]);
void searchByEmail(myStruct temp, char email[100]);
void searchByZipCode(myStruct temp, char zipCode[100]);
#endif

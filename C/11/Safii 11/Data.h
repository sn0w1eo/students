#ifndef DATA_H
#define DATA_H


typedef struct {
	char* name;
	char* phone;
	char* email;
	char* zipCode;

} MyStruct;



MyStruct addContact( MyStruct person,  char name[50],  char phone[50],  char email[50],  char zipCode[50]);
MyStruct updateContact( MyStruct person, char name[50], char phone[50], char email[50], char zipCode[50]);
MyStruct deleteContact( MyStruct person);
void searchByName( MyStruct person, char name[50]);
void searchByPhone( MyStruct person, char phone[50]);
void searchByEmail( MyStruct person, char email[50]);
void searchByZipCode( MyStruct person, char zipCode[50]);

void strcopy( const char*, const char*);



#endif
#ifndef PHONEBOOK_H
#define PHONEBOOK_H

//Синоним unsigned char
typedef unsigned char uchar;

//Синоним к указатель на unsigned char
typedef uchar* string;

typedef struct
{
	string name;                       //Имя контакта.
	string phone;                      //Номер телефона контакта.
	string email;                      //Электронная почта контакта.
	string zip;                        //ZIP-код контакта.
	unsigned int contactStatus : 1;    //Пустой контакт или нет?.
}ContactData;

typedef struct
{
	ContactData* contacts;             //Контакты.
}PhoneBook;

//Для работы с бинарным режимом ввода/вывода в/из файл(а).
typedef struct
{
	uchar name[31];
	uchar phone[31];
	uchar email[31];
	uchar zip[10];

}Contact;

//Существует контакт или нет.
enum ContactStatus
{
	Blank,
	Existing,
};

enum ContactInfo
{
	Name,
	Phone,
	Email,
	ZipCode,
};

enum Boolean
{
	False = 0,
	True,
};

//===============================================================РАБОТА С МАССИВОМ типа ContactData contacts==========================================================
void AddContact(PhoneBook* _PointerToPhoneBook, const string _NameString, const string _PhoneString, const string _EmailString, const string _ZipString);
void UpdateContact(ContactData* _PointerToContact, const string _NameString, const string _PhoneString, const string _EmailString, const string _ZipString);
void DeleteContacts(ContactData* _ContactsArray, int _ArgumentsCount, ...);
ContactData* GetFreeSpace(ContactData* _ContactsArray);
ContactData* GetFirstByteOfContacts(ContactData* _ContactsArray);
ContactData* MoveByFourBytes(ContactData* _ContactsArray);
int GetContactsCount(ContactData* _ContactsArray);
void PrintContacts(ContactData* _ContactsArray);

//===============================================================ГЕТТЕРЫ=========================================================================================================
ContactData* GetContacts(PhoneBook* _PointerToPhoneBook);
string GetContactDataFieldByArgument(ContactData _Contact, enum ContactInfo _DataFieldEnum);
int GetSize(ContactData* _ContactArray);
string GetName(ContactData _Contact);
string GetPhone(ContactData _Contact);
string GetEmail(ContactData _Contact);
string GetZipCode(ContactData _Contact);
int GetContactStatus(ContactData _Contact);

//===============================================================СЕТТЕРЫ=========================================================================================================
void SetContacts(PhoneBook* _PointerToPhoneBook, ContactData* _ContactArray);
void SetSize(ContactData* _ContactsArray, const int _ElementsCount);
void SetName(ContactData* _PointerToContact, const string _NameString);
void SetPhone(ContactData* _PointerToContact, const string _PhoneString);
void SetEmail(ContactData* _PointerToContact, const string _EmailString);
void SetZipCode(ContactData* _PointerToContact, const string _ZipString);
void SetContactStatus(ContactData* _PointerToContact, enum ContactStatus _ContactStatus);

//===============================================================ЧЕКЕРЫ===========================================================================================================
int CheckArguments(ContactData* _ContactsArray, const string _NameString, const string _PhoneString, const string _EmailString);
int IsFreeSpace(ContactData* _ContactsArray);

//===============================================================СОРТИРОВКА=======================================================================================================
int AscendingCompareByName(void* _Contact, void* _Contact_);
int AscendingCompareByPhoneNumber(void* _Contact, void* _Contact_);
int AscendingCompareByEmail(void* _Contact, void* _Contact_);
int AscendingCompareByZipCode(void* Contact, void* _Contact);

int DiscendingCompareByName(void* _Contact, void* _Contact_);
int DiscendingCompareByPhoneNumber(void* _Contact, void* _Contact_);
int DiscendingCompareByEmail(void* _Contact, void* _Contact_);
int DiscendingCompareByZipCode(void* _Contact, void* _Contact_);

#endif // !PHONEBOOK_H
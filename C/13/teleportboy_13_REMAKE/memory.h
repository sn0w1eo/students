#ifndef MEMORY_H
#define MEMORY_H

#include "phonebook.h"

ContactData* InitStorageForContacts(int _ElementsCount);
ContactData* ReallocStorageForContacts(ContactData* _ContactsArray);
void FreeContactMemory(ContactData* _PointerToContact);
void FreeMemory(PhoneBook* _PointerToPhoneBook, PhoneBook* _PointerToSearchBook, PhoneBook* _PointerToPhoneBookTXT, Contact* _PointerToPhoneBookDAT);;

#endif // !MEMORY_H

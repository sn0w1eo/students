#ifndef SEARCH_H
#define SEARCH_H

#include "phonebook.h"

//Поиск по массиву phoneBook.
void DoContactSearch(PhoneBook* _Source, PhoneBook* Destination, string _SearchPurposeString, enum ContactInfo _SearchTypeEnum);

#endif // !SEARCH_H
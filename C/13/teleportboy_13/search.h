#ifndef SEARCH_H
#define SEARCH_H

#include "phonebook.h"

//Поиск по массиву phoneBook.
PhoneBook** DoSearch(PhoneBook*, PhoneBook**, string, PhoneBook** (*callback)(PhoneBook*, PhoneBook**, string));
PhoneBook** FindByName(PhoneBook*, PhoneBook**, string);
PhoneBook** FindByPhoneNumber(PhoneBook*, PhoneBook**, string);
PhoneBook** FindByEmail(PhoneBook*, PhoneBook**, string);
PhoneBook** FindByZipCode(PhoneBook*, PhoneBook**, string);

//Вывод массива searchBook.
void PrintSeachResults(PhoneBook** searchBook, int size);

#endif // !SEARCH_H

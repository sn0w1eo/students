#ifndef SEARCH_H
#define SEARCH_H

#include "phonebook.h"

//Поиск по имени.
int FindByName(phonebook* phoneBook);

//Поиск по номеру телефона.
int FindByPhoneNumber(phonebook* phoneBook);

//Поиск по email.
int FindByEmail(phonebook* phoneBook);

//Поиск по ZipCode.
int FindByZipCode(phonebook* phoneBook);

//Выполнить поиск взависимости от аргумента.
int DoSearch(phonebook* phoneBook, int(*criterion)(phonebook*));

#endif // !SEARCH_H
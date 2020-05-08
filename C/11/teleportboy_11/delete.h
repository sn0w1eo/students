#ifndef DELETE_H
#define DELETE_H

#include "phonebook.h"

//Удалить контакт.
void DeleteContact(phonebook* phoneBook, int contactIndex);

//Удалить имя.
void DeleteName(phonebook* phoneBook, int contactIndex);

//Удалить номер телеофна.
void DeletePhoneNumber(phonebook* phoneBook, int contactIndex);

//Удалить email.
void DeleteEmail(phonebook* phoneBook, int contactIndex);

//Удалить ZipCode.
void DeleteZipCode(phonebook* phoneBook, int contactIndex);

#endif // !DELETE_H
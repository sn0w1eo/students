#ifndef READ_H
#define READ_H

#include "phonebook.h"

//Отобразить все контакты.
void DisplayAllContacts(phonebook* phoneBook);

//Отобразить имя.
void DisplayName(phonebook* phoneBook, int contactIndex);

//Отобразить номер телефона.
void DisplayPhoneNumber(phonebook* phoneBook, int contactIndex);

//Отобразить email.
void DisplayEmail(phonebook* phoneBook, int contactIndex);

//Отобразить ZipCode.
void DisplayZipCode(phonebook* phoneBook, int contactIndex);

#endif // !READ_H
#ifndef CREATE_H
#define CREATE_H

#include "phonebook.h"

//Добавить контакт.
phonebook* AddContact(phonebook* phoneBook, int* contactIndex);

//Выделить/перераспределить память.
phonebook* GetMemory(phonebook* phoneBook);

//Добавить имя.
void AddName(phonebook* phoneBook, int* contactIndex);

//Добавить номер телефона.
void AddPhoneNumber(phonebook* phoneBook, int* contactIndex);

//Добавить email.
void AddEmail(phonebook* phoneBook, int* contactIndex);

//Добавить ZipCode.
void AddZipCode(phonebook* phoneBook, int* contactIndex);

#endif // !CREATE_H
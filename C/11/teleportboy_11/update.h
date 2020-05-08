#ifndef UPDATE_H
#define UPDATE_H

#include "phonebook.h"

void UpdateContact(phonebook* phoneBook, int contactIndex);

void UpdateName(phonebook* phoneBook, int contactIndex);
void UpdatePhoneNumber(phonebook* phoneBook, int contactIndex);
void UpdateEmail(phonebook* phoneBook, int contactIndex);
void UpdateZipCode(phonebook* phoneBook, int contactIndex);

#endif // !UPDATE_H
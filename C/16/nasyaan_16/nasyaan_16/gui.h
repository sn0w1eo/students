#ifndef GUI_H
#define GUI_H

#include "phonebook.h"
#include "windows.h"
#include "tchar.h"

#define ID_ADD_NUMBER 1
#define ID_DELETE_NUMBER 2
#define ID_UPDATE_NUMBER 3
#define ID_COMBOBOX_TEXT 4
#define ID_EXIT 5
#define ID_NAME 6
#define ID_NUMBER 7
#define ID_STATIC_TEXT 8
#define ID_NEWNAME 9
#define ID_NEWNUMBER 10
#define ID_USER_PHONE 11

#define ARRAY_SIZE 100
#define BUFF_SIZE 128

PhoneDB pdb;

void InitControlsAndText(HWND hwnd);

void InitComboBox(HWND hwndCombo, PhoneDB* pdb);
void InitAddButton(HWND hwnd, HWND hwndName, HWND hwndPhone, PhoneDB* pdb);
void InitUpdateButton(HWND hwnd, HWND hwndNewName, HWND hwndNewPhone, PhoneDB* pdb);
void getUsersPhone(HWND hwnd, PhoneDB* db);
void getUsersPhoneD(HWND hwnd, PhoneDB* db);
void deleteFmCB(HWND hwnd, PhoneDB* db);

#endif // !GUI_H

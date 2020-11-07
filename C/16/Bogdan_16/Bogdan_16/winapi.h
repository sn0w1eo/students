#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "strsafe.h"
#include "phoneBook.h"


//для каждого элемента окна выделяем ID адрес по которому будем к ним обращаться
#define ID_ADD_BUTTON 1
#define ID_DELETE_BUTTON 2
#define ID_UPDATE_BUTTON 3
#define ID_EXIT_BUTTON 4
#define ID_NAME_EDIT 5
#define ID_NUMBER_EDIT 6
#define ID_STATIC_TEXT_PHONE 7
#define ID_LISTBOX 8
#define ID_CHANGE_TEXT 9
#define ID_STATIC_TEXT_NAME 10

#ifndef WINAPI
#define WINAPI

void updateButton(HWND hwnd);
void deleteButton(HWND hwnd);
void InitListBox(HWND hwnd);
void printPhoneOfPerson(HWND hwnd);
void addButton(HWND hwnd);
void createWindowElements(HWND hwnd);

#endif // !WINAPI

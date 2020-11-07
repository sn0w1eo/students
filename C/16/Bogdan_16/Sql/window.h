#include "windows.h"

#ifndef WINDOWS
#define WINDOWS

void createWindowElements(HWND hwnd);					//создание всех элементов окна
void openAndCreateBD();									//создание и открытие БД
void addButton(HWND hwnd);								//обработка кнопки add
void printPhoneOfPerson(HWND hwnd);						//показывает данные лежащие в БД			
void InitListBox(HWND hwndListBox);						//заполняет listBox именами
void deleteButton(HWND hwnd);							//обработка кнопки delete
void updateButton(HWND hwnd);							//обработка кнопки update

#endif 


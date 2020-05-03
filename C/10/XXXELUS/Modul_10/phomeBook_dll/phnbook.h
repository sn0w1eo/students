
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "windows.h"
#include "time.h"

#define NAME_SIZE    20
#define NUMBER_SIZE  14
#define AGE_SIZE     3
#define TOTAL_SIZE   37
#define CONTACTS     10

/*Key macros*/

#define ESC          0x1B


/*Color macros*/

#define LIGHT_RED    0x0C
#define LIGHT_BLUE   0x09
#define LIGHT_GREEN  0x0A
#define LIGHT_YELLOW 0x0E
#define CYAN         0x0B
#define WHITE        0x0F
#define GREEN        0x02
#define BLUE         0x03
#define DEFAULT      0x07 
#define GREY         0x08

#ifndef PHNBOOK_H
#define PHNBOOK_H

__declspec(dllexport) void copy(char* dest, const char* source);
__declspec(dllexport) void addContactStatic(char** contact, const char* name, const char* number, const char* age);
__declspec(dllexport) int addContactByKeyboard(char** contact);
__declspec(dllexport) void showContacts(char** list);
__declspec(dllexport) void deleteContact(char** contact);
__declspec(dllexport) void wait();
__declspec(dllexport) void color(int color);
__declspec(dllexport) int searchContact(char** contact);
__declspec(dllexport) int updateContact(char** contact);
__declspec(dllexport) void showLegend();
__declspec(dllexport) void setPosition(int x, int y);
__declspec(dllexport) void printContact(char** contact, char number);
__declspec(dllexport) char* setTime();


#endif // !PHNBOOK_H

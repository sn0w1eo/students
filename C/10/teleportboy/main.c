#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

///CRUD
#include "create.h"
#include "read.h"
#include "update.h"
#include "delete.h"

///OTHER
#include "memory.h"
#include "visualization.h"
#include "engine.h"

//Cиноним к unsigned char.
typedef unsigned char uchar;

int main()
{
	void* list = NULL;

	system("mode con cols=131 lines=45");
	
	list = GetMemory(list);   //Инициализировать память.

	HideCursor();             //Спрятать курсор.
	DisplayHotkeys();         //Отобразить ХотКеи.
	DisplayCap(list);         //Отобразить шапку.
	DisplayFrames(list);      //Отобразить таблицу.
	DisplayContacts(list);    //Отобразить контакты.
	
	GetKeystroke(list);       //Основной цикл программы.
	
	FreeMemory(list);         //Очистить память.
}

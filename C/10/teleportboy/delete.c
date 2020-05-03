/*/——————————————————————————————————————————————\
 |                                                |
 | Функция DeleteContact очищает память с данными |
 | о контакте.                                    |
 |                                                |
 | Функции DeletePhoneNumber и DeleteDate         |
 | "затирают" данные в определенных областях      |
 | блока памяти одним символом                    |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"

//Синоним к unsigned char.
typedef unsigned char uchar;

//Удалить весь контакт.
void DeleteContact(uchar** list, int contactIndex)
{
	//Зачистить блок памяти в котором хранятся все данные о контакте.
	free(list[contactIndex]);
	list[contactIndex] = NULL;
}

//Затиреть номер телефона.
void DeletePhoneNumber(uchar** list, int contactIndex)
{
	int nameLength = list[contactIndex][0];             //Длина имени.
	int phoneLength = list[contactIndex][nameLength];   //Длина номера телефона.
	
	//"Затиреть" данные о номере телефона другим символом.
	memset(&list[contactIndex][nameLength + 1], '-', sizeof(uchar) * phoneLength - 2);
}

//Затиреть дату.
void DeleteDate(uchar** list, int contactIndex)
{
	int nameLength = list[contactIndex][0];                          //Длина имени.
	int phoneLength = list[contactIndex][nameLength];                //Длина номера телефона.
	int dateLength = list[contactIndex][nameLength + phoneLength];   //Длина даты.
	
	//"Затиреть" данные о дате другим символом.
	memset(&list[contactIndex][nameLength + phoneLength + 1], '-', sizeof(uchar) * dateLength - 2);
}
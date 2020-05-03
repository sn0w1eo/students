/*/——————————————————————————————————————————————\
 |                                                |
 | Так как блоки памяти содержащие в себе в       |
 | частности такие данные как имя, номер и дата,  |
 | логически поделены на 3 части и хранят в начале|
 | каждой такой части деления размер этого блока. |
 | Функции манипулируют этими данными и на основе |
 | этих вычисленний выделяют и перераспределяют   |
 | память что бы сохранить в ней новые данные     |
 | полученные из stdin.                           |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

 //Синоним к unsigned char
typedef unsigned char uchar;

//Перезаписать имя.
uchar** UpdateName(uchar** list, int contactIndex)
{
	uchar** tempList = NULL;   //Создать временную переменную указатель на указатель.
	tempList = list;           //и записать в него адрес основного блока памяти.
	
	uchar* tempBlock;          //Временная переменная указатель на unsigned char
	                           //в которую будут записаны текущие номер телефона и дата.

	int nameLength = list[contactIndex][0];                        //Длина имени.
	int phoneLength = list[contactIndex][nameLength];              //Длина номера телефона.
	int dateLength = list[contactIndex][nameLength + phoneLength]; //Длина даты.
	int newNameLength;                                             //Длина нового имени.
	int newListLength;                                             //Длина нового блока памяти.

	uchar buffer[50] = { 0x00 };
	//======================================================================================================

	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0]));            //Записать новое имя.

	newNameLength = strlen(buffer) + 2;                            //Длина блока памяти под новое имя.
	newListLength = newNameLength + nameLength + phoneLength;      //Новая длина блока памяти под все данные.

	//Выделить память для временной строки.
	tempBlock = calloc(phoneLength + dateLength, sizeof(uchar));
	if (tempBlock == NULL)
	{
		printf_s("Memory allocation falied!");
		return NULL;
	}

	//Скопировать текущий номер телефона  в новую временную строку.
	strcpy_s(&tempBlock[0], phoneLength, &list[contactIndex][nameLength]);

	//Скопировать текущую дату в новую временную строку.
	strcpy_s(&tempBlock[phoneLength], dateLength, &list[contactIndex][nameLength + phoneLength]);

	//Перераспределить блок памяти для хранения обновлённых данных.
	tempList[contactIndex] = realloc(list[contactIndex], sizeof(uchar) * newListLength);
	if (tempList[contactIndex] == NULL)
	{
		printf_s("Memory allocation falied!");
		return tempList;
	}
	
	//Скопировать новое имя в новый блок памяти и записать в 0-ую ячейку этого блока памяти его размер.
	strcpy_s(&list[contactIndex][1], newNameLength - 1, buffer);
	list[contactIndex][0] = newNameLength;

	//Скопировать текущий номер телефона с временного указателя на строку, в новый блок памяти.
	strcpy_s(&list[contactIndex][newNameLength], phoneLength, &tempBlock[0]);
	
	//Скопировать текущую дату с временного указателя на строку, в новый блок памяти.
	strcpy_s(&list[contactIndex][newNameLength + phoneLength], dateLength, &tempBlock[phoneLength]);

	free(tempBlock);
	tempBlock = NULL;
	
	return tempList;
}

//Перезаписать номер телефона.
uchar** UpdatePhoneNumber(uchar** list, int contactIndex)
{
	uchar** tempList = NULL;   //Создать временную переменную указатель на указатель
	tempList = list;           //и записать в него адрес основного блока памяти.

	uchar* tempBlock;          //Временная переменная указатель на unsigned char
	                           //в которую будут записаны текущие имя и дата.

	int nameLength = list[contactIndex][0];                        //Длина имени.
	int phoneLength = list[contactIndex][nameLength];              //Длина номера телефона.
	int dateLength = list[contactIndex][nameLength + phoneLength]; //Длина даты.
	int newPhoneLength;                                            //Длина нового номера телефона.
	int newListLength;                                             //Длина нового блока памяти.
	
	uchar buffer[50] = { 0x00 };
	//======================================================================================================
	
	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0]));            //Записать новый номер телефона.

	newPhoneLength = strlen(buffer) + 2;                           //Длина блока памяти под новый номер телефона.
	newListLength = newPhoneLength + nameLength + dateLength;      //Новая длина блока памяти под все данные.

	//Выделить память для временной строки.
	tempBlock = calloc(nameLength + dateLength, sizeof(uchar));
	if (tempBlock == NULL)
	{
		printf_s("Memory allocation falied!");
		return NULL;
	}
	
	//Скопировать текущее имя в новую временную строку.
	strcpy_s(&tempBlock[0], nameLength, &list[contactIndex][0]);

	//Скопировать текущую дату в новую временную строку.
	strcpy_s(&tempBlock[nameLength], dateLength, &list[contactIndex][nameLength + phoneLength]);

	//Перераспределить блок памяти для хранения обновлённых данных.
	tempList[contactIndex] = realloc(list[contactIndex], sizeof(uchar) * newListLength);
	if (tempList[contactIndex] == NULL)
	{
		printf_s("Memory allocation falied!");
		return tempList;
	}

	//Скопировать новый номер в новый блок памяти и записать в "0-ую" ячейку этого блока памяти его размер.
	strcpy_s(&list[contactIndex][nameLength + 1], newPhoneLength - 1, buffer);
	list[contactIndex][nameLength] = newPhoneLength;

	//Скопировать текуще имя с временного указателя на строку, в новый блок памяти.
	strcpy_s(&list[contactIndex][0], nameLength, &tempBlock[0]);

	//Cкопировать текущую дату с временного указателя на строку в новый блок памяти.
	strcpy_s(&list[contactIndex][newPhoneLength + nameLength], dateLength, &tempBlock[nameLength]);

	free(tempBlock);
	tempBlock = NULL;

	return tempList;
}

//Перезаписать дату.
uchar** UpdateDate(uchar** list, int contactIndex)
{
	uchar** tempList = NULL;   //Создать временную переменную указатель на указатель
	tempList = list;           //и записать в него адрес основного блока памяти.
	
	uchar* tempBlock;          //Временная переменная указатель на unsigned char
	                           //в которую будут записаны текущие имя и номер телефона.
	
	int nameLength = list[contactIndex][0];                        //Длина имени.
	int phoneLength = list[contactIndex][nameLength];              //Длина номера телефона.
	int dateLength = list[contactIndex][nameLength + phoneLength]; //Длина даты.
	int newDateLength;                                             //Длина новой даты.
	int newListLength;                                             //Длина нового блока памяти.
	
	uchar buffer[50] = { 0x00 };
	//======================================================================================================

	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0]));            //Записать новую дату телефона.

	newDateLength = strlen(buffer) + 2;                            //Длина блока памяти под новую дату.
	newListLength = newDateLength + nameLength + dateLength;       //Новая длина блока памяти под все данные.

	//Выделить память для временной строки.
	tempBlock = calloc(nameLength + phoneLength, sizeof(uchar));
	if (tempBlock == NULL)
	{
		printf_s("Memory allocation falied!");
		return NULL;
	}

	//Скопировать текущее имя в новую временную строку.	
	strcpy_s(&tempBlock[0], nameLength, &list[contactIndex][0]);

	//Скопировать текущий номер в новую временную строку.
	strcpy_s(&tempBlock[nameLength], phoneLength, &list[contactIndex][nameLength]);

	//Перераспределить блок памяти для хранения обновлённых данных.
	tempList[contactIndex] = realloc(list[contactIndex], sizeof(uchar) * newListLength);

	if (tempList[contactIndex] == NULL)
	{
		printf_s("Memory allocation falied!");
		return tempList;
	}

	//Скопировать новую дату в новый блок памяти и записать в "0-ую" ячейку этого блока памяти его размер.
	strcpy_s(&list[contactIndex][nameLength + phoneLength + 1], newDateLength - 1, buffer);
	list[contactIndex][nameLength + phoneLength] = newDateLength;

	//Скопировать текущее имя с временного указателя на строку, в новый блок памяти.
	strcpy_s(&list[contactIndex][0], nameLength, &tempBlock[0]);

	//Скопировать текущий номер телефона с временного указателя на строку, в новый блок памяти.
	strcpy_s(&list[contactIndex][nameLength], phoneLength, &tempBlock[nameLength]);

	free(tempBlock);
	tempBlock = NULL;
	
	return tempList;
}
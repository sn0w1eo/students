/*/——————————————————————————————————————————————\
 |                                                |
 | Все три функции принимают в качестве аргумента |
 | указатель на блок памяти и индекс ячейки.      |
 | В ней хранится указатель на блок памяти куда   |
 | будут записываться данные.                     |
 |                                                |
 | Каждая функция запрашивает ввод данных у       |
 | пользователя с клавиатуры и выделяет память    |
 | в куче под эти данные.                         |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//Cиноним к unsigned char.
typedef unsigned char uchar;

//Добавить контакт.
uchar** AddContact(uchar** list, int contactIndex)
{	
	uchar buffer[50] = { 0x00 };  //Буфер для имени.
	int nameLength;               //Длина имени.

	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0]));  //Ввод имени. scanf_s("%[^\n]", buffer);
	nameLength = (strlen(buffer) + 2);                   //Записать длину имени в переменную.
	//================================================================================================

	//Если указатель пустой, присваеваем ему указатель на выделенную память.
	if (list[contactIndex] == NULL)
	{
		//Выделить память в "определенную ячейку"
		list[contactIndex] = (uchar*)malloc(sizeof(uchar*) * nameLength);
		if (list[contactIndex] == NULL)
		{
			printf_s("Memory allocation falied!");
			return list;
		}
		list[contactIndex][0] = nameLength; //В нулевую ячейку новой памяти записать длину имени.
	}
	
	//Записать имя. Передаю адресс ячейки с которой начать запись
	strcpy_s(&list[contactIndex][1], nameLength, buffer); //Запись имени

	return list;
}

//Добавить номер телефона.
uchar** AddPhoneNumber(uchar** list, int contactIndex)
{
	uchar** tempList = NULL;                            //Создать временную переменную указатель на указатель
	tempList = list;                                    //и записать в него адрес основного блока памяти
	uchar buffer[25] = { 0x00 };                        //Буфер для номера телефона
	int phoneLength;
	int nameLength = list[contactIndex][0];             //В этой ячейке длина имени
	int position = nameLength;                          //индекс с которого можно вносить другие данные
	//================================================================================================

	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0])); //Ввод номера.

	phoneLength = strlen(buffer) + 2;                   //+2 учитывая /0 и доп. ячейку для хранения длины номера

	//перераспределить память с учётом новых данных(телефонный номер)
	tempList[contactIndex] = realloc(list[contactIndex], sizeof(uchar) * (nameLength + phoneLength));
	if (tempList[contactIndex] == NULL)
	{
		printf_s("Memory allocation falied!");
		return tempList;
	}
	list[contactIndex][position] = phoneLength;                           //Записать длину номера телефона
	strcpy_s(&list[contactIndex][position + 1], phoneLength - 1, buffer); //Запись номера телефона

	return tempList;
}

//Добавить дату.
uchar** AddDate(uchar** list, int contactIndex)
{
	uchar** tempList = NULL;      //Создать временную переменную указатель на указатель
	tempList = list;              //и записать в него адрес основного блока памяти
	uchar buffer[15] = { 0x00 };
	int dateLength;
	int nameLength = list[contactIndex][0];
	int phoneLength = list[contactIndex][nameLength];
	int position = nameLength + phoneLength;             //индекс с которого можно вносить другие данные
	int newLength;
	//================================================================================================
	
	gets_s(buffer, sizeof(buffer) / sizeof(buffer[0]));  //Ввод даты.
	dateLength = strlen(buffer) + 2;
	newLength = nameLength + phoneLength + dateLength;   //Новый размер блока памяти

	tempList[contactIndex] = realloc(list[contactIndex], sizeof(uchar) * (newLength));
	if (tempList[contactIndex] == NULL)
	{
		printf_s("Memory allocation falied!");
		return tempList;
	}

	list[contactIndex][position] = dateLength;                           //Записать длину даты
	strcpy_s(&list[contactIndex][position + 1], dateLength - 1, buffer); //запись даты

	return tempList;
}
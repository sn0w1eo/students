/*/——————————————————————————————————————————————\
 |                                                |
 | Функции выводят в stdout информацию хранящуюся |
 | в определённых участках памяти                 |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"

//Синоним к unsigned char.
typedef unsigned char uchar;

//Отобразить имя.
void DisplayName(uchar** list, int contactIndex)
{
	//С list[x][1] всегда начинается имя.
	printf_s("%s", &list[contactIndex][1]);
}

//Отобразить номер телефона.
void DisplayPhoneNumber(uchar** list, int contactIndex)
{
	int position = list[contactIndex][0];                //Взять длину имени и начать вывод с адреса
	printf_s("%s", &list[contactIndex][position + 1]);   //ячейки сдвинутой на длину имени + 1.
}

//Отобразить дату.
void DisplayDate(uchar** list, int contactIndex)
{
	int position = list[contactIndex][0];                //Взять длину имени и прибавить к ней
	position = position + list[contactIndex][position];  //длину номера телефона взятой аналогичным способом.
	printf_s("%s", &list[contactIndex][position + 1]);   //После начать вывод с адреса ячейки сдвинутой на
	                                                     //полученное число. 
}

//Считать общий размер основного блока памяти.
int GetListSize(uchar** list)
{
	return ((int*)list[0])[0];
}

//Функция только для разработчика :D
void DisplayAll(uchar** list)
{
	int size = ((int*)list[0])[0];
	int nameLength;
	int phoneLength;
	int dateLength;

	for (int i = 1; i < size; i++)
	{
		if (list[i] != NULL)
		{
			nameLength = list[i][0];//там сидит инфа о длине номера
			phoneLength = list[i][nameLength];
			dateLength = nameLength + phoneLength;
			printf_s("name length  %d\nname is %s\nphone number: %s\nlength of phone number: %d\n"
				"date is %s\ndate length %d\n",
				list[i][0], &list[i][1], &list[i][nameLength + 1], list[i][nameLength], &list[i][dateLength + 1], list[i][dateLength]);
		}
	}
}
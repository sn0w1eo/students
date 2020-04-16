#include "stdio.h"
#include "windows.h"

#include "mydll.h"

#define WIDTH		70 //ширина рамки
#define HEIGHT		10 //высота рамки

#define WHITE		0x07 //белый цвет
#define LIGHTBLUE	0x0B //голубой цвет


//отрисовка рамки
__declspec(dllexport) void f1()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LIGHTBLUE);
	int x = 0;
	int y = 0;
	for (int y = 0; y <= HEIGHT; y++)
	{
		for (int x = 0; x <= WIDTH; x++)
		{
			if (y == 0)
			{
				if (x == 0)
				{
					printf("\xDA");
				}
				else
				{
					printf("\xC4");
				}
				if (x == WIDTH)
				{
					printf("\xBF\n");
				}
			}
			if (y > 0 && y != HEIGHT && x == 0)
			{
				printf("\xB3");
			}
			else if (x == WIDTH && y != HEIGHT && y > 0)
			{
				printf(" \xB3\n");
			}
			else
			{
				if (y != 0 && y != HEIGHT)
				{

					printf(" ");
				}
			}
			if (y == HEIGHT)
			{
				if (x == 0)
				{
					printf("\xC0");
				}
				else
				{
					printf("\xC4");
				}
				if (x == WIDTH)
				{
					printf("\xD9");
				}
			}

		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
}

//функция по дате рождения определяет твой знак зодиака
__declspec(dllexport) void f2()
{	
	int month, day;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = 1;
    cursorPosition.Y = 1;
	system("chcp 1251>nul");
	SetConsoleCursorPosition(console, cursorPosition);
	printf("Привет! Введи дату своего рождения, чтобы узнать свой знак зодиака.");
	cursorPosition.X = 1;
	cursorPosition.Y = 2;
	SetConsoleCursorPosition(console, cursorPosition);
	printf("Введи номер месяца");
	cursorPosition.X = 1;
	cursorPosition.Y = 3;
	SetConsoleCursorPosition(console, cursorPosition);
	scanf_s("%d", &month);
	cursorPosition.X = 1;
	cursorPosition.Y = 4;
	SetConsoleCursorPosition(console, cursorPosition);
	printf("Введи число");
	cursorPosition.X = 1;
	cursorPosition.Y = 5;
	SetConsoleCursorPosition(console, cursorPosition);
	scanf_s("%d", &day);
	cursorPosition.X = 1;
	cursorPosition.Y = 6;
	SetConsoleCursorPosition(console, cursorPosition);
	if (month == 3 && day >= 21 || month == 4 && day <= 20)
	{
		printf("Овен");
	}
	else if (month == 4 && day >= 21 || month == 5 && day <= 21)
	{
		printf("Телец");
	}
	else if (month == 5 && day >= 22 || month == 6 && day <= 21)
	{
		printf("Близнецы");
	}
	else if (month == 6 && day >= 22 || month == 7 && day <= 22)
	{
		printf("Рак");
	}
	else if (month == 7 && day >= 23 || month == 8 && day <= 23)
	{
		printf("Лев");
	}
	else if (month == 8 && day >= 24 || month == 9 && day <= 23)
	{
		printf("Дева");
	}
	else if (month == 9 && day >= 24 || month == 10 && day <= 23)
	{
		printf("Весы");
	}
	else if (month == 10 && day >= 24 || month == 11 && day <= 22)
	{
		printf("Скорпион");
	}
	else if (month == 11 && day >= 23 || month == 12 && day <= 21)
	{
		printf("Стрелец");
	}
	else if (month == 12 && day >= 22 || month == 1 && day <= 20)
	{
		printf("Стрелец");
	}
	else if (month == 1 && day >= 21 || month == 2 && day <= 19)
	{
		printf("Козерог");
	}
	else if (month == 2 && day >= 20 || month == 3 && day <= 20)
	{
		printf("Рыбы");
	}
	else
	{
		printf("Ты кто???");
	}
}

//функция определяет год по восточному календарю
__declspec(dllexport) void f3()
{
	int year, check;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 1;
	cursorPosition.Y = 7;
	SetConsoleCursorPosition(console, cursorPosition);
	printf("В каком году ты родился?");
	cursorPosition.X = 1;
	cursorPosition.Y = 8;
	SetConsoleCursorPosition(console, cursorPosition);
	
	scanf_s("%d", &year);
	cursorPosition.X = 1;
	cursorPosition.Y = 9;
	SetConsoleCursorPosition(console, cursorPosition);
	check = year % 12;
	switch (check)
	{
	case 0:
		printf("Год обезьяны");
		break;
	case 1:
		printf("Год петуха");
		break;
	case 2:
		printf("Год собаки");
		break;
	case 3:
		printf("Год свиньи");
		break;
	case 4:
		printf("Год крысы");
		break;
	case 5:
		printf("Год быка");
		break;
	case 6:
		printf("Год тигра");
		break;
	case 7:
		printf("Год кролика");
		break;
	case 8:
		printf("Год дракона");
		break;
	case 9:
		printf("Год змеи");
		break;
	case 10:
		printf("Год лошади");
		break;
	case 11:
		printf("Год овцы");
		break;

	default:
		printf("?");
		break;
	}
	cursorPosition.X = 1;
	cursorPosition.Y = 13;
	SetConsoleCursorPosition(console, cursorPosition);


}
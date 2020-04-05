#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "windows.h"
#include "time.h"
#include "conio.h"

typedef enum
{
	#define UP 0xE048
	#define DOWN 0xE050
	#define LEFT  0xE04B
	#define RIGHT 0xE04D
	#define ESC 0x1B
}eDirect;//перечислим тип для возможных вариантов движения *

eDirect dir;

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void setPosition(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void begin() // ввод данных
{
	char firstName, lastName, nickName, fullName;
	int blocks, steps;
	printf_s("FirstName: ");
	scanf_s("%s", &firstName);
	printf_s("LastName: ");
	scanf_s("%s", &lastName);
	printf_s("NickName: ");
	scanf_s("%s", &nickName);
	printf_s("\n Welcome:%s, %s, %s !\n", firstName, lastName, nickName);
	printf_s("Blocks: ");
	scanf_s("%d", &blocks);
	printf_s("Steps: ");
	scanf_s("%d", &steps);
}

void input()//функция, которая контролирует все нажатия пользователя
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 1:
			dir = LEFT;
			break;
		case 2:
			dir = RIGHT;
			break;
		case 3:
			dir = UP;
			break;
		case 4:
			dir = DOWN;
			break;

		}
	}

}

void Draw()//фунция отрисовывает консольную графику
{
	system("cls"); //очищаем экран
	setColor(5);
	int x = 0, y = 0;
	for (int y = 0; y <= 30; y++)
	{
		for (int x = 0; x <= 50; x++)
		{
			if (y == 0) {
				if (x == 0){
					printf_s("\xDA");
				}
				else{
					printf_s("\xC4");
				}
				if (x == 50){
					printf_s("\xBF\n");
				}
			}
			if (y > 0 && y != 30 && x == 0){
				printf_s("\xB3");
			}
			else if (x == 50 && y != 30 && y > 0){
				printf_s(" \xB3\n");
			}
			else{
				if (y != 0 && y != 30){
					printf_s(" ");
				}
			}
			if (y == 30){
				if (x == 0){
					printf_s("\xC0");
				}
				else{
					printf_s("\xC4");
				}
				if (x == 50){
					printf_s("\xD9");
				}
			}

		}
	}
	setColor(7);
}



void rand(int blocks, int arr[30][50]) //заполняем рандомными # и @
{
	for (int i = 0; i < blocks; i++)
	{

		int x = 1 + rand() % (30 - 1);
		int y = 1 + rand() % (50 - 1);
		arr[x][y] = '#';

	}
	for (int i = 0; i < 1; i++)
	{

		int x = 1 + rand() % (30 - 1);
		int y = 1 + rand() % (50 - 1);
		arr[x][y] = '@';

	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (arr[i][j] != '#' && arr[i][j] != '@' && arr[i][j] != '*')
			{
				arr[i][j] = ' ';
			}
		}
	}
}






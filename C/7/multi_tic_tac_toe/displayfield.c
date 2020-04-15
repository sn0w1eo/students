#include "stdio.h"                 
#include "windows.h"          

//этот файл использует функции с другого исходного файла
#include "displayfield.h"    
#include "engine.h"

//изобразить игровое поле
void DisplayGameField(unsigned char krissKross[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (krissKross[i][j] == '*')
			{
				DrawBlank(j * 10 + 15, i * 6 + 5);
			}
			else if (krissKross[i][j] == 'X')
			{
				DrawKriss(j * 10 + 15, i * 6 + 5);
			}
			else DrawKross(j * 10 + 15, i * 6 + 5);
		}
	}
}
//нарисовать крестик
void DrawKriss(int x, int y)
{
	SetColor(12);
	for (int i = 0; i < 3; i++)
	{
		Sleep(25);
		for (int j = 0; j < 3; j++)
		{
			SetConsoleCursor(j + x, i + y);
			if (i == 0 && j == 1)
			{
				printf_s(" ");
			}
			else if (i == 1 && j == 0 || i == 1 && j == 2)
			{
				printf_s(" ");
			}
			else if (i == 2 && j == 1)
			{
				printf_s(" ");
			}
			else printf_s("*");
		}
		printf_s("\n");
	}

}

//нарисовать нолик
void DrawKross(int x, int y)
{
	SetColor(9);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Sleep(15);
			SetConsoleCursor(j + x, i + y);
			if (i == 1 && j == 1)
			{
				printf_s(" ");
			}
			else printf_s("*");
		}
		printf_s("\n");
	}
}

//нарисовать пробел
void DrawBlank(int x, int y)
{
	SetColor(15);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			SetConsoleCursor(j + x, i + y);
			printf_s("\xB0");
		}
	}
}

//нарисовать рамку
// 179	B3	10110011	-	│
// 197	C5	11000101	-	┼
// 196	C4	11000100	-	─
void DisplayFrame()
{
	SetColor(2);
	//вертикальная линия 1
	for (int i = 0; i < 21; i++)
	{
		SetConsoleCursor(21, i + 2);
		printf_s("%c", '\xB3');
	}
	//вертикальная линия 2
	for (int i = 0; i < 21; i++)
	{
		SetConsoleCursor(31, i + 2);
		printf_s("%c", '\xB3');
	}

	//горизонтальная линия 1	
	for (int i = 0; i < 33; i++)
	{
		SetConsoleCursor(i + 10, 9);
		printf_s("%c", '\xC4');
		if (i == 11 || i == 21)
		{
			SetConsoleCursor(i + 10, 9);
			printf_s("%c", '\xC5');
		}
	}
	//горизонтальная линия 2
	for (int i = 0; i < 33; i++)
	{
		SetConsoleCursor(i + 10, 15);
		printf_s("%c", '\xC4');
		if (i == 11 || i == 21)
		{
			SetConsoleCursor(i + 10, 15);
			printf_s("%c", '\xC5');
		}
	}
}

//отобразить горячие клавиши. 
void ShowHotkeys()
{
	SetColor(13);
	SetConsoleCursor(50, 2);
	printf_s("Hotkeys for setting marker:");

	//закрасить Q W E
	SetColor(0XEF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 51, j + 5);
			puts(" ");
		}
	}
	//вывести Q W E
	SetColor(10);
	SetConsoleCursor(52, 6);
	printf_s("Q");
	SetConsoleCursor(59, 6);
	printf_s("W");
	SetConsoleCursor(66, 6);
	printf_s("E");

	//закрасить A S D
	SetColor(0XAF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 55, j + 9);
			puts(" ");
		}
	}
	//вывести A S D
	SetColor(11);
	SetConsoleCursor(56, 10);
	printf_s("A");
	SetConsoleCursor(63, 10);
	printf_s("S");
	SetConsoleCursor(70, 10);
	printf_s("D");

	//закрасить Z X C
	SetColor(0XBF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 58, j + 13);
			puts(" ");
		}
	}
	//вывести Z X C
	SetColor(13);
	SetConsoleCursor(59, 14);
	printf_s("Z");
	SetConsoleCursor(66, 14);
	printf_s("X");
	SetConsoleCursor(73, 14);
	printf_s("C");
}

//установить цвет
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

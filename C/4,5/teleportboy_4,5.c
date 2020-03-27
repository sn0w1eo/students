#include "stdio.h"
#include "windows.h"
#define UP 0x4800
#define LEFT 0x4B00
#define RIGHT 0x4D00
#define DOWN 0x5000
#define ESC 0x1B
//настройка границ
#define TOPLINE 0 //координата верхней границы по игреку
#define BOTTOMLINE 25 //координата нижней границы по игреку
#define LEFTBORDER 0 //координата левой границы по иксу
#define RIGHTBORDER 80//координата правой границы по иксу

//изменить цвет; диапазон 48 — 63
void SetColor(int colorNumber)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber - 48);
}
//отобразить прогресс бар
void DisplayBar()
{	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = BOTTOMLINE+1;
	//смена цвета
	SetColor(61);
	for (int abscissaX = LEFTBORDER; abscissaX <= RIGHTBORDER; abscissaX++)
	{
		//скорость прогресс бара
		Sleep(15);
		cursorPosition.X = abscissaX;
		for (int j = 65; j < 123; j++)
		{			
			if (j > 90 && j < 97) j += 6;
			SetConsoleCursorPosition(console, cursorPosition);
			printf_s("%c", j);
		}
		//заменить последний символ после перебора на 219
		SetConsoleCursorPosition(console, cursorPosition);
		putchar(219);
	}
}
//отобразить горячию клавишу выхода из программы
void DisplayHotKey()
{	
	//куда выводить и координаты соответственно 
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = BOTTOMLINE+1;
	//смена цвета
	SetColor(62);
	SetConsoleCursorPosition(console, cursorPosition);
	puts("Press ESC to exit . . .");	
}
//визуально отобразить границы
int DisplayFrame()
{
	if (TOPLINE > BOTTOMLINE || LEFTBORDER > RIGHTBORDER)
	{
		SetColor(60);
		puts("INCORRECTLY SIZED BOUNDARY SIZES !!!");
		return 0;
	}
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	//нарисовать верхнюю границу
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = TOPLINE;
	for (int i = 0; i <=RIGHTBORDER-LEFTBORDER; i++)
	{
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("*");
		cursorPosition.X++;
	}
	//нарисовать левую границу
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = TOPLINE;
	for (int i = 0; i <= BOTTOMLINE - TOPLINE; i++)
	{
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("*");
		cursorPosition.Y++;
	}
	//нарисовать правую границу
	cursorPosition.X =  RIGHTBORDER;
	cursorPosition.Y = TOPLINE;
	for (int i = 0; i <= BOTTOMLINE-TOPLINE; i++)
	{
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("*");
		cursorPosition.Y++;
	}
	//нарисовать нижнюю границу
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = BOTTOMLINE;
	for (int i = 0; i <= RIGHTBORDER - LEFTBORDER; i++)
	{
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("*");
		cursorPosition.X++;
	}
	return 0;
}
int main()
{	
	int key = 0;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = LEFTBORDER;
	cursorPosition.Y = TOPLINE;	
	DisplayFrame();	
	DisplayHotKey();
	SetConsoleCursorPosition(console, cursorPosition);	
	while (key != ESC)
	{		
		key = getch();
		if (key == 0 || key == 0xE0)
		{
			key = getch() << 8;
		}
		//если пользователь ввёл цифру, меняется цвет
		if (key >= 48 && key <= 57)
		{
			SetColor(key);
		}
		switch (key)
		{			
			//сдвиг вверх
		case UP:				
			cursorPosition.Y = cursorPosition.Y - 1;
			if (cursorPosition.Y < TOPLINE)
			{
				cursorPosition.Y = TOPLINE;
			}			
			SetConsoleCursorPosition(console, cursorPosition);			
			break;			
			//сдвиг влево
		case LEFT:
			cursorPosition.X = cursorPosition.X - 1;
			if (cursorPosition.X < LEFTBORDER)
			{
				cursorPosition.X = LEFTBORDER;
			}			
			SetConsoleCursorPosition(console, cursorPosition);
			break;			
			//сдвиг вправо
		case RIGHT:
			cursorPosition.X= cursorPosition.X+1;
			if (cursorPosition.X > RIGHTBORDER)
			{
				cursorPosition.X = RIGHTBORDER;
			}			
			SetConsoleCursorPosition(console, cursorPosition);
			break;			
			//сдвиг вниз
		case DOWN:			
			cursorPosition.Y = cursorPosition.Y + 1;
			if (cursorPosition.Y > BOTTOMLINE)
			{
				cursorPosition.Y = BOTTOMLINE;
			}			
			SetConsoleCursorPosition(console, cursorPosition);
			break;				
			//разрешить ввод латиницы	
		default:
			if (key >= 60 && key <= 90 || key >= 97 && key <= 122)
			{				
				putchar(key);
				SetConsoleCursorPosition(console, cursorPosition);
			}
			break;
		}
	}
	DisplayBar();
	return 0;
}
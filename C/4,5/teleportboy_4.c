#include "stdio.h"
#include "windows.h"
#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ESC 27
//меняет цвет консоли; диапазон 48 — 63
void SetColor(int colorNumber)
{	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNumber-48);
}
//отобразить прогресс бар
void DisplayBar(int esc)
{
	int x = 0;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	
	cursorPosition.X = x;
	cursorPosition.Y = 25;	
	
	//смена цвета
	SetColor(61);
	
	for (x = 0; x <= 80; x++)
	{
		//сохранить номер клетки в переменную
		cursorPosition.X = x;
		for (int j = 65; j < 123; j++)
		{
			SetConsoleCursorPosition(console, cursorPosition);
			if (j > 90 && j < 97) j += 6;
			putchar(j);
			//управление скоростью прогресс бара
			Sleep(1);
		}
		//заменить последний символ после перебора на 219
		SetConsoleCursorPosition(console, cursorPosition);
		putchar(219);
	}
}
int main()
{		
	int abscissa = 0, ordinate = 0, key=0;
	
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);	
	COORD cursorPos;

	cursorPos.X = abscissa;
	cursorPos.Y = 25;
	// вывод цветного сообщения
	SetColor(62);
	SetConsoleCursorPosition(console, cursorPos);
	puts( "Press ESC to exit . . .");
	cursorPos.Y = 0;
	
	while (key!=ESC)
	{		
		SetConsoleCursorPosition(console, cursorPos);
		key = getch();	
		//если пользователь ввёл цифру, меняется цвет
		if (key >= 48 && key <= 57)
		{
			SetColor(key);
		}		
		switch (key)
		{
			//сдвиг вверх
		case UP:
			cursorPos.X = abscissa;
			ordinate = ordinate - 1;
			if (ordinate<0)
			{
				ordinate = 0;
			}
			cursorPos.Y = ordinate;		
			SetConsoleCursorPosition(console, cursorPos);
			break;
			//сдвиг влево
		case LEFT:
			abscissa = abscissa - 1;
			if (abscissa<0)
			{
				abscissa = 0;
			}
			cursorPos.X = abscissa;
			cursorPos.Y = ordinate;		
			SetConsoleCursorPosition(console, cursorPos);
			break;
			//сдвиг вправо
		case RIGHT:
			abscissa += 1;
			if (abscissa>85)
			{
				abscissa = 85;
			}
			cursorPos.X = abscissa;
			cursorPos.Y = ordinate;		
			SetConsoleCursorPosition(console, cursorPos);			
			break;
			//сдвиг вниз
		case DOWN:			
			cursorPos.X = abscissa;
			ordinate +=1;
			if (ordinate>25)
			{
				ordinate = 25;
			}
			cursorPos.Y = ordinate;
			SetConsoleCursorPosition(console, cursorPos);		
			break;
		//разрешить ввод латиницы	
		default:
			if (key >= 60 && key <= 90 || key >= 97 && key <= 122)
			{
				putchar(key);							
			}		
			break;
		}		
	}
	DisplayBar(key);
}
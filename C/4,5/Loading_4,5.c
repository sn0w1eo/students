#include "stdio.h"
#include "windows.h"
#include "conio.h"

#define RIGHT 0x4D00
#define LEFT 0x4B00
#define UP 0x4800
#define DOWN 0x5000
#define ESC 0x1B

#define GO(x,y){COORD coordinates={x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);}
#define SET_COLOR(color){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);}


int main()
{
	int abscissa = 0, ordinate = 0, push, abscissaMax = 79, ordinateMax = 24;
	GO(0, 24)
	SET_COLOR(6)
	printf("Press ESC to exit... ");
	GO(abscissa, ordinate)
		do {
			push = _getch();
			if (push == 0 || push == 0xE0)
			{
				push = _getch() << 8;
			}

			// letters
			if (push >= 'A' && push <= 'z') 
			{ 
				printf("%c\b", push); 
			}

			// MOVE →
			if (push == RIGHT && abscissa != abscissaMax) 
			{ 
				abscissa++; GO(abscissa, ordinate)
			}

			// MOVE ←
			if (push == LEFT && abscissa != 0)
			{ 
				abscissa--; GO(abscissa, ordinate)
			}

			// MOVE ↑
			if (push == UP && ordinate != 0) 
			{ 
				ordinate--; GO(abscissa, ordinate) 
			}

			// MOVE ↓
			if (push == DOWN && ordinate != ordinateMax)
			{
				ordinate++; GO(abscissa, ordinate) 
			}

			//  color 
			if (push >= '0' && push <= '9')
			{
				SET_COLOR(push - '0' + 6);
				continue;
			}

			if (push == ESC)
			{
				GO(0, 24)
				SET_COLOR(14)
				for (int i = 0; i <= 80; i++)
				{
					int dec = 50;
					while (dec <= 100)
					{
					    Sleep(2);
						GO(i, 24);
						printf("%c\b", dec);
						dec++;
						printf("Ы\b");
					}
				}
		    return;
			}
		} while (1);
}
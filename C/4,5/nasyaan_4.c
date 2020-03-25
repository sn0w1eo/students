#include "windows.h"
#include "stdio.h"
#define ESC 0x1B
#define RIGHT 0x4D00
#define DOWN 0x5000
#define LEFT 0x4B00
#define UP 0x4800

#define GO(x,y){COORD coordinates={x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);}
#define SET_COLOR(color){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);}



int main()
{

	int x = 0, y = 0, maxY = 29, maxX = 118;
	int push;
	GO(0, 29)
		printf("Press ESC to exit...");
	GO(x, y)
	do {

		push = getch();
		if (push == 0 || push == 0xE0)
		{
			push = getch() << 8;
		}
		if (push >= 'A' && push <= 'z')
		{
			printf("%c\b", push);
		}
		if (push == RIGHT)
		{
			if (x != maxX)
			{
				x++; GO(x, y)
			}
		}
		else if (push == DOWN)
		{
			if (y != maxY)
			{
				y++; GO(x, y)
			}
		}
		else if (push == UP)
		{
			if (y != 0)
			{
				y--; GO(x, y)
			}
		}
		else if (push == LEFT)
		{
			if (x != 0)
			{
				x--; GO(x, y)
			}

		}
			if (push == '1')
			{
				SET_COLOR(0x2)
			}
			else if (push == '2')
			{
				SET_COLOR(0x3)
			}
			else if (push == '3')
			{
				SET_COLOR(0x4)
			}
			else if (push == '4')
			{
				SET_COLOR(0x5)
			}
			else if (push == '5')
			{
				SET_COLOR(0x6)
			}
			else if (push == '6')
			{
				SET_COLOR(0x7)
			}
			else if (push == '7')
			{
				SET_COLOR(0x8)
			}
			else if (push == '8')
			{
				SET_COLOR(0x9)
			}
			else if (push == '9')
			{
				SET_COLOR(0xC)
			}
			if (push == ESC)
			{
				int sym = 58;//{:}
				for (int i = 0; i <= 80;i++)
				{
					int sym = 58;
					while (sym <= 122) //{;}
					{
						SET_COLOR(0xb)
						GO(i, 29);
						printf("%c\b", sym);
						sym++;
						printf("\xDB\b");

					}
				}
			}

	} while (push != ESC);
 return 0;
}
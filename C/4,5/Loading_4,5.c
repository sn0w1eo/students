#include "stdio.h"
#include "windows.h"
#include "conio.h"
// Scan code
#define RIGHT 0x4D00
#define LEFT 0x4B00
#define UP 0x4800
#define DOWN 0x5000
#define ESC 0x1B
// Сoordinates(x,y)
#define GO(x,y){COORD coordinates={x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);}
// Colors
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
			if (push >= 'A' && push <= 'z') { printf("%c\b", push); }
			// MOVE →
			if (push == RIGHT && abscissa != abscissaMax) { abscissa++; GO(abscissa, ordinate) }
			// MOVE ←
			if (push == LEFT && abscissa != 0) { abscissa--; GO(abscissa, ordinate) }
			// MOVE ↑
			if (push == UP && ordinate != 0) { ordinate--; GO(abscissa, ordinate) }
			// MOVE ↓
			if (push == DOWN && ordinate != ordinateMax) { ordinate++; GO(abscissa, ordinate) }
			// Change color (Blue)
			if (push == '1') { SET_COLOR(1) }
			// Change color (Green)
			if (push == '2') { SET_COLOR(2) }
			// Change color (Cyan)
			if (push == '3') { SET_COLOR(3) }
			// Change color (Red)
			if (push == '4') { SET_COLOR(4) }
			// Change color (Magenta )
			if (push == '5') { SET_COLOR(5) }
			// Change color (Brown)
			if (push == '6') { SET_COLOR(6) }
			// Change color (LightGray)
			if (push == '7') { SET_COLOR(7) }
			// Change color (DarkGray)
			if (push == '8') { SET_COLOR(8) }
			// Change color (LightBlue)
			if (push == '9') { SET_COLOR(9) }
			// Change color (LightGreen)
			if (push == '0') { SET_COLOR(10) }
			if (push == ESC)
			{
				GO(0, 24)
					SET_COLOR(14)
					for (int i = 0; i <= 80; i++)
					{
						int dec = 50;
						while (dec <= 100)
						{
							GO(i, 24);
							printf("%c\b", dec);
							dec++;
							printf("Ы\b");
						}
					}
			}
		} while (push != ESC);
}
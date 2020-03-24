#include "windows.h"
#include "stdio.h"
#include "stdlib.h"


#define setBlue case 0x31:SET_COLOR(0x1) break;
#define setGreen case 0x32: SET_COLOR(0x2) break;
#define setGoluboi case 0x33:SET_COLOR(0x3) break;
#define setRed case 0x34: SET_COLOR(0x4) break;
#define setLilac case 0x35:SET_COLOR(0x5) break;
#define setYellow case 0x36:SET_COLOR(0x6) break;
#define setWhite case 0x37:SET_COLOR(0x7) break;
#define setLightBlue case 0x38:SET_COLOR(0x9) break;
#define setLightLilac case 0x39:SET_COLOR(0xd) break;
#define RIGHT 0x4D00
#define LEFT 0x4B00
#define UP 0x4800
#define DOWN 0x5000
#define ESC 0x1B
#define GO(x,y){COORD coordinates={x,y}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);}
#define SET_COLOR(color){SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color);}



int main() 
{
	system("chcp 866>nul");
	int x = 0, y = 0, xMax = 121,yMax=30;
	int push;
	GO(0, 29)
		puts("Press ESC to exit...");
	GO(x,y)
	do {

		push = getch();
		if (push == 0 || push == 0xE0) 
		{
			push = getch()<<8;
		}
		if (push >= 'A' && push <= 'z') { printf("%c\b", push); }
		switch (push)
		{
		case RIGHT: if(x!=xMax) x++; GO(x, y) break;
		case LEFT: if(x!=0) x--; GO(x, y) break;
		case UP: if(y!=0) y--; GO(x, y) break;
		case DOWN: if(y!=yMax) y++; GO(x, y) break;
		setRed
		setGreen
		setBlue
		setLightBlue
		setYellow
		setWhite
		setLilac
		setLightLilac
		setGoluboi
		}
		
		if (push == ESC) 
		{
			GO(0,29)
				SET_COLOR(0x8)
			printf("ллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллллл");
				
				for (int i = 0; i <= 110;i++) 
				{
					int dec = 58;
					while (dec <= 122) 
					{
						SET_COLOR(0xa)
						GO(i, 29);
						printf("%c\b", dec);
						dec++;
						printf("\xDB\b");
						
					}
					if (i == 110) { printf("\nComplete 100%%....\n\n"); }
				}
				
		}
	} while (push != ESC);
	
	return 0;
}
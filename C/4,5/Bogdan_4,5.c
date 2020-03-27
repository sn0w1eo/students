#include "windows.h"
#include "stdio.h"


#define ESC 0x1B
#define LEFT 0x4B00
#define RIGHT 0x4D00
#define UP 0x4800
#define DOWN 0x5000
//смена позиции по консоли
void position(int x, int y) {
COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}
//смена цвета
void color(int ColorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}

int main() {
	int vvod;
	int x = 0, y = 0, xMax = 78, yMax = 22;

	position(0, 23);
	color(12);
	printf("Press ESC to exit");
	position(0, 0);
	do 
	{
		
			vvod = _getch();
			
			if (vvod >= 'A' && vvod <= 'z') {
				printf("%c\b", vvod);
			}
			
			if (vvod == 0 || vvod == 0xE0) vvod = _getch() << 8;
			
			switch (vvod)
			{
			case LEFT: if (x != 0)  --x; position(x, y); break; 
			case RIGHT: if (x != xMax)  ++x; position(x, y); break; 
			case UP: if (y != 0)  --y; position(x, y); break; 
			case DOWN: if (y != yMax) ++y; position(x, y); break;
				case '1': color (7); break;
				case '2': color(8); break;
				case '3': color(9); break;
				case '4': color(10); break;
				case '5': color(11); break;
				case '6': color(12); break;
				case '7': color(13); break;
				case '8': color(14); break;
				case '9': color(15); break;
				}
				
		if (vvod==ESC){
			position(0, 24);
			color(12);
			for (int x = 0; x <= xMax; x++) {
				for (int Progress = 65;Progress<=122;Progress++) {
					printf("%c\b", Progress);
					if (Progress==122)printf("%c\b", 219);
				}
				position(x,24);
			}
		
		
		}

	} while (vvod!=ESC);
}
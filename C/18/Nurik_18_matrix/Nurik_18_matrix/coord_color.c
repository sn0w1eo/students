#include "coord_color.h"

void set_coord_and_color(int x, int y, int color)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
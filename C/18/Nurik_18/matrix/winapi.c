#include "winapi.h"

#define _CRT_RAND_S

void maximize_window() {
	CONSOLE_SCREEN_BUFFER_INFOEX info = { 0 };
	HANDLE hConsole = NULL;

	// maximize window
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
}

int get_height() {
	CONSOLE_SCREEN_BUFFER_INFOEX info = { 0 };
	HANDLE hConsole = NULL;

	// print width/height of this window in terms of columns and rows
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	info.cbSize = sizeof(info);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	return info.srWindow.Bottom + 1;
}

int get_width() {
	CONSOLE_SCREEN_BUFFER_INFOEX info = { 0 };
	HANDLE hConsole = NULL;

	// print width/height of this window in terms of columns and rows
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	info.cbSize = sizeof(info);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	return info.srWindow.Right + 1;
}

void show_cursor(bool show) {
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

	structCursorInfo.bVisible = show;

	SetConsoleCursorInfo(hConsoleOutput,
		&structCursorInfo);
}

int random(int min, int max) {
	unsigned int number;
	int num = max - min;
	rand_s(&number);
	return min + (int)((float)number /
		((float)UINT_MAX + 1) * num) + 0;
}

COORD rand_coordinate(int width, int height) {
	COORD rand_coord;
	rand_coord.X = random(0, width);
	rand_coord.Y = random(0, height);
	return rand_coord;
}

void set_coord(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void set_bkcolor(int color, int x, int y)
{
	COORD cursor_position = { 0 };
	cursor_position.X = x;
	cursor_position.Y = y;

	int a = 0;

	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		color, 1, cursor_position, &a);
}

void set_colors(int next_color, int prev_color, int x, node_t* list) {
	set_bkcolor(WHITE_BACKGROUND | GREEN_FOREGROUND, x, list->data);

	list = list->prev;
	set_bkcolor(BLACK_BACKGROUND | GREEN_FOREGROUND, x, list->data);
}

void sleep_time(int threads) {
	if (threads < 12) {
		Sleep(50 - (threads * 4));
	}
}
#include "win_api.h"


void show_cursor(bool show) {
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;

	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

	structCursorInfo.bVisible = show;

	SetConsoleCursorInfo(hConsoleOutput,
		&structCursorInfo);
}

void get_size_monitor(int* width, int* height) {
	CONSOLE_SCREEN_BUFFER_INFOEX info = { 0 };
	HANDLE hConsole = NULL;

	// maximize window
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	// print width/height of this window in terms of columns and rows
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	info.cbSize = sizeof(info);
	GetConsoleScreenBufferInfoEx(hConsole, &info);

	*width = info.srWindow.Right + 1;
	*height = info.srWindow.Bottom + 1;
}
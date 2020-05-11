#include "stdio.h"
#include "windows.h"

#include "visual.h"

//Отобразить клавиши управления.
void DisplayHotKeys()
{
	system("mode con cols=131 lines=45");
	SetConsoleCursor(85, 0);
	printf("Press A to add new contact.");
	SetConsoleCursor(85, 2);
	printf("Press U to update an contact.");
	SetConsoleCursor(85, 4);
	printf("Press D to delete an contact.");
	SetConsoleCursor(85, 6);
	printf("Press S to search.");
	SetConsoleCursor(85, 7);
	printf("You will get the amount of contacts.");
	SetConsoleCursor(85, 9);
	printf("Press R to display all contacts.");
	SetConsoleCursor(85, 11);
	printf("Press C to clean screen.");
	SetConsoleCursor(85, 13);
	printf("Press ESC to close programm.");
	SetConsoleCursor(0, 0);
}

//Установить курсор.
void SetConsoleCursor(int x, int y)
{
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
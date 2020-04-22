#include "stdio.h"
#include "windows.h"
#include "time.h"

#include "mydll.h"

//приветствие
__declspec(dllexport) void f1()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 13;
	cursorPosition.Y = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	SetConsoleCursorPosition(console, cursorPosition);

	printf_s(" Its \"Shoot dice!\" game\n");
	cursorPosition.Y = 2;
	SetConsoleCursorPosition(console, cursorPosition);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printf_s(" Press any key to shoot dice!");

	getch();
}

//нарисовать рамку
__declspec(dllexport) void f2()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 10;
	cursorPosition.Y = 2;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	SetConsoleCursorPosition(console, cursorPosition);

	//нарисовать горизонтальные линии
	for (int i = 0; i < 23; i++)
	{
		cursorPosition.X = i + 14;
		cursorPosition.Y = 4;

		SetConsoleCursorPosition(console, cursorPosition);
		if (i == 0) putchar('\xDA'); //┌

		printf_s("%c", '\xC4'); // ─
		if (i == 22) putchar('\xBF'); // ┐


		cursorPosition.Y = 18;
		SetConsoleCursorPosition(console, cursorPosition);
		if (i == 0) putchar('\xC0'); // └

		printf_s("%c", '\xC4');//  ─
		if (i == 22) putchar('\xD9'); //┘
	}
	//нарисовать вертикальные линии
	for (int i = 0; i < 13; i++)
	{
		cursorPosition.Y = i + 5;
		cursorPosition.X = 14;

		SetConsoleCursorPosition(console, cursorPosition);

		printf_s("%c", '\xB3'); // │

		cursorPosition.X = 37;
		SetConsoleCursorPosition(console, cursorPosition);

		printf_s("%c", '\xB3'); // │
	}
}


__declspec(dllexport) void f3()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	int random;
	char dice[3][3];

	while (getch() != 27)
	{
		//очистить экран
		srand(time(NULL));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				dice[i][j] = ' ';
			}
		}

		//зарандомить кубик
		random = 1 + rand() % 6;
		switch (random)
		{
			//кубик с числом 1
		case 1:
			dice[1][1] = '\xFD';
			break;
			//кубик с числом 2
		case 2:
			dice[0][0] = '\xFD';
			dice[2][2] = '\xFD';
			break;
			//кубик с числом 3

		case 3:
			dice[0][0] = '\xFD';
			dice[1][1] = '\xFD';
			dice[2][2] = '\xFD';
			break;
			//кубик с числом 4

		case 4:
			dice[0][0] = '\xFD';
			dice[0][2] = '\xFD';
			dice[2][0] = '\xFD';
			dice[2][2] = '\xFD';
			break;
			//кубик с числом 5

		case 5:
			dice[0][0] = '\xFD';
			dice[0][2] = '\xFD';
			dice[1][1] = '\xFD';
			dice[2][0] = '\xFD';
			dice[2][2] = '\xFD';
			break;

			//кубик с числом 6
		default:
			dice[0][0] = '\xFD';
			dice[0][2] = '\xFD';
			dice[1][0] = '\xFD';
			dice[1][2] = '\xFD';
			dice[2][0] = '\xFD';
			dice[2][2] = '\xFD';
			break;
		}
		//отобразить кубик
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cursorPosition.X = j * 8 + 17;
				cursorPosition.Y = i * 5 + 6;
				SetConsoleCursorPosition(console, cursorPosition);
				printf_s("%c", dice[i][j]);
			}
		}
	}
	printf("\n\n\n\n\n");
}
#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "windows.h"
#include "time.h"

#define RED			0x0C
#define LIGHTBLUE	0x0B
#define MAGENTA		0x0D
#define STR_LEN		40
#define UP_ARROW    0xE048
#define DOWN_ARROW  0xE050
#define LEFT_ARROW  0xE04B
#define RIGHT_ARROW 0xE04D
#define ESC_BTN     0x1B

void setPosition(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
/*прячем курсор*/
void hideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
/*рисуем рамку*/
void drawTable()
{
	setColor(MAGENTA);
	int x = 0;
	int y = 0;
	for (int y = 0; y <= 21; y++)
	{
		for (int x = 0; x <= 41; x++)
		{
			if (y == 0)
			{
				if (x == 0)
				{
					printf("\xDA");
				}
				else
				{
					printf("\xC4");
				}
				if (x == 41)
				{
					printf("\xBF\n");
				}
			}
			if (y > 0 && y != 21 && x == 0)
			{
				printf("\xB3");
			}
			else if (x == 41 && y != 21 && y > 0)
			{
				printf(" \xB3\n");
			}
			else
			{
				if (y != 0 && y != 21)
				{

					printf(" ");
				}
			}
			if (y == 21)
			{
				if (x == 0)
				{
					printf("\xC0");
				}
				else
				{
					printf("\xC4");
				}
				if (x == 41)
				{
					printf("\xD9");
				}
			}

		}
	}
	setColor(7);
}
/*выводим массив*/
void printArray(int Arr[][41])
{
	for (int i = 1; i < 21; i++)
	{
		for (int j = 1; j < 41; j++)
		{
			setPosition(j, i);
			if (Arr[i][j] == '#')
			{
				setColor(RED);
			}
			else if (Arr[i][j] == '*')
			{
				setColor(LIGHTBLUE);
			}
			else
			{
				setColor(7);
			}

			printf("%c ", Arr[i][j]);

		}
	}
}
/*находим рандомные координаты для # и @*/
void fillArray(int gameBlocks, int Arr[][41])
{
	for (int i = 0; i < gameBlocks; i++)
	{

		int a = 0 + rand() % 21;
		int b = 0 + rand() % 41;
		Arr[a][b] = '#';

	}
	for (int i = 0; i < 1; i++)
	{

		int a = 0 + rand() % 21;
		int b = 0 + rand() % 41;
		Arr[a][b] = '@';

	}
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (Arr[i][j] != '#' && Arr[i][j] != '@' && Arr[i][j] != '*')
			{
				Arr[i][j] = ' ';
			}
		}
	}
}
int main()
{

	char firstName[STR_LEN] = { 0x00 };
	char lastName[STR_LEN] = { 0x00 };
	char nickName[STR_LEN] = { 0x00 };
	char fullName[STR_LEN * 3] = { 0x00 };
	int Arr[21][41];
	int gameBlocks, gameSteps;

	/*меню ввода имени, блоков и шагов*/
	printf("firstName: ");
	scanf_s("%s", firstName, STR_LEN);

	printf("lastName: ");
	scanf_s("%s", lastName, STR_LEN);

	printf("nickName: ");
	scanf_s("%s", nickName, STR_LEN);

	strcat(fullName, firstName);
	strcat(fullName, " \"");
	strcat(fullName, nickName);
	strcat(fullName, "\" ");
	strcat(fullName, lastName);

	printf("Welcome: %s\n", fullName);

	printf("Blocks: ");
	scanf_s("%d", &gameBlocks);
	

	printf("Steps: ");
	scanf_s("%d", &gameSteps);
	
	int gameStepsStart = gameSteps;

	system("cls");

	srand(time(NULL));
	fillArray(gameBlocks, Arr);
	Arr[1][1] = '*';
	/*вызываем наши функции*/
	drawTable();
	printArray(Arr);

	int x = 1;
	int y = 1;
	while (1)
	{
		setPosition(0, 22);
		setColor(MAGENTA);
		printf("STEPS: ");
		setColor(7);
		printf("%d  ", gameSteps);
		hideCursor();
		unsigned int ch = getch();
		if (ch == 0xE0)
		{
			ch = ch << 8;
			ch = ch | getch();
		}
		if (gameSteps == 1)
		{
			setPosition(0, 21);
			setColor(RED);
			printf("\nYou`ve failed. Try ur luck next time.\n");
			return 0;
		}
		/*при нажатии на клавишу "вправо" делаем шаг, ставим * и след в виде . */
		if (ch == RIGHT_ARROW)
		{
			if (Arr[x][y + 1] == '@')
			{
				Arr[x][y + 1] = '*';
				Arr[x][y] = '.';
				printArray(Arr);
				printf("\n\n\nCongratulations! You`ve won! Steps:%d/%d\n", gameStepsStart - gameSteps, gameStepsStart);
				return 0;

			}
			else if (y != 40 && Arr[x][y + 1] != '#')
			{
				y++;
				gameSteps--;
				Arr[x][y] = '*';
				Arr[x][y - 1] = '.';
				printArray(Arr);
			}


		}
		/*шаг влево*/
		if (ch == LEFT_ARROW)
		{
			if (Arr[x][y - 1] == '@')
			{
				Arr[x][y - 1] = '*';
				Arr[x][y] = '.';
				printArray(Arr);
				printf("\n\n\nCongratulations! You`ve won! Steps:%d/%d\n", gameStepsStart - gameSteps, gameStepsStart);
				return 0;

			}
			else if (y > 1 && Arr[x][y - 1] != '#')
			{
				y--;
				gameSteps--;
				Arr[x][y] = '*';
				Arr[x][y + 1] = '.';
				printArray(Arr);
			}

		}
		/*шаг вниз*/
		if (ch == DOWN_ARROW)
		{
			if (Arr[x + 1][y] == '@')
			{
				Arr[x + 1][y] = '*';
				Arr[x][y] = '.';
				printArray(Arr);
				printf("\n\n\nCongratulations! You`ve won! Steps:%d/%d\n", gameStepsStart - gameSteps, gameStepsStart);
				return 0;

			}
			else if (x != 20 && Arr[x + 1][y] != '#')
			{
				x++;
				gameSteps--;
				Arr[x][y] = '*';
				Arr[x - 1][y] = '.';
				printArray(Arr);
			}

		}
		/*шаг вверх*/
		if (ch == UP_ARROW)
		{
			if (Arr[x - 1][y] == '@')
			{
				Arr[x - 1][y] = '*';
				Arr[x][y] = '.';
				printArray(Arr);
				printf("\n\n\nCongratulations! You`ve won! Steps:%d/%d\n", gameStepsStart - gameSteps, gameStepsStart);
				return 0;

			}
			else if (x > 1 && Arr[x - 1][y] != '#')
			{
				x--;
				gameSteps--;
				Arr[x][y] = '*';
				Arr[x + 1][y] = '.';
				printArray(Arr);
			}
		}
		/*при нажатии на escape выход из программы*/
		if (ch == ESC_BTN)
		{
			setPosition(0, 22);
			setColor(MAGENTA);
			printf("Ok buddy. Cya next time...");
			return 0;
		}

	}

}
#include "stdio.h"
#include "windows.h"
#include "time.h"
#include "math.h"
#define UP				0xE048
#define LEFT			0xE04B
#define RIGHT			0xE04D
#define DOWN            0xE050
#define ESC				0x1B
void MakeGameField(unsigned char array[22][42], int blocks);
int CheckBlock(unsigned char gameField[22][42], int row, int column, int key);
int CheckVictory(unsigned char gameField[22][42], int row, int column);
void DisplayGameField(unsigned char  array[22][42]);
void DisplayPathway(unsigned char  array[22][42]);

int main()
{
	int key = 0, row = 1, column = 1, stepsCount = 0, blocks = 0, winCheck, blockCheck;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 22;
	unsigned char gameField[22][42], firstName[20], lastName[20], nickName[20];

	//ввод имени
	printf_s("Name: ");
	gets(firstName);

	//ввод фамили€
	printf_s("lastName: ");
	gets(lastName);

	//ввод никнейма
	printf_s("nickNme: ");

	gets(nickName);
	printf_s("Welcomeeee: %s \"%s\" %s\n", firstName, nickName, lastName);

	//установка счетчика шагов	
	printf_s("Steps: ");
	scanf_s("%d", &stepsCount);

	//установка преп€тствий	
	printf_s("Blocks: ");
	scanf_s("%d", &blocks);

	system("cls"); 	//отчистить экран перед игрой

	//запуск игры . . .

	MakeGameField(gameField, blocks);
	DisplayGameField(gameField);
	DisplayPathway(gameField);

	do
	{
		//спр€тать каретку
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(console, &info);

		// проверка на неверно введЄнное ко-во шагов; конец игры при 0 оставшихс€ шагов
		if (stepsCount < 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cursorPosition.X = 0;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(console, cursorPosition);
			puts("You've failed. Try ur luck next time.");
			return 0;
		}
		//ввод 
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		//система управлени€
		switch (key)
		{
			//шаг впер™д
		case UP:
			row--;
			stepsCount--;
			if (row < 1)
			{
				stepsCount++; /// не измен€ть счетчик при попытках выхода за границы/столкновени€х с блоками
				row = 1;
			}

			//условие победы при входе в €чейку с символом '@'
			winCheck = CheckVictory(gameField, row, column);
			if (winCheck == 0) return 0;
			//проверка на блоки
			blockCheck = CheckBlock(gameField, row, column, key);
			if (blockCheck == 1)
			{
				row++;
				stepsCount++;
			}
			break;

			//шаг назад
		case DOWN:
			row++;
			stepsCount--;
			if (row > 20)
			{
				stepsCount++;
				row = 20;
			}

			winCheck = CheckVictory(gameField, row, column);
			if (winCheck == 0) return 0;

			blockCheck = CheckBlock(gameField, row, column, key);
			if (blockCheck == 1)
			{
				row--;
				stepsCount++;
			}
			break;

			//шаг влево
		case LEFT:
			column--;
			stepsCount--;
			if (column < 1)
			{
				stepsCount++;
				column = 1;
			}

			winCheck = CheckVictory(gameField, row, column);
			if (winCheck == 0) return 0;

			blockCheck = CheckBlock(gameField, row, column, key);
			if (blockCheck == 1)
			{
				column++;
				stepsCount++;
			}
			break;
			//шаг вправо
		case RIGHT:
			column++;
			stepsCount--;
			if (column > 40)
			{
				stepsCount++;
				column = 40;
			}

			winCheck = CheckVictory(gameField, row, column);
			if (winCheck == 0) return 0;

			blockCheck = CheckBlock(gameField, row, column, key);
			if (blockCheck == 1)
			{
				column--;
				stepsCount++;
			}
			break;
			//выйти из игры
		case ESC:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			SetConsoleCursorPosition(console, cursorPosition);
			puts("Ok buddy. Cya next time...");
			return 0;
		}
		//вывод шагов
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("Steps:%d     ", stepsCount);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	} while (!0); // :D
}
//инициализаци€ игры
void MakeGameField(unsigned char array[22][42], int blocks)
{
	srand(time(NULL));
	int row = 0, column = 0;
	//заполнение преп€тствий
	for (int i = 0; i < blocks; i++)
	{
		row = 0 + rand() % 21;
		column = 0 + rand() % 41;
		array[row][column] = '#';
	}
	//цель 
	for (int i = 0; i < 1; i++)
	{
		row = 1 + rand() % 21;
		column = 0 + rand() % 41;
		array[row][column] = '@';
	}
	//заполнение пробелов
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (array[i][j] == '#' || array[i][j] == '@')
			{
				continue;
			}
			else
			{
				array[i][j] = ' ';
			}
		}
	}
	//нарисовать рамку
	for (int i = 1; i < 22; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			array[0][j] = '\x0CD';
			array[21][j] = '\x0CD';
			array[0][41] = '\xBB';
			array[0][0] = '\xC9';
		}
		array[i][0] = '\x0BA';
		array[i][41] = '\x0BA';
		array[21][41] = '\xBC';
		array[21][0] = '\xC8';
	}
	array[1][1] = '*';
}


//проверка преп€тстви€ перед маркером и сердце игры
int CheckBlock(unsigned char gameField[22][42], int row, int column, int key)
{
	if (key == UP)
	{
		if (gameField[row][column] == '#')
		{
			gameField[++row][column] = '*';
			DisplayPathway(gameField);
			return 1;
		}
		else
		{
			gameField[row][column] = '*';
			DisplayGameField(gameField);
			DisplayPathway(gameField);
			return 0;
		}
	}
	if (key == DOWN)
	{
		if (gameField[row][column] == '#')
		{
			gameField[--row][column] = '*';
			DisplayPathway(gameField);
			return 1;
		}
		else
		{
			gameField[row][column] = '*';
			DisplayGameField(gameField);
			DisplayPathway(gameField);
			return 0;
		}
	}
	if (key == LEFT)
	{

		if (gameField[row][column] == '#')
		{
			gameField[row][++column] = '*';
			DisplayPathway(gameField);
			return 1;
		}
		else
		{
			gameField[row][column] = '*';
			DisplayGameField(gameField);
			DisplayPathway(gameField);
			return 0;
		}
	}
	if (key == RIGHT)
	{
		if (gameField[row][column] == '#')
		{
			gameField[row][--column] = '*';
			DisplayPathway(gameField);
			return 1;
		}
		else
		{
			gameField[row][column] = '*';
			DisplayGameField(gameField);
			DisplayPathway(gameField);
			return 0;
		}
	}
	return 0;
}
//проверка услови€ победы
int CheckVictory(unsigned char gameField[22][42], int row, int column)
{
	if (gameField[row][column] == '@')
	{
		gameField[row][column] = '*';
		DisplayGameField(gameField);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		puts("Congratulations! You've won!");
		return 0;
	}
	else return 1;
}
//вывод  игрового пол€ 
void DisplayGameField(unsigned char  array[22][42])
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			//по координате X выводить столбцы, а по Y - строки
			cursorPosition.X = j;
			cursorPosition.Y = i;
			SetConsoleCursorPosition(console, cursorPosition);

			//покраска и вывод элементов игрового пол§
			if (array[i][j] == '#')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				putchar('#');
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			}
			else if (array[i][j] == '*')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				putchar('*');
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
			}
			else printf_s("%c", array[i][j]);
		}
	}
	printf_s("\n");
}
//отоброжать пройденный путь
void DisplayPathway(unsigned char  array[22][42])
{
	for (int i = 0; i < 21; i++)
	{
		for (int j = 0; j < 41; j++)
		{
			if (array[i][j] == '*')
			{
				array[i][j] = '\xF9';
			}
		}
	}
}

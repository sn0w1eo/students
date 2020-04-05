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

	//���� �����
	printf_s("Name: ");
	gets(firstName);

	//���� �������
	printf_s("lastName: ");
	gets(lastName);

	//���� ��������
	printf_s("nickNme: ");

	gets(nickName);
	printf_s("Welcomeeee: %s \"%s\" %s\n", firstName, nickName, lastName);

	//��������� �������� �����	
	printf_s("Steps: ");
	scanf_s("%d", &stepsCount);

	//��������� �����������	
	printf_s("Blocks: ");
	scanf_s("%d", &blocks);

	system("cls"); 	//��������� ����� ����� �����

	//������ ���� . . .

	MakeGameField(gameField, blocks);
	DisplayGameField(gameField);
	DisplayPathway(gameField);

	do
	{
		//�������� �������
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(console, &info);

		// �������� �� ������� �������� ��-�� �����; ����� ���� ��� 0 ���������� �����
		if (stepsCount < 1)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cursorPosition.X = 0;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(console, cursorPosition);
			puts("You've failed. Try ur luck next time.");
			return 0;
		}
		//���� 
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		//������� ����������
		switch (key)
		{
			//��� �����
		case UP:
			row--;
			stepsCount--;
			if (row < 1)
			{
				stepsCount++; /// �� �������� ������� ��� �������� ������ �� �������/������������� � �������
				row = 1;
			}

			//������� ������ ��� ����� � ������ � �������� '@'
			winCheck = CheckVictory(gameField, row, column);
			if (winCheck == 0) return 0;
			//�������� �� �����
			blockCheck = CheckBlock(gameField, row, column, key);
			if (blockCheck == 1)
			{
				row++;
				stepsCount++;
			}
			break;

			//��� �����
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

			//��� �����
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
			//��� ������
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
			//����� �� ����
		case ESC:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			SetConsoleCursorPosition(console, cursorPosition);
			puts("Ok buddy. Cya next time...");
			return 0;
		}
		//����� �����
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		SetConsoleCursorPosition(console, cursorPosition);
		printf_s("Steps:%d     ", stepsCount);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	} while (!0); // :D
}
//������������� ����
void MakeGameField(unsigned char array[22][42], int blocks)
{
	srand(time(NULL));
	int row = 0, column = 0;
	//���������� �����������
	for (int i = 0; i < blocks; i++)
	{
		row = 0 + rand() % 21;
		column = 0 + rand() % 41;
		array[row][column] = '#';
	}
	//���� 
	for (int i = 0; i < 1; i++)
	{
		row = 1 + rand() % 21;
		column = 0 + rand() % 41;
		array[row][column] = '@';
	}
	//���������� ��������
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
	//���������� �����
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


//�������� ����������� ����� �������� � ������ ����
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
//�������� ������� ������
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
//�����  �������� ���� 
void DisplayGameField(unsigned char  array[22][42])
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 42; j++)
		{
			//�� ���������� X �������� �������, � �� Y - ������
			cursorPosition.X = j;
			cursorPosition.Y = i;
			SetConsoleCursorPosition(console, cursorPosition);

			//�������� � ����� ��������� �������� ���
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
//���������� ���������� ����
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

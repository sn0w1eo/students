#define _CRT_SECURE_NO_WARNINGS
#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "time.h"

#define GO(x, y) { COORD coordinates = { x,y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates); }

/*Set Color*/
#define COLOR(color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);}

/*Frame Drawing Macros*/

#define MIN_HEIGHT 0
#define MIN_WIDTH  0
#define MAX_HEIGHT 22
#define MAX_WIDTH  44

/*Control Macros*/

#define UP    0xE048
#define DOWN  0xE050
#define LEFT  0xE04B
#define RIGHT 0xE04D
#define ESC   0x1B


/*Read Nameÿ*/
void getName() 
{
	COLOR(0x0E);
	char name[3][15] = { "" };
	printf("Enter firstName: ");
	gets(name[0]);
	printf("Enter lastName:");
	gets(name[1]);
	printf("Enter your nickName:");
	gets(name[2]);
	printf("\n Welcome:%s \"%s\" %s !\n",name[0],name[2],name[1]);
	
	
}

/* Draw Dynamic Frame*/
void drawFrame()
{
	COLOR(0x0B);
	int x = 0, y = 0;
	for (x = MIN_HEIGHT; x <= MAX_HEIGHT; x++)
	{
		for (y = MIN_WIDTH; y <= MAX_WIDTH; y++)
		{
			if (x == MIN_HEIGHT)
			{
				if (y == MIN_WIDTH)
				{
					printf("\xDA");
				}
				if (y > MIN_WIDTH&& y < MAX_WIDTH)
				{
					printf("\xc4");
				}
				if (y == MAX_WIDTH)
				{
					printf("\xBF\n");
				}

			}

			else
			{
				if (x == MAX_HEIGHT)
				{

					if (y == MIN_WIDTH)
					{
						printf("\xC0");
					}
					if (y > MIN_WIDTH&& y < MAX_WIDTH)
					{
						printf("\xC4");
					}
					if (y == MAX_WIDTH)
					{
						printf("\xD9");
					}
				}

				if (x > MIN_HEIGHT&& x != MAX_HEIGHT && y == MIN_WIDTH)
				{
					printf("\xB3");
				}
				else if (y == MAX_WIDTH && x != MAX_HEIGHT && y != MIN_WIDTH)
				{
					printf("\xB3\n");
				}
				if (x != MIN_HEIGHT && x != MAX_HEIGHT && y != MIN_WIDTH && y != MAX_WIDTH)
				{
					
					putc(' ',stdout);
					
				}

			}
		}

	}
	COLOR(0x07);

}

/*Read Key*/
int readKey() {
	unsigned int ch = getch();
	if (ch == 0xE0) {
		ch = ch << 8;
		ch = ch | getch();
	}
	return ch;
}

/*Print Array*/
void drawField( char  array[MAX_HEIGHT-1][MAX_WIDTH-1])
{
	
	for (int i = 0; i < MAX_HEIGHT-2; i++)
	{
		for (int j = 0; j < MAX_WIDTH-2; j++)
		{
			int x1=i+1, x2=j+1;
			GO(x2, x1);
			if (array[i][j] == '#')
			{
				COLOR(12);
			}
			else if (array[i][j] == '*')
			{
				COLOR(11);
			}
			else if(array[i][j]=='@')
			{
				COLOR(15);
			}
			else 
			{
				COLOR(3);
			}

			printf("%c ", array[i][j]);
				
				
			
		}
	}
	
}

/*Array Filling*/
void makeField(char array[MAX_HEIGHT - 1][MAX_WIDTH - 1], int blocks)
{
	int X = 0, Y = 0;
	
	for (int i = 0; i < blocks; i++)
	{
		X = 1 + rand() % (MAX_HEIGHT - 1);
		Y = 1 + rand() % (MAX_WIDTH - 1);
		array[X][Y] = '#';
	}

	for (int i = 0; i < 1; i++)
	{
		X = 1 + rand() % (MAX_HEIGHT - 1);
		Y = 1 + rand() % (MAX_WIDTH - 1);
		array[X][Y] = '@';
	}
	
	for (int i = 0; i < MAX_HEIGHT-1; i++)
	{
		for (int j = 0; j < MAX_WIDTH-1; j++)
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
}

/*Hide Cursor*/
void hidecursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}

int main()
{
	int originalSteps, steps = 0, blocks = 0;
	SetConsoleCP(866);
	SetConsoleOutputCP(866);
	//getName();
	printf("Blocks:");
	scanf("%d", &blocks);
	printf("Steps:");                                           //Option block
	scanf("%d", &steps);
	originalSteps = steps;
	COLOR(0x07);
	system("cls");

	drawFrame();
	int key = 0;
	int x = 0, y = 0;
	srand(time(NULL));
	char gameField[MAX_HEIGHT - 1][MAX_WIDTH-1];      //Drawing block
	makeField(gameField, blocks);
	gameField[0][0] = '*';
	drawField(gameField);

	do
	{
		GO(1, MAX_HEIGHT+1);
		COLOR(0x0E)
		printf_s("\n\nSteps:%d    ", steps);
		hidecursor();
		if (steps < 1)
		{
			COLOR(12);
			puts("\n\nYou've failed. Try ur luck next time.");
			return 0;
		}
		key = readKey();

		if (key == ESC)
		{
			COLOR(11)			
			puts("\n\nOk buddy. Cya next time...");
			return 0;
		}

		switch (key)
		{
		case DOWN:

			if (gameField[x+1][y] == '@')
			{
				gameField[x + 1][y] = '*';
				gameField[x][y] = '\xF8';
				drawField(gameField);
				printf("\n\n\nCongratulations! You've won!	Steps: %d / %d\n", originalSteps - steps, originalSteps);
				return 0;
			}
			else if (x != MAX_HEIGHT-3 && gameField[x+1][y] != '#')
			{
				x++;
				steps--;
				gameField[x][y] = '*';
				gameField[x - 1][y] = '\xF8';
				drawField(gameField);
			}
			break;

		case LEFT:

			if (gameField[x][y-1] == '@')
			{
				gameField[x][y - 1] = '*';
				gameField[x][y] = '\xF8';
				drawField(gameField);
				printf("\n\n\nCongratulations! You've won!	Steps: %d / %d\n", originalSteps - steps, originalSteps);
				return 0;
			}
			else if (y != MIN_WIDTH && gameField[x][y -1] != '#')
			{
				y--;
				steps--;
				gameField[x][y] = '*';
				gameField[x][y + 1] = '\xF8';
				drawField(gameField);
			}
			break;

		case UP:

			if (gameField[x-1][y] == '@')
			{
				gameField[x-1][y] = '*';
				gameField[x][y] = '\xF8';
				drawField(gameField);
				printf("\n\n\nCongratulations! You've won!	Steps: %d / %d\n", originalSteps - steps, originalSteps);
				return 0;
			}
			else if (x!=0 && gameField[x-1][y] != '#')
			{
				x--;
				steps--;
				gameField[x][y] = '*';
				gameField[x+1][y] = '\xF8';
				drawField(gameField);
			}
			break;
			
			

		case RIGHT:
			if (gameField[x][y+1] == '@') 
			{
				gameField[x][y+1] = '*';
				gameField[x][y] = '\xF8';
				drawField(gameField);
				printf("\n\n\nCongratulations! You've won!	Steps: %d / %d\n", originalSteps - steps, originalSteps);
				return 0;
			}
			else if(y!=MAX_WIDTH-3 && gameField[x][y+1]!='#')
			{
				y++;
				steps--;
				gameField[x][y] = '*';
				gameField[x][y - 1] = '\xF8';
				drawField(gameField);
			}
			break;
		}
		COLOR(14);
		
	} while (1);
	

}	
	
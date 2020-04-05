#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "windows.h"
#include "conio.h"
#include "time.h"

#define RIGHT  0xE04D
#define LEFT   0xE04B
#define UP     0xE048
#define DOWN   0xE050
#define N      20
#define M      70


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setPosition(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void outArray(char array[N][M])
{

    for (int i = 0; i < 18; i++)
    {
        for (int j = 0; j < 68; j++)
        {
            int x = j + 1, y = i + 1;
            setPosition(x, y);
            printf("%c", array[i][j]);
          
        }
    }
}

int main()
{
	printf("firstName: ");
	char name[50],lastName[50],nickName[50];
	int  steps, block;

	scanf_s("%s", &name);                
	scanf_s("%s", &name, sizeof(name));

	printf("lastName: ");
	scanf_s("%s", &lastName);
	scanf_s("%s", &lastName, sizeof(lastName));

	printf("nickName: ");
	scanf_s("%s", &nickName);
	scanf_s("%s", &nickName, sizeof(nickName));

	printf("\n\nWelcomt: %s %s %s ", name, nickName, lastName);

	printf("\nBlocks: ");
	scanf_s("%d", &block);
    
	printf("Steps: ");
	scanf_s("%d", &steps);
	
	system("cls");

    char arr[N][M];
    int x = 0, y = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            setColor(4);
            if (i == 0) {
                if (i == 0 && j == 0)
                {
                    printf("\xDA");   // 218	0xDA	11011010	┌
                }
                else if (i == 0 && j == 69)
                {
                    printf("\xBF\n"); // 191	BF	    10111111	┐
                }
                else
                {
                    printf("\xC4");   // 196	C4	    11000100    ─
                }
            }
            if (i == 19) {
                if (i == 19 && j == 0)
                {
                    printf("\xC0");   // 192	C0	    11000000	└
                }
                else if (i == 19 && j == 69)
                {
                    printf("\xD9");   // 217	D9	    11011001	┘
                }
                else
                {
                    printf("\xC4");   // 196	C4	    11000100    ─
                }
            }
            if (i != 0 && i != 19 && j == 0)
            {
                printf("\xB3");       // 179	B3	    10110011	│
            }
            else if (j == 69 && i != 0 && i != 19)
            {
                printf("\xB3\n");     // 179	B3	    10110011	│
            }
            if (i != 0 && i != 19 && j != 0 && j != 69)
            {
                printf(" ");
            }
        }
    }

    srand(time(NULL));

    int R = 0, Q = 0;
    for (block; block > 0; block--)
    {
        R = 1 + rand() % (19 - 1);
        Q = 1 + rand() % (68 - 1);
        arr[R][Q] = '#';
    }
    
    for (int i = 0; i < 1; i++)
    {
        R = 1 + rand() % (19 - 1);
        Q = 1 + rand() % (68 - 1);
        arr[R][Q] = '@';
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == '#' || arr[i][j] == '@')
            {
                continue;
            }
            else
            {
                arr[i][j] = ' ';
            }
        }
    }
    setColor(2);
    arr[0][0] = '*';
    outArray(arr);
    while (steps != 0)
    {
        setPosition(0, 21);
        printf("Steps: %d", steps--);
        int push;
        push = _getch();
        if (push == 0xE0)
        {
            push = push << 8;
            push = push | _getch();
        }

        switch (push)
        {
        case RIGHT:
            if (push == RIGHT)
            {
                if (arr[x][y + 1] == '@')
                {
                    arr[x][y + 1] = '*';
                    arr[x][y] = '.';
                    outArray(arr);
                    setColor(2);
                    setPosition(0, 22);
                    printf("Congratulations! You`ve won!");
                    return ;
                }
                else if (y != M - 3 && arr[x][y + 1] != '#')
                {
                    y++;
                    arr[x][y] = '*';
                    arr[x][y - 1] = '.';
                    outArray(arr);
                }
            }break;
        case LEFT:
            if (push == LEFT)
            {
                if (arr[x][y - 1] == '@')
                {
                    arr[x][y - 1] = '*';
                    arr[x][y] = '.';
                    outArray(arr);
                    setColor(2);
                    setPosition(0, 22);
                    printf("Congratulations! You won!");
                    return ;
                }
                else if (y != 0 && arr[x + 1][y] != '#')
                {
                    y--;

                    arr[x][y] = '*';
                    arr[x][y + 1] = '.';
                    outArray(arr);
                }
            }break;
        case DOWN:
            if (push == DOWN)
            {
                if (arr[x + 1][y] == '@')
                {
                    arr[x + 1][y] = '*';
                    arr[x][y] = '.';
                    outArray(arr);
                    setColor(2);
                    setPosition(0, 22);
                    printf("Congratulations! You`ve won!");
                    return ;
                }
                else if (x != N - 3 && arr[x + 1][y] != '#')
                {
                    x++;

                    arr[x][y] = '*';
                    arr[x - 1][y] = '.';
                    outArray(arr);
                }
            }break;
        case UP:
            if (push == UP)
            {
                if (arr[x - 1][y] == '@')
                {
                    arr[x - 1][y] = '*';
                    arr[x][y] = '.';
                    outArray(arr);
                    setColor(2);
                    setPosition(0, 22);
                    printf("Congratulations! You`ve won!");
                    return ;
                }
                else if (x != 0 && arr[x + 1][y] != '#')
                {
                    x--;

                    arr[x][y] = '*';
                    arr[x + 1][y] = '.';
                    outArray(arr);
                }
            }break;
            return ;
        }

    }
    
    if (steps == 0) {
        setColor(4);
        setPosition(0, 22);
        printf("You lose try next time!!!");
    }
}
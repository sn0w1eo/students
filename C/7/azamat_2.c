/*Кирилл я немного подругому сделал))*/
#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#define SPACE ' '
char matrix[3][3] = { /* матрица для крестиков-ноликов */
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE},
{SPACE, SPACE, SPACE}
};
void get_computer_move(void), get_player_move(void);
void disp_matrix(void);
char check(void);
void color(int color);



int main()
{
	char total;
	color(12);
	printf("This is the game of Tic-Tac-Toe.\n");
	printf("You will be playing against the computer.\n");
	total = SPACE;
	do {
		color(11);
		disp_matrix(); /* вывод игровой доски */
		get_player_move(); /* ходит игрок */
		total = check(); /* проверка на победу */
		if (total != SPACE) break; /* победитель */
		get_computer_move(); /* ходит компьютер */
		total = check(); /* проверка на победу */
	} while (total == SPACE);
	if (total == 'X') printf("Ez\n");
	else printf("Molodoy ti proigral\n");
	disp_matrix(); /* отображение результата */
	return 0;
}

/* ввод хода игрока */
void get_player_move(void)
{
	int x;
	int y;
	printf("Enter coordinates for your X.\n");
	color(7);
	printf("Line? ");
	scanf_s("%d", &x);
	color(8);
	printf("Column? ");
	scanf_s("%d", &y);
	x--, y--;
	if (x < 0 || y < 0 || x>2 || y>2 || matrix[x][y] != SPACE)
	{
		printf("Invalid move, try again.\n");
		get_player_move();
	}
	else matrix[x][y] = 'X';
}

/* ход компьютера */
void get_computer_move(void)
{
    int t;
	char* p;
	p = (char*)matrix;
	for (t = 0; *p != SPACE && t < 9; ++t) p++;
	if (t == 9)
	{
		printf("draw\n");
		exit(0); /* game over */
	}
	else *p = 'O';
}

/* отображение игровой доски */
void disp_matrix(void)
{
	int t;
	for (t = 0; t < 3; t++)
	{
		printf(" %c | %c | %c", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) printf("\n-|-|-|-|-|-\n");
	}
	printf("\n");
}

/* проверка на победу */
char check(void)
{
	int t;
	char* p;
	for (t = 0; t < 3; t++) { /* проверка строк */
		p = &matrix[t][0];
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) return *p;
	}
	for (t = 0; t < 3; t++) { /* проверка столбцов */
		p = &matrix[0][t];
		if (*p == *(p + 3) && *(p + 3) == *(p + 6)) return *p;
	}

	/* проверка диагоналей */
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])
		return matrix[0][0];
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
		return matrix[0][2];
	return SPACE;
}
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}
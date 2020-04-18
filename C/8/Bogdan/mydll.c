#include "stdio.h"
#include "windows.h"
#include "time.h"
#include "stdlib.h"

#define GREEN  10
#define WHATE  15
#define BLUE   11
#define DWHITE 8
#define RED    12


static int victory = 0;
static int losing = 0;

//смена цвета
void color(color) {
SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//приветствие
__declspec(dllexport) void f1() {

	color(GREEN);
	printf("Hola amigos\n");
	color(WHATE);
	printf("Try your luck.The game \"heads or tails\"\n");
	color(BLUE);
	printf("Amigo,choose HEADS or TAILS?\n");
	color(DWHITE);
	printf("to select HEADS click <W>\n");
	printf("to select TAILS click <E>\n");
	printf("to exit press <X>\n");
}


//конец игры
__declspec(dllexport) void f3() {

	if (victory > losing) {

		color(BLUE);
		printf("Ok,Amigo. Take your winnings - %d coin", victory);
	}
	else if (victory < losing)
	{
		color(BLUE);
		printf("Ok,Amigo. give my money - %d dollars", losing * 2);
	}
	else {
		color(BLUE);
		printf("Ok,Amigo.See you");
	}
}


//выбор стороны
__declspec(dllexport) void f2() {

	int vvod;
	
	int coin;
	srand(time(NULL));
	rand();

	do {
		coin = rand() % 2;
		vvod = getch();
		
		switch (vvod)
		{

		case 'W':
		case 'w':
			if (coin == 0) {
				color(GREEN);
				printf("%c - Congratulations,HEADS fell out. Get a coin\n", 0xFE);
				++victory;
			}
			else {
				color(RED);
				printf("%c - TAILS fell out.Bad luck\n", 0xFE);
				++losing;
			}
			break;


		case 'e':
		case 'E':
			if (coin == 1) {

				color(GREEN);
				printf("% c - Congratulations, TAILS fell out.Get a coin\n", 0xFE);
				++victory;
			}
			else {
				color(RED);
				printf("%c - HEADS fell out. Bad luck\n", 0xFE);
				++losing;
			}
			break;


		case 'x':
		case 'X':

			
			return(0);

		}

	} while (1);

}







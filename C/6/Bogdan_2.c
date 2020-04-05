#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define xMax  39
#define yMax  19
#define ESC   0x1B
#define LEFT  0xE04B
#define RIGHT 0xE04D
#define UP    0xE048
#define DOWN  0xE050


//ãÒ¨Ô  ØÖó·¤··
void position(int x, int y) {
	COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}


//ãÒ¨Ô  ¤ë¨å 
void color(int ColorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}

//ëñëÖ¦ á ÒÆ·
void Display(int x, int y)

{
	position(x, y);
	color(13);

	//ë¨áµÔÞÞ ¬á Ô·¤ 
	for (int i = 0; i < xMax; i++)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"Ä" ì¨áµÔÞÞ · Ô·éÔÞÞ ¬á Ô·¤ 
		x++;
	}

	//Øá ë Þ ¬á Ô·¤ 
	for (int i = 0; i < yMax; i++)
	{
		position(x, y);
		printf("\xB3");		//179	B3	10110011	"³" Ýá ë Þ ¬á Ô·¤ 
		y++;
	}

	//Õ·éÔÞÞ ¬á Ô·¤ 
	for (int i = xMax; i > 0; i--)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"Ä" ì¨áµÔÞÞ · Ô·éÔÞÞ ¬á Ô·¤ 
		x--;
	}

	//è¬Ðñ
	position(0, 0);
	printf("\xDA");			//218	DA	11011010  "Ú"	Ð¨ëñ½ ë¨áµÔ·½ ç¬ÖÐ
	position(xMax, 0);           	
	printf("\xBF");			//191	BF	10111111  "¿"   ë¨áµÔ·½ Øá ëñ½ ç¬ÖÐ 
	position(xMax, yMax);
	printf("\xD9");			//217	D9	11011001  "Ù"	Øá ëñ½ Ô·éÔ·½ ç¬ÖÐ
	position(0, yMax);           
	printf("\xC0");			//192	C0	11000000  "À"   Ô·éÔ·½ Ð¨ëñ½ ç¬ÖÐ
} 

//ëñëÖ¦ Ò ãã·ë  ã ãÖÖåë¨åãåëçœù·Ò· ¤ë¨å Ò·
void PrintMassiv(int Massiv[][xMax - 1]){

	position(0, 1);
	for (int y = 0; y < yMax - 1 ; y++) {
		for (int x = 0; x < xMax - 1 ; x++) {
			if (x == 0)
			{
				color(13);
			}
			else if (Massiv[y][x] == '#')
			{
				color(12);
			}
			else if (Massiv[y][x] == '*')
			{
				color(11);
			}
			else if (Massiv[y][x] == '@')
			{
				color(10);
			}
			else if (Massiv[y][x] == 0xF9)
			{
				color(14);
			}
			printf("%c", Massiv[y][x]);
		}
		printf(" \n");
	}
	}



int main() {

	char FirstName[20] = { 0x00 };
	char LastName[20] = { 0x00 };
	char NickName[20] = { 0x00 };
	int Steps, Blocks, x = 0, y = 0;
	int Massiv[yMax-1][xMax-1];
	unsigned int vvod;
	int stroka = 0, stolb = 1;
	int lable = 1;
	int BeginnerSteps;
	srand(time(NULL));


	//ìëÖ¦ ¦ ÔÔñµ
	printf("first Name: ");
	gets(FirstName);
	printf("\nlastName: ");
	gets(LastName);
	printf("\nnick Name: ");
	gets(NickName);
	printf("\nWelcome %s \"%s\" %s\n", FirstName, NickName, LastName);
	printf("Blocks: ");
	scanf_s("%d", &Blocks);
	printf("Steps: ");
	scanf_s("%d", &Steps);
	BeginnerSteps = Steps;
	Display(x, y);
	position(x, yMax + 2);
	color(14);
	printf("STEPS: %d", Steps);
	system("cls");

	//ô ØÖÐÔ¨Ô·¨ Ó ãã·ë  ØáÖ¢¨Ð Ò·
	for (int y = 0; y < yMax - 1 ; y++) {
		for (int x = 0; x < xMax - 1; x++) {
			Massiv[y][x] = ' ';
		}
		if (x == 0)
		{
			Massiv[y][x] = 0xB3;              //  179	B3	10110011	"³" Ð¨ë Þ ¬á Ô·¤ 
		}
	}


	//ô ØÖÐÔ¨Ô·¨ Ò ãã·ë  @
	for (int i = 1; i > 0; i--)
	{

		y = rand() % (yMax -1);
		x = rand() % (xMax -1);
		if (x == 0 || (x == 1 && y == 0))   //ØáÖë¨áÆ  Ô  ¬á Ô·¤ç · Ô û ÐíÔñ½ ÷Ð¨Ò¨Ôå
		{
			++i;
			continue;
		}
		Massiv[y][x] = '@';
	}


	//ô ØÖÐÔ¨Ô·¨ Ò ãã·ë  *
	Massiv[0][1] = '*';


	//ó ØÖÐÔ¨Ô·¨ Ò ãã·ë  (#)
	for (int i = Blocks; i > 0; i--)
	{
		y = rand() % (yMax-1 );
		x = rand() % (xMax -1);
		if (x == 0 || (x == 1 && y == 0) || Massiv[y][x] == '@' || Massiv[y][x] == '#') {         //ØáÖë¨áÆ  Ô  ¬áÔ·¤ç, Ô û ÐíÔñ½ ÷Ð¨Ò¨Ôå, ª·Ô·õ · ØÖëåÖáÔñ½ ¢ÐÖÆ
			++i;
			continue;
		}
		Massiv[y][x] = '#';
	}

	//ëñëÖ¦ ·óÔ û ÐíÔÖ¬ Ò ãã·ë 
	Display(0,0);
	PrintMassiv(Massiv);


	
	do
	{

		vvod = _getch();

		if (vvod == 0xE0)
		{
			vvod = vvod << 8;
			vvod = vvod | _getch();
		}
		//ØáÖë¨áÆ  ãåá¨ÐÖÆ
		switch (vvod)
		{
		case RIGHT: 
			//ØáÖë¨áÆ  Ô  ¬á Ô·¤ñ · ¢ÐÖÆ·
			if ((Massiv[stroka][stolb + 1] == '#') || (stolb+1==xMax-1))
		{
			break;
		}


			else
		{
			Massiv[stroka][stolb] = 0xF9;                  //óÔ Æ åÖûÆ·
			if (Massiv[stroka][stolb + 1] == '@') {        //ØáÖë¨áÆ  Ô  ª·Ô·õ
				lable = 0;
			}
			++stolb;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);                                 //ëñëÖ¦ á ÒÆ·
			PrintMassiv(Massiv);                           //ëñëÖ¦ Ò ãã·ë 
			Steps--;
			position(0, yMax + 2);                         //ëñëÖ¦ ÆÖÐ-ë  õ ¬Öë
			color(14);
			printf("STEPS: %d  ", Steps);
			break;

		}
		case LEFT:
			if (Massiv[stroka][stolb - 1] == '#' || (stolb - 1 == 0))
		{
			break;
		}


			 else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka][stolb - 1] == '@')
				lable = 0;
			--stolb;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}

		case UP:
			if (Massiv[stroka - 1][stolb] == '#' || (stroka - 1 == -1))

		{
			break;
		}


			else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka-1][stolb ] == '@')
				lable = 0;
			--stroka;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}

		case DOWN:
			if (Massiv[stroka + 1][stolb] == '#' || (stroka + 1 == yMax - 1))

		{
			break;
		}


		   else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka-1][stolb ] == '@')
				lable = 0;
			++stroka;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}


		}
		if (vvod == ESC) {
			position(0, yMax+2);
			color(13);
			printf("Ok buddy. Cya next time...");
			_getch();
			return;
		}

	} while (Steps !=0 && lable!=0);

	
	if (lable == 0)
	{
		position(0, yMax+2);                                                        
		color(10);
		printf("Congratulations! You've won! Steps: %d/%d ",Steps,BeginnerSteps);
	}
	else
	{

		position(0, yMax + 2);
		color(12);
		printf("You've failed. Try ur luck next time");
	}


	_getch();
}

#define _CRT_SECURE_NO_WARNINGS
#include "mydll.h"
#include "stdio.h"
#include "stdlib.h"
#include "Windows.h"
#include "time.h"
#include "stdbool.h"


#define CYAN        0x0B
#define GREY        0x08
#define WHITE       0x07
#define GREEN       0x02
#define LIGHTGREEN  0x0A
#define RED         0x04
#define LIGHTRED    0x0C
#define BACKGROUND  0xA0
#define BLUE        0x03
#define YELLOW      0x0E

#define ENTER       13
#define ESC         0x1B



void f1()
{
	system("chcp 1251>nul");

	 int height=0;

	time_t rawtime;
	struct tm* info;
	 char buffer[80];
	time(&rawtime);
	info = localtime(&rawtime);
	strftime(buffer, 80, "%I:%M", info);

	HANDLE consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;

	system("mode con cols=80 lines=45");

	SetConsoleTextAttribute(consoleOut, BLUE);
	printf(
"	                .sss.  \n"    
"	                $P'`T.     \n"
"	                $;  :;     \n"
"	                $;  :$     \n"
"	        __.......$b__d$     \n"
"	   .sd$$$P^^^^^^^^TBuG$s.   \n"
"	  .$P'      ____     _`T$.  \n"
"	  $P        ****    (_) T$  \n"
"	 s$   _..---****---.._   $s \n"
"	 $$ .'     NOKIA      `. $$ \n"
"	.$$.  .--------------.  .$$.\n"
"	:$$: :                ; ;$$;\n"
"	$$;| |                | |:$$\n"
"	$$'| |                | |'$$\n"
"	$$ | |                | | $$\n"
"	$$ | |                | | $$\n"
"	$$ | :                ; | $$\n"
"	$$.;  `--------------'  :.$$\n"
"	$$;  .       .-.       . :$$\n"
"	:$$   `-.   / _ \\   .-'  $$;\n"
"	'$$   .-.`.: (_) ;.'.-.  $$'\n"
"	 $$  :   ; `.___.' :   ; $$ \n"
"	 $$   `-'           `-'  $$ \n"
"	 $$.                    .$$ \n"
"	 $$;                    :$$ \n"
"	 :$$                    $$; \n"
"	 '$$                    $$' \n"
"	  $$                    $$  \n"
"	  $$                    $$  \n"
"	  $$                    $$  \n"
"	  $$.                  .$$  \n"
"	  $$;                  :$P  \n"
"	   T$b.              .d$P   \n"
"	    `^T$$$$$$$$$$$$$P^'\n");

	/*Green button*/
	cursorPosition.X = 14;
	cursorPosition.Y = 20;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, GREEN);
	printf(".-.");
	cursorPosition.X = 13;
	cursorPosition.Y = 21;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	printf(":ÂÛÇ;");
	cursorPosition.X = 14;
	cursorPosition.Y = 22;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	printf("`-'");

	/*Red button*/
	
	cursorPosition.X = 28;
	cursorPosition.Y = 20;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, RED);
	printf(".-.");
	cursorPosition.X = 27;
	cursorPosition.Y = 21;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	printf(":ÂÛÕ;");
	cursorPosition.X = 28;
	cursorPosition.Y = 22;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	printf("`-'");

	/*Draw Display*/
	cursorPosition.X = 14;
	cursorPosition.Y = 11;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, BACKGROUND);
	for (int i = 1; i <= 16; i++) 
	{
		printf(" ");

		if (i == 16 && height < 6 ) 
		{
			if (height == 1) 
			{
				cursorPosition.Y = 11;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf("XXXELUS    %s",&buffer);
				
			}
			if (height == 3)
			{
				cursorPosition.Y = 13;
				cursorPosition.X = 15;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf("ÂÂÅÄÈÒÅ ÍÎÌÅÐ");
				cursorPosition.X = 14;
				cursorPosition.Y = 13;
			}
			if (height == 5) 
			{
				cursorPosition.Y = 15;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				printf("________________");
				cursorPosition.Y = 16;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				printf("ÂÛÇÎÂ      ÂÛÕÎÄ");
				break;
			}
			cursorPosition.Y++;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			i = 0;
			height++;
		}
		
		
	}
	/*Draw button*/
	cursorPosition.X = 13;
	cursorPosition.Y = 24;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 1 )");

	cursorPosition.X = 20;
	cursorPosition.Y = 24;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 2 )");

	cursorPosition.X = 27;
	cursorPosition.Y = 24;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 3 )");

	cursorPosition.X = 13;
	cursorPosition.Y = 26;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 4 )");

	cursorPosition.X = 20;
	cursorPosition.Y = 26;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 5 )");

	cursorPosition.X = 27;
	cursorPosition.Y = 26;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 6 )");

	cursorPosition.X = 13;
	cursorPosition.Y = 28;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 7 )");

	cursorPosition.X = 20;
	cursorPosition.Y = 28;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 8 )");

	cursorPosition.X = 27;
	cursorPosition.Y = 28;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 9 )");

	cursorPosition.X = 13;
	cursorPosition.Y = 30;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( * )");

	cursorPosition.X = 20;
	cursorPosition.Y = 30;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( 0 )");

	cursorPosition.X = 27;
	cursorPosition.Y = 30;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, WHITE);
	printf("( # )");

}

void f3()
{
	HANDLE consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 15;
	cursorPosition.Y = 14;
	int key, digitPosition = 0, number=0,height_1=0;
	bool inputBan = false;

	while (1)
	{

		key = getch();
		if (key == ENTER)
		{
			inputBan = true;
			cursorPosition.X = 14;
			cursorPosition.Y = 20;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, LIGHTGREEN);
			printf(".-.");
			cursorPosition.X = 13;
			cursorPosition.Y = 21;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf(":ÂÛÇ;");
			cursorPosition.X = 14;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf("`-'");
			Beep(525, 200);
			cursorPosition.X = 14;
			cursorPosition.Y = 20;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, GREEN);
			printf(".-.");
			cursorPosition.X = 13;
			cursorPosition.Y = 21;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf(":ÂÛÇ;");
			cursorPosition.X = 14;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf("`-'");

			switch (number)
			{
			case 702324061:
				cursorPosition.X = 14;
				cursorPosition.Y = 12;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);		
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf(" ÂÛÇÎÂ ÍÀÑÒÞØÈ");
				cursorPosition.Y = 14;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				printf("                ");
				cursorPosition.X = 14;
				cursorPosition.Y = 14;
				
				for (int beep = 0; beep < 2; beep++)
				{
					Beep(412, 1220);
					Sleep(100);
					Beep(412, 1220);
					Sleep(1200);
				}
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf(" ÀÁÎÍÅÍÒ ÇÀÍßÒ");
				Beep(432, 500);
				Beep(432, 500);
				Beep(432, 500);
				Sleep(1000);
				cursorPosition.X = 0;
				cursorPosition.Y = 34;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, GREY);
				return 0;
			break;
			case 555661796:

				cursorPosition.X = 14;
				cursorPosition.Y = 12;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf(" ÂÛÇÎÂ ÊÈÐÈËËÀ");
				cursorPosition.Y = 14;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				printf("                ");
				cursorPosition.X = 14;
				cursorPosition.Y = 14;
				for (int beep = 0; beep < 2; beep++)
				{
					Beep(412, 1220);
					Sleep(100);
					Beep(412, 1220);
					Sleep(1200);
				}
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf(" ÀÁÎÍÅÍÒ ÇÀÍßÒ");
				Beep(432, 500);
				Beep(432, 500);
				Beep(432, 500);
				Sleep(1000);
				cursorPosition.X = 0;
				cursorPosition.Y = 34;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, GREY);
				return 0;

			break;

			case 705770013:

				cursorPosition.X = 14;
				cursorPosition.Y = 12;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf("   ÂÛÇÎÂ ÁÎÑÑÀ");
				cursorPosition.Y = 14;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				printf("                ");
				cursorPosition.X = 14;
				cursorPosition.Y = 14;
				for (int beep = 0; beep < 2; beep++)
				{
					Beep(412, 1220);
					Sleep(100);
					Beep(412, 1220);
					Sleep(1200);
				}
				cursorPosition.Y = 13;
				cursorPosition.X = 14;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				printf("   ÁÎÑÑ ÇÀÍßÒ ");
				Beep(432, 500);
				Beep(432, 500);
				Beep(432, 500);
				Sleep(1000);
				cursorPosition.X = 0;
				cursorPosition.Y = 34;
				SetConsoleCursorPosition(consoleOut, cursorPosition);
				SetConsoleTextAttribute(consoleOut, GREY);
				return 0;

				break;
			default:
				if(number == 0)
				{
					
						cursorPosition.Y = 13;
						cursorPosition.X = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						SetConsoleTextAttribute(consoleOut, BACKGROUND);
						printf("  ÍÅÊÎÐÐÅÊÒÍÎ  ");
						Sleep(1000);
						cursorPosition.Y = 13;
						cursorPosition.X = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						SetConsoleTextAttribute(consoleOut, BACKGROUND);
						printf(" ÂÂÅÄÈÒÅ ÍÎÌÅÐ");
						inputBan = false;

				}
				else 
{

					cursorPosition.X = 14;
					cursorPosition.Y = 12;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, BACKGROUND);
					
					for (int i = 1; i <= 16; i++)
					{

						printf(" ");

						if (i == 16 && height_1 < 4)
						{

							if (height_1 == 3)
							{
								cursorPosition.Y = 13;
								cursorPosition.X = 17;
								SetConsoleCursorPosition(consoleOut, cursorPosition);
								SetConsoleTextAttribute(consoleOut, BACKGROUND);
								printf(" ÂÛÇÎÂ...");
								cursorPosition.X = 14;
								cursorPosition.Y = 14;
							}
							cursorPosition.Y++;
							SetConsoleCursorPosition(consoleOut, cursorPosition);
							i = 0;
							height_1++;
						}
					}
					for (int beep = 0; beep < 2; beep++) 
					{
						Beep(412, 1220);
						Sleep(100);
						Beep(412, 1220);
						Sleep(1200);
					}
					cursorPosition.Y = 13;
					cursorPosition.X = 14;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, BACKGROUND);
					printf(" ÀÁÎÍÅÍÒ ÇÀÍßÒ");
					Beep(432, 500);
					Beep(432, 500);
					Beep(432, 500);
					Sleep(1000);	
					cursorPosition.X = 0;
					cursorPosition.Y = 34;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					return 0;

				}
				break;
			}
		}

		if (key == ESC)
		{
			inputBan = true;
			cursorPosition.X = 28;
			cursorPosition.Y = 20;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, LIGHTRED);
			printf(".-.");
			cursorPosition.X = 27;
			cursorPosition.Y = 21;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf(":ÂÛÕ;");
			cursorPosition.X = 28;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf("`-'");
			Beep(525, 200);
			cursorPosition.X = 28;
			cursorPosition.Y = 20;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, RED);
			printf(".-.");
			cursorPosition.X = 27;
			cursorPosition.Y = 21;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf(":ÂÛÕ;");
			cursorPosition.X = 28;
			cursorPosition.Y = 22;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			printf("`-'");

			cursorPosition.X = 14;
			cursorPosition.Y = 11;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, BACKGROUND);
			for (int i = 1; i <= 16; i++)
			{
				
				printf(" ");

				if (i == 16 && height_1 < 6)
				{
					
					if (height_1 == 3)
					{
						cursorPosition.Y = 13;
						cursorPosition.X = 17;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						SetConsoleTextAttribute(consoleOut, BACKGROUND);
						printf(" Óâèäèìñÿ!");
						cursorPosition.X = 14;
						cursorPosition.Y = 13;
					}
					cursorPosition.Y++;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					i = 0;
					height_1++;
				}
			}
			Beep(294, 1000 / 8);
			Beep(440, 1000 / 4);
			Beep(262 * 2, 1000 / 4);
			Beep(330 * 2, 1000 / 4);
			Beep(415, 1000 / 8);
			Beep(440, 1000);
			
			cursorPosition.X = 0;
			cursorPosition.Y = 34;
			SetConsoleCursorPosition(consoleOut, cursorPosition);
			SetConsoleTextAttribute(consoleOut, GREY);
			return 0;	
		}

		if(key >='0' && key <= '9' && digitPosition < 10)
		{
			if (inputBan == false)
			{
				number = number * 10 + (key - 48);
			}
		}
		if (inputBan == false) 
		{
			if (digitPosition == 10) 
			{
				inputBan = true;
			}
			else
			{
				if (key == '1')
				{
					cursorPosition.X = 13;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 1 )");
					Beep(525, 200);
					cursorPosition.X = 13;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 1 )");

				}

				if (key == '2')
				{
					cursorPosition.X = 20;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 2 )");
					Beep(525, 200);
					cursorPosition.X = 20;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 2 )");

				}

				if (key == '3')
				{
					cursorPosition.X = 27;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 3 )");
					Beep(525, 200);
					cursorPosition.X = 27;
					cursorPosition.Y = 24;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 3 )");
				}

				if (key == '4')
				{
					cursorPosition.X = 13;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 4 )");
					Beep(525, 200);
					cursorPosition.X = 13;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 4 )");
				}

				if (key == '5')
				{
					cursorPosition.X = 20;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 5 )");
					Beep(525, 200);
					cursorPosition.X = 20;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 5 )");
				}

				if (key == '6')
				{
					cursorPosition.X = 27;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 6 )");
					Beep(525, 200);
					cursorPosition.X = 27;
					cursorPosition.Y = 26;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 6 )");
				}

				if (key == '7')
				{
					cursorPosition.X = 13;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 7 )");
					Beep(525, 200);
					cursorPosition.X = 13;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 7 )");
				}

				if (key == '8')
				{
					cursorPosition.X = 20;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 8 )");
					Beep(525, 200);
					cursorPosition.X = 20;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 8 )");
				}

				if (key == '9')
				{
					cursorPosition.X = 27;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 9 )");
					Beep(525, 200);
					cursorPosition.X = 27;
					cursorPosition.Y = 28;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 9 )");
				}

				if (key == '*')
				{
					cursorPosition.X = 13;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( * )");
					Beep(525, 200);
					cursorPosition.X = 13;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( * )");
				}

				if (key == '0')
				{
					cursorPosition.X = 20;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( 0 )");
					Beep(525, 200);
					cursorPosition.X = 20;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( 0 )");
				}

				if (key == '#')
				{
					cursorPosition.X = 27;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, GREY);
					printf("( # )");
					Beep(525, 200);
					cursorPosition.X = 27;
					cursorPosition.Y = 30;
					SetConsoleCursorPosition(consoleOut, cursorPosition);
					SetConsoleTextAttribute(consoleOut, WHITE);
					printf("( # )");
				}

				SetConsoleTextAttribute(consoleOut, BACKGROUND);
				switch (digitPosition)
				{

				case 0:
					if (key >= '0' && key <= '9' || key == '#' || key == '*') {
						cursorPosition.X = 17;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 1:
					if (key >= '0' && key <= '9' || key == '#' || key == '*') {
						cursorPosition.X = 18;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 2:
					if (key >= '0' && key <= '9' || key == '#' || key == '*') {
						cursorPosition.X = 19;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 3:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 20;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 4:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 21;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 5:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 22;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 6:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 23;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 7:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 24;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 8:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 25;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}
				case 9:
					if (key >= '0' && key <= '9' || key == '#' || key == '*')
					{
						cursorPosition.X = 26;
						cursorPosition.Y = 14;
						SetConsoleCursorPosition(consoleOut, cursorPosition);
						putchar(key);
						digitPosition++;
						break;
					}

				}
			}
		}
	}
}

void f2() 
{
	HANDLE consoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition;
	cursorPosition.X = 44;
	cursorPosition.Y = 0;
	for (int i = 0; i < 45; i++) 
	{
		printf("|");
		cursorPosition.Y++;
		SetConsoleCursorPosition(consoleOut, cursorPosition);
	}
	
	cursorPosition.X = 54;
	cursorPosition.Y = 3;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, CYAN);
	printf("Êîíòàêòû:");
	
	cursorPosition.X = 50;
	cursorPosition.Y = 5;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, YELLOW);
	printf("Áîññ - 705770013 ");
	
	cursorPosition.X = 50;
	cursorPosition.Y = 6;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, YELLOW);
	printf("Íàñòÿ - 702324061 ");
	
	cursorPosition.X = 50;
	cursorPosition.Y = 7;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, YELLOW);
	printf("Êèðèëë - 555661796 ");
	
	
	cursorPosition.X = 54;
	cursorPosition.Y = 11;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, CYAN);
	printf("CÏÐÀÂÊÀ:");

	cursorPosition.X = 50;
	cursorPosition.Y = 13;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, YELLOW);
	printf("ENTER - ");

	cursorPosition.X = 58;
	cursorPosition.Y = 13;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, LIGHTGREEN);
	printf("ÂÛÇÎÂ");

	cursorPosition.X = 50;
	cursorPosition.Y = 14;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, YELLOW);
	printf("ESC   - ");

	cursorPosition.X = 58;
	cursorPosition.Y = 14;
	SetConsoleCursorPosition(consoleOut, cursorPosition);
	SetConsoleTextAttribute(consoleOut, LIGHTRED);
	printf("ÂÛÕÎÄ");


}

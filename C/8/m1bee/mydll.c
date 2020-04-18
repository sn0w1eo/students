#include "stdio.h"
#include "windows.h"
#include "time.h"

#include "mydll.h"

__declspec(dllexport) void f1()
{
	printf_s("Hello! Bee made 4 u cookies with predictions\n");
	printf_s("__&&&&&&____________&&&&&&\n");
	printf_s("&&&&___&&&________&&&____&&&&\n");
	printf_s("__&&&&___&&&_____&&&___&&&&\n");
	printf_s("____&&&&_&&&&__&&&&_&&&&\n");
	printf_s("______&&&&&&&&&&&&&&&&\n");
	printf_s("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf_s("&&&&&__&&&&__&&&__&&&&_&&&&&&\n");
	printf_s("&__&&&&&&____&&&____&&&&&&__&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&____________&&&____________&\n");
	printf_s("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
}

__declspec(dllexport) void f2()
{
	do
	{
		printf_s("It's ur random prediction:\n");
		srand(time(NULL));
		int number = 1 + rand() % 5;
		switch (number)
		{
		case 1:
			printf_s("U can handle everything. And if u can’t do it, u’ll survive\n");
			break;
		case 2:
			printf_s("U will find what u are looking 4\n");
			break;
		case 3:
			printf_s("Vivacity will not leave u\n");
			break;
		case 4:
			printf_s("U will have the chance to create something immortal\n");
			break;
		case 5:
			printf_s("Routine will stop annoying u\n");
			break;
		}
	} while (1);
}

__declspec(dllexport) void f3()
{
	printf_s("Now u can choose number from 1 to 15\n");
	do
	{
		int number;
		printf_s("Press any number from 1 to 10\n");
		scanf_s("%d", &number);
		switch (number)
		{
		case 1:
			printf_s("Ur work will be fruitful\n");
			break;
		case 2:
			printf_s("All the reasons, why u missed morning exercises, will disappear\n");
			break;
		case 3:
			printf_s("Ur world will be safe\n");
			break;
		case 4:
			printf_s("Until the end of days, the world will never stop surprising u\n");
			break;
		case 5:
			printf_s("Ur guardian angel will take care of u forever\n");
			break;
		case 6:
			printf_s("The taste 4 life will live in u forever\n");
			break;
		case 7:
			printf_s("The most important thing in ur life u can see without the help of the eyes\n");
			break;
		case 8:
			printf_s("Others will make a choice 4 u if u decide to doubt\n");
			break;
		case 9:
			printf_s("U will never get too old to learn\n");
			break;
		case 10:
			printf_s("Life will present many meetings with different people\n");
			break;
		case 11:
			printf_s("Happiness will become ur usual state\n");
			break;
		case 12:
			printf_s("Ur reward will find u\n");
			break;
		case 13:
			printf_s("Complete what you started\n");
			break;
		case 14:
			printf_s("Ur goal is achievable\n");
			break;
		case 15:
			printf_s("Don't wait 4 quick results\n");
			break;
		}
	} while (1);
}
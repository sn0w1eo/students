﻿#include "stdio.h"
#include "windows.h"
#include "time.h"

void setColor(int color);
void printGoods();
void car();
void laghman();
void ticket();
void brain();
void iceCream();
void zachet();
void bonus();

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	int number;
	printf_s("Welcome to shop. This is list of Goods\n\n");
	printGoods();
	printf_s("\nChoose the number of Goods you want\n");
	do
	{
		scanf_s("%d", &number);
		if (number == 1)
		{
			car();
		}
		else if (number == 2)
		{
			laghman();
		}
		else if (number == 3)
		{
			ticket();
		}
		else if (number == 4)
		{
			brain();
		}
		else if (number == 5)
		{
			iceCream();
		}
		else if (number == 6)
		{
			zachet();
		}
	} while (1);
}

void printGoods()
{
	setColor(11);
	printf_s("1. BMW M8 Gran Coupe\n");
	printf_s("2. Laghman from Faiza\n");
	printf_s("3. The ticket to USA\n");
	printf_s("4. The technical ability of Dima\n");
	printf_s("5. Ice cream\n");
	printf_s("6. Zachet po vsem predmetam\n");
	setColor(7);
}

void car()
{
	unsigned long int a;
	printf_s("U chose BMW M8 Gran Coupe. It costs 140000$. How much money do u have in $ ?\n");
	scanf_s("%d", &a);
	if (a < 140000)
	{
		printf_s("U don't have enough money. Come here when u will make a lot of money or choose another Goods\n");

	}
	else if (a > 140000)
	{
		unsigned long int b = a - 140000;
		printf_s("Congratulations with car! Your balance is %d $. Be careful!", b);
		bonus();
	}
}

void laghman()
{
	unsigned long int a;
	printf_s("U chose Laghman from Faiza. It costs 4$. How much money do u have in $ ?\n");
	scanf_s("%d", &a);
	if (a < 4)
	{
		printf_s("U don't have enough money. Come here when u will make a lot of money or choose another Goods\n");

	}
	else if (a > 4)
	{
		unsigned long int b = a - 4;
		printf_s("Congratulations with Laghman! Your balance is %d $. Bon appetit", b);
		bonus();
	}
}

void ticket()
{
	unsigned long int a;
	printf_s("U chose the ticket to USA. It costs 550$. How much money do u have in $ ?\n");
	scanf_s("%d", &a);
	if (a < 550)
	{
		printf_s("U don't have enough money. Come here when u will make a lot of money or choose another Goods\n");

	}
	else if (a > 550)
	{
		unsigned long int b = a - 550;
		printf_s("Congratulations with ticket! Your balance is %d $. Safe road!", b);
		bonus();
	}
}

void brain()
{
	printf_s("U r not in a fairy tale. Go study\n");
	setColor(12);
	printf_s("\nBUT\n");
	setColor(7);
	bonus();
}

void iceCream()
{
	unsigned long int a;
	printf_s("U chose an ice cream. It costs 1$. How much money do u have in $ ?\n");
	scanf_s("%d", &a);
	if (a < 1)
	{
		printf_s("U don't have enough money. Come here when u will make a lot of money or choose another Goods\n");

	}
	else if (a > 1)
	{
		unsigned long int b = a - 1;
		printf_s("Congratulations with ice cream! Your balance is %d $. Bon appetit!\n", b);
		bonus();
	}
}

void zachet()
{
	printf_s("It was a joke. Go study\n");
	setColor(12);
	printf_s("\nBUT\n");
	setColor(7);
	bonus();
}

void bonus()
{
	printf_s("\nU have a present from us\n");
	srand(time(NULL));
	int a = 1 + rand() % 6;
		switch(a)
		{
		case 1:
			setColor(10);
			printf_s("U won an ice cream. Congrats\n");
			setColor(7);
			break;
		case 2:
			setColor(10);
			printf_s("U won a face mask. Congrats\n");
			setColor(7);
			break;
		case 3:
			setColor(10);
			printf_s("U won an antiseptic. Congrats\n");
			setColor(7);
			break;
		case 4:
			setColor(10);
			printf_s("U won 10 packs of chips. Congrats\n");
			setColor(7);
			break;
		case 5:
			setColor(10);
			printf_s("U won 100 $. Congrats\n");
			setColor(7);
			break;
		case 6:
			setColor(10);
			printf_s("U won zachet po ekologii. Congrats\n");
			setColor(7);
			break;
		}
}
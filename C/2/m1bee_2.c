#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
int main()
{
	system("chcp 866> NUL");
	int num1, num2, add, sub, mul, mod;
	printf_s("WELCOME, Press any key...\n\n");
	char sim;
	sim = _getch();

	printf("ЪДДДДДДДДДДДВДДДДДДДДДДДДВДДДДДДДДДДДДВДДДДДДДДДДДДї\n");
	printf("і%12s %12s %12s %13s", "ASCIIі", "DECі", "HEXі", "BINі\n");
	printf("ГДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДґ\n");
	printf("і%11cі %11dі %11xі    %d%d%d%d%d%d%d%dі ", sim, sim, sim,
		sim >> 7, (sim >> 6) % 2,
		(sim >> 5) % 2, (sim >> 4) % 2, (sim >> 3) % 2,
		(sim >> 2) % 2, (sim >> 1) % 2, sim % 2);
	printf("\nАДДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДЩ\n");

	printf_s("Enter two numbers...\n");
	scanf_s("%d %d", &num1, &num2);
	double div;
	add = num1 + num2;
	sub = num1 - num2;
	mod = num1 % num2;
	mul = num1 * num2;
	div = (double)num1 / (double)num2;

	printf("ЪДДДДДДДДДДДДВДДДДДДДДДДДДДВДДДДДДДДДДДДДВДДДДДДДДДДДДДВДДДДДДДДДДДДДї\n");
	printf("і%13s %13s %13s %13s %14s", "ADDі", "SUBі", "MULі", "DIVі", "MODі\n");
	printf("ГДДДДДДДДДДДДЕДДДДДДДДДДДДДЕДДДДДДДДДДДДДЕДДДДДДДДДДДДДЕДДДДДДДДДДДДДґ\n");
	printf("і%12dі %12dі %12dі %12.1fі %12dі ", add, sub, mul, div, mod);
	printf("\nАДДДДДДДДДДДДБДДДДДДДДДДДДДБДДДДДДДДДДДДДБДДДДДДДДДДДДДБДДДДДДДДДДДДДЩ\n\n");
	printf_s("100%% complete...\n\n");
}

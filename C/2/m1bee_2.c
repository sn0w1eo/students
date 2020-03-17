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
	printf("іASCII      іDEC         іHEX         іBIN         і\n");
	printf("ГДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДґ\n");
	printf("і%11cі %11dі %11xі %11sі ", sim, sim, sim,   "emptyі\n");
	printf("АДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДЩ\n\n");

	printf_s("Enter two numbers...\n");
	scanf_s("%d %d", &num1, &num2);
	double div;
	add = num1 + num2;
	sub = num1 - num2;
	mod = num1 % num2;
	mul = num1 * num2;
	div = (double)num1 / (double)num2;

	printf("ЪДДДДДДДДДДДВДДДДДДДДДДДДВДДДДДДДДДДДДВДДДДДДДДДДДДВДДДДДДДДДДДДї\n");
	printf("іADD        іSUB         іMUL         іDIV         іMOD         і\n");
	printf("ГДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДЕДДДДДДДДДДДДґ\n");
	printf("і%11dі %11dі %11dі %11.1fі %11dі\n ", add, sub, mul, div, mod);
    printf("АДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДБДДДДДДДДДДДДЩ\n\n");
	printf_s("100%% complete...\n\n");
}

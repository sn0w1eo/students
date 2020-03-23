#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 866>nul");
	char symbol;
	int n1, n2, add, sub, mul, mod;
	printf("\nPress any key ...");
	symbol = getch();

	Tabl1(symbol);//ฏฅเข๋ฉ กซฎช

	printf("\nEnter 2 numbers...");
	scanf_s("%d %d", &n1, &n2);
	add = n1 + n2;
	sub = n1 - n2;
	mul = n1 * n2;
	double div = (double)n1 / (double)n2;
	mod = n1 % n2;

	Tabl2(add, sub, mul, div, mod);
	printf("\nComplete 100%%\n");
}
int Tabl1(char symbol)
{
	printf("\nษออออออออออหออออออออออหออออออออออหออออออออออป");
	printf("\nบ%11s%11s%11s%11s", "ASCIIบ", "DECบ", "HEXบ", "BINARYบ");
	printf("\nฬออออออออออฮออออออออออฮออออออออออฮออออออออออน");
	printf("\nบ%10cบ %9dบ %9xบ  %d%d%d%d%d%d%d%dบ ", symbol, symbol, symbol,
		symbol >> 7, (symbol >> 6) % 2,
		(symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
		(symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2);

	printf("\nศออออออออออสออออออออออสออออออออออสออออออออออผ");

}
int Tabl2(int add, int sub, int mul, double div, int mod)
{
	printf("\nษออออออออออหออออออออออหออออออออออหออออออออออหออออออออออป");
	printf("\nบ%11s %10s %10s %10s %10s", "ADDบ", "SUMบ", "MULบ", "DIVบ", "MODบ");
	printf("\nฬออออออออออฮออออออออออฮออออออออออฮออออออออออฮออออออออออน");
	printf("\nบ%10dบ%10dบ%10dบ%10.2fบ%10dบ", add, sub, mul, div, mod);
	printf("\nศออออออออออสออออออออออสออออออออออสออออออออออสออออออออออผ");
}
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("chcp 866>nul");
	char symbol;
	int n1, n2, add, sub, mul, mod;
	printf("\nPress any key ...");
	symbol = getch();

	Tabl1(symbol);//���� ����

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
	printf("\n�������������������������������������������ͻ");
	printf("\n�%11s%11s%11s%11s", "ASCII�", "DEC�", "HEX�", "BINARY�");
	printf("\n�������������������������������������������͹");
	printf("\n�%10c� %9d� %9x�  %d%d%d%d%d%d%d%d� ", symbol, symbol, symbol,
		symbol >> 7, (symbol >> 6) % 2,
		(symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
		(symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2);

	printf("\n�������������������������������������������ͼ");

}
int Tabl2(int add, int sub, int mul, double div, int mod)
{
	printf("\n������������������������������������������������������ͻ");
	printf("\n�%11s %10s %10s %10s %10s", "ADD�", "SUM�", "MUL�", "DIV�", "MOD�");
	printf("\n������������������������������������������������������͹");
	printf("\n�%10d�%10d�%10d�%10.2f�%10d�", add, sub, mul, div, mod);
	printf("\n������������������������������������������������������ͼ");
}
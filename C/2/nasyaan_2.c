#include "stdio.h"
int main()
{

	char key;
	int digit1, digit2, add, sub, mul, mod;
	system("chcp 866 > nul");
	printf("\n1) Press any key... ");
	key = getch();
	drawTableKod(key);

	printf("\n2) Enter 2 digits...");
	scanf_s("%d %d", &digit1, &digit2);
	add = digit1 + digit2;
	sub = digit1 - digit2;
	mul = digit1 * digit2;
	double div = (double)digit1 / (double)digit2;
	mod = digit1 % digit2;
	drawTableMath(add, sub, mul, div, mod);
	printf("\n100%%Complete...\n");
	getch();
}
int drawTableKod(char key)
{
	printf("\nзддддддддддбддддддддддбддддддддддбдддддддддд©");
	printf("\nЁ%10sЁ%10sЁ%10sЁ%10sЁ", "ASCII", "DEC", "HEX", "BINARY");
	printf("\nцддддддддддеддддддддддеддддддддддедддддддддд╢ ");
	printf("\nЁ%10cЁ%10dЁ%10xЁ%3d%d%d%d%d%d%d%dЁ", key, key, key,
		key >> 7, (key >> 6) % 2,
		(key >> 5) % 2, (key >> 4) % 2, (key >> 3) % 2,
		(key >> 2) % 2, (key >> 1) % 2, key % 2);
	printf("\nюддддддддддаддддддддддаддддддддддадддддддддды");


}
int drawTableMath(int add, int sub, int mul, double div, int mod)
{
	printf("\nзддддддддддбддддддддддбддддддддддбддддддддддбдддддддддд©");
	printf("\nЁ%10sЁ%10sЁ%10sЁ%10sЁ%10sЁ", "ADD", "SUB", "MUL", "DIV", "MOD");
	printf("\nцддддддддддеддддддддддеддддддддддеддддддддддедддддддддд╢ ");
	printf("\nЁ%10dЁ%10dЁ%10dЁ%10.1fЁ%10dЁ", add, sub, mul, div, mod);
	printf("\nюддддддддддаддддддддддаддддддддддаддддддддддадддддддддды");
}

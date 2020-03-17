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
printf("\nÚÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄ¿");
printf("\n³%10s³%10s³%10s³%10s³","ASCII","DEC", "HEX", "BINARY");
printf("\nÃÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄ´ ");
printf("\n³%10c³%10d³%10x³%10s³", key, key, key, "EMPTY");
printf("\nÀÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÙ");


}
int drawTableMath(int add, int sub, int mul, double div, int mod)
{
	printf("\nÚÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÄÄÄ¿");
	printf("\n³%10s³%10s³%10s³%10s³%10s³", "ADD", "SUB", "MUL", "DIV", "MOD");
	printf("\nÃÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄ´ ");
	printf("\n³%10d³%10d³%10d³%10.1f³%10d³",add , sub, mul, div, mod);
	printf("\nÀÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÄÄÄÙ");
}

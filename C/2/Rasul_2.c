#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
int main()
{
	printf("1) Press any key...\n\n");
	int n1, n2, add, sub, mul, mod;
	system("chcp 866 > nul");
	char sim;
	sim = _getch();
	printf ("�������������������������������������������Ŀ\n");
	printf ("� %10s %10s %10s %11s",  "ASCII�","DEC�", "HEX�","BINARY�\n");
	printf ("�������������������������������������������Ĵ\n");
	printf ("�    %2c    �   %2d     �%2x        �  %d%d%d%d%d%d%d%d�\n", sim, sim, sim,sim >> 7, (sim >> 6) % 2,
		(sim >> 5) % 2, (sim >> 4) % 2, (sim >> 3) % 2,(sim >> 2) % 2, (sim >> 1) % 2, sim % 2);
	printf ("���������������������������������������������\n");
	printf ("2) Enter 2 digits:\n");
	scanf_s ("%d %d", &n1, &n2);
	add = n1 + n2;
	sub = n1 - n2;
	mul = n1 * n2;
	double div;
	div = (double)n1 / (double)n2;
	mod = n1 % n2;
	printf ("������������������������������������������������������Ŀ\n");
	printf ("� %10s %10s %10s %10s %11s", "ADD�","SUB�","MUL�","DIV�", "MOD�\n");
	printf ("������������������������������������������������������Ĵ\n");
	printf ("� %8d � %8d � %8d �  %8.1f� %8d �", add,sub,mul,div,mod);
	printf ("\n��������������������������������������������������������\n");
	printf ("\n\n100%% complete...\n\n");


}

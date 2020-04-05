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
	printf ("зддддддддддбддддддддддбддддддддддбдддддддддд©\n");
	printf ("Ё %10s %10s %10s %11s",  "ASCIIЁ","DECЁ", "HEXЁ","BINARYЁ\n");
	printf ("цддддддддддеддддддддддеддддддддддедддддддддд╢\n");
	printf ("Ё    %2c    Ё   %2d     Ё%2x        Ё  %d%d%d%d%d%d%d%dЁ\n", sim, sim, sim,sim >> 7, (sim >> 6) % 2,
		(sim >> 5) % 2, (sim >> 4) % 2, (sim >> 3) % 2,(sim >> 2) % 2, (sim >> 1) % 2, sim % 2);
	printf ("юддддддддддаддддддддддаддддддддддадддддддддды\n");
	printf ("2) Enter 2 digits:\n");
	scanf_s ("%d %d", &n1, &n2);
	add = n1 + n2;
	sub = n1 - n2;
	mul = n1 * n2;
	double div;
	div = (double)n1 / (double)n2;
	mod = n1 % n2;
	printf ("зддддддддддбддддддддддбддддддддддбддддддддддбдддддддддд©\n");
	printf ("Ё %10s %10s %10s %10s %11s", "ADDЁ","SUBЁ","MULЁ","DIVЁ", "MODЁ\n");
	printf ("цддддддддддеддддддддддеддддддддддеддддддддддедддддддддд╢\n");
	printf ("Ё %8d Ё %8d Ё %8d Ё  %8.1fЁ %8d Ё", add,sub,mul,div,mod);
	printf ("\nюддддддддддаддддддддддаддддддддддаддддддддддадддддддддды\n");
	printf ("\n\n100%% complete...\n\n");


}

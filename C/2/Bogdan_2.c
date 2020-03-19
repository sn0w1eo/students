#include "stdio.h"
#include "conio.h"


int main()
{
	double div;
	unsigned char key;
	int perv, vtor, add, sub, mul, mod;
	printf("1) Press any key...\n");
	key = _getch();




	printf("\n здддддддбдддддбдддддддбддддддддд©		");
	printf("\n Ё ASCII Ё DEC Ё  HEX  Ё   BIN   Ё");
	printf("\n цдддддддедддддедддддддеддддддддд╢");
	printf("\n Ё%7cЁ %4dЁ %6XЁ%d%d%d%d%d%d%d%d Ё", key, key, key,key>>7, (key >> 6) % 2, (key >> 5) % 2, (key >> 4) % 2, (key >> 3) % 2, (key >> 2) % 2, (key >> 1) % 2,key%2 );
	printf("\n юдддддддадддддадддддддаддддддддды");




	printf("\n\n 2) Enter 2 digits: ");
	scanf_s("%d %d", &perv, &vtor);
	add = perv + vtor;
	sub = perv - vtor;
	mul = perv * vtor;
	div = (double)perv / (double)vtor;
	mod = perv % vtor;


	printf("\n здддддддбдддддбдддддддбдддддддбддддддд©		");
	printf("\n Ё ADD   Ё SUB Ё  MUL  Ё  DIV  Ё  MOD  Ё");
	printf("\n цдддддддедддддедддддддедддддддеддддддд╢");
	printf("\n Ё%7dЁ%5dЁ%7dЁ%7.2fЁ%7dЁ", add, sub, mul, div, mod);
	printf("\n юдддддддадддддадддддддадддддддаддддддды");

	printf("\n99.9 %% complete..................");








	_getch();


}
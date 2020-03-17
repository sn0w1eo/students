#include "stdio.h"
#include "conio.h"


int main()
{
	double div;
	char key;
	int perv, vtor, add, sub, mul, mod;
	printf("1) Press any key...\n");
	key = _getch();




	printf("\n ÚÄÄÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄ¿		");
	printf("\n ³ ASCII ³ DEC ³  HEX  ³  BIN  ³");
	printf("\n ÃÄÄÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ´");
	printf("\n ³%7c³ %4d³ %6X³ Empty ³", key, key, key);
	printf("\n ÀÄÄÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÙ");




	printf("\n\n 2) Enter 2 digits: ");
	scanf_s("%d %d", &perv, &vtor);
	add = perv + vtor;
	sub = perv - vtor;
	mul = perv * vtor;
	div = (double)perv / (double)vtor;
	mod = perv % vtor;


	printf("\n ÚÄÄÄÄÄÄÄÂÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄÂÄÄÄÄÄÄÄ¿		");
	printf("\n ³ ADD   ³ SUB ³  MUL  ³  DIV  ³  MOD  ³");
	printf("\n ÃÄÄÄÄÄÄÄÅÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄ´");
	printf("\n ³%7d³%5d³%7d³%7.f³%7d³", add, sub, mul, div, mod);
	printf("\n ÀÄÄÄÄÄÄÄÁÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÁÄÄÄÄÄÄÄÙ");

	printf("\n99.9 %% complete..................");








	_getch();


}
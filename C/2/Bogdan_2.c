#include "stdio.h"
#include "conio.h"


int main()
{
	double div;
	char key;
	int perv, vtor, add, sub, mul, mod;
	printf("1) Press any key...\n");
	key = _getch();




	printf("\n ┌───────┬─────┬───────┬───────┐		");
	printf("\n │ ASCII │ DEC │  HEX  │  BIN  │");
	printf("\n ├───────┼─────┼───────┼───────┤");
	printf("\n │  %c    │ %d  │ %X    │ Empty │", key, key, key);
	printf("\n └───────┴─────┴───────┴───────┘");




	printf("\n\n 2) Enter 2 digits: ");
	scanf_s("%d %d", &perv, &vtor);
	add = perv + vtor;
	sub = perv - vtor;
	mul = perv * vtor;
	div = (double)perv / (double)vtor;
	mod = perv % vtor;


	printf("\n ┌───────┬─────┬───────┬───────┬───────┐		");
	printf("\n │ ADD   │ SUB │  MUL  │  DIV  │  MOD  │");
	printf("\n ├───────┼─────┼───────┼───────┼───────┤");
	printf("\n │  %d    │ %d  │ %d   │ %.3f │  %d  │", add, sub, mul, div, mod);
	printf("\n └───────┴─────┴───────┴───────┴───────┘");

	printf("\n99.9 %% complete..................");








	_getch();


}
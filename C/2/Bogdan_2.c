#include "stdio.h"
#include "conio.h"


int main()
{
	double div;
	char key;
	int perv, vtor, add, sub, mul, mod;
	printf("1) Press any key...\n");
	key = _getch();




	printf("\n �����������������������������Ŀ		");
	printf("\n � ASCII � DEC �  HEX  �  BIN  �");
	printf("\n �����������������������������Ĵ");
	printf("\n �%7c� %4d� %6X� Empty �", key, key, key);
	printf("\n �������������������������������");




	printf("\n\n 2) Enter 2 digits: ");
	scanf_s("%d %d", &perv, &vtor);
	add = perv + vtor;
	sub = perv - vtor;
	mul = perv * vtor;
	div = (double)perv / (double)vtor;
	mod = perv % vtor;


	printf("\n �������������������������������������Ŀ		");
	printf("\n � ADD   � SUB �  MUL  �  DIV  �  MOD  �");
	printf("\n �������������������������������������Ĵ");
	printf("\n �%7d�%5d�%7d�%7.f�%7d�", add, sub, mul, div, mod);
	printf("\n ���������������������������������������");

	printf("\n99.9 %% complete..................");








	_getch();


}
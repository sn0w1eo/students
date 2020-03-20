#include<stdio.h>

void znacenie(double perv, unsigned char znak, double vtor) {
	double rezult ;
	if (znak == '+') {                                                      //проверяет знак
		rezult = perv + vtor; printf("%g\n", rezult);                      // делает вычисления и выводит
		for (int i = 0; i <= 20; i++) {                                 
			printf("Н");                                                //печатает разделитель за счет цикла
		}
		printf("\nHEX: %08X\n",(int) rezult);                                 //выводит в HEX


       printf("\nBIN: ");
	for (int i = 31; i>= 0; i--){                                      //цикл на бинарный вывод 
		printf("%d", ((int)rezult >> i) % 2); 
		if (i % 8 == 0) { printf("  "); }
	}
	}
	else if (znak == '-') {                                     //продолжение преведущего
		rezult = perv - vtor; printf("%g\n",rezult);
		
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}

	}
	else if (znak == '*') {
		rezult = perv * vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '/') {
		rezult = perv / vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\n This program cannot yet calculate the value (BIN and HEX). Wait for the update ");
	}
	else if (znak == '%') {
		rezult = (int)perv % (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '&') {
		rezult = (int)perv & (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '^') {
		rezult = (int)perv ^ (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '|') {
		rezult = (int)perv | (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}

	}
	return;
}





int main(){
	
	
	
	int perv=0, vtor=0 ;
	unsigned char znak,vvod_perv,vvod_vtor;




	printf("Universal calculator\n");
	printf("Sintax: VALUE SIGN VALUE EQUAL >\n");

	for (int i = 0; i <= 20; i++) {
		printf("Н");
		if (i == 20) printf("\n");
	}

	printf("VALUE: any int namberic value\n");
	printf("SIGN: +, -, %%, /, *, &, ^, |\n");
	printf("EQUAL: =\n");
for (int i = 0; i <= 20; i++) {
	printf("Н");
	if (i == 20) printf("\n");            // Вывод на консоль шапки и инструкции
}




	for (;;) {
		vvod_perv = getch();
		if (vvod_perv >= '0' && vvod_perv <= '9' ) 
		{
			printf("%c", vvod_perv);
			perv =perv*10+( vvod_perv-48);

		}
		else if (vvod_perv == '+' || vvod_perv == '-' || vvod_perv == '*' || vvod_perv == '/' || vvod_perv == '%' || vvod_perv == '&' || vvod_perv == '^' || vvod_perv == '|')
		{
			printf("%c", vvod_perv);
			znak = vvod_perv;
			break;
		}
		else if (vvod_perv == 'x')
		{
			break;
		}
		else
		{
			continue;
		}                                 //Ввод первого числа и знака операции
	}



	for (;;) {
		vvod_vtor = getch();
		if (vvod_vtor >= '0' && vvod_vtor <= '9') {
			printf("%c", vvod_vtor);
			vtor = vtor * 10 + (vvod_vtor - 48);

		}
		else if (vvod_vtor == '=' ) {
			printf("%c",vvod_vtor);
			break;
		}
		else if (vvod_perv == 'x')
		{
			break;
		}
		else
		{
			continue;

		}                                 //Ввод второго числа и знака равно


	}
	znacenie(perv, znak, vtor);     

	_getch();
	
}

#include<stdio.h>


void printInstruction();
void printLine();
void printZnacenie(int perv, unsigned char znak, int vtor);
void printHexBin(int rezult);
void printHexBin1(double result);

int main() {

	int perv = 0, vtor = 0;
	unsigned char znak, vvod_perv, vvod_vtor;

	printInstruction();

	//Ввод первого числа и знака операции
	for (;;) {
		vvod_perv = getch();
		if (vvod_perv >= '0' && vvod_perv <= '9')
		{
			printf("%c", vvod_perv);
			perv = perv * 10 + (vvod_perv - 48);
		}
		else if (vvod_perv == '+' || vvod_perv == '-' || vvod_perv == '*' || vvod_perv == '/' || vvod_perv == '%' || vvod_perv == '&' || vvod_perv == '^' || vvod_perv == '|')
		{
			printf("%c", vvod_perv);
			znak = vvod_perv;
			break;
		}
		else
		{
			continue;
		}                                 
	}


	//Ввод второго числа и знака равно
	for (;;) {
		vvod_vtor = getch();
		if (vvod_vtor >= '0' && vvod_vtor <= '9') {
			printf("%c", vvod_vtor);
			vtor = vtor * 10 + (vvod_vtor - 48);

		}
		else if (vvod_vtor == '=') {
			printf("%c", vvod_vtor);
			break;
		}
		else
		{
			continue;

		}                                
	}

	printZnacenie(perv,znak,vtor);


	getch();
}

//вывод линии
void printLine() {

for (int i = 0; i <= 20; i++) {
		printf("Н");
		if (i == 20) printf("\n");
	}
}

// Вывод на консоль шапки и инструкции
void printInstruction() {

	printf("Universal calculator\n");
	printf("Sintax: VALUE SIGN VALUE EQUAL >\n");

	printLine();

	printf("VALUE: any int namberic value\n");
	printf("SIGN: +, -, %%, /, *, &, ^, |\n");
	printf("EQUAL: =\n");
	
	printLine();
}


	void printZnacenie(int perv, unsigned char znak, int vtor) {
	
		int rezult;
		double rezult1;

		switch (znak)
		{
		case '+':                                                 
			rezult = perv + vtor;
			printf("%d\n", rezult);	

			printLine();
			printHexBin(rezult);
			break;
		case '-':
			rezult = perv - vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		case '*':
			rezult = perv * vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		case '/':
			rezult1 = (double)perv / (double)vtor;
			printf("%g\n", rezult1);

			printLine();
			printHexBin1(rezult1);
			break;
		case '%':
			rezult = perv % vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		case '&':
			rezult = perv & vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		case '|':
			rezult = perv | vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		case '^':
			rezult = perv ^ vtor;
			printf("%d\n", rezult);

			printLine();
			printHexBin(rezult);
			break;
		}
	
		}

	void printHexBin(double rezult) {
		 //выводит в HEX
		printf("\nHEX: %08X\n", rezult);    

		//цикл на бинарный вывод
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {                                    
			printf("%d", ((unsigned int)rezult >> i) % 2);

			if (i % 8 == 0) {
				printf("  "); }


		}
	}

	//вывод при делении
	void printHexBin1(double result) {

		long long ptr = *(long long*)&result;
		printf("HEX: %llX", ptr);
		printf("\nBIN: ");

		for (int i = 63; i >= 0; i--) {
			printf("%d",( ptr >> i) % 2);

			if (i % 8 == 0) {
				printf(" ");
			}
		}
	}
#include "stdio.h"
#include "math.h"
#include "windows.h"

#define White         15;


int mathOperation(int mathSign, int firstNumber, int secondNumber) {
	if (mathSign == '+') return firstNumber + secondNumber;
	else if (mathSign == '-') return firstNumber - secondNumber;
	else if (mathSign == '*') return firstNumber * secondNumber;
	else if (mathSign == '/') return (double)firstNumber / secondNumber;
	else if (mathSign == '%') return firstNumber % secondNumber;
	else if (mathSign == '^') return firstNumber ^ secondNumber;
	else if (mathSign == '|') return firstNumber | secondNumber;
	else return firstNumber & secondNumber;
	return 0;
}

void HexAndBin(double Res);

int main() {
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	int firstDigit, secondDigit, mathSign, firstNumber = 0, secondNumber = 0, Res;

	printf_s("  Universal calculator...\n"
			 "  Syntax: VALUE SIGN VALUE EQUAL\n"
			 "----------------------------------------\n"
			 "   VALUE: any numeric value\n"
			 "    SIGN: +, -, / , *, %%, ^, | , &\n"
			 "   EQUAL: =\n"
			 "----------------------------------------\n"
			 "     EXP: ");
	do {
		int num = 0;
		firstDigit = getch();

		if (firstDigit >= '0' && firstDigit <= '9') {
			putchar(firstDigit);
			firstNumber = firstNumber * 10 + (firstDigit - 48);
		}
		if (firstNumber > 0 && (firstDigit == '-' || firstDigit == '+'
			|| firstDigit == '/' || firstDigit == '%' || firstDigit == '*'
			|| firstDigit == '^' || firstDigit == '|' || firstDigit == '&')) {

			putchar(firstDigit);
			mathSign = firstDigit;
			break;
		}
	} while (1);

	do {
		secondDigit = getch();

		if (secondDigit >= '0' && secondDigit <= '9') {
			putchar(secondDigit);

			secondNumber = secondNumber * 10 + (secondDigit - 48);
		}
		if (secondNumber > 0 && secondDigit == '=') {
			putchar(secondDigit);

			break;
		}

	} while (1);

	Res = mathOperation(mathSign, firstNumber, secondNumber);

	if (mathSign == '/') {
		printf_s("%.2lf", (double)firstNumber / secondNumber);
		printf_s("\n----------------------------------------\n");
		HexAndBin((double)firstNumber / secondNumber);
	}

	else {
		printf_s("%d", Res);
		printf_s("\n----------------------------------------"
			     "\nHEX: %.8X", Res);
		printf_s("\nBIN: ");
		toBinary(Res);
	}
	return 0;
}
int toBinary(int n) {

	for (int i = 31; i >= 0; i--) {
		int k = n >> i;
		if (i == 7) printf(" ");
		if (i == 15)printf(" ");
		if (i == 23)printf(" ");
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
}

void HexAndBin(double Res) {
	//Dubl data types - tak slojnaa

	long long convert = *(long long*)&Res;          // doljno bit 8 bite
	char* ptr = &convert;
	printf("HEX: ");
	for (int i = 7; i >= 0; i--) {
		printf("%.2X ", (unsigned char)ptr[i]);
	}

	printf("\n");

	// bin
	printf("BIN: ");                                

	for (int i = 63; i >= 0; i--) {
		int bin = (convert >> i) % 2;

		if (bin == -1) {
			printf("%d", -1 * bin);
		}

		else {
			printf("%d", bin);
		}

		if (i % 8 == 0) {
			printf("  ");
		}
	}

	printf("\n\n");
}
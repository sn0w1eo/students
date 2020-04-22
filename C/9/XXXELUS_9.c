#include "stdio.h"
#include "math.h"


void printHexAndBin(double result);


int main()
{
	int firstDig, secondDig, mathSign, firstNumber = 0, secondNumber = 0, Result;
	printf_s("Universal calculator...\n"
		"Syntax: VALUE SIGN VALUE EQUAL\n"
		"----------------------------------------\n"
		"   VALUE: any numeric value\n"
		"    SIGN: +, -, / , *, %%, ^, | , &\n"
		"   EQUAL: =\n"
		"----------------------------------------\n"
		"     EXP: ");
	do
	{
		int count = 0;
		firstDig = getch();
		if (firstDig >= '0' && firstDig <= '9')
		{
			putchar(firstDig);
			firstNumber = firstNumber * 10 + (firstDig - 48);
		}
		if (firstNumber > 0 && (firstDig == '-' || firstDig == '+'
			|| firstDig == '/' || firstDig == '%' || firstDig == '*'
			|| firstDig == '^' || firstDig == '|' || firstDig == '&'))
		{
			putchar(firstDig);


			mathSign = firstDig;
			break;
		}
	} while (1);

	do
	{
		secondDig = getch();
		if (secondDig >= '0' && secondDig <= '9')
		{
			putchar(secondDig);
			secondNumber = secondNumber * 10 + (secondDig - 48);
		}
		if (secondNumber > 0 && secondDig == '=')
		{
			putchar(secondDig);
			break;
		}
	} while (1);
	Result = mathOperation(mathSign, firstNumber, secondNumber);

	if (mathSign == '/')
	{
		printf_s("%.2lf", (double)firstNumber / secondNumber);
		printf_s("\n----------------------------------------\n");
		printHexAndBin((double)firstNumber / secondNumber);
	}
	else
	{
		printf_s("%d", Result);
		printf_s("\n----------------------------------------"

			"\nHEX: %.8X", Result);
		printf_s("\nBIN: ");
		decToBinary(Result);
	}
	return 0;
}
int decToBinary(int n)
{

	for (int i = 31; i >= 0; i--) {
		int k = n >> i;
		if (i == 7)printf(" ");
		if (i == 15)printf(" ");
		if (i == 23)printf(" ");
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
}
int mathOperation(int mathSign, int firstNumber, int secondNumber)
{
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

void printHexAndBin(double result) {
	long long convert = *(long long*)&result;
	char* ptr = &convert;
	printf("HEX: ");
	for (int i = 7; i >= 0; i--) 
	{
		printf("%.2X ", (unsigned char)ptr[i]);
	}
	printf("\n");
	printf("BIN: ");
	for (int i = 63; i >= 0; i--)
	{
		int bin = (convert >> i) % 2;
		if (bin == -1)
		{
			printf("%d", -1 * bin);
		}
		else
		{
			printf("%d", bin);
		}
		if (i % 8 == 0)
		{ 
			printf("  ");
		}
	}
	printf("\n\n");
}

#include "stdio.h"


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
		printf_s("\n----------------------------------------");
		printf_s("\nError");
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
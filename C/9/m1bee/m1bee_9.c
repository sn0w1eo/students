#include "stdio.h"
#include "conio.h"

void binConverter(int result)
{
	printf_s("\nBIN: ");
	for (int i = 31; i >= 0; i--)
	{
		(result >> i) % 2;
		printf_s("%d", result & (1 << i) ? 1 : 0);

		if (i % 8 == 0)
		{
			printf(" ");
		}
	}                                  //cycle for bin
}

void printHexBin(double result)
{
	long long ptr = *(long long*)&result;
	printf_s("\nHEX: %llX", ptr);
	printf_s("\nBIN: ");
	for (int i = 63; i >= 0; i--)
	{
		int bin = (ptr >> i) % 2;
		if (bin & 1)
		{
			printf_s("1");
		}
		else
		{
			printf_s("0");
		}
		if (i % 8 == 0)
		{
			printf_s(" ");
		}
	}
}

void operate(int num1, int num2, unsigned char sign)
{
	int result;
	switch (sign)
	{
	case '+':
		result = num1 + num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '-':
		result = num1 - num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '*':
		result = num1 * num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '%':
		result = num1 % num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '^':
		result = num1 ^ num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '|':
		result = num1 | num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result);
		break;

	case '&':
		result = num1 & num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		binConverter(result); 
		break;   
		
	case '/':
		double result;
		result = (double)num1 / (double)num2;
		printf_s("%g", result);
		printHexBin(result);
		break;                                     // operations that we use
	}
}

int main()
{
	printf_s("Welcome to Universal calculator...\n");
	printf_s("Syntax: VALUE SIGN VALUE EQUAL\n");
	printf_s("-------------------------------------------\n");
	printf_s("Value: any numeric value\n");
	printf_s("Sign: +, -, /, *, %%, ^, |, &\n");
	printf_s("Equal: =\n");
	printf_s("--------------------------------------------\n");
	printf_s("EXP:");                  // text

	unsigned char amount1, amount2, sign;
	double num1 = 0, num2 = 0, result;
	do {
		amount1 = _getch();
		if (amount1 >= '0' && amount1 <= '9')
		{
			putchar(amount1);
			num1 = num1 * 10 + (amount1 - 48);
		}
		if (num1 > 0 && (amount1 == '+' || amount1 == '-'
			|| amount1 == '/' || amount1 == '*' || amount1 == '%'
			|| amount1 == '^' || amount1 == '|' || amount1 == '&'))
		{
			putchar(amount1);
			sign = amount1;
			break;
		}
	} while (1);                 //first number and sign

	do {
		amount2 = _getch();
		if (amount2 >= '0' && amount2 <= '9')
		{
			putchar(amount2);
			num2 = num2 * 10 + (amount2 - 48);

		}
		if (num2 > 0 && (amount2 == '='))
		{
			putchar(amount2);
			break;
		}
	} while (1);                 //second number and equal
	operate(num1, num2, sign);
	return 0;
}

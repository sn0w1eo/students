#include "stdio.h"
#include "conio.h"

void converter(int result)
{
	printf_s("BIN: ");
	for (int i = 31; i >= 0; i--)
	{
		(result >> i) % 2;
		printf_s("%d", result&(1<<i) ? 1 : 0);
	
		if (i % 8 == 0)
		{
			printf("  ");
		}
	}                                  //cycle for bin
}                              

void operate(int num1, int num2, unsigned char sign)
{
	int result;
	if (sign == '+')
	{
		result = num1 + num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '-')
	{
		result = num1 - num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '/')
	{
		float result;
		result = (float)num1 / (float)num2;
		printf_s("%.1f", result);
		printf_s("\nNO HEX AND BINARY AVAILABLE YET FOR DIVISION OPERATIONS");
	}
	else if (sign == '*')
	{
		result = num1 * num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '%')
	{
		result = num1 % num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '^')
	{
		result = num1 ^ num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '|')
	{
		result = num1 | num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}
	else if (sign == '&')
	{
		result = num1 & num2;
		printf_s("%d\n", result);
		printf_s("HEX: %.8X\n", result);
		converter(result);
	}                                     // operations that we use
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
	float num1 = 0, num2 = 0;
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

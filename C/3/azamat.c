#include "stdio.h"
int Working(int begin, int num1, int num2)
{
	if (begin == '-')return num1 - num2;
	else if (begin == '+')return num1 + num2;
	else if (begin == '*')return num1 * num2;
	else if (begin == '|')return num1 | num2;
	else if (begin == '%')return num1 % num2;
	else if (begin == '^')return num1 ^ num2;
	else if (begin == '&')return num1 & num2;

}
int main()
{
	printf_s("Universal calculator...\n"
		"Syntax: VALUE SIGN VALUE EQUAL\n"
		"----------------------------------------\n"
		"   VALUE: any numeric value\n"
		"    SIGN: +, -, / , *, %%, ^, | , &\n"
		"   EQUAL: =\n"
		"----------------------------------------\n"
		"     EXP: ");
	int nnum1, nnum2, begin, result, num1 = 0, num2 = 0;
	do
	{
		int num = 0;
		nnum1 = getch();
		if (nnum1 >= '0' && nnum1 <= '9')
		{
			putchar(nnum1);
			num1 = num1 * 10 + (nnum1 - 48);
		}
		if (num1 > 0 && (nnum1 == '-' || nnum1 == '+'
			|| nnum1 == '/' || nnum1 == '%' || nnum1 == '*'
			|| nnum1 == '^' || nnum1 == '|' || nnum1 == '&'))
		{
			putchar(nnum1);



			begin = nnum1;
			break;
		}
	} while (1);
	do
	{
		nnum2 = getch();
		if (nnum2 >= '0' && nnum2 <= '9')
		{
			putchar(nnum2);
			num2 = num2 * 10 + (nnum2 - 48);

		}
		if (num2 > 0 && nnum2 == '=')
		{
			putchar(nnum2);
			break;
		}

	} while (1);


	result = Working(begin, num1, num2);
	if (begin == '/')
	{
		printf_s("%.2lf", (double)num1 / num2);
		printf_s("\nMdaa molodoy");
		printf_s("\nbad idea");

	}
	else
	{
		printf_s("%d", result);
		printf_s("\n----------------------------------------"


			"\nHEX: %.8X", result);
		printf_s("\nBIN: ");
		binary(result);
	}
	return 0;
}

int binary(unsigned int b)
{

	for (int i = 31; i >= 0; i--)
	{
		int a = b >> i;
		if (i == 7)printf(" ");
		if (i == 15)printf(" ");
		if (i == 23)printf(" ");
		if (a & 1)
			printf("1");
		else
			printf("0");

	}return 0;
}

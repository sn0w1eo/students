#include "stdio.h"

int working(int begin, int Num1, int Num2);
void printHEXandBIN(double result);

int main()
{
	printf_s(
		"Universal Calculator...\n"
		"Syntax: Value sign value equal\n"
		"----------------------------------------\n"
		"   Value: Any numeric value\n"
		"    Sign: +, -, / , *, %%, ^, | , &\n"
		"   Equal: =\n"
		"----------------------------------------\n"
		"     Exp: ");


    int digitNum1,digitNum2, Begin, Result;
	double Num1 = 0, Num2 = 0;

	do
	{
		int num = 0;
		digitNum1 = getch();
		if (digitNum1 >= '0' && digitNum1 <= '9')
		{
			putchar(digitNum1);
			Num1 = Num1 * 10 + (digitNum1 - 48);
		}
		if (Num1 > 0 && (digitNum1 == '-' || digitNum1 == '+'
			|| digitNum1 == '/' || digitNum1 == '%' || digitNum1 == '*'
			|| digitNum1 == '^' || digitNum1 == '|' || digitNum1 == '&'))
		{
			putchar(digitNum1);
			Begin = digitNum1;
			break;
		}
	} while (1);


	do
	{
		digitNum2 = getch();
		if (digitNum2 >= '0' && digitNum2 <= '9')
		{
			putchar(digitNum2);
			Num2 = Num2 * 10 + (digitNum2 - 48);
		}
		if (Num2 > 0 && digitNum2 == '=')
		{
			putchar(digitNum2);
			break;
		}

	} while (1);


	Result = working(Begin, Num1, Num2);
	if (Begin == '/')
	{
		printf_s("%.2lf", Num1 / Num2);
		printHEXandBIN(Num1 / Num2);

	}
	else
	{
		printf_s("%d", Result);
		printf_s("\n----------------------------------------"
		"\nHex: %.8x", Result);
		printf_s("\nBin: ");
		binary(Result);
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
int working(int begin, int num1, int num2)
{
	if      (begin == '-')return num1 - num2;
	else if (begin == '+')return num1 + num2;
	else if (begin == '*')return num1 * num2;
	else if (begin == '|')return num1 | num2;
	else if (begin == '%')return num1 % num2;
	else if (begin == '^')return num1 ^ num2;
	else if (begin == '&')return num1 & num2;

}
void printHEXandBIN(double result)
 {
	long long pointer = *(long long*)&result;
	printf_s("\nHex: %llx", pointer);
	printf_s("\nBin: ");
	for (int i = 63; i >= 0; i--)
	{
	    int bin = (pointer >> i) % 2;
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

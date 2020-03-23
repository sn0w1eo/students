#include "stdio.h"
//vse nashi operacii
double Calculate(unsigned char sign, int value1, int value2)
{
	if (sign == '+')
	{
		return value1 + value2;
	}
	else if (sign == '-')
	{
		return value1 - value2;
	}
	else if (sign == '*')
	{
		return value1 * value2;
	}
	else if (sign == '%')
	{
		return value1 % value2;
	}
	else if (sign == '^')
	{
		return value1 ^ value2;
	}
	else if (sign == '|')
	{
		return value1 | value2;
	}
	else
	{
		return value1 & value2;
	}

	return 0;
}
//vyvodim nachalnyi text
int main()
{
	printf("Universal calculator...");
	printf("\nSyntax: VALUE SIGN VALUE EQUAL");
	printf("\n----------------------------------------");
	printf("\n  VALUE: any numeric value");
	printf("\n   SIGN: +, -, /, *, %%, ^, |, &");
	printf("\n  EQUAL: =");
	printf("\n----------------------------------------");
	printf("\nEXP:");

	unsigned char digitOfValue1, digitOfValue2, Sign;
	double value1 = 0, value2 = 0, result;
	int i, bin;
	//tut zapishem pervoe chislo
	do
	{
		digitOfValue1 = getch();
		if (digitOfValue1 >= '0' && digitOfValue1 <= '9')
		{
			putchar(digitOfValue1);
			value1 = value1 * 10 + (digitOfValue1 - 48);
		}
		if (value1 > 0 && (digitOfValue1 == '-' || digitOfValue1 == '+'
			|| digitOfValue1 == '/' || digitOfValue1 == '%' || digitOfValue1 == '*'
			|| digitOfValue1 == '^' || digitOfValue1 == '|' || digitOfValue1 == '&'))
		{
			putchar(digitOfValue1);
			//zapisali sign
			Sign = digitOfValue1;
			break;
		}
	} while (1);
	//zapisali vtoroe chislo
	do
	{
		digitOfValue2 = getch();
		if (digitOfValue2 >= '0' && digitOfValue2 <= '9')
		{
			putchar(digitOfValue2);
			value2 = value2 * 10 + (digitOfValue2 - 48);
		}
		if (value2 > 0 && digitOfValue2 == '=')
		{
			putchar(digitOfValue2);
			break;
		}
	} while (1);
	result = Calculate(Sign, value1, value2);
	if (Sign == '/')
	{
		printf_s("%.3lf", (double)value1 / (double)value2);
		printf_s("\n----------------------------------------");
		printf_s("\nNO HEX AND BINARY AVAILABLE YET FOR DIVISION OPERATIONS");
	}
	else
	{
		printf("%.lf", result);
		printf_s("\n----------------------------------------");
		printf_s("\nHEX: %.8X", (int)result); //vyvod hex
		//tsikl na bin
		printf_s("\nBIN: ");
		for (i = 31; i >= 0; i--)
		{
			bin = (int)result >> i;
			if (i == 7 || i == 15 || i == 23)
			{
				printf(" ");

			}
			if (bin & 1)
			{
				printf("1");
			}
			else
			{
				printf("0");
			}

		}


	}
	return 0; //vsem spasibo za prosmotr
}
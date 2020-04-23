#include "stdio.h"
#include "conio.h"

void Line(symbol)
{
	puts("ДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДД");
}

void Condition(key)
{
	puts("Universal calculator...\nSytax:VALUE SIGN VALUE EQUAL>");
	Line("symbol");
	puts("VALUE: ANY NUMERIC VALUE\n SIGN: +, -, /, *, %, ^, |, &\nEQUAL: =");
	Line("symbol");
	printf("  EXP: ");
}

int BIN(int n)
{
	printf("  BIN: ");
	for (int i = 31; i >= 0; i--)
	{
		int k = n >> i;
		if (i == 7 || i == 15 || i == 23)printf(" ");
		if (k & 1)
			printf("1");
		else
			printf("0");
	}
	return 0;
}

void operationofDivision(double resultofDivision)
{
	unsigned char *ptr = (unsigned char*) & resultofDivision;
	printf("HEX: ");
	for (int i = 7; i >= 0; i--)
	{

		if (ptr[i] == 0)
		{
			printf("00 ");
		}

		else
		{
			printf("%.2x ", ptr[i]);
		}

	}
	printf("\nBIN: ");
	for (int i = 7; i >= 0; i--)
	{
		if (ptr[i] == 0)
		{
			printf("00000000 ");
		}
		else
		{
			for (int j = 7; j >= 0; j--)
			{
				if (j == 7)
				{
					printf("%d", ptr[i] >> j);
				}

				else if (j == 0)
				{
					printf("%d", ptr[i] % 2);
				}

				else
				{
					printf("%d", (ptr[i] >> j) % 2);
				}

			}
			printf(" ");
		}
	}
}

int Operations(unsigned char ch3, int firstvalue, int secondvalue)
{
	int result;
	if (ch3 == '+')
	{
		result = firstvalue + secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '-')
	{
		result = firstvalue - secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '/')
	{
		double resultofDivision;
		resultofDivision = (double)firstvalue / (double)secondvalue;
		printf("%.2lf\n", resultofDivision);
		Line("symbol");
		operationofDivision(resultofDivision);
	}

	else if (ch3 == '%')
	{
		result = firstvalue % secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '*')
	{
		result = firstvalue * secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '^')
	{
		result = firstvalue ^ secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '|')
	{
		result = firstvalue | secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}

	else if (ch3 == '&')
	{
		result = firstvalue & secondvalue;
		printf("%d\n", result);
		Line("symbol");
		printf("  HEX: %.8X\n", result);
		BIN(result);
	}
	return 0;
}

int main()
{
	unsigned char firstnumsign;
	Condition("key");
	int secndnum = 0;
	int firstnum = 0;
	do {
		unsigned char ch;
		ch = _getch();
		if (ch >= '0' && ch <= '9')
		{
			putchar(ch);
			firstnum = firstnum * 10 + (ch - 48);
		}

		else if (firstnum > 0 && (ch == '-' || ch == '+'
			|| ch == '/' || ch == '%' || ch == '*'
			|| ch == '^' || ch == '|' || ch == '&'))
		{
			putchar(ch);
			firstnumsign = ch;
			break;
		}

	} while (1);

	do {
		unsigned char ch2;
		ch2 = _getch();

		if (ch2 >= '0' && ch2 <= '9')
		{
			putchar(ch2);
			secndnum = secndnum * 10 + (ch2 - 48);
		}

		else if (secndnum > 0 && (ch2 == '='))
		{
			putchar(ch2);
			break;
		}

	} while (1);

	Operations(firstnumsign, firstnum, secndnum);
}
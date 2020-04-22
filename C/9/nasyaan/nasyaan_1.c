#include "stdio.h"
#include "windows.h"

#define RED			0x0C //красный
#define WHITE		0x07 //белый
#define LIGHTBLUE	0x0B //светло-голубой
#define YELLOW		0x06 //жёлтый

void setColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//vse nashi operacii
int Calculate(int sign, int value1, int value2)
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
	
	unsigned char digitOfValue1, digitOfValue2, sign;
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
			sign = digitOfValue1;
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
	result = Calculate(sign, value1, value2);

	if (sign == '/')
	{
		int binary;
		result = (double)value1 / (double)value2;
		long long hexAndBin = *(long long*) &result; //privodim k tipu 8 byte
		printf_s("%.3lf", result);
		printf_s("\n----------------------------------------");
		setColor(YELLOW);
		printf_s("\nHEX: ");
		printf_s("%llX", hexAndBin); //raspechativaem hex
		setColor(LIGHTBLUE);
		//raspechativaem bin
		printf_s("\nBIN:");
		for (i = 63; i >= 0; i--)
		{
			binary = hexAndBin >> i;
			if (i % 8 == 7) 
			{
				printf(" ");

			}
			if (binary & 1)
			{
				setColor(LIGHTBLUE);
				printf("1");
				setColor(WHITE);
			}
			else
			{
				setColor(RED);
				printf("0");
				setColor(WHITE);
			}
		}
	}
	else
	{
		printf("%.lf", result);
		printf_s("\n----------------------------------------");
		setColor(YELLOW);
		printf_s("\nHEX: %.8X", (int)result); //vyvod hex
		setColor(LIGHTBLUE);
		printf_s("\nBIN: ");
		//tsikl na bin
		for (i = 31; i >= 0; i--)
		{
			bin = (int)result >> i;
			if (i == 7 || i == 15 || i == 23)
			{
				printf(" ");

			}
			if (bin & 1)
			{
				setColor(LIGHTBLUE);
				printf("1");
				setColor(WHITE);
			}
			else
			{
				setColor(RED);
				printf("0");
				setColor(WHITE);
			}

		}


	}
	return 0; //vsem spasibo za prosmotr
}
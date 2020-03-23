#include "stdio.h"
//фунция возвращает результат в зависимости от переданного ей оператора 
int DoOperation(int operatorSign, int firstNumber, int secondNumber)
{
	if (operatorSign == '+') return firstNumber + secondNumber;
	else if (operatorSign == '-') return firstNumber - secondNumber;
	else if (operatorSign == '*') return firstNumber * secondNumber;
	/*else if (operatorSign == '/') return (double)firstNumber / secondNumber;*/
	else if (operatorSign == '%') return firstNumber % secondNumber;
	else if (operatorSign == '^') return firstNumber ^ secondNumber;
	else if (operatorSign == '|') return firstNumber | secondNumber;
	else return firstNumber & secondNumber;
	return 0;
}
int main()
{
	int frstNumDigit, scndNumDigit, operatorSign, firstNumber = 0, secondNumber = 0, operationResult;
	printf_s("Universal calculator...\n"
		"Syntax: VALUE SIGN VALUE EQUAL\n"
		"----------------------------------------\n"
		"   VALUE: any numeric value\n"
		"    SIGN: +, -, / , *, %%, ^, | , &\n"
		"   EQUAL: =\n"
		"----------------------------------------\n"
		"     EXP: ");
	//запись первого числа
	do
	{
		int count = 0;
		frstNumDigit = getch();
		if (frstNumDigit >= '0' && frstNumDigit <= '9')
		{
			putchar(frstNumDigit);
			firstNumber = firstNumber * 10 + (frstNumDigit - 48);
		}
		if (firstNumber > 0 && (frstNumDigit == '-' || frstNumDigit == '+'
			|| frstNumDigit == '/' || frstNumDigit == '%' || frstNumDigit == '*'
			|| frstNumDigit == '^' || frstNumDigit == '|' || frstNumDigit == '&'))
		{
			putchar(frstNumDigit);

			//запись знака мат. операции в память
			operatorSign = frstNumDigit;
			break;
		}
	} while (1);
	//запись второго числа
	do
	{
		scndNumDigit = getch();
		if (scndNumDigit >= '0' && scndNumDigit <= '9')
		{
			putchar(scndNumDigit);
			secondNumber = secondNumber * 10 + (scndNumDigit - 48);
		}
		if (secondNumber > 0 && scndNumDigit == '=')
		{
			putchar(scndNumDigit);
			break;
		}
	} while (1);
	//вызов функции калькулятора
	operationResult = DoOperation(operatorSign, firstNumber, secondNumber);
	//вывод результата опирации в зависимости от оператора
	if (operatorSign == '/')
	{
		printf_s("%.2lf", (double)firstNumber / secondNumber);
		printf_s("\n----------------------------------------");
		printf_s("\nNO HEX AND BINARY AVAILABLE YET FOR DIVISION OPERATIONS");
	}
	else
	{
		printf_s("%d", operationResult);
		printf_s("\n----------------------------------------"
			//вывод в HEX
			"\nHEX: %.8X", operationResult);
		//вывод в BIN
		printf_s("\nBIN: ");		
		for (int i = 31; i >= 0; i--)
		{
			int bin;
			bin = (operationResult >> i) % 2;
			if (bin == -1) printf("%d", -1 * bin);
			else printf("%d", bin);
			if (i % 8 == 0) printf("  ");
		}
	}
	return 0;
}
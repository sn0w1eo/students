#include "stdio.h"
//фунция возвращает результат взависимости от переданного ей оператора 
int DoOperation(unsigned char operatorSign, int firstNumber, int secondNumber)
{	
	if(operatorSign== '+') return firstNumber + secondNumber;
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
		if (firstNumber > 0  && (frstNumDigit == '-' || frstNumDigit == '+'
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
		printf_s("%.2lf", (double)firstNumber/secondNumber);
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
		//счётчик цикла
		int count = 31;
		while (count>=0)
		{
			if (operationResult >> count & 1) printf_s("1");			
			else printf_s("0");
			if (count == 24 || count == 16 || count == 8) printf_s(" ");
			count--;
		}		
	}
	return 0;
}
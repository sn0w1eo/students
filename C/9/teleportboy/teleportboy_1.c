#include "stdio.h"

//фунция возвращает результат в зависимости от переданного ей оператора 
void DoOperation(int operatorSign, int* operatorResult, int firstNumber, int secondNumber);

///два варианта бинарника
//вывести в бинарном виде
void PrintBinary(double result);
//вывести в бинарном виде
void PrintBinary2(double result);

//вывести в хексе
void PrintHex(double result);


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
	

	
	if (operatorSign == '/')
	{		
		double result = (double)firstNumber / (double)secondNumber;
		printf_s("%.3lf", result);

		PrintBinary(result);

		PrintHex(result);
	}
	
	
	else
	{
		int bin;
		DoOperation(operatorSign, &operationResult, firstNumber, secondNumber);
		//вывод результата опирации в зависимости от оператора

		printf_s("%d", operationResult);
		printf_s("\n----------------------------------------"
			//вывод в HEX
			"\nHEX: %.8X", operationResult);
		//вывод в BIN
		printf_s("\nBIN: ");
		for (int i = 31; i >= 0; i--)
		{			
			bin = (operationResult >> i) % 2;
			if (bin == -1) printf("%d", -1 * bin);
			else printf("%d", bin);
			if (i % 8 == 0) printf("  ");
		}
	}

	
	return 0;
}

//выполнить мат. операцию
void DoOperation(int operatorSign, int* operatorResult, int firstNumber, int secondNumber)
{
	switch (operatorSign)
	{
	case '+': *operatorResult = firstNumber + secondNumber;
		break;
	case '-': *operatorResult = firstNumber - secondNumber;
		break;
	case '*': *operatorResult = firstNumber * secondNumber;
		break;
	case '%': *operatorResult = firstNumber % secondNumber;
		break;
	case '^': *operatorResult = firstNumber ^ secondNumber;
		break;
	case '|': *operatorResult = firstNumber | secondNumber;
		break;
	case '&': *operatorResult = firstNumber & secondNumber;
		break;
	}
}


void PrintBinary(double result)
{
	int bin;	
	//адресс результата деления
	unsigned char* byte = &result;

	printf_s("\n     BIN: ");
	for (int i = 0; i <= 7; i++)
	{
		for (int j = 7; j >= 0; j--)
		{
			bin = (byte[7 - i] >> j) % 2;
		    if (bin == -1) printf("%d", -1 * bin);
		    else printf("%d", bin);

		}
		printf_s(" ");
	}


}

void PrintBinary2(double result)
{
	int bin;
	//запись числа с плавающей запятой, как целое десятичное	
	long long int res = *(long long int*)&result;	   //(хуета)
	
	printf_s("\n     BIN: ");
	for (int i = 63; i >= 0; i--)
	{		
		bin = ((res) >> i) % 2;
		/*if (bin == -1) printf("%d", -1 * bin);*/
		/*else*/ printf("%d", bin);
		if (i % 8 == 0) printf("  ");
	}
}

void PrintHex(double result)
{
	//адресс результата деления
	unsigned char* byte = &result;

	//вывод результата в хексе побайтово 
	printf_s("\n     HEX: ");
	for (int i = 7; i >= 0; i--)
	{
		printf_s("%.2X ", byte[i]);
	}
}


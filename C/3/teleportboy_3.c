#include "stdio.h"
//фунция возвращает результат взависимости от переданного ей оператора 
double DoOperation(unsigned char operatorSign,double firstNumber, double secondNumber)
{	
	switch (operatorSign)
	{
	case '+': return firstNumber + secondNumber; break;
	case '-': return firstNumber - secondNumber; break;
	case '*': return firstNumber * secondNumber; break;
	case '/': return firstNumber / secondNumber; break;
	case '%': return (int)firstNumber % (int)secondNumber; break;
	case '^': return (int)firstNumber ^ (int)secondNumber; break;
	case '|': return(int)firstNumber | (int)secondNumber; break;
	case '&': return (int)firstNumber & (int)secondNumber; break;
	default: break;
	}	
	return 0;
}
int main()
{		
	unsigned char frstNumDigit, scndNumDigit, operatorSign;	
	double firstNumber=0, secondNumber=0, operationResult;
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
			printf_s("%.2lf", operationResult);
			printf_s("\n----------------------------------------");
			printf_s("\nNO HEX AND BINARY AVAILABLE YET FOR DIVISION OPERATIONS");
		}
		else
		{
			printf_s("%.lf", operationResult);
			printf_s("\n----------------------------------------"
			//вывод в HEX
				"\nHEX: %.8X", (int)operationResult);
			//вывод в BIN
			printf_s("\nBIN: %d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d "
				"%d%d%d%d%d%d%d%d %d%d%d%d%d%d%d%d",
				(int)operationResult >> 31, ((int)operationResult >> 30) % 2,
				((int)operationResult >> 29) % 2, ((int)operationResult >> 28) % 2, ((int)operationResult >> 27) % 2,
				((int)operationResult >> 26) % 2, ((int)operationResult >> 25) % 2, ((int)operationResult >> 24) % 2,
				((int)operationResult >> 23) % 2, ((int)operationResult >> 22) % 2,
				((int)operationResult >> 21) % 2, ((int)operationResult >> 20) % 2, ((int)operationResult >> 19) % 2,
				((int)operationResult >> 18) % 2, ((int)operationResult >> 17) % 2, ((int)operationResult >> 16) % 2,
				((int)operationResult >> 15) % 2, ((int)operationResult >> 14) % 2,
				((int)operationResult >> 13) % 2, ((int)operationResult >> 12) % 2, ((int)operationResult >> 11) % 2,
				((int)operationResult >> 10) % 2, ((int)operationResult >> 9) % 2, ((int)operationResult >> 8) % 2,
				((int)operationResult >> 7) % 2, ((int)operationResult >> 6) % 2,
				((int)operationResult >> 5) % 2, ((int)operationResult >> 4) % 2, ((int)operationResult >> 3) % 2,
				((int)operationResult >> 2) % 2, ((int)operationResult >> 1) % 2, (int)operationResult % 2);
			printf_s("\n----------------------------------------");
		}
		return 0;
}
#include "stdio.h"
#include "stdlib.h"
#include <string.h>


//КТО СПИЗДИТ ТОТ ЛОХ (who spizdit that sucker)

//немного пояснил за код,в остальном все CTRL+C CTRL+V 
//P.S Сделал через If ,а не через switch , потому что Кирюха начал делать свитчом,что бы хоть шушут было отличие
int decToBinary(int n)
{
	
	for (int i = 31; i >= 0; i--) {
		int k = n >> i;
		if (i == 7)printf(" ");
		if (i == 15)printf(" ");
		if (i == 23)printf(" ");
		if (k & 1)
			printf( "1");
		else
			printf("0");
	}
}

int main()
{
	system("chcp 866>nul");
	decor();
	
	char inputSymbol;
	char firstNumberArray[10];
	char secondNumberArray[10];
	int secondNumber = 0, firstNumber = 0, Counter = 0;
	int result;
	do//пока 
	{
		inputSymbol = getch();
		if (inputSymbol >= '0' && inputSymbol <= '9' || inputSymbol == '+' || inputSymbol == '-' 
			|| inputSymbol == '*' || inputSymbol == '|' || inputSymbol == '/' || inputSymbol == '%' 
			|| inputSymbol == '&' || inputSymbol == '^')// Если вводится один из символов
		{
		
			putchar(inputSymbol);//печатаем
			if (inputSymbol >= '0' && inputSymbol <= '9')
			{
				firstNumberArray[Counter] = inputSymbol;//массив куда идут цифры первого числа
				firstNumber = atoi(firstNumberArray);//Конвертим цифры в число
				
			}
			Counter++;
		}
	} while ((inputSymbol) != '+' && (inputSymbol) != '-' && (inputSymbol) != '*' && (inputSymbol) != '/' && (inputSymbol) != '%' && (inputSymbol) != '&' && (inputSymbol) != '|' && (inputSymbol) != '^');

	Counter = 0;
	
		if (inputSymbol == '+') {//ecли встречаем знак ,то начинаем записывать 2е 
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;//массив второго числа
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');//выполняем действие что сверху пока не наткнемся на =
			if (inputSymbol == '=')//если жмякнули = то выводим
			{
				result = (double)firstNumber + secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
				
			}
		}
		//Остальное все аналогично
		if (inputSymbol == '-') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = (double)firstNumber - secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '*') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = (double)firstNumber * secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '/') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				double result = (double)firstNumber / (double)secondNumber;
				printf_s("=%.2f\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '%') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = firstNumber % secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '^') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = firstNumber ^ secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '|') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = firstNumber | secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
		if (inputSymbol == '&') {
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');
			if (inputSymbol == '=')
			{

				result = firstNumber & secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
			}
		}
	
}

	int decor()
	{
		printf("░░░░░░░░░░▒▒▒▒▒▒▒▓▓▓▓ XXXELUS_CALC ▓▓▓▓▒▒▒▒▒▒▒░░░░░░░░░░\n"
		    "\nУниверсальный калькулятор...\n"
			"Синтаксис: ЗНАЧЕНИЕ ЗНАК ЗНАЧЕНИЕ РАВНО\n"
			"----------------------------------------\n"
			"Допустимые символы:\n"
			"     ЗНАЧЕНИЕ: любые числа\n"
			"     ЗНАК: + , - , / , * , % , ^ , | , & \n"
			"     РАВНО : =\n"
			"----------------------------------------\n"
			"     РЕШЕНИЕ: ");
	}
	
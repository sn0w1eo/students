#include "stdio.h"
#include "stdlib.h"
#include <string.h>


//��� ������� ��� ��� (who spizdit that sucker)

//������� ���᭨� �� ���,� ��⠫쭮� �� CTRL+C CTRL+V 
//P.S ������ �१ If ,� �� �१ switch , ��⮬� �� ����� ��砫 ������ ᢨ�箬,�� �� ��� ����� �뫮 �⫨稥
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
	do//���� 
	{
		inputSymbol = getch();
		if (inputSymbol >= '0' && inputSymbol <= '9' || inputSymbol == '+' || inputSymbol == '-' 
			|| inputSymbol == '*' || inputSymbol == '|' || inputSymbol == '/' || inputSymbol == '%' 
			|| inputSymbol == '&' || inputSymbol == '^')// �᫨ �������� ���� �� ᨬ�����
		{
		
			putchar(inputSymbol);//���⠥�
			if (inputSymbol >= '0' && inputSymbol <= '9')
			{
				firstNumberArray[Counter] = inputSymbol;//���ᨢ �㤠 ���� ���� ��ࢮ�� �᫠
				firstNumber = atoi(firstNumberArray);//������⨬ ���� � �᫮
				
			}
			Counter++;
		}
	} while ((inputSymbol) != '+' && (inputSymbol) != '-' && (inputSymbol) != '*' && (inputSymbol) != '/' && (inputSymbol) != '%' && (inputSymbol) != '&' && (inputSymbol) != '|' && (inputSymbol) != '^');

	Counter = 0;
	
		if (inputSymbol == '+') {//ec�� ����砥� ���� ,� ��稭��� �����뢠�� 2� 
			do
			{
				inputSymbol = getch();
				if (inputSymbol >= '0' && inputSymbol <= '9')
				{
					putchar(inputSymbol);
					if (inputSymbol >= '0' && inputSymbol <= '9')
					{
						secondNumberArray[Counter] = inputSymbol;//���ᨢ ��ண� �᫠
						secondNumber = atoi(secondNumberArray);
					}
					Counter++;
				}
			} while ((inputSymbol) != '=');//�믮��塞 ����⢨� �� ᢥ��� ���� �� ��⪭���� �� =
			if (inputSymbol == '=')//�᫨ ��節㫨 = � �뢮���
			{
				result = (double)firstNumber + secondNumber;
				printf_s("=%d\n"
					"HEX: %x\n"
					"BINARY:", result, result); decToBinary(result);
				
			}
		}
		//��⠫쭮� �� �������筮
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
		printf("��������������������� XXXELUS_CALC ���������������������\n"
		    "\n������ᠫ�� ��������...\n"
			"���⠪��: �������� ���� �������� �����\n"
			"----------------------------------------\n"
			"�����⨬� ᨬ����:\n"
			"     ��������: ��� �᫠\n"
			"     ����: + , - , / , * , % , ^ , | , & \n"
			"     ����� : =\n"
			"----------------------------------------\n"
			"     �������: ");
	}
	
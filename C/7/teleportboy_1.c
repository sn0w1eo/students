//AZA◆MI◆SLEDIM◆ZA◆TOBOI  

#include "stdio.h"
#include "stdlib.h"
#include"windows.h"

#define checkBit 0x01

int binCount = 0; //счётчик итераций для функции PrintBinary
int hexCount = 0; //счётчик итераций для функции PrintHexadecimal

void SetColor(int color);
void PrintHexadecimal(char text[]);
void PrintBinary(char text[]);
int main()
{
	char text[100];
	SetColor(8);
	printf_s("string: ");	
	scanf_s("%s",text,100);
	
	printf_s("\nBIN: ");
	PrintBinary(text);
	
	puts("");

	SetColor(8);
	printf_s("\nHEX: ");
	PrintHexadecimal(text);
}
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void PrintBinary(char text[])
{
	int bin;
	//итерировать пока не встретил \0 
	if (text[binCount] == '\0')
	{
		return;
	}

	for (int i = 7; i >= 0; i--)
	{
		bin = !!(checkBit & ((text[binCount] >> i)));
		if (bin == 1)
		{
			SetColor(10);
			printf_s("%d", bin);
		}
		else
		{
			SetColor(8);
			printf_s("%d", bin);
		}
	}
	printf_s("  ");

	binCount++;
	PrintBinary(text);
}
void PrintHexadecimal(char text[])
{
	SetColor(11);
	//итерировать пока не встретил \0 
	if (text[hexCount] == '\0')
	{
		return;
	}
	printf_s("%x ", text[hexCount]);

	hexCount++;
	PrintHexadecimal(text);
}
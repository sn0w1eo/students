#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "windows.h"

#define strLen 120

void setColor(int color);
int inHex(unsigned char str[]);
int inBin(unsigned char str[]);

int main()
{
	unsigned char str[strLen] = {0x00};
	printf("%s", "Write a line: " );
	scanf("%s", str);
	printf("HEX: ");
	inHex(str);
	setColor(7);
	printf("\nBIN: ");
	inBin(str);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int inHex(unsigned char str[]) 
{
	setColor(11);
	if (str[0] != 0)
	{
		printf("%x ", str[0]);
		inHex(str+1);
	}
}

int inBin(unsigned char str[])
{
	if (str[0]!= 0)
	{
		for (int i = 7; i >= 0; i--)
		{
			int k = str[0] >> i;
			if (k & 1)
			{
				setColor(14);
				printf("1");
			}
			else
			{
				setColor(7);
				printf("0");
			}
		}
		printf(" ");
		inBin(str + 1);
	}
}
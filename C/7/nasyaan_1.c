#include "stdio.h"
#include "windows.h"

 
//цвет
void color(color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//функция перевода строки в hex
void makeHex(char string[], int increment)
{
	color(11);
	if (string[increment] == '\0')
	{
		return;
	}
	printf("%x ", string[increment]);
	increment++;
	makeHex(string, increment);
	color(7);

}

//функция перевода строки в binary
void makeBinary(char string[], int binIncrement)
{
	if (string[binIncrement] == '\0')
	{
		return;
	}
	int bin;
	for (int i = 7; i >=0 ; i--)
	{
		bin = (string[binIncrement] >> i) % 2;
		
		if (bin == 1)
		{
			color(6);
			printf("%d", bin);
		}
		else
		{
			color(5);
			printf("%d", bin);
		}
		
	}
	color(8);
	printf(" ");
	binIncrement++;
	makeBinary(string, binIncrement);
}

int main()
{
	char string[100];
	printf("String: ");
	scanf_s("%s", string, 100);
	printf("HEX: ");
	makeHex(string, 0);
	printf("\nBIN: ");
	makeBinary(string, 0);
}
#include "stdio.h"
#include "windows.h"

int increment = 0; //индекс для функции hex
int binIncrement = 0; //индекс для функции binary

//цвет
void color(color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//функция перевода строки в hex
void makeHex(char string[100])
{
	color(11);
	if (string[increment] == '\0')
	{
		return;
	}
	printf("%x ", string[increment]);
	increment++;
	makeHex(string);
	color(7);

}

//функция перевода строки в binary
void makeBinary(char string[100])
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
	makeBinary(string);
}

int main()
{
	char string[100];
	printf("String: ");
	scanf_s("%s", string, 100);
	printf("HEX: ");
	makeHex(string);
	printf("\nBIN: ");
	makeBinary(string);
}
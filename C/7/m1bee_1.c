#include "stdio.h"
#include "windows.h"

void setColor(int color);
void toBin(unsigned char arr[]);
void toHex(unsigned char str[]);

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main()
{
	unsigned char string[50];
	printf_s("%s", "String, please: \n");
	scanf_s("%s", &string, 50);
	printf_s("your BIN: \n");
	toBin(string);
	setColor(7);       // white
	printf_s("\nyour HEX: \n");
	toHex(string);
}

void toBin(unsigned char arr[])  
{
	int result;
	if (arr[0] == '\0')
	{
		return;
	}
		for (int i = 7; i >= 0; i--)
		{
			result = (arr[0] >> i) % 2;
			if (result & 1)
			{
				setColor(2);         // green
				printf_s("1 ");      
			}
			else if (result == 0)
			{
				setColor(3);          // blue
				printf_s("0 ");
			}
		}
		toBin(arr + 1);
}

void toHex(unsigned char str[])
{
	setColor(3);                      // blue
	if (str[0] == '\0')
	{
		return;
	}
	printf_s("%x", str[0]);
	toHex(str + 1);
}

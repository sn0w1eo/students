#include "stdio.h"
#include "windows.h"

void stringToBin(char array[]);
void stringToHex(char array[]);
void color();

int globalIndexHex = 0;
int globalIndexBin = 0;

int main() 
{
	char inputString[255];
	memset(inputString, "\0", sizeof(inputString));
	 
	printf("Enter string:");
	gets(inputString);
	printf("\nHEX: ");
	stringToHex(inputString);
	printf("\nBINARY: ");
	stringToBin(inputString);

}

void stringToBin(char array[]) 
{
	if (array[globalIndexBin ] == '\0') {
		color(7);
		return 0;
	}
		for (int i = 7; i >= 0; i--) {
			int k = array[globalIndexBin] >> i;
			if (k & 1) 
			{
				color(15);
				printf("1");
			}
			else 
			{
				color(8);
				printf("0");
			}
		}
		globalIndexBin++;
		printf(" ");
		stringToBin(array);
	
	
	
}

void stringToHex(char array[]) 
{
	color(13);
	if (array[globalIndexHex] != 0x00) {
		printf("%x ", array[globalIndexHex]);
		globalIndexHex++;
		stringToHex(array);
	}
	color(7);
	return 0;
}

void color(color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
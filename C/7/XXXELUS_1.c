/*  ***********************************************
    **              By.XXXELUS                   **
	**                                           **
	**              WHO SPIZDIL                  **
	**               TOT PUSSY                   **
	**                                           **
	**                                           **
	**       p.s: aza ya sleju za toboi!         **
	***********************************************
  */


#include "stdio.h"
#include "windows.h"

void stringToBin(char array[]);
void stringToHex(char array[]);
void color();

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
	if (array[0] == '\0') {
		color(7);
		return 0;
	}
		for (int i = 7; i >= 0; i--) {
			int k = array[0] >> i;
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
		printf(" ");
		stringToBin(array+1);
}

void stringToHex(char array[]) 
{
	color(13);
	if (array[0] != 0x00) {
		printf("%x ", array[0]);
		
		stringToHex(array+1);
	}
	color(7);
	return 0;
}

void color(color) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); 
}
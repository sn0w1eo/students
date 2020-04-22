#include "stdio.h"
#include "windows.h"

void strBinary(char array[]);
void strHex(char array[]);

void setColor();


int main() {

	char inputString[255];
	printf("\nString:\t");
	gets(inputString);

	printf("\nHEX:\t");
	strHex(inputString);

	printf("\nBIN:\t");
	strBinary(inputString);

	printf("\n\nDone!");

}


void strBinary(char array[]) {

	if (array[0] == '\0') {

		setColor(7);
		return 0;

	}


	for (int i = 7; i >= 0; i--) {

		int k = array[0] >> i;
		if (k & 1) {

			setColor(15);
			printf("1");

		}

		else {

			setColor(8);
			printf("0");

		}

	}

	printf(" ");
	strBinary(array + 1);
}


void strHex(char array[]) {

	setColor(9);
	if (array[0] != 0x00) {

		printf("%X ", array[0]);

		strHex(array + 1);

	}


	setColor(7);

	return 0;

}


void setColor(setColor) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), setColor);

}

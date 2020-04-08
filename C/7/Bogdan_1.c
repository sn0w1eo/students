#include"stdio.h"
#include "windows.h"

//цвета по желанию можно изменить
#define GREEN 0x0A
#define RED   0x0C
#define WHITE 0x07

#define SIZE 100


void color(int color);
void printHex(char text[], int hexStep);
void printBin(char text[], int binStep);


		
int main() {

	char text[SIZE];
	int hexStep = 0;
	int binStep = 0;

	color(0x0E);
	printf("Enter text and the program will print them in BIN and HEX format\n\n");
	color(0x07);
	printf("Text: ");
	scanf_s("%s",text, SIZE);    //заполнение массива
	printf("HEX : ");
	printHex(text,hexStep);      //вывод по таблице ASCII в 16ричной системе
	color(0x07);
	printf("\nBIN : ");
	printBin(text, binStep);     //вывод по таблице ASCII в бинарной системе
	_getch();
}

//смена цвета
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}


//вывод по таблице ASCII в 16ричной системе
void printHex(char text[], int hexStep) {
	color(GREEN);
	if (text[hexStep] == '\0') {
		return;
	}
	printf("%X ", text[hexStep]);
	++hexStep;
	printHex(text, hexStep);
}


//вывод по таблице ASCII в бинарной системе
void printBin(char text[], int binStep) {
	if (text[binStep] == '\0') {
		return;
	}

	for (int i = 7; i >= 0; i--)
	{ 
		//проверка на получение цвета
		if ((text[binStep] >> i) % 2 == 0) {
			color(WHITE);
		}
		else {
			color(RED);
		}
		printf("%d", (text[binStep] >> i) % 2);  //цикл на бинарный вывод
	}
	printf(" ");
	++binStep;
	printBin(text, binStep);
}



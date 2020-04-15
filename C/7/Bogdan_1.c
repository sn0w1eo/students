#include"stdio.h"
#include "windows.h"

//цвета по желанию можно изменить
#define GREEN 0x0A
#define RED   0x0C
#define WHITE 0x07

#define SIZE 100


void color(int color);
void printHex(unsigned char text[]);
void printBin(unsigned char text[]);


		
int main() {

	unsigned char text[SIZE];
	

	color(0x0E);
	printf("Enter text and the program will print them in BIN and HEX format\n\n");

	color(WHITE);
	printf("Text: ");
	scanf_s("%s",text, SIZE);	//заполнение массива

	printf("HEX : ");
	printHex(text);		        //вывод по таблице ASCII в 16ричной системе

	color(0x07);
	printf("\nBIN : ");
	printBin(text);		        //вывод по таблице ASCII в бинарной системе
	_getch();
}

//смена цвета
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

}


//вывод по таблице ASCII в 16ричной системе
void printHex(unsigned char text[]) {
	color(GREEN);
	if (text[0] == '\0') {
		return;
	}
	printf("%X ", text[0]);
	printHex(text+1);
}


//вывод по таблице ASCII в бинарной системе
void printBin(unsigned char text[]) {
	if (text[0] == '\0') {
		return;
	}

	for (int i = 7; i >= 0; i--)
	{ 
		//проверка на получение цвета
		if ((text[0] >> i) % 2 == 0) {
			color(WHITE);
		}
		else {
			color(RED);
		}
		printf("%d", (text[0] >> i) % 2);  //цикл на бинарный вывод
	}
	printf(" ");
	printBin(text+1);
}



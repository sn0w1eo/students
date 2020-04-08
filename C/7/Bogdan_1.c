#include"stdio.h"
#include "windows.h"

//цвета по желанию можно изменить
#define GREEN 0x0A
#define RED   0x0C
#define WHITE 0x07

#define SIZE 100

int stepHex = 0;				//сдвиг по массиву    /подсмотрел вынос у ребят они за мной следили azazaza
int stepBin = 0;

void color(int color);
void printHex(char text[]);
void printBin(char text[]);


		
int main() {

	char text[SIZE];
	

	color(0x0E);
	printf("Enter text and the program will print them in BIN and HEX format\n\n");

	color(0x07);
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
void printHex(char text[]) {
	color(GREEN);
	if (text[stepHex] == '\0') {
		return;
	}
	printf("%X ", text[stepHex]);
	++stepHex;
	printHex(text);
}


//вывод по таблице ASCII в бинарной системе
void printBin(char text[]) {
	if (text[stepBin] == '\0') {
		return;
	}

	for (int i = 7; i >= 0; i--)
	{ 
		//проверка на получение цвета
		if ((text[stepBin] >> i) % 2 == 0)
			color(WHITE);
		else
			color(RED);
		printf("%d", (text[stepBin] >> i) % 2);  //цикл на бинарный вывод
	}
	printf(" ");
	++stepBin;
	printBin(text);
}



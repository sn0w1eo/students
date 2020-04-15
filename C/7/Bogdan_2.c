//не знал что писать и запихнул все прошлые программы в одну )))
//


#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "conio.h"
#include  "string.h"
#include "time.h"

#define size 100
#define SIZE 100

#define name "Богдан"

#define xMax  39
#define yMax  19

#define ESC   0x1B
#define LEFT  0xE04B
#define RIGHT 0xE04D
#define UP    0xE048
#define DOWN  0xE050

#define GREEN  0x0A
#define RED    0x0C
#define WHITE  0x07
#define YELLOW 0x0E


void znacenie(double perv, unsigned char znak, double vtor);
void position(int x, int y);
void color(int ColorNumber);
void help();
void programDir();

int programBin();
int programArray();
int programGame();
int vvodProgram();
int programCalculator();
int programConsole();
int function();
int options();

int main() {

	color(YELLOW);
	printf("Ya ne znal chto pisat',poetomu zapikhal vse v odnu programmu.\n Programma soberayet vse prevedushchiye programmy\n");
	color(GREEN);
	printf("Vvedite tsifru dlya polucheniya programmy  ili komandu \"h\" dlya polucheniya \n spravki\n");
	vvodProgram();
	_getch();
}




//выбор программы
int vvodProgram() {

	int vvod;
	do {
		vvod = _getch();
		switch (vvod)
		{
		case '1':
			programDir();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;

		case '2':
			programBin();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;

		case '3':
			programCalculator();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;

		case '4':
			programConsole();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;

		case '5':
			programArray();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;


		case '6':
			programGame();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;

			case '7':
			programText();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;
		case '8':
			function();
			system("cls");
			color(YELLOW);
			printf("Khotiye posmotret' yeshche programmy?");
			color(GREEN);
			printf("\nVvedite kod programmy: ");
			break;
		case 'h':
			help();
			break;
		default: 
			color(RED);
			printf("\nEtoy programmy poka net");
			break;
		}
	} while (vvod != ESC);
}

//рандом для получения значений 
int options() {
	srand(time(NULL));
	rand(); rand();
	return rand() % 100 + 1;
}


//вывод рандомного текста		программа вызывает и получает значения от функции options(); и обрабатывает их.
int function()
{
	system("cls");
	printf("Vvedite \'y\'chtoby uznat' kto ty ili \'n\'chtoby vernut'sya ");
	do {
		int vvod = _getch();
		if (vvod == 'y') {
			int i = options();
			if (i <= 10) {
				color(15);
				printf("\nChaynik");
			}
			if ((i <= 20) && (i > 10)){
				color(14);
				printf("\nNorm pots");
			}
			if ((i <= 30) && (i > 20)) {
				color(13);
				printf("\nBlotnoy");
			}
			if ((i <= 40) && (i > 30)) {
				color(12);
				printf("\nMilashka");
			}
			if ((i <= 50) && (i > 40)) {
				color(11);
				printf("\nZabavnyy");
			}
			if ((i <= 60) && (i > 50)) {
				color(12);
				printf("\nKachok");
			}
			if ((i <= 70) && (i > 60)) {
				color(10);
				printf("\nBandit");
			}
			if ((i <= 80) && (i > 70)) {
				color(9);
				printf("\nVorobushek");
			}
			if ((i <= 90) && (i > 80)) {
				color(8);
				printf("\nBarashek");
			}
			if ((i <= 100) && (i > 90)) {
				color(7);
				printf("\nKotik");
			}
		}
		else if (vvod == 'n')
			{
				color(13);
				printf("\nPoka, sladkiy");
				_getch();
				return;
			}

	} while (1);



}


//справка о программе
void help()
{
	color(0x0f);
	printf("\n\'1\'");
	color(0x02);
	printf("\nProgramma vyvodit dannyye diska C");
	color(0x0f);
	printf("\n\'2\'");
	color(0x02);
	printf("\nProgramma vyvodit dannyye koda klavishi nazhatiya i delayet operatsii na chisla");
	color(0x0f);
	printf("\n\'3\'");
	color(0x02);
	printf("\nProgramma moyego mini kal'kulyatora");
	color(0x0f);
	printf("\n\'4\'");
	color(0x02);
	printf("\nProgramma peredvizheniya po konsoli");
	color(0x0f);
	printf("\n\'5\'");
	color(0x02);
	printf("\nProgramma na funktsii massiva");
	color(0x0f);
	printf("\n\'6\'");
	color(0x02);
	printf("\nProgramma mini igra");
	color(0x0f);
	printf("\n\'7\'");
	color(0x02);
	printf("\nProgramma perevodit tekst v BIN i HEX");
	color(0x0f);
	printf("\n\'8\'");
	color(0x02);
	printf("\nProgramma vyvodit random tekst");
}









//смена позиции
void position(int x, int y) {
	COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}


//смена цвета
void color(int ColorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}


//вывод  данных диска С
void programDir()
{
	color(WHITE);
	system("cls");
	system("chcp 1251>nul");
	printf_s("%s\n", name);
	printf("Программа выводит список файлов диска С \n\n");
	system(" dir C:\\");
	color(RED);
	printf("\nprogramma vypolnena");
	_getch();
	return 0;
}






//выводит код клавы и потом типа калькулятор
int programBin()
{
	double div;
	unsigned char key;
	int perv, vtor, add, sub, mul, mod;

	color(WHITE);
	system("cls");
	
	printf("1) Press any key...\n");
	key = _getch();




	printf("\n ЪДДДДДДДВДДДДДВДДДДДДДВДДДДДДДДДї		");
	printf("\n і ASCII і DEC і  HEX  і   BIN   і");
	printf("\n ГДДДДДДДЕДДДДДЕДДДДДДДЕДДДДДДДДДґ");
	printf("\n і%7cі %4dі %6Xі%d%d%d%d%d%d%d%d і", key, key, key, key >> 7, (key >> 6) % 2, (key >> 5) % 2, (key >> 4) % 2, (key >> 3) % 2, (key >> 2) % 2, (key >> 1) % 2, key % 2);
	printf("\n АДДДДДДДБДДДДДБДДДДДДДБДДДДДДДДДЩ");




	printf("\n\n 2) Enter 2 digits: ");
	scanf_s("%d %d", &perv, &vtor);
	add = perv + vtor;
	sub = perv - vtor;
	mul = perv * vtor;
	div = (double)perv / (double)vtor;
	mod = perv % vtor;


	printf("\n ЪДДДДДДДВДДДДДВДДДДДДДВДДДДДДДВДДДДДДДї		");
	printf("\n і ADD   і SUB і  MUL  і  DIV  і  MOD  і");
	printf("\n ГДДДДДДДЕДДДДДЕДДДДДДДЕДДДДДДДЕДДДДДДДґ");
	printf("\n і%7dі%5dі%7dі%7.2fі%7dі", add, sub, mul, div, mod);
	printf("\n АДДДДДДДБДДДДДБДДДДДДДБДДДДДДДБДДДДДДДЩ");

	printf("\n99.9 %% complete..................");

	color(RED);
	printf("\nprogramma vypolnena");
	_getch();

	return 0;

}










//функция для функции калькулятора
void znacenie(double perv, unsigned char znak, double vtor) {
	double rezult;
	if (znak == '+') {                                                      //проверяет знак
		rezult = perv + vtor; printf("%g\n", rezult);                      // делает вычисления и выводит
		for (int i = 0; i <= 20; i++) {
			printf("Н");                                                //печатает разделитель за счет цикла
		}
		printf("\nHEX: %08X\n", (int)rezult);                                 //выводит в HEX


		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {                                      //цикл на бинарный вывод 
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '-') {                                     //продолжение преведущего
		rezult = perv - vtor; printf("%g\n", rezult);

		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}

	}
	else if (znak == '*') {
		rezult = perv * vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '/') {
		rezult = perv / vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\n This program cannot yet calculate the value (BIN and HEX). Wait for the update ");
	}
	else if (znak == '%') {
		rezult = (int)perv % (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '&') {
		rezult = (int)perv & (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '^') {
		rezult = (int)perv ^ (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}
	}
	else if (znak == '|') {
		rezult = (int)perv | (int)vtor; printf("%g\n", rezult);
		for (int i = 0; i <= 20; i++) {
			printf("Н");
		}
		printf("\nHEX: %08X\n", (int)rezult);
		printf("\nBIN: ");
		for (int i = 31; i >= 0; i--) {
			printf("%d", ((int)rezult >> i) % 2);
			if (i % 8 == 0) { printf("  "); }
		}

	}
	return;
}


//типа калькулятор
int programCalculator() {

	
	int perv = 0, vtor = 0;
	unsigned char znak, vvod_perv, vvod_vtor;


	system("cls");
	color(WHITE);

	printf("Universal calculator\n");
	printf("Sintax: VALUE SIGN VALUE EQUAL >\n");

	for (int i = 0; i <= 20; i++) {
		printf("Н");
		if (i == 20) printf("\n");
	}

	printf("VALUE: any int namberic value\n");
	printf("SIGN: +, -, %%, /, *, &, ^, |\n");
	printf("EQUAL: =\n");
	for (int i = 0; i <= 20; i++) {
		printf("Н");
		if (i == 20) printf("\n");            // Вывод на консоль шапки и инструкции
	}




	for (;;) {
		vvod_perv = _getch();
		if (vvod_perv >= '0' && vvod_perv <= '9')
		{
			printf("%c", vvod_perv);
			perv = perv * 10 + (vvod_perv - 48);

		}
		else if (vvod_perv == '+' || vvod_perv == '-' || vvod_perv == '*' || vvod_perv == '/' || vvod_perv == '%' || vvod_perv == '&' || vvod_perv == '^' || vvod_perv == '|')
		{
			printf("%c", vvod_perv);
			znak = vvod_perv;
			break;
		}
		else if (vvod_perv == 'x')
		{
			break;
		}
		else
		{
			continue;
		}                                 //Ввод первого числа и знака операции
	}



	for (;;) {
		vvod_vtor = _getch();
		if (vvod_vtor >= '0' && vvod_vtor <= '9') {
			printf("%c", vvod_vtor);
			vtor = vtor * 10 + (vvod_vtor - 48);

		}
		else if (vvod_vtor == '=') {
			printf("%c", vvod_vtor);
			break;
		}
		else if (vvod_perv == 'x')
		{
			break;
		}
		else
		{
			continue;

		}                                 //Ввод второго числа и знака равно


	}
	znacenie(perv, znak, vtor);

	color(RED);
	printf("\nprogramma vypolnena");
	_getch();
	return 0;

}


//свободная консоль
int programConsole() {
	int vvod;
	int x = 0, y = 0, XMax = 78, YMax = 22;

	system("cls");
	position(0, 23);
	color(12);
	printf("Press ESC to exit");
	position(0, 0);
	do
	{

		vvod = _getch();

		if (vvod >= 'A' && vvod <= 'z') {
			printf("%c\b", vvod);
		}

		if (vvod == 0xE0)
		{
			vvod = vvod << 8;
			vvod = vvod | _getch();
		}

		switch (vvod)
		{
		case LEFT: if (x != 0)  --x; position(x, y); break;
		case RIGHT: if (x != XMax)  ++x; position(x, y); break;
		case UP: if (y != 0)  --y; position(x, y); break;
		case DOWN: if (y != YMax) ++y; position(x, y); break;
		case '1': color(7); break;
		case '2': color(8); break;
		case '3': color(9); break;
		case '4': color(10); break;
		case '5': color(11); break;
		case '6': color(12); break;
		case '7': color(13); break;
		case '8': color(14); break;
		case '9': color(15); break;
		}

		if (vvod == ESC) {
			position(0, 24);
			color(12);
			for (int x = 0; x <= XMax; x++) {
				for (int Progress = 65; Progress <= 122; Progress++) {
					printf("%c\b", Progress);
					if (Progress == 122)printf("%c\b", 219);
				}
				position(x, 24);
			}


		}

	} while (vvod != ESC);
}



//функции массивов
int programArray()
{

	int chislo;
	double chislo2;
	char numbers[size];
	char str1[size];
	char str2[size] = { 0x00 };



	color(WHITE);
	system("cls");

	//strtol
	printf("vvedite chislo\n");
	gets(numbers);
	long longNumber = strtol(numbers, NULL, 10);                //функцию не cовсем понял но она преобразует строку в число типа long преобразуя в нужную систему счисления
	printf("%ld", longNumber);

	//strtod
	printf("\n\nvvedite chislo\n");
	gets(numbers);
	double doubleNumber = strtod(numbers, NULL, 10);           //функцию не cовсем понял но она преобразует строку в число типа double преобразуя в нужную систему счисления
	printf("%lf", doubleNumber);

	//atoi
	printf("\n\nvvedite chislo,poluchite kvadrat\n");
	gets(numbers);
	printf("%d\n", atoi(numbers) * atoi(numbers));              //преобразует строку в число типа int

	//atol
	printf("\nvvedite chislo,poluchite summ\n");
	gets(numbers);
	printf("%d\n", atol(numbers) + atol(numbers));             //преобразует строку в число типа long


	//_itoa_s
	printf("\nvvedite chislo,poluchite hex\n");
	scanf_s("%d", &chislo);
	char per[size];
	_itoa_s(chislo, numbers, size, 16);                        //преобразует число в строку и после в нужную систему счисления от 2 до 36 . 1)Число, которое требуется преобразовать. 2)Выходной буфер, содержащий результат преобразования. 3)Размер буфера в символах или расширенных символах.4)Основание системы счисления
	printf(numbers);

	//_ltoa_s
	printf("\n\nvvedite chislo,poluchite bin\n");
	scanf_s("%d", &chislo);
	_ltoa_s(chislo, numbers, size, 2);                        //преобразует число(длинное) в строку и после в нужную систему счисления от 2 до 36
	printf(numbers);


	//_gcvt_s
	printf("\n\nvvedite drobnoye chislo\n");
	scanf_s("%lf", &chislo2);
	_gcvt_s(numbers, size, chislo2, 2);                      // Преобразует значение с плавающей запятой в строку.  1)Буфер для сохранения результата преобразования. 2)Размер буфера.3)Преобразуемое значение.4)Количество значащих цифр хранятся.
	printf(numbers);

	//strlen
	printf("\n\nDlina stroki  % s - % d simvolov\n", numbers, strlen(numbers));      //измерение длинны строки


	//strcmp
	printf("\nvvedite stroky1: ");
	gets(str1);
	gets(str1);
	printf("vvedite stroky2: ");
	gets(str2);
	if (strcmp(str1, str2) == 0)                           //сравнивает 2 строки по алфавиту если строки одинаковы выдает 0
		puts("troki odinakovy\n");
	else
		puts("stroki otlichayutsya\n");


	//strncmp
	if (strncmp(str1, str2, 1) == 0)                        //сравнивает 2 строки по алфавиту,не более определенного кол-ва символов. если строки одинаковы выдает 0
		puts("stroki odinakovy\n");
	else
		puts("stroki otlichayutsya\n");

	//strcpy
	strcpy(str1, "kopirovaniye vypolneno uspeshno\n");     //копирование строки целиком
	printf(str1);

	//strncpy
	printf("\n vyvod strncpy\n");
	strncpy(str2, str1, 5);                                 //копирование строки до определенного символа
	printf(str2);

	//strcat
	printf("\n\n vyvod strcat\n");                        //присоединение строки
	strcat(str2, str1);
	printf(str2);

	//strncat
	printf("\n vyvod strncat\n");                       //присоединение строки до опрределенного символа
	strncat(str2, str1, 10);
	printf(str2);

	color(RED);
	printf("\nprogramma vypolnena");

	_getch();

	return 0;
}


//лслЦ¦ б ТЖ·
void Display(int x, int y)

{
	color(WHITE);
	system("cls");

	position(x, y);
	color(13);

	//лЁбµФЮЮ ¬б Ф·¤ 
	for (int i = 0; i < xMax; i++)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"Д" мЁбµФЮЮ · Ф·йФЮЮ ¬б Ф·¤ 
		x++;
	}

	//Шб л Ю ¬б Ф·¤ 
	for (int i = 0; i < yMax; i++)
	{
		position(x, y);
		printf("\xB3");		//179	B3	10110011	"і" Эб л Ю ¬б Ф·¤ 
		y++;
	}

	//Х·йФЮЮ ¬б Ф·¤ 
	for (int i = xMax; i > 0; i--)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"Д" мЁбµФЮЮ · Ф·йФЮЮ ¬б Ф·¤ 
		x--;
	}

	//и¬Рс
	position(0, 0);
	printf("\xDA");			//218	DA	11011010  "Ъ"	РЁлсЅ лЁбµФ·Ѕ з¬ЦР
	position(xMax, 0);
	printf("\xBF");			//191	BF	10111111  "ї"   лЁбµФ·Ѕ Шб лсЅ з¬ЦР 
	position(xMax, yMax);
	printf("\xD9");			//217	D9	11011001  "Щ"	Шб лсЅ Ф·йФ·Ѕ з¬ЦР
	position(0, yMax);
	printf("\xC0");			//192	C0	11000000  "А"   Ф·йФ·Ѕ РЁлсЅ з¬ЦР
}

//лслЦ¦ Т гг·л  г гЦЦелЁегелзњщ·Т· ¤лЁе Т·
void PrintMassiv(int Massiv[][xMax - 1]) {

	position(0, 1);
	for (int y = 0; y < yMax - 1; y++) {
		for (int x = 0; x < xMax - 1; x++) {
			if (x == 0)
			{
				color(13);
			}
			else if (Massiv[y][x] == '#')
			{
				color(12);
			}
			else if (Massiv[y][x] == '*')
			{
				color(11);
			}
			else if (Massiv[y][x] == '@')
			{
				color(10);
			}
			else if (Massiv[y][x] == 0xF9)
			{
				color(14);
			}
			printf("%c", Massiv[y][x]);
		}
		printf(" \n");
	}
}



int programGame() {

	color(WHITE);
	system("cls");

	char FirstName[20] = { 0x00 };
	char LastName[20] = { 0x00 };
	char NickName[20] = { 0x00 };
	int Steps, Blocks, x = 0, y = 0;
	int Massiv[yMax - 1][xMax - 1];
	unsigned int vvod;
	int stroka = 0, stolb = 1;
	int lable = 1;
	int BeginnerSteps;
	srand(time(NULL));


	//млЦ¦ ¦ ФФсµ
	printf("first Name: ");
	gets(FirstName);
	printf("\nlastName: ");
	gets(LastName);
	printf("\nnick Name: ");
	gets(NickName);
	printf("\nWelcome %s \"%s\" %s\n", FirstName, NickName, LastName);
	printf("Blocks: ");
	scanf_s("%d", &Blocks);
	printf("Steps: ");
	scanf_s("%d", &Steps);
	BeginnerSteps = Steps;
	Display(x, y);
	position(x, yMax + 2);
	color(14);
	printf("STEPS: %d", Steps);
	system("cls");

	//ф ШЦРФЁФ·Ё У гг·л  ШбЦўЁР Т·
	for (int y = 0; y < yMax - 1; y++) {
		for (int x = 0; x < xMax - 1; x++) {
			Massiv[y][x] = ' ';
		}
		if (x == 0)
		{
			Massiv[y][x] = 0xB3;              //  179	B3	10110011	"і" РЁл Ю ¬б Ф·¤ 
		}
	}


	//ф ШЦРФЁФ·Ё Т гг·л  @
	for (int i = 1; i > 0; i--)
	{

		y = rand() % (yMax - 1);
		x = rand() % (xMax - 1);
		if (x == 0 || (x == 1 && y == 0))   //ШбЦлЁбЖ  Ф  ¬б Ф·¤з · Ф ы РнФсЅ чРЁТЁФе
		{
			++i;
			continue;
		}
		Massiv[y][x] = '@';
	}


	//ф ШЦРФЁФ·Ё Т гг·л  *
	Massiv[0][1] = '*';


	//у ШЦРФЁФ·Ё Т гг·л  (#)
	for (int i = Blocks; i > 0; i--)
	{
		y = rand() % (yMax - 1);
		x = rand() % (xMax - 1);
		if (x == 0 || (x == 1 && y == 0) || Massiv[y][x] == '@' || Massiv[y][x] == '#') {         //ШбЦлЁбЖ  Ф  ¬бФ·¤з, Ф ы РнФсЅ чРЁТЁФе, Є·Ф·х · ШЦлеЦбФсЅ ўРЦЖ
			++i;
			continue;
		}
		Massiv[y][x] = '#';
	}

	//лслЦ¦ ·уФ ы РнФЦ¬ Т гг·л 
	Display(0, 0);
	PrintMassiv(Massiv);



	do
	{

		vvod = _getch();

		if (vvod == 0xE0)
		{
			vvod = vvod << 8;
			vvod = vvod | _getch();
		}
		//ШбЦлЁбЖ  гебЁРЦЖ
		switch (vvod)
		{
		case RIGHT:
			//ШбЦлЁбЖ  Ф  ¬б Ф·¤с · ўРЦЖ·
			if ((Massiv[stroka][stolb + 1] == '#') || (stolb + 1 == xMax - 1))
			{
				break;
			}


			else
			{
				Massiv[stroka][stolb] = 0xF9;                  //уФ Ж еЦыЖ·
				if (Massiv[stroka][stolb + 1] == '@') {        //ШбЦлЁбЖ  Ф  Є·Ф·х
					lable = 0;
				}
				++stolb;
				Massiv[stroka][stolb] = '*';
				Display(0, 0);                                 //лслЦ¦ б ТЖ·
				PrintMassiv(Massiv);                           //лслЦ¦ Т гг·л 
				Steps--;
				position(0, yMax + 2);                         //лслЦ¦ ЖЦР-л  х ¬Цл
				color(14);
				printf("STEPS: %d  ", Steps);
				break;

			}
		case LEFT:
			if (Massiv[stroka][stolb - 1] == '#' || (stolb - 1 == 0))
			{
				break;
			}


			else
			{
				Massiv[stroka][stolb] = 0xF9;
				if (Massiv[stroka][stolb - 1] == '@')
					lable = 0;
				--stolb;
				Massiv[stroka][stolb] = '*';
				Display(0, 0);
				PrintMassiv(Massiv);
				Steps--;
				position(0, yMax + 2);
				color(14);
				printf("STEPS: %d  ", Steps);
				break;
			}

		case UP:
			if (Massiv[stroka - 1][stolb] == '#' || (stroka - 1 == -1))

			{
				break;
			}


			else
			{
				Massiv[stroka][stolb] = 0xF9;
				if (Massiv[stroka - 1][stolb] == '@')
					lable = 0;
				--stroka;
				Massiv[stroka][stolb] = '*';
				Display(0, 0);
				PrintMassiv(Massiv);
				Steps--;
				position(0, yMax + 2);
				color(14);
				printf("STEPS: %d  ", Steps);
				break;
			}

		case DOWN:
			if (Massiv[stroka + 1][stolb] == '#' || (stroka + 1 == yMax - 1))

			{
				break;
			}


			else
			{
				Massiv[stroka][stolb] = 0xF9;
				if (Massiv[stroka - 1][stolb] == '@')
					lable = 0;
				++stroka;
				Massiv[stroka][stolb] = '*';
				Display(0, 0);
				PrintMassiv(Massiv);
				Steps--;
				position(0, yMax + 2);
				color(14);
				printf("STEPS: %d  ", Steps);
				break;
			}


		}
		if (vvod == ESC) {
			position(0, yMax + 2);
			color(13);
			printf("Ok buddy. Cya next time...");
			_getch();
			return;
		}

	} while (Steps != 0 && lable != 0);


	if (lable == 0)
	{
		position(0, yMax + 2);
		color(10);
		printf("Congratulations! You've won! Steps: %d/%d ", Steps, BeginnerSteps);
	}
	else
	{

		position(0, yMax + 2);
		color(12);
		printf("You've failed. Try ur luck next time");
	}

	color(RED);
	printf("\nprogramma vypolnena");

	_getch();
}





int stepHex = 0;				//сдвиг по массиву    /подсмотрел вынос у ребят они за мной следили azazaza
int stepBin = 0;

void color(int color);
void printHex(char text[]);
void printBin(char text[]);



int programText() {


	color(WHITE);
	system("cls");

	char text[SIZE];


	color(0x0E);
	printf("Enter text and the program will print them in BIN and HEX format\n\n");

	color(0x07);
	printf("Text: ");
	scanf_s("%s", text, SIZE);	//заполнение массива

	printf("HEX : ");
	printHex(text);		        //вывод по таблице ASCII в 16ричной системе

	color(0x07);
	printf("\nBIN : ");
	printBin(text);		        //вывод по таблице ASCII в бинарной системе
	
	color(RED);
	printf("\nprogramma vypolnena");

	_getch();
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



#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STR_LEN 5

int main()
{
	//_itoa
	int number = 934;
	char string[25];
	printf("Number: ");

	//Преобразование числа типа int в строку
	_itoa(number, string, 10); 

	//Вывод результата преобразования
	printf("int: %d, string: %s\n", number, string);

	//_ltoa
	char stringLtoa[25];
	long value = 123456789L;

	//Преобразование числа типа long в строку
	_ltoa(value, stringLtoa, 10);

	//Вывод результата преобразования
	printf("long = %ld string: %s\n", value, stringLtoa);

	//_gcvt
	char buf[80];

	//Преобразование числа 10.12 в строку
	_gcvt(10.12, 5, buf);

	//Вывод результата преобразования
	printf("%s gcvt 10.12\n", buf);

	//atoi
	char temporaryString[STR_LEN] = { 0x00 };
	int dogs = 0;
	printf("Dogs string: ");
	scanf("%s", temporaryString);

	//Преобразование строки в число типа int
	dogs = atoi(temporaryString);

	//Вывод результата преобразования
	printf("Dogs int: %d\n", dogs);

	//_atol
	char* Str = "372.23djkj"; //Строка для преобразования
	long int Num = 0;           //Переменная для записи результата

	//Преобразование строки в число типа long int
	Num = atol(Str);

	//Вывод результата преобразования
	printf("372.23djkj to int %ld\n", Num);

	//strtol
	char str[30] = "5670 how r u";
	char* ptr;
	long ret;

	//Вывод числа типа long из строки
	ret = strtol(str, &ptr, 10);
	printf("The number(unsigned long integer) is %ld\n", ret);

	//Вывод строковой части
	printf("String part is: %s\n", ptr);

	//strtod
	char strD[30] = "54.3670 I`m ok, thx";
	char* ptrD;
	double retD;
	//Вывод числа типа double из строки
	retD = strtod(strD, &ptrD);
	printf("The number(double) is %lf\n", retD);
	printf("String part is: %s\n", ptrD);

	//strlen
	char numbers[11] = "0123456789";

	//Определение длины строки и вывод результата на консоль
	printf("String length %s - %d symbols\n", numbers, strlen(numbers));

	//strcmp

	// Введите 2 строки для сравнения
	printf("Input 2 strings\n");
	char str1[1024] = { 0x00 };
	scanf("%s", str1);
	char str2[1024] = { 0x00 };
	scanf("%s", str2);

	// Сравниваем две строки
	if (strcmp(str1, str2) == 0)
		printf("Strings are equal\n");
	else
		printf("Strings are different\n");

	//strncmp

	printf("Input 2 strings\n");
	char str3[1024] = { 0x00 };
	scanf("%s", str3);
	char str4[1024] = { 0x00 };
	scanf("%s", str4);

	// Сравниваем первые пять символов двух строк
	if (strncmp(str3, str3, 5) == 0)
		printf("The first five symbols of the strings are equal\n");
	else
		printf("The first five symbols of the strings are different\n");

	//strcpy

	// Массив источник данных
	char src[1024] = "first string\0 second string";

	// Массив приемник данных
	char dst[1024] = " ";

	// Копируем строку из массива src в массив dst 
	strcpy(dst, src);

	// Вывод массива src на консоль
	printf("src: % s % s\n", src, &src[14]);

	// Вывод массива dst на консоль
	printf("dst: % s % s\n", dst, &dst[14]);

	//strncpy
	// Массив источник данных
	char abc[10] = "12345\0006789";

	// Массивы приемники данных
	char def[10] = "1111111111";
	char ghi[10] = "1111111111";

	// Счетчик
	int i;

	// Вывод массива src на консоль
	printf("abc: ");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)abc[i]);
	printf("\n");

	// Копируем строку длиною не более трех символов из массива abc в массив def. 
	strncpy(def, abc, 3);

	// Вывод массива egh на консоль
	printf("def:");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)def[i]);
	printf("\n");

	// Копируем строку длиною не более семи символов из массива abc в массив ghi. 
	strncpy(ghi, abc, 7);

	// Вывод массива ghi на консоль
	printf("ghi: ");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)ghi[i]);
	printf("\n");

	//strcat

	char sec[1024] = "horosho normalno";

	// Массив приемник данных
	char fir[1024] = "privet kak dela ";

	// Добавляем строку из массива sec в массив fir. 
	strcat(fir, sec);

	// Вывод массива fir на консоль
	printf("fir: % s\n", fir);

	//strncat

	// Массивы в которые добавляется строка
	char src1[10] = "000";
	char src2[10] = "000";

	// Добавляемая строка
	char app[10] = "12345";

	// Вывод добавляемой строки
	printf("app: % s\n", app);

	// Добавление строки app в строку src1, но не более трех символов
	strncat(src1, app, 3);
	// Вывод результата
	printf("src1: % s\n", src1);

	// Добавление строки app в строку src2, но не более семи символов
	strncat(src2, app, 7);
	// Вывод результата
	printf("src2: % s\n", src2);
}

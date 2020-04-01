#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"

int main()
{

	int integer;
	printf("1) Press integer:                       ");
	scanf_s("%d", &integer);
	unsigned char array[50];
	// Конвертирование целого числа в строку 
	_itoa(integer, array, 10);
	printf("2) Convert to string: %20s\n", array);

	// Выводит значение integer в шестнадцатеричной системе счисления
	_ltoa(integer,array, 16);
	printf("3) Integer value in hex:                ");
	printf(array);

	// Конвертирует float в строку:
	_gcvt(12.15, 5, array);
	printf("\n4) Convert float to string: %17s\n",array);

	// Конвертирует string  в integer 
	int a;
    unsigned char string[20]="123456";
	a= atoi(string);
	printf("5) String to integer: %24d\n", a);

	// Конвертирует string  в integer
	int b;
	unsigned char string2[25] = "12342331";
	b = atol(string2);
	printf("6) Long String to integer: %21d", b);

	// Конвертирует string to long
	char str[30] = "2030300 This is test";
	char* ptr;
	long ret;
	ret = strtol(str, &ptr, 10);
	printf("\n7) The number(unsigned long integer) is %ld\n", ret);

	// Конвертирует string to double 
	char str2[30] = "20.30300 This is test";
	char* ptr2;
	double ret2;

	ret2 = strtod(str2, &ptr2);
	printf("8) The number(double) is %21.3lf\n", ret2);

	//-------------------------------------------------------------------------
	printf("ДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДДД\n");
	//-------------------------------------------------------------------------
	
	// Вычисление длины строки array3.
	char array3[20] = "Program";
	printf("1) Length of string a = %ld \n", strlen(array3));

	// Сравнение строк str1 и str2
	char str1[15]="abcdef";
	char str3[15]="ABCDEF";
	int res;
	res = strcmp(str3, str2);

	if (res < 0) {
		printf("2) str1 is less than str2");
	}
	else if (res > 0) {
		printf("2) str2 is less than str1\n");
	}
	else {
		printf("2) str1 is equal to str2");
	}

	// Сравнение строк str1 и str2 (4 символа)
	int res2;
	res2 = strncmp(str3, str2, 4);
	if (res2 < 0) {
		printf("3) str1 is less than str2");
	}
	else if (res2 > 0) {
		printf("3) str2 is less than str1\n");
	}
	else {
		printf("3) str1 is equal to str2");
	}

	// Копирование строки src в строку - приемник dest
	char src[50]= "This is Copy";
	char dest[100];
	strcpy(dest, src);
	printf("4) %s\n",dest);

	// Копирование строки src1 в строку - приемник dest1 
	// (15 символов, дополняя их символами '\0' или отсекая лишние, в
	// последнем случае dest1 не будет ограничена.)
	char src1[50]="This is the string";
	char dest1[15];
	strncpy(dest1, src1, 15);
	printf("5) %s\n", dest1);

	// Добавление строки src2 конец строки dest2
	char src2[20]="World";
	char dest2[30]="Hello ";
	strcat(dest2, src2);
	printf("6) %s\n", dest2);

	// Добавление строки src2 или не более maxlen ее первых символов
	// в конец строки dest2 ()
	char src3[20] = "World";
	char dest3[30] = "Hello ";
	strncat(dest3, src3, 4);
	printf("7) %s\n", dest3);
}
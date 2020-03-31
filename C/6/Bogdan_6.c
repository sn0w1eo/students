/*itoa
ltoa
gcvt
atoi
atol
strtol
strtod



string.h
strlen
strcmp
strncmp
strcpy
strncpy
strcat
strncat*/

#define _CRT_SECURE_NO_WARNINGS
#include  "stdio.h"
#include  "stdlib.h"
#include  "string.h"

#define size 100

//вот мой говнокод)))
int main()
{
	
	int chislo;
	double chislo2;
	char numbers[size] ; 
	char str1[size];
	char str2[size] = {0x00};





	//strtol
	printf("vvedite chislo\n");                           
	gets(numbers);
	long longNumber = strtol(numbers, NULL, 10);                //функцию не cовсем понял но она преобразует строку в число типа long преобразуя в нужную систему счисления
	printf("%ld", longNumber);
	
	//strtod
	printf("\n\nvvedite chislo\n");
	gets(numbers);
	double doubleNumber = strtod(numbers, NULL, 10);           //функцию не cовсем понял но она преобразует строку в число типа double преобразуя в нужную систему счисления
	printf("%ld", doubleNumber);

	//atoi
	printf("\n\nvvedite chislo,poluchite kvadrat\n");
	gets(numbers);
	printf("%d\n", atoi(numbers)* atoi(numbers));              //преобразует строку в число типа int

	//atol
	printf("\nvvedite chislo,poluchite summ\n");
	gets(numbers);
	printf("%d\n", atol(numbers) + atol(numbers));             //преобразует строку в число типа long


	//_itoa_s
	printf("\nvvedite chislo,poluchite hex\n");
	scanf_s("%d", &chislo);
	char per[size];
	_itoa_s(chislo, numbers, size,16);                        //преобразует число в строку и после в нужную систему счисления от 2 до 36 . 1)Число, которое требуется преобразовать. 2)Выходной буфер, содержащий результат преобразования. 3)Размер буфера в символах или расширенных символах.4)Основание системы счисления
	printf(numbers);

	//_ltoa_s
	printf("\n\nvvedite chislo,poluchite bin\n");
	scanf_s("%d", &chislo);
	_ltoa_s(chislo, numbers, size,2);                        //преобразует число(длинное) в строку и после в нужную систему счисления от 2 до 36
	printf(numbers);


	//_gcvt_s
	printf("\n\nvvedite drobnoye chislo\n");
	scanf_s("%lf", &chislo2); 
	_gcvt_s(numbers, size, chislo2,2);                      // Преобразует значение с плавающей запятой в строку.  1)Буфер для сохранения результата преобразования. 2)Размер буфера.3)Преобразуемое значение.4)Количество значащих цифр хранятся.
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
	if (strncmp(str1, str2,1) == 0)                        //сравнивает 2 строки по алфавиту,не более определенного кол-ва символов. если строки одинаковы выдает 0
		puts("stroki odinakovy\n");
	else
		puts("stroki otlichayutsya\n");

	//strcpy
	strcpy(str1, "kopirovaniye vypolneno uspeshno\n");     //копирование строки целиком
	printf(str1);

	//strncpy
	printf("\n vyvod strncpy\n");
	strncpy(str2, str1,5);                                 //копирование строки до определенного символа
	printf(str2);

	//strcat
	printf("\n\n vyvod strcat\n");                        //присоединение строки
	strcat(str2, str1);
	printf(str2);

	//strncat
	printf("\n vyvod strncat\n");                       //присоединение строки до опрределенного символа
	strncat(str2, str1,10);
	printf(str2);



	return 0;
}



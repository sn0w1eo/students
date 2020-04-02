#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "windows.h"

#define COLOR(color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
	

void printAllFunctions() 
{
	printf("\nВсе функции:\n");
	puts("#1  itoa ");
	puts("#2  ltoa");
	puts("#3  gcvt");
	puts("#4  atoi");
	puts("#5  atol");
	puts("#6  strtol");
	puts("#7  strtod");
	puts("\nФункции string.h\n");
	puts("#8  strlen");
	puts("#9  strcmp");
	puts("#10 strncmp");
	puts("#11 strcpy");
	puts("#12 strncpy");
	puts("#13 strcat");
	puts("#14 strncat\n");
	puts("Введите номер функии что бы посмотреть что она выполняет\n");
	
}
int main() 
{
	system("chcp 866>nul");
	char help[] = { "help" };
	char exitconsole[] = { "exit" };
	char input[10];
	char number;
	int Check=0;
	puts("Программа для проверки функций...");
	puts("Введите help для справки или exit для выхода...");
		while (Check!=1) 
		{
			gets(input);
			int EXITconsole = strcmp(exit, input);
			int HELP = strcmp(help, input);
			if (EXITconsole == 0) 
			{
				
				return 0;
			}
			else
			{
				if (EXITconsole > 0 || HELP>0)
				{
					puts("Неизветсная команда!Попробуйте еще раз");
				}
			}
			if (HELP == 0) 
			{
				Check ++;
				if (HELP > 0) {
					printAllFunctions();
				}
			}
			
		}
		printAllFunctions();
		
		do 
		{
			scanf("%d",&number);
			switch (number)
			{
			case 1:
				COLOR(0x0E);
				puts("#1 itoa - Функция itoa (i-int)(a-ascii) преобразует целое число n в строку str в формате rad. Максимальная длина 17 байт\n");
				COLOR(0x07);
				char buffer_It[18];
				int value_It,rad_It;	
				printf("Введите число: ");
				scanf("%d",&value_It);
				printf("Введите основание системы (число от 2 до 36):");
				scanf("%d", &rad_It);
				_itoa_s(value_It, buffer_It, _countof(buffer_It),rad_It);
				COLOR(0x0A);
				printf("Число которое Вы ввели %d в системе с основанием %d имеет вид: %s\n",value_It,rad_It,buffer_It);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 2:
				COLOR(0x0E);
				puts("#2 ltoa - Функция ltoa (l-long)(a-ascii) тоже самое что и itoa .Преобразует целое число n в строку str в формате rad. Максимальная длина 34 байта\n");
				COLOR(0x07);
				char buffer_Lt[35];
				int value_Lt, rad_Lt;
				printf("Введите число: ");
				scanf("%d", &value_It);
				printf("Введите основание системы (число от 2 до 36):");
				scanf("%d", &rad_It);
				_itoa_s(value_It, buffer_It, _countof(buffer_It), rad_It);
				COLOR(0x0A);
				printf("Число которое Вы ввели %d в системе с основанием %d имеет вид: %s\n", value_It, rad_It, buffer_It);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 3:
				COLOR(0x0E);
				puts("#3 gcvt - Функция преобразовывает значение с плавающей точкой в символьную строку и запоминает эту строку в буфере.");
				COLOR(0x07);
				char buffer_Gc[50];
				double value_Gc;
				printf("Введите число: ");
				scanf("%f", &value_It);
				_gcvt(value_It,4,buffer_It);
				COLOR(0x0A);
				printf("Преобразованное число: %s\n", buffer_It);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 4:
				COLOR(0x0E);
				puts("#4 atoi - Функция atoi (a-ASCII)(i-int) используется для приведения (конвертации) строки в числовой вид. Строка должна содержать целое число");
				COLOR(0x07);
				char buffer_Atoi[] = { "4554pussy" };
				int result = atoi(buffer_Atoi);
				COLOR(0x0A);
				printf("Результат конвертации: Строка %s и ее целая часть %d\n", buffer_Atoi,result);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 5:
				COLOR(0x0E);
				puts("#5 atol - Функция atol (a-ASCII)(l-long int) используется для приведения (конвертации) строки в числовой вид. Строка должна содержать целое число");
				COLOR(0x07);
				char buffer_Atol[] = { "652.23brrt" };
				long int Num = 0;           
				Num = atol(buffer_Atol);
				COLOR(0x0A);
				printf("Результат конвертации: Строка %s и ее численная часть %d\n", buffer_Atol, Num);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 6:
				COLOR(0x0E);
				puts("#6 strtol - Функция преобразует строковое представление числа, которое содержится в строке, в значение типа long int.");
				COLOR(0x07);
				char buffer_strtol[] = {"228228pussy"};
				puts("Введите строку с численными значениями в начале: ");			
				long int Number = strtol(buffer_strtol, NULL, 10);
				COLOR(0x0A);
				printf_s("Результат конвертации: Строка %s и ее численная часть %d\n", buffer_strtol,Number);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 7:
				COLOR(0x0E);
				puts("#7 strtod - Функция преобразует строковое представление числа, которое содержится в строке, в значение типа double.");
				COLOR(0x07);
				char buffer_strtod[50] = { "228.228pussy" };
				double number = strtod(buffer_strtod, NULL, 10);
				COLOR(0x0A);
				printf_s("Результат конвертации: Строка %s и ее численная часть %.2lf\n",buffer_strtod, number);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			//string.h

			case 8:
				COLOR(0x0E);
				puts("#8 strlen - Функция strlen вычисляет количество символов в строке.");
				COLOR(0x07);
				char buffer_strlen[10];
				printf("Введите произвольную строку:");
				scanf("%s", &buffer_strlen, 10);
				int result_len = strlen(buffer_strlen);
				COLOR(0x0A);
				printf("Количество символов в введеной строке: %d\n", result_len);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 9:
				COLOR(0x0E);
				puts("#9 strcmp - Функция strcmp сравнивает 2 строки. Возвращает 0, если строки одинаковые, положительное, если первая строка больше, и отрицательное, если меньше");
				COLOR(0x07);
				char first[10];
				char second[10];
				printf("Введите первую строку:");
				scanf("%s", &first, 10);
				printf("Введите вторую строку:");
				scanf("%s", &second, 10);
				int result_cmp = strcmp(first, second);
				if (result_cmp == 0) 
				{
					COLOR(0x0A);
					printf("Строки равны\n");
					COLOR(0x07);
				}
				else if (result_cmp == 1) 
				{
					COLOR(0x0A);
					printf("Первая строка больше второй\n");
					COLOR(0x07);
				}
				else 
				{
					COLOR(0x0A);
					printf("Вторая строка больше первой\n");
					COLOR(0x07);
				}
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;
			
			case 10:
				COLOR(0x0E);
				puts("#10 strncmp - Функция strncmp сравнивает первые n байтов строк");
				COLOR(0x07);
				char first_n[20];
				char second_n[20];
				int n;
				printf("Введите первую строку:");
				scanf("%s", &first_n, 20);
				printf("Введите вторую строку:");
				scanf("%s", &second_n, 20);
				printf("Введите до какого байта проверять:");
				scanf("%d", &n);
				strncmp(first_n, second_n, n);
				int result_ncmp = strcmp(first_n, second_n);
				if (result_ncmp == 0)
				{
					COLOR(0x0A);
					printf("Первые %d букв(ы) строк равны!\n",n);
					COLOR(0x07);
				}
				else
				{
					COLOR(0x0A);
					printf("Первые %d букв(ы) строк не равны!\n", n);
					COLOR(0x07);
				}
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 11:
				COLOR(0x0E);
				puts("#11 strcpy - Функция strcpy копирует строку из одного места в другое");
				COLOR(0x07);
				char src[24] = "ЭТО КОПИРУЕМ";
				char dst[24] = "";	
				strcpy(dst, src);
				COLOR(0x0A);
				printf("src: % s % s\n", src, &src[14]);
				printf("dst: %s %s\n", dst, &dst[14]);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 12:
				COLOR(0x0E);
				puts("#12 strncpy - Функция strncpy копирует до n байт строки из одного места в другое ");
				COLOR(0x07);
				char* str = "образец строки";
				char  buf[10] = { 0 };                  
				COLOR(0x0A);
				printf("строка: \"%s\"\n\n", str);
				printf("буфер перед копированием: \"%s\"\n", buf);
				strncpy(buf, str, sizeof(buf) - 1); 
				printf("буфер после копирования:  \"%s\"\n", buf);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 13:
				COLOR(0x0E);
				puts("#13 strcat - Функция strcat дописывает одну строку  в конец другой ");
				COLOR(0x07);
				char firstStr[] = "Cюда";
				char secondStr[] = "_Дописали";
				COLOR(0x0A);
				printf("Первая строка:%s\n", firstStr);
				strcat(firstStr,secondStr);
				printf("Вторая строка:%s\n", secondStr);
				printf("Результат: %s\n",firstStr);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 14:
				COLOR(0x0E);
				puts("#14 strncat - Функция strncat дописывает не более n байт одной строки в конец другой ");
				COLOR(0x07);
				char firstStrn[] = "Cюда допишем 4 символа 2й строки";
				char secondStrn[] = "_Дописали";
				COLOR(0x0A);
				printf("Первая строка:%s\n", firstStrn);
				strncat(firstStrn, secondStrn,4);
				printf("Вторая строка:%s\n", secondStrn);
				printf("Результат: %s\n", firstStrn);
				COLOR(0x07);
				puts("Что бы продолжить просто введите номер функции. Если Вы хотите выйти введите 0");
				break;

			case 0:
				exit(0);
				break;
			}
			
		
		} while (1);

		return 0;
}
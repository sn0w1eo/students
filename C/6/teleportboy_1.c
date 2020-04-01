#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int main()
{
	puts("\nZ-d***A/*\\pO_oBaaa, cloooose .... programmu poka ne pozdno.");
	getch();
	long longNumber = 0;
	double floatNumber = 0;
	int integerNumber = 0;	

	puts("\n             alpha to integer");
	{
		char array[] = { "228qef2" };
		integerNumber = atoi(array);
		printf_s("Result of alpha to integer: %d\n", integerNumber);
	}
	puts("\n              float to alpha");	
	{
		char array[150];
		int size = sizeof(array) / sizeof(array[0]);
		double floatNumber = 35.34;
		_gcvt_s(array, size, floatNumber, size-2);// size-2 потому что 2 байта в массиве займёт .(точка) и /0
		printf_s("Result of float to alpha: %s\n", array);
	}
	puts("\n              integer to alpha");	
	{
		char array[150];
		int size = sizeof(array) / sizeof(array[0]);
		printf_s("Enter number... or anything: ");
		scanf_s("%d", &integerNumber);
		_itoa_s(integerNumber, array, size, 16);
		printf("Result of integer to alpha (in hex): %s\n", array); 
	}
	puts("\n            alpha to long");
	{
		char array[] = { "-234dfg34" };	    
	    longNumber = atol(array);
	    printf_s("Result of alpha to long: %d\n", longNumber); 
	}
	puts("\n              string to long");	
	{
		char array[150];
		puts("Enter anything,I will try convert it to long!");
		scanf_s("%s", array, 150);
		longNumber = strtol(array, NULL, 10);
		printf_s("Result of string to long: %d\n", longNumber);
	}
	puts("\n           string to double");	

	{
		char array[75] = { "24.5423245 еба ща магия будет"};		
		floatNumber = strtod(array,NULL, 10);
		printf_s("Result of string to double: %.2lf\n", floatNumber*2);
	}

//string.h
	{
		
		char array[100];
		int size = sizeof(array) / sizeof(array[0]);
		puts("Enter anything, I will return length of your trash ");
		scanf_s("%s", array, size);
		printf_s("String length:%d\n", strlen(array));
    }

	{
		system("chcp 866");
		char array[150];
		char answer[150] = { "Перейти дорогу" };
		int size = sizeof(array) / sizeof(array[0]);
		puts("Отгадай загадку: ");
		puts("Что нужно делать, когда видишь зеленого человечка?");
		gets_s(array, size);
		while (strcmp(array,answer) != 0)
		{
			puts("Не правильно! Попытайся еще раз");
			gets_s(array, size);
		}
		puts("Нихуясебе! У тебя получилось");
	}

	{
		char *array[]= {"астрономия", "сепартизм",	"астрофизика", "ебанизм", "астры"};
		int count = 0;
		int size = sizeof(array) / sizeof(array[0]);
		for (int i = 0; i < size ; i++)
		{
			if (strncmp(array[i], "астро", 5) == 0)
			{		
			printf("Haйдeнo: %s\n", array[i]);
			count++;
		    }		
		}
		printf("Количество слов в списке начинающихся с астро: %d\n", count);
	}
	{
		char array[] = { "Hello,World!" };
		char array2[20];
		strcpy_s(array2, 20, array);
		puts(array2);
	}

	{
		puts("То же самое но без \",World!\"");
		char array[] = { "Hello,World!" };
		char array2[20];
		strncpy_s(array2, 20, array,5);
		puts(array2);
	}
	{
		puts("склеиваю строки)))");
		char array1[50] = { "Hello" };
		char array2[50] = { " Alina & Masha" };
		strcat_s(array1, 50, array2);
		puts(array1);
	}
	{
	puts("склеиваю строки ещё раз.. надоело..");
	char array1[50] = { "Hello" };
	char array2[50] = { " Alina & Masha" };
	strncat_s(array1, 50, array2, 6);
	puts(array1);
	}
}
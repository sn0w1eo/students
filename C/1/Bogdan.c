#include <stdio.h>
#include <stdlib.h>
#define name "Богдан"
int main()
{
	system("chcp 1251>nul");
	printf_s("%s\n",name );
	printf("Программа выводит список файлов диска С \n\n");
	system(" dir C:\\");
	getch();
	return 0;
}
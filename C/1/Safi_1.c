#include <stdio.h>
#include <stdlib.h>

#define name "Сафи"

int main()
{
	system("chcp 1251>nul");
	printf_s("%s\n", name);
	printf("Программа выводит список файлов диска C \n\n");
	printf("Список диска C :\n");
		system(" dir C:\\");

	return 0;
}

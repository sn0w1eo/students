#include <stdio.h>
#include <stdlib.h>
#define name "������"
int main()
{
	system("chcp 1251>nul");
	printf_s("%s\n",name );
	printf("��������� ������� ������ ������ ����� � \n\n");
	system(" dir C:\\");
	getch();
	return 0;
}
#define myName "Konstantin"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() 
{
	printf_s("\n-------------------%s-------------------\n", myName);
	puts("\n\n...The program displays a list of C drive files...\n\n");
	system("dir C:\\");
	_getch();//���� �������� � ��������,����� �����������, ��� ������ �� ����� ������ ��� �������.
	return 0;
	

}
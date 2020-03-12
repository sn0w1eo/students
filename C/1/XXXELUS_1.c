#define myName "Konstantin"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main() 
{
	printf_s("\n-------------------%s-------------------\n", myName);
	puts("\n\n...The program displays a list of C drive files...\n\n");
	system("dir C:\\");
	_getch();//Были проблемы с консолью,сразу закрывалась, что только не делал только это помогло.
	return 0;
	

}
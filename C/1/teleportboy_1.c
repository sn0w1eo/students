#define name "Kirill" 
#include <stdio.h>

int main()
{		
	puts("\n\n******************The program displays list of folders in disk C****************");
	printf_s("\n\n*************************************%s*************************************\n\n", name);	
	system("dir C:\\");
	return 0;
}
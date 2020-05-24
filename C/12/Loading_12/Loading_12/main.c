#include "stdio.h"
#include "stdlib.h"

#include "operations.h"

int main()
{
	MyStruct temp[5] = {0x00};
	add(&temp[0], "Nurik ",  2000, 321478.47 );
	add(&temp[1], "Dima  ",   1983, 655.43    );
	add(&temp[2], "Kirill", 1999, 3.8945    );
	add(&temp[3], "Nastya", 2010, 5454.651  );
	add(&temp[4], "Kostya", 2011, 5454.652  );
	printf("Ordinary list\n");
	read(temp);
	compare(temp); 
}
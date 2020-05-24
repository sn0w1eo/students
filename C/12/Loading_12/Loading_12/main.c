#include "stdio.h"
#include "stdlib.h"

#include "operations.h"

int main()
{
	MyStruct names[5] = {0x00};
	add(&names[0], "Nurik ",  2000, 321478.47 );
	add(&names[1], "Dima  ",   1983, 655.43    );
	add(&names[2], "Kirill", 1999, 3.8945    );
	add(&names[3], "Nastya", 2010, 5454.651  );
	add(&names[4], "Kostya", 2011, 5454.652  );
	printf("Ordinary list\n");
	read(names);
	compare(names); 
}
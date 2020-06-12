#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "data.h"

int main() {

	int p = 5;
	phoneBook* allList = (phoneBook*)calloc(p, sizeof(phoneBook));
	printf("\nPhoneBook\n");
	SetPhoneBook(&allList[0], "Safii", 324.57, 500233302);
	SetPhoneBook(&allList[1], "Dima", 4674.345, 705770013);
	SetPhoneBook(&allList[2], "Nurik", 21.5, 500500500);
	SetPhoneBook(&allList[3], "Nastya", 123.456, 700700700);
	SetPhoneBook(&allList[4], "Kostya", 25467.678, 555555555);
	PrintPhoneBooks(allList, p);

	//asc
	printf("\n------------------------------------\n");
	printf("\nName to ASC\n");
	qsort(allList, p, sizeof(phoneBook), sortNameToAsc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nDouble to ASC\n");
	qsort(allList, p, sizeof(phoneBook), sortDoubleToAsc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nPhone to ASC\n");
	qsort(allList, p, sizeof(phoneBook), sortPhoneToAsc);
	PrintPhoneBooks(allList, p);


	//desxc
	printf("\n------------------------------------\n");
	printf("\nName to DESC: \n");
	qsort(allList, p, sizeof(phoneBook), sortNameToDesc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nDouble to DESC\n");
	qsort(allList, p, sizeof(phoneBook), sortDoubleToDesc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nPhone to DESC\n");
	qsort(allList, p, sizeof(phoneBook), sortPhoneToDesc);
	PrintPhoneBooks(allList, p);


	free(allList);
	allList = NULL;
	return 0;
}

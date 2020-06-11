#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "Data.h"

int main() {

	int p = 5;
	phoneBook* allList = (phoneBook*)calloc(p, sizeof(phoneBook));
	printf("\nPhoneBook\n");
	SetPhoneBook(&allList[0], "Safii", 5002333023, 19);
	SetPhoneBook(&allList[1], "Dima", 705770013, 25);
	SetPhoneBook(&allList[2], "Nurik", 500500500, 21);
	SetPhoneBook(&allList[3], "Nastya", 700700700, 23);
	SetPhoneBook(&allList[4], "Kostya", 555555555, 20);
	PrintPhoneBooks(allList, p);

	//asc
	printf("\n------------------------------------\n");
	printf("\nName to ASC\n");
	qsort(allList, p, sizeof(phoneBook), sortNameToAsc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nAge to ASC\n");
	qsort(allList, p, sizeof(phoneBook), sortAgeToAsc);
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
	printf("\nAge to DESC\n");
	qsort(allList, p, sizeof(phoneBook), sortAgeToDesc);
	PrintPhoneBooks(allList, p);

	printf("\n------------------------------------\n");
	printf("\nPhone to DESC\n");
	qsort(allList, p, sizeof(phoneBook), sortPhoneToDesc);
	PrintPhoneBooks(allList, p);


	free(allList);
	allList = NULL;
	return 0;
}

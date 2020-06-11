#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "file.h"

int main() {
	FILE* fin = fopen("data.txt", "r");
	if (fin == NULL) {
		printf("FAILED\n");
		return -1;
	}


	int p = 5;
	phoneBook* allList = (phoneBook*)calloc(p, sizeof(phoneBook));
	printf("\nPhoneBook\n");
	fprintf(fin, "\nPhoneBook\n");
	SetPhoneBook(&allList[0], "Safii", 19, 5002333023);
	SetPhoneBook(&allList[1], "Dima", 25, 705770013);
	SetPhoneBook(&allList[2], "Nurik", 21, 500500500);
	SetPhoneBook(&allList[3], "Nastya", 23, 700700700);
	SetPhoneBook(&allList[4], "Kostya", 20, 555555555);
	PrintPhoneBooks(allList, p);

	wFile(fin, p);

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
	fclose(fin);
}

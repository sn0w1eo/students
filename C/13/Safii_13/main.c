#define _CRT_SECURE_NO_WARNINGS
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "file.h"

int main() {
	int p = 6;
	phoneBook* contact = (phoneBook*)calloc(p, sizeof(phoneBook));
	const int n = sizeof * contact;

	//-----------------------------------------------------------open file .txt-------------------------------------------------
	FILE* stream = NULL;
	errno_t err = fopen_s(&stream, "phonebook.txt", "w");
	if (stream == NULL || err) {
		printf("Ooops open file failed\n");
		return -1;
	}
	
	addPerson(&contact[0], "Safii", 19, 5002333023);
	addPerson(&contact[1], "Diima", 25, 705770013);
	addPerson(&contact[2], "Nurik", 21, 500500500);
	addPerson(&contact[3], "Nastya", 23, 700700700);
	addPerson(&contact[4], "Kostya", 20, 555555555);
	addPerson(&contact[5], "Sasha", 28, 777777777);

	//--------------------------------------------------------print in console---------------------------------------------------
	printf("PhoneBook\n"); 	
	PrintPhoneBook(contact, p);
	getch();

	//-------------------------------------------------------write in file .txt--------------------------------------------------

	fprintf(stream, "PhoneBook\n");
	writeDataInFileTxt(stream, contact);

	//-----------------------------------------------------sort asc in console---------------------------------------------------
	system("cls");
	printf("------------------------------------\n");
	printf("Name to ASC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortNameAsc);
	PrintPhoneBook(contact, p);
	getch();

	printf("------------------------------------\n");
	printf("Age to ASC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortAgeAsc);
	PrintPhoneBook(contact, p);
	getch();

	printf("------------------------------------\n");
	printf("Phone to ASC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortPhoneAsc);
	PrintPhoneBook(contact, p);	
	getch();


	//----------------------------------------------------sort desc in console---------------------------------------------------
	system("cls");
	printf("------------------------------------\n");
	printf("Name to DESC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortNameDesc);
	PrintPhoneBook(contact, p);
	getch();

	printf("------------------------------------\n");
	printf("Age to DESC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortAgeDesc);
	PrintPhoneBook(contact, p);
	getch();

	printf("------------------------------------\n");
	printf("Phone to DESC: \n");
	printf("------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortPhoneDesc);
	PrintPhoneBook(contact, p);
	getch();


	//------------------------------------------------------write sort in file---------------------------------------------------

	//----------------------------------------------------------asc in file------------------------------------------------------
	fprintf(stream, "Name to ASC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortNameAsc);
	writeDataInFileTxt(stream, contact);

	fprintf(stream, "------------------------------------\n");
	fprintf(stream, "Age to ASC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortAgeAsc);
	writeDataInFileTxt(stream, contact);

	fprintf(stream, "------------------------------------\n");
	fprintf(stream, "Phone to ASC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortPhoneAsc);
	writeDataInFileTxt(stream, contact);

	//---------------------------------------------------------desc in file---------------------------------------------------------
	fprintf(stream, "------------------------------------\n");
	fprintf(stream, "Name to DESC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortNameDesc);
	writeDataInFileTxt(stream, contact);

	fprintf(stream, "------------------------------------\n");
	fprintf(stream, "Age to DESC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortAgeDesc);
	writeDataInFileTxt(stream, contact);

	fprintf(stream, "------------------------------------\n");
	fprintf(stream, "Phone to DESC: \n");
	fprintf(stream, "------------------------------------\n");
	qsort(contact, p, sizeof(phoneBook), sortPhoneDesc);
	writeDataInFileTxt(stream, contact);

	//----------------------------------------------------close file-----------------------------------------------------------------
	fclose(stream);
	//------------------------------------------------------free---------------------------------------------------------------------
	free(contact);
	contact = NULL;

	return 0;
}

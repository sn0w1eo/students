#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"

struct contactData {
	int cntctNum;
	char name[15];
	char email[20];
	char phone[10];
	char zipCode[7];
};


int main() {
	FILE* cfPtr; //указатель файла
	struct contactData contact = { 0, "", "", 0, 0 };
	errno_t error = fopen_s(&cfPtr, "phone.dat", "wb"); //открытие файла для записи в бинарном режиме
		//проверка на ошибку
	if (cfPtr == NULL || error) {
		perror("Open file failed\n");
		getch();
		return -1;
	}
	else
	{
		printf("%s", "Enter contact number" " (1 to 100, 0 to end input)\n");
		scanf("%d", &contact.cntctNum);

		while (contact.cntctNum != 0) {

			printf("%s", "Enter contact name, email, phone number and zip code\n");
			fscanf(stdin, "%s%s%s%s", contact.name, contact.email, contact.phone, contact.zipCode);
			/*найти позицию указанного контакта*/
			fseek(cfPtr, (contact.cntctNum - 1) *
			sizeof(struct contactData), SEEK_SET);
			/*записать информацию в файл*/
			fwrite(&contact, sizeof(struct contactData), 1, cfPtr);
			printf("%s", "Enter contact number\n");
			scanf("%d", &contact.cntctNum);
		}
		fclose(cfPtr);
	}
	errno_t err = fopen_s(&cfPtr, "phone.dat", "rb"); //открытие файла для записи в бинарном режиме
		//проверка на ошибку
	if (cfPtr == NULL || error) {
		perror("Open file failed\n");
		getch();
		return -1;
	}
	else {
		printf("%-16s%-21s%-11s%-8s\n" , "Name", "Email", "Phone", "ZIP code");
	/*прочитать из файла все записи пока не eof */
		while ( !feof(cfPtr))
		{
			fread(&contact, sizeof(struct contactData), 1, cfPtr);
			
			if (contact.cntctNum != 0)
			{
				printf("%-16s%-21s%-11s%-8s\n", contact.name, contact.email, contact.phone, contact.zipCode);
			}
		}
		fclose(cfPtr);
	}


	return 0;
}

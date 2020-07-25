#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "string.h"
#include "stdlib.h"



typedef	struct
{
	int size;
	char name[32];
	char number[32];
	char email[16];
}contact;			 

// добавление нового юзера
void addUser(contact* persons, char name[32], char number[32], char emai[16]) {
	for (int i = 0; i < persons->size; i++)
	{
		if (persons[i].name[0] == NULL) { 
			strcpy(persons[i].name, name);
			strcpy(persons[i].number, number); 
			strcpy(persons[i].email, emai);
			break;
		}
	}
}
// записываем в .dat
void writeToDat(contact* persons)
{
		FILE* streamBin = fopen("fucking_binary.dat", "wb");
		if (streamBin == NULL) {
			printf("По пизде пошло\n");
		}
		fwrite(persons, sizeof(contact), persons->size, streamBin);
		fclose(streamBin);
}
// читаем из .dat
void readFromDat(contact* persons)
{
	
		FILE* streamBin = fopen("fucking_binary.dat", "rb");
		if (streamBin == NULL) {
			printf("По пизде пошло\n");
		}
		fread(persons, sizeof(contact), persons->size, streamBin);
		fclose(streamBin);
		streamBin = NULL;
	
}
// вывод в консоль 
void print(contact* persons) {
	
		printf("\n-_-READING FROM A FUCKING BINARY-_-\n");
		for (int i = 0; i < persons->size; i++)
		{
			printf("\n%-24s %-24s %-16s\n", persons[i].name, persons[i].number, persons[i].email);
		}
	
}


int main() {
	contact* users = (contact*)calloc(3, sizeof(contact));
	if (users == NULL) {
		printf("Все пошло по пизде...");
		return -1;                       
	}
	users->size = 3;
	addUser(users, "Loqiemean", "44444444", "loqie@mail.com");
	addUser(users, "Skriptonit", "78846544", "skrip@jjjf.com");
	addUser(users, "Oxxxy", "778899665544", "ox@u.ru");
	writeToDat(users);           
	readFromDat(users); 
	print(users);   
	/*for (int i = 0; i < users->size; i++) {
		free(users[i].name);
		free(users[i].email);
		free(users[i].number);	
	}
	free(users);
	users = NULL;*/
}

#include "stdio.h"
#include "stdlib.h"
#include "phonebook.h"

int main()
{
	char* buffer = calloc(1000, sizeof(char));
	
	InitDataBase();
	CreateTable();
	
	AddRecordToDataBase(1, "Kirill", "0555661796", "boyteleport@gmail.com");
	AddRecordToDataBase(2, "Masha", "0553307237", "exorcism@gmail.com");
	AddRecordToDataBase(3, "Erlan", "0772559119", "bobby312@gmail.com");
	
	//UpdateRecordInDataBase(2, "Masha", "0559309306", "lanaya@yandex.ru");	
	//DeleteRecordInDataBase(1);

	LoadRecordsFromDataBaseToArray(buffer);
	
	printf("%s", buffer);
	
	CloseDataBase();
}
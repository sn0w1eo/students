#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "phonebook.h"

int main()
{
	DBInfo db;

	InitDB(&db);
	CreateTable(&db);

	AddRecordToDB(&db, 1, "Kirill", "0555661796", "boyteleport@gmail.com");
	AddRecordToDB(&db, 2, "Masha", "0553307237", "exorcism@gmail.com");
	AddRecordToDB(&db, 3, "Erlan", "0772559119", "bobby312@gmail.com");

	ClodeDB(&db);
}
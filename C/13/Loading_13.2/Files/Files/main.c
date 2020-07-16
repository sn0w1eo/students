#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "phoneBook.h"

int main()
{
	contact* person = calloc(1,sizeof(contact));
	person->size = 1;
	person = addPerson(person, "Nurik", "0700556611", "20");
	person = addPerson(person, "Dima  ", "0550988552", "25");
	person = addPerson(person, "Kirill", "0755122356", "22");
	person = addPerson(person, "Nastya", "0500575859", "30");
	person = addPerson(person, "Kostya", "0900536332", "28");
	person = addPerson(person, "Safi", "0200112233", "29");
	person = addPerson(person, "Bogdan", "0500118899", "15");

	writeToFile(person, Text);
	writeToFile(person, Binary);

	readFromFile(person, Text);
	readFromFile(person, Binary);

	freeMemory(person);
}
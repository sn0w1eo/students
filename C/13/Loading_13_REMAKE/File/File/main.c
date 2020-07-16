#include "stdio.h"
#include "stdlib.h"
#include "operations.h"

// Work with files

int main() {
	contact* persons = calloc(7, sizeof(contact));
	if (persons == NULL){
		printf("Not memory");
		return -1;                       // Return if memory is not allocated
	}
	persons->size = 7;
	addPerson(persons, "Dima", "0550988552", "25");
	addPerson(persons, "Safi", "0200112233", "29");
	addPerson(persons, "Nurik", "0700556611", "20");
	addPerson(persons, "Kirill", "0755122356", "22");
	addPerson(persons, "Nastya", "0500575859", "30");
	addPerson(persons, "Kostya", "0900536332", "28");
	addPerson(persons, "Bogdan", "0500118899", "15");
	
	writeToFile(persons, Text);           // Write data to Text File
	writeToFile(persons, Binary);         // Write data to Binary File
	
	readFromFileToArray(persons, Binary); // Read data from Binary File
	printDataToConsole(persons,Binary);   // Write data from Binary File to Console
	
	readFromFileToArray(persons, Text);   // Read data from Text File
	printDataToConsole(persons, Text);    // Write data from Text File to Console
	
}
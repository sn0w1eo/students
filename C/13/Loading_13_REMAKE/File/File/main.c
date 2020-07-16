#include "stdio.h"
#include "stdlib.h"
#include "operations.h"

// Work with files

int main() {
	contact* person = calloc(7, sizeof(contact));
	if (person == NULL){
		printf("Not memory");
		return -1;                       // Return if memory is not allocated
	}
	person->size = 7;
	addPerson(person, "Dima", "0550988552", "25");
	addPerson(person, "Safi", "0200112233", "29");
	addPerson(person, "Nurik", "0700556611", "20");
	addPerson(person, "Kirill", "0755122356", "22");
	addPerson(person, "Nastya", "0500575859", "30");
	addPerson(person, "Kostya", "0900536332", "28");
	addPerson(person, "Bogdan", "0500118899", "15");
	
	writeToFile(person, Text);           // Write data to Text File
	writeToFile(person, Binary);         // Write data to Binary File
	
	readFromFileToArray(person, Binary); // Read data from Binary File
	printDataToConsole(person,Binary);   // Write data from Binary File to Console
	
	readFromFileToArray(person, Text);   // Read data from Text File
	printDataToConsole(person, Text);    // Write data from Text File to Console
	
}
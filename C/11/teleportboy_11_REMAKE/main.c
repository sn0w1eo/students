#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"

void UpdateScreen()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tpress any key......");
	getchar();
	system("cls");
}

int main()
{
	PHONEBOOK* phoneBook = GetMemory(5);
	PHONEBOOK** searchBook = NULL;

	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", 1);
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", 2);

	phoneBook = AddContact(phoneBook, "JK2Apparel", "+1 111 222 3333", "jk2@apparel@gmail.com", 3);
	phoneBook = AddContact(phoneBook, "Is_Yellow_Flash", "+3652342343", "Is_Yellow_Flash@gmail.com", 1);
	phoneBook = AddContact(phoneBook, "Re_Illyminat", "+345453233243", "Re_Illyminat@gmail.com", 1);
	phoneBook = AddContact(phoneBook, "Incubus", "+153533555", "INDUS@gmail.com", 5);
	phoneBook = AddContact(phoneBook, "Unryze", "+74957556983", "Unryze@gmail.com", 5);
	phoneBook = AddContact(phoneBook, "Much2Much", "+74957556983", "much2much@gmail.com", 1);
	phoneBook = AddContact(phoneBook, "UK_Moscow", "+74957888888", "UK_Moscow@gmail.com", 1);
	phoneBook = AddContact(phoneBook, "Mafon", "+78907246163", "Mafon@gmail.com", 6);
	phoneBook = AddContact(phoneBook, "Jet", "+81037501710011", "Jet@gmail.com", 7);
	phoneBook = AddContact(phoneBook, "KomiCityBears", "+78907556083", "KomiCityBears@gmail.com", 5);
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", 7);
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", 6);
	PrintContacts(phoneBook);

	//UpdateScreen();
	//UpdateContact(phoneBook, "Loading", "+996777777777", "Loading@gmail.com", 2, 1);
	//PrintContacts(phoneBook);
	//
	//UpdateScreen();
	//DeleteContact(phoneBook, 9);
	//DeleteContact(phoneBook, 10);
	//PrintContacts(phoneBook);

	//UpdateScreen();
	//searchBook = FindByName(phoneBook, searchBook, "teleportboy");
	//PrintSeachResults(searchBook, phoneBook->size);
	//free(searchBook);
	//searchBook = NULL;

	//UpdateScreen();
	//searchBook = FindByPhoneNumber(phoneBook, searchBook, "+74957556983");
	//PrintSeachResults(searchBook, phoneBook->size);
	//free(searchBook);
	//searchBook = NULL;

	//UpdateScreen();
	//searchBook = FindByEmail(phoneBook, searchBook, "boyteleport@gmail.com");
	//PrintSeachResults(searchBook, phoneBook->size);
	//free(searchBook);
	//searchBook = NULL;

	//UpdateScreen();
	//searchBook = FindByZipCode(phoneBook, searchBook, 4324);
	//PrintSeachResults(searchBook, phoneBook->size);
	//free(searchBook);
	//searchBook = NULL;

	FreeMemory(phoneBook);
}
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"

#include "phonebook.h"
#include "memory.h"
#include "search.h"
#include "fileio.h" 

void UpdateScreen()
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tpress any key......");
	getchar();
	system("cls");
}

int main()
{
	PhoneBook* phoneBook = GetMemory(1);
	PhoneBook* phoneBookForTXT = NULL;
	PhoneBook** searchBook = NULL;

	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "11");
	phoneBook = AddContact(phoneBook, "JK2Apparel", "+11112223333", "jk2@apparel@gmail.com", "1");	
	phoneBook = AddContact(phoneBook, "Is_Yellow_Flash", "+3652342343", "Is_Yellow_Flash@gmail.com", "2");
	phoneBook = AddContact(phoneBook, "Re_Illyminat", "+345453233243", "Re_Illyminat@gmail.com", "3");
	phoneBook = AddContact(phoneBook, "Incubus", "+153533555", "INDUS@gmail.com", "4");
	phoneBook = AddContact(phoneBook, "Unryze", "+74957556983", "Unryze@gmail.com", "5");
	phoneBook = AddContact(phoneBook, "Much2Much", "+74957556983", "much2much@gmail.com", "6");
	phoneBook = AddContact(phoneBook, "UK_Moscow", "+74957888888", "UK_Moscow@gmail.com", "7");
	phoneBook = AddContact(phoneBook, "Mafon", "+78907246163", "Mafon@gmail.com", "8");
	phoneBook = AddContact(phoneBook, "Jet", "+81037501710011", "Jet@gmail.com", "9");
	phoneBook = AddContact(phoneBook, "KomiCityBears", "+78907556083", "KomiCityBears@gmail.com", "10");
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "14");

	qsort(phoneBook, GetContactsCount(phoneBook), sizeof(PhoneBook), AscendingCompareByName);

	RecordInfoToTXT(phoneBook);

	//getch();

	phoneBookForTXT = ReadInfoFromFile(phoneBookForTXT);
	if (phoneBookForTXT == NULL)
	{
		exit(1);
	}
	UpdateScreen();
	PrintContacts(phoneBookForTXT);

	UpdateScreen();
	PrintContacts(phoneBook);

	UpdateScreen();

	DeleteContacts(phoneBook, 3, 4, 5, 6);
	PrintContacts(phoneBook);

	UpdateScreen();

	UpdateContact(phoneBook, "Loading", "+996777777777", "Loading@gmail.com", "2222", 3);
	PrintContacts(phoneBook);

	UpdateScreen();

	searchBook = DoSearch(phoneBook, searchBook, "Unryze@gmail.com", FindByEmail);
	PrintSeachResults(searchBook, GetSize(phoneBook));


	FreeMemory(phoneBook, phoneBookForTXT, searchBook);

	return 0;
}
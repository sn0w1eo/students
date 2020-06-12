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
	PhoneBook* phoneBook = calloc(1, sizeof(PhoneBook));
	phoneBook->contacts = InitStorageForContacts(5);
	PhoneBook* searchResults = calloc(1, sizeof(PhoneBook));
	PhoneBook* readingFromTXT = calloc(1, sizeof(PhoneBook));
	if (phoneBook == NULL || searchResults == NULL || readingFromTXT == NULL)
	{
		exit(1);
		printf("MEMORY ALLOCATED FALIED IN MAIN!");
	}

	AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "11");
	AddContact(phoneBook, "JK2Apparel", "+11112223333", "jk2@apparel@gmail.com", "1");
	AddContact(phoneBook, "Is_Yellow_Flash", "+3652342343", "Is_Yellow_Flash@gmail.com", "2");
	AddContact(phoneBook, "Re_Illyminat", "+345453233243", "Re_Illyminat@gmail.com", "3");
	AddContact(phoneBook, "Incubus", "+153533555", "INDUS@gmail.com", "4");
	AddContact(phoneBook, "Unryze", "+74957556983", "Unryze@gmail.com", "5");
	AddContact(phoneBook, "Much2Much", "+74957556983", "much2much@gmail.com", "6");
	AddContact(phoneBook, "UK_Moscow", "+74957888888", "UK_Moscow@gmail.com", "7");
	AddContact(phoneBook, "Mafon", "+78907246163", "Mafon@gmail.com", "8");
	AddContact(phoneBook, "Jet", "+81037501710011", "Jet@gmail.com", "9");
	AddContact(phoneBook, "KomiCityBears", "+78907556083", "KomiCityBears@gmail.com", "10");
	
	DeleteContacts(phoneBook->contacts, 3, 9, 10, 11);
	UpdateContact(&phoneBook->contacts[3], "Loading", "+996777777777", "Loading@gmail.com", "2222");

	qsort(phoneBook->contacts, GetContactsCount(phoneBook->contacts), sizeof(ContactData), AscendingCompareByZipCode);
	
	//Работа с txt файлом
	RecordInfoToTXT(phoneBook);
	ReadInfoFromFile(readingFromTXT);
	PrintContacts(readingFromTXT->contacts);

	//Работа с бинарным режимом
	UpdateScreen();
	Contact* binaryReadingFromDAT = calloc(GetContactsCount(phoneBook->contacts), sizeof(Contact));
	BinaryRecordInfoToDAT(phoneBook);
	BinaryReadInfoFromFile(binaryReadingFromDAT, GetContactsCount(phoneBook->contacts));
	PrintContactsBinMode(binaryReadingFromDAT, GetContactsCount(phoneBook->contacts));
	
	UpdateScreen();
	PrintContacts(phoneBook->contacts);
	
	DoContactSearch(phoneBook, searchResults, "14", ZipCode);
	
	UpdateScreen();
	PrintContacts(searchResults->contacts);

	FreeMemory(phoneBook, searchResults, readingFromTXT, binaryReadingFromDAT);
}
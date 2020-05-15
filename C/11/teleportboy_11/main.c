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
	PHONEBOOK* phoneBook = GetMemory(2);
	PHONEBOOK** searchBook = NULL;
	
	//Добавить контакт.
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "11");
	phoneBook = AddContact(phoneBook, "JK2Apparel", "+1 111 222 3333", "jk2@apparel@gmail.com", "1");
	phoneBook = AddContact(phoneBook, "Is_Yellow_Flash", "+3652342343", "Is_Yellow_Flash@gmail.com", "2");
	phoneBook = AddContact(phoneBook, "Re_Illyminat", "+345453233243", "Re_Illyminat@gmail.com", "3");
	phoneBook = AddContact(phoneBook, "Incubus", "+153533555", "INDUS@gmail.com", "4");
	phoneBook = AddContact(phoneBook, "Unryze", "+74957556983", "Unryze@gmail.com", "5");
	phoneBook = AddContact(phoneBook, "Much2Much", "+74957556983", "much2much@gmail.com", "6");
	phoneBook = AddContact(phoneBook, "UK_Moscow", "+74957888888", "UK_Moscow@gmail.com", "7");
	phoneBook = AddContact(phoneBook, "Mafon", "+78907246163", "Mafon@gmail.com", "8");
	phoneBook = AddContact(phoneBook, "Jet", "+81037501710011", "Jet@gmail.com", "9");
	phoneBook = AddContact(phoneBook, "KomiCityBears", "+78907556083", "KomiCityBears@gmail.com", "10");
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "11");
	phoneBook = AddContact(phoneBook, "teleportboy", "+996555661796", "boyteleport@gmail.com", "11");
	PrintContacts(phoneBook);	
	
	//Удалить контакт.
	UpdateScreen();
	DeleteContacts(phoneBook, 3, 4, 5, 6);
	PrintContacts(phoneBook);

	//Изменить контакт.
	UpdateScreen();
	UpdateContact(phoneBook, "Loading", "+996777777777", "Loading@gmail.com", "1337", 3);
	PrintContacts(phoneBook);

	//Искать контакт.
	UpdateScreen();
	searchBook = DoSearch(phoneBook, searchBook, "boyteleport@gmail.com", FindByEmail);
	PrintSeachResults(searchBook, GetSize(*phoneBook));
	
	//Освободить память.
	free(searchBook);
	searchBook = NULL;
	
	FreeMemory(phoneBook);
	

}
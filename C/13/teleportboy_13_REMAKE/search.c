#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "phonebook.h"
#include "search.h"
#include "memory.h"

//Выполнить поиск котактов.
void DoContactSearch(PhoneBook* phoneBook, PhoneBook* searchResults, string searchPurpose, enum ContactInfo searchType)
{
	int maxNumberOfSearchResults = GetSize(phoneBook->contacts);
	string infoFromContact = NULL;
	
	//Выделить память для хранения указателей на ячейки другого массива типа ContactData.
	searchResults->contacts = InitStorageForContacts(maxNumberOfSearchResults);

	for (int i = 0; i < maxNumberOfSearchResults; i++)
	{
		//Получить информацию с контакта, взависимости от типа поиска.
		infoFromContact = GetContactDataFieldByArgument(phoneBook->contacts[i], searchType);
		if (infoFromContact == NULL)
		{
			continue;
		}

		//Сравнить раннее полученную информацию с искоемой информацией.
		if (strcmp(infoFromContact, searchPurpose) == 0)
		{
			searchResults->contacts[i] = phoneBook->contacts[i];
		}
	}
}
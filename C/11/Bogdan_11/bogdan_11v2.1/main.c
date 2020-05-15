#include "stdio.h"
#include "crtdbg.h"

#include "database.h"

int main() {

	
	book book = { 0 };



	book = addNumber(book, "Bogdan", "0770368836", "bkominarets@gmail.com", "123");
	book = addNumber(book, "Dima", "05553953223", "asdf@com", "435");
	book = addNumber(book, "Nina", "05235", "g.com", "233");
	book = addNumber(book, "Bogdan", "0770368836", "bkominarets@gmail.com", "123");


	deleteContact(findName(book, "Nina"));
	
	iteratePersons(book, printContacts, ITERATE_NON_FREE);




	printf("\n\nSEARCH RESULTS BY NAME:\n");
	printf("-----------------------\n");

	struct MatchPersons rez = findPersonsByName(book, "Bogdan");
	for (size_t i = 0; i < rez.size; i++) {
		printf("\nName: %s\n", rez.findPersons[i]->name);
		printf("Number: %s\n", rez.findPersons[i]->number);
		printf("Email: %s\n", rez.findPersons[i]->email);
		printf("Zip: %s\n", rez.findPersons[i]->zip);
	}


	freeContacts(book);

	getchar();
	


}
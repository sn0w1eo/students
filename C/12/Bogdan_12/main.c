#include "stdio.h"
#include "algorithm.h"




int main() {
	

	data db = initStorage(20);
	addPerson(&db, "Bogdan", 29, 123.123);
	addPerson(&db, "Dima", 13, 136.123);
	addPerson(&db, "Artur", 234, 1.123);
	addPerson(&db, "Ira", 45, 123.233);
	addPerson(&db, "Kirill", 5, 14.123);


	sort(&db, byName, descending);         // byName, byAge, byEarnings //ascending ,descending 
	
	printStorage(&db);
	freeStorage(&db);


}
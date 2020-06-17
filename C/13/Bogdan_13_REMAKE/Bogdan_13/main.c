
#include "stdio.h"
#include "algorithm.h"




int main() {
	

	data db = initStorage(20);
	addPerson(&db, "Bogdan", 29, 123.123);
	addPerson(&db, "Dima", 13, 136.123);
	addPerson(&db, "Artur", 234, 1.123);
	addPerson(&db, "Ira", 45, 123.233);
	addPerson(&db, "Kirill", 5, 14.123);


	sortStorage(&db, byName, descending);         // byName, byAge, byEarnings //ascending ,descending 

	


	//writeToFileBin(&db);
	writeToFileTxt(&db);

	//size_t numberOfPerson = readNumberFromFileDat(&db);
	size_t numberOfPerson = readNumberFromFileTxt(&db);

	dataFile databaseFile = initStorageForFile(numberOfPerson);
	if (databaseFile.person == NULL) {
		return -1;
	}
	
	//addPersonsFromFileBin(&databaseFile);
	addPersonsFromFileTxt(&databaseFile);

	printStorageFromFile(&databaseFile);
	freeStorageFile(&databaseFile);

	return 0;
}
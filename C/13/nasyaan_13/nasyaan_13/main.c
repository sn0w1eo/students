#define _CRT_SECURE_NO_WARNINGS

#include "db.h"
#include "newfile.h"


void print(struct Contact* contact) {
	printf("    Name: %s\n", getName(contact));
	printf("   Phone: %lld\n", getPhone(contact));
	printf("   Email: %s\n", getEmail(contact));
	printf("Zip Code: %d\n\n", getZipCode(contact));
}

int main() {
	struct Database db = newDatabase(8);

	FILE* streamTxt = NULL;
	errno_t err = fopen_s(&streamTxt, "phone.txt", "w+");
	if (streamTxt == NULL || err) {
		printf("Open file failed\n");
		getch();
		return -1;
	}

	FILE* streamBin = NULL;
	errno_t error = fopen_s(&streamBin, "phone.dat", "wb+");
	if (streamBin == NULL || error) {
		perror("Open file failed\n");
		getch();
		return -1;
	}

	addContact(db, "Dima", 705770013, "snowleo@gmail.com", 720075);
	addContact(db, "Nurik", 709233778, "loading@gmail.com", 720037);
	addContact(db, "Kirill", 555661796, "teleportboy@gmail.com", 720037);
	addContact(db, "Kostya", 553233717, "xxxelus@gmail.com", 722200);
	addContact(db, "Nastya", 700436842, "nasyaan@gmail.com", 720005);
	addContact(db, "Bermet", 777777777, "m1bee@gmail.com", 720052);
	addContact(db, "Bogdan", 555555555, "bogdan@gmail.com", 720064);
	addContact(db, "Safi", 77777777, "safi@gmail.com", 720001);

	removeContact(db, findContactByName(db, "Bogdan"));

	iterateContacts(db, print, ITERATE_NON_FREE);

	{
		printf("SEARCH RESULTS BY NAME:\n");
		printf("-----------------------\n");
		struct MatchContacts results = findContactsByName(db, "Dima");
		for (int i = 0; i < results.size; i++) {
			print(results.contacts[i]);
		}
		printf("-----------------------\n\n");
	}
	{
		printf("SEARCH RESULTS BY PHONE:\n");
		printf("-----------------------\n");
		struct MatchContacts results = findContactsByPhone(db, 700436842);
		for (int i = 0; i < results.size; i++) {
			print(results.contacts[i]);
		}
		printf("-----------------------\n\n");
	}
	{
		printf("SEARCH RESULTS BY EMAIL:\n");
		printf("-----------------------\n");
		struct MatchContacts results = findContactsByEmail(db, "m1bee@gmail.com");
		for (int i = 0; i < results.size; i++) {
			print(results.contacts[i]);
		}
		printf("-----------------------\n\n");
	}

	{
		printf("SEARCH RESULTS BY ZIP CODE:\n");
		printf("-----------------------\n");
		struct MatchContacts results = findContactsByZipCode(db, 720037);
		for (int i = 0; i < results.size; i++) {
			print(results.contacts[i]);
		}
		printf("-----------------------\n\n");
	}
	printf("The binary file is written..\n\n");
	writingToFile(streamBin, db, print);
	fseek(streamBin, 0, SEEK_END);
	printf("Size of phone.dat = %d bytes\n\n", ftell(streamBin));
	fclose(streamBin);
	readingFile(streamBin, db, print);
	printf("\nThe text file is written..\n\n");
	writingToFile(streamTxt, db, print);
	fseek(streamTxt, 0, SEEK_END);
	printf("Size of phone.txt = %d bytes\n\n", ftell(streamTxt));
	fclose(streamTxt);
	readingFile(streamTxt, db, print);
	deleteDatabase(&db);
	getch();
}
#include "addFile.h"
#include "addConsole.h"


int main()
{
	FILE* stream = fopen("phone.txt", "w+");
	if (stream == NULL) {
		printf("ooops open file failed\n");
		return -1;
	}

	FILE* streamBin = fopen("phone1.dat", "wb+");
	if (streamBin == NULL) {
		printf("ooops open file failed\n");
		return -1;
	}

	MyStruct contact[5] = {0x00};
	add(&contact[0], "Nurik ", 20, "0700561232");
	add(&contact[1], "Dima  ", 19, "0550988552");
	add(&contact[2], "Kirill", 19, "0755122356");
	add(&contact[3], "Nastya", 20, "0500575859");
	add(&contact[4], "Kostya", 21, "0900536332");

	printf("Ordinary list\n");
	fprintf(stream, "Ordinary list\n");

	//fprintf(streamBin, "Ordinary list\n");
	//writeFile(streamBin, contact);

	writeFile(stream, contact);

	//writeFile(streamBin, contact);

	read(contact);
	
	compare(stream,contact);
	//compare(streamBin, contact);
	compareConsole(contact);
	fwrite(stream, sizeof(FILE*), 385, streamBin);
	fclose(stream);
	fclose(streamBin);
}
#include "newfile.h"
#include "db.h"

void txtWritingToFile(FILE* streamTxt, const struct Database db, void(*callback)(struct Contact*)) {
    errno_t err = fopen_s(&streamTxt, "phone.txt", "w+");

    if (streamTxt == NULL || err) {
        printf("Open file failed\n");
        getch();
        return -1;
    }

	for (int i = 0; i < db.size; i++) {

		if (db.contacts[i].name!=NULL)
		{
			fprintf(streamTxt, "%s %lld %s %d\n\n", db.contacts[i].name, db.contacts[i].phone, db.contacts[i].email, db.contacts[i].zipCode);
		}
	}

    fseek(streamTxt, 0, SEEK_END);
    printf("Size of phone.txt = %d bytes\n\n", ftell(streamTxt));
    fclose(streamTxt);
}

void binWritingToFile(FILE* streamBin, const struct Database db, void(*callback)(struct Contact*)) {
    errno_t error = fopen_s(&streamBin, "phone.dat", "wb+");

    if (streamBin == NULL || error) {
        perror("Open file failed\n");
        getch();
        return -1;
    }

    for (int i = 0; i < db.size; i++) {

        if (db.contacts[i].name != NULL)
        {
            fprintf(streamBin, "%s %lld %s %d\n\n", db.contacts[i].name, db.contacts[i].phone, db.contacts[i].email, db.contacts[i].zipCode);
        }
    }

    fseek(streamBin, 0, SEEK_END);
    printf("Size of phone.dat = %d bytes\n\n", ftell(streamBin));
    fclose(streamBin);
}

int readingTxtFile(FILE* streamTxt, const struct Database db, void(*callback)(struct Contact*)) {
    errno_t err = fopen_s(&streamTxt, "phone.txt", "r+");
    int size = sizeof(struct Contact);
    struct Contact* ptr = (struct Contact*) malloc(size);

    if (streamTxt == NULL || err) {
        printf("Open file failed\n");
        getch();
        return -1;
    }

    int ch;
    while ((ch = fgetc(streamTxt)) != EOF) {
        fprintf(stdout, "%c", ch);
    }

    fclose(streamTxt);
    free(ptr);
    return 0;
}
    
int readingBinFile(FILE* streamBin, const struct Database db, void(*callback)(struct Contact*)){
    errno_t error = fopen_s(&streamBin, "phone.dat", "r+");
    int ch;
    int size = sizeof(struct Contact);
    struct Contact* ptr = (struct Contact*) malloc(size);

    if (streamBin == NULL || error) {
        printf("Open file failed\n");
        getch();
        return -1;
    }

    while ((ch = fgetc(streamBin)) != EOF) {  
    		fprintf(stdout, "%c", ch);
    	}

    fclose(streamBin);
    free(ptr);
    
}
    
#include "newfile.h"
#include "db.h"

void writingToFile(FILE* streamTxt, const struct Database db, void(*callback)(struct contact*)) {

	for (int i = 0; i < db.size; i++) {
		if (db.contacts[i].name!=NULL)
		{
			fprintf(streamTxt, "name: %s, phone: %lld, email: %s, zipCode: %d\n\n", db.contacts[i].name, db.contacts[i].phone, db.contacts[i].email, db.contacts[i].zipCode);
			/*printf("name: %s, phone: %lld, email: %s, zipCode: %d\n\n", db.contacts[i].name, db.contacts[i].phone, db.contacts[i].email, db.contacts[i].zipCode);*/
		}
	}
}

int readingFile(FILE* stream, const struct Database db, void(*callback)(struct contact*))
    {
        printf("Reading struct from file:\n\n");
        	fseek(stream, 0, SEEK_SET);
        	fread(&db, sizeof(db), 1, stream);
            for (int i = 0; i < db.size; i++) {
                if (db.contacts[i].name != NULL)
                {
                    printf("name: %s, phone: %lld, email: %s, zipCode: %d\n\n", db.contacts[i].name, db.contacts[i].phone, db.contacts[i].email, db.contacts[i].zipCode);
                }
            }
   
        fclose(stream);
   
     }
    
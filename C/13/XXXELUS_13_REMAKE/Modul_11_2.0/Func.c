#define _CRT_SECURE_NO_WARNINGS
#include "Func.h"

int busy;



/*Save*/


// Read
void readBinary(contact* stream, FILE* strg) {
	char i = 0;
	int lines = 0;
	char ch;
	strg = freeMemory(strg);
	stream = fopen("Report.dat", "rd");
	if (stream == NULL) {
		printf("ERROR");
		return -1;
	}
	while ((ch = fgetc(stream)) != EOF) {
		if (ch == '>') {
			lines++;
		}
		else { continue; }
	}
	if (strg == NULL) {
		strg = initStorage(lines);
		setSize(strg, lines);
	}
	fclose(stream);
	overwriteFromFile(stream, strg);
}

int readTextFile(FILE* stream, contact* strg) {

	int lines = 0;
	char ch;
	stream = fopen("Report.txt", "r");
	if (stream == NULL) {
		printf("ERROR");
		return -1;
	}
	while ((ch = fgetc(stream)) != EOF) {
		if (ch == '>') {
			lines++;
		}
		else { continue; }
	}
	if (strg == NULL) {
		strg = initStorage(lines);
		setSize(strg, lines);
	}
	fclose(stream);
	overwriteFromFile(stream, strg);
}

void read(FILE* stream, contact* strg, int param) {
	switch (param)
	{
	case Text: readTextFile(stream, strg);
		break;
	case Binary: readBinary(stream, strg);
		break;
	default:
		printf("Invalid param");
		break;
	}
}


//Write
void saveToBin(contact* strg, FILE* stream) {
	int size = getSize(*strg);
	stream = fopen("Report.dat", "wb");
	if (stream == NULL) {
		printf("ERROR");
		return -1;
	}
	for (int i = 0; i < size; i++) {
		if (getName(strg[i]) != NULL) {
			fprintf(stream, "> %s  %s  %s  %s\n", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}
	fclose(stream);
	
}

void saveToText(contact* strg, FILE* stream) {
	int size = getSize(*strg);
	stream = fopen("Report.txt", "w");
	if (stream == NULL) {
		printf("ERROR");
		return -1;
	}
	for (int i = 0; i < size; i++) {
		if (getName(strg[i]) != NULL) {
			fprintf(stream,"> %s  %s  %s  %s\n",  strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}

}

void overwriteFromFile(FILE* st,contact* strg) {
	
	char name[20], number[80], email[30], zip[20],tmp[2];
	int i = 0;
	st = fopen("Report.txt", "r");
	while (fscanf(st,"%s%s%s%s%s", tmp,name, number, email, zip) != EOF)
	{
		strg = add(strg, name, number, email, zip);
		i++;
	}
	sortShow(strg);
	for (int j = 0; j < sizeof(tmp); j++) {
		tmp[j] =  NULL ;
	}
	fclose(st);
}

void save(FILE* stream, contact* strg,int param) {
	switch (param)
	{
	case Text:saveToText(strg, stream);
		break;
	case Binary:saveToBin(strg, stream);
		break;

	default:
		printf("Invalid param");
		break;
	}
		
	

}



/*Set*/

void setSize(contact* storage,size_t size) {
	storage->size = size;
}

void setName(contact* strg,  str name) {
	strg->name = _strdup(name);
	
}

void setNumber(contact* strg, const str number){
	strg->number = _strdup(number);
}

void setMail(contact* strg, const str email) {
	strg->email = _strdup(email);
}

void setZip(contact* strg, const str zip) {
	strg->zipCode = _strdup(zip);
}

void setUser(contact* strg, const str name, const str number, const str email, const str zip) {
	setName(strg, name);
	setNumber(strg, number);
	setMail(strg, email);
	setZip(strg, zip);
}


/*Get*/


int getSize(contact strg) {
	return strg.size;
}

str getName(contact strg) {
	return strg.name;
}

str getNumber(contact strg) {
	return strg.number;
}

str getMail(contact strg) {
	return strg.email;
}

str getZip(contact strg) {
	return strg.zipCode;
}

contact* getAdress(contact* strg) {
	int size = getSize(*strg);
	int i = 0;
	for (; i < size; i++) {
		if (getName(strg[i]) == NULL) {
			break;
		}
	}
	return &strg[i];
}


/*Memory*/

contact* initStorage(size_t size){
	contact* storage = NULL;
	if (size <= 0) {
		size = 2;
	 }
	if (storage == NULL) {
		storage = (contact*)calloc(size, sizeof(contact));
		if (storage == NULL) {
			return storage;
		}
		setSize(storage, size);
	}
	return storage;
}
contact* reallocStorage(contact* strg) {
	int size = getSize(*strg) * 2;
	setSize(strg, size);
	strg = realloc(strg, size * sizeof(contact));;
	for (int i = size / 2; i < size; i++) {
		setUser(&strg[i], NULL, NULL, NULL, NULL);
	}
	return strg;
}
contact* freeMemory(contact* strg) {
	size_t size = getSize(*strg);
	for (int i = 0; i < size; i++) {
		if (strg[i].name != NULL && strg[i].number!=NULL && strg[i].email!=NULL && strg[i].zipCode!=NULL) {
			free(strg[i].name);
			free(strg[i].number);
			free(strg[i].email);
			free(strg[i].zipCode);
			strg[i].name = NULL;
			strg[i].email = NULL;
			strg[i].number = NULL;
			strg[i].zipCode = NULL;
			strg[i].size = NULL;
		}
	}
	free(strg);
	strg = NULL;
	return strg;
}


/*Editing*/

contact* add(contact *strg, const str name, const str number, const str email, const str zip) {
	contact* newUser = NULL;
	switch (freePlace(strg))
	{
	case true:
		newUser = getAdress(strg);
		break;
	case false:
		strg = reallocStorage(strg);
		newUser = getAdress(strg);
		break;
	}
	
	setUser(newUser, name, number, email, zip);	
	return strg;
}

contact* update(contact* strg, const str name, const str number, const str email, const str zip, int index) {
	setUser(&strg[index], name, number, email, zip);
}

contact* updateName(contact* strg, const str name, int index) {
	setName(&strg[index], name);
}

contact* updateNumber(contact* strg, const str number, int index) {
	setNumber(&strg[index], number);
}

contact* updateMail(contact* strg, const str mail, int index) {
	setMail(&strg[index], mail);
}

contact* updateZip(contact* strg, const str zip,int index) {
	setZip(&strg[index],zip);
}

contact* delete(contact* strg, int index){
	free(strg[index].name);
	free(strg[index].number);
	free(strg[index].zipCode);
	free(strg[index].email);
	setUser(&strg[index], NULL, NULL, NULL, NULL);
}


/*Searching*/


void srhName(contact* strg, str name) {
	int size = getSize(*strg);
	int check = false;
	printf("\n all contacts with name %s : ", name);
	for (int i = 0; i < size; i++) {
		if (getName(strg[i]) == NULL) {
			continue; }
		else {
			if (_stricmp(strg[i].name, name) == 0) {
				printf("\n name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
				check = true;
			}
		}		
	}
	if (check == false) {
		printf("\nNot found!\n");
	}
}

void srhNumber(contact* strg, str number) {
	int size = getSize(*strg);
	int check = false;
	printf("\n all contacts with number %s : ", number);
	for (int i = 0; i < size; i++) {
		if (getNumber(strg[i]) == NULL) {
			continue;
		}
		else {
			if (_stricmp(strg[i].number, number) == 0) {
				if (getNumber(strg[i]) != NULL) {
					printf("\n name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n\n", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
				}
				check = true;
			}
		}
	}
	if (check == false) {
		printf("\nNot found!\n");
	}
}

void srhMail(contact* strg, str mail) {
	int size = getSize(*strg);
	int check = false;
	printf("\n all contacts with eMail %s : ", mail);
	for (int i = 0; i < size; i++) {
		if (getMail(strg[i]) == NULL) {
			continue;
		}
		else {
			if (_stricmp(strg[i].email, mail) == 0) {
				if (getMail(strg[i]) != NULL) {
					printf("\n name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
				}
				check = true;
			}
		}
	}
	if (check == false) {
		printf("\nNot found!\n");
	}
}

void srhZip(contact* strg, str zip) {
	int size = getSize(*strg);
	int check = false;
	printf("\n all contacts with eMail %s : ", zip);
	for (int i = 0; i < size; i++) {
		if (getZip(strg[i]) == NULL) {
			continue;
		}
		else {
			if (_stricmp(strg[i].zipCode, zip) == 0) {
				if (getZip(strg[i]) != NULL) {
					printf("\n name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
				}
				check = true;
			}
		}
	}
	if (check == false) {
		printf("\nNot found!\n");
	}
}

/*Other*/

void sortShow(contact* strg) {
	int size = getSize(*strg);
	sortByName(strg, asc);
	printf("\n written from file...\n");
	for (size_t i = 0; i < size; i++)
	{
		if (strg[i].name != NULL) {
			printf("%d:   name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", i, strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}
}

void show(contact* strg) {
	int size = getSize(*strg);
	for (int i = 0; i < size; i++) {
		if (getName(strg[i]) != NULL) {
			printf("%d:   name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", i,strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}
}

int freePlace(contact* phoneBook)
{
	int size = getSize(*phoneBook);
	int i = 0;
	for (; i < size; i++)
	{
		if (getName(phoneBook[i]) == NULL)
		{
			return true;
		}
	}
	return false;
}


void wait() {
	printf("\nPress any key...\n");
	getch();
}



/*sorting*/
int namesrt_a(const void* a, const void* b) {
	const contact* ptr1 = a;
	const contact* ptr2 = b;
	return strcmp(ptr1->name, ptr2->name);
}

int namesrt_d(const void* a, const void* b) {
	const contact* ptr1 = a;
	const contact* ptr2 = b;
	return strcmp(ptr2->name, ptr1->name);
}

void sortByName(contact* strg, int in_order) {
	int size = getSize(*strg);
	if (in_order == asc) {
		qsort(strg, busy, sizeof(contact), namesrt_a);
	}
	else if (in_order == desc) {
		qsort(strg, busy, sizeof(contact), namesrt_d);
	}
}
#define _CRT_SECURE_NO_WARNINGS
#include "Func.h"

int busy;



/*Save*/


// Read
void readDAT(binContact* contacts) {
	char ch;
	
	FILE *stream = fopen("Report.dat", "rb");// ��������� ��� ������ ���������
	if (stream == NULL) {
		printf("ERROR");
		return -1;
	}

	for (int i = 0; i < busy; i++)
	{
		fread(&contacts[i], sizeof(binContact), 1, stream);
		contacts[i].name[30] = '\0';
		contacts[i].phone[30] = '\0';
		contacts[i].email[30] = '\0';
		contacts[i].zip[9] = '\0';
	}
	for (int i = 0; i < busy; i++)
	{
		printf("%s %s %s %s\n", contacts[i].name, contacts[i].phone, contacts[i].email, contacts[i].zip);
	}
	fclose(stream);
	stream = NULL;
	
}

int readTextFile( contact* strg) {
	char name[32], number[32], email[32], zip[20], tmp[5];// ������� ������ 
	int i = 0;
	int users = 0;
	char ch;
	FILE *stream = fopen("Report.txt", "r");// ��������� ��� ������
	if (stream == NULL) {
		printf("ERROR"); // ���������������� ������
		return -1;
	}
	while ((ch = fgetc(stream)) != EOF) { //��� ���� �����
		if (ch == '>') {
			users++;
		}
		else { continue; }
	}
	if (strg == NULL) {
		strg = initStorage(users); // � ��� ����
		setSize(strg, users);
	}

	while (fscanf(stream, "%s%s%s%s%s", tmp, name, number, email, zip) != EOF)//���� �� ����� �����, ������
	{
		strg = addNewContact(strg, name, number, email, zip); // ��������� ������� ������� �������, � ������ ������
		i++;
	}
	show(strg); // �������� �� �����
	for (int j = 0; j < sizeof(tmp); j++) {
		tmp[j] = NULL; // ��� ����� ������� ���������� TMP, � ��� ����� ����� ��� ��� ����� ���� , �� ��� ��... ������� � ����������, � ��� ������������ ���� ">"!
	}
	fclose(stream);// ���������
	stream = NULL;
	
}




//Write
void saveToBin(contact* strg) {
	int size = getSize(*strg); // ������ ������
	FILE* stream = fopen("Report.dat", "wb");


	for (int i = 0; i < busy; i++)
	{
		
		if (strg->name != NULL)
		{
			fprintf(stream, "%-30s %-30s %-30s %-10s", strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
			
		}
	}

	fclose(stream);
	stream = NULL;
}

void saveToText(contact* strg) {
	
	FILE *stream = fopen("Report.txt", "w"); // ���������
	if (stream == NULL) {
		printf("ERROR"); //������
		return -1;
	}
	for (int i = 0; i < busy; i++) {
		if (getName(strg[i]) != NULL && getZip(strg[i])!=NULL) { //��������
			fprintf(stream,"> %s  %s  %s  %s\n",  strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}
	fclose(stream);// ���������
}


//����� ������� �������(���� ����������)
void overwriteFromFile(FILE* st,contact* strg) {
	
	
}

void save(FILE* stream, contact* strg,int param) {
	switch (param)//������ ��������
	{
	case Text:saveToText(strg, stream);// ����� �����,�� �����
		break;
	case Binary:saveToBin(strg, stream);//����� ��������, �� ��������
		break;

	default:
		printf("Invalid param");// ����� ������ �����
		break;
	}
}



/*Set*/

void setSize(contact* storage,size_t size) {  //���������� ������ 
	storage->size = size;
}

void setName(contact* strg,  string name) {  //���������� ���
	strg->name = _strdup(name);
	
}

void setNumber(contact* strg, const string number){  //���������� �����
	strg->number = _strdup(number);
}

void setMail(contact* strg, const string email) {  //���������� �����
	strg->email = _strdup(email);
}

void setZip(contact* strg, const string zip) {  //���������� ������
	strg->zipCode = _strdup(zip);
}


//��������� ���������� ������ ������������ 
void setUser(contact* strg, const string name, const string number, const string email, const string zip) {
	setName(strg, name);
	setNumber(strg, number);
	setMail(strg, email);    
	setZip(strg, zip);
}


/*Get*/


int getSize(contact strg) { //����� ������
	return strg.size;
}

string getName(contact strg) {  //����� ���
	return strg.name;
}

string getNumber(contact strg) {  //����� �����
	return strg.number;
}

string getMail(contact strg) {  //����� �����
	return strg.email;
}

string getZip(contact strg) {  //����� ���
	return strg.zipCode;
}

contact* getAdress(contact* strg) {  //����� ����� ���������� �����
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

contact* initStorage(size_t size){  //������������� ������
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
contact* reallocStorage(contact* strg) {  //��������� ���-�� ������
	int size = getSize(*strg) * 2;
	setSize(strg, size);
	strg = realloc(strg, size * sizeof(contact));;
	for (int i = size / 2; i < size; i++) {
		setUser(&strg[i], NULL, NULL, NULL, NULL);
	}
	return strg;
}
contact* freeMemory(contact* strg) {  //���������� ������
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


//���������� ������ ��������
contact* addNewContact(contact *strg, const string name, const string number, const string email, const string zip) {
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
	busy++;
	return strg;
}

//�������� ������� ���������
contact* update(contact* strg, const string name, const string number, const string email, const string zip, int index) {
	setUser(&strg[index], name, number, email, zip);
}
//�������� ��� ��������
contact* updateName(contact* strg, const string name, int index) {
	setName(&strg[index], name);
}
//�������� ����� ��������
contact* updateNumber(contact* strg, const string number, int index) {
	setNumber(&strg[index], number);
}
//�������� ����� ��������
contact* updateMail(contact* strg, const string mail, int index) {
	setMail(&strg[index], mail);
}
//�������� ��� ��������
contact* updateZip(contact* strg, const string zip,int index) {
	setZip(&strg[index],zip);
}
//������� �����
contact* delete(contact* strg, int index){
	free(strg[index].name);
	free(strg[index].number);
	free(strg[index].zipCode);
	free(strg[index].email);
	setUser(&strg[index], NULL, NULL, NULL, NULL);
}


/*Searching*/

//����� �� �����
void srhName(contact* strg, string name) {
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
//����� �� ������
void srhNumber(contact* strg, string number) {
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
//����� �� �����
void srhMail(contact* strg, string mail) {
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
//����� �� ����
void srhZip(contact* strg, string zip) {
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
//����� ���������������� ������ ���������
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
//����� ������ ���������
void show(contact* strg) {
	int size = getSize(*strg);
	for (int i = 0; i < size; i++) {
		if (getName(strg[i]) != NULL) {
			printf("%d:   name: %-20s number: %15s  eMail: %15s zipCode: %8s    \n", i,strg[i].name, strg[i].number, strg[i].email, strg[i].zipCode);
		}
	}
}
//����� ���������� ����� � ������
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





//��������
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
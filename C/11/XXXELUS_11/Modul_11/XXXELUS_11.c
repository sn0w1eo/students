#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"



typedef struct {
	
	char name[32];
	char num[16];
	char email[32];
	int zip;
}contact;

#define ESC 0x1B

int main() 
{
	bool check = false;
	bool check_name = false;
	bool check_num = false;
	bool check_email = false;
	bool check_zip = false;
	int user=0,index_del = 0;

	int index[100] ;
	memset(index, -1, 100);
	char buf_name[31] = {NULL};
	char buf_nm[15] = { NULL };
	char buf_email[31] = { NULL };
	int zip=0;
	contact* data = (contact*)malloc(sizeof(contact)+1);
	
	if (data == NULL) {
		printf("Memory allocated went to pussy");
		return 1;
	}
	printf("Size:  %d", sizeof(contact));
	printf("====--------------------------------====");
	printf("Press 'a' - add contact");
	printf("Press 'd' - delete contact");
	printf("Press 's' - search contact");
	printf("Press '' - add contact");
	memset(data, NULL, sizeof(contact) * user);
	while(1){
		char ch = getch();
		switch (ch) {
		case'a':
			printf("\nname ");
			scanf_s("%s", &data[user].name,30);
			printf("\nnumber ");
			scanf_s("%s", &data[user].num, 14);
			printf("\nemail ");
			scanf_s("%s", &data[user].email, 30);
			for (int i = 0; i < sizeof(&data[user].email); i++) {
				if (data[user].email[i] == '@') {
					check = true;
					break;
				}	
			}
			if (check == false) {
				printf("\nInvalid email!\n");
				break;
			}
			printf("\nZip ");
			scanf_s("%d", &data[user].zip);
			user++;
			data = (contact*)realloc(data, (sizeof(contact)*(user+1)));	
			/*strcpy_s(data[user].name,sizeof(data->name),buf_name);
			strcpy_s(data[user].num, sizeof(data->num), buf_nm);
			strcpy_s(data[user].email, sizeof(data->email), buf_email);*/
			break;

		case 'p':
			system("Cls");
			for (int i = 0; i < user; i++) {
				if (data[i].name != '\0') {
					printf("name: %s number: %s  email: %s  zipCode: %d\n", data[i].name, data[i].num, data[i].email, data[i].zip);
					printf("====---------------------------====\n");
				}
			}
			break;
		case'd':
			printf("contact under which number to remove ? ");
			scanf_s("%d", &index_del);
			memset(data[index_del].name, NULL, sizeof(data[index_del].name));
			memset(data[index_del].num,NULL, sizeof(data[index_del].num));
			memset(data[index_del].email, NULL, sizeof(data[index_del].email));
			data[index_del].zip = NULL;
			break;

		case'u':
			printf("contact under which number to update? ");
			scanf_s("%d", &index_del);
			printf("\n New name ");
			scanf_s("%s", &data[index_del].name, 30);
			printf("\nNew number ");
			scanf_s("%s", &data[index_del].num, 14);
			printf("\nNew email ");
			scanf_s("%s", &data[index_del].email, 30);
			for (int i = 0; i < sizeof(&data[index_del].email); i++) {
				if (data[index_del].email[i] == '@') {
					check = true;
					break;
				}
			}
			if (check == false) {
				printf("\nInvalid email!\n");
				break;
			}
			printf("\nZip ");
			scanf_s("%d", &data[index_del].zip);
			break;

		case ESC: free(data);
			return 0;

		case's':
			printf("1- name 2-number 3-email 4- zip");
			char key = getch();
			switch (key)
			{
			case'1':
				printf("\nEnter name: ");
				scanf_s("%s", &buf_name, 31);
				printf("all contacts with a name %s :\n", buf_name);
				for (int i = 0; i < user; i++)
				{
					if (_stricmp(data[i].name, buf_name) == 0)
					{
						check_name = true;
						index[i] = i;
						if (index[i] != -1) {
							printf("name: %s number: %s  email: %s  zipCode: %d\n", data[index[i]].name, data[index[i]].num, data[index[i]].email, data[index[i]].zip);
						}
					}
				}
				if (check_name == false) {
					printf("\nNot found!\n");
				}
				break;
			case'2':
				printf("\nEnter number: ");
				scanf_s("%s", &buf_nm, 31);
				printf("all contacts with a number %s :\n", buf_nm);
				for (int i = 0; i < user; i++)
				{
					if (_stricmp(data[i].num, buf_nm) == 0)
					{
						check_num = true;
						index[i] = i;
						if (index[i] != -1) {
							printf("name: %s number: %s  email: %s  zipCode: %d\n", data[index[i]].name, data[index[i]].num, data[index[i]].email, data[index[i]].zip);
						}
					}
				}
				if (check_num == false) {
					printf("\nNot found!\n");
				}
				break;
			case'3':
				printf("\nEnter email: ");
				scanf_s("%s", &buf_nm, 31);
				printf("all contacts with a email %s :\n", buf_email);
				for (int i = 0; i < user; i++)
				{
					if (_stricmp(data[i].email, buf_email) == 0)
					{
						check_email = true;
						index[i] = i;
						if (index[i] != -1) {
							printf("name: %s number: %s  email: %s  zipCode: %d\n", data[index[i]].name, data[index[i]].num, data[index[i]].email, data[index[i]].zip);
						}
					}
				}
				if (check_email == false) {
					printf("\nNot found!\n");
				}
			case'4':
				printf("\nEnter zipCode: ");
				scanf_s("%d", &zip, 15);
				printf("all contacts with a zipCode %d :\n", zip);
				for (int i = 0; i < user; i++)
				{
					if (data[i].zip == zip)
					{
						check_zip = true;
						index[i] = i;
						if (index[i] != -1) {
							printf("name: %s number: %s  email: %s  zipCode: %d\n", data[index[i]].name, data[index[i]].num, data[index[i]].email, data[index[i]].zip);
						}
					}
				}
				if (check_email == false) {
					printf("\nNot found!\n");
					break;
			default:
				printf("There is no such button");
				break;
				}
			}

		}
	}
}
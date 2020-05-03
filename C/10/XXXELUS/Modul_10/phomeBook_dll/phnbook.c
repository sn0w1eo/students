#include "phnbook.h"

void setPosition(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void wait() {
	setPosition(112, 28);
	color(LIGHT_GREEN);
	printf("Press any key to continue...");
	color(DEFAULT);
	getch();
}

void copy(char* dest, const char* source)
{
	
	while (*dest++ = *source++);
}

char* setTime()
{
	const time_t timer = time(NULL);
	
	return ctime(&timer);
}

void addContactStatic(char** contact, const char* name, const char* number, const char* age)
{
	
	char* buf = setTime();
	static int freeIn;
	for (freeIn; freeIn < 10; freeIn++)
	{
		if (contact[freeIn] == NULL) break;
	}
	if (freeIn == 10)
	{
		printf("no free places");

	}

	if (contact[freeIn] == NULL) {
		contact[freeIn] = (char*)malloc(TOTAL_SIZE+strlen(buf));
		copy(&contact[freeIn][0], name);
		copy(&contact[freeIn][NAME_SIZE], age);
		copy(&contact[freeIn][NAME_SIZE + AGE_SIZE], number);
		strcpy(&contact[freeIn][NAME_SIZE + AGE_SIZE + NUMBER_SIZE], buf);
	}
}

int addContactByKeyboard(char** contact)
{
	char* buf = setTime();
	static int freeIn;
	char name[100] = { NULL },
		 age[10] = {NULL},
		 number[20] = {NULL};
	setPosition(72, 13);
	printf("Enter contact name:");
	setPosition(72, 14);
	scanf_s("%s", name, 20);
	if (strlen(name) > NAME_SIZE)
	{
		setPosition(72, 15);
		printf("name too long");
		wait();
		return 1;
	}
	setPosition(72, 15);
	printf("Enter contact age: ");
	setPosition(72, 16);
	scanf_s("%s", age, 3);
	if (strlen(age) >= AGE_SIZE)
	{
		setPosition(72, 17);
		printf("don't live with that age");
		wait();
		return 1;
	}
	setPosition(72, 17);
	printf("Enter contact number: ");
	setPosition(72, 18);
	scanf_s("%s", number, 13);
	if (strlen(number) > NUMBER_SIZE)
	{
		setPosition(72, 19);
		printf("number too long");
		
		wait();
		return 1;
	}

	for (freeIn; freeIn < 10; freeIn++)
	{
		if (contact[freeIn] == NULL) break;
	}
	if (freeIn == 10)
	{
		freeIn = 0;
		setPosition(72, 19);
		color(LIGHT_RED);
		printf("no free places");
		wait();
		return -1;
	}

	if (contact[freeIn] == NULL) {
		contact[freeIn] = (char*)malloc(sizeof(buf) + TOTAL_SIZE);
		copy(&contact[freeIn][0], name);
		copy(&contact[freeIn][NAME_SIZE], age);
		copy(&contact[freeIn][NAME_SIZE + AGE_SIZE], number);
		copy(&contact[freeIn][NAME_SIZE + AGE_SIZE + NUMBER_SIZE], buf);
		return 0;
	}
	return 0;
}

void showContacts(char** list)
{
	color(CYAN);
	printf("%-2s %-20s%-5s %14s %20s\n", "#", "name:", "age:", "number:","Date added:");
	for (int i = 0; i < 70; i++)
	{
		if (i % 2 == 0) 
		{ 
			color(CYAN);
		}
		else 
		{ 
			color(LIGHT_YELLOW); 
		}

		if (i < 5 || i>65) 
		{
			printf("=");
		}
		else
		printf("-");
	}

	for (int i = 0; i < CONTACTS; i++)
	{
	
		if (list[i] != NULL)
		{
			color(LIGHT_RED);
			printf("\n%d: ",i );
			color(LIGHT_YELLOW);
			printf("%-20s", (char*)&list[i][0]);
			color(CYAN);
			printf("%-5s", &list[i][NAME_SIZE]);
			color(BLUE);
			printf("%17s ", &list[i][NAME_SIZE + AGE_SIZE]);
			color(GREEN);
			printf("%20s", &list[i][NAME_SIZE + AGE_SIZE + NUMBER_SIZE]);
			color(DEFAULT);
			for (int i = 0; i < 70; i++) 
			{
				if (i % 2 == 0) { color(CYAN); }
				else { color(LIGHT_YELLOW); }
				if (i < 5 || i > 65)
				{
					printf("=");
				}
				else
					printf("-");
			}
			
		}
		else
		{
			color(LIGHT_RED);
			printf("\n%d: ", i);
			printf("%-20s", "EMPTY");
			printf("%-5s", "0");
			printf("%17s\n","+996550000000");
			color(CYAN);
			for (int i = 0; i < 70; i++)
			{
				if (i % 2 == 0) { color(CYAN); }
				else { color(LIGHT_YELLOW); }
				if (i < 5 || i > 65)
				{
					printf("=");
				}
				else
					printf("-");
			}
		}
	}
}

void deleteContact(char** contact)
{
	char deleteIndex = 0;
	setPosition(72, 13);
	printf("What contact number do you want to delete?\n");
	setPosition(72, 14);
	deleteIndex = getch() - 48;
	if (deleteIndex > 9 ) 
	{
		setPosition(72, 15);
		printf("No such contact\n");
		wait();
	}

	else
	{
		if (contact[deleteIndex] != NULL) {
			contact[deleteIndex] = NULL;
			free(contact[deleteIndex]);
			
			setPosition(72, 15);
			printf("Contact deleted!\n");
			wait();
		}
		else
		{
			setPosition(72, 15);
			printf("Contact is clean\n");
			wait();
		}
	}
}

int searchContact(char** contact) 
{
	unsigned int index = 0;
	
	char searchingName[100] = {NULL};
	color(CYAN);
	setPosition(72, 13);
	printf("who do you want to find? (Enter name)");
	setPosition(72, 14);
	color(DEFAULT);
	scanf_s("%s",searchingName,100);
	for (index; index < 10; index++) {
		if(contact[index]!=NULL)
		if (_stricmp(&contact[index][0], searchingName)==0)
		{
			return index;
			break;
		}
		
	}
	return -1;
}

int updateContact(char** contact)
{
	char* buf = setTime();
	static char newName[100] = {NULL},
			newAge[10] = { NULL },
			newNumber[20] = { NULL };
	static char key = '0';
	color(CYAN);
	char buff = ' ';
	setPosition(72, 13);
	printf("What contact number do you want to change ?");
	setPosition(72, 14);
	buff = getch() - 48;
	if (buff < 0 || buff > 9) 
	{ 
		setPosition(72, 15);
		color(LIGHT_RED);
		printf("It's not a number!");
		color(DEFAULT);
		wait();
		return -1; 
	}
	else
		if (contact[buff] != NULL)
		{
			setPosition(72, 15);
			color(LIGHT_GREEN);
			printf("%d: ", buff);
			color(LIGHT_YELLOW);
			printf("%-15s", (char*)&contact[buff][0]);
			color(CYAN);
			printf("%5s", &contact[buff][NAME_SIZE]);
			color(LIGHT_BLUE);
			printf("%14s", &contact[buff][NAME_SIZE + AGE_SIZE]);
			color(CYAN);
			setPosition(72, 16);
			printf("do you want to change this contact?(Y/N)");
			key = getch();
			switch (key)
			{
			case 'Y':
			case'y':

				setPosition(72, 17);
				printf("Enter new name: ");
				scanf_s("%s", newName,20);
				if (strlen(newName) >= NAME_SIZE)
				{
					setPosition(72, 18);
					color(LIGHT_RED);
					printf("name too long");
					
					wait();
					return 1;
				}
				setPosition(72, 18);
				printf("Enter new age: ");
				scanf_s("%s", newAge,4);
				if (strlen(newAge) >= AGE_SIZE)
				{
					setPosition(72, 19);
					color(LIGHT_RED);
					printf("don't live with that age");					
					wait();
					return 1;
				}
				setPosition(72, 19);
				printf("Enter new number: ");
				scanf_s("%s", newNumber,14);
				if (strlen(newNumber) >= NUMBER_SIZE)
				{
					setPosition(72, 21);
					color(LIGHT_RED);
					printf("number too long");
					wait();
					return 1;
				}

				copy(&contact[buff][0], newName);
				copy(&contact[buff][NAME_SIZE], newAge);
				copy(&contact[buff][NAME_SIZE + AGE_SIZE], newNumber);
				copy(&contact[buff][NAME_SIZE + AGE_SIZE + NUMBER_SIZE], buf);
				color(LIGHT_GREEN);
				setPosition(72, 20);
				printf("Comleted!");
				color(DEFAULT);
				wait();
				break;
				return 0;


			case 'N':
			case'n':
				
				color(LIGHT_GREEN);
				setPosition(72, 17);
				printf("OK, if you change your mind press 'U'");
				color(DEFAULT);
				wait();
				break;
				return 0;

			default:
				color(LIGHT_RED);
				setPosition(72, 17);
				printf("You were told in English that the choice is between Y and N!");
				color(DEFAULT);
				wait();		
				break;
				return 0;
			}

		}
		else
		{
			color(LIGHT_RED);
			setPosition(72, 16);
			printf("PIZDA,there is no contact");
			color(DEFAULT);
			wait();		
			return -1;
		}
		return 0;
}

void showLegend() 
{
	for (int i = 0; i < 30; i++) 
	{
		setPosition(70, i);
		
		if (i % 2 == 0) { color(CYAN); }
		else { color(LIGHT_YELLOW); }
		printf("||");
	}
	for (int j = 0; j < 70; j++)
	{
		setPosition(72+j, 12);
		if (j % 2 == 0) { color(CYAN); }
		else { color(LIGHT_YELLOW); }
		printf("=");
	}
	color(LIGHT_YELLOW);
	setPosition(92, 1);
	printf("%20s","Legend:");
	setPosition(92, 2);
	for (int i = 0; i <= 30; i++) 
	{
		if (i % 2 == 0) { color(CYAN); }
		else { color(LIGHT_YELLOW); }
		if (i <= 3 || i >= 25) 
		{
			printf("=");
		}
		else
		{
			printf("-");
		}
	}
	color(LIGHT_YELLOW);
	setPosition(92, 3);
	printf("   key 'A' - Add new contact");
	setPosition(92, 4);
	printf("   key 'D' - Delete  contact");
	setPosition(92, 5);
	printf("   key 'U' - Update  contact");
	setPosition(92, 6);
	printf("   key 'S' - Search  contact");
	setPosition(92, 7);
	printf("   key 'ESC' - exit");
	setPosition(92, 8);
	for (int i = 0; i <= 30; i++)
	{
		if (i % 2 == 0) { color(CYAN); }
		else { color(LIGHT_YELLOW); }
		if (i <= 3 || i >= 25)
		{
			printf("=");
		}
		else
		{
			printf("-");
		}
	}
	setPosition(0, 1);
}

void printContact(char** contact, char number) 
{
	setPosition(72, 17);
	color(BLUE);
	printf("%-20s", &contact[number][0]);
	color(CYAN);
	printf("%-5s", &contact[number][NAME_SIZE]);
	color(GREY);
	printf("%17s ", &contact[number][NAME_SIZE + AGE_SIZE]);
	color(DEFAULT);
	
}


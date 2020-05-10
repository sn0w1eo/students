#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

typedef struct
{
	char* name;
	char* phone;
	char* email;
	char* zipCode;
}myStruct;

enum myEnum
{
	Name = 1, phone, email, zipCode, ESC = 0x1b
};

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}

int main()
{
	int ch;
	myStruct storage[20] = { 0x00 };
	while (1)
	{
		system("cls");
		setColor(14);
		printf("ADD[a]       ");
		setColor(13);
		printf("READ[r]       ");
		setColor(12);
		printf("delete[d]      ");
		setColor(11);
		printf("UPDATE[u]      ");
		setColor(10);
		printf("SEARCH[s]      ");
		setColor(4);
		printf("EXIT[e]");
		ch = getch();
		system("cls");
		switch (ch)
		{
		case 'A':
		case 'a':
			for (int i = 0; i < 20; i++)
			{
				if (storage[i].name == NULL)
				{
					setColor(14);
					char buff[100];
					printf("Name: ");
					setColor(10);
					scanf_s("%s", buff, 100);
					int buffLen = strlen(buff);
					storage[i].name = (char*)malloc(buffLen + 1);
					strcopy(storage[i].name, buff);

					setColor(14);
					char buff1[100];
					printf("Phone: ");
					setColor(10);
					scanf_s("%s", buff1, 100);
					int buffLen1 = strlen(buff1);
					storage[i].phone = (char*)malloc(buffLen1 + 1);
					strcopy(storage[i].phone, buff1);

					setColor(14);
					char buff2[100];
					printf("Email: ");
					setColor(10);
					scanf_s("%s", buff2, 100);
					int buffLen2 = strlen(buff1);
					storage[i].email = (char*)malloc(buffLen2 + 1);
					strcopy(storage[i].email, buff2);

					setColor(14);
					char buff3[100];
					printf("ZipCode: ");
					setColor(10);
					scanf_s("%s", buff3, 100);
					int buffLen3 = strlen(buff3);
					storage[i].zipCode = (char*)malloc(buffLen3 + 1);
					strcopy(storage[i].zipCode, buff3);
					break;
				}
				else
				{
					continue;
				}
			}
			break;
		case 'R':
		case 'r':
			setColor(14);
			for (int i = 0; i < 20; i++)
			{
				if (storage[i].name == NULL)
				{
					continue;
				}
				printf("%d)Name: %s\n", i, storage[i].name);
				printf("  Phone: %s\n", storage[i].phone);
				printf("  Email: %s\n", storage[i].email);
				printf("  zipCode: %s\n\n", storage[i].zipCode);

			}
			getch();
			break;
		case 'd':
		case 'D':
			printf("Which line do you want to delete?\n");
			int value;
			setColor(4);
			scanf_s("%d", &value);
			free(storage[value].name);
			storage[value].name = NULL;
			free(storage[value].phone);
			storage[value].phone = NULL;
			free(storage[value].email);
			storage[value].email = NULL;
			free(storage[value].zipCode);
			storage[value].zipCode = NULL;
			break;
		case 'U':
		case 'u':
			setColor(14);
			printf("Which line do you want to update?\n");
			int i;
			scanf_s("%d", &i);
			if (storage[i].name == NULL)
			{
				setColor(14);
				char buff[100];
				printf("Name: ");
				setColor(10);
				scanf_s("%s", buff, 100);
				int buffLen = strlen(buff);
				storage[i].name = (char*)malloc(buffLen + 1);
				strcopy(storage[i].name, buff);

				setColor(14);
				char buff1[100];
				printf("Phone: ");
				setColor(10);
				scanf_s("%s", buff1, 100);
				int buffLen1 = strlen(buff1);
				storage[i].phone = (char*)malloc(buffLen1 + 1);
				strcopy(storage[i].phone, buff1);

				setColor(14);
				char buff2[100];
				printf("Email: ");
				setColor(10);
				scanf_s("%s", buff2, 100);
				int buffLen2 = strlen(buff1);
				storage[i].email = (char*)malloc(buffLen2 + 1);
				strcopy(storage[i].email, buff2);

				setColor(14);
				char buff3[100];
				printf("ZipCode: ");
				setColor(10);
				scanf_s("%s", buff3, 100);
				int buffLen3 = strlen(buff3);
				storage[i].zipCode = (char*)malloc(buffLen3 + 1);
				strcopy(storage[i].zipCode, buff3);
				break;
			}
			else
			{
				setColor(14);
				char buff[100];
				printf("Name: ");
				setColor(10);
				scanf_s("%s", buff, 100);
				int buffLen = strlen(buff);
				storage[i].name = (char*)realloc(storage[i].name, buffLen + 1);
				strcopy(storage[i].name, buff);

				setColor(14);
				char buff1[100];
				printf("Phone: ");
				setColor(10);
				scanf_s("%s", buff1, 100);
				int buffLen1 = strlen(buff1);
				storage[i].phone = (char*)realloc(storage[i].phone, buffLen1 + 1);
				strcopy(storage[i].phone, buff1);

				setColor(14);
				char buff2[100];
				printf("Email: ");
				setColor(10);
				scanf_s("%s", buff2, 100);
				int buffLen2 = strlen(buff1);
				storage[i].email = (char*)realloc(storage[i].email, buffLen2 + 1);
				strcopy(storage[i].email, buff2);


				setColor(14);
				char buff3[100];
				printf("ZipCode: ");
				setColor(10);
				scanf_s("%s", buff3, 100);
				int buffLen3 = strlen(buff3);
				storage[i].zipCode = (char*)realloc(storage[i].zipCode, buffLen3 + 1);
				strcopy(storage[i].zipCode, buff3);
				break;
			}
			break;
		case 'S':
		case 's':
			setColor(10);
			printf("What do you want to search? ");
			setColor(14);
			printf("Name[1]  ");
			setColor(12);
			printf("Phone[2]  ");
			setColor(13);
			printf("Email[3]  ");
			setColor(15);
			printf("ZipCode[4]  \n");

			ch = getch() - 48;
			switch (ch)
			{
			case Name:
				setColor(14);
				printf("Write name: ");
				char buff5[100];
				setColor(10);
				scanf_s("%s", buff5, 100);
				for (int i = 0; i < 20; i++)
				{
					if (storage[i].name != NULL)
					{
						if (strlen(storage[i].name) == strlen(buff5))
						{
							if (storage[i].name[0] == buff5[0] && storage[i].name[1] == buff5[1] && storage[i].name[2] == buff5[2])
							{
								printf("%d)Name: %s\n", i, storage[i].name);
								printf("  Phone: %s\n", storage[i].phone);
								printf("  Email: %s\n", storage[i].email);
								printf("  zipCode: %s\n\n", storage[i].zipCode);
							}
						}
					}
					else
					{
						continue;
					}
				}
				getch();
				break;

			case phone:
				setColor(14);
				printf("Write phone: ");
				setColor(10);
				scanf_s("%s", buff5, 100);
				for (int i = 0; i < 20; i++)
				{
					if (storage[i].phone != NULL)
					{
						if (strlen(storage[i].phone) == strlen(buff5))
						{
							if (storage[i].phone[0] == buff5[0] && storage[i].phone[1] == buff5[1] && storage[i].phone[2] == buff5[2])
							{
								printf("%d)Name: %s\n", i, storage[i].name);
								printf("  Phone: %s\n", storage[i].phone);
								printf("  Email: %s\n", storage[i].email);
								printf("  zipCode: %s\n\n", storage[i].zipCode);
							}
						}
					}
					else
					{
						continue;
					}
				}
				getch();
				break;

			case email:
				setColor(14);
				printf("Write email: ");
				setColor(10);
				scanf_s("%s", buff5, 100);
				for (int i = 0; i < 20; i++)
				{
					if (storage[i].email != NULL)
					{
						if (strlen(storage[i].email) == strlen(buff5))
						{
							if (storage[i].email[0] == buff5[0] && storage[i].email[1] == buff5[1] && storage[i].email[2] == buff5[2])
							{
								printf("%d)Name: %s\n", i, storage[i].name);
								printf("  Phone: %s\n", storage[i].phone);
								printf("  Email: %s\n", storage[i].email);
								printf("  zipCode: %s\n\n", storage[i].zipCode);
							}
						}
					}
					else
					{
						continue;
					}
				}
				getch();
				break;

			case zipCode:
				setColor(14);
				printf("Write zipCode: ");
				setColor(10);
				scanf_s("%s", buff5, 100);
				for (int i = 0; i < 20; i++)
				{
					if (storage[i].zipCode != NULL)
					{
						if (strlen(storage[i].zipCode) == strlen(buff5))
						{
							if (storage[i].zipCode[0] == buff5[0] && storage[i].zipCode[1] == buff5[1] && storage[i].zipCode[2] == buff5[2])
							{
								printf("%d)Name: %s\n", i, storage[i].name);
								printf("  Phone: %s\n", storage[i].phone);
								printf("  Email: %s\n", storage[i].email);
								printf("  zipCode: %s\n\n", storage[i].zipCode);
							}
						}
					}
					else
					{
						continue;
					}
				}
				getch();
				break;
			}
			break;
		case ESC:
			for (int i = 0; i < 20; i++)
			{
				free(storage[i].name);
				storage[i].name = NULL;
				free(storage[i].phone);
				storage[i].phone = NULL;
				free(storage[i].email);
				storage[i].email = NULL;
				free(storage[i].zipCode);
				storage[i].zipCode = NULL;
			}
			return;
		}
	}
}

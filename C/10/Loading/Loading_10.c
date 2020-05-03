#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "windows.h"

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void strcopy(char* dest, const char* source)
{
	while (*dest++ = *source++);
}

char* creatContact(char* storage)
{
	setColor(14);
	char buffNum[10];
	char buff[100];
	printf("Name: ");
	setColor(10);
	scanf_s("%s", buff, 100);
	unsigned int d,m,y,y1,y2;
	setColor(14);
	printf("Date of birrh(15.15.1999): ");
	setColor(10);
	scanf_s("%2d.%2d.%2d%1d%1d", &d,&m,&y,&y1,&y2);
	int number;
	setColor(14);
	printf("Number: +996 ");
	setColor(10);
    scanf("%d", &number);
	_itoa(number, buffNum, 10);

	int buffLen = strlen(buff)+strlen(buffNum);
	if (storage != NULL)
	{
		storage = (char*)realloc(storage,buffLen + 6);
	}

	else
	{
		storage = (char*)malloc(buffLen + 6);
	}
	
	if (storage == NULL)
	{
		printf("Memory allocation failed");
	}

	else
	{
		storage[0] = d;
		storage[1] = m;
		storage[2] = y;
		storage[3] = y1;
		storage[4] = y1;
		strcopy(storage + 5, buffNum);
		strcopy(storage + 14, buff);
	}
	return storage;
}

char* delete(char** storage)
{
	setColor(0xC);
	printf("Which line do you want to delete?   ");
	int i;
	setColor(12);
	scanf_s("%d", &i);
	free(storage[i]);
	storage[i] = NULL;
	return 0;
}

void read(char** storage)
{
	setColor(13);
	printf("     DATE OF BIRTH:            NUMBER:                NAME:  \n");
	setColor(10);
	for (int i=1;i<21;i++)
	{
		if (storage[i] == NULL)
		{
			continue;
		}
		else
		{
			printf("#%d", i);
			printf("   %2d.%2d.%2d%1d%1d                +996 ", storage[i][0], storage[i][1], storage[i][2], storage[i][3], storage[i][4]);
				

			for (int j = 5; storage[i][j] != (int) NULL; j++)
			{
			    if (j == 14)
				{
					printf("         %c", storage[i][j]);
				}

				else
				{
					printf("%c", storage[i][j]);
				}
			}
			printf("\n");
		}
	}
	getch();
}

void update(char** storage)
{
	setColor(10);
	int i;
	printf("Which line do you want to update? ");
	scanf("%d", &i);
	creatContact(storage[i]);
}

int main()
{
	char* storage[21] = {NULL};
	char ch;  // ввод с клавиатуры

	while (1)
	{
		system("cls");
		setColor(14);
		printf("CREATE[c]");
		setColor(13);
		printf("          READ[r]");
		setColor(11);
		printf("          UPDATE[u]");
		setColor(12);
		printf("          DELETE[d]");
		setColor(4);
		printf("         EXIT[e]");
		ch = getch();
		system("cls");
		switch (ch)
		{
		case 'c':
			for (int i = 1; i <= 20; i++)
			{
				if (storage[i] == NULL)
				{
					storage[i] = creatContact(storage[i]);
					break;
				}
			}
			break;

		case 'r':
			read(storage);
			break;

		case 'd':
			delete(storage);
			break;

		case 'u':
			update(storage);
			break;
		}

		if (ch == 'e')
		{
			break;
		}

	}
	for (int i = 0; i < 21; i++)
	{
		free(storage[i]);
		storage[i] = NULL;
	}
}
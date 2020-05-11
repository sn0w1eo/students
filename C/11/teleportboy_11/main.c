#include "stdio.h"
#include "stdlib.h"

//Объявление структуры, enum и синонимов к unsigned char и  unsigned long long int
#include "phonebook.h"

#include "create.h" //Создание контакта.
#include "read.h"   //Чтение контакта.
#include "update.h" //Изменение контакта.
#include "delete.h" //Удаление контакта.

#include "search.h" //Поиск контакта.

#include "memory.h" //Работа динамической памяти.

#include "visual.h" //Интерфейс

int main()
{

	phonebook* phoneBook = NULL;
	int size = 0, ch;
	DisplayHotKeys();
	
	while (ch = getch())
	{
		DisplayHotKeys();
		switch (ch)
		{
		//Добавить контакт.
		case 'a':
		case 'A':
			printf("Enter contact details.\n");
			
			phoneBook = AddContact(phoneBook, &size);
			break;

		//Изменить контакт.
		case 'u':
		case 'U':
			printf("Update contact.\n");
			printf("Enter contact number: ");
			
			ch = getch() - 48;
			putchar(ch + 48);
			
			UpdateContact(phoneBook, ch - 1);
			break;

		//Удалить контакт.
		case 'd':
		case 'D':
			printf("Enter contact number: ");
			
			ch = getch() - 48;
			putchar(ch + 48);
			
			DeleteContact(phoneBook, ch - 1);
			break;

		//Отобразить все контакты.
		case 'r':
		case 'R':
			DisplayAllContacts(phoneBook);
			break;

		//Поиск
		case 's':
		case 'S':
			printf("By what parameter do you want to search for a contact?\n");
			printf("1 - name; 2 - phone; 3 - email; 4 - zipcode\n");
			printf("Enter selection number: ");
			
			ch = getch() - 48;
			putchar(ch + 48);
			//Взависимости от введёных пользователем данных
			//передавать определённую функцию как аргумент в функцию DoSearch.
			switch (ch)
			{
			case BY_NAME:
				printf("Found %d contacts by name", DoSearch(phoneBook, FindByName));
				break;

			case BY_NUMBER:
				printf("Found %d contacts by number", DoSearch(phoneBook, FindByPhoneNumber));
				break;

			case BY_EMAIL:
				printf("Found %d contacts by email", DoSearch(phoneBook, FindByEmail));
				break;

			case BY_ZIPCODE:
				printf("Found %d contacts by zipcode", DoSearch(phoneBook, FindByZipCode));
				break;
			}
			
			break;
			//Очистить вывод на консоли.
		case 'c':
		case 'C':
			system("cls");
			DisplayHotKeys();
			break;

		//Выход из программы.
		case 27:
			printf("Exit.");
			FreeMemory(phoneBook);   //Очистить память.
			exit(0);                 //Звершить работу программы.
		}
	}
}
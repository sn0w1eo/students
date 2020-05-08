/*/——————————————————————————————————————————————\
 |                                                |
 | Функции FindByXXXX выполняют поиск по массиву  |
 | содержащий контакты. Критерии поиска: имя,     |
 | номер телефона, email и zipсode. Функции       |
 | возращают количество найденных совпадений      |
 |                                                |
 | В качестве единственного аргумента принимают   |
 | указатель на массив типа phonebook             |
 |                                                |
 | Функция DoSearch выполняет по указанному       |
 | критерию заданному ей как аргумент. В качестве |
 | этого аргумента выступает другая фу-ия поиска. |
 | Так же в качестве второго аргумента принимает  |
 | указатель на массив. Возвращает количество     |
 | найденных совпадений.                          |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "string.h"

#include "phonebook.h"

//Поиск по имени.
int FindByName(phonebook* phoneBook)
{
	int counter = 0;             //Счётчик для количества контактов.
	uchar buffer[50];

	printf("\nenter name: ");
	scanf_s("%s", buffer, 50);   //Ввод имени.

	for (int i = 0; i < phoneBook->size; i++)
	{
		//Если NULL то контакт удалён.
		if (phoneBook[i].name == NULL) 
		{
			continue;
		}
		//Сранить ввод и содержимое.
		if (strcmp(buffer, phoneBook[i].name) == 0)
		{
			counter++;
		}
	}

	return counter;
}

//Поиск по номеру телефона.
int FindByPhoneNumber(phonebook* phoneBook)
{
	int counter = 0;             //Счётчик для количества контактов.
	uchar buffer[50];

	printf("\nenter phone: ");
	scanf_s("%s", buffer, 50);   //Ввод номера.

	for (int i = 0; i < phoneBook->size; i++)
	{
		//Если NULL то контакт удалён.
		if (phoneBook[i].phoneNumber == NULL)
		{
			continue;
		}
		//Сранить ввод и содержимое.
		if (strcmp(buffer, phoneBook[i].phoneNumber) == 0)
		{
			counter++;
		}
	}

	return counter;
}

//Поиск по  email.
int FindByEmail(phonebook* phoneBook)
{
	int counter = 0;             //Счётчик для количества контактов.
	uchar buffer[50];

	printf("\nenter email: "); 
	scanf_s("%s", buffer, 50);   //Ввод email'a.

	for (int i = 0; i < phoneBook->size; i++)
	{
		//Если NULL то контакт удалён.
		if (phoneBook[i].email == NULL)
		{
			continue;
		}
		//Сранить ввод и содержимое.
		if (strcmp(buffer, phoneBook[i].email) == 0)
		{
			counter++;
		}
	}

	return counter;
}

//Поиск по ZipCode.
int FindByZipCode(phonebook* phoneBook)
{
	int counter = 0;             //Счётчик для количества контактов.
	ulong zipCode;

	printf("\nenter zipcode: ");
	scanf_s("%lld", &zipCode);   //Ввод ZipCode'a.

	for (int i = 0; i < phoneBook->size; i++)
	{
		//Если 0 то контакт удалён.
		if (phoneBook[i].zipCode == 0)
		{
			continue;
		}
		//Сранить ввод и содержимое.
		if (zipCode == phoneBook[i].zipCode)
		{
			counter++;
		}
	}

	return counter;
}

//С такими колбэками место в Apple мне обеспечено.
int DoSearch(phonebook* phoneBook, int(*criterion)(phonebook*))
{
	return criterion(phoneBook);
}
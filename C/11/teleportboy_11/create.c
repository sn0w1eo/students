/*/——————————————————————————————————————————————\
 |                                                |
 | Все 4 функции принимают в качестве аргумента   |
 | указатель на блок памяти и общий размер блока. |
 | Иными словами, это индекс на который надо      |
 | сдвинуться в массиве данных типа phonebook,    |
 | что бы корректно записать новые данные.        |
 |                                                |
 | Каждая функция запрашивает ввод данных у       |
 | пользователя с клавиатуры и выделяет память    |
 | в куче под эти данные.                         |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"
#include "memory.h"

void AddName(phonebook* phoneBook, int* contactIndex)
{
	uchar buffer[50];
	int nameLength;                    //Длина имени.

	printf("enter name: ");
	scanf_s("%s", buffer, 50);         //Ввод имени.

	nameLength = strlen(buffer) + 1;   //Сохранить длину имени.

	//Выделить память под имя и сохранить в ней.
	phoneBook[*contactIndex].name = (uchar*)calloc(nameLength, sizeof(uchar));
	if (!phoneBook[*contactIndex].name)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	strcpy_s(phoneBook[*contactIndex].name, nameLength * sizeof(uchar), buffer);
}

void AddPhoneNumber(phonebook* phoneBook, int* contactIndex)
{
	uchar buffer[50];
	int numberLength;                    //Длина номера телефона.
	 
	printf("enter phone: ");
	scanf_s("%s", buffer, 50);           //Ввод номера телефона.

	numberLength = strlen(buffer) + 1;   //Сохранить длину номера телефона.

	//Выделить память под номер телефона и сохранить в ней.
	phoneBook[*contactIndex].phoneNumber = (uchar*)calloc(numberLength, sizeof(uchar));
	if (!phoneBook[*contactIndex].phoneNumber)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	strcpy_s(phoneBook[*contactIndex].phoneNumber, numberLength * sizeof(uchar), buffer);
}

void AddEmail(phonebook* phoneBook, int* contactIndex)
{
	uchar buffer[50];
	int emailLength;                    //Длина email.
	
	printf("enter email: ");
	scanf_s("%s", buffer, 50);          //Ввод email.

	emailLength = strlen(buffer) + 1;   //Сохранить длину email.

	//Выделить память под email и сохранить в ней.
	phoneBook[*contactIndex].email = (uchar*)calloc(emailLength, sizeof(uchar));
	if (!phoneBook[*contactIndex].email)
	{
		printf("Memory allocation failed!\n");
		return;
	}

	strcpy_s(phoneBook[*contactIndex].email, emailLength * sizeof(uchar), buffer);
}

void AddZipCode(phonebook* phoneBook, int* contactIndex)
{
	ulong zipCode;
	
	printf("enter zipcode: ");
	scanf_s("%lld", &zipCode);                      //Ввод зипкода.

	phoneBook[*contactIndex].zipCode = zipCode;   //Сохранить зипкод.
}

phonebook* AddContact(phonebook* phoneBook, int* contactIndex)
{
	phoneBook = GetMemory(phoneBook);          //Выделить/перераспределить память.
	AddName(phoneBook, contactIndex);          //Добавить имя.
	AddPhoneNumber(phoneBook, contactIndex);   //Добавить телефон.
	AddEmail(phoneBook, contactIndex);         //Добавить email.
	AddZipCode(phoneBook, contactIndex);       //Добавить ZipCode.
	
	*contactIndex = phoneBook->size;           //Записать размер блока памяти в переменную на стеке.
	
	return phoneBook;
}
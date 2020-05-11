/*/——————————————————————————————————————————————\
 |                                                |
 | Первые 4 функции принимают в качестве аргумента|
 | указатель на блок памяти и общий размер блока. |
 | Иными словами, это индекс на который надо      |
 | сдвинуться в массиве данных типа phonebook,    |
 | что бы корректно записать новые данные.        |
 |                                                |
 | Каждая функция запрашивает ввод данных у       |
 | пользователя с клавиатуры и выделяет или       |
 | перераспределяет память в куче под эти данные. |
 |                                                |
 | Функция - UpdateContact совокупность первых 4. |
 |                                                |
 \————————————————————————————————————————————————/*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "phonebook.h"

//Изменить имя.
void UpdateName(phonebook* phoneBook, int contactIndex)
{
	uchar buffer[50];
	int nameLength;                    //Длина имени.

	printf("\nenter name: ");
	scanf_s("%s", buffer, 50);         //Ввод имени.

	nameLength = strlen(buffer) + 1;   //Записать длину имени.

	//Перераспределить память под новое имя и сохранить его в ней.
	phoneBook[contactIndex].name = (uchar*)realloc(phoneBook[contactIndex].name, nameLength * sizeof(uchar));
	if (!phoneBook[contactIndex].name)
	{
		printf("Memory realloc failed!");
		return;
	}

	strcpy_s(phoneBook[contactIndex].name, nameLength, buffer);
}

//Изменить номер телефона.
void* UpdatePhoneNumber(phonebook* phoneBook, int contactIndex)
{
	uchar buffer[50];
	int numberLength;                    //Длина номера телефона.

	printf("enter phone: ");
	scanf_s("%s", buffer, 50);           //Ввод номера телефона.

	numberLength = strlen(buffer) + 1;   //Ввод номера телефона.

	//Перераспределить память под новый номер и сохранить его в ней.
	phoneBook[contactIndex].phoneNumber = (uchar*)realloc(phoneBook[contactIndex].phoneNumber, numberLength * sizeof(uchar));
	if (!phoneBook[contactIndex].phoneNumber)
	{
		printf("Memory realloc failed!");
		return;
	}

	strcpy_s(phoneBook[contactIndex].phoneNumber, numberLength, buffer);
}

//Изменить email.
void UpdateEmail(phonebook* phoneBook, int contactIndex)
{
	uchar buffer[50];
	int emailLength;                    //Длина номера email.

	printf("enter email: ");
	scanf_s("%s", buffer, 50);          //Ввод номера emai;.

	emailLength = strlen(buffer) + 1;   //Ввод номера emai.

	//Перераспределить память под новый email и сохранить его в ней.
	phoneBook[contactIndex].email = (uchar*)realloc(phoneBook[contactIndex].email, emailLength * sizeof(uchar));
	if (!phoneBook[contactIndex].email)
	{
		printf("Memory realloc failed!");
		return;
	}

	strcpy_s(phoneBook[contactIndex].email, emailLength, buffer);
}

//Изменить ZipCode.
void UpdateZipCode(phonebook* phoneBook, int contactIndex)
{
	ulong newZipCode;

	printf("enter zipcode: ");
	scanf_s("%lld", &newZipCode);                   //Ввод нового ZipCode.

	phoneBook[contactIndex].zipCode = newZipCode;   //Сохранить новый Zipcode.
}

//Изменить контакт.
void UpdateContact(phonebook* phoneBook, int contactIndex)
{
	UpdateName(phoneBook, contactIndex);
	UpdatePhoneNumber(phoneBook, contactIndex);
	UpdateEmail(phoneBook, contactIndex);
	UpdateZipCode(phoneBook, contactIndex);
}
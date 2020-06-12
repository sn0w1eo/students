#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdarg.h"

#include "phonebook.h"
#include "memory.h"

//====================================================РАБОТА С МАССИВОМ phoneBook====================================================

//Добавить новый контакт.
void AddContact(PhoneBook* phoneBook, const string name, const string phone, const string email, const string zip)
{
	ContactData* freeContactSlot = NULL;
	ContactData* newContacts = phoneBook->contacts;

	//Проверить корректность аргументов
	if (CheckArguments(newContacts, name, phone, email) == False)
	{
		printf("Invalid arguments!");
		return;
	}

	switch (IsFreeSpace(newContacts))                           //Проверить есть ли свободное место.
	{
	case True:                                                  //Если есть,
		freeContactSlot = GetFreeSpace(newContacts);            //то получить адресс ячейки в которую можно записать новые данные.
		break;
	
	case False:                                                 //Если нету,
		newContacts = ReallocStorageForContacts(newContacts);   //то перераспределить память
		freeContactSlot = GetFreeSpace(newContacts);            //и затем получить адресс ячейки в которую можно записать новые данные.
		break;
	}

	//Записать новые данные.
	SetName(freeContactSlot, name);
	SetPhone(freeContactSlot, phone);
	SetEmail(freeContactSlot, email);
	SetZipCode(freeContactSlot, zip);
	SetContactStatus(freeContactSlot, Existing);
	SetContacts(phoneBook, newContacts);
}

//Найти свободное место для записи новых данных.
ContactData* GetFreeSpace(ContactData* contacts)
{
	int size = GetSize(contacts);

	int index = 0;
	for (; index < size; index++)
	{
		//Если в поле структуры содержит NULL, значит ячейка структуры свободна.
		if (GetContactStatus(contacts[index]) == Blank)
		{
			break;
		}
	}

	return &contacts[index];
}

void UpdateContact(ContactData* contact, const string name, const string phoneNumber, const string email, const string zip)
{
	if (CheckArguments(contact, name, phoneNumber, email) == False)
	{
		printf("Invalid arguments!");
		return;
	}

	FreeContactMemory(contact);

	//Обновить данные в полях структуры.
	SetName(contact, name);
	SetPhone(contact, phoneNumber);
	SetEmail(contact, email);
	SetZipCode(contact, zip);
	SetContactStatus(contact, Existing);
}

//Удалить контакты.
void DeleteContacts(ContactData* contacts, int argumentsCount, ...)
{
	int contactIndex;
	int size = GetSize(contacts);;

	va_list vl;
	va_start(vl, argumentsCount);                         //Установить указатель на первый аргумент.
	
	while (argumentsCount--)
	{
		contactIndex = va_arg(vl, int);                   //Получить значение аргумента.
		
		if (contactIndex >= size || contactIndex < 0)     //Защита от выхода за границы доступной памяти.
		{
			continue;
		}

		FreeContactMemory(&contacts[contactIndex]);       //"Удалить" контакт путём освобождения всей выделенной памяти для него.
	}
	
	va_end(vl);
}

int GetContactsCount(ContactData* contacts)
{
	int contactsCounter = 0;

	for (int i = 0; i < GetSize(contacts); i++)
	{
		if (GetContactStatus(contacts[i]) == Existing)
		{
			contactsCounter++;
		}
	}

	return contactsCounter;
}

ContactData* GetFirstByteOfContacts(ContactData* contacts)
{
	return (ContactData*)((char*)contacts - sizeof(int));
}

ContactData* MoveByFourBytes(ContactData* contacts)
{
	return (ContactData*)((char*)contacts + sizeof(int));
}

//Отобразить все контакты.
void PrintContacts(ContactData* contacts)
{
	int size = GetSize(contacts);

	for (int i = 0; i < size; i++)
	{
		//Пропустить итерацию если поле в структуре содержит NULL.
		if (GetContactStatus(contacts[i]) == Blank)
		{
			continue;
		}
		else
		{
			printf(" %15s ", GetName(contacts[i]));
			printf(" %15s ", GetPhone(contacts[i]));
			printf(" %10s ", GetEmail(contacts[i]));
			printf("\t%5s \n\n", GetZipCode(contacts[i]));
		}
	}
}

//====================================================ГЕТТЕРЫ====================================================

//Полчить указатель на массив контактов.
ContactData* GetContacts(PhoneBook* phoneBook)
{
	return phoneBook->contacts;
}

//Получить размера блока данных типа ContactData.
int GetSize(ContactData* contacts)
{
	return *((char*)contacts - sizeof(int));
}

//Получить данные с поля name.
string GetName(ContactData contact)
{
	return contact.name;
}

//Получить данные с поля phoneNumber.
string GetPhone(ContactData contact)
{
	return contact.phone;
}

//Получить данные с поля email.
string GetEmail(ContactData contact)
{
	return contact.email;
}

//Получить данные с поля zip.
string GetZipCode(ContactData contact)
{
	return contact.zip;
}

//Получить данные с поля contactStatus.
int GetContactStatus(ContactData contact)
{
	return contact.contactStatus;
}

//Получить данные с определённого поля.
string GetContactDataFieldByArgument(ContactData contact, enum ContactInfo contactDataField)
{
	if (contact.contactStatus == Existing)
	{
		switch (contactDataField)
		{
		case Name:
			return GetName(contact);
		
		case Phone:
			return GetPhone(contact);
		
		case Email:
			return GetEmail(contact);
		
		case ZipCode:
			return GetZipCode(contact);
		}
	}

	return NULL;
}

//====================================================СЕТТЕРЫ====================================================

void SetContacts(PhoneBook* phoneBook, ContactData* contacts)
{
	phoneBook->contacts = contacts;
}

void SetSize(ContactData* contacts, const int size)
{
	*(int*)contacts = size;
}

//Установить новое имя в поле структуры name.
void SetName(ContactData* contact, const string name)
{
	contact->name = _strdup(name);
}

//Установить новый номер телефона в поле структуры phoneNumber.
void SetPhone(ContactData* contact, const string phone)
{
	contact->phone = _strdup(phone);
}

//Установить новый email в поле структуры email.
void SetEmail(ContactData* contact, const string email)
{
	contact->email = _strdup(email);
}

//Установить новый zipcode в поле структуры zip.
void SetZipCode(ContactData* contact, const string zip)
{
	contact->zip = _strdup(zip);
}

//Установить состояние контакта.
void SetContactStatus(ContactData* contact, enum ContactStatus status)
{
	contact->contactStatus = status;
}

//====================================================ЧЕКЕРЫ====================================================

//Проверить корректность аргументов.
int CheckArguments(ContactData* contacts, const string name, const string phone, const string email)
{
	if (contacts == NULL)
	{
		return False;
	}
	else if (name == NULL)
	{
		return False;
	}
	else if (phone == NULL)
	{
		return False;
	}
	else if (email == NULL)
	{
		return False;
	}
	else
	{
		return True;
	}
}

//Проверить если ли место.
int IsFreeSpace(ContactData* contacts)
{
	int size = GetSize(contacts);

	for (int i = 0; i < size; i++)
	{
		if (GetContactStatus(contacts[i]) == Blank)
		{
			return True;
		}
	}

	//Если цикл завершился, значит мест больше нет.
	return False;
}

//===================================================СОРТИРОВКА=================================================

int AscendingCompareByName(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook1->name, ptrBook2->name);
}

int AscendingCompareByPhoneNumber(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook1->phone, ptrBook2->phone);
}

int AscendingCompareByEmail(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook1->email, ptrBook2->email);
}

int AscendingCompareByZipCode(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook1->zip, ptrBook2->zip);
}

int DiscendingCompareByName(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook2->name, ptrBook1->name);
}

int DiscendingCompareByPhoneNumber(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook2->phone, ptrBook1->phone);
}

int DiscendingCompareByEmail(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook2->email, ptrBook1->email);
}

int DiscendingCompareByZipCode(void* a, void* b)
{
	const ContactData* ptrBook1 = a;
	const ContactData* ptrBook2 = b;

	return strcmp(ptrBook2->zip, ptrBook1->zip);
}
#pragma once
#pragma warning (disable : 4996)

#include "stdio.h"
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char* name, * phoneNumber, * email;
	int zipCode;
} contact;

void contactInit(contact*);
void contactDefine(contact*, const char*, const char*, const char*, int);
void contactCopy(contact*, contact);
void contactPrint(contact);
int	compare(contact, contact);
void contactChangeName(contact*, const char*);
void contactChangePhoneNumber(contact*, const char*);
void contactChangeEmail(contact*, const char*);
void contactChangeZipCode(contact*, int);
void contactFree(contact*);

typedef struct
{
	contact s;
	struct node* next, * prev;
} node;

typedef struct
{
	struct node* head, * tail;
} list;

void initList(list*);
void pushBack(list*, contact);
void listPrint(list l);
contact* listFind(list, contact);
void listFree(list*);
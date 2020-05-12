#include "list.h"

void contactInit(contact* s)
{
	s->name = s->phoneNumber = s->email = NULL;
	s->zipCode = 0;
}

void contactDefine(contact* s, const char* nname, const char* nphoneNumber, const char* nemail, int nzipCode)
{
	s->name = s->phoneNumber = s->email = NULL;
	s->name = (char*)realloc(s->name, sizeof(char) * (strlen(nname) + 1));
	strcpy(s->name, nname);
	s->phoneNumber = (char*)malloc(s->phoneNumber, sizeof(char) * (strlen(nphoneNumber) + 1));
	strcpy(s->phoneNumber, nphoneNumber);
	s->email = (char*)malloc(s->email, sizeof(char) * (strlen(nemail) + 1));
	strcpy(s->email, nemail);
	s->zipCode = nzipCode;
}


void contactCopy(contact* s, contact ns)
{
	s->name = s->phoneNumber = s->email = NULL;
	s->name = (char*)realloc(s->name, sizeof(char) * (strlen(ns.name) + 1));
	strcpy(s->name, ns.name);
	s->phoneNumber = (char*)malloc(s->phoneNumber, sizeof(char) * (strlen(ns.phoneNumber) + 1));
	strcpy(s->phoneNumber, ns.phoneNumber);
	s->email = (char*)malloc(s->email, sizeof(char) * (strlen(ns.email) + 1));
	strcpy(s->email, ns.email);
	s->zipCode = ns.zipCode;
}

void contactPrint(contact s)
{
	if (s.name != NULL)
	{
		printf("Имя: %s Номер телефона: %s Почтовый ящик: %s, Индекс: %d", s.name, s.phoneNumber, s.email, s.zipCode);
	}

}

int contactCompare(contact s, contact ns)
{
	return (!strcmp(s.name, ns.name) && !strcmp(s.phoneNumber, ns.phoneNumber) && !strcmp(s.email, ns.email));
}

void contactChangeZipCode(contact* s, int nzipCode)
{
	s->zipCode = nzipCode;
}
void contactChangeName(contact* s, const char* nname)
{
	s->name = NULL;
	s->name = (char*)malloc(s->name, sizeof(char) * (strlen(nname) + 1));
	strcpy(s->name, nname);
}
void contactChangePhoneNumber(contact* s, const char* nphoneNumber)
{
	s->phoneNumber = NULL;
	s->phoneNumber = (char*)malloc(s->phoneNumber, sizeof(char) * (strlen(nphoneNumber) + 1));
	strcpy(s->phoneNumber, nphoneNumber);
}
void contactChangeEmail(contact* s, const char* nemail)
{
	s->email = NULL;
	s->email = (char*)malloc(s->email, sizeof(char) * (strlen(nemail) + 1));
	strcpy(s->email, nemail);
}

void contactFree(contact* s)
{
	free(s->name);
	free(s->phoneNumber);
	free(s->email);
	s->zipCode = 0;
	s->name = s->phoneNumber = s->email = NULL;
}


void initList(list* l)
{
	l->head = l->tail = NULL;
}

void pushBack(list* l, contact ns)
{
	node* cur = l->tail;
	if (cur == NULL)
	{
		cur = l->head = l->tail = (node*)malloc(sizeof(node));
		contactCopy(&cur->s, ns);
		cur->next = cur->prev = NULL;
	}
	else
	{
		cur->next = (node*)malloc(sizeof(node));
		cur = cur->next;
		cur->prev = l->tail;
		cur->next = NULL;
		contactCopy(&cur->s, ns);
		l->tail = cur;
	}
}

void listPrint(list l)
{
	printf("\n");
	for (node* cur = l.head; cur; cur = cur->next)
	{
		contactPrint(cur->s);
		printf("\n");
	}
}

contact* listFind(list l, contact s)
{
	for (node* cur = l.head; cur; cur = cur->next)
		if (contactCompare(cur->s, s)) return &cur->s;
	return NULL;
}

void listFree(list* l)
{
	if (l->head == NULL) return;
	if (l->head != l->tail)
	{
		node* cur = l->tail;
		for (cur = cur->prev; cur != l->head; cur = cur->prev)
		{
			node* n = cur->next;
			contactFree(&n->s);
			free(cur->next);
		}
	}
	node* h = l->head;
	contactFree(&h->s);
	free(l->head);
	l->head = l->tail = NULL;
}

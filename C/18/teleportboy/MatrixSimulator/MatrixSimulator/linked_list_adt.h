#ifndef LINKED_LIST_ADT_H

#define LINKED_LIST_ADT_H

#include "include_libs.h"

typedef struct dlist_element {
	char* data;
	struct dlist_element* prev;
	struct dlist_element* next;
}dlist_element;

typedef struct dlist {
	int size;
	dlist_element* head;
	dlist_element* tail;
}dlist;

void dlist_init(dlist* list);
void append(dlist* list, char* new_data);
void parse_file_to_list(char* file_path, dlist* list);
void circulate_list(dlist* list);
char* get_node_data(dlist_element* list_node);

#endif // !LINKED_LIST_ADT_H

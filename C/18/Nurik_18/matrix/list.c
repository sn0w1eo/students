#include "list.h"
#include "stdio.h"
#include "stdlib.h"

void push(node_t** head_ref, int new_data)
{
	// allocate node 
	node_t* new_node = (node_t*)malloc(sizeof(node_t));

	// put in the data 
	new_node->data = new_data;

	// make next of new node as head and previous as NULL
	 
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	// change prev of head node to new node
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	// move the head to point to the new node
	(*head_ref) = new_node;
}

node_t* init_list(int max_value) {
	node_t* current = NULL;
	node_t* tail = NULL;
	int j = --max_value;
	for (int i = 0; i <= j; j--) {
		push(&current, j);
		if (j == max_value) {
			tail = current;
		}
		else if (i == j)
		{
			tail->next = current;
			current->prev = tail;
			return current;
		}
	}
	return current;
}

node_t* iterating_list(node_t* list, int data) {
	while (list->data != data)
		list = list->next;
	return list;
}

void free_memory_list(node_t* list, int height) {
	for (int i = 0; i < height - 1; i++) {
		free(list->prev);
		list->prev = NULL;
		if (i == height - 2) {
			free(list);
			list = NULL;
			break;
		}
		list = list->next;
	}
}
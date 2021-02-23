#ifndef LIST_H
#define LIST_H

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
} node_t;

// find the data you need
node_t* iterating_list(node_t* list, int data);

// init 
node_t* init_list(int max_value);

// add new data
void push(node_t** head_ref, int new_data);

// clear memory
void free_memory_list(node_t* list, int height);
#endif // !LIST_H

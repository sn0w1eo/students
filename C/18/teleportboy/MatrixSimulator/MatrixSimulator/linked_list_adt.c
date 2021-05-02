#include "include_libs.h"
#include "linked_list_adt.h"

void dlist_init(dlist* list) 
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
}

void append(dlist* list, char* new_data)
{
	if (!strcmp(new_data, "")) {
		return;
	}

	dlist_element* node = (dlist_element*)malloc(sizeof(dlist_element));

	node->data = _strdup(new_data);

	node->next = NULL;
	node->prev = list->tail;
	
	if (list->head == NULL) {
		list->head = node;
		list->tail = node;
		return;
	}

	list->tail->next = node;

	list->tail = node;
}

void circulate_list(dlist* list)
{
	dlist_element* node = list->head;

	while (node->next) {
		node = node->next;
	}

	node->next = list->head;
	list->head->prev = node;
}

void parse_file_to_list(char* file_path, dlist* list)
{
	FILE* file = NULL;
	char* music_path = calloc(MUSIC_PATH_SIZE + 1, sizeof(char));

	file = fopen(file_path, "r");
	
	while (!feof(file))
	{
		fgets(music_path, MUSIC_PATH_SIZE, file);
		music_path[strcspn(music_path, "\n")] = '\0';
		append(list, music_path);
		memset(music_path, 0, sizeof(char) * MUSIC_PATH_SIZE);
	}

	fclose(file);
	file = NULL;

	free(music_path);
	music_path = NULL;
}

char* get_node_data(dlist_element* list_node)
{
	return list_node->data;
}
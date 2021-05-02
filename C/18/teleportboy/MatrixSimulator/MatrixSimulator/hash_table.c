#include "include_libs.h"

int calculate_next_pos(int current_pos, int* hash_table)
{
	return hash_table[current_pos + 1];
}

int calculate_previos_pos(int current_pos, int* hash_table)
{
	return hash_table[current_pos];
}

int* init_hash_table(int size)
{
	int* hash_table = calloc(size, sizeof(int));
	if (!hash_table) {
		return NULL;
	}

	hash_table[0] = size - 3;
	for (int i = 1; i < size - 1; i++) {
		hash_table[i] = i - 1;
	}
	hash_table[size - 1] = 0;

	return hash_table;
}

void free_hashtable(int* hash_table)
{
	free(hash_table);
	hash_table = NULL;
}
#ifndef HASH_TABLE_H

#define HASH_TABLE_H

int calculate_next_pos(int current_pos, int* hash_table);
int calculate_previos_pos(int current_pos, int* hash_table);
int* init_hash_table(int size);
void free_hashtable(int* hash_table);

#endif // !HASH_TABLE_H

#ifndef GENERAL_H

#define GENERAL_H

#include "include_libs.h"
#include "linked_list_adt.h"

typedef struct object
{
	int                pressed_key;
	int                flag;
	int*               hash_table;
	dlist              music_list;
	Mix_Music*         music;
	sem_t              semaphore;
	pthread_barrier_t  barrier;
	wait_group         wg;
}object;

#define WHITE_BACKGROUND   0x70
#define BLACK_BACKGROUND   0x00

#endif // !GENERAL_H

#ifndef GENERAL_H

#define GENERAL_H

#include "include_libs.h"

typedef struct object
{
	int                pressed_key;
	int                flag;
	int*               hash_table;
	sem_t              semaphore;
	pthread_barrier_t  barrier;
	wait_group         wg;
}object;


#define QUIT               1
#define CLOSE_THREAD       2
#define ADD_THREAD         3

#define WHITE_BACKGROUND   0x70
#define BLACK_BACKGROUND   0x00

#endif // !GENERAL_H

#ifndef HEADER_H

#define HEADER_H
#include "libraries.h"

#define THREAD_WORKS 1

#define CLOSE_THREAD 0
#define QUIT 2

#define GREEN 2
#define WHITE 7
#define BLACK 0

typedef struct
{
	char key;
	sem_t semaphore;
	int flag;
	WaitGroup wg;
}Object;

#endif // !HEADER_H


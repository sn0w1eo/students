#ifndef OBJECT_H
#define OBJECT_H

#include "semaphore.h"
#include "pthread.h"
#include "waitgroup.h"

// ASCII from 'A' to 'Z'
#define ASCII_FROM 65
#define ASCII_TO   90

// color 
#define BLACK_BKGROUND_GREEN_FRGROUND 002
#define WHITE_BKGROUND_GREEN_FRGROUND 114

// for random length 
#define MAX_RAND_CHAR  20
#define ZERO		   0

typedef struct {
	// for operations '+', '-'. 'q'
	int Flag;

	// check functions for errors
	int rc;

	// wait group
	WaitGroup wg;

	// for threads
	sem_t sem;
	pthread_mutex_t mutex_main, mutex_thread, mutex_matrix;
	pthread_cond_t cond_main, cond_thread;

	int width, height;
}Object;

enum operations {
	ADD = 43,
	MINUS = 45,
	QUIT = 113,
	EMPTY = 1,
};
#endif // !OBJECT_H

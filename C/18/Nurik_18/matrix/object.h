#ifndef OBJECT_H
#define OBJECT_H

#include "list.h"
#include "semaphore.h"
#include "waitgroup.h"

#define WHITE_BACKGROUND   0x70
#define BLACK_BACKGROUND   0x00
#define GREEN_FOREGROUND   0x0002

#define MIN_ASCII		   65
#define MAX_ASCII		   90
#define MAX_LENGTH		   50

typedef struct {
	// choose operation
	int flag;
	// max height of monitor 
	int height;
	// max width of monitor
	int width;
	// check result of functions
	int rc;
	// list for counting height of monitor
	node_t* list;
	// wait group
	wait_group wg;
	// semaphore
	sem_t sem;
}Object;

enum operations {
	ADD = 43,
	MINUS = 45,
	QUIT = 113,
};

#endif // !OBJECT_H
#include "check.h"
#include "stdio.h"
#include "object.h"
#include "stdlib.h"

void exit_on_error(int rc, int lineNumber) {
	if (rc) {
		printf("Error: %d. Line: %d.\n", rc, lineNumber);
		_getch();
		exit(rc);
	}
}


int is_thread_close(Object* obj)
{
	sem_wait(&obj->sem_flag);
	switch (obj->flag)
	{
	case MINUS:
		// if flag == '-' change flag and destroy this thread
		obj->flag = -1;
		sem_post(&obj->sem_flag);
		return 1;

	case QUIT:
		// destroy all threads
		sem_post(&obj->sem_flag);
		return 1;

	default:
		sem_post(&obj->sem_flag);
		return 0;
	}
}
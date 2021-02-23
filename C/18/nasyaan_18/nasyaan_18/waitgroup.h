#ifndef WAITGROUP_H

#define WAITGROUP_H

#include "pthread.h"

typedef struct WaitGroup {
	pthread_mutex_t mutex;
	int threadsCounter;
}WaitGroup;

WaitGroup WgInit();
void WgAdd(WaitGroup* wg, int amount);
void WgDone(WaitGroup* wg);
void WgWait(WaitGroup* wg);
int WgIsEmpty(WaitGroup* wg);

#endif // !WAITGROUP_H
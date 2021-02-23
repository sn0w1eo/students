#include "waitgroup.h"

WaitGroup WgInit()
{
	WaitGroup wg = {
		.threadsCounter = 0,
		.mutex = PTHREAD_MUTEX_INITIALIZER,
	};
	return wg;
}

void WgAdd(WaitGroup* wg, int amount)
{
	pthread_mutex_lock(&wg->mutex);
	wg->threadsCounter += amount;
	pthread_mutex_unlock(&wg->mutex);
}

void WgDone(WaitGroup* wg)
{
	pthread_mutex_lock(&wg->mutex);
	wg->threadsCounter--;
	pthread_mutex_unlock(&wg->mutex);
}

void WgWait(WaitGroup* wg)
{
	while (!WgIsEmpty(wg));
}

int WgIsEmpty(WaitGroup* wg) {
	pthread_mutex_lock(&wg->mutex);
	int res = wg->threadsCounter;
	pthread_mutex_unlock(&wg->mutex);
	if (res == 0) {
		return 1;
	}
	return 0;
}
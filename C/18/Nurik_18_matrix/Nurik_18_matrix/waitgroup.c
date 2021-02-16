#include "waitgroup.h"


WaitGroup CreateWG() {
	WaitGroup wg = {
		.counter = 0,
		.mu = PTHREAD_MUTEX_INITIALIZER,
	};
	return wg;
}

void WG_Add(WaitGroup* wg, int amount) {
	pthread_mutex_lock(&wg->mu);
	wg->counter += amount;
	pthread_mutex_unlock(&wg->mu);
}

void WG_Done(WaitGroup* wg) {
	pthread_mutex_lock(&wg->mu);
	wg->counter--;
	pthread_mutex_unlock(&wg->mu);
}

int WG_IsEmpty(WaitGroup* wg) {
	pthread_mutex_lock(&wg->mu);
	int res = wg->counter;
	pthread_mutex_unlock(&wg->mu);
	if (res == 0) return 1;
	return 0;
}
#include "waitgroup.h"


wait_group ñreate_wg() {
	wait_group wg = {
		.counter = 0,
		.mu = PTHREAD_MUTEX_INITIALIZER,
	};
	return wg;
}

void wg_add(wait_group* wg, int amount) {
	pthread_mutex_lock(&wg->mu);
	wg->counter += amount;
	pthread_mutex_unlock(&wg->mu);
}

void wg_done(wait_group* wg) {
	pthread_mutex_lock(&wg->mu);
	wg->counter--;
	pthread_mutex_unlock(&wg->mu);
}

int wg_is_empty(wait_group* wg) {
	pthread_mutex_lock(&wg->mu);
	int res = wg->counter;
	pthread_mutex_unlock(&wg->mu);
	if (res == 0) return 1;
	return 0;
}

void wg_wait(wait_group* wg) {
	while (wg->counter != 0);
}
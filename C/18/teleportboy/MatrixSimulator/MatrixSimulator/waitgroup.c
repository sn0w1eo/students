#include "include_libs.h"

#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"

wait_group wg_init()
{
	wait_group wg = {
		.threads_counter = 0,
		.mutex = PTHREAD_MUTEX_INITIALIZER,
	};
	return wg;
}

void wg_add(wait_group* wg, int amount)
{
	pthread_mutex_lock(&wg->mutex);
	wg->threads_counter += amount;
	pthread_mutex_unlock(&wg->mutex);
}

void wg_done(wait_group* wg)
{
	pthread_mutex_lock(&wg->mutex);
	wg->threads_counter--;
	pthread_mutex_unlock(&wg->mutex);
}

void wg_wait(wait_group* wg)
{	
	while (!wg_is_empty(wg));
}

int wg_is_empty(wait_group* wg) {
	pthread_mutex_lock(&wg->mutex);
	int res = wg->threads_counter;
	pthread_mutex_unlock(&wg->mutex);
	if (res == 0) {
		return 1;
	}
	return 0;
}
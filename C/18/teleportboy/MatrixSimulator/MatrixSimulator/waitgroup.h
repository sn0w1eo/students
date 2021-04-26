#ifndef WAITGROUP_H

#define WAITGROUP_H

typedef struct wait_group {
	pthread_mutex_t mutex;
	int threads_counter;
}wait_group;


wait_group wg_init();
void wg_add(wait_group* wg, int amount);
void wg_done(wait_group* wg);
void wg_wait(wait_group* wg);
int wg_is_empty(wait_group* wg);

#endif // !WAITGROUP_H
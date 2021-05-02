#include "stdio.h"
#include "pthread.h"
#include "semaphore.h"
#include "windows.h"
#include "stdbool.h"

#include "waitgroup.h"
#include "winapi.h"
#include "list.h"
#include "object.h"
#include "check.h"

void manipulation_threads(Object* obj);
void* matrix(void* arg);

int main() {
	// Max size of console
	maximize_window();
	show_cursor(false);
	
	Object obj = { .flag = 0,
				   .wg = ñreate_wg(),
				   .height = get_height(),
				   .width = get_width(),
				   .list = init_list(obj.height),
				   .rc = 0 };

	// init semaphore
	obj.rc = sem_init(&obj.sem_threads, 0, 1);
	exit_on_error(obj.rc, __LINE__);
	obj.rc = sem_init(&obj.sem_flag, 0, 1);
	exit_on_error(obj.rc, __LINE__);
	
	// main thread will manipulate with new threads 
	manipulation_threads(&obj);

	// clear dynamic memory in list
	free_memory_list(obj.list, obj.height);

	// destroy mutex && semaphore
	obj.rc = pthread_mutex_destroy(&obj.wg.mu);
	exit_on_error(obj.rc, __LINE__);
	obj.rc = sem_destroy(&obj.sem_threads);
	exit_on_error(obj.rc, __LINE__);
	obj.rc = sem_destroy(&obj.sem_flag);
	exit_on_error(obj.rc, __LINE__);

	return 0;
}

void manipulation_threads(Object* obj) {
	while (obj->flag != QUIT)
	{
		// keyboard input 
		obj->flag = _getch();
		if (obj->flag == ADD) {
			pthread_t thread;
			obj->rc = pthread_create(&thread, NULL, (void*)matrix, (void*)obj);
			exit_on_error(obj->rc, __LINE__);
		}
	}
	// wait while threads doing last operation
	wg_wait(&obj->wg);
}

void* matrix(void* arg) {
	Object* obj = arg;
	// we need list to count height of monitor 
	node_t* list = NULL;
	node_t* list_for_space = NULL;
	// take head of list
	list = obj->list;
	// add 1 thread to WG
	wg_add(&obj->wg, 1);

	while (!is_thread_close(obj)) {
		// random coordinate and length
		COORD coord_for_char = rand_coordinate(obj->width, obj->height - 1);
		int length = random(0, MAX_LENGTH);

		// we will repeat list while data == coord_for_char.Y  
		list = iterating_list(list, coord_for_char.Y);
		list_for_space = list;

		for (int i = 0; i < length; i++) {
			// binary semaphore
			sem_wait(&obj->sem_threads);

			// set coordinate
			set_coord(coord_for_char.X, list->data);

			// print random symbol
			printf("%c", random(MIN_ASCII, MAX_ASCII));

			// set white background && green foreground for current coordinate
			// and black background && green foreground for previos coordinate
			set_colors(WHITE_BACKGROUND | GREEN_FOREGROUND, BLACK_BACKGROUND | GREEN_FOREGROUND, coord_for_char.X, list);

			// sleep_time(obj->wg.counter);
			sem_post(&obj->sem_threads);

			// next data
			list = list->next;
		}
		// black background && green foreground for last coordinate
		list = list->prev;
		set_bkcolor(BLACK_BACKGROUND | GREEN_FOREGROUND, coord_for_char.X, list->data);

		for (int i = 0; i < length; i++) {
			sem_wait(&obj->sem_threads);

			set_coord(coord_for_char.X, list_for_space->data);
			printf(" ");

			// sleep_time(obj->wg.counter);
			sem_post(&obj->sem_threads);
			
			// next data
			list_for_space = list_for_space->next;
		}
	}
	wg_done(&obj->wg);
	return NULL;
}
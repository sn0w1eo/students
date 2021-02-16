#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "semaphore.h"
#include "pthread.h"
#include "stdbool.h"

#include "coord_color.h"
#include "check.h"
#include "rand.h"
#include "waitgroup.h"
#include "win_api.h"
#include "destroy.h"
#include "object.h"

void* matrix(void* arg) {
	Object* obj = arg;
	while (1)
	{ 
		pthread_mutex_lock(&obj->mutex_matrix);
		if (obj->Flag == QUIT) {
			// each thread minuses itself
			WG_Done(&obj->wg); 
			if (WG_IsEmpty(&obj->wg) == EMPTY) {
				// if there are no threads, signal to manipulation_thread
				pthread_cond_signal(&obj->cond_thread);
				return NULL;
			}
			pthread_mutex_unlock(&obj->mutex_matrix);
			return NULL;
		} else if (obj->Flag == MINUS) {
			// thread minuses itself
			WG_Done(&obj->wg);
			// change flag, another thread does not enter
			obj->Flag = NULL;
			// signal to manipulation_thread
			pthread_cond_signal(&obj->cond_thread);
			pthread_mutex_unlock(&obj->mutex_matrix);
			return NULL;
		}
		pthread_mutex_unlock(&obj->mutex_matrix);

		// each thread take random coordinate
		COORD coord_to_char = rand_coordinate(obj->width, obj->height - 1);
		COORD coord_to_space = rand_coordinate(obj->width, obj->height - 1);

		// previos symbol and rand new symbol
		char prev_ch = 0;
		char new_ch = 0;

		// rand Loop
		for (int i = ZERO, length = random(ZERO, MAX_RAND_CHAR); i < length; i++) {

			// rand character from 'A' - 'Z'
			new_ch = ASCII_FROM + random(0, ASCII_TO - ASCII_FROM);

			// check height if height == MAX_HEIGHT, we set starting position 
			coord_to_char.Y = check_next_position(i, coord_to_char.Y, obj->height);

			// binary semaphore because here we have data racing 
			sem_wait(&obj->sem);
			// if next position is ZERO line we change last position background
			if ((coord_to_char.Y + i) == ZERO && coord_to_char.Y < 0) {
				set_coord_and_color(coord_to_char.X, obj->height - 1, BLACK_BKGROUND_GREEN_FRGROUND);
				printf("%c", prev_ch);
			}
			// change previous position background
			else if (i > 0){
				set_coord_and_color(coord_to_char.X, coord_to_char.Y + i - 1, BLACK_BKGROUND_GREEN_FRGROUND);
				printf("%c", prev_ch);
			}

			// set WHITE_BKGROUND_GREEN_FRGROUND color and rand coordinate 
			set_coord_and_color(coord_to_char.X, coord_to_char.Y + i, WHITE_BKGROUND_GREEN_FRGROUND);
			printf("%c", new_ch);

			// change last position background
			if ((length - 1) == i) {
				set_coord_and_color(coord_to_char.X, coord_to_char.Y + i, BLACK_BKGROUND_GREEN_FRGROUND);
				printf("%c", new_ch);
			}
			prev_ch = new_ch;
			sem_post(&obj->sem);
		}

		for (int i = ZERO, length = random(ZERO, MAX_RAND_CHAR); i < length; i++) {

			// check height if height == MAX_HEIGHT, we set starting position 
			coord_to_space.Y = check_next_position(i, coord_to_space.Y, obj->height);

			// binary semaphore because here we have data racing 
			sem_wait(&obj->sem);

			// if next position is ZERO line we change last position background
			if ((coord_to_space.Y + i) == ZERO && coord_to_space.Y < 0) {
				set_coord_and_color(coord_to_space.X, obj->height - 1, BLACK_BKGROUND_GREEN_FRGROUND);
				printf(" ");
			} 
			// change previous position background
			else if (i > 0) {
				set_coord_and_color(coord_to_space.X, coord_to_space.Y + i - 1, BLACK_BKGROUND_GREEN_FRGROUND);
				printf(" ");
			}

			set_coord_and_color(coord_to_space.X, coord_to_space.Y + i, WHITE_BKGROUND_GREEN_FRGROUND);
			printf(" ");

			// change last position background
			if ((length - 1) == i) {
				set_coord_and_color(coord_to_space.X, coord_to_space.Y + i, BLACK_BKGROUND_GREEN_FRGROUND);
				printf(" " );
			}
			sem_post(&obj->sem);
		}
	}
}

void* manipulation_threads(void* arg) {
	Object* obj = arg;
	while (1)
	{
		// keyboard input 
		obj->Flag = _getch();
		switch (obj->Flag)
		{
		case ADD:
			// add 1 thread to WG
			WG_Add(&obj->wg, 1); 
			pthread_t thread;
			pthread_create(&thread, NULL, (void*)matrix, (void*)obj);
			break;
		case MINUS:
			if (!WG_IsEmpty(&obj->wg) == 1) {
				// wait while one thread not finished 
				pthread_cond_wait(&obj->cond_thread, &obj->mutex_thread);
			}
			break;
		case QUIT:
			if (!WG_IsEmpty(&obj->wg) == EMPTY) {
				// wait while all threads will finish their works
				pthread_cond_wait(&obj->cond_thread, &obj->mutex_thread);
			}
			// signal to main
			pthread_cond_signal(&obj->cond_main);
			return NULL;
		}
	}
}

int main() {
	Object obj = { .Flag = NULL,
				   .cond_main = PTHREAD_COND_INITIALIZER,
				   .cond_thread = PTHREAD_COND_INITIALIZER,
				   .mutex_main = PTHREAD_MUTEX_INITIALIZER,
				   .mutex_thread = PTHREAD_MUTEX_INITIALIZER,
				   .mutex_matrix = PTHREAD_MUTEX_INITIALIZER,
				   .wg = CreateWG(),
				   .width = ZERO, .height = ZERO};

	pthread_t manipulate_threads;

	obj.rc = sem_init(&obj.sem, 0, 1);
	ExitOnError(obj.rc, __LINE__);

	get_size_monitor(&obj.width, &obj.height);

	show_cursor(false);

	obj.rc = pthread_create(&manipulate_threads, NULL, manipulation_threads, &obj);
	ExitOnError(obj.rc, __LINE__);

	obj.rc = pthread_cond_wait(&obj.cond_main, &obj.mutex_main);
	ExitOnError(obj.rc, __LINE__);

	pthread_join(manipulate_threads, NULL);

	obj.rc = sem_destroy(&obj.sem);
	ExitOnError(obj.rc, __LINE__);

	obj.rc = pthread_cond_destroy(&obj.cond_main);
	ExitOnError(obj.rc, __LINE__);

	obj.rc = pthread_mutex_destroy(&obj.wg.mu);
	ExitOnError(obj.rc, __LINE__);

	return 0;
}
#include "include_libs.h"

#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"

void* keyboard_input(void* args)
{
	object* func_args = (object*)args;
	wg_add(&func_args->wg, 1);

	do {

		func_args->pressed_key = getch();
		pthread_cond_signal(&func_args->input_cond);
		pthread_barrier_wait(&func_args->barrier);

	} while (func_args->pressed_key != 'q');

	wg_done(&func_args->wg);

	return NULL;
}

void* input_handler(void* args)
{
	object* func_args = (object*)args;
	wg_add(&func_args->wg, 1);
	pthread_t thread;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	do {
		pthread_cond_wait(&func_args->input_cond, &mutex);

		switch (func_args->pressed_key)
		{
		case '+':
			send_signal(func_args, ADD_THREAD);
			pthread_create(&thread, NULL, string_to_console, (void*)func_args);
			break;

		case '-':
			send_signal(func_args, CLOSE_THREAD);
			break;

		case 'q':
			send_signal(func_args, QUIT);
			break;

		default:
			break;
		}
		pthread_barrier_wait(&func_args->barrier);
	} while (func_args->pressed_key != 'q');

	pthread_mutex_destroy(&mutex);

	wg_done(&func_args->wg);

	return NULL;
}

void* string_to_console(void* arg)
{
	object* arguments = (object*)arg;
	wg_add(&arguments->wg, 1);

	COORD coordinates = { .X = 0, .Y = 0 };
	int console_height = get_console_height();
	int console_width = get_console_width();

	int* flag = &arguments->flag;

	while (!is_close_signal(arguments)) {
		int coord_x = random_number(1, console_width);
		int coord_y = random_number(1, console_height);
		int string_length = random_number(1, console_height);
		unsigned char alpha = 0;

		for (int i = 0; i < string_length; i++) {

			sem_wait(&arguments->semaphore);

			alpha = random_char(166, 221);
			coord_y = calculate_next_pos(coord_y, arguments->hash_table);
			int rc = print_char(alpha, coord_x, coord_y);
			if (rc == 0) {
				sem_post(&arguments->semaphore);
				break;
			}
			highlight_cursor(WHITE_BACKGROUND | FOREGROUND_GREEN, BLACK_BACKGROUND | FOREGROUND_GREEN,
				coord_x, coord_y, arguments->hash_table);

			coord_y = coord_y + 1;
		
			sem_post(&arguments->semaphore);
			
		}
		sem_wait(&arguments->semaphore);
		highlight_cursor(0, BLACK_BACKGROUND | FOREGROUND_GREEN,
			coord_x, coord_y, arguments->hash_table);
		sem_post(&arguments->semaphore);

		for (int i = 0; i < console_height; i++) {
			sem_wait(&arguments->semaphore);
			coord_y = calculate_next_pos(coord_y, arguments->hash_table);
			int rc = print_char(' ', coord_x, coord_y);
			if (rc == 0) {
				sem_post(&arguments->semaphore);
				break;
			}

			coord_y = coord_y + 1;
			
			sem_post(&arguments->semaphore);
			
		}
	}

	wg_done(&arguments->wg);

	return NULL;
}

int print_char(unsigned char symbol, int coord_x, int coord_y)
{
	int rc = set_console_cursor(coord_x, coord_y);
	if (rc == 0) {
		return 0;
	}
	printf_s("%c", symbol);

	return 1;
}

int highlight_cursor(int current_cursor_color, int previos_cursor_color, int coord_x, int coord_y, int* hash_table)
{
	coord_y = calculate_next_pos(coord_y, hash_table);
	set_console_color(current_cursor_color, coord_x, coord_y);

	coord_y = calculate_previos_pos(coord_y, hash_table);
	set_console_color(previos_cursor_color, coord_x, coord_y);
}

int set_console_cursor(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor_position = { 0 };
	cursor_position.X = x;
	cursor_position.Y = y;
	return (int)SetConsoleCursorPosition(console, cursor_position);
}

void set_console_color(int color, int x, int y)
{
	COORD cursor_position = { 0 };
	cursor_position.X = x;
	cursor_position.Y = y;

	int a = 0;

	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		color, 1, cursor_position, &a);
}
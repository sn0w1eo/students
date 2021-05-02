#include "include_libs.h"

#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"
#include "sound.h"

void* keyboard_input(void* args)
{
	object* func_args = (object*)args;

	do {
		//Read pressed key into memory
		func_args->pressed_key = getch();
		//Wait until pressed key isn't handled
		pthread_barrier_wait(&func_args->barrier);

	} while (func_args->pressed_key != QUIT);

	//Thread is done
	wg_done(&func_args->wg);

	return NULL;
}

void* input_handler(void* args)
{
	object* func_args = (object*)args;

	pthread_t thread;
	dlist_element* current_node = func_args->music_list.head;
	int current_key = 0;
	
	do {
		//Wait until key isn't pressed
		pthread_barrier_wait(&func_args->barrier);
		
		//Input key handling
		current_key = func_args->pressed_key;
		switch (current_key)
		{
		case ADD_THREAD:
			send_signal(func_args, NEW_THREAD);
			pthread_create(&thread, NULL, string_to_console, (void*)func_args);
			wg_add(&func_args->wg, 1);
			break;

		case CLOSE_THREAD:
			send_signal(func_args, END_THREAD);
			break;

		case QUIT:
			send_signal(func_args, CLOSE_PROGRAM);
			break;

		case PREV_MUSIC:
			current_node = current_node->prev;
			func_args->music = play_sound(get_node_data(current_node), func_args->music);
			break;

		case NEXT_MUSIC:
			current_node = current_node->next;
			func_args->music = play_sound(get_node_data(current_node), func_args->music);
			break;
		}

	} while (func_args->pressed_key != QUIT);
	
	//Thread is done
	wg_done(&func_args->wg);

	return NULL;
}

void* string_to_console(void* arg)
{
	object* arguments = (object*)arg;

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
			alpha = random_char(166, 221);
			//Critical section
			sem_wait(&arguments->semaphore);
			int rc = print_char(alpha, coord_x, coord_y);
			if (rc == 0) {
				sem_post(&arguments->semaphore);
				break;
			}
			highlight_cursor(WHITE_BACKGROUND | FOREGROUND_GREEN, BLACK_BACKGROUND | FOREGROUND_GREEN,
				coord_x, coord_y, arguments->hash_table);
			//End critical section
			sem_post(&arguments->semaphore);

			coord_y = calculate_next_pos(coord_y + 1, arguments->hash_table);
		}
		sem_wait(&arguments->semaphore);
		highlight_cursor(0, BLACK_BACKGROUND | FOREGROUND_GREEN,
			coord_x, coord_y, arguments->hash_table);
		sem_post(&arguments->semaphore);

		//Print empty string
		for (int i = 0; i < console_height; i++) {
			sem_wait(&arguments->semaphore);
			int rc = print_char(' ', coord_x, coord_y);
			if (rc == 0) {
				sem_post(&arguments->semaphore);
				break;
			}
			sem_post(&arguments->semaphore);
			
			coord_y = calculate_next_pos(coord_y + 1, arguments->hash_table);
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

void diplay_info()
{
	set_console_cursor(100, 25);
	printf("ADD THREAD:          key:  +");
	set_console_cursor(100, 26);
	printf("CLOSE RADNOM THREAD: key:  -");
	set_console_cursor(100, 27);
	printf("CLOSE PROGRAMM:      key:  q");
	set_console_cursor(100, 28);

	printf("SET MUSIC VOLUME:    keys: 1 - 5");
	set_console_cursor(100, 29);
	printf("OFF MUSIC:           key:  0");
	set_console_cursor(100, 32);
	printf("PRESS ANY KEY TO CONTINUE");
	getch();
	system("cls");
}
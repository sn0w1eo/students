#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <windows.h>

#define _CRT_RAND_S

typedef struct object
{
	int                key;
	int                flag;
	pthread_cond_t     cond;
	sem_t              semaphore;
}object;


#define QUIT 1
#define CLOSE_THREAD 2

void* string_to_console(void* args);
void* keyboard_input(void* args);
void* input_handler(void* args);
int is_thread_close(int* flag);
void set_console_cursor(int x, int y);
void set_console_color(int color);

void send_signal(int* flag, int signal_code);

int calculate_next_pos(int current_pos, int console_height);

int random_number(int min_value, int max_value);
void rand_console_coords(COORD* coordinates, int min_value, int max_value);
void start_randomizer();


void get_console_sizes(int* height, int* width);

void* keyboard_input(void* args)
{
	object* func_args = (object*)args;

	do {

		//TO DO: KEYBOARD HOOKS
		func_args->key = getch();
		pthread_cond_signal(&func_args->cond);

		//func_args->key = 'q';
	} while (func_args->key != 'q');

	return NULL;
}

void* input_handler(void* args)
{
	object* func_args = (object*)args;
	pthread_t thread;
	pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	while (func_args->key != 'q') {

		pthread_cond_wait(&func_args->cond, &mutex);

		switch (func_args->key)
		{
			case '+':
				pthread_create(&thread, NULL, string_to_console, (void*)func_args);
				break;

			case '-':
				//TO DO
				send_signal(&func_args->flag, CLOSE_THREAD);
				break;

			case 'q':
				//TO DO
				send_signal(&func_args->flag, QUIT);
				break;

			default:
				break;
		}
	}

	return NULL;
}

void send_signal(int* flag, int signal_code)
{
	*flag = signal_code;
}

int random_number(int min_value, int max_value)
{
	unsigned int number = 1;
	rand_s(&number);
	number = (unsigned int) ( (double)number / ((double)UINT_MAX + 1) * max_value ) + min_value;
	return number;
}

void rand_console_coords(COORD* coordinates, int console_width, int console_height)
{
	coordinates->X = random_number(1, console_width);
	coordinates->Y = random_number(1, console_height);
}

char random_char(int min_ascii, int max_ascii)
{
	return random_number(min_ascii, max_ascii);
}

void start_randomizer()
{
	srand(time(NULL));
}

int get_console_width()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Right;
}

int get_console_height()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Bottom;
}

int calculate_next_pos(int current_pos, int console_height)
{
	current_pos = current_pos % console_height;
	return current_pos;
}

void* string_to_console(void* arg)
{
	object* arguments = (object*)arg;
	
	COORD coordinates = { .X = 0, .Y = 0 };
	int console_height = get_console_height();
	int console_width = get_console_width();
	
	int* flag = &arguments->flag;
	while (!is_thread_close(flag)) {
		int x = random_number(1, console_width);
		int y = random_number(1, console_height);
		int string_length = random_number(6, console_height);

		char alpha = 0;
		int i = 0;

		for (; i < string_length; i++) {
			alpha = random_char(64, 94);

			sem_wait(&arguments->semaphore);
			set_console_color(117);
			set_console_cursor(x, (y + i) % console_height);
			printf("%c", alpha);

			set_console_cursor(x, (y + i - 1) % console_height);
			set_console_color(002);
			printf("%c", alpha);
			sem_post(&arguments->semaphore);
		}

		sem_wait(&arguments->semaphore);
		set_console_cursor(x, (y + i - 1) % console_height);
		set_console_color(002);
		printf("%c", alpha);
		sem_post(&arguments->semaphore);

		//rand_console_coords(&coordinates, console_width, console_height);
		string_length = random_number(1, console_height);
		x = random_number(1, console_width);
		y = random_number(1, console_height);
		for (int i = 0; i < string_length; i++) {
			sem_wait(&arguments->semaphore);

			set_console_cursor(x, (y + i) % console_height);
			printf(" ");

			sem_post(&arguments->semaphore);
		}
	}

	return NULL;
}

int is_thread_close(int* flag)
{
	static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

	//pthread_mutex_lock(&mutex);

	switch (*flag)
	{
		case CLOSE_THREAD:
			*flag = -1;
			//pthread_mutex_unlock(&mutex);
			return 1;

		case QUIT:
			//pthread_mutex_unlock(&mutex);
			return 1;

		default:
			//pthread_mutex_unlock(&mutex);
			return 0;
	}
}


int main()
{
	//start_randomizer();
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	object obj = { .flag = 0, .key = 0, .cond = PTHREAD_COND_INITIALIZER};
	sem_init(&obj.semaphore, 0, 1);

	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, keyboard_input, (void*)&obj);
	pthread_create(&thread2, NULL, input_handler, (void*)&obj);
	
	pthread_join(thread2, NULL);

	return 0;
}


void set_console_cursor(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0 };
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(console, cursorPosition);
}

void set_console_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
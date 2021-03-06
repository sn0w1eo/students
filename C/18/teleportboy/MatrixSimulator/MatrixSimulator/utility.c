#include "include_libs.h"

#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"
#include "linked_list_adt.h"

void init_object(object* obj, char* musics_path)
{
	obj->flag = 0;
	obj->pressed_key = 0;
	obj->hash_table = init_hash_table(get_console_height() + 2);
	dlist_init(&obj->music_list);
	parse_file_to_list(musics_path, &obj->music_list);
	circulate_list(&obj->music_list);
	sem_init(&obj->semaphore, 0, 1);
	pthread_barrier_init(&obj->barrier, NULL, 2);
	obj->wg.threads_counter = 0;
	pthread_mutex_init(&obj->wg.mutex, NULL);
}

int is_close_signal(object* obj)
{
	sem_wait(&obj->semaphore);
	switch (obj->flag)
	{
		case END_THREAD:
			obj->flag = -1;
			sem_post(&obj->semaphore);
			return 1;

		case CLOSE_PROGRAM:
			sem_post(&obj->semaphore);
			return 1;

		default:
			sem_post(&obj->semaphore);
			return 0;
	}
}

void send_signal(object* obj, int signal_code)
{
	sem_wait(&obj->semaphore);
	obj->flag = signal_code;
	sem_post(&obj->semaphore);
}

int random_number(int min_value, int max_value)
{
	unsigned int number = 1;
	rand_s(&number);
	number = (unsigned int)(max_value - min_value + 1) * ((double)number / ((double)UINT_MAX + 1)) + min_value;
	return number;
}

unsigned char random_char(int min_ascii, int max_ascii)
{
	return random_number(min_ascii, max_ascii);
}

void music_paths_to_txt(char* music_folder_path, char* txt_path)
{
	char* command = calloc(MUSIC_PATH_SIZE, sizeof(char));

	sprintf(command, "dir %s /b /s > %s", music_folder_path, txt_path);
	system(command);

	free(command);
	command = NULL;
}

void maximize_window()
{
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleDisplayMode(hstdout, CONSOLE_FULLSCREEN_MODE, 0);
	
	COORD window_coords = { 0 };
	window_coords.X = get_console_width();
	window_coords.Y = get_console_height();
	SetConsoleScreenBufferSize(hstdout, window_coords);

	HWND console = GetConsoleWindow();
	ShowScrollBar(console, SB_BOTH, FALSE);
}

int get_console_width()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Right + 1;
}

int get_console_height()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Bottom + 1;
}
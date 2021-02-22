#define _CRT_RAND_S

#include "include_libs.h"
#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"

int main() {

	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	object obj;
	init_object(&obj);

	system("chcp 932 > nul");
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, keyboard_input, (void*)&obj);
	pthread_create(&thread2, NULL, input_handler, (void*)&obj);
	Sleep(500);

	wg_wait(&obj.wg);

	Sleep(1000);

	pthread_mutex_destroy(&obj.wg.mutex);
	sem_destroy(&obj.semaphore);
	pthread_cond_destroy(&obj.input_cond);

	return 0;
}
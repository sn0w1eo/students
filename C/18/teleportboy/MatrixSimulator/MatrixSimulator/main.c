#define _CRT_RAND_S

#include "include_libs.h"
#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"
#include "sound.h"

//Including music lib. Works only on windows.
#pragma comment(lib, "winmm")

int main() {

	//Full scrin
	maximize_window();

	//Set console encoding
	system("chcp 932 > nul");
	diplay_info();

	PlaySoundW(TEXT("1234.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	waveOutSetVolume(0, OFF);

	object obj;
	init_object(&obj);
	//Statrup input systems
	pthread_t input_thread1, input_thread2, output_threads, sound_thread;
	pthread_create(&input_thread1, NULL, keyboard_input, (void*)&obj);
	pthread_create(&input_thread2, NULL, input_handler, (void*)&obj);
	pthread_create(&sound_thread, NULL, change_sound_volume, (void*)&obj);
	wg_add(&obj.wg, 3);

	//Start displaying matrix strings
	int strings_count = 100;
	for (int i = 0; i < strings_count; i++) {
		pthread_create(&output_threads, NULL, string_to_console, (void*)&obj);
		wg_add(&obj.wg, 1);
	}

	//Wait until all child threads closn't
	wg_wait(&obj.wg);

	//Free used memory
	pthread_mutex_destroy(&obj.wg.mutex);
	sem_destroy(&obj.semaphore);

	return 0;
}
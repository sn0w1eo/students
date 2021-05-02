#define _CRT_RAND_S
#define SDL_MAIN_HANDLED

#include "include_libs.h"
#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"
#include "sound.h"
#include "linked_list_adt.h"
#include "mpg123.h"

//Including music lib. Works only on windows.
#pragma comment(lib, "winmm")

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_MP3);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	//Full scrin
	maximize_window();

	//Set console encoding
	system("chcp 932 > nul");	

	music_paths_to_txt("..\\MatrixSimulator\\music", "..\\MatrixSimulator\\music_paths.txt");
	diplay_info();

	object obj;
	init_object(&obj, "..\\MatrixSimulator\\music_paths.txt");

	//Music
	obj.music = play_sound("..\\MatrixSimulator\\music\\matrix.mp3", obj.music);

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
	Mix_FreeMusic(obj.music);
	Mix_CloseAudio();
	SDL_Quit();
	free_hashtable(obj.hash_table);
	return 0;
}
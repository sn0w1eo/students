#include "include_libs.h"
#include "waitgroup.h"
#include "console_io.h"
#include "hash_table.h"
#include "utility.h"
#include "sound.h"
#include "linked_list_adt.h"

void* change_sound_volume(void* args)
{
	object* obj = (object*)args;
	DWORD volumes[6] = { OFF, LOW, NORMAL, MEDIUM, HIGHT, VERY_HIGHT };

	int volume_level = 0;

	do
	{
		volume_level = obj->pressed_key - 48;
		if (volume_level >= 0 && volume_level <= 5) {
			waveOutSetVolume(0, volumes[volume_level]);
		}
		
	} while (obj->pressed_key != QUIT);

	wg_done(&obj->wg);
	
	return NULL;
}

Mix_Music* play_sound(char* sound_path, Mix_Music* music)
{
	if (Mix_PlayingMusic() > 0) {
		Mix_FadeOutMusic(1750);
		Mix_FreeMusic(music);
	}
	music = Mix_LoadMUS(sound_path);

	Mix_PlayMusic(music, -1);
	return music;
}
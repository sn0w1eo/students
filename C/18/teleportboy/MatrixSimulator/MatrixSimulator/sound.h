#ifndef SOUND_H

#define SOUND_H

#define OFF           0
#define LOW           858993459
#define NORMAL        1717986918
#define MEDIUM       -1717986919
#define HIGHT        -858993460
#define VERY_HIGHT   -1

#include "include_libs.h"

void* change_sound_volume(void* args);
Mix_Music* play_sound(char* sound_path, Mix_Music* music);
#endif // !SOUND_H

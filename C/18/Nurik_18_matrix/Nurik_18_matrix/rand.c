#include "rand.h"

int random(int min, int max) {
	unsigned int number;
	rand_s(&number);
	return (int)((float)number /
		((float)UINT_MAX + 1) * max) + min;
}

COORD rand_coordinate(int width, int height) {
	COORD rand_coord;
	rand_coord.X = random(ZERO, width);
	rand_coord.Y = random(ZERO, height);
	return rand_coord;
}


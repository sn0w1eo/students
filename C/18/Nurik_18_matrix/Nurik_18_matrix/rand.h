#ifndef RAND_H
#define RAND_H

#include "windows.h"
#include "object.h"

// rand numbers
int random(int min, int max);

// rand coordinates
COORD rand_coordinate(int width, int height);

#endif // !RAND_H

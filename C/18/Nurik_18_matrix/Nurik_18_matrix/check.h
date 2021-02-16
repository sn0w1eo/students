#ifndef CHECK_H
#define CHECK_H

#include "stdio.h"

// check next position coordinate
int check_next_position(int i, int y, int max_height);

// check result of functions
void ExitOnError(int rc, int lineNumber);

#endif // !CHECK_H


#ifndef WIN_API_H
#define WIN_API_H

#include "windows.h"
#include "stdbool.h"

// visible, invisible cursor
void show_cursor(bool show);
// get full monitor size - "consol" 
void get_size_monitor(int* width, int* height);

#endif // !WIN_API_H


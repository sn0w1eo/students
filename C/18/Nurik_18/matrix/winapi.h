#ifndef WINAPI_H
#define WINAPI_H

#include "stdbool.h"
#include "windows.h"
#include "list.h"
#include "object.h"

// increase the console
void maximize_window();

// get max size of height 
int get_height();

// get max size of width
int get_width();

// true/false 
void show_cursor(bool show);

// random value
int random(int min, int max);

// random coordinate
COORD rand_coordinate(int width, int height);

// set
void set_coord(int x, int y);
void set_bkcolor(int color, int x, int y);
void set_colors(int next_color, int prev_color, int x, node_t* list);
// Sleep();
void sleep_time(int threads);

#endif // !WINAPI_H

#ifndef UTILITY_H

#define UTILITY_H

#include "general.h"

void init_object(object* obj);
int is_close_signal(object* obj);
void send_signal(object* obj, int signal_code);
int random_number(int min_value, int max_value);
unsigned char random_char(int min_ascii, int max_ascii);
int get_console_width();
int get_console_height();

#endif // !UTILITY_H

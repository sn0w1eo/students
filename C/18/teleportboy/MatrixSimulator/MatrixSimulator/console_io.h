#ifndef CONSOLE_IO_H

#define CONSOLE_IO_H

void* string_to_console(void* args);
void* keyboard_input(void* args);
void* input_handler(void* args);

int print_char(unsigned char symbol, int coord_x, int coord_y);
int set_console_cursor(int x, int y);
int highlight_cursor(int foreground, int background, int coord_x, int coord_y, int* hash_table);
void set_console_color(int color, int x, int y);

#endif // !CONSOLE_IO

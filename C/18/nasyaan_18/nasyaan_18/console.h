#ifndef CONSOLE_H

#define CONSOLE_H
#include "libraries.h"

void SetPosition(int x, int y);
void SetBackground(int color);
void* WriteSymbols(void* arg);
void* KeyPress(void* arg);

#endif // !CONSOLE_H

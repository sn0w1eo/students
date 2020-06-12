#ifndef NEWFILE_H
#define NEWFILE_H

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void writingToFile(FILE*, const struct Database, void(*callback)(struct contact*));
int readingFile(FILE*, const struct Database, void(*callback)(struct contact*));


#endif // !NEWFILE_H

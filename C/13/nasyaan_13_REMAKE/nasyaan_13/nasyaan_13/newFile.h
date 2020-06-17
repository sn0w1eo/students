#ifndef NEWFILE_H
#define NEWFILE_H

#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void txtWritingToFile(FILE*, const struct Database, void(*callback)(struct Contact*));
void binWritingToFile(FILE*, const struct Database, void(*callback)(struct Contact*));
int readingTxtFile(FILE*, const struct Database, void(*callback)(struct Contact*));
int readingBinFile(FILE*, const struct Database, void(*callback)(struct Contact*));


#endif // !NEWFILE_H

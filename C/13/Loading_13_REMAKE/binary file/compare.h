#ifndef COMPARE_H
#define COMPARE_H

#include "stdio.h"
#include "stdlib.h"
#include "operations.h"

// ASC functions 
int compareNameASC(const void*, const void*);
int compareAgeASC(const void*, const void*);
int compareNumberASC(const void*, const void*);

// DESC functions
int compareNameDESC(const void*, const void*);
int compareAgeDESC(const void*, const void*);
int compareNumberDESC(const void*, const void*);

// Sorting by ASC
void sortByNameASC(contact*);
void sortByNumberASC(contact*);
void sortByAgeASC(contact*);

// Sorting by DESC
void sortByNameDESC(contact*);
void sortByNumberDESC(contact*);
void sortByAgeDESC(contact*);


#endif // !COMPARE_H


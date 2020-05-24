#ifndef BOOKS_H
#define BOOKS_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"


typedef unsigned char* string;

typedef struct name {
	string title; //название книги
	string author; //автор
}Name;

typedef struct dimensions {
	int volumes; //количество томов в книге
	int pages; //количество страниц в книге
}Dimensions;

typedef struct price {
	double dollars; //цена в долларах
	double soms; //цена в сомах
}Price;

typedef struct book {
	Name bookName; //название книги
	Dimensions bookDimensions; //величины
	Price bookPrice; //цена
} Book;

int titlecmpAsc(const void* a, const void* b);
int titlecmpDesc(const void* a, const void* b);
int pagescmpAsc(const void* a, const void* b);
int pagescmpDesc(const void* a, const void* b);
int dollarscmpAsc(const void* a, const void* b);
int somscmpDesc(const void* a, const void* b);

#endif // !BOOKS_H
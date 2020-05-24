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

void SetBookTitle(Book*, string const);
void SetBookAuthor(Book*, string const author);
void SetVolumes(Book* book, int volumes);
void SetPages(Book*, int);
void SetBookPriceInUsd(Book*, const double);
void SetBookPriceInKgs(Book*, const double);

string GetBookTitle(Book const);
string GetBookAuthor(Book const);
int GetBookVolumes(Book const);
int GetBookPages(Book const);
double GetBookPriceInUsd(Book const);
double GetBookPriceInKgs(Book const);

void SetBook(Book* const, const string, const string, int, int, const double, const double);

void PrintBooks(const Book*, int const);
void GetInt(int*, int, int);

int TitleCmpAsc(const void* a, const void* b);
int TitleCmpDesc(const void* a, const void* b);
int PagesCmpAsc(const void* a, const void* b);
int PagesCmpDesc(const void* a, const void* b);
int DollarsCmpAsc(const void* a, const void* b);
int SomsCmpDesc(const void* a, const void* b);

#endif // !BOOKS_H
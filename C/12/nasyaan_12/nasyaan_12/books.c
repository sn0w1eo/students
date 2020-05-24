#include "books.h"

//сеттеры

void SetBookTitle(Book* book, string const title) {
	book->bookName.title = _strdup(title);
}

void SetBookAuthor(Book* book, string const author) {
	book->bookName.author = _strdup(author);
}

void SetVolumes(Book* book, int volumes) {
	book->bookDimensions.volumes = volumes;
}

void SetPages(Book* book, int pages) {
	book->bookDimensions.pages = pages;
}
void SetBookPriceInUsd(Book* book, const double dollars) {
	book->bookPrice.dollars = dollars;
}

void SetBookPriceInKgs(Book* book, const double soms) {
	book->bookPrice.soms = soms;
}

// геттеры

string GetBookTitle(Book const book) {
	return book.bookName.title;
}

string GetBookAuthor(Book const book) {
	return book.bookName.author;
}

int GetBookVolumes(Book const book) {
	return book.bookDimensions.volumes;
}

int GetBookPages(Book const book) {
	return book.bookDimensions.pages;
}

double GetBookPriceInUsd(Book const book) {
	return book.bookPrice.dollars;
}

double GetBookPriceInKgs(Book const book) {
	return book.bookPrice.soms;
}

//сеттер для всей структуры Book
void SetBook(Book* const book, string const title, string const author, int volumes, int pages, double const dollars, double const soms) {
	SetBookTitle(book, title);
	SetBookAuthor(book, author);
	SetVolumes(book, volumes);
	SetPages(book, pages);
	SetBookPriceInUsd(book, dollars);
	SetBookPriceInKgs(book, soms);
}

//функция распечатки книг
void PrintBooks(const Book* books, int const booksAmount) {
	for (int i = 0; i < booksAmount; i++)
	{
		printf("\"%s\" - %s\n", GetBookTitle(books[i]), GetBookAuthor(books[i]));
		printf("Количество томов: %d. Количество страниц: %d\n", GetBookVolumes(books[i]), GetBookPages(books[i]));
		printf("Цена в долларах: %.2lf. Цена в сомах: %.2lf \n\n", GetBookPriceInUsd(books[i]), GetBookPriceInKgs(books[i]));
	}

}

//функция чтения клавиши 0-9
void getInt(int* x, int min, int max) {
	*x = 0;
	char ch = ' ';
	int skip, st = 0;
	int b = 0, i;
	do
	{
		st = i = skip = 0;
		for (; b = ((ch = getchar()) != '\n'); i++)
		{
			if (ch == EOF) return;
			if ((atoi(&ch)) == 0 && ch != '0') skip = 1;
			else if (b && !skip) { *x *= 10; *x += atoi(&ch); }
			if (*x < min || *x > max) skip = 1;
			if (skip) { *x = 0; st++; }
		}
		if (!b && !i) skip = 1;
	} while (skip || b);
}

//функции сортировки

int titlecmpAsc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return strcmp(pa->bookName.title, pb->bookName.title);
}

int titlecmpDesc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return strcmp(pb->bookName.title, pa->bookName.title);
}

int pagescmpAsc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return pa->bookDimensions.pages - pb->bookDimensions.pages;
}

int pagescmpDesc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return pb->bookDimensions.pages - pa->bookDimensions.pages;
}

int dollarscmpAsc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return pa->bookPrice.dollars - pb->bookPrice.dollars;
}

int somscmpDesc(const void* a, const void* b) {
	Book* pa = a;
	Book* pb = b;
	return pb->bookPrice.soms - pa->bookPrice.soms;
}
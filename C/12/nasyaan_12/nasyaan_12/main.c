#include "books.h"

#include "locale.h"

//программа выводит список книг с названиями, ценой и количеством страниц

int main() {

	setlocale(LC_ALL, "RU");
	int ch;
	int booksAmount = 6;
	Book* books = (Book*)calloc(booksAmount, sizeof(Book));
	printf("Здравствуй, дорогой друг! Ты находишься в магазине книг. В наличии у нас сегодня: \n\n");
	SetBook(&books[0], "Мастер и Маргарита", "М.А.Булгаков", 1, 310, 1.95, 144.2);
	SetBook(&books[1], "Граф Монте-Кристо", "А.Дюма", 2, 1350, 13.8, 1016.61);
	SetBook(&books[2], "Зулейха открывает глаза", "Г.Ш.Яхина", 1, 450, 6.02, 443.93);
	SetBook(&books[3], "Гарри Поттер", "Дж.Роулинг", 8, 3636, 51.8, 3817.18);
	SetBook(&books[4], "Властелин колец", "Дж.Р.Р.Толкин", 5, 2176, 13.83, 1018.67);
	SetBook(&books[5], "Песнь льда и пламени", "Дж.Р.Р.Мартин", 7, 4768, 67.69, 4985.7);

	PrintBooks(books, booksAmount);

	do 
	{
		
		printf("\nНажми цифру операции, которую ты хочешь выполнить, и ENTER\n");
		printf("\n0.Выход\n\n1.Сортировка по названию книги в алфавитном порядке\n");
		printf("\n2.Сортировка по названию книги в обратном порядке\n");
		printf("\n3.Сортировка по количеству страниц по возрастанию\n");
		printf("\n4.Сортировка по количеству страниц по убыванию\n");
		printf("\n5.Сортировка по цене в долларах по возрастанию\n");
		printf("\n6.Сортировка по цене в сомах по убыванию\n");

		GetInt(&ch, 0, 6);
		if (ch == 1) {
			printf("\nСортировка по названию книги в алфавитном порядке\n\n");
			qsort(books, booksAmount, sizeof(Book), TitleCmpAsc);
			PrintBooks(books, booksAmount);
		}
		else if (ch == 2) {
			printf("\nСортировка по названию книги в обратном порядке\n\n");
			qsort(books, booksAmount, sizeof(Book), TitleCmpDesc);
			PrintBooks(books, booksAmount);
		}
		else if (ch == 3) {
			printf("\nСортировка по количеству страниц по возрастанию\n");
			qsort(books, booksAmount, sizeof(Book), PagesCmpAsc);
			PrintBooks(books, booksAmount);
		}

		else if (ch == 4) {
			printf("\nСортировка по количеству страниц по убыванию\n\n");
			qsort(books, booksAmount, sizeof(Book), PagesCmpDesc);
			PrintBooks(books, booksAmount);
		}

		else if (ch == 5) {
			printf("\nСортировка по цене в долларах по возрастанию\n\n");
			qsort(books, booksAmount, sizeof(Book), DollarsCmpAsc);
			PrintBooks(books, booksAmount);
		}

		else if (ch == 6) {
			printf("\nСортировка по цене в самах по убыванию\n\n");
			qsort(books, booksAmount, sizeof(Book), SomsCmpDesc);
			PrintBooks(books, booksAmount);
		}
	}	while (ch);
	
	free(books);
	books = NULL;
	return 0;
}


#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "windows.h"
#include "pthread.h"
#include "string.h"
#include "stdlib.h"
#include "semaphore.h"

#define OPERATIONS_COUNT        4
#define THREADS_COUNT           4
#define OPERATION_COMPLETED     1
#define OPERATION_INCOMPLETED   0

#define ADDITION                0
#define SUBTRACTION             1
#define MULTIPLICATION          2
#define DIVISION                3

#define WHITE                   7
#define GREY                    8
#define GREEN                   10
#define BLUE                    11
#define RED                     12
#define YELLOW                  14

#define QUIT_COMMAND            "quit"

typedef struct Arguments
{ 
	double              first_number;
	double              second_number;

	unsigned int        pthreads_id[THREADS_COUNT];

	pthread_mutex_t     mutex;
	sem_t               semaphore;
	pthread_cond_t      main_thread_cond_var;
	pthread_cond_t      child_thread_cond_var;
	pthread_barrier_t   barrier;
}Arguments;

void* do_operation(void* arguments);
int read_numbers(double* first_number, double* second_number);
void set_console_cursor(int x, int y);
void set_console_color(int color);
void set_thread_color(unsigned int* threads_id, unsigned int thread_id);
void display_threads_info();

int main()
{
	Arguments arguments = { .first_number = 1, .second_number = 1, .pthreads_id = { 0 } };
	pthread_t pthreads[THREADS_COUNT];

	display_threads_info();
	
	pthread_mutex_init(&arguments.mutex, NULL);
	pthread_cond_init(&arguments.child_thread_cond_var, NULL);
	pthread_cond_init(&arguments.main_thread_cond_var, NULL);
	pthread_barrier_init(&arguments.barrier, NULL, THREADS_COUNT);
	sem_init(&arguments.semaphore, 0, 1);

	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_create(&pthreads[i], NULL, do_operation, (void*)&arguments);
		arguments.pthreads_id[i] = pthreads[i].p;
	}

	//Основной цикл
	while (read_numbers(&arguments.first_number, &arguments.second_number)) {
		//После ввода данных, отправить сигнал всем остальным тредам,
		//а после ждать сигнала от них.
		pthread_cond_broadcast(&arguments.child_thread_cond_var);
		pthread_cond_wait(&arguments.main_thread_cond_var, &arguments.mutex);
	}

	pthread_mutex_destroy(&arguments.mutex);
	pthread_cond_destroy(&arguments.child_thread_cond_var);
	pthread_cond_destroy(&arguments.main_thread_cond_var);
	pthread_barrier_destroy(&arguments.barrier);
	sem_destroy(&arguments.semaphore);
	pthread_barrier_destroy(&arguments.barrier);

	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_cancel(pthreads[i]);
	}

	return 0;
}

void* do_operation(void* arg)
{
	//Хранит результат арифмитической операции.
	double operation_result = 0;

	//Переменная логически принимает значения в диапазоне от -1 до 3,
	//где каждой цифре от 0 до 3 соответствует своя арифмитическая операция.
	static int current_operation_id = -1;

	//Счётчик выполненных операций.
	static int operations_done = 0;

	Arguments* arguments = (Arguments*)arg;
	
	while (1) {
		//Ожидание сигнала который поступит после ввода данных.
		pthread_cond_wait(&arguments->child_thread_cond_var, &arguments->mutex);

		//Критическая секция
		sem_wait(&arguments->semaphore);

		//Взависимости от ID текущего треда в критической секции поменять цвет.
		set_thread_color(arguments->pthreads_id, pthread_self().p);

		//При попадании в критическую секцию инкрементируем
		//и взависимости от её значения выполняем ариф. операцию.
		switch (++current_operation_id)
		{
		case ADDITION:
			operation_result = arguments->first_number + arguments->second_number;
			set_console_cursor(0, 1);
			printf("%.2lf + %.2lf = %.2lf          ",
				arguments->first_number, arguments->second_number, operation_result);
			break;

		case SUBTRACTION:
			operation_result = arguments->first_number - arguments->second_number;
			set_console_cursor(30, 1);
			printf("%.2lf - %.2lf = %.2lf          ",
				arguments->first_number, arguments->second_number, operation_result);
			break;

		case MULTIPLICATION:
			operation_result = arguments->first_number * arguments->second_number;
			set_console_cursor(60, 1);
			printf("%.2lf * %.2lf = %.2lf          ",
				arguments->first_number, arguments->second_number, operation_result);
			break;

		case DIVISION:
			operation_result = arguments->first_number / arguments->second_number;
			set_console_cursor(90, 1);
			printf("%.2lf / %.2lf = %.2lf          ",
				arguments->first_number, arguments->second_number, operation_result);
			//Т.к. операция деления выполняется последней по порядку,
			//то сброс значения этой переменной происходит именно здесь.
			current_operation_id = -1;
			break;
		}

		// ;DDD
		if (++operations_done % OPERATIONS_COUNT == 0) {
			set_console_color(WHITE);
			set_console_cursor(0, 3);
			printf("Total operations: %d", operations_done / OPERATIONS_COUNT);
		}

		sem_post(&arguments->semaphore);
		pthread_mutex_unlock(&arguments->mutex);

		//Ожидать выполнения всех 4-х дочерних тред,
		//а затем отправить сигнал главной треде
		pthread_barrier_wait(&arguments->barrier);
		pthread_cond_signal(&arguments->main_thread_cond_var);
	}

	return NULL;
}

void set_thread_color(unsigned int* threads_id, unsigned int thread_id)
{
	if (threads_id[0] == thread_id) {
		set_console_color(GREEN);
	} else if (threads_id[1] == thread_id) {
		set_console_color(BLUE);
	} else if (threads_id[2] == thread_id) {
		set_console_color(RED);
	} else {
		set_console_color(YELLOW);
	}
}

void display_threads_info()
{
	set_console_color(GREEN);
	set_console_cursor(90, 5);
	printf("Thread #1 - GREEN");
	set_console_color(BLUE);
	set_console_cursor(90, 6);
	printf("Thread #2 - BLUE");
	set_console_color(RED);
	set_console_cursor(90, 7);
	printf("Thread #3 - RED");
	set_console_color(YELLOW);
	set_console_cursor(90, 8);
	printf("Thread #4 - YELLOW");
}

int read_numbers(double* first_number, double* second_number)
{
	char first_num[10] = { 0 };
	char second_num[10] = { 0 };

	set_console_color(GREY);
	set_console_cursor(0, 5);
	printf("Enter first  number:          ");
	set_console_cursor(21, 5);
	scanf("%s", first_num);
	if (!strcmp(first_num, QUIT_COMMAND)) {
		return FALSE;
	}

	set_console_cursor(0, 6);
	printf("Enter second number:          ");
	set_console_cursor(21, 6);
	scanf("%s", second_num);
	if (!strcmp(second_num, QUIT_COMMAND)) {
		return FALSE;
	}

	*first_number = atof(first_num);
	*second_number = atof(second_num);
	return TRUE;
}

void set_console_cursor(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0 };
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(console, cursorPosition);
}

void set_console_color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
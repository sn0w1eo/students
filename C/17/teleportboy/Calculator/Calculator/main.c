#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "windows.h"
#include "pthread.h"
#include "string.h"
#include "stdlib.h"
#include "semaphore.h"

#define OPERATIONS_COUNT        4
#define THREADS_COUNT           4

#define NO_OPERATION           -1
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

typedef struct function_arguments
{
	double              first_number;
	double              second_number;
	unsigned int        pthreads_id[THREADS_COUNT];
}function_arguments;

typedef struct pthreads_objects
{
	pthread_mutex_t     main_thread_mutex;
	pthread_cond_t      main_thread_cond_var;
	sem_t               semaphore;
	pthread_barrier_t   all_threads_barrier;
	pthread_barrier_t   child_threads_barrier;
}pthreads_objects;

typedef struct function_variables
{
	function_arguments arguments;
	pthreads_objects   threads_objects;
}function_variables;

void* do_operation(void* arguments);
int read_numbers(double* first_number, double* second_number);
int generate_numbers(double* first_number, double* second_number, int lower_limit, int upper_limit, int count);

void set_console_cursor(int x, int y);
void set_console_color(int color);
void set_thread_color(unsigned int* threads_id, unsigned int thread_id);
void display_threads_info();

int main()
{
	srand(time(0));
	
	//Слагаемые для арифметических операций и элементы примитивов синхронизации.
	function_variables func_variables;
	function_arguments* func_arguments = &func_variables.arguments;
	pthreads_objects* thread_objects = &func_variables.threads_objects;
	
	pthread_t pthreads[THREADS_COUNT];

	pthread_mutex_init(&thread_objects->main_thread_mutex, NULL);
	pthread_cond_init(&thread_objects->main_thread_cond_var, NULL);
	sem_init(&thread_objects->semaphore, 0, 1);
	pthread_barrier_init(&thread_objects->all_threads_barrier, NULL, THREADS_COUNT + 1);
	pthread_barrier_init(&thread_objects->child_threads_barrier, NULL, THREADS_COUNT);

	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_create(&pthreads[i], NULL, do_operation, (void*)&func_variables);
		func_arguments->pthreads_id[i] = pthreads[i].p;
	}

	display_threads_info();

	//generate_numbers(&func_arguments->first_number, &func_arguments->second_number, 1, 100, 10000) - EMULATION
	//read_numbers(&arguments.first_number, &arguments.second_number) - NO_EMULATION

	while (generate_numbers(&func_arguments->first_number, &func_arguments->second_number, 1, 10, 10000)) {
		//Как только сюда попадает тред, это сигнализирует дочерним тредам в функции do_operation
		//что данные в слагаемых first_number и second_number обновлены и ими можно пользоваться.
		pthread_barrier_wait(&thread_objects->all_threads_barrier);
		
		//Затем эта треда засыпает до тех пор пока остальные треды не выполняет все ариф. операции.
		pthread_cond_wait(&thread_objects->main_thread_cond_var, &thread_objects->main_thread_mutex);
	}

	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_cancel(pthreads[i]);
	}

	//Освободить использованную память.
	pthread_mutex_destroy(&thread_objects->main_thread_mutex);
	pthread_cond_destroy(&thread_objects->main_thread_cond_var);
	pthread_barrier_destroy(&thread_objects->all_threads_barrier);
	pthread_barrier_destroy(&thread_objects->child_threads_barrier);
	sem_destroy(&thread_objects->semaphore);

	return 0;
}

void* do_operation(void* func_arguments)
{
	//Переменная логически принимает значения в диапазоне от -1 до 3,
	//где каждой цифре от 0 до 3 соответствует своя арифмитическая операция.
	static int current_operation_id = NO_OPERATION;

	//Счётчик выполненных операций.
	static int operations_done = 0;

	//Слагаемые для арифметических операций и элементы примитивов синхронизации.
	function_variables* func_variables = (function_variables*)func_arguments;
	function_arguments* arguments = &func_variables->arguments;
	pthreads_objects* thread_objects = &func_variables->threads_objects;

	while (1) {
		//Хранит результат арифмитической операции.
		double operation_result = 0;

		//Пройти через барьер можно только после очередных изменений значений
		//в переменых структуры function_arguments - first_number и second_number.
		pthread_barrier_wait(&thread_objects->all_threads_barrier);

		//Критическая секция.
		sem_wait(&thread_objects->semaphore);

		//Взависимости от ID текущего треда в критической секции поменять цвет.
		set_thread_color(arguments->pthreads_id, pthread_self().p);

		//При попадании в критическую секцию инкрементируем current_operation_id
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

		//Ко-во выполненных операций.
		if (++operations_done % OPERATIONS_COUNT == 0) {
			set_console_color(WHITE);
			set_console_cursor(0, 3);
			printf("Total operations: %d", operations_done / OPERATIONS_COUNT);
		}

		//Конец критической секции.
		sem_post(&thread_objects->semaphore);

		//Ожидать выполнения всех дочерних тред (функция do_operation),
		//а затем отправить сигнал главной треде (функция main).
		if (pthread_barrier_wait(&thread_objects->child_threads_barrier) == PTHREAD_BARRIER_SERIAL_THREAD) {
			pthread_cond_signal(&thread_objects->main_thread_cond_var);
		}
	}

	return NULL;
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

int generate_numbers(double* first_number, double* second_number, int lower_limit, int upper_limit, int count)
{
	static int counter = -1;

	*first_number = rand() % upper_limit + lower_limit;
	*second_number = rand() % upper_limit + lower_limit;

	set_console_color(GREY);
	set_console_cursor(0, 5);
	printf("Enter first  number: %.2lf        \n", *first_number);
	printf("Enter second  number: %.2lf        \n", *second_number);

	if (++counter == count) {
		return FALSE;
	}

	return TRUE;
}

void set_thread_color(unsigned int* threads_id, unsigned int thread_id)
{
	if (threads_id[0] == thread_id) {
		set_console_color(GREEN);
	}
	else if (threads_id[1] == thread_id) {
		set_console_color(BLUE);
	}
	else if (threads_id[2] == thread_id) {
		set_console_color(RED);
	}
	else {
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
#define _CRT_SECURE_NO_WARNINGS

#include "pthread.h"
#include "stdio.h"
#include "semaphore.h"
#include "windows.h"

// number of operations
#define SUM				0
#define	DIFFERENCE		1
#define	MULTIPLICATION  2
#define	DIVISION		3
// maximum of something 
#define MAX_THREADS		4
#define MAX_VALUES		11
#define MAX_COLORS		15
#define MAX_OF_RAND_NUM 10000
// time to start other threads
#define MAIN_SLEEP		100
// constant colors
#define WHITE			15
#define LIGHTMAGENTA	13
// exit
#define QUIT			-2

typedef struct {
	// handler 
	sem_t semaphore;
	pthread_cond_t cond;
	pthread_mutex_t lock;

	// values
	int first_num, second_num;

	// number of operations
	int count_operations;

	// implementation priority
	int num_of_operations;

	// number of color
	int color[MAX_THREADS];

	// exit process
	int quit;
}obj;

// color && coordinate
void setColor(int color);
void setCoordinate(int x, int y);

// operations (+, -, *, /)
void* operations(void* arg);

// two type of process
void writeNum(obj* Object);
void randNums(obj* Object);

int main() {
	// handler
	pthread_t thread[MAX_THREADS];
	// create struct
	obj Object = { .count_operations = -1,
				  .num_of_operations = 0,
				  .quit = 0 };
	// init 
	sem_init(&Object.semaphore, 0, 1);
	pthread_cond_init(&Object.cond, NULL);
	pthread_mutex_init(&Object.lock, NULL);

	// choose random numbers for colors 
	srand(time(NULL));
	for (int i = 0; i < MAX_THREADS; i++) {
		if (pthread_create(&thread[i], NULL, operations, (void*)&Object))
			printf("pthread_create failed");
		Object.color[i] = rand() % 15 + 1;
	}
	// main wait while threads working 
	// main will continue when threads finish the process  
	pthread_cond_wait(&Object.cond, &Object.lock);

	// destroy threads
	for (int i = 0; i < MAX_THREADS; i++)
		pthread_cancel(thread[i]);
	printf("All threads down\n");

	// destroy handlers
	sem_destroy(&Object.semaphore);
	pthread_cond_destroy(&Object.cond);
	pthread_mutex_destroy(&Object.lock);

	return 0;
}

void* operations(void* arg) {
	obj* Object = arg;
	while (1)
	{
		//  one thread can go futher 
		sem_wait(&Object->semaphore);
		switch (Object->num_of_operations)
		{
		case SUM:
			// set color[0]
			setColor(Object->color[SUM]);
			if (Object->quit == QUIT) {
				setCoordinate(0, 11);
				printf("Thread %p with color %d down\n", pthread_self().p, Object->color[SUM]);
			}
			else {
				setCoordinate(0, 0);
				printf("%d + %d = %d           ", Object->first_num, Object->second_num, Object->first_num + Object->second_num);
			}
			Object->num_of_operations++;
			break;
		case DIFFERENCE:
			// set color[1]
			setColor(Object->color[DIFFERENCE]);
			if (Object->quit == QUIT) {
				printf("Thread %p with color %d down\n", pthread_self().p, Object->color[DIFFERENCE]);
			}
			else {
				setCoordinate(25, 0);
				printf("%d - %d = %d           ", Object->first_num, Object->second_num, Object->first_num - Object->second_num);
			}
			Object->num_of_operations++;
			break;
		case MULTIPLICATION:
			// set color[2]
			setColor(Object->color[MULTIPLICATION]);
			if (Object->quit == QUIT) {
				printf("Thread %p with color %d down\n", pthread_self().p, Object->color[MULTIPLICATION]);
			}
			else {
				setCoordinate(50, 0);
				printf("%d * %d = %d           ", Object->first_num, Object->second_num, Object->first_num * Object->second_num);
			}
			Object->num_of_operations++;
			break;
		case DIVISION:
			// set color[3]
			setColor(Object->color[DIVISION]);
			if (Object->quit == QUIT) {
				printf("Thread %p with color %d down\n", pthread_self().p, Object->color[DIVISION]);
				pthread_cond_signal(&Object->cond);
				return NULL;
			}
			else {
				setCoordinate(75, 0);
				printf("%d / %d = %.2f        ", Object->first_num, Object->second_num, (float)Object->first_num / (float)Object->second_num);
			}
			Object->num_of_operations = 0;
			break;
		}
		if (Object->num_of_operations == 0) {
			// amount of operation
			setCoordinate(0, 3);
			setColor(WHITE);
			printf("Total operations: %d\n", ++(Object->count_operations));
 
			// 1. writeNum(Object); - here you write numbers and threads execute while your first value not equal "quit"
			writeNum(Object);
			// 2. randNums(Object); - here we have random numbers and threads execute while first value not equal 50
			// randNums(Object);
		}
		sem_post(&Object->semaphore);
	}
}

void writeNum(obj* Object) {
	char first_input[MAX_VALUES],
		second_input[MAX_VALUES];

	// set color && coordinate
	setColor(LIGHTMAGENTA);
	setCoordinate(0, 10);

	// write first arg
	printf("Enter first number: ");
	scanf("%s", first_input);
	printf("           ");

	// check first value
	if (strcmp(first_input, "quit") == 0) {
		Object->quit = QUIT;
	} else {
		// set coordinate
		setCoordinate(0, 11);
		// write second arg
		printf("Enter second number: ");
		scanf("%s", second_input);
		printf("           ");
		// converts string to integer
		Object->first_num = atoi(first_input);
		Object->second_num = atoi(second_input);
	}
}

void randNums(obj* Object) {
	// set color && coordinate
	setColor(LIGHTMAGENTA);
	setCoordinate(0, 10);
	// set random color
	Object->first_num = rand() % MAX_OF_RAND_NUM;
	Object->second_num = rand() % MAX_OF_RAND_NUM;
	// write numbers
	printf("Enter first number: %d   \n", Object->first_num);
	printf("Enter second number: %d   ", Object->second_num);
	// check first rand number
	if (Object->first_num == 50) {
		Object->quit = QUIT;
	}
}

// color && coodinate
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void setCoordinate(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
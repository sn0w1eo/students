#define _CRT_SECURE_NO_WARNINGS
#include "pthread.h"
#include "stdio.h"
#include "semaphore.h"
#include "stdbool.h"
#include "windows.h"
#include "string.h"


#define EXIT_CMD "exit"
#define EMULATION    true

#define EMULATION_COUNT 1000
//COLORS
#define DEFOLT_COLOR 0x0E
#define GREEN	     0x0A
#define RED		     0x04
#define CYAN		 0x0B
#define BLUE         0x03

#define THREADS_COUNT 4

#define ADDITION                1
#define SUBTRACTION             2
#define MULTIPLICATION          3
#define DIVISION                4



typedef struct {
	float fNumber;
	float sNumber;
	unsigned int threadID[THREADS_COUNT];
	unsigned int totalOperations;

	pthread_mutex_t mutex;
	pthread_barrier_t   barrier;
	sem_t			semaphore;
	pthread_cond_t  mThread_CV;
	pthread_cond_t  cThread_CV;
}Options;

enum operations
{
	summing = 1,
	subtraction,
	multiplication,
	division
};


_Bool readNumbers(float* first, float* second);
int emulationNumbers(float* first, float* second);

int performingOperations(void* options);

void setTextColor(int color_id);
void setCursor(int x, int y);
void set_thread_color(int* threads_id, int thread_id);

int main() {
	Options option = { .fNumber = 1, .sNumber = 1 , .threadID = 0, .totalOperations = 0};
	pthread_t threads[THREADS_COUNT];

	pthread_mutex_init(&option.mutex, NULL);
	pthread_cond_init(&option.mThread_CV, NULL);
	pthread_cond_init(&option.cThread_CV, NULL);
	pthread_barrier_init(&option.barrier, NULL, THREADS_COUNT);
	sem_init(&option.semaphore, 0, 1);
	
	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_create(&threads[i], NULL, performingOperations, (void*)&option);
		option.threadID[i] = threads[i].p;
	}
	
	
	
		
	if (!EMULATION) {
		while (readNumbers(&option.fNumber, &option.sNumber)) {

			pthread_cond_broadcast(&option.cThread_CV);
			pthread_cond_wait(&option.mThread_CV, &option.mutex);
		}
	}
	else {
		while (emulationNumbers(&option.fNumber, &option.sNumber,&option.totalOperations)) {

			pthread_cond_broadcast(&option.cThread_CV);
			pthread_cond_wait(&option.mThread_CV, &option.mutex);
		}
	}
	
	pthread_mutex_destroy(&option.mutex);
	pthread_cond_destroy(&option.cThread_CV);
	pthread_cond_destroy(&option.mThread_CV);
	pthread_barrier_destroy(&option.barrier);
	sem_destroy(&option.semaphore);
	pthread_barrier_destroy(&option.barrier);

	for (int i = 0; i < THREADS_COUNT; i++) {
		pthread_cancel(threads[i]);
	}

	return NULL;
	

}



_Bool readNumbers(float* first, float* second) {
	char firstNumber[8] = { 0 }; 
	char secondNumber[8] = { 0 };

	setTextColor(DEFOLT_COLOR);
	setCursor(0, 10);
	printf("Enter first number:");
	setCursor(20, 10);
	scanf("%s", firstNumber);
	if (!strcmp(firstNumber, EXIT_CMD)) {
		return false;
	}
	else { *first = atof(firstNumber); }
	setCursor(0, 11);
	printf("Enter second number:");
	setCursor(21, 11);
	scanf("%s", secondNumber);
	if (!strcmp(secondNumber, EXIT_CMD)) {
		return false;
	}
	else {
		*second = atof(secondNumber);
	}
	setCursor(0, 0);
	return true;
}

int emulationNumbers(float* first, float* second, int* total) {
	int firstNumber = 0, secondNumber = 0;
	
	
	if (*total<EMULATION_COUNT) {
		firstNumber = rand();
		secondNumber = rand();
		*first = firstNumber;
		*second = secondNumber;
		setTextColor(DEFOLT_COLOR);
		setCursor(0, 10);
		printf("Enter first number:");
		setCursor(20, 10);
		printf("%d", firstNumber);
		setCursor(0, 11);
		printf("Enter second number:");
		setCursor(21, 11);
		printf("%d", secondNumber);
	}
}


int performingOperations(void* options) {
	float result = 0.0;
	Options* option = (Options*)options;
	static int totalOperations = 0;
	static int rc = 0;
	
	while (true)
	{
		
		pthread_cond_wait(&option->cThread_CV, &option->mutex);
		sem_wait(&option->semaphore);
		set_thread_color(option->threadID, pthread_self().p);
		switch (++rc)
		{
		case ADDITION:
			result = option->fNumber + option->sNumber;
			setCursor(0, 1);
			printf("%.2lf + %.2lf = %.2lf       ",option->fNumber, option->sNumber, result);
			break;

		case SUBTRACTION:
			result = option->fNumber - option->sNumber;
			setCursor(30, 1);
			printf("%.2lf - %.2lf = %.2lf       ", option->fNumber, option->sNumber, result);
			
			break;

		case MULTIPLICATION:
			result = option->fNumber * option->sNumber;
			setCursor(60, 1);
			printf("%.2lf * %.2lf = %.2lf       ", option->fNumber, option->sNumber, result);
			break;

		case DIVISION:
			result = option->fNumber / option->sNumber;
			setCursor(90, 1);
			printf("%.2lf / %.2lf = %.2lf       ", option->fNumber, option->sNumber, result);
			rc = 0;
			break;
		}
		if (++totalOperations % 4 == 0) {
			setTextColor(DEFOLT_COLOR);
			setCursor(0, 3);
			printf("Total operations: %d", totalOperations / 4);
			option->totalOperations = totalOperations / 4;
		}
		sem_post(&option->semaphore);
		pthread_mutex_unlock(&option->mutex);
		pthread_barrier_wait(&option->barrier);
		pthread_cond_signal(&option->mThread_CV);
	}
}


void setTextColor(int color_id) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_id);
}

void setCursor(int x, int y)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorPosition = { 0 };
	cursorPosition.X = x;
	cursorPosition.Y = y;
	SetConsoleCursorPosition(console, cursorPosition);
}

void set_thread_color( int* threads_id,  int thread_id)
{
	if (threads_id[0] == thread_id) {
		setTextColor(GREEN);
	}
	else if (threads_id[1] == thread_id) {
		setTextColor(BLUE);
	}
	else if (threads_id[2] == thread_id) {
		setTextColor(RED);
	}
	else {
		setTextColor(CYAN);
	}
}
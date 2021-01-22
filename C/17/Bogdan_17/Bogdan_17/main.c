
#include "stdio.h"
#include "pthread.h"
#include "windows.h"
#include "time.h"


#define EMULATION

#define TOTAL_OPERATIONS 4
#define ADDITION 1
#define SUBTRACTION 2
#define MULTIPLICATION 3
#define DIVISION 4

//цвета
#define GREY 8
#define LIGHT_GREEN 10
#define LIGHT_BLUE 11
#define LIGHT_RED 12
#define LIGHT_YELLOW 13
#define LIGHT_WHITE 15




//функция выбора цвета
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//функция выбора позиции в консоли
void position(int x, int y) {
	COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}

typedef struct {
	int firstDigit;
	int secondDigit;

	int performedOperations;	//для уже выполненных операций в функции operations()
	int totalOperations;		//для общего кол-ва операций 

	char inputFlag;				//разрешает ввод данных

	int trheadStart;			//для проверки запуска всех тредов
	
	pthread_mutex_t lock;		//мютекс для крит. зоны
	pthread_mutex_t sleep;		//мютекс для cond variable

	pthread_cond_t condition;	// cond variable для передачи управления другим тредам
}object;

void* operations(void* arg) {	

	//инциализирум переменные
	object* obj = (object*)arg;
	int additionResult = 0;
	int subtractionResult = 0;
	int multiplicationResult = 0; 
	float divisionResult = 0;

	pthread_mutex_lock(&obj->sleep);
	obj->trheadStart++;
	while (1) {
		//треды засыпают и ждут данных
		pthread_cond_wait(&obj->condition, &obj->sleep);

		//начало критической зоны
		pthread_mutex_lock(&obj->lock);
		if (obj->performedOperations < TOTAL_OPERATIONS){	//смотрит каки операции выполнены
			obj->performedOperations++;
		}
		else {
			obj->performedOperations = 1;
		}
		//конец крит. зоны
		pthread_mutex_unlock(&obj->lock);

		//выполняет операции
		switch (obj->performedOperations)
		{
		case ADDITION:
			additionResult = (int)obj->firstDigit + (int)obj->secondDigit;
			position(0, 4);
			color(LIGHT_BLUE);
			printf("%d + %d = %d       \n", obj->firstDigit, obj->secondDigit, additionResult);		//пробелы для удобства и красоты)))
			break;

		case SUBTRACTION:
			subtractionResult = (int)obj->firstDigit - (int)obj->secondDigit;
			position(0, 5);
			color(LIGHT_WHITE);
			printf("%d - %d = %d        \n", obj->firstDigit, obj->secondDigit, subtractionResult);
			break;

		case MULTIPLICATION:
			multiplicationResult = (int)obj->firstDigit * (int)obj->secondDigit;
			position(0, 6);
			color(LIGHT_YELLOW);
			printf("%d * %d = %d         \n", obj->firstDigit, obj->secondDigit, multiplicationResult);
			break;

		case DIVISION:
			divisionResult = (float)obj->firstDigit / (float)obj->secondDigit;
			position(0, 7);
			color(LIGHT_GREEN);
			printf("%d / %d = %.3f        \n", obj->firstDigit, obj->secondDigit, divisionResult);

			position(0, 9);
			color(LIGHT_RED);
			obj->totalOperations++;
			printf("TOTAL OPERATIONS: %d", obj->totalOperations);		
			break;
		}

		//проверяет все ли действия завершены и разрешает ввод данных
		if (obj->performedOperations == TOTAL_OPERATIONS && obj->inputFlag == 0) {
			obj->inputFlag = 1;
		}
	}
}

int main() {

	//инициализируем треды
	pthread_t  threads[TOTAL_OPERATIONS];

	//инициализируем созданную структуру
	object obj = { .performedOperations = 0 ,
					.totalOperations = 0 ,
					.inputFlag = 1 ,
					.trheadStart = 0 };

	//инициализируем мютексы
	if (pthread_mutex_init(&obj.lock, NULL) != 0) {
		printf("Mutex init failed");
		return -1;
	};
	if (pthread_mutex_init(&obj.sleep, NULL) != 0) {
		printf("Mutex init failed");
		return -1;
	};
	if (pthread_cond_init(&obj.condition, NULL) != 0) {
		printf("Condition variable init failed");
		return -1;
	}

	//создаем треды 
	for (int i = 0; i < TOTAL_OPERATIONS; i++) {
		pthread_create(&threads[i], NULL, operations, (void*)&obj);	//передаем адрес структуры
	}

	//привветствие
	color(GREY);
	printf("Hello user! To exit the program, enter (0) in the SECOND digit.");

	//ввод данных
#ifdef EMULATION
	srand(time(NULL));
	while (1) {
		if (obj.inputFlag == 1) {					//проверка на разрешения ввода
			obj.firstDigit = rand() % 10000;
			obj.secondDigit = rand() % 10000;

			position(0, 1);
			color(LIGHT_GREEN);
			printf("FIRST digit: %d", obj.firstDigit);
						
			position(0, 2);
			printf("SECOND digit: %d", obj.secondDigit);
					
			if (obj.secondDigit == 0) {				//проверка на завершение программы
				break;
			}
			obj.inputFlag = 0;						//завершение ввода
			

			//пожалуй костыль и не лучшее решение....
			while (1)
			{	//если все треды запущены то посылаем сигнал
				if (obj.trheadStart == TOTAL_OPERATIONS) {
					pthread_cond_broadcast(&obj.condition);	//посылает сигнал всем спящим тредам
					break;
				}
				
			}
		}
	}
#else // !EMULATION
	while (1) {
		if (obj.inputFlag == 1) {					//проверка на разрешения ввода
			position(0, 1);
			color(LIGHT_GREEN);
			printf("enter the FIRST digit: ");
			scanf_s("%d", &obj.firstDigit);			//ввод первого числа
			position(0, 2);
			printf("enter the SECOND digit: ");
			scanf_s("%d", &obj.secondDigit);		//ввод второго числа
			if (obj.secondDigit == 0) {				//проверка на завершение программы
				break;
			}
			obj.inputFlag = 0;						//завершение ввода


			while (1)
			{//если все треды запущены посылаем сигнал
				if (obj.trheadStart == TOTAL_OPERATIONS) {
					pthread_cond_broadcast(&obj.condition);	//посылает сигнал всем спящим тредам
					break;
				}
			}
		}
	}
#endif

		//закрываем мютексы и cond
		pthread_mutexattr_destroy(&obj.lock);
		pthread_mutexattr_destroy(&obj.sleep);
		pthread_cond_destroy(&obj.condition);

		//закрываем треды
		for (int i = 0; i < TOTAL_OPERATIONS; i++) {
			pthread_cancel(threads[i]);
		}
		position(0, 10);
		return 0;
}

	

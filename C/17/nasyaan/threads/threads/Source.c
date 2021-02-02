#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "windows.h"
#include "pthread.h"
#include "string.h"
#include "stdlib.h"
#include "semaphore.h"

#define MAX_THREAD 4
#define RED				0x0C //красный
#define WHITE			0x07 //белый
#define LIGHTBLUE		0x0B //светло-голубой
#define YELLOW			0x06 //жёлтый
#define LIGHTMAGENTA	0x0D //светло-лиловый


typedef struct {
	sem_t semaphore;
	pthread_cond_t cond, cond1;
	pthread_mutex_t mutex, mutex1;
	int flag, first_num, second_num, total_num, exit;
} Obj;

void Position(int x, int y) {
	COORD coordinate = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//функция, присваивающая рандомные значения для firest num и second num
void RandNum(Obj* object)
{
	object->first_num = rand() % 1000;
	object->second_num = rand() % 1000;
	Color(WHITE);
	Position(0, 10);
	printf("First num: %d\n", object->first_num);
	//при условии first num = 50 выход из функции
	if (object->first_num == 50)
	{
		object->exit = 1;
		return;
	}
	printf("Second num: %d", object->second_num);

}

//функция вычисления
void* Calculate(void* arg) {
	Obj* object = arg;
	while (1)
	{
		pthread_cond_wait(&object->cond, &object->mutex); //треды ждут
		sem_wait(&object->semaphore); //запускаем по 1
		switch (object->flag)
		{	
		case 0: 
			Color(RED);
			if (object->exit == 1)
			{
				printf("%p: Exit with color %d \n", pthread_self().p, RED);
				object->flag++;
			}
			else
			{
				Position(0, 0);
				printf("%d + %d = %d           ", object->first_num, object->second_num, object->first_num + object->second_num);
				object->flag++;
			}
			
			break;
		case 1: 
			Color(LIGHTBLUE);
			if (object->exit == 1)
			{
				printf("%p: Exit with color %d \n", pthread_self().p, LIGHTBLUE);
				object->flag++;
			}
			else
			{
				Position(25, 0);
				printf("%d - %d = %d           ", object->first_num, object->second_num, object->first_num - object->second_num);
				object->flag++;
			}
			break;
		case 2: 
			Color(YELLOW);
			if (object->exit == 1)
			{
				printf("%p: Exit with color %d \n", pthread_self().p, YELLOW);
				object->flag++;
			}

			else
			{
				Position(50, 0);
				printf("%d * %d = %d           ", object->first_num, object->second_num, object->first_num * object->second_num);
				object->flag++;
			}
			break;
		case 3: 
			Color(LIGHTMAGENTA);
			if (object->exit == 1)
			{
				printf("%p: Exit with color %d \n", pthread_self().p, LIGHTMAGENTA);
				
			}
			else
			{
				Position(75, 0);
				printf("%d / %d = %.2f           ", object->first_num, object->second_num, (float)object->first_num / (float)object->second_num);
				object->flag = 0;
				
			}
			
			break;
		}
	
		sem_post(&object->semaphore);

		//отправляем сигнал в main
		if (object->flag == 0)
		{
			Position(0, 5);
			object->total_num++;
			Color(WHITE);
			printf("Total Operations: %d", object->total_num);
			pthread_cond_signal(&object->cond1);
		}
	}

}

//функция записи значений
void WriteValue(Obj* object) {
	char first_value[15] = { 0 }, second_value[15] = {0};
	Color(WHITE);
	Position(0, 10);
	printf("First num: ");
	scanf("%s", first_value);
	if (strcmp(first_value, "quit")==0)
	{	
		object->exit = 1;
		return NULL;
	}
	object->first_num = atoi(first_value);
	printf("Second num: ");
	scanf("%s", second_value);
	object->second_num = atoi(second_value);
}


int main() {
	Obj object = {.flag = 0, .exit = 0, .first_num = 1, .second_num = 1};
	pthread_t thread[MAX_THREAD]; //создаём массив тредов
	//инициализируем semaphore, cond, mutex
	sem_init(&object.semaphore, 0, 1);
	pthread_cond_init(&object.cond, NULL);
	pthread_cond_init(&object.cond1, NULL);
	pthread_mutex_init(&object.mutex, NULL);
	pthread_mutex_init(&object.mutex1, NULL);
	srand(time(0));
	//запускаем цикл создания тредов
	for (int i = 0; i < MAX_THREAD;	i++)
		pthread_create(&thread[i], NULL, Calculate, &object);
	Sleep(500); 
	while (1)
	{
		RandNum(&object); //вызываем функцию RandNum
		Sleep(1);
		/*WriteValue(&object);*/
		pthread_cond_broadcast(&object.cond); //будим наши треды 
		pthread_cond_wait(&object.cond1, &object.mutex1); //main ждёт 
		if (object.exit == 1)
			break;
	}
	for (int i = 0; i < MAX_THREAD; i++)
		pthread_cancel(thread[i]);
	sem_destroy(&object.semaphore);
	pthread_cond_destroy(&object.cond);
	pthread_cond_destroy(&object.cond1);
	pthread_mutex_destroy(&object.mutex);
	pthread_mutex_destroy(&object.mutex1);
	return 0;
}
#ifndef WAITGROUP_H
#define WAITGROUP_H

#include "pthread.h"

typedef struct {
	pthread_mutex_t mu;
	int counter;
} WaitGroup;

// возвращает инициализированную структуру
WaitGroup CreateWG();

// добавляет к счётчику количество (amount)
void WG_Add(WaitGroup* wg, int amount);

// уменьшает счётчик на 1
void WG_Done(WaitGroup* wg);

// возвращает 1 если счётчик равен 0. 
// в противном случае возвращает 0
int WG_IsEmpty(WaitGroup* wg);

#endif // WAITGROUP_H
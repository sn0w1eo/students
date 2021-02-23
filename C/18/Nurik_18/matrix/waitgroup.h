#ifndef WAITGROUP_H
#define WAITGROUP_H

#include "pthread.h"

typedef struct {
	pthread_mutex_t mu;
	int counter;
} wait_group;

// возвращает инициализированную структуру
wait_group сreate_wg();

// добавляет к счётчику количество (amount)
void wg_add(wait_group* wg, int amount);

// уменьшает счётчик на 1
void wg_done(wait_group* wg);

// ждет всех тредов
void wg_wait(wait_group* wg);

// возвращает 1 если счётчик равен 0. 
// в противном случае возвращает 0
int wg_is_empty(wait_group* wg);

#endif // WAITGROUP_H
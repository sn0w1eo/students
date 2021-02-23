#ifndef WAITGROUP_H
#define WAITGROUP_H

#include "pthread.h"

typedef struct {
	pthread_mutex_t mu;
	int counter;
} wait_group;

// ���������� ������������������ ���������
wait_group �reate_wg();

// ��������� � �������� ���������� (amount)
void wg_add(wait_group* wg, int amount);

// ��������� ������� �� 1
void wg_done(wait_group* wg);

// ���� ���� ������
void wg_wait(wait_group* wg);

// ���������� 1 ���� ������� ����� 0. 
// � ��������� ������ ���������� 0
int wg_is_empty(wait_group* wg);

#endif // WAITGROUP_H
#ifndef WAITGROUP_H
#define WAITGROUP_H

#include "pthread.h"

typedef struct {
	pthread_mutex_t mu;
	int counter;
} WaitGroup;

// ���������� ������������������ ���������
WaitGroup CreateWG();

// ��������� � �������� ���������� (amount)
void WG_Add(WaitGroup* wg, int amount);

// ��������� ������� �� 1
void WG_Done(WaitGroup* wg);

// ���������� 1 ���� ������� ����� 0. 
// � ��������� ������ ���������� 0
int WG_IsEmpty(WaitGroup* wg);

#endif // WAITGROUP_H
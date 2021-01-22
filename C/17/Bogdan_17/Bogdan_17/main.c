
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

//�����
#define GREY 8
#define LIGHT_GREEN 10
#define LIGHT_BLUE 11
#define LIGHT_RED 12
#define LIGHT_YELLOW 13
#define LIGHT_WHITE 15




//������� ������ �����
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//������� ������ ������� � �������
void position(int x, int y) {
	COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}

typedef struct {
	int firstDigit;
	int secondDigit;

	int performedOperations;	//��� ��� ����������� �������� � ������� operations()
	int totalOperations;		//��� ������ ���-�� �������� 

	char inputFlag;				//��������� ���� ������

	int trheadStart;			//��� �������� ������� ���� ������
	
	pthread_mutex_t lock;		//������ ��� ����. ����
	pthread_mutex_t sleep;		//������ ��� cond variable

	pthread_cond_t condition;	// cond variable ��� �������� ���������� ������ ������
}object;

void* operations(void* arg) {	

	//������������ ����������
	object* obj = (object*)arg;
	int additionResult = 0;
	int subtractionResult = 0;
	int multiplicationResult = 0; 
	float divisionResult = 0;

	pthread_mutex_lock(&obj->sleep);
	obj->trheadStart++;
	while (1) {
		//����� �������� � ���� ������
		pthread_cond_wait(&obj->condition, &obj->sleep);

		//������ ����������� ����
		pthread_mutex_lock(&obj->lock);
		if (obj->performedOperations < TOTAL_OPERATIONS){	//������� ���� �������� ���������
			obj->performedOperations++;
		}
		else {
			obj->performedOperations = 1;
		}
		//����� ����. ����
		pthread_mutex_unlock(&obj->lock);

		//��������� ��������
		switch (obj->performedOperations)
		{
		case ADDITION:
			additionResult = (int)obj->firstDigit + (int)obj->secondDigit;
			position(0, 4);
			color(LIGHT_BLUE);
			printf("%d + %d = %d       \n", obj->firstDigit, obj->secondDigit, additionResult);		//������� ��� �������� � �������)))
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

		//��������� ��� �� �������� ��������� � ��������� ���� ������
		if (obj->performedOperations == TOTAL_OPERATIONS && obj->inputFlag == 0) {
			obj->inputFlag = 1;
		}
	}
}

int main() {

	//�������������� �����
	pthread_t  threads[TOTAL_OPERATIONS];

	//�������������� ��������� ���������
	object obj = { .performedOperations = 0 ,
					.totalOperations = 0 ,
					.inputFlag = 1 ,
					.trheadStart = 0 };

	//�������������� �������
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

	//������� ����� 
	for (int i = 0; i < TOTAL_OPERATIONS; i++) {
		pthread_create(&threads[i], NULL, operations, (void*)&obj);	//�������� ����� ���������
	}

	//������������
	color(GREY);
	printf("Hello user! To exit the program, enter (0) in the SECOND digit.");

	//���� ������
#ifdef EMULATION
	srand(time(NULL));
	while (1) {
		if (obj.inputFlag == 1) {					//�������� �� ���������� �����
			obj.firstDigit = rand() % 10000;
			obj.secondDigit = rand() % 10000;

			position(0, 1);
			color(LIGHT_GREEN);
			printf("FIRST digit: %d", obj.firstDigit);
						
			position(0, 2);
			printf("SECOND digit: %d", obj.secondDigit);
					
			if (obj.secondDigit == 0) {				//�������� �� ���������� ���������
				break;
			}
			obj.inputFlag = 0;						//���������� �����
			

			//������� ������� � �� ������ �������....
			while (1)
			{	//���� ��� ����� �������� �� �������� ������
				if (obj.trheadStart == TOTAL_OPERATIONS) {
					pthread_cond_broadcast(&obj.condition);	//�������� ������ ���� ������ ������
					break;
				}
				
			}
		}
	}
#else // !EMULATION
	while (1) {
		if (obj.inputFlag == 1) {					//�������� �� ���������� �����
			position(0, 1);
			color(LIGHT_GREEN);
			printf("enter the FIRST digit: ");
			scanf_s("%d", &obj.firstDigit);			//���� ������� �����
			position(0, 2);
			printf("enter the SECOND digit: ");
			scanf_s("%d", &obj.secondDigit);		//���� ������� �����
			if (obj.secondDigit == 0) {				//�������� �� ���������� ���������
				break;
			}
			obj.inputFlag = 0;						//���������� �����


			while (1)
			{//���� ��� ����� �������� �������� ������
				if (obj.trheadStart == TOTAL_OPERATIONS) {
					pthread_cond_broadcast(&obj.condition);	//�������� ������ ���� ������ ������
					break;
				}
			}
		}
	}
#endif

		//��������� ������� � cond
		pthread_mutexattr_destroy(&obj.lock);
		pthread_mutexattr_destroy(&obj.sleep);
		pthread_cond_destroy(&obj.condition);

		//��������� �����
		for (int i = 0; i < TOTAL_OPERATIONS; i++) {
			pthread_cancel(threads[i]);
		}
		position(0, 10);
		return 0;
}

	

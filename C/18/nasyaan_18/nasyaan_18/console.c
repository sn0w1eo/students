#include "libraries.h"
#include "header.h"

void SetPosition(int x, int y) {
	COORD coordinate = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}

void SetBackground(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((color << 4) | GREEN));
}

//������ ��������
void* WriteSymbols(void* arg) {
	int x, y, stringLength, consoleWidth, consoleHeight;
	char symbol;
	Object* obj = (Object*)arg;
	WgAdd(&obj->wg, 1);
	consoleWidth = GetConsoleWidth();
	consoleHeight = GetConsoleHeight();

	while (UseFlag(obj))
	{
		x = RandomNumber(0, consoleWidth);
		y = RandomNumber(0, consoleHeight);
		stringLength = RandomNumber(0, consoleHeight);
		for (int i = 0; i < stringLength; i++)
		{
			sem_wait(&obj->semaphore);
			SetPosition(x, y);
			SetBackground(WHITE);
			symbol = RandomNumber(33, 126);
			printf("%c", symbol);
			/*Sleep(7);*///��� ������� ����� ����������������
					 //(��������� ��� ���������� �������� ��������� ��������)
			SetPosition(x, y);
			SetBackground(BLACK); //������� ������ �� ������ ����
			printf("%c", symbol);
			sem_post(&obj->semaphore);
			y++;
			if (y > consoleHeight)
			{
				y = 0;
			}

		}
		x = RandomNumber(0, consoleWidth);
		y = RandomNumber(0, consoleHeight);
		stringLength = RandomNumber(0, consoleHeight);
		for (int i = 0; i < stringLength; i++)
		{
			sem_wait(&obj->semaphore);
			SetPosition(x, y);
			printf("%c", 32); //32 ��� ������
			sem_post(&obj->semaphore);
			y++;
			if (y > consoleHeight)
			{
				y = 0;
			}
		}

	}
	WgDone(&obj->wg);
}

//������� �������
void* KeyPress(void* arg) {
	Object* obj = (Object*)arg;
	pthread_t thread;
	WgAdd(&obj->wg, 1); //�������� � ������� ������ 1
	while (1)
	{
		obj->key = getch();
		if (obj->key == '+')
		{
			SetFlag(obj, THREAD_WORKS);
			pthread_create(&thread, NULL, WriteSymbols, (void*)obj);
			//��������� ����
		}
		if (obj->key == '-')
		{
			SetFlag(obj, CLOSE_THREAD);
			//��������� 1 ����
		}
		if (obj->key == 'q')
		{
			SetFlag(obj, QUIT);
			WgDone(&obj->wg);
			return NULL;
			//������� ���������
		}
	}

}



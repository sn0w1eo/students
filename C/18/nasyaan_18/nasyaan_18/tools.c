#include "tools.h"

int RandomNumber(int minValue, int maxValue)
{
	unsigned int number = 1;
	rand_s(&number);
	number = (unsigned int)(maxValue - minValue + 1) * ((double)number / ((double)UINT_MAX + 1)) + minValue;
	return number;
}

//получение ширины экрана
int GetConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Right;
}

//получение высоты экрана
int GetConsoleHeight()
{
	CONSOLE_SCREEN_BUFFER_INFOEX info;
	info.cbSize = sizeof(info);

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	GetConsoleScreenBufferInfoEx(console, &info);

	return info.srWindow.Bottom;
}

//установка флага для тредов
void SetFlag(Object* obj, int value) {
	sem_wait(&obj->semaphore);
	obj->flag = value;
	sem_post(&obj->semaphore);
}

//обработка полученного значения флага
int UseFlag(Object* obj) {
	sem_wait(&obj->semaphore);
	if (obj->flag == CLOSE_THREAD)
	{
		obj->flag = THREAD_WORKS;
		sem_post(&obj->semaphore);
		return 0;
	}
	else if (obj->flag == QUIT)
	{
		sem_post(&obj->semaphore);
		return 0;
	}
	else
	{
		sem_post(&obj->semaphore);
		return 1;
	}
}
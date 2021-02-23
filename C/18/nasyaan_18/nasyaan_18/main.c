#define _CRT_SECURE_NO_WARNINGS

#include "libraries.h"

int main() {
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED); //раскрыть окно
	Object obj;
	obj.flag = THREAD_WORKS;	
	obj.wg = WgInit();
	sem_init(&obj.semaphore, 0, 1);
	pthread_t thread;
	pthread_create(&thread, NULL, KeyPress, (void*)&obj);
	Sleep(100);
	WgWait(&obj.wg);
	return 0;
}
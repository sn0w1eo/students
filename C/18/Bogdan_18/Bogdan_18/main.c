



#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "tchar.h"
#include "stdio.h"
#include "pthread.h"
#include "semaphore.h"


#define NUMBER_OF_THREADS 0 //количество запускаемых тредов в начале
#define WRITE 1             //флаг для пробелов или символов

#define CLOSE_THREAD 1      //флаг на закрытие одного треда
#define EXIT 2              //флаг выхода из программы



typedef struct {
    pthread_mutex_t mu;
    int counter;
} WaitGroup;

typedef struct {
    int widht;
    int height;

    //флаг выхода
    char exitFlag;

    WaitGroup wg;

    //бинарный семафор для тредов
    sem_t sem;
   
    //бинарный семафор для проверки выхода
    sem_t exit;

}OperationObj;




//функция для тредов
void* matrix(void* obj);

//реагирует на нажатие кнопки. Отвечает главный тред (main)
int pressButton(OperationObj* obj);

//разворачивает окно и получает ширину и высоту окна
int maximizeWindowAndGetSize(OperationObj* obj);

WaitGroup CreateWG();
void WG_Add(WaitGroup* wg, int amount);
int WG_IsEmpty(WaitGroup* wg);
void WG_Done(WaitGroup* wg);

void setPosition(int x, int y);
void setColor(int ColorNumber);

//функция скрытия коретки курсора
void showCursor(char show);








int main()
{
    //инициализация
    OperationObj obj = {
        .height = 0,
        .widht = 0,
        .exitFlag = 0,

        .wg = CreateWG(),
        
    };
    sem_init(&obj.sem, 0, 1);
    sem_init(&obj.exit, 0, 1);


    maximizeWindowAndGetSize(&obj);
   
    //Запускает начальное кол-во тредов
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        // добавляем 1 треду к waitgroup
        WG_Add(&obj.wg, 1);
        pthread_t thread;
        pthread_create(&thread, NULL, matrix, &obj);
    }

    //для главного потока. Реагирует на нажатие кнопки
    pressButton(&obj);

    return 0;
}

//функция для тредов
void* matrix(void* obj) {
    srand(pthread_self().p);
    OperationObj* Obj = (OperationObj*)obj;


    while (1) {

        //начало крит зоны
        sem_wait(&Obj->exit);

        //проверка закрытие треда
        if (Obj->exitFlag == CLOSE_THREAD) {

            //возврат флага
            Obj->exitFlag = 0;

            //разблокируем смафор
            sem_post(&Obj->exit);

            //завершение треда
            return NULL;

        }
        // конец крит зоны
        sem_post(&Obj->exit);

        //проверка на закрытие программы
        if (Obj->exitFlag == EXIT) {
            WG_Done(&Obj->wg);
            return NULL;
        }

        //инициализация рандомных переменных
        int lineLength = rand() % 100;
        int x = rand() % Obj->widht;
        int y = rand() % Obj->height;
        char writeORdelete = rand() % 2;
        char letter;

        //до тех пор пока не закончится строка
        for (int i = 0; i < lineLength; i++) {

            //проверка на границы окна
            if (y > Obj->height) {
                x++;
                y = 0;
            }
            if (x > Obj->widht) {
                x = 0;
            }

            //если флаг стоит на печати
            if (writeORdelete == WRITE) {

                //начало крит зоны
                sem_wait(&Obj->sem);

                //печатает на белом фоне букву
                //генерируем случайное число
                letter = rand() % (64 - 33) + 33;
                //выбираем позицию
                setPosition(x, y);
                //выбираем цвет
                setColor(0x7A);
                printf("%c", letter);

                //конец крит зоны
                sem_post(&Obj->sem);

                //меняет фон
                //начало крит зоны
                sem_wait(&Obj->sem);
                setPosition(x, y);
                setColor(0x0A);
                printf("%c", letter);
                y++;

                //конец крит зоны
                sem_post(&Obj->sem);



            }
            else {  //удаление строки

                //начало крит зоны
                sem_wait(&Obj->sem);

                setPosition(x, y);
                setColor(0x7A);
                printf(" ");

                //конец крит зоны
                sem_post(&Obj->sem);


                //начало крит зоны
                sem_wait(&Obj->sem);
                setPosition(x, y);
                setColor(0x0A);
                printf(" ");
                y++;

                //конец крит зоны
                sem_post(&Obj->sem);

            }

        }

    }

}

//реагирует на нажатие кнопки. Отвечает главный тред (main)
int pressButton(OperationObj* obj) {

    char button;

    while (1) {
        button = _getch();

        switch (button)
        {
        case '+':
            WG_Add(&obj->wg, 1);
            pthread_t thread;
            pthread_create(&thread, NULL, matrix, obj);
            break;

        case '-':
            WG_Done(&obj->wg);
            obj->exitFlag = CLOSE_THREAD;


            break;

        case 'q':
        case 'Q':

            obj->exitFlag = EXIT;
            for (;;) {
                if (WG_IsEmpty(&obj->wg) == 1)return 0;     //условие выхода
            }
        }
    }

    return 0;
}





WaitGroup CreateWG() {
    WaitGroup wg = {
        .counter = 0,
        .mu = PTHREAD_MUTEX_INITIALIZER,
        
    };
    return wg;
}


void WG_Add(WaitGroup* wg, int amount) {
    pthread_mutex_lock(&wg->mu);
    wg->counter += amount;
    pthread_mutex_unlock(&wg->mu);
}


void WG_Done(WaitGroup* wg) {
    pthread_mutex_lock(&wg->mu);
    if (wg->counter != 0) {
        wg->counter--;
    }
    pthread_mutex_unlock(&wg->mu);
}

int WG_IsEmpty(WaitGroup* wg) {
    pthread_mutex_lock(&wg->mu);
    int res = wg->counter;
    pthread_mutex_unlock(&wg->mu);
    if (res == 0) return 1;
    return 0;
}

//разворачивает окно и получает ширину и высоту окна
int maximizeWindowAndGetSize(OperationObj* obj ) {

    ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
    showCursor(FALSE);

    HANDLE hWndConsole;
    hWndConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    GetConsoleScreenBufferInfo(hWndConsole, &consoleInfo);

    obj->widht = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left;
    obj->height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top;

    return 0;
}

//выбор позиции
void setPosition(int x, int y) {
    COORD coordinat = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}

//выбор цвета
void setColor(int ColorNumber) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}


//функция скрытия коретки курсора
void showCursor(char show) {
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

    structCursorInfo.bVisible = show;

    SetConsoleCursorInfo(hConsoleOutput,
        &structCursorInfo);
}

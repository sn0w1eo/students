



#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "tchar.h"
#include "stdio.h"
#include "pthread.h"
#include "semaphore.h"


#define NUMBER_OF_THREADS 0 //���������� ����������� ������ � ������
#define WRITE 1             //���� ��� �������� ��� ��������

#define CLOSE_THREAD 1      //���� �� �������� ������ �����
#define EXIT 2              //���� ������ �� ���������



typedef struct {
    pthread_mutex_t mu;
    int counter;
} WaitGroup;

typedef struct {
    int widht;
    int height;

    //���� ������
    char exitFlag;

    WaitGroup wg;

    //�������� ������� ��� ������
    sem_t sem;
   
    //�������� ������� ��� �������� ������
    sem_t exit;

}OperationObj;




//������� ��� ������
void* matrix(void* obj);

//��������� �� ������� ������. �������� ������� ���� (main)
int pressButton(OperationObj* obj);

//������������� ���� � �������� ������ � ������ ����
int maximizeWindowAndGetSize(OperationObj* obj);

WaitGroup CreateWG();
void WG_Add(WaitGroup* wg, int amount);
int WG_IsEmpty(WaitGroup* wg);
void WG_Done(WaitGroup* wg);

void setPosition(int x, int y);
void setColor(int ColorNumber);

//������� ������� ������� �������
void showCursor(char show);








int main()
{
    //�������������
    OperationObj obj = {
        .height = 0,
        .widht = 0,
        .exitFlag = 0,

        .wg = CreateWG(),
        
    };
    sem_init(&obj.sem, 0, 1);
    sem_init(&obj.exit, 0, 1);


    maximizeWindowAndGetSize(&obj);
   
    //��������� ��������� ���-�� ������
    for (int i = 0; i < NUMBER_OF_THREADS; i++) {
        // ��������� 1 ����� � waitgroup
        WG_Add(&obj.wg, 1);
        pthread_t thread;
        pthread_create(&thread, NULL, matrix, &obj);
    }

    //��� �������� ������. ��������� �� ������� ������
    pressButton(&obj);

    return 0;
}

//������� ��� ������
void* matrix(void* obj) {
    srand(pthread_self().p);
    OperationObj* Obj = (OperationObj*)obj;


    while (1) {

        //������ ���� ����
        sem_wait(&Obj->exit);

        //�������� �������� �����
        if (Obj->exitFlag == CLOSE_THREAD) {

            //������� �����
            Obj->exitFlag = 0;

            //������������ ������
            sem_post(&Obj->exit);

            //���������� �����
            return NULL;

        }
        // ����� ���� ����
        sem_post(&Obj->exit);

        //�������� �� �������� ���������
        if (Obj->exitFlag == EXIT) {
            WG_Done(&Obj->wg);
            return NULL;
        }

        //������������� ��������� ����������
        int lineLength = rand() % 100;
        int x = rand() % Obj->widht;
        int y = rand() % Obj->height;
        char writeORdelete = rand() % 2;
        char letter;

        //�� ��� ��� ���� �� ���������� ������
        for (int i = 0; i < lineLength; i++) {

            //�������� �� ������� ����
            if (y > Obj->height) {
                x++;
                y = 0;
            }
            if (x > Obj->widht) {
                x = 0;
            }

            //���� ���� ����� �� ������
            if (writeORdelete == WRITE) {

                //������ ���� ����
                sem_wait(&Obj->sem);

                //�������� �� ����� ���� �����
                //���������� ��������� �����
                letter = rand() % (64 - 33) + 33;
                //�������� �������
                setPosition(x, y);
                //�������� ����
                setColor(0x7A);
                printf("%c", letter);

                //����� ���� ����
                sem_post(&Obj->sem);

                //������ ���
                //������ ���� ����
                sem_wait(&Obj->sem);
                setPosition(x, y);
                setColor(0x0A);
                printf("%c", letter);
                y++;

                //����� ���� ����
                sem_post(&Obj->sem);



            }
            else {  //�������� ������

                //������ ���� ����
                sem_wait(&Obj->sem);

                setPosition(x, y);
                setColor(0x7A);
                printf(" ");

                //����� ���� ����
                sem_post(&Obj->sem);


                //������ ���� ����
                sem_wait(&Obj->sem);
                setPosition(x, y);
                setColor(0x0A);
                printf(" ");
                y++;

                //����� ���� ����
                sem_post(&Obj->sem);

            }

        }

    }

}

//��������� �� ������� ������. �������� ������� ���� (main)
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
                if (WG_IsEmpty(&obj->wg) == 1)return 0;     //������� ������
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

//������������� ���� � �������� ������ � ������ ����
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

//����� �������
void setPosition(int x, int y) {
    COORD coordinat = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}

//����� �����
void setColor(int ColorNumber) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}


//������� ������� ������� �������
void showCursor(char show) {
    HANDLE hConsoleOutput;
    CONSOLE_CURSOR_INFO structCursorInfo;

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);

    structCursorInfo.bVisible = show;

    SetConsoleCursorInfo(hConsoleOutput,
        &structCursorInfo);
}

#include "windows.h"
#include "stdio.h"
#include "mydll.h"

#define N 8
#define M 8


__declspec(dllexport) void f1()
{
    int x = 0, y = 8;
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

__declspec(dllexport) void f2()
{
    char a[10];
    printf("Now you will see the shit code\n");
    printf("Nevertheless it is chess\nDo you know how to walk with an elephant?\n");
    scanf_s("%s", a,10);
    system("cls");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == 0 && j == 0)
            {
                printf("* ");
            }
            else if (i % 2 == j % 2)
                printf("+ ");
            else
                printf("- ");
            if (i == 0 && j == (M - 1))
            {
                printf("\n");
            }
            if (j == (M - 1) && i != 0 && i != (N - 1))
            {
                printf("\n");
            }
        }
    }

}

__declspec(dllexport) void f3() 
{
    f2();
    int x, y;
    f1();
    printf("Imagine * this is an elephant\nHow an elephant can walk?(type coordinates)\n");
    printf("Enter x1: ");
    scanf_s("%d", &x);
    printf("Enter y1: ");
    scanf_s("%d", &y);

    if (x <= 8 && y <= 8)
    {
        if (x == y)
        {
            printf("Yes, good job(elephant can only walk diagonally)");
        }
        else
        {
            printf("No, try next time");
        }
    }
    else
    {
        printf("Firstly Learn Chess Board (8x8)");
    }

}
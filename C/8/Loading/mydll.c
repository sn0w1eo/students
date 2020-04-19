#include "windows.h"
#include "stdio.h"
#include "mydll.h"

#define WHITE		0x70  // белый цвет
#define GREEN		0x20  // зеленый цвет

#define N 8         
#define M 8

__declspec(dllexport) void f1()
{
    char a[10];
    printf("Now you will see the shit code\n");
    printf("Nevertheless it is chess\n"
           "Do you know how to walk with an elephant?\n");
    scanf_s("%s", a, 10);

    system("cls");
}

__declspec(dllexport) void f2()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {

            if (i == 0 && j == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                printf("* ");
            }

            else if (i % 2 == j % 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                printf("x ");
            }

            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
                printf("- ");
            }

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
    int x, y;
    COORD coord = { 0, 8 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
    printf("\n   Imagine * this is an elephant\n"
        "   How an elephant can walk?(type coordinates)\n");
    printf("   Enter x1: ");
    scanf_s("%d", &x);
    printf("   Enter y1: ");
    scanf_s("%d", &y);

    if (x < 8 && y < 8)
    {
        if (x == y)
        {
            x = 2 * x;
            COORD coord = { x, y };
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
            printf("*");
            
            {
                COORD coord = { 0, 0 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
                printf("x ");
            } 

            {
                COORD coord = { 2, 13 };
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x07);
                printf("  Yes, good job(elephant can only walk diagonally)");
            }  

        }
        else
        {
            printf("  No, try next time");
        }

    }

    else
    {
        printf("  Firstly Learn Chess Board (8x8)");
    }

}
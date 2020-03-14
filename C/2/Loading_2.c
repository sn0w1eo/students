#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main ()
{
    system("chcp 866");
    char symbol;
    printf("\n1) Press any symbol... ");
    symbol = _getch();;
    SymbolTable(symbol);

    printf("\n2) Enter two numbers: ");
    int a, b, c, d, e, g;
    scanf_s("%d %d", &a, &b);
    MathTable(a, b);
}
int SymbolTable(char symbol)
{    
    
                     printf("\n┌───────────┬───────────┬───────────┬──────────┐");
    printf("\n³%10s³ %10s³ %10s³ %10s³", "ASCII", "DEC", "HEX", "BINARY");
                     printf("\n├───────────┼───────────┼───────────┼──────────┤");
    printf("\n³%10c³ %10d³ %10x³ %10s³ ", symbol, symbol, symbol, "EMPTY");
                     printf("\n└───────────┴───────────┴───────────┴──────────┘\n");
}
int MathTable(int a , int b)
{
    
    int  c, d, e, g;
    float f;
    c = a + b;
    d = a - b;
    e = a * b;
    f = (float)a / (float)b;
    g = a % b;
    printf("\n┌──────────────┬──────────────┬──────────────┬─────────────┐");
    printf("\n³%10s³ %10s³ %10s³ %10s³ %10s³", "add", "sub", "mul", "div","mod");
    printf("\n├──────────────┼──────────────┼──────────────┼─────────────┤");
    printf("\n³%10d³ %10d³ %10d³ %10.2lf³ %10d³", c, d, e, f, g);
    printf("\n└──────────────┴──────────────┴──────────────┴─────────────┘\n");
    
    printf("\n100%% Complete...\n\n ");
}


#include "stdio.h"
#include "conio.h"
#include "stdlib.h"

int main()
{
    system("chcp 866 > nul");
    char symbol;
    printf("\n1) Press any symbol... ");
    symbol = _getch();;
    SymbolTable(symbol);

    printf("\n2) Enter two numbers: ");
    int a, b, c, d, e, g;
    scanf_s("%d %d", &a, &b);
    MathTable(a, b);
}
int SymbolTable(unsigned char symbol)
{

    printf("\nЪДДДДДДДДДВДДДДДДДДДДВДДДДДДДДДДВДДДДДДДДДДї");
    printf("\nі%10s %10s %10s %10s", "ASCIIі", "DECі", "HEXі", "BINARYі");
    printf("\nГДДДДДДДДДЕДДДДДДДДДДЕДДДДДДДДДДЕДДДДДДДДДДґ");
    printf("\nі%9cі %9dі %9xі  %d%d%d%d%d%d%d%dі ", symbol, symbol, symbol, 
        symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2);
    printf("\nАДДДДДДДДДБДДДДДДДДДДБДДДДДДДДДДБДДДДДДДДДДЩ\n");
}
int MathTable(int a, int b)
{

    int  c, d, e, g;
    float f;
    c = a + b;
    d = a - b;
    e = a * b;
    f = (float)a / (float)b;
    g = a % b;
    printf("\nЪДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДї");
    printf("\nі%10sі %10sі %10sі %10sі %10sі", "add", "sub", "mul", "div", "mod");
    printf("\nГДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДґ");
    printf("\nі%10dі %10dі %10dі %10.2lfі %10dі", c, d, e, f, g);
    printf("\nАДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДЩ\n");

    printf("\n100%% Complete...\n\n ");
}


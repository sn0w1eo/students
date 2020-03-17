#include "stdio.h"
#include "conio.h"

int main()
{
    system("chcp 866 > nul");
    unsigned char symbol;
    printf("\n1) Press any symbol... ");
    symbol = _getch();
    //Symbol Table
    printf("\nЪДДДДДДДДДВДДДДДДДДДДВДДДДДДДДДДВДДДДДДДДДДї");
    printf("\nі%10s %10s %10s %10s", "ASCIIі", "DECі", "HEXі", "BINARYі");
    printf("\nГДДДДДДДДДЕДДДДДДДДДДЕДДДДДДДДДДЕДДДДДДДДДДґ");
    printf("\nі%9cі %9dі %9xі  %d%d%d%d%d%d%d%dі ", symbol, symbol, symbol,
        symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2);
    printf("\nАДДДДДДДДДБДДДДДДДДДДБДДДДДДДДДДБДДДДДДДДДДЩ\n");
    // Math Table
    printf("\n2) Enter two numbers: ");
    int  firstnum, secondnum;
    scanf_s("%d %d", &firstnum, &secondnum);
    printf("\nЪДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДВДДДДДДДДДДДї");
    printf("\nі%10sі %10sі %10sі %10sі %10sі", "add", "sub", "mul", "div", "mod");
    printf("\nГДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДЕДДДДДДДДДДДґ");
    printf("\nі%10dі %10dі %10dі %10.2lfі %10dі", firstnum + secondnum, 
                                                  firstnum - secondnum, 
                                                  firstnum * secondnum,
                                                 (float)firstnum / (float)secondnum,
                                                  firstnum % secondnum);
    printf("\nАДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДБДДДДДДДДДДДЩ\n");
	printf("\n100%% Complete...\n\n ");
}




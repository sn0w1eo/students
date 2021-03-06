#include "stdio.h"
void SymbolTable(unsigned char symbol)
{      
    printf_s("\n浜様様様様様様曜様様様様様様様曜様様様様様様様僕様様様様様様�");    
    printf_s("\n�         ASCII�            DEC�           HEX�       BINARY�");     
    printf_s("\n麺様様様様様様洋様様様様様様様洋様様様様様様様陵様様様様様様�");   
    printf_s("\n�      %8c�       %8d�      %8X�     %d%d%d%d%d%d%d%d�", 
        symbol, symbol, symbol, symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2);     
    printf_s("\n藩様様様様様様擁様様様様様様様擁様様様様様様様瞥様様様様様様�");
    return;
}
void MathTable(int frstNumber, int scndNumber)
{      
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;
    
    printf_s("\n浜様様様様僕様様様様曜様様様様様僕様様様様曜様様様様様融");    
    printf_s("\n�      ADD�       SUB�       MUL�       DIV�        MOD�");      
    printf_s("\n麺様様様様陵様様様様洋様様様様様陵様様様様洋様様様様様郵");    
    printf_s("\n�%9i� %9i� %9i�%10.2lf�  %9i�", add, sub, mul, div, mod);     
    printf_s("\n藩様様様様瞥様様様様擁様様様様様瞥様様様様擁様様様様様夕"); 
    return;
}
int main(void)
{  
    system("chcp 866>nul");
    unsigned char symbol; int frstNumber, scndNumber;

    printf_s("\nHello!\nPlease, enter the SYMBOL:  ");    
    symbol = getch();
    //Calling the SymbolTable function
    SymbolTable(symbol);  

    printf_s("\nPlease, enter TWO NUMBERS:  ");
    scanf_s("%i%i", &frstNumber, &scndNumber);
    //Calling the Math Table Function
    MathTable(frstNumber, scndNumber);

    printf_s("\n\n100%% Complete...");
    return 0;
}
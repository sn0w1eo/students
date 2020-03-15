#include "stdio.h"
void SymbolTable(unsigned char symbol)
{
    system("chcp 866>nul");
   
    printf_s("\n�����������������������������������������������������������ͻ");

    
    printf_s("\n�         ASCII�            DEC�           HEX�       BINARY�"); 

    
    printf_s("\n�����������������������������������������������������������͹");
   
    printf_s("\n�      %8c�       %8d�      %8X�     %d%d%d%d%d%d%d%d�", 
        symbol, symbol, symbol, symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2); 

    
    printf_s("\n�����������������������������������������������������������ͼ");
    return;
}
void MathTable(int frstNumber, int scndNumber)
{
    system("chcp 866>nul");
  
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    
    printf("\n������������������������������������������������������ͻ");    
    printf("\n�      ADD�       SUB�       MUL�       DIV�        MOD�");      
    printf("\n������������������������������������������������������͹");    
    printf("\n�%9i� %9i� %9i�%10.2lf�  %9i�", add, sub, mul, div, mod);     
    printf("\n������������������������������������������������������ͼ"); 
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
#include "stdio.h"
void SymbolTable(unsigned char symbol)
{
    system("chcp 866>nul");
   
    printf_s("\nษออออออออออออออหอออออออออออออออหออออออออออออออหอออออออออออออป");

    
    printf_s("\nบ         ASCIIบ            DECบ           HEXบ       BINARYบ"); 

    
    printf_s("\nฬออออออออออออออฮอออออออออออออออฮออออออออออออออฮอออออออออออออน");
   
    printf_s("\nบ      %8cบ       %8dบ      %8Xบ     %d%d%d%d%d%d%d%dบ", 
        symbol, symbol, symbol, symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2); 

    
    printf_s("\nศออออออออออออออสอออออออออออออออสออออออออออออออสอออออออออออออผ");
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

    
    printf("\nษอออออออออหออออออออออหออออออออออหออออออออออหอออออออออออป");    
    printf("\nบ      ADDบ       SUBบ       MULบ       DIVบ        MODบ");      
    printf("\nฬอออออออออฮออออออออออฮออออออออออฮออออออออออฮอออออออออออน");    
    printf("\nบ%9iบ %9iบ %9iบ%10.2lfบ  %9iบ", add, sub, mul, div, mod);     
    printf("\nศอออออออออสออออออออออสออออออออออสออออออออออสอออออออออออผ"); 
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
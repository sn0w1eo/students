#include "stdio.h"
void SymbolTable(unsigned char symbol)
{
    //ษอออออออออออออหออออออออออออออหออออออออออออออหออออออออออออออป
    printf_s("\n\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB" //C9 => ' ษ '; CD =>  ' อ '; CB => ' ห '
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");//BB => 'ป';

    //บ                               บ                                   บ                                 บ                                 บ
    printf_s("\n\xBA        ASCII\xBA           DEC\xBA           HEX\xBA        BINARY\xBA"); //BA => ' บ ';

    //ฬอออออออออออออฮออออออออออออออฮออออออออออออออฮออออออออออออออน
    printf_s("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE" // CC => ' ฬ '; CE => ' ฮ ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");//B9 => ' น ' ; 

    //บ                               บ                                   บ                                 บ                                 บ
    printf_s("\n\xBA     %8c\xBA      %8d\xBA      %8X\xBA      %d%d%d%d%d%d%d%d\xBA", 
        symbol, symbol, symbol, symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2); //BA => ' บ ';

    //ศอออออออออออออสออออออออออออออสออออออออออออออสออออออออออออออผ
    printf_s("\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA" //C8 =>' ศ '; CA =>' ส ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");//BC => ' ผ ';
    return;
}
void MathTable(int frstNumber, int scndNumber)
{
  
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    
    printf("\nษอออออออออหออออออออออหออออออออออหออออออออออหออออออออออป");    
    printf("\nบ      ADDบ       SUBบ       MULบ       DIVบ       MODบ");      
    printf("\nฬอออออออออฮออออออออออฮออออออออออฮออออออออออฮออออออออออน");    
    printf("\nบ%9iบ %9iบ %9iบ%10.2lfบ %9iบ", add, sub, mul, div, mod);     
    printf("\nศอออออออออสออออออออออสออออออออออสออออออออออสออออออออออผ"); 
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
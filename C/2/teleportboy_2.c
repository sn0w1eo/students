#include "stdio.h"
void SymbolTable(char symbol)
{

    //╔═════════════╦══════════════╦══════════════╦══════════════╗
    printf_s("\n\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB" //C9 => ' ╔ '; CD =>  ' ═ '; CB => ' ╦ '
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");//BB => '╗';

    //║                               ║                                   ║                                 ║                                 ║
    printf_s("\n\xBA        ASCII\xBA           DEC\xBA           HEX\xBA        BINARY\xBA"); //BA => ' ║ ';

    //╠═════════════╬══════════════╬══════════════╬══════════════╣
    printf_s("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE" // CC => ' ╠ '; CE => ' ╬ ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");//B9 => ' ╣ ' ; 

    //║                               ║                                   ║                                 ║                                 ║
    printf_s("\n\xBA     %8c\xBA      %8d\xBA      %8X\xBA IN DEVELOPING\xBA", symbol, symbol, symbol); //BA => ' ║ ';

    //╚═════════════╩══════════════╩══════════════╩══════════════╝
    printf_s("\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA" //C8 =>' ╚ '; CA =>' ╩ ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");//BC => ' ╝ ';
    return;
}
void MathTable(int frstNumber, int scndNumber)
{
  
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    
    printf_s("\n╔═════════╦══════════╦══════════╦══════════╦══════════╗");    
    printf_s("\n║      ADD║       SUB║       MUL║       DIV║       MOD║");      
    printf_s("\n╠═════════╬══════════╬══════════╬══════════╬══════════╣");    
    printf_s("\n║ %8i║  %8i║%10i║  %8.2lf║  %8i║", add, sub, mul, div, mod);     
    printf_s("\n╚═════════╩══════════╩══════════╩══════════╩══════════╝"); 
    return;
}
int main(void)
{  
    system("chcp 866");
    char symbol; int frstNumber, scndNumber;

    printf_s("\nHello!\nPlease, enter the SYMBOL:  ");    
    symbol = getch();
    //Calling the SymbolTable function
    SymbolTable(symbol);  

    printf_s("\nPlease, enter TWO NUMBERS:  ");
    scanf_s("%i%i", &frstNumber, &scndNumber);
    //Calling the Math Table Function
    MathTable(frstNumber, scndNumber);

    printf_s("\n100%% Complete...\n\n\n");
    return 0;
}
#include "stdio.h"
void SymbolTable(char symbol)
{
    //╔═════════════╦══════════════╦══════════════╦══════════════╗
    printf_s("\n╔═════════════╦══════════════╦══════════════╦══════════════╗");//BB => '╗';

    //║                               ║                                   ║                                 ║                                 ║
    printf_s("\n\xBA        ASCII\xBA           DEC\xBA           HEX\xBA        BINARY\xBA"); //BA => ' ║ ';

    //╠═════════════╬══════════════╬══════════════╬══════════════╣
    printf_s("\n╠═════════════╬══════════════╬══════════════╬══════════════╣");//B9 => ' ╣ ' ; 

    //║                               ║                                   ║                                 ║                                 ║
    printf_s("\n\xBA     %8c\xBA      %8d\xBA      %8X\xBA IN DEVELOPING\xBA", symbol, symbol, symbol); //BA => ' ║ ';

    //╚═════════════╩══════════════╩══════════════╩══════════════╝
    printf_s("\n╚═════════════╩══════════════╩══════════════╩══════════════╝\n");//BC => ' ╝ ';
}
void MathTable(int frstNumber, int scndNumber)
{
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    //╔═════════╦══════════╦══════════╦══════════╦══════════╗
    printf_s("\n╔═════════╦══════════╦══════════╦══════════╦══════════╗");//BB => '╗';

    //║                      ║                        ║                        ║                        ║                        ║
    printf_s("\n\xBA      ADD\xBA       SUB\xBA       MUL\xBA       DIV\xBA       MOD\xBA");  //BA => ' ║ ';
    
    //╠═════════╬══════════╬══════════╬══════════╬══════════╣
    printf_s("\n╠═════════╬══════════╬══════════╬══════════╬══════════╣");//B9 => ' ╣ ' ; 
    
    //║                      ║                        ║                        ║                        ║                        ║
    printf_s("\n\xBA %8i\xBA  %8i\xBA  %8i\xBA  %8.2lf\xBA  %8i\xBA",add,sub,mul,div,mod); //BA => ' ║ ';

    //╚═════════╩══════════╩══════════╩══════════╩══════════╝
    printf_s("\n╚═════════╩══════════╩══════════╩══════════╩══════════╝"); //BC => ' ╝ ';
}


int main()
{
    system("chcp 1251");
    char symbol; int frstNumber, scndNumber;
    printf_s("\nHello!\nPlease, enter the SYMBOL:  ");
    scanf_s("%c", &symbol);
   //Calling the SymbolTable function
    SymbolTable(symbol);
    
    getch();
    system("chcp 437");
    printf_s("\nPlease, enter TWO NUMBERS:  ");
    scanf_s("%i%i", &frstNumber, &scndNumber);
   
    //Calling the Math Table Function
    MathTable(frstNumber, scndNumber); 

    printf_s("\n100%% Complete...\n\n\n");    
}
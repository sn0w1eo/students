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
}
void MathTable(int frstNumber, int scndNumber)
{
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    //╔═════════╦══════════╦══════════╦══════════╦══════════╗
    printf_s("\n\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB" //C9 => ' ╔ '; CD =>  ' ═ '; CB => ' ╦ '
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");//BB => '╗';

    //║                      ║                        ║                        ║                        ║                        ║
    printf_s("\n\xBA      ADD\xBA       SUB\xBA       MUL\xBA       DIV\xBA       MOD\xBA");  //BA => ' ║ ';
    
    //╠═════════╬══════════╬══════════╬══════════╬══════════╣
    printf_s("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE" // CC => ' ╠ '; CE => ' ╬ ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");//B9 => ' ╣ ' ; 
    
    //║                      ║                        ║                        ║                        ║                        ║
    printf_s("\n\xBA %8i\xBA  %8i\xBA  %8i\xBA  %8.2lf\xBA  %8i\xBA",add,sub,mul,div,mod); //BA => ' ║ ';

    //╚═════════╩══════════╩══════════╩══════════╩══════════╝
    printf_s("\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA" //C8 =>' ╚ '; CA =>' ╩ ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC"); //BC => ' ╝ ';
}


int main()
{
    char symbol; int frstNumber, scndNumber;
    printf_s("\nHello!\nPlease, enter the SYMBOL:  ");
    scanf_s("%c", &symbol);
   //Calling the SymbolTable function
    SymbolTable(symbol);

    printf_s("\nPlease, enter FIRST NUMBER:  ");
    scanf_s("%i", &frstNumber);
    printf_s("\nPlease, enter SECOND NUMBER:  ");
    scanf_s("%i", &scndNumber);
    //Calling the Math Table Function
    MathTable(frstNumber, scndNumber); 

    printf_s("\n100%% Complete...\n\n\n");    
}
﻿#include "stdio.h"
void SymbolTable(unsigned char symbol)
{
    //����������������������������������������������������������ͻ
    printf_s("\n\xC9\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB" //C9 => ' � '; CD =>  ' � '; CB => ' � '
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCB"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBB");//BB => '�';

    //�                               �                                   �                                 �                                 �
    printf_s("\n\xBA        ASCII\xBA           DEC\xBA           HEX\xBA        BINARY\xBA"); //BA => ' � ';

    //����������������������������������������������������������͹
    printf_s("\n\xCC\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE" // CC => ' � '; CE => ' � ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCE"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xB9");//B9 => ' � ' ; 

    //�                               �                                   �                                 �                                 �
    printf_s("\n\xBA     %8c\xBA      %8d\xBA      %8X\xBA      %d%d%d%d%d%d%d%d\xBA", 
        symbol, symbol, symbol, symbol >> 7, (symbol >> 6) % 2,
        (symbol >> 5) % 2, (symbol >> 4) % 2, (symbol >> 3) % 2,
        (symbol >> 2) % 2, (symbol >> 1) % 2, symbol % 2); //BA => ' � ';

    //����������������������������������������������������������ͼ
    printf_s("\n\xC8\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA" //C8 =>' � '; CA =>' � ';
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCA"
        "\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xBC");//BC => ' � ';
    return;
}
void MathTable(int frstNumber, int scndNumber)
{
  
    int add = frstNumber + scndNumber;
    int sub = frstNumber - scndNumber;
    int mul = frstNumber * scndNumber;
    double div = (double)frstNumber / scndNumber;
    int mod = frstNumber % scndNumber;

    
    printf("\n�����������������������������������������������������ͻ");    
    printf("\n�      ADD�       SUB�       MUL�       DIV�       MOD�");      
    printf("\n�����������������������������������������������������͹");    
    printf("\n�%9i� %9i� %9i�%10.2lf� %9i�", add, sub, mul, div, mod);     
    printf("\n�����������������������������������������������������ͼ"); 
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
// На больное давите молодые
#define _CRT_SECURE_NO_WARNINGS 
#include "stdio.h" 
#include "windows.h" 
#define DLINA 100

void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


int Hex(unsigned char text[])
{
    setColor(11);
    if (text[0] != 0)
    {
        printf("%x ", text[0]);
        Hex(text + 1);
    }
}


int Bin(unsigned char text[])
{
    if (text[0] != 0)
    {
        for (int i = 7; i >= 0; i--)
        {
            int k = text[0] >> i;
            if (k & 1)
            {
                setColor(21);
                printf("1");
            }
            else
            {
                setColor(31);
                printf("0");
            }
        }
        printf(" ");
        Bin(text + 1);
    }
}

int main()
{
    unsigned char text[DLINA] = { 0x00 };
    printf("%s", "Vvedite text: ");
    scanf("%s", text);
    setColor(4);
    printf("HEX: ");
    Hex(text);
    setColor(5);
    printf("\nBIN: ");
    Bin(text);
    setColor(6);
}



/*
    ****************************
    *      NEW AAA PROJECT     *
    *        By.XXXELUS        *
    *    VRYATLI WHO SPIZDIT,  *
    * BUT AZA YA SLEJU ZA TOBOI*
    *                          *
    ****************************
*/ 

#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h" 
#include "windows.h"
#include "locale.h"
#include "stdlib.h"
#include "string.h"

/*Colors*/
#define YELLOW 0x0E
#define CYAN   0x0B 
#define RED    0x0C
#define GREY   0x08
#define GREEN  0x0A
#define White  0x0F

/*Button Macros*/
#define UP     0xE048
#define DOWN   0xE050
#define LEFT   0xE04B
#define RIGHT  0xE04D
#define ENTER  13
#define SPACE  0x20
#define ESC    0x1B

/*global variables*/

int Score = 0,           /*���� ������*/
    key,                 /*������*/
    difficultyLevel = 0, /*������� ���������*/
    choose = 0 ,         /*���������� � ��������*/
    crib = 0,            /*������� �����*/
    friendMoron = 0,     /*������� ����������*/
    diploma = 0;         /*������� �������*/

char playerName[1][15] = { "Player" };


/*FUNC FOR DRAWING */


void drawEnd();
void drawMenu(int menuItem);
void Color(int color);
void drawLogo();
void drawGameFieldKerimbekov();
void drawGameFieldBorubaev();
void drawWin();

/*FUNC CONTROL*/


int getName(int key);
int chooseDifficulty(int key);
int readKey();
void setPosition(int x, int y);
void shop(int key);
void shopber(int key);
void startGame();
void mainMenu();
void gameControl(int button_Number, int key);



int main()
{ 
    system("mode con cols=120 lines=31");
    system("chcp 866>nul");
   getName(key);
    
}


/*FUNC CONTROL*/

/*������������� ������� �������*/
void setPosition(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*������������ �� ����*/
void gameControl(int button_Number,int key) 
{
    while (key !=ENTER)
    {
        key = readKey();
        switch (key)
        {
        case DOWN:

            if (button_Number < 3) {
                button_Number++;
            }
            system("cls");
            drawLogo();
            drawMenu(button_Number);
            break;

        case UP:

            if (button_Number != 1)
            {
                button_Number--;
            }
            system("cls");
            drawLogo();
            drawMenu(button_Number);
            break;


        case ENTER:

            if (button_Number == 1)
            {
                startGame(key);
            }

            if (button_Number == 2)
            {
                if (difficultyLevel == 0) 
                {
                    shopber(key);
                }

                else
                {
                    shop(key);
                }
                
            }

            if (button_Number == 3) 
            {
                exit(0);
            }
        }   
    }
}

/*��������� � ��������� ��������(������� �������)*/
void shop(int key)
{

    system("cls");
    if (difficultyLevel == 1)
    {

        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba\n", "��������", "����", "���ᠭ��");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "�����", "45", "�窨 �2", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "���℀��", "15", "�窨 -10", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "������", "100", "������!", " ");
        printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

        if (choose == 0)
        {
            if (crib == 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (crib > 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">�㯫���");
                Color(GREY);
            }
        }

        else if (choose != 0)
        {

            if (crib == 0)
            {
                Color(RED);
                setPosition(32, 3);
                printf(" �㯨��");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 3);
                printf("�㯫���");
                Color(GREY);
            }

        }

        if (choose == 1)
        {
            if (friendMoron == 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (friendMoron > 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">�㯫���");
                Color(GREY);
            }
        }

        else if (choose != 1)
        {
            if (friendMoron == 0)
            {
                Color(RED);
                setPosition(32, 5);
                printf(" �㯨��");
                Color(GREY);
            }
            else
            {
                Color(GREEN);
                setPosition(32, 5);
                printf("�㯫���");
                Color(GREY);
            }

        }
        if (choose == 2)
        {
            if (diploma == 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (diploma > 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">�㯫���");
                Color(GREY);
            }
        }
        else if (choose != 2)
        {
            if (diploma == 0)
            {
                Color(RED);
                setPosition(32, 7);
                printf(" �㯨��");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 7);
                printf("�㯫���");
                Color(GREY);
            }

        }
        Color(0x0);
        while (key != ESC)
        {
            key = readKey();
            switch (key)
            {
            case DOWN:

                if (choose < 2)
                {
                    choose++;
                }
                system("cls");
                shop(key);
                break;


            case UP:

                if (choose != 0)
                {
                    choose--;
                }
                system("cls");
                shop(key);
                break;


            case ENTER:
                
                Color(12);
                if (choose == 0)
                {
                    if (Score >= 45) 
                    {
                        if (crib < 1)
                        {
                            Score -= 45;
                            crib++;
                            system("cls");
                            shop(key);
                        }

                        else
                        {
                            setPosition(55, 6);
                            Color(RED);
                            printf(" ��� �������");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");
                    }
                }
                if (choose == 1)
                {
                    if (Score >= 15)
                    {
                        if (friendMoron < 1) 
                        {
                            friendMoron++;
                            Score -= 15;
                            system("cls");
                            shop(key);
                        }
                        else

                        {

                            setPosition(55, 6);
                            printf(" ��� �������");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");
                    }
                }

                if (choose == 2)
                {
                    if (Score >= 100) 
                    {
                        diploma++;
                        system("cls");
                        drawWin();
                        
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");

                    }

                }
                break;
            }

            if (key == ESC)
            {
                mainMenu();
            }
        }
    }
}

/*��������� � ��������� ��������(������ �������)*/
void shopber(int key)
{
    system("cls");
    if (difficultyLevel == 0)
    {

        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba\n", "��������", "����", "���ᠭ��");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "�����", "5", "�窨 �2", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "���℀��", "5", "�窨 -10", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "������", "20", "������!", " ");
        printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

        if (choose == 0)
        {
            if (crib == 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (crib > 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">�㯫���");
                Color(GREY);
            }
        }
        else if (choose != 0)
        {
            if (crib == 0)
            {
                Color(RED);
                setPosition(32, 3);
                printf(" �㯨��");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 3);
                printf("�㯫���");
                Color(GREY);
            }

        }

        if (choose == 1)
        {
            if (friendMoron == 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (friendMoron > 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">�㯫���");
                Color(GREY);
            }
        }
        else if (choose != 1)
        {
            if (friendMoron == 0)
            {
                Color(RED);
                setPosition(32, 5);
                printf(" �㯨��");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 5);
                printf("�㯫���");
                Color(GREY);
            }

        }
        if (choose == 2)
        {
            if (diploma == 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">�㯨��");
                Color(GREY);
            }

            else if (diploma > 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">�㯫���");
                Color(GREY);
            }
        }
        else if (choose != 2)
        {
            if (diploma == 0)
            {
                Color(RED);
                setPosition(32, 7);
                printf(" �㯨��");
                Color(GREY);
            }
            else
            {
                Color(GREEN);
                setPosition(32, 7);
                printf("�㯫���");
                Color(GREY);
            }

        }
        Color(0x00);
        while (key != ESC)
        {
            key = readKey();
            switch (key)
            {
            case DOWN:

                if (choose < 2)
                {
                    choose++;
                }
                system("cls");
                shopber(key);
                break;


            case UP:

                if (choose != 0)
                {
                    choose--;
                }
                system("cls");
                shopber(key);
                break;


            case ENTER:

                Color(12);
                if (choose == 0)
                {
                    if (Score >= 5) 
                    {
                        if (crib < 1)
                        {
                            Score -= 5;
                            crib++;
                            system("cls");
                            shopber(key);
                        }

                        else
                        {
                            setPosition(55, 6);
                            Color(RED);
                            printf(" ��� �������");
                        }
                    }
                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");
                    }
                }
                if (choose == 1)
                {
                    if (Score >= 5) 
                    {
                        if (friendMoron < 1) 
                        {
                            friendMoron++;
                            Score -= 5;
                            system("cls");
                            shopber(key);
                        }

                        else
                        {

                            setPosition(55, 6);
                            printf(" ��� �������");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");
                    }
                }

                if (choose == 2)
                {
                    if (Score >= 20)
                    {
                        diploma++;
                        system("cls");
                        drawWin();
                        
                    }
                    else
                    {
                        setPosition(55, 6);
                        printf("��������� ����� ������!");

                    }

                }
                break;
            }
            if (key == ESC)
            {
                mainMenu();
            }
           
        }
    }
}

/*��������� ������*/
int readKey() {
    unsigned int ch = getch();
    if (ch == 0xE0) {
        ch = ch << 8;
        ch = ch | getch();
    }
    return ch;
}

/*������ �������*/
void startGame(int key)
{
    system("cls");

    /*���� ������� ��������� ������*/
    if (difficultyLevel == 0)
    {
         drawGameFieldBorubaev();
         while (key != ESC)
         {
            if (Score < 0)
            {
                system("cls");
                drawEnd();
                
            }

            key = readKey();
            Sleep(110);
            switch (key)
            {
            case SPACE:

                if (friendMoron > 0)
                {
                    Score -= 10;
                }
                else {
                    if (crib > 0) {
                        Score += 2;
                    }
                    else
                    {
                        Score++;
                    }
                }

                system("cls");
                drawGameFieldBorubaev();
                break;
            }
         }
    }

    /*���� ������� ��������� �������*/
    if (difficultyLevel == 1)
    {

        drawGameFieldKerimbekov();
        while (key != ESC)
        {
            if (Score < 0)
            {
                system("cls");
                drawEnd();
                
            }
            key = readKey();
            Sleep(150);
            switch (key)
            {
            case SPACE:

                if (friendMoron > 0)
                {
                    Score -= 10;
                }
                else {
                    if (crib > 0) {
                        Score += 2;
                    }
                    else
                    {
                        Score++;
                    }
                }

                system("cls");
                drawGameFieldKerimbekov();
                break;
            }

        }
    }
    if (key == ESC)
    {
        mainMenu();
    }
}

/*������� ����*/
void mainMenu()
{
    int button_Number = 1;
    system("cls");
    drawLogo();
    drawMenu(button_Number);
    gameControl(button_Number, key);
}

/*������� �������*/
int getName(int key)
{
    Color(YELLOW);
    setPosition(42, 0);
    printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    setPosition(42, 1);
    printf("\xba������ ᢮� ���-����\xba");
    setPosition(42, 2);
    printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
    setPosition(42, 3);
    printf("\xba                     \xba");
    setPosition(42, 4);
    printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    setPosition(43, 3);

    scanf("%s", playerName[0], 14);
    system("cls");
    chooseDifficulty(key);

}

/*����� ������ ���������*/
int chooseDifficulty(int key)
{

    setPosition(42, 0);
    printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    setPosition(42, 1);
    printf("\xba  �롥��  ᫮������  \xba");
    setPosition(42, 2);
    printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
    setPosition(42, 3);
    printf("\xba           \xba           \xba");
    setPosition(42, 4);
    printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    setPosition(82, 0);
    Color(GREY);
    printf("��ࠢ��:");
    setPosition(72, 1);
    printf("���㡠�� - ������ �஢�� ᫮�����.");
    setPosition(72, 2);
    printf("����஥ � ������ ����祭�� �������.");
    setPosition(72, 4);
    printf("��ਬ����� - �殮�� �஢�� ᫮�����.");
    setPosition(72, 5);
    printf("������ � �� ������ ����祭�� �������.");
    Color(YELLOW);


    if (difficultyLevel == 0)
    {
        setPosition(43, 3);
        printf(">���㡠��");
    }
    else
    {
        setPosition(43, 3);
        printf(" ���㡠��");
    }
    if (difficultyLevel == 1)
    {
        setPosition(55, 3);
        printf(">��ਬ�����");
    }
    else
    {
        setPosition(55, 3);
        printf(" ��ਬ�����");
    }

    while (key != ENTER)
    {
        key = readKey();
        switch (key)
        {
        case RIGHT:

            if (difficultyLevel == 0)
            {
                difficultyLevel++;
            }
            system("cls");
            chooseDifficulty(key);
            break;


        case LEFT:

            if (difficultyLevel == 1)
            {
                difficultyLevel--;
            }
            system("cls");
            chooseDifficulty(key);
            break;

        case ENTER:

            Color(GREY);
            mainMenu();
            break;

        }
    }
}





/*FUNC FOR DRAWING*/

/*��������� ����*/
void drawMenu(int menuItem)
{
    int i = 0, j = 0;
    setPosition(0, 17);
    while (i < 120) {
        printf("_");
        i++;
    }
    if (menuItem == 1)
    {
        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    �����    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
        
    }

    else
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    �����    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    if (menuItem == 2)
    {
        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba   �������    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    else 
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba   �������    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    if (menuItem == 3)
    {
        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    ��室     \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    else
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    ��室     \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    Color(GREY);
    while (j < 120) 
    {
        printf("_");
        j++;
    }

    setPosition(55, 22);
    printf("%s, �ਢ������!", playerName);
    setPosition(55, 23);
    printf("��� �窨 ������: %d ", Score);
   
}

/*��������� ����*/
void drawLogo() 
{
    Color(RED);
    printf(
        "                                                                                                       \n"
        "                                                                                                       \n"
        "                                                                                                       \n"
        "                                                                                                       \n"
        "                                                                                                        \n"
        "                      ||\   /||`           ||     ||         | '''',   ||      |''||''| .|'''', '||  //' \n"
        "                      ||\\.//||            ||     ||         ||        ||         ||    ||       || //   \n"
        "                      ||    ||    '''|. ''||''   ||''|,     ||        ||         ||    ||       ||<<    \n"
        "                      ||    ||  .| ''||   ||     ||  ||     ||        ||         ||    ||       || \\\\   \n"
        "                      ||    ||  `|.. ||   `|..'  ||  ||     |....' .  || ...| |..||..| |....'.  ||  \\\\ \n");

    Color(GREY);
}

/*����� �����*/
void Color(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*��������� �������� ���� ��� ������� ������ ���������*/
void drawGameFieldKerimbekov() 
{
    int i = 0;
    /*���㥬 ࠬ�� ����� ������*/
    for(i=0;i<31;i++)
    {
        Color(White);
        setPosition(50, i);
        if (i == 1 || i == 27) 
        {
            printf("\xb9");
        }

        else if (i == 25) 
        {
            printf("\xcc");
        }

        else
        {
            printf("\xba");
        }
        
    }
    setPosition(0, 0);
    Color(0x8E);
    printf("                ��� �������������                 ");
    Color(GREY);
    setPosition(0, 1);
    int j = 0;
    for (j = 0; j < 50; j++)
    {
        Color(White);
        printf("\xcd");
    }
    Color(White);
    setPosition(51, 25);
    for (int y = 0; y < 69; y++) 
    {
        Color(White);
        printf("\xcd");
    }
    setPosition(64, 27);
    Color(RED);
    printf("�������� | SPACE | ��� ��������� ����� ������");
    setPosition(64, 28);
    printf("     ������� |ESC| ��� �������� � ����");
    Color(White);
    setPosition(0, 27);
    for (int t = 0; t < 50; t++)
    {
        Color(White);
        printf("\xcd");
    }
    setPosition(5, 28);
    Color(YELLOW);
    printf("%s", playerName);
    setPosition(5, 29);
    printf("����� ������: %d", Score);
    

    /*���㥬 ������*/
    setPosition(0, 2);
    Color(GREY);
    printf(
        "..................................................\n"
        "..................................................\n"
        "......................***,,*,.....................\n"
        "................,###/*,,,,*,,.,/(*,...............\n"
        "..............#&&%%%%%%#(/(///*/*,..////.............\n"
        "............(%%%%#((##(####((///**/***,,,...........\n"
        ".........../(######%%#%%##########((((/,*...........\n"
        "........../(((#####%%%%%%%%%%%%%%########(((//*..........\n"
        "........./(((#(#######((((##%%%%%%%%%%###((*(..........\n"
        "..........(((((######(/((###%%###(#((//*/..........\n"
        "..........((#(#%%%%%%%%#####(##%%%%((/.*/((*/,..........\n"
        "........../%%##%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%######((*,...........\n"
        "........../.#####%%%%%%%%%%%%##%%%%%%%%#(#%%%%#(*.............\n"
        "...........*#####%%%%%%%%##%%###((((####/..............\n"
        "........,**(#((##%%%%#(/(((###((#(#(/...............\n"
        "....****,,..&((((#######(((((((##,................\n"
        "*,,.  ..,....%%%%((((##%%#####((((...................\n"
        "..    ....... #%%&(((((((##((.(   .................\n"
        ".      .      .#&&&%%(#((((/(%%*        ............\n"
        "                (&&&&&%%(*#%%%%%%            .........\n"
        "                 (&&&(*...,%%*               ......\n"
        "                  #%%/  ...*.*                  ...\n"
        "                   #(%%# .*(#,                   ..\n"
        "                    #(/,..(#.                   ..\n"
        "                     ..., /#.                   ..\n");


    /*���㥬 �����*/
    Color(White);
    setPosition(51, 1);
    printf("          .,**((**..                                .**/(/*,.      ");
    setPosition(51, 2);
    printf(" /@@@@@&&/,      ,(&@@@@@@@*               .&@@@@@@&%*      .*%&@@@@@%   ");
    setPosition(51, 3);
    printf    ("@*                         #@@@.      &@@@&                       @@");
    setPosition(51, 4);
    printf("/@*                           .@@@(@@@(                             @");
    setPosition(51, 5);
    printf("@*    .*������&/.               ,@@@,              ,(&��C����%/.     @");
    setPosition(51, 6);
    printf("@*                  .%@@@@(      ,@@@,    *@@@@&/                    @");
    setPosition(51, 7);
    printf("@*      *(%������&(*.            ,@@@,    ,       ,*��C����#(*.      @");
    setPosition(51, 8);
    printf("@*    .            ,#@@@@%.       ,@@@,      #@@@@%/.            ,.    @");
    setPosition(51, 9);
    printf("@*     ./#������@@#/,     .*    ,@@@,    (,        ,/��C����%#/,      @");
    setPosition(51, 10);
    printf("@*    .            .#@@@@@,     ,@@@,    .#@@@@*              ..    @");
    setPosition(51, 11);
    printf("@*        ,������,         ,    ,@@@,   (.          ��C����         @");
    setPosition(51, 12);
    printf("@*    ((,        ,(%@@@@&,       ,@@@,     .#@@@@@#/.         ,/*    @");
    setPosition(51, 13);
    printf("@*        ,*/((/*,        ##    ,@@@,    @%.         .,,,,.           @");
    setPosition(51, 14);
    printf("@*    ((,        ,(&@@@@%,       ,@@@,      #@@@@@#/.         ,/*    @");
    setPosition(51, 15);
    printf("@*         .,,,,.         ##    ,@@@,    @&.                        @");
    setPosition(51, 16);
    printf("@*    %&/,     .,/%@@@@@#         ,@@@,        /&@@@@@#/,.   .,/#@/   @");
    setPosition(51, 17);
    printf("@*                      ,@&     ,@@@,     @@*                       @");
    setPosition(51, 18);
    printf("@*    &@%/,..  ..,/%@@@@@&,       ,@@@,       .%@@@@@@#/*,..,*/#@@(    @");
    setPosition(51, 19);
    printf("@*                      /@@     ,@@@,     @@#.                      @");
    setPosition(51, 20);
    printf("@*                                *                                 @");
    setPosition(51, 21);
    printf("@*         (&@@@@@@@@@@&/         *               ,#&@@@@@@@@@@@@,  @");
    setPosition(51, 22);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    *      @@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    setPosition(51, 23);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    
}

/*��������� �������� ���� ��� ������ ������ ���������*/
void drawGameFieldBorubaev() 
{
    int i = 0;
    /*���㥬 ࠬ�� ����� ������*/
    for (i = 0; i < 31; i++)
    {
        Color(White);
        setPosition(50, i);
        if (i == 1 || i == 27)
        {
            printf("\xb9");
        }
        else if (i == 25)
        {
            printf("\xcc");
        }
        else
        {
            printf("\xba");
        }

    }
    setPosition(0, 0);
    Color(0x8E);
    printf("                ��� �������������                 ");
    Color(GREY);
    setPosition(0, 1);
    int j = 0;
    for (j = 0; j < 50; j++)
    {
        Color(White);
        printf("\xcd");
    }
    Color(15);
    setPosition(51, 25);
    for (int y = 0; y < 69; y++)
    {
        Color(White);
        printf("\xcd");
    }
    setPosition(64, 27);
    Color(RED);
    printf("�������� | SPACE | ��� ��������� ����� ������");
    setPosition(64, 28);
    printf("     ������� |ESC| ��� �������� � ����");
    Color(White);
    setPosition(0, 27);
    for (int t = 0; t < 50; t++)
    {
        Color(White);
        printf("\xcd");
    }
    setPosition(5, 28);
    Color(YELLOW);
    printf("%s", playerName);
    setPosition(5, 29);
    printf("����� ������: %d", Score);

    /*��������� ��������*/
    setPosition(0, 2);
    Color(GREY);
    printf(
        "                      .                           \n"
        "                  .,.,**//////(..                 \n"
        "              ,**///*///(/(/((((((,. .      .     \n"
        "             ,*//*////////////**,*/(/*.  .       .\n"
        "            ,*/**//////((((((////*****,. .. .     \n"
        "          .,//*////(((((((((((///*//#**. .  .     \n"
        "          .***///////(((((((////////(/*...      . \n"
        "         .******/**/(##%%#%%((((////////*..    .    \n"
        "          (*.(***/##//((///((//////*//*/*         \n"
        "         ..,**///((//*(///////**/***(//(,.        \n"
        "           ,*/////////(///((/((///***((.  .       \n"
        " .    .    ,**/(((/*//((/*/###(///**/( ..         \n"
        "*.        ..**////(/((/((((//(///**,/....        .\n"
        "*,.    ......*/(((/***/***///(///*(........       \n"
        "....   .......,*/(((((((((((////*/%... ...........\n"
        "... ...........# &///((((((//*/***&#..............\n"
        "................,&@@///////////&@&(...............\n"
        ". ................&@@@@&//(/#&@@@&/...............\n"
        "...................(@@@##(/,,,/&&%%,...............\n"
        "....................,&&%&(*/*/&&&%%........... ....\n"
        ".....................,&&@@&*(*&&@*................\n"
        ".......................&&(/(#/,&,.................\n"
        "........................,/(%%#(*...................\n"
        "............................(.....................\n");



    /*���㥬 �����*/
    Color(White);
    setPosition(51, 1);
    printf("          .,**((**..                                .**/(/*,.      ");
    setPosition(51, 2);
    printf(" /@@@@@&&/,      ,(&@@@@@@@*               .&@@@@@@&%*      .*%&@@@@@%   ");
    setPosition(51, 3);
    printf("@*                         #@@@.      &@@@&                       @@");
    setPosition(51, 4);
    printf("/@*                           .@@@(@@@(                             @");
    setPosition(51, 5);
    printf("@*    .*������&/.               ,@@@,              ,(&��C����%/.     @");
    setPosition(51, 6);
    printf("@*                  .%@@@@(      ,@@@,    *@@@@&/                    @");
    setPosition(51, 7);
    printf("@*      *(%������&(*.            ,@@@,    ,        ,*��C����#(*.     @");
    setPosition(51, 8);
    printf("@*    .            ,#@@@@%.       ,@@@,      #@@@@%/.            ,.    @");
    setPosition(51, 9);
    printf("@*     ./#������@@#/,     .*    ,@@@,    (,         ,/��C����%#/,     @");
    setPosition(51, 10);
    printf("@*    .            .#@@@@@,     ,@@@,    .#@@@@*              ..    @");
    setPosition(51, 11);
    printf("@*        ,������,         ,    ,@@@,   (.          ��C����         @");
    setPosition(51, 12);
    printf("@*    ((,        ,(%@@@@&,       ,@@@,      .#@@@@@#/.        ,/*    @");
    setPosition(51, 13);
    printf("@*        ,*/((/*,        ##    ,@@@,    @%.         .,,,,.           @");
    setPosition(51, 14);
    printf("@*    ((,        ,(&@@@@%,       ,@@@,      #@@@@@#/.         ,/*    @");
    setPosition(51, 15);
    printf("@*         .,,,,.         ##    ,@@@,    @&.                        @");
    setPosition(51, 16);
    printf("@*    %&/,     .,/%@@@@@#         ,@@@,        /&@@@@@#/,.   .,/#@/   @");
    setPosition(51, 17);
    printf("@*                      ,@&     ,@@@,     @@*                       @");
    setPosition(51, 18);
    printf("@*    &@%/,..  ..,/%@@@@@&,       ,@@@,       .%@@@@@@#/*,..,*/#@@(    @");
    setPosition(51, 19);
    printf("@*                      /@@     ,@@@,     @@#.                      @");
    setPosition(51, 20);
    printf("@*                                *                                 @");
    setPosition(51, 21);
    printf("@*         (&@@@@@@@@@@&/         *               ,#&@@@@@@@@@@@@,  @");
    setPosition(51, 22);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@    *      @@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    setPosition(51, 23);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");

    

}

/*��������� ��������� */
void drawEnd() 
{
    Color(RED);
    printf(
        "_____ _____ _____ _   _ _____ _____ _     _____ _   _   _   _  ___  _   _ _   _ _____ \n"
        "|  _  |_   _/  __ | | | |_   _/  ___| |   |  ___| \\ | | | \\ | |/ _ \\| | | | | | |_   _|\n"
        "| | | | | | | /  \\| |_| | | | \\ `--.| |   | |__ |  \\| | |  \\| / /_\\ | |_| | | | | | |  \n"
        "| | | | | | | |   |  _  | | |  `--. | |   |  __|| . ` | | . ` |  _  |  _  | | | | | |  \n"
        "\\ \\_/ / | | | \\__/| | | |_| |_/\\__/ | |___| |___| |\\  | | |\\  | | | | | | | |_| |_| |_ \n"
        " \\___/  \\_/  \____\\_| |_/\\___/\\____/\_____\\____/\\_| \\_/ \\_| \\_\\_| |_\\_| |_/\\___/ \\___/ \n P.S: �������� �����");
    Sleep(5000);
    exit(0);
}

/*��������� ��������*/
void drawWin() 
{
    Color(GREEN);
    printf(
        " .----------------.  .----------------.  .-----------------.\n"
        "| .--------------. || .--------------. || .--------------. |\n"
        "| | _____  _____ | || |     _____    | || | ____  _____  | |\n"
        "| ||_   _|| _  _|| || |    |_   _|   | || ||_   \\ |  _|  | |\n"
        "| |  | | /\\ | |  | || |      | |     | || |  |   \\ | |   | |\n"
        "| |  | |/  \\| |  | || |      | |     | || |  | |\\ \\| |   | |\n"
        "| |  |   /\\   |  | || |     _| |_    | || | _| |_\\ | |_  | |\n"
        "| |  |__ / \\__|  | || |    |_____|   | || ||_____|\\____| | |\n"
        "| |              | || |              | || |              | |\n"
        "| '--------------' || '--------------' || '--------------' |\n"
        "'----------------'  '----------------'  '----------------' \n");
    Color(GREY);
    Sleep(5000);
    exit(0);
}
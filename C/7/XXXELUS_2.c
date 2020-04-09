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

int Score = 0,           /*Œ˜ÍË ÁÌ‡ÌËÈ*/
    key,                 /* ÌÓÔÍ‡*/
    difficultyLevel = 0, /*”Ó‚ÂÌ¸ ÒÎÓÊÌÓÒÚË*/
    choose = 0 ,         /*”Ô‡‚ÎÂÌËÂ ‚ Ï‡„‡ÁËÌÂ*/
    crib = 0,            /*ÔÓÍÛÔÍ‡ ¯ÔÓ˚*/
    friendMoron = 0,     /*ÔÓÍÛÔÍ‡ ƒÛ„‡ƒ¿”Õ¿*/
    diploma = 0;         /*ÔÓÍÛÔÍ‡ ‰ËÔÎÓÏ‡*/

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

/*”ÒÚ‡Ì‡‚ÎË‚‡ÂÚ ÔÓÁËˆË˛ ÍÛÒÓ‡*/
void setPosition(int x, int y)
{
    COORD coord = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

/*œÂÂ‰‚ËÊÂÌËÂ ÔÓ ÏÂÌ˛*/
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

/*ŒÚËÒÓ‚Í‡ Ë Ì‡ÒÚÓÈÍË Ï‡„‡ÁËÌ‡(“ﬂ∆≈À€… ”–Œ¬≈Õ‹)*/
void shop(int key)
{

    system("cls");
    if (difficultyLevel == 1)
    {

        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba\n", "ç†ß¢†≠®•", "ñ•≠†", "éØ®·†≠®•");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "òèéêÄ", "45", "éÁ™® Â2", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "™•≠‚ÑÄìç", "15", "éÁ™® -10", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "Ñàèãéå", "100", "èéÅÖÑÄ!", " ");
        printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

        if (choose == 0)
        {
            if (crib == 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (crib > 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }

        else if (choose != 0)
        {

            if (crib == 0)
            {
                Color(RED);
                setPosition(32, 3);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 3);
                printf("ä„Ø´•≠Æ");
                Color(GREY);
            }

        }

        if (choose == 1)
        {
            if (friendMoron == 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (friendMoron > 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }

        else if (choose != 1)
        {
            if (friendMoron == 0)
            {
                Color(RED);
                setPosition(32, 5);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }
            else
            {
                Color(GREEN);
                setPosition(32, 5);
                printf("ä„Ø´•≠Æ");
                Color(GREY);
            }

        }
        if (choose == 2)
        {
            if (diploma == 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (diploma > 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }
        else if (choose != 2)
        {
            if (diploma == 0)
            {
                Color(RED);
                setPosition(32, 7);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 7);
                printf("ä„Ø´•≠Æ");
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
                            printf(" ìÜÖ äìèãÖçé");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");
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
                            printf(" ìÜÖ äìèãÖçé");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");
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
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");

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

/*ŒÚËÒÓ‚Í‡ Ë Ì‡ÒÚÓÈÍË Ï‡„‡ÁËÌ‡(À≈√ »… ”–Œ¬≈Õ‹)*/
void shopber(int key)
{
    system("cls");
    if (difficultyLevel == 0)
    {

        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba\n", "ç†ß¢†≠®•", "ñ•≠†", "éØ®·†≠®•");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "òèéêÄ", "5", "éÁ™® Â2", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "™•≠‚ÑÄìç", "5", "éÁ™® -10", " ");
        printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xce\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
        printf("\xba%8s\xba%5s\xba%15s\xba%8s\xba\n", "Ñàèãéå", "20", "èéÅÖÑÄ!", " ");
        printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");

        if (choose == 0)
        {
            if (crib == 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (crib > 0)
            {
                Color(GREEN);
                setPosition(32, 3);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }
        else if (choose != 0)
        {
            if (crib == 0)
            {
                Color(RED);
                setPosition(32, 3);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 3);
                printf("ä„Ø´•≠Æ");
                Color(GREY);
            }

        }

        if (choose == 1)
        {
            if (friendMoron == 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (friendMoron > 0)
            {
                Color(GREEN);
                setPosition(32, 5);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }
        else if (choose != 1)
        {
            if (friendMoron == 0)
            {
                Color(RED);
                setPosition(32, 5);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }

            else
            {
                Color(GREEN);
                setPosition(32, 5);
                printf("ä„Ø´•≠Æ");
                Color(GREY);
            }

        }
        if (choose == 2)
        {
            if (diploma == 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">ä„Ø®‚Ï");
                Color(GREY);
            }

            else if (diploma > 0)
            {
                Color(GREEN);
                setPosition(32, 7);
                printf(">ä„Ø´•≠Æ");
                Color(GREY);
            }
        }
        else if (choose != 2)
        {
            if (diploma == 0)
            {
                Color(RED);
                setPosition(32, 7);
                printf(" ä„Ø®‚Ï");
                Color(GREY);
            }
            else
            {
                Color(GREEN);
                setPosition(32, 7);
                printf("ä„Ø´•≠Æ");
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
                            printf(" ìÜÖ äìèãÖçé");
                        }
                    }
                    else
                    {
                        setPosition(55, 6);
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");
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
                            printf(" ìÜÖ äìèãÖçé");
                        }
                    }

                    else
                    {
                        setPosition(55, 6);
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");
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
                        printf("çÖïÇÄíÄÖí éóäéÇ áçÄçàâ!");

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

/*—˜ËÚ˚‚‡ÂÏ ÍÌÓÔÍÛ*/
int readKey() {
    unsigned int ch = getch();
    if (ch == 0xE0) {
        ch = ch << 8;
        ch = ch | getch();
    }
    return ch;
}

/*»„‚ÓÈ ÔÓˆÂÒÒ*/
void startGame(int key)
{
    system("cls");

    /*≈—À» ”–Œ¬≈Õ‹ —ÀŒ∆ÕŒ—“» À≈√ »…*/
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

    /*≈—À» ”–Œ¬≈Õ‹ —ÀŒ∆ÕŒ—“» “ﬂ∆≈À€…*/
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

/*√Î‡‚ÌÓÂ ÏÂÌ˛*/
void mainMenu()
{
    int button_Number = 1;
    system("cls");
    drawLogo();
    drawMenu(button_Number);
    gameControl(button_Number, key);
}

/*—˜ËÚ‡Ú¸ ÌËÍÌÂÈÏ*/
int getName(int key)
{
    Color(YELLOW);
    setPosition(42, 0);
    printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    setPosition(42, 1);
    printf("\xbaÇ¢•§®‚• ·¢Æ© ≠®™-≠•©¨\xba");
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

/*¬˚·Ó ÛÓ‚Ìˇ ÒÎÓÊÌÓÒÚË*/
int chooseDifficulty(int key)
{

    setPosition(42, 0);
    printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    setPosition(42, 1);
    printf("\xba  ÇÎ°•‡•‚•  ·´Æ¶≠Æ·‚Ï  \xba");
    setPosition(42, 2);
    printf("\xcc\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcb\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xb9\n");
    setPosition(42, 3);
    printf("\xba           \xba           \xba");
    setPosition(42, 4);
    printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xca\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    setPosition(82, 0);
    Color(GREY);
    printf("ëØ‡†¢™†:");
    setPosition(72, 1);
    printf("ÅÆ‡„°†•¢ - ´•£™®© „‡Æ¢•Ï ·´Æ¶≠Æ·‚®.");
    setPosition(72, 2);
    printf("ÅÎ·‚‡Æ• ® ´•£™Æ• ØÆ´„Á•≠®• §®Ø´Æ¨†.");
    setPosition(72, 4);
    printf("ä•‡®¨°•™Æ¢ - ‚Ô¶•´Î© „‡Æ¢•Ï ·´Æ¶≠Æ·‚®.");
    setPosition(72, 5);
    printf("ÑÆ´£Æ• ® ≠• ´•£™Æ• ØÆ´„Á•≠®• §®Ø´Æ¨†.");
    Color(YELLOW);


    if (difficultyLevel == 0)
    {
        setPosition(43, 3);
        printf(">ÅÆ‡„°†•¢");
    }
    else
    {
        setPosition(43, 3);
        printf(" ÅÆ‡„°†•¢");
    }
    if (difficultyLevel == 1)
    {
        setPosition(55, 3);
        printf(">ä•‡®¨°•™Æ¢");
    }
    else
    {
        setPosition(55, 3);
        printf(" ä•‡®¨°•™Æ¢");
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

/*ŒÚËÒÓ‚Í‡ ÏÂÌ˛*/
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
            "\xba    à£‡†‚Ï    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
        
    }

    else
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    à£‡†‚Ï    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    if (menuItem == 2)
    {
        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba   å†£†ß®≠    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    else 
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba   å†£†ß®≠    \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    if (menuItem == 3)
    {
        Color(CYAN);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    ÇÎÂÆ§     \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    else
    {
        Color(YELLOW);
        printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n"
            "\xba    ÇÎÂÆ§     \xba\n"
            "\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    }

    Color(GREY);
    while (j < 120) 
    {
        printf("_");
        j++;
    }

    setPosition(55, 22);
    printf("%s, Ø‡®¢•‚·‚¢„Ó!", playerName);
    setPosition(55, 23);
    printf("Ç†Ë® ÆÁ™® ß≠†≠®©: %d ", Score);
   
}

/*ŒÚËÒÓ‚Í‡ ÀÓ„Ó*/
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

/*¬˚·Ó ˆ‚ÂÚ‡*/
void Color(int color) 
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/*ŒÚËÒÓ‚Í‡ Ë„Ó‚Ó„Ó ÔÓÎˇ ÔË ÚˇÊÂÎÓÏ ÛÓ‚ÌÂ ÒÎÓÊÌÓÒÚË*/
void drawGameFieldKerimbekov() 
{
    int i = 0;
    /*ê®·„•¨ ‡†¨™„ ¢Æ™‡„£ ØÆ‡‚‡•‚†*/
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
    printf("                ÇÄò èêÖèéÑÄÇÄíÖãú                 ");
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
    printf("çÄÜàåàíÖ | SPACE | Ñãü èéãìóÖçàü éóäéÇ áçÄçàâ");
    setPosition(64, 28);
    printf("     çÄÜåàíÖ |ESC| Ñãü ÇéáÇêÄíÄ Ç åÖçû");
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
    printf("éóäéÇ áçÄçàâ: %d", Score);
    

    /*ê®·„•¨ ØÆ‡‚‡•‚*/
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


    /*ê®·„•¨ ™≠®£„*/
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
    printf("@*    .*ÖÅìóàâ&/.               ,@@@,              ,(&ÇõCòåÄí%/.     @");
    setPosition(51, 6);
    printf("@*                  .%@@@@(      ,@@@,    *@@@@&/                    @");
    setPosition(51, 7);
    printf("@*      *(%ÖÅìóàâ&(*.            ,@@@,    ,       ,*ÇõCòåÄí#(*.      @");
    setPosition(51, 8);
    printf("@*    .            ,#@@@@%.       ,@@@,      #@@@@%/.            ,.    @");
    setPosition(51, 9);
    printf("@*     ./#ÖÅìóàâ@@#/,     .*    ,@@@,    (,        ,/ÇõCòåÄí%#/,      @");
    setPosition(51, 10);
    printf("@*    .            .#@@@@@,     ,@@@,    .#@@@@*              ..    @");
    setPosition(51, 11);
    printf("@*        ,ÖÅìóàâ,         ,    ,@@@,   (.          ÇõCòåÄí         @");
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

/*ŒÚËÒÓ‚Í‡ Ë„Ó‚Ó„Ó ÔÓÎˇ ÔË ÎÂ„ÍÓÏ ÛÓ‚ÌÂ ÒÎÓÊÌÓÒÚË*/
void drawGameFieldBorubaev() 
{
    int i = 0;
    /*ê®·„•¨ ‡†¨™„ ¢Æ™‡„£ ØÆ‡‚‡•‚†*/
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
    printf("                ÇÄò èêÖèéÑÄÇÄíÖãú                 ");
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
    printf("çÄÜàåàíÖ | SPACE | Ñãü èéãìóÖçàü éóäéÇ áçÄçàâ");
    setPosition(64, 28);
    printf("     çÄÜåàíÖ |ESC| Ñãü ÇéáÇêÄíÄ Ç åÖçû");
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
    printf("éóäéÇ áçÄçàâ: %d", Score);

    /*ÓÚËÒÓ‚Í‡ ÔÓÚÂÚ‡*/
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



    /*ê®·„•¨ ™≠®£„*/
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
    printf("@*    .*ÖÅìóàâ&/.               ,@@@,              ,(&ÇõCòåÄí%/.     @");
    setPosition(51, 6);
    printf("@*                  .%@@@@(      ,@@@,    *@@@@&/                    @");
    setPosition(51, 7);
    printf("@*      *(%ÖÅìóàâ&(*.            ,@@@,    ,        ,*ÇõCòåÄí#(*.     @");
    setPosition(51, 8);
    printf("@*    .            ,#@@@@%.       ,@@@,      #@@@@%/.            ,.    @");
    setPosition(51, 9);
    printf("@*     ./#ÖÅìóàâ@@#/,     .*    ,@@@,    (,         ,/ÇõCòåÄí%#/,     @");
    setPosition(51, 10);
    printf("@*    .            .#@@@@@,     ,@@@,    .#@@@@*              ..    @");
    setPosition(51, 11);
    printf("@*        ,ÖÅìóàâ,         ,    ,@@@,   (.          ÇõCòåÄí         @");
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

/*ŒÚËÒÓ‚Í‡ ÔÓË„˚¯‡ */
void drawEnd() 
{
    Color(RED);
    printf(
        "_____ _____ _____ _   _ _____ _____ _     _____ _   _   _   _  ___  _   _ _   _ _____ \n"
        "|  _  |_   _/  __ | | | |_   _/  ___| |   |  ___| \\ | | | \\ | |/ _ \\| | | | | | |_   _|\n"
        "| | | | | | | /  \\| |_| | | | \\ `--.| |   | |__ |  \\| | |  \\| / /_\\ | |_| | | | | | |  \n"
        "| | | | | | | |   |  _  | | |  `--. | |   |  __|| . ` | | . ` |  _  |  _  | | | | | |  \n"
        "\\ \\_/ / | | | \\__/| | | |_| |_/\\__/ | |___| |___| |\\  | | |\\  | | | | | | | |_| |_| |_ \n"
        " \\___/  \\_/  \____\\_| |_/\\___/\\____/\_____\\____/\\_| \\_/ \\_| \\_\\_| |_\\_| |_/\\___/ \\___/ \n P.S: éíóàëãÖç çÄïìâ");
    Sleep(5000);
    exit(0);
}

/*ŒÚËÒÓ‚Í‡ ‚˚È„˚¯‡*/
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
#include "stdio.h" 
#include "windows.h"
#include "conio.h"

#define RIGHT 0x4D00
#define LEFT 0x4B00
#define UP 0x4800
#define DOWN 0x5000
#define ESC 0x1B
#define POSITION(x, y) { COORD coordinates = { x,y }; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates); }
#define COLOR(color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }


int main()
{
    int x = 0, y = 0, input, xMax = 118, yMax = 24;
    POSITION(0, 24)
    COLOR(14)
    printf("Press ESC to exit... ");
    POSITION(x, y)
        do {
            input = _getch();
            if (input == 0 || input == 0xE0)
            {
                input = _getch() << 8;
            }

            if (input >= 'A' && input <= 'z') { printf("%c\b", input); }
            switch (input)
            {
            case RIGHT: if (x != xMax) x++; POSITION(x, y) break;
            case LEFT: if (x != 0) x--; POSITION(x, y) break;
            case UP: if (y != 0) y--; POSITION(x, y) break;
            case DOWN: if (y != yMax) y++; POSITION(x, y) break;
            case '0': COLOR(1); break;
            case '1': COLOR(2); break;
            case '2': COLOR(3); break;
            case '3': COLOR(4); break;
            case '4': COLOR(5); break;
            case '5': COLOR(6); break;
            case '6': COLOR(7); break;
            case '7': COLOR(8); break;
            case '8': COLOR(9); break;
            case '9': COLOR(10); break;
            default:

                if (input == ESC)
                {
                    POSITION(0, 24)
                        COLOR(14)
                        for (int i = 0; i <= 80; i++)
                        {
                            int sum = 50;
                            while (sum <= 100)
                            {
                                POSITION(i, 24);
                                printf("%c\b", sum);
                                sum++;
                                printf("Û\b");
                            }
                        }
                }

            }

        } while (input != ESC);
}
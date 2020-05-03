#ifndef ENGINE_H
#define ENGINE_H

typedef unsigned char uchar;

void GetKeystroke(uchar** list); //основа
int SeletDeleteAction();
int SelectUpdateAction();
int SelectAction();
void SetConsoleCursor(int x, int y);
void HideCursor();

#endif // !ENGINE_H


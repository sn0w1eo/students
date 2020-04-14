#ifndef DISPLAYFIELD_H  // или вот так?
#define DISPLAYFIELD_H

// отобразить игровое поле
void DisplayGameField(unsigned char krissKross[3][3]);

//нарисовать крестик

void DrawKriss(int x, int y);
//нарисовать нолик

void DrawKross(int x, int y);
//нарисовать пробел

void DrawBlank(int x, int y);
//установить цвет

void SetColor(int color);
//нарисовать рамку

void DisplayFrame();

//изобразить хоткеи
void ShowHotkeys();


#endif // !DISPLAYFIELD_H

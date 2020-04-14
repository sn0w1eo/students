#pragma once // так защищать свой хедер файл от повторной загрузки

// создать игровое поле
void MakeGameField(unsigned char krissKross[3][3]);

//проверить все ряды на наличие одинаковых знаков
unsigned char CheckThreeMark(unsigned char krissKross[3][3]);

//определить победителя
int ItsVictory(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char computerMark);

// ход компьютера
void ComputerMove(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char aiMark);

//Проверка на правильность хода, не занята ли уже ячейка
int  CheckMove(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char aiMark, int x, int y);

//установить курсор
void SetConsoleCursor(int x, int y);

//спрятать курсор
void HideCursor();
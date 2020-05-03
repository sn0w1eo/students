#ifndef READ_H
#define READ_H

//Синоним к unsigned char.
typedef unsigned char uchar;

//Отобразить имя.
void DisplayName(uchar** list, int contactIndex);

//Отобразить номер телефона.
void DisplayPhoneNumber(uchar** list, int contactIndex);

//Отобразить дату.
void DisplayDate(uchar** list, int contactIndex);

//Считать общий размер основного блока памяти.
int GetListSize(uchar** list);

void DisplayAll(uchar** list);
#endif // !READ_H

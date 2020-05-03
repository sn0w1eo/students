#ifndef UPDATE_H
#define UPDATE_H

//Синоним к unsigned char.
typedef unsigned char uchar;

//Перезаписать имя.
uchar** UpdateName(uchar** list, int contactIndex);

//Перезаписать номер телефона.
uchar** UpdatePhoneNumber(uchar** list, int contactIndex);

//Перезаписать дату.
uchar** UpdateDate(uchar** list, int contactIndex);

#endif // !UPDATE_H

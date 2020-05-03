#ifndef DELETE_H
#define DELETE_H

//Синоним к unsigned char.
typedef unsigned char uchar;

//Удалить весь контакт.
void DeleteContact(uchar** list, int contactIndex);

//Затиреть номер телефона.
void DeletePhoneNumber(uchar** list, int contactIndex);

//Затиреть дату.
void DeleteDate(uchar** list, int contactIndex);

#endif // !DELETE_H

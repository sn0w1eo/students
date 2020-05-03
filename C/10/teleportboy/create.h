#ifndef CREATE_H
#define CREATE_H

//Синоним к unsigned char.
typedef unsigned char uchar;

//Добавить контакт.
uchar** AddContact(uchar** list, int contactIndex);

//Добавить номер телефона.
uchar** AddPhoneNumber(uchar** list, int contactIndex);

//Добавить дату.
uchar** AddDate(uchar** list, int contactIndex);

#endif // !CREATE_H


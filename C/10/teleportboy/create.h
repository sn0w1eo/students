#ifndef CREATE_H
#define CREATE_H

//������� � unsigned char.
typedef unsigned char uchar;

//�������� �������.
uchar** AddContact(uchar** list, int contactIndex);

//�������� ����� ��������.
uchar** AddPhoneNumber(uchar** list, int contactIndex);

//�������� ����.
uchar** AddDate(uchar** list, int contactIndex);

#endif // !CREATE_H


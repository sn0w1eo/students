#ifndef MEMORY_H
#define MEMORY_H

//C������ � unsigned char.
typedef unsigned char uchar;

//���������������� ������ "��������� ����� ������" (������ ���������� �� ���������).
void* GetMemory(uchar** list);

//�������� ��� ���������� ��� ��������� ������.
void FreeMemory(uchar** list);

#endif // !MEMORY_H

#include "windows.h"

#ifndef WINDOWS
#define WINDOWS

void createWindowElements(HWND hwnd);					//�������� ���� ��������� ����
void openAndCreateBD();									//�������� � �������� ��
void addButton(HWND hwnd);								//��������� ������ add
void printPhoneOfPerson(HWND hwnd);						//���������� ������ ������� � ��			
void InitListBox(HWND hwndListBox);						//��������� listBox �������
void deleteButton(HWND hwnd);							//��������� ������ delete
void updateButton(HWND hwnd);							//��������� ������ update

#endif 


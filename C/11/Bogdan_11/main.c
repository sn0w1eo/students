#include "stdio.h"
#include "database.h"

int main() {
	
	//��������� �� ��� ���� ������ 
	person* book = NULL;

	//���������� ��� ����� ������
	char key;
	char inputName[20] = { 0x00 };
	char inputNumber[20] = { 0x00 };
	char inputEmail[32] = { 0x00 };
	char inputZip[20] = { 0x00 };

	do {
		//������ �����
		printInstruction();
		key = getch();
		system("cls");
		switch (key)
		{

		//�������� �������
		case 'a':
		case 'A':
			system("cls");
			printf("Name: ");
			scanf_s("%s", inputName, 20);
			printf("Number: ");
			scanf_s("%s", inputNumber, 20);
			printf("Email: ");
			scanf_s("%s", inputEmail, 32);
			printf("ZIP: ");
			scanf_s("%s", inputZip, 20);
			
			//��������� ������ � ���������� ���� ������
			book = initStorage(book);
			addNumber(book, inputName, inputNumber, inputEmail, inputZip);
			system("cls");
			break;

		//�������� ��� ��������
		case 's':
		case 'S':
			printContacts(book);
			getch();
			system("cls");
			break;

		//����� ������� �� ���������� (������������� enum � callback)
		case 'w':
		case 'W':
			system("cls");
			printf("By what parameters do you want to find a contact?\n"
				"<1> - by name\n"
				"<2> - by number\n"
				"<3> - by email\n"
				"<4> - by ZIP\n"
				"___________________\n");

			char parameter;
			
			parameter = getch() - 48;
			switch (parameter)
			{
			case NAME:
				showContact(book, findName(book));
				getch();
				system("cls");
				break;
			
			case NUMBER:
				showContact(book, findNumber(book));
				getch();
				system("cls");
				break;

			case EMAIL:
				showContact(book, findEmail(book));
				getch();
				system("cls");
				break;

			case ZIP:
				showContact(book, findZip(book));
				getch();
				system("cls");
				break;
			}
			break;

			//�������� ��������
		case 'd':
		case 'D':
			deleteContact(book, findName(book));
			getch();
			system("cls");
			break;

			//�����
		case 'q':
		case 'Q':
			freeContacts(book);
			return 0;
		}
	} while (1);
}
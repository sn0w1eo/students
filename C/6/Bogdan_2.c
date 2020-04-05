#include "windows.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define xMax  39
#define yMax  19
#define ESC   0x1B
#define LEFT  0xE04B
#define RIGHT 0xE04D
#define UP    0xE048
#define DOWN  0xE050


//�ҨԠ ��󷤷�
void position(int x, int y) {
	COORD coordinat = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinat);
}


//�ҨԠ ���
void color(int ColorNumber) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ColorNumber);
}

//���֦ ��Ʒ
void Display(int x, int y)

{
	position(x, y);
	color(13);

	//����� ��Է��
	for (int i = 0; i < xMax; i++)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"�" ����� � Է���� ��Է��
		x++;
	}

	//���� ��Է��
	for (int i = 0; i < yMax; i++)
	{
		position(x, y);
		printf("\xB3");		//179	B3	10110011	"�" ���� ��Է��
		y++;
	}

	//շ���� ��Է��
	for (int i = xMax; i > 0; i--)
	{
		position(x, y);
		printf("\xC4");		// 96	C4	11000100	"�" ����� � Է���� ��Է��
		x--;
	}

	//���
	position(0, 0);
	printf("\xDA");			//218	DA	11011010  "�"	Ш�� ��Է� ���
	position(xMax, 0);           	
	printf("\xBF");			//191	BF	10111111  "�"   ��Է� ���� ��� 
	position(xMax, yMax);
	printf("\xD9");			//217	D9	11011001  "�"	���� Է�Է� ���
	position(0, yMax);           
	printf("\xC0");			//192	C0	11000000  "�"   Է�Է� Ш�� ���
} 

//���֦ Ҡ��� � ������������ҷ ���ҷ
void PrintMassiv(int Massiv[][xMax - 1]){

	position(0, 1);
	for (int y = 0; y < yMax - 1 ; y++) {
		for (int x = 0; x < xMax - 1 ; x++) {
			if (x == 0)
			{
				color(13);
			}
			else if (Massiv[y][x] == '#')
			{
				color(12);
			}
			else if (Massiv[y][x] == '*')
			{
				color(11);
			}
			else if (Massiv[y][x] == '@')
			{
				color(10);
			}
			else if (Massiv[y][x] == 0xF9)
			{
				color(14);
			}
			printf("%c", Massiv[y][x]);
		}
		printf(" \n");
	}
	}



int main() {

	char FirstName[20] = { 0x00 };
	char LastName[20] = { 0x00 };
	char NickName[20] = { 0x00 };
	int Steps, Blocks, x = 0, y = 0;
	int Massiv[yMax-1][xMax-1];
	unsigned int vvod;
	int stroka = 0, stolb = 1;
	int lable = 1;
	int BeginnerSteps;
	srand(time(NULL));


	//��֦ �����
	printf("first Name: ");
	gets(FirstName);
	printf("\nlastName: ");
	gets(LastName);
	printf("\nnick Name: ");
	gets(NickName);
	printf("\nWelcome %s \"%s\" %s\n", FirstName, NickName, LastName);
	printf("Blocks: ");
	scanf_s("%d", &Blocks);
	printf("Steps: ");
	scanf_s("%d", &Steps);
	BeginnerSteps = Steps;
	Display(x, y);
	position(x, yMax + 2);
	color(14);
	printf("STEPS: %d", Steps);
	system("cls");

	//�����ԨԷ� Ӡ��� ��֢�Рҷ
	for (int y = 0; y < yMax - 1 ; y++) {
		for (int x = 0; x < xMax - 1; x++) {
			Massiv[y][x] = ' ';
		}
		if (x == 0)
		{
			Massiv[y][x] = 0xB3;              //  179	B3	10110011	"�" Ш�� ��Է��
		}
	}


	//�����ԨԷ� Ҡ��� @
	for (int i = 1; i > 0; i--)
	{

		y = rand() % (yMax -1);
		x = rand() % (xMax -1);
		if (x == 0 || (x == 1 && y == 0))   //�����Ơ Ԡ ��Է�� � Ԡ������ �ШҨ��
		{
			++i;
			continue;
		}
		Massiv[y][x] = '@';
	}


	//�����ԨԷ� Ҡ��� *
	Massiv[0][1] = '*';


	//����ԨԷ� Ҡ��� (#)
	for (int i = Blocks; i > 0; i--)
	{
		y = rand() % (yMax-1 );
		x = rand() % (xMax -1);
		if (x == 0 || (x == 1 && y == 0) || Massiv[y][x] == '@' || Massiv[y][x] == '#') {         //�����Ơ Ԡ ��Է��, Ԡ������ �ШҨ��, ��Է� � �������� ����
			++i;
			continue;
		}
		Massiv[y][x] = '#';
	}

	//���֦ ��Ԡ�����֬ Ҡ���
	Display(0,0);
	PrintMassiv(Massiv);


	
	do
	{

		vvod = _getch();

		if (vvod == 0xE0)
		{
			vvod = vvod << 8;
			vvod = vvod | _getch();
		}
		//�����Ơ ������
		switch (vvod)
		{
		case RIGHT: 
			//�����Ơ Ԡ ��Է�� � ���Ʒ
			if ((Massiv[stroka][stolb + 1] == '#') || (stolb+1==xMax-1))
		{
			break;
		}


			else
		{
			Massiv[stroka][stolb] = 0xF9;                  //�Ԡ� ���Ʒ
			if (Massiv[stroka][stolb + 1] == '@') {        //�����Ơ Ԡ ��Է�
				lable = 0;
			}
			++stolb;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);                                 //���֦ ��Ʒ
			PrintMassiv(Massiv);                           //���֦ Ҡ���
			Steps--;
			position(0, yMax + 2);                         //���֦ ���-� �����
			color(14);
			printf("STEPS: %d  ", Steps);
			break;

		}
		case LEFT:
			if (Massiv[stroka][stolb - 1] == '#' || (stolb - 1 == 0))
		{
			break;
		}


			 else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka][stolb - 1] == '@')
				lable = 0;
			--stolb;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}

		case UP:
			if (Massiv[stroka - 1][stolb] == '#' || (stroka - 1 == -1))

		{
			break;
		}


			else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka-1][stolb ] == '@')
				lable = 0;
			--stroka;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}

		case DOWN:
			if (Massiv[stroka + 1][stolb] == '#' || (stroka + 1 == yMax - 1))

		{
			break;
		}


		   else
		{
			Massiv[stroka][stolb] = 0xF9;
			if (Massiv[stroka-1][stolb ] == '@')
				lable = 0;
			++stroka;
			Massiv[stroka][stolb] = '*';
			Display(0, 0);
			PrintMassiv(Massiv);
			Steps--;
			position(0, yMax + 2);
			color(14);
			printf("STEPS: %d  ", Steps);
			break;
		}


		}
		if (vvod == ESC) {
			position(0, yMax+2);
			color(13);
			printf("Ok buddy. Cya next time...");
			_getch();
			return;
		}

	} while (Steps !=0 && lable!=0);

	
	if (lable == 0)
	{
		position(0, yMax+2);                                                        
		color(10);
		printf("Congratulations! You've won! Steps: %d/%d ",Steps,BeginnerSteps);
	}
	else
	{

		position(0, yMax + 2);
		color(12);
		printf("You've failed. Try ur luck next time");
	}


	_getch();
}

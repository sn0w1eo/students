#include "stdio.h"

	int main() 
	{
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		unsigned char sim;
		int number1, number2, add, sub, mul,mod;
		decor();
		printf("\nPress any key... ");
		sim = getch();
		drawTableASCII(sim);
		printf("\nEnter 2 numbers...");
		scanf_s("%d %d",&number1,&number2);
		add = number1 + number2;
		sub = number1 - number2;
		mul = number1 * number2;
		double div = (double)number1 / (double)number2;
		mod = number1 % number2;
		drawTableMathActions(add,sub,mul,div,mod);
		printf("\nComplete 100%%\n");
		
	}
	int decor ()
	{
		printf(" �������XXXELUS�������\n");
	}
	int drawTableASCII(unsigned char sim) 
	{
		printf("\n��������������������������������ͻ");//�����(1 ��ப�)(Up,First line)
		printf("\n� ASCII � DEC �  HEX  �    BIN   �");// 2 ��ப�(Left border 2 line)
		printf("\n��������������������������������͹ ");// 3 ��ப�(3 line)
		printf("\n�%7c�%5d�%7x�   %d%d%d%d%d%d%d�", sim, sim, sim, sim >> 7, (sim >> 6) % 2,
			(sim >> 5) % 2, (sim >> 4) % 2, (sim >> 3) % 2,
			(sim >> 2) % 2, (sim >> 1) % 2, sim % 2); //��������� �� ���⮢� ��ࠢ� � ����� �� ����� �� 2.�����㥬 १����(1 ��� 0)
		printf("\n��������������������������������ͼ");//5 ��ப�(5 line)
	}
	int drawTableMathActions(int add,int sub,int mul,double div,int mod) 
	{
		printf("\n���������������������������������������ͻ");//�����(1 ��ப�)(Up,First line)
		printf("\n�  ADD  �  SUB  �  MUL  �  DIV  �  MOD  �");//2 line
		printf("\n���������������������������������������͹");
		printf("\n�%7d�%7d�%7d�%7.1f�%7d�", add, sub, mul,div,mod);
		printf("\n���������������������������������������ͼ");//5 ��ப�(5 line)
	}
	
	
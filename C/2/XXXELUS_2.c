#include "stdio.h"

	int main() 
	{
		SetConsoleCP(866);
		SetConsoleOutputCP(866);
		char sim;
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
		printf(" ░░░▒▒▓▓XXXELUS▓▓▒▒░░░\n");
	}
	int drawTableASCII(char sim) 
	{
		
		printf("\n╔═══════╦═════╦═══════╦══════════╗");//Вверх(1 строка)(Up,First line)
		printf("\n\xBA ASCII \xba DEC \xba  HEX  \xba    BIN   \xba");// 2 строка(Left border 2 line)
		printf("\n╠═══════╬═════╬═══════╬══════════╣ ");// 3 строка(3 line)
		printf("\n\xba%7c\xba%5d\xba%7x\xba   EMPTY  \xba", sim, sim, sim);//4 строка(4 line)
		printf("\n╚═══════╩═════╩═══════╩══════════╝");//5 строка(5 line)
	}
	int drawTableMathActions(int add,int sub,int mul,double div,int mod) 
	{
		printf("\n╔═══════╦═══════╦═══════╦═══════╦═══════╗");//Вверх(1 строка)(Up,First line)
		printf("\n\xBA  ADD  \xba  SUB  \xba  MUL  \xba  DIV   \xba  MOD  \xba");//2 line
		printf("\n╠═══════╬═══════╬═══════╬═══════╬═══════╣");
		printf("\n\xba%7d\xba%7d\xba%7d\xba%6.1f\xba%8d\xba", add, sub, mul,div,mod);
		printf("\n╚═══════╩═══════╩═══════╩═══════╩═══════╝");//5 строка(5 line)
	}
	
	
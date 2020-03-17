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
		printf(" ฐฐฐฑฑฒฒXXXELUSฒฒฑฑฐฐฐ\n");
	}
	int drawTableASCII(unsigned char sim) 
	{
		printf("\nษอออออออหอออออหอออออออหออออออออออป");//ขฅเๅ(1 แโเฎช )(Up,First line)
		printf("\nบ ASCII บ DEC บ  HEX  บ    BIN   บ");// 2 แโเฎช (Left border 2 line)
		printf("\nฬอออออออฮอออออฮอออออออฮออออออออออน ");// 3 แโเฎช (3 line)
		printf("\nบ%7cบ%5dบ%7xบ   %d%d%d%d%d%d%dบ", sim, sim, sim, sim >> 7, (sim >> 6) % 2,
			(sim >> 5) % 2, (sim >> 4) % 2, (sim >> 3) % 2,
			(sim >> 2) % 2, (sim >> 1) % 2, sim % 2); //ขจฃ ฅฌแ๏ ฏฎ ก ฉโฎขฎ ขฏเ ขฎ จ คฅซจฌ ฏฎ ฌฎคใซ๎ ญ  2. ฏจแใฅฌ เฅงใซ์โ โ(1 จซจ 0)
		printf("\nศอออออออสอออออสอออออออสออออออออออผ");//5 แโเฎช (5 line)
	}
	int drawTableMathActions(int add,int sub,int mul,double div,int mod) 
	{
		printf("\nษอออออออหอออออออหอออออออหอออออออหอออออออป");//ขฅเๅ(1 แโเฎช )(Up,First line)
		printf("\nบ  ADD  บ  SUB  บ  MUL  บ  DIV  บ  MOD  บ");//2 line
		printf("\nฬอออออออฮอออออออฮอออออออฮอออออออฮอออออออน");
		printf("\nบ%7dบ%7dบ%7dบ%7.1fบ%7dบ", add, sub, mul,div,mod);
		printf("\nศอออออออสอออออออสอออออออสอออออออสอออออออผ");//5 แโเฎช (5 line)
	}
	
	
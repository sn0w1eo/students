#include "stdio.h"
#include "windows.h"
#include "conio.h"

#define	Red			 4;
#define Yellow       14;

//3, ���ਪ
__declspec(dllexport) void f3() {
	system("cls");
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	printf("�� ���ਪ!\n");
	printf(" _______________________$$$$ \n"
		   "_____________________$$____$ \n"
		   "____________________$______$ \n"
		   "___________________$_______$ \n"
		   "__________________$________$ \n"
		   "_________________$____$__$_$ \n"
		   "________________$_________$$ \n"
		   "________________$_____$$___$ \n"
		   "_______________$______$$$$__$$ \n"
		   "_______________$_____$____$$__$ \n"
		   "______________$_____$$$$$$$$$$$ \n"
		   "______________$_____$______$___$ \n"
		   "______________$______$___o_$_o_$ \n"
		   "______________$_______$___$$___$ \n"
		   "_____________$___$$____$$$__$$$$ \n"
		   "____________$______$$$$$$$$$$$$$$$ \n"
		   "_________$$$____________________$ \n"
		   "_______$$________________________$$$ \n"
		   "_____$$___________________________$_$$ \n"
		   "____$______$$________________$$____$__$$ \n"
		   "__$$________________________________$___$$ \n"
		   "_$___________$_______________________$____$ \n"
		   "_$__________$_____________$$________$_$____$ \n"
		   "$_________$$___________________________$__$_$ \n"
		   "$_______$$_____________________________$___$_$ \n"
		   "$_$____$__________________________$$$__$$____$ \n"
		   "$_____$$$$$$_________________________$$$_$$$$ \n"
		   "_$$__$_$____$$$$$$$$$$_________$$$$$$$$$ \n"
		   "___$$___$_____________$$$$$$$$$_______$$ \n"
		   "_________$$________________$__$$___$$$_$ \n"
		   "_________$$_________________$$_$____$_$ \n"
		   "_________$$$$$_________$________$$$___$ \n"
		   "_________$$___$________$$$$__________$ \n"
		   "__________$$$$_____$$$$____$$$$$$$$$$ \n"
		   "___________$$_$$$$$__$______$____$_$ \n"
		   "____________$$______$________$__$_$ \n"
		   "______________$$$$$$__________$$$$ \n");
}



//2, ��䨪� ᯠ�� ���
__declspec(dllexport) void f2() {
	system("cls");
	HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("�� ����� ��� ������� �⠭�!\n"
"      .--..--..--..--..--..--.\n"
"    .' \  (`._   (_)     _   \ \n"
"  .'    |  '._)         (_)  | \n"
"  \ _.')\      .----..---.   / \n"
"  |(_.'  |    /    .-\-.  \  | \n"
"  \     0|    |   ( O| O) | o| \n"
"   |  _  |  .--.____.'._.-.  | \n"
"   \ (_) | o         -` .-`  | \n"
"    |    \   |`-._ _ _ _ _\ / \n"
"    \    |   |  `. |_||_|   | \n"
"    | o  |    \_      \     |     -.   .-. \n"
"    |.-.  \     `--..-'   O |     `.`-' .' \n"
"  _.'  .' |     `-.-'      /-.__   ' .-' \n"
".' `-.` '.|='=.='=.='=.='=|._/_ `-'.' \n"
"`-._  `.  |________/\_____|    `-.' \n"
"   .'   ).| '=' '='\/ '=' | \n"
"   `._.`  '---------------' \n"
"           //___\   //___\ \n"
"             ||       || \n"
"             ||_.-.   ||_.-. \n"
"            (_.--__) (_.--__) \n"
"------------------------------------------------");

	
				
}




//1, ��� sponge bob
__declspec(dllexport) void f1() {
	int fDig,
		sDig,
		thDig,
		fvDig;

	printf("� �⮬ ��� �� 㧭���� �� �� �� ���⨪� ����� ���\n");
	printf("------------------------------------------------------\n");

	printf("\t\t����� 梥� ⥡� �ࠢ���� �����?\n");
	printf("����� (1) \t �����(2)\n");
	scanf_s("%d", &fDig);
	

	printf("\t\t����� �� ����� ���� �� �롥���?\n");
	printf("����ਬ����, �������� (1) \t ��娩 ᯮ����� ����\n");
	scanf_s("%d", &sDig);
	

	printf("\t\t��� � ⥡� � ᯮ�⮬?\n");
	printf("����� - ��� ����! \t � � ᯮ�� ����� ����\n");
	scanf_s("%d", &thDig);


	printf("\t\t�� �� � �⭮襭�� ࠡ���?\n");
	printf("������ \t ��㤮�����\n");
	scanf_s("%d", &fvDig);


	if (fDig == 1 && sDig == 2 && thDig == 2 && fvDig == 2) {
		printf("�� ����� ���!\n");
			f2();
	}
	else if(fDig == 1 && sDig == 1 && thDig == 2 && fvDig == 2) {
		printf("�� ����� ���!\n");
		f2();
	}
	else if (fDig == 2 && sDig == 2 && thDig == 2 && fvDig == 2) {
		printf("�� ����� ���!\n");
		f2();
	}
	else if (fDig == 1 && sDig == 1 && thDig == 1 && fvDig == 2) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 1 && sDig == 1 && thDig == 1 && fvDig == 1) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 2 && sDig == 1 && thDig == 1 && fvDig == 2) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 1 && sDig == 2 && thDig == 1 && fvDig == 2) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 1 && sDig == 2 && thDig == 1 && fvDig == 2) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 2 && sDig == 1 && thDig == 2 && fvDig == 1) {
		printf("�� ���ਪ!\n");
		f2();
	}
	else if (fDig == 1 && sDig == 2 && thDig == 2 && fvDig == 1) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig == 2 && sDig == 2 && thDig == 1 && fvDig == 2) {
		printf("�� ���ਪ!\n");
		f3();
	}
	else if (fDig >= 2 && sDig >=2 && thDig >= 2 && fvDig >= 2) {
		printf("���஡� �� ࠧ\n");
	}

	system("pause");

}
			 

int main() {
	system("chcp 866>nul");

	f1();
}
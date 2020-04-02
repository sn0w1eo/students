#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "windows.h"

#define COLOR(color) { SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color); }
	

void printAllFunctions() 
{
	printf("\n�� �㭪樨:\n");
	puts("#1  itoa ");
	puts("#2  ltoa");
	puts("#3  gcvt");
	puts("#4  atoi");
	puts("#5  atol");
	puts("#6  strtol");
	puts("#7  strtod");
	puts("\n�㭪樨 string.h\n");
	puts("#8  strlen");
	puts("#9  strcmp");
	puts("#10 strncmp");
	puts("#11 strcpy");
	puts("#12 strncpy");
	puts("#13 strcat");
	puts("#14 strncat\n");
	puts("������ ����� �㭪�� �� �� ��ᬮ���� �� ��� �믮����\n");
	
}
int main() 
{
	system("chcp 866>nul");
	char help[] = { "help" };
	char exitconsole[] = { "exit" };
	char input[10];
	char number;
	int Check=0;
	puts("�ணࠬ�� ��� �஢�ન �㭪権...");
	puts("������ help ��� �ࠢ�� ��� exit ��� ��室�...");
		while (Check!=1) 
		{
			gets(input);
			int EXITconsole = strcmp(exit, input);
			int HELP = strcmp(help, input);
			if (EXITconsole == 0) 
			{
				
				return 0;
			}
			else
			{
				if (EXITconsole > 0 || HELP>0)
				{
					puts("�������᭠� �������!���஡�� �� ࠧ");
				}
			}
			if (HELP == 0) 
			{
				Check ++;
				if (HELP > 0) {
					printAllFunctions();
				}
			}
			
		}
		printAllFunctions();
		
		do 
		{
			scanf("%d",&number);
			switch (number)
			{
			case 1:
				COLOR(0x0E);
				puts("#1 itoa - �㭪�� itoa (i-int)(a-ascii) �८�ࠧ�� 楫�� �᫮ n � ��ப� str � �ଠ� rad. ���ᨬ��쭠� ����� 17 ����\n");
				COLOR(0x07);
				char buffer_It[18];
				int value_It,rad_It;	
				printf("������ �᫮: ");
				scanf("%d",&value_It);
				printf("������ �᭮����� ��⥬� (�᫮ �� 2 �� 36):");
				scanf("%d", &rad_It);
				_itoa_s(value_It, buffer_It, _countof(buffer_It),rad_It);
				COLOR(0x0A);
				printf("��᫮ ���஥ �� ����� %d � ��⥬� � �᭮������ %d ����� ���: %s\n",value_It,rad_It,buffer_It);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 2:
				COLOR(0x0E);
				puts("#2 ltoa - �㭪�� ltoa (l-long)(a-ascii) ⮦� ᠬ�� �� � itoa .�८�ࠧ�� 楫�� �᫮ n � ��ப� str � �ଠ� rad. ���ᨬ��쭠� ����� 34 ����\n");
				COLOR(0x07);
				char buffer_Lt[35];
				int value_Lt, rad_Lt;
				printf("������ �᫮: ");
				scanf("%d", &value_It);
				printf("������ �᭮����� ��⥬� (�᫮ �� 2 �� 36):");
				scanf("%d", &rad_It);
				_itoa_s(value_It, buffer_It, _countof(buffer_It), rad_It);
				COLOR(0x0A);
				printf("��᫮ ���஥ �� ����� %d � ��⥬� � �᭮������ %d ����� ���: %s\n", value_It, rad_It, buffer_It);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 3:
				COLOR(0x0E);
				puts("#3 gcvt - �㭪�� �८�ࠧ��뢠�� ���祭�� � ������饩 �窮� � ᨬ������ ��ப� � ���������� ��� ��ப� � ����.");
				COLOR(0x07);
				char buffer_Gc[50];
				double value_Gc;
				printf("������ �᫮: ");
				scanf("%f", &value_It);
				_gcvt(value_It,4,buffer_It);
				COLOR(0x0A);
				printf("�८�ࠧ������� �᫮: %s\n", buffer_It);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 4:
				COLOR(0x0E);
				puts("#4 atoi - �㭪�� atoi (a-ASCII)(i-int) �ᯮ������ ��� �ਢ������ (�������樨) ��ப� � �᫮��� ���. ��ப� ������ ᮤ�ঠ�� 楫�� �᫮");
				COLOR(0x07);
				char buffer_Atoi[] = { "4554pussy" };
				int result = atoi(buffer_Atoi);
				COLOR(0x0A);
				printf("������� �������樨: ��ப� %s � �� 楫�� ���� %d\n", buffer_Atoi,result);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 5:
				COLOR(0x0E);
				puts("#5 atol - �㭪�� atol (a-ASCII)(l-long int) �ᯮ������ ��� �ਢ������ (�������樨) ��ப� � �᫮��� ���. ��ப� ������ ᮤ�ঠ�� 楫�� �᫮");
				COLOR(0x07);
				char buffer_Atol[] = { "652.23brrt" };
				long int Num = 0;           
				Num = atol(buffer_Atol);
				COLOR(0x0A);
				printf("������� �������樨: ��ப� %s � �� �᫥���� ���� %d\n", buffer_Atol, Num);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 6:
				COLOR(0x0E);
				puts("#6 strtol - �㭪�� �८�ࠧ�� ��ப���� �।�⠢����� �᫠, ���஥ ᮤ�ন��� � ��ப�, � ���祭�� ⨯� long int.");
				COLOR(0x07);
				char buffer_strtol[] = {"228228pussy"};
				puts("������ ��ப� � �᫥��묨 ���祭�ﬨ � ��砫�: ");			
				long int Number = strtol(buffer_strtol, NULL, 10);
				COLOR(0x0A);
				printf_s("������� �������樨: ��ப� %s � �� �᫥���� ���� %d\n", buffer_strtol,Number);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 7:
				COLOR(0x0E);
				puts("#7 strtod - �㭪�� �८�ࠧ�� ��ப���� �।�⠢����� �᫠, ���஥ ᮤ�ন��� � ��ப�, � ���祭�� ⨯� double.");
				COLOR(0x07);
				char buffer_strtod[50] = { "228.228pussy" };
				double number = strtod(buffer_strtod, NULL, 10);
				COLOR(0x0A);
				printf_s("������� �������樨: ��ப� %s � �� �᫥���� ���� %.2lf\n",buffer_strtod, number);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			//string.h

			case 8:
				COLOR(0x0E);
				puts("#8 strlen - �㭪�� strlen ������ ������⢮ ᨬ����� � ��ப�.");
				COLOR(0x07);
				char buffer_strlen[10];
				printf("������ �ந������� ��ப�:");
				scanf("%s", &buffer_strlen, 10);
				int result_len = strlen(buffer_strlen);
				COLOR(0x0A);
				printf("������⢮ ᨬ����� � �������� ��ப�: %d\n", result_len);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 9:
				COLOR(0x0E);
				puts("#9 strcmp - �㭪�� strcmp �ࠢ������ 2 ��ப�. �����頥� 0, �᫨ ��ப� ���������, ������⥫쭮�, �᫨ ��ࢠ� ��ப� �����, � ����⥫쭮�, �᫨ �����");
				COLOR(0x07);
				char first[10];
				char second[10];
				printf("������ ����� ��ப�:");
				scanf("%s", &first, 10);
				printf("������ ����� ��ப�:");
				scanf("%s", &second, 10);
				int result_cmp = strcmp(first, second);
				if (result_cmp == 0) 
				{
					COLOR(0x0A);
					printf("��ப� ࠢ��\n");
					COLOR(0x07);
				}
				else if (result_cmp == 1) 
				{
					COLOR(0x0A);
					printf("��ࢠ� ��ப� ����� ��ன\n");
					COLOR(0x07);
				}
				else 
				{
					COLOR(0x0A);
					printf("���� ��ப� ����� ��ࢮ�\n");
					COLOR(0x07);
				}
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;
			
			case 10:
				COLOR(0x0E);
				puts("#10 strncmp - �㭪�� strncmp �ࠢ������ ���� n ���⮢ ��ப");
				COLOR(0x07);
				char first_n[20];
				char second_n[20];
				int n;
				printf("������ ����� ��ப�:");
				scanf("%s", &first_n, 20);
				printf("������ ����� ��ப�:");
				scanf("%s", &second_n, 20);
				printf("������ �� ������ ���� �஢�����:");
				scanf("%d", &n);
				strncmp(first_n, second_n, n);
				int result_ncmp = strcmp(first_n, second_n);
				if (result_ncmp == 0)
				{
					COLOR(0x0A);
					printf("���� %d �㪢(�) ��ப ࠢ��!\n",n);
					COLOR(0x07);
				}
				else
				{
					COLOR(0x0A);
					printf("���� %d �㪢(�) ��ப �� ࠢ��!\n", n);
					COLOR(0x07);
				}
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 11:
				COLOR(0x0E);
				puts("#11 strcpy - �㭪�� strcpy ������� ��ப� �� ������ ���� � ��㣮�");
				COLOR(0x07);
				char src[24] = "��� ��������";
				char dst[24] = "";	
				strcpy(dst, src);
				COLOR(0x0A);
				printf("src: % s % s\n", src, &src[14]);
				printf("dst: %s %s\n", dst, &dst[14]);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 12:
				COLOR(0x0E);
				puts("#12 strncpy - �㭪�� strncpy ������� �� n ���� ��ப� �� ������ ���� � ��㣮� ");
				COLOR(0x07);
				char* str = "��ࠧ�� ��ப�";
				char  buf[10] = { 0 };                  
				COLOR(0x0A);
				printf("��ப�: \"%s\"\n\n", str);
				printf("���� ��। ����஢�����: \"%s\"\n", buf);
				strncpy(buf, str, sizeof(buf) - 1); 
				printf("���� ��᫥ ����஢����:  \"%s\"\n", buf);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 13:
				COLOR(0x0E);
				puts("#13 strcat - �㭪�� strcat �����뢠�� ���� ��ப�  � ����� ��㣮� ");
				COLOR(0x07);
				char firstStr[] = "C";
				char secondStr[] = "_����ᠫ�";
				COLOR(0x0A);
				printf("��ࢠ� ��ப�:%s\n", firstStr);
				strcat(firstStr,secondStr);
				printf("���� ��ப�:%s\n", secondStr);
				printf("�������: %s\n",firstStr);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 14:
				COLOR(0x0E);
				puts("#14 strncat - �㭪�� strncat �����뢠�� �� ����� n ���� ����� ��ப� � ����� ��㣮� ");
				COLOR(0x07);
				char firstStrn[] = "C ����襬 4 ᨬ���� 2� ��ப�";
				char secondStrn[] = "_����ᠫ�";
				COLOR(0x0A);
				printf("��ࢠ� ��ப�:%s\n", firstStrn);
				strncat(firstStrn, secondStrn,4);
				printf("���� ��ப�:%s\n", secondStrn);
				printf("�������: %s\n", firstStrn);
				COLOR(0x07);
				puts("�� �� �த������ ���� ������ ����� �㭪樨. �᫨ �� ��� ��� ������ 0");
				break;

			case 0:
				exit(0);
				break;
			}
			
		
		} while (1);

		return 0;
}
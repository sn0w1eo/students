#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define STR_LEN 5

int main()
{
	//_itoa
	int number = 934;
	char string[25];
	printf("Number: ");

	//�������������� ����� ���� int � ������
	_itoa(number, string, 10); 

	//����� ���������� ��������������
	printf("int: %d, string: %s\n", number, string);

	//_ltoa
	char stringLtoa[25];
	long value = 123456789L;

	//�������������� ����� ���� long � ������
	_ltoa(value, stringLtoa, 10);

	//����� ���������� ��������������
	printf("long = %ld string: %s\n", value, stringLtoa);

	//_gcvt
	char buf[80];

	//�������������� ����� 10.12 � ������
	_gcvt(10.12, 5, buf);

	//����� ���������� ��������������
	printf("%s gcvt 10.12\n", buf);

	//atoi
	char temporaryString[STR_LEN] = { 0x00 };
	int dogs = 0;
	printf("Dogs string: ");
	scanf("%s", temporaryString);

	//�������������� ������ � ����� ���� int
	dogs = atoi(temporaryString);

	//����� ���������� ��������������
	printf("Dogs int: %d\n", dogs);

	//_atol
	char* Str = "372.23djkj"; //������ ��� ��������������
	long int Num = 0;           //���������� ��� ������ ����������

	//�������������� ������ � ����� ���� long int
	Num = atol(Str);

	//����� ���������� ��������������
	printf("372.23djkj to int %ld\n", Num);

	//strtol
	char str[30] = "5670 how r u";
	char* ptr;
	long ret;

	//����� ����� ���� long �� ������
	ret = strtol(str, &ptr, 10);
	printf("The number(unsigned long integer) is %ld\n", ret);

	//����� ��������� �����
	printf("String part is: %s\n", ptr);

	//strtod
	char strD[30] = "54.3670 I`m ok, thx";
	char* ptrD;
	double retD;
	//����� ����� ���� double �� ������
	retD = strtod(strD, &ptrD);
	printf("The number(double) is %lf\n", retD);
	printf("String part is: %s\n", ptrD);

	//strlen
	char numbers[11] = "0123456789";

	//����������� ����� ������ � ����� ���������� �� �������
	printf("String length %s - %d symbols\n", numbers, strlen(numbers));

	//strcmp

	// ������� 2 ������ ��� ���������
	printf("Input 2 strings\n");
	char str1[1024] = { 0x00 };
	scanf("%s", str1);
	char str2[1024] = { 0x00 };
	scanf("%s", str2);

	// ���������� ��� ������
	if (strcmp(str1, str2) == 0)
		printf("Strings are equal\n");
	else
		printf("Strings are different\n");

	//strncmp

	printf("Input 2 strings\n");
	char str3[1024] = { 0x00 };
	scanf("%s", str3);
	char str4[1024] = { 0x00 };
	scanf("%s", str4);

	// ���������� ������ ���� �������� ���� �����
	if (strncmp(str3, str3, 5) == 0)
		printf("The first five symbols of the strings are equal\n");
	else
		printf("The first five symbols of the strings are different\n");

	//strcpy

	// ������ �������� ������
	char src[1024] = "first string\0 second string";

	// ������ �������� ������
	char dst[1024] = " ";

	// �������� ������ �� ������� src � ������ dst 
	strcpy(dst, src);

	// ����� ������� src �� �������
	printf("src: % s % s\n", src, &src[14]);

	// ����� ������� dst �� �������
	printf("dst: % s % s\n", dst, &dst[14]);

	//strncpy
	// ������ �������� ������
	char abc[10] = "12345\0006789";

	// ������� ��������� ������
	char def[10] = "1111111111";
	char ghi[10] = "1111111111";

	// �������
	int i;

	// ����� ������� src �� �������
	printf("abc: ");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)abc[i]);
	printf("\n");

	// �������� ������ ������ �� ����� ���� �������� �� ������� abc � ������ def. 
	strncpy(def, abc, 3);

	// ����� ������� egh �� �������
	printf("def:");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)def[i]);
	printf("\n");

	// �������� ������ ������ �� ����� ���� �������� �� ������� abc � ������ ghi. 
	strncpy(ghi, abc, 7);

	// ����� ������� ghi �� �������
	printf("ghi: ");
	for (i = 0;i < 10;i++)
		printf(" %2d", (unsigned short)ghi[i]);
	printf("\n");

	//strcat

	char sec[1024] = "horosho normalno";

	// ������ �������� ������
	char fir[1024] = "privet kak dela ";

	// ��������� ������ �� ������� sec � ������ fir. 
	strcat(fir, sec);

	// ����� ������� fir �� �������
	printf("fir: % s\n", fir);

	//strncat

	// ������� � ������� ����������� ������
	char src1[10] = "000";
	char src2[10] = "000";

	// ����������� ������
	char app[10] = "12345";

	// ����� ����������� ������
	printf("app: % s\n", app);

	// ���������� ������ app � ������ src1, �� �� ����� ���� ��������
	strncat(src1, app, 3);
	// ����� ����������
	printf("src1: % s\n", src1);

	// ���������� ������ app � ������ src2, �� �� ����� ���� ��������
	strncat(src2, app, 7);
	// ����� ����������
	printf("src2: % s\n", src2);
}

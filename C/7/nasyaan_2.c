#define _CRT_SECURE_NO_WARNINGS

#include "stdio.h"
#include "windows.h"
#include "string.h"

#define RED			0x0C //красный
#define WHITE		0x07 //белый
#define LIGHTBLUE	0x0B //светло-голубой
#define YELLOW		0x06 //жёлтый
#define GREEN		0x02 //зелёный
#define CYAN		0x03 //голубой

#define WIDTH		60	 //ширина рамки
#define HEIGHT		13	 //длмна рамки

#define STR_LEN		40	 //длина строки

#define ENTER		0x0D //код клавиши Enter


// Функция чтения клавиши 
int ReadKey()
{
	unsigned int ch = getch();
	if (ch == 0xE0)
	{
		ch = ch << 8;
		ch = ch | getch();
	}
	return ch;
}
// Функция для смещения курсора
void SetPosition(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// Функция выбора цвета
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
// Функция отрисовки рамки
void DrawFrame()
{
	SetColor(LIGHTBLUE);
	int x = 0;
	int y = 0;
	for (int y = 0; y <= HEIGHT; y++)
	{
		for (int x = 0; x <= WIDTH; x++)
		{
			if (y == 0)
			{
				if (x == 0)
				{
					printf("\xDA");
				}
				else
				{
					printf("\xC4");
				}
				if (x == WIDTH)
				{
					printf("\xBF\n");
				}
			}
			if (y > 0 && y != HEIGHT && x == 0)
			{
				printf("\xB3");
			}
			else if (x == WIDTH && y != HEIGHT && y > 0)
			{
				printf(" \xB3\n");
			}
			else
			{
				if (y != 0 && y != HEIGHT)
				{

					printf(" ");
				}
			}
			if (y == HEIGHT)
			{
				if (x == 0)
				{
					printf("\xC0");
				}
				else
				{
					printf("\xC4");
				}
				if (x == WIDTH)
				{
					printf("\xD9");
				}
			}

		}
	}
	SetColor(7);
}
// Функция вычисления суммы двух чисел
int Sum(int a, int b) // в функцию передаются два целых числа
{
	return a + b;
}

// Функция смены цвета в зависимости от твоего пола
void Gender()
{
	printf("Hello, please, Enter your gender(male/female): ");
	char str1[1024] = { 0x00 };
	scanf_s("%s", str1, 1024);
	char str2[1024] = { "male" };
	char str3[1024] = { "female" };
	SetPosition(1, 2);

	if (strcmp(str1, str2) == 0)
	{
		SetColor(LIGHTBLUE);
		printf("hi, man");
	}
	else if (strcmp(str1, str3) == 0)
	{
		SetColor(RED);
		printf("hi, girl");
	}
	else
	{
		SetColor(WHITE);
		printf("hi, dolboyob");
	}
	
}

// Функция вывода стартового текста
void Text()
{
	char name[STR_LEN] = { 0x00 };
	SetPosition(1, 3);
	printf("What is your name? ");
	scanf_s("%s", name, STR_LEN);
	SetPosition(1, 4);
	printf("Nice to see you, ");
	printf("%s", name);
	SetPosition(1, 5);
	printf("Now you can enter two integers, and we`ll add them up.");

    SetColor(WHITE);
}

// Функция перехода на следующий экран
void GoToNextScreen()
{
	unsigned int ch;
	SetPosition(1, 12);
	printf("Press ENTER to go to the next step");
	while (1)
	{
		ch = ReadKey();
		if (ch == ENTER)
		{
			system("cls");
			return;
		}
	}

}

// Функция загадка
void Riddle()
{
	SetColor(YELLOW);
	printf("What has a face and two hands but no arms or legs? ");
	char answer[1024] = { 0x00 };
	scanf_s("%s", answer, 1024);
	char trueAnswer[1024] = { "clock" };
	SetPosition(1, 4);
	if (strcmp(answer, trueAnswer) == 0)
	{
		printf("Yes!\n");
	}
	else
	{
		printf("No! The correct answer is \"clock\".\n");
	}
		
		
}

// Функция вторая загадка
void SecondRiddle()
{
	SetColor(GREEN);
	printf("Mary's father has five daughters - Nana, Nene, Nini, Nono.");
	SetPosition(1, 7);
	printf("What is the fifth daughter's name? ");
	char answ[1024] = { 0x00 };
	scanf_s("%s", answ, 1024);
	char trueAnsw[1024] = { "Mary" };
	SetPosition(1, 8);
	if (strcmp(answ, trueAnsw) == 0)
	{
		printf("Yes!)\n");
	}
	else
	{
		printf("No! The correct answer is \"Mary\".\n");
	}
}

// Функция третья загадка
void ThirdRiddle()
{
	SetColor(CYAN);
	printf("If I drink, I die.If I eat, I am fine.What am I ? ");
	char thirdAnswer[1024] = { 0x00 };
	scanf_s("%s", thirdAnswer, 1024);
	char thirdTrueAnswer[1024] = { "fire" };
	SetPosition(1, 11);
	if (strcmp(thirdAnswer, thirdTrueAnswer) == 0)
	{
		printf("Yes!!!\n");
	}
	else
	{
		printf("No:(. The correct answer is \"fire\".\n");
	}

	SetPosition(1, 14);

}


int main()
{
	int a, b, sum;
	DrawFrame();
	SetPosition(1, 1);
	Gender();
    Text();
	SetPosition(1, 6);
    printf("a=");
    scanf_s("%d", &a); 
	SetPosition(1, 8);
    printf("b=");
    scanf_s("%d", &b); 
	SetPosition(1, 9);
	printf("a+b=");
	sum = Sum(a, b);
	printf("%d", sum);
	GoToNextScreen();
	DrawFrame();
	SetPosition(1, 1);
	printf("Now I`m going to give you three little riddles.");
	SetPosition(1, 3);
	Riddle();
	SetPosition(1, 6);
	SecondRiddle();
	SetPosition(1, 10);
	ThirdRiddle();

    return 0; 
}
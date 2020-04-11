#include "stdio.h"
#include "windows.h"
#include "stdlib.h"
#include "time.h"

// создать игровое поле
void MakeGameField(unsigned char krissKross[3][3]);
//проверить все ряды на наличие одинаковых знаков
unsigned char CheckThreeMark(unsigned char krissKross[3][3]);
//определить победителя
int ItsVictory(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char computerMark);
// ход компьютера
void ComputerMove(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char aiMark);
//Проверка на правильность хода, не занята ли уже ячейка
int  CheckMove(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char aiMark, int x, int y);
// отобразить игровое поле
void DisplayGameField(unsigned char krissKross[3][3]);
//нарисовать крестик
void DrawKriss(int x, int y);
//нарисовать нолик
void DrawKross(int x, int y);
//нарисовать пробел
void DrawBlank(int x, int y);
// установить курсор
void SetConsoleCursor(int x, int y);
//установить цвет
void SetColor(int color);
//нарисовать рамку
void DisplayFrame();
//изобразить хоткеи
void ShowHotkeys();
//звук хода игрока
void SoundPlayerMove();
//звук хода компьютера
void SoundComputerMove();
//звук неверного хода
void SoundWrongMove();
//звук неверно нажатой клавиши
void SoundWrongKey();
//звук при победе
void SoundWin();
//звук при проигрыше
void SoundLose();
//звук ничьей
void SoundDeadHeat();
//звук при ливе из игры
void SoundESC();
//спрятать курсор
void HideCursor();

int main()
{
	unsigned char krissKross[3][3], key = 0, playerMark = 'X', computerMark = 'O';
	int checkMove, countMove = 0, checkVictory = 0;
	//запуск игры		
	MakeGameField(krissKross);
	HideCursor();
	DisplayGameField(krissKross, playerMark, computerMark);
	DisplayFrame();
	ShowHotkeys();

	//checkVictory что то вроде флага , пока функция ItsVictory возвращает 0, цикл не прекращается 
	while (checkVictory == 0)
	{

		key = getch();
		
		switch (key)
		{
		case 'q':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 0, 0);			
			if (checkMove == 1)
			{
				continue;
			}
			SoundPlayerMove();
			break;

		case 'w':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 0, 1);			
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'e':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 0, 2);			
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'a':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 1, 0);			
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 's':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 1, 1);
			
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'd':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 1, 2);
			SoundPlayerMove();
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'z':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 2, 0);
			SoundPlayerMove();
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'x':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 2, 1);
			SoundPlayerMove();
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;

		case 'c':
			checkMove = CheckMove(krissKross, playerMark, computerMark, 2, 2);
			SoundPlayerMove();
			if (checkMove == 1)
			{
				SoundWrongMove();
				continue;
			}
			SoundPlayerMove();
			break;
			//если нажата клавиша ESC - завершить выполнение программы.
		case 27: //27 = ESC
			SetConsoleCursor(15, 22);
			SetColor(11);
			printf_s("Ok, buddy. Cya next time...");
			SoundESC();
			return 0;	
			//если нажата неверная клавиша, сообщить об этом пользователю
		default:
			SetConsoleCursor(15, 24);
			SetColor(14);			
			printf_s("It seems you enter the wrong keys... hm ... try to chang the layout");
			SoundWrongKey();
			Sleep(1000);
			SetConsoleCursor(15, 24);
			printf_s("                                                                        ");
			break;
		}
		//заблокировать приём других нажатий на клавишу
		if (key == 'q' || key == 'w' || key == 'e' || key == 'a' || key == 's' || key == 'd' || key == 'z' || key == 'x' || key == 'c')
		{
			//проверка на победу игрока
			DisplayGameField(krissKross, playerMark, computerMark);
			checkVictory = ItsVictory(krissKross, playerMark, computerMark);
			//счётчик ходов
			countMove++;
			if (checkVictory == 1)
			{
				return 0;
			}
			//ход компьютера и проверка на его победу
			ComputerMove(krissKross, computerMark, playerMark);
			checkVictory =  ItsVictory(krissKross, playerMark, computerMark);
			if (checkVictory == 2)
			{
				return 0;
			}
			//это условие выполнится только если достигнется максимальное количество ходов и никто не победит
			if (countMove == 5)
			{
				SetConsoleCursor(10, 23);
				SetColor(15);
				printf_s("Dead heat! It was an incredible battle!");
				SoundDeadHeat();
				return 0;
			}
		}
	}
}
//проверка на победу
int ItsVictory(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char computerMark)
{
	//вызвать функцию на проверку всех линий
	unsigned char checkVictory = CheckThreeMark(krissKross);
	//если функция вернула маркер игрока(X) то победил игрок
	if (checkVictory == playerMark)
	{
		SetConsoleCursor(10, 23);
		SetColor(13);
		printf_s("You won! Congratulations!");
		SoundWin();
		return 1;
	}
	//если функция вернула маркер компьютера(O) то победил компьютер
	else if (checkVictory == computerMark)
	{
		SetConsoleCursor(10, 23);
		SetColor(12);
		printf_s("You lose! Try next time! ");
		SoundLose();
		return 2;
	}
	//иначе функия вернёт 0, что говорит о том что игра ещё не окончена
	return 0;
}
//проверка на одинаковое содержимое по всем линиям
//функция возврщает O , X или *
//если какой то ряд заполнен O,возращает O, если какой то ряд заполнен X то X, иначе возвращает *
unsigned char CheckThreeMark(unsigned char krissKross[3][3])
{
	int i;
	unsigned char* check;
	//проверка строк
	for (i = 0; i < 3; i++)
	{
		check = &krissKross[i][0];
		//сравнить содержимое всех ячеек во всех "горизонталях" массива и при этом
		//не брать в учёт содержимое "пустых" ячеек
		if ((*check == *(check + 1) && *(check + 1) == *(check + 2)) && krissKross[i][0] != '*')
		{
			return *check;
		}
	}
	//проверка столбцов
	for (i = 0; i < 3; i++)
	{
		check = &krissKross[0][i];
		if ((*check == *(check + 3) && *(check + 3) == *(check + 6)) && krissKross[0][i] != '*')
		{
			return *check;
		}
	}
	///P.S не играйте, дети, с указателями !

	//проверка диагоналей
	if (krissKross[0][0] == krissKross[1][1] && krissKross[1][1] == krissKross[2][2])
	{
		return krissKross[0][0];
	}
	if (krissKross[0][2] == krissKross[1][1] && krissKross[1][1] == krissKross[2][0])
	{
		return krissKross[0][2];
	}
	return '*';
}
// создать игровое поле
void MakeGameField(unsigned char krissKross[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			krissKross[i][j] = '*';
		}
	}
}
//проверить правильность хода игрока
int  CheckMove(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char aiMark, int x, int y)
{
	if (krissKross[x][y] == aiMark || krissKross[x][y] == playerMark)
	{
		return 1;
	}
	else
	{
		krissKross[x][y] = playerMark;
	}
	return 0;
}
//непобедимый алгоритм методом Минимакс в разработке... :D
void ComputerMove(unsigned char krissKross[3][3], unsigned char aiMark, unsigned char playerMark)
{
	Sleep(250);// компьютер думает)))		
	srand(time(NULL));
	//ищет ближайшую пустую клетку начиная с [0][0] - тупейший алгоритм
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (krissKross[i][j] != playerMark && krissKross[i][j] != aiMark)
			{
				krissKross[i][j] = aiMark;				
				DisplayGameField(krissKross, aiMark, playerMark);
				SoundComputerMove();
				return;
			}
		}
	}
}

//отобразить игровое поле
void DisplayGameField(unsigned char krissKross[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (krissKross[i][j] == '*')
			{
				DrawBlank(j * 10 + 15, i * 6 + 5);
			}
			else if (krissKross[i][j] == 'X')
			{
				DrawKriss(j * 10 + 15, i * 6 + 5);
			}
			else DrawKross(j * 10 + 15, i * 6 + 5);
		}
	}
}
//нарисовать крестик
void DrawKriss(int x, int y)
{
	SetColor(12);
	for (int i = 0; i < 3; i++)
	{
		Sleep(25);
		for (int j = 0; j < 3; j++)
		{			
			SetConsoleCursor(j + x, i + y);
			if (i == 0 && j == 1)
			{
				printf_s(" ");
			}
			else if (i == 1 && j == 0 || i == 1 && j == 2)
			{
				printf_s(" ");
			}
			else if (i == 2 && j == 1)
			{
				printf_s(" ");
			}
			else printf_s("*");
		}
		printf_s("\n");
	}

}
//нарисовать нолик
void DrawKross(int x, int y)
{
	SetColor(9);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			Sleep(15);
			SetConsoleCursor(j + x, i + y);
			if (i == 1 && j == 1)
			{
				printf_s(" ");
			}
			else printf_s("*");
		}
		printf_s("\n");
	}
}
//нарисовать пробел
void DrawBlank(int x, int y)
{
	SetColor(15);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			SetConsoleCursor(j + x, i + y);
			printf_s("\xB0");
		}
	}
}
//нарисовать рамку
// 179	B3	10110011	-	│
// 197	C5	11000101	-	┼
// 196	C4	11000100	-	─
void DisplayFrame()
{
	SetColor(2);
	//вертикальная линия 1
	for (int i = 0; i < 21; i++)
	{
		SetConsoleCursor( 21 , i + 2);
		printf_s("%c", '\xB3'); // │
	}
	//вертикальная линия 2
	for (int i = 0; i < 21; i++)
	{
		SetConsoleCursor(31, i + 2);
		printf_s("%c", '\xB3'); // │
	}

	//горизонтальная линия 1	
	for (int i = 0; i < 33; i++)
	{
		SetConsoleCursor(i + 10, 9);
		printf_s("%c", '\xC4'); // ─
		if (i == 11 || i == 21)
		{
			SetConsoleCursor(i + 10, 9);
			printf_s("%c", '\xC5'); // ┼
		}
	}
	//горизонтальная линия 2
	for (int i = 0; i < 33; i++)
	{
		SetConsoleCursor(i + 10, 15);
		printf_s("%c", '\xC4'); // ─
		if (i == 11 || i == 21)
		{
			SetConsoleCursor(i + 10, 15);
			printf_s("%c", '\xC5'); // ┼
		}
	}
}
void ShowHotkeys()
{
	SetColor(13);
	SetConsoleCursor(50, 2);
	printf_s("Hotkeys for setting marker:");
	
	
	SetColor(0XEF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 51, j + 5);
			puts(" ");			
		}
	}

	SetColor(10);
	SetConsoleCursor(52, 6);
	printf_s("Q");
	SetConsoleCursor(59, 6);
	printf_s("W");
	SetConsoleCursor(66, 6);
	printf_s("E");	

	SetColor(0XAF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 55, j + 9);
			puts(" ");
		}
	}

	SetColor(11);
	SetConsoleCursor(56, 10);
	printf_s("A");
	SetConsoleCursor(63, 10);
	printf_s("S");
	SetConsoleCursor(70, 10);
	printf_s("D");
	
	SetColor(0XBF);
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i > 4 && i < 7 || i > 11 && i < 14)
			{
				continue;
			}
			SetConsoleCursor(i + 58, j + 13);
			puts(" ");
		}
	}

	SetColor(13);
	SetConsoleCursor(59, 14);
	printf_s("Z");
	SetConsoleCursor(66, 14);
	printf_s("X");
	SetConsoleCursor(73, 14);
	printf_s("C");

}
//установить курсор
void SetConsoleCursor(int x, int y)
{
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}
//установить цвет
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//звук хода игрока
void SoundPlayerMove()
{
	Beep(450, 350);	
}
//звук хода компьютера
void SoundComputerMove()
{
	Beep(750, 275);
}
//звук неверного хода
void SoundWrongMove()
{
	Beep(1050, 750);
}
//звук неверной клавиши
void SoundWrongKey()
{
	Beep(1050, 750);
	Beep(550, 750);	
}
//звук лива из игры
void SoundESC()
{
	for (int x = 1050; x > 500; x = x - 50)
	{
		Beep(x, 150);
	}
}
//звук победы
void SoundWin()
{

	for (int x = 300; x < 750; x = x +50)
	Beep(x, 200);
}
//звук поражения
void SoundLose()
{
	for (int x = 900; x > 250; x = x - 50)
		Beep(x, 200);
}
//звук при ничьей
void SoundDeadHeat()
{
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);
	Beep(300, 500);
	Sleep(50);
	Beep(250, 500);
	Sleep(50);
	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);
	Beep(250, 500);
	Sleep(50);
	Beep(350, 250);
	Beep(300, 500);
	Sleep(50);
}
//спрятать курсор
void HideCursor()
{	
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = FALSE;
		SetConsoleCursorInfo(consoleHandle, &info);	
}
#include "stdio.h"
#include  "windows.h"
#include "time.h"

//этот файл использует функции с другого исходного файла
#include "displayfield.h"
#include "engine.h"
#include "gamesound.h"

//————————————————Движок игры :D ———————————————— 
//создать игровое поле
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

//проверка на победу
int ItsVictory(unsigned char krissKross[3][3], unsigned char playerMark, unsigned char computerMark)
{
	//вызвать функцию на проверку всех линий
	unsigned char checkVictory = CheckThreeMark(krissKross);
	//если функция CheckThreeMark вернула маркер игрока(X) то победил игрок
	if (checkVictory == playerMark)
	{
		SetConsoleCursor(10, 23);
		SetColor(13);
		printf_s("You won! Congratulations!");
		SoundWin();
		return 1;
	}
	//если функция CheckThreeMark  вернула маркер компьютера(O) то победил компьютер
	else if (checkVictory == computerMark)
	{
		SetConsoleCursor(10, 23);
		SetColor(12);
		printf_s("You lose! Try next time! ");
		SoundLose();
		return 2;
	}
	//иначе функия  вернёт 0, что говорит о том что игра ещё не окончена
	return 0;
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

//непобедимый алгоритм методом минимакс в разработке... :D
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
				DisplayGameField(krissKross);
				SoundComputerMove();
				return;
			}
		}
	}
}

// установить курсор
void SetConsoleCursor(int x, int y)
{
	COORD cursorPosition = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
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
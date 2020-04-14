#include "stdio.h"
#include "windows.h"

//подключение моих исходных файлов
#include "displayfield.h"                  //изображение
#include "engine.h"                            //движок игры
#include "gamesound.h"                   //игровые звуки

int main()
{
	unsigned char krissKross[3][3], key = 0, playerMark = 'X', computerMark = 'O';
	int checkMove, countMove = 0, checkVictory = 0;
	
	//запуск игры		
	MakeGameField(krissKross);
	HideCursor();
	DisplayGameField(krissKross);
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
			DisplayGameField(krissKross);
			checkVictory = ItsVictory(krissKross, playerMark, computerMark);
			//счётчик ходов
			countMove++;
			if (checkVictory == 1)
			{
				return 0;
			}
			//ход компьютера и проверка на его победу
			ComputerMove(krissKross, computerMark, playerMark);
			checkVictory = ItsVictory(krissKross, playerMark, computerMark);
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
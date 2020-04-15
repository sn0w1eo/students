#include "windows.h"

//————————————————Звуки ————————————————
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
	for (int x = 300; x < 750; x = x + 50)
	{
		Beep(x, 200);
	}		
}

//звук поражения
void SoundLose()
{
	for (int x = 900; x > 250; x = x - 50)
	{
		Beep(x, 200);
	}		
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
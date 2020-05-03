//TO DO
#include "stdio.h"
#include "windows.h"

#include "visualization.h"
#include "read.h"
#include "engine.h"

typedef unsigned char uchar;

//Рисуем одну ячейку
void DisplayCell(int shiftX, int shiftY, int size, uchar symbol)

//179  B3  10110011  │
//191  BF  10111111  ┐
//192  C0  11000000  └
//196  C4  11000100  ─
//212  D4  11010100  ╘
//213  DA  11010101  ╒
//217  D9  11011001  ┘
{
	for (int i = 0; i <= size; i++)
	{

		if (i > 0 && i < size)
		{
			SetConsoleCursor(i + shiftX, 0 + shiftY);
			putchar('\xC4');
			SetConsoleCursor(i + shiftX, 2 + shiftY);
			putchar('\xC4');
		}

		if (i == 0)
		{
			SetConsoleCursor(i + shiftX, 0 + shiftY);
			putchar('\xDA');
			SetConsoleCursor(i + shiftX, 2 + shiftY);
			putchar('\xC0');
		}

		if (i == size - 1)
		{
			SetConsoleCursor(i + shiftX, 0 + shiftY);
			putchar('\xBF');
			SetConsoleCursor(i + shiftX, 2 + shiftY);
			putchar('\xD9');
		}
	
	}
}

//отобразить горячие клавиши управления программой
void DisplayHotkeys()
{
	SetConsoleCursor(87, 8);
	SetColor(14);
	printf_s("PRESS");
	SetColor(13);
	printf_s("\'SPACEBAR\'");
	SetColor(14);
	printf_s("TO ADD A CONTACT SLOT\n");

	SetConsoleCursor(87, 10);
	SetColor(14);
	printf_s("PRESS");
	SetColor(13);
	printf_s("\'ENTER\'");
	SetColor(14);
	printf_s("TO SELECT THE SLOT TO FILL\n");

	SetConsoleCursor(87, 12);
	SetColor(14);
	printf_s("PRESS");
	SetColor(13);
	printf_s("\'UP\'");
	SetColor(14);
	printf_s("OR");
	SetColor(13);
	printf_s("\'DOWN\'");
	SetColor(14);
	printf_s("TO SCROLL THROUGH THE LIST\n");
	SetColor(7);

}

//рисовать таблицу с помощью DisplayCell
void DisplayFrames(uchar** list)
{
	int size = GetListSize(list);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			DisplayCell(0 + j * 28, i * 2, 28, '*');
		}
	}
}

//табличка с выбором типа действия(удалить/изменить)
void DisplayActions()
{
	SetColor(12);
	SetConsoleCursor(88, 1);
	printf_s(" DELETE");

	SetColor(10);
	SetConsoleCursor(88, 3);
	printf_s(" UPDATE");

	SetColor(6);
	for (int i = 0; i < 2; i++)
	{
		DisplayCell(87, i * 2, 9, '*');
	}
	SetColor(7);
}

//просто шапка
void DisplayCap(uchar** list)
{
	DisplayFrames(list);
	SetConsoleCursor(1, 1);
	printf_s("Name");
	SetConsoleCursor(29, 1);
	printf_s("Phone number");
	SetConsoleCursor(57, 1);
	printf_s("Date");
}

//отобразить контакты
void DisplayContacts(uchar** list)
{
	int size = ((int*)list[0])[0];
	for (int contactIndex = 1; contactIndex < size; contactIndex++)
	{
		if (list[contactIndex] == NULL)
		{
			SetColor(12);
			ClearInputField(contactIndex);
			SetConsoleCursor(1, (2 * contactIndex) + 1);
			printf_s("NO CONTACT");
			SetConsoleCursor(29, (2 * contactIndex) + 1);
			printf_s("NO CONTACT");
			SetConsoleCursor(57, (2 * contactIndex) + 1);
			printf_s("NO CONTACT");
			SetColor(7);
		}
		else
		{
			SetColor(10);
			SetConsoleCursor(1, (2 * contactIndex) + 1);
			DisplayName(list, contactIndex);

			SetConsoleCursor(29, (2 * contactIndex) + 1);
			DisplayPhoneNumber(list, contactIndex);

			SetConsoleCursor(57, (2 * contactIndex) + 1);
			DisplayDate(list, contactIndex);
			SetColor(7);
		}
	}
}

//стереть символы с консоли))
void BackSpace(int amount)
{
	for (int i = 0; i < amount; i++)
	{
		printf_s("\b \b");
	}
}

//очищать поля для ввода
void ClearInputField(int rowNumber)
{
	SetConsoleCursor(27, (2 * rowNumber) + 1);
	BackSpace(26);
	SetConsoleCursor(55, (2 * rowNumber) + 1);
	BackSpace(26);
	SetConsoleCursor(83, (2 * rowNumber) + 1);
	BackSpace(26);
	SetConsoleCursor(1, (2 * rowNumber) + 1);
}

//стереть минюшку выбора дейтсвия
void ClearChooseMenu()
{
	for (int i = 0; i < 7; i++)
	{
		SetConsoleCursor(103, i);
		BackSpace(16);
	}
}

//выделение ячейки с выбором действия
void ChooseAction(int rowNumber, int color)
{
	SetColor(color);
	DisplayCell(87, rowNumber * 2, 9, '*');
	SetColor(7);
}

//отобразить менюшку функционала удаления
void DisplayDeleteActions()
{
	SetColor(12);
	SetConsoleCursor(88, 1);
	printf_s("DELETE COTACT");

	SetColor(12);
	SetConsoleCursor(88, 3);
	printf_s("DELETE PHONE");

	SetColor(12);
	SetConsoleCursor(88, 5);
	printf_s("DELETE DATE");

	SetColor(6);
	for (int i = 0; i < 3; i++)
	{
		DisplayCell(87, i * 2, 15, '*');
	}
	SetColor(7);
}

//отобразить выделение ячейки при выборе действия удаления
void ChooseDeleteAction(int rowNumber, int color)
{
	SetColor(color);
	DisplayCell(87, rowNumber * 2, 15, '*');
	SetColor(7);
}

//отобразить менюшку функционала изменения данных контакта
void DisplayUpdateActions()
{
	SetColor(10);
	SetConsoleCursor(88, 1);
	printf_s(" UPDATE NAME");

	SetColor(10);
	SetConsoleCursor(88, 3);
	printf_s(" UPDATE PHONE");

	SetColor(10);
	SetConsoleCursor(88, 5);
	printf_s(" UPDATE DATE");

	SetColor(6);
	for (int i = 0; i < 3; i++)
	{
		DisplayCell(87, i * 2, 15, '*');
	}
	SetColor(7);
}


void ChooseUpdateAction(int rowNumber, int color)
{
	SetColor(color);
	DisplayCell(87, rowNumber * 2, 15, '*');
	SetColor(7);
}

//выделить строку
void SelectRow(int rowNumber, int color)
{
	SetColor(color);
	for (int i = 0; i < 3; i++)
	{
		DisplayCell(0 + i * 28, rowNumber * 2, 28, '*');
	}
	SetColor(7);
}

//выделить строку
void ChooseRow(int rowNumber, int color)
{
	SetColor(color);
	for (int i = 0; i < 3; i++)
	{
		DisplayCell(0 + i * 28, rowNumber * 2, 28, '*');
	}
	SetColor(7);
}

//цвет ^^
void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


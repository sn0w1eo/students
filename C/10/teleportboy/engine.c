#include "stdio.h"
#include "windows.h"

#include "read.h"
#include "create.h"
#include "update.h"
#include "delete.h"

#include "memory.h"
#include "visualization.h"
#include "engine.h"

#define UP         0xE048
#define DOWN       0xE050
#define ESC        0x1B
#define ENTER      0xD
#define SPACE      0x20

//основа
void GetKeystroke(uchar** list)
{
	int key, listSize, rowNumber = 1;
	ChooseRow(rowNumber, 11);

	while (1)
	{
		listSize = GetListSize(list) - 1;
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		//Этот свитч для управления курсором по списку контактов
		switch (key)
		{		
		//Вверх
		case UP:
			if (listSize > 1)
			{
				rowNumber = rowNumber - 1;
				if (rowNumber < 1)
				{
					
					rowNumber = 1;
				}
				//Выделение ячейки
				ChooseRow(rowNumber, 11);
				ChooseRow(rowNumber + 1, 7);
				ChooseRow(rowNumber, 11);
			}
			break;
		
		//Вниз
		case DOWN:
			if (listSize > 1)
			{
				rowNumber = rowNumber + 1;
				if (rowNumber > listSize)
				{
					
					rowNumber = listSize;
				}
				//Выделение ячейки
				ChooseRow(rowNumber, 11);
				ChooseRow(rowNumber - 1, 7);
				ChooseRow(rowNumber, 11);
			}
			break;
		
		case ENTER:
			//Если указатель пустой
			//то есть если туда не записан контакт,
			//то значит начать запись контакта в этой ячейке
			if (list[rowNumber] == NULL)
			{
				ClearInputField(rowNumber);

				SetColor(14);

				SetConsoleCursor(1, (2 * rowNumber) + 1);
				list = AddContact(list, rowNumber);

				SetConsoleCursor(29, (2 * rowNumber) + 1);
				list = AddPhoneNumber(list, rowNumber);

				SetConsoleCursor(57, (2 * rowNumber) + 1);
				list = AddDate(list, rowNumber);

				DisplayContacts(list);
			}
			else
			{
				//Иначе выбрать действие над данными
				//SelectAction() - удалить или обновить
				switch (SelectAction())
				{
					
				case 0:
					DeleteContact(list, rowNumber);
					DisplayContacts(list);
					break;
				case 1:
					DeletePhoneNumber(list, rowNumber);
					DisplayContacts(list);
					break;
				case 2:
					DeleteDate(list, rowNumber);
					DisplayContacts(list);
					break;
				case 3:
					SetConsoleCursor(27, (2 * rowNumber) + 1);
					BackSpace(26);
					list = UpdateName(list, rowNumber);
					DisplayContacts(list);

					break;
				case 4:
					SetConsoleCursor(55, (2 * rowNumber) + 1);
					BackSpace(26);
					list = UpdatePhoneNumber(list, rowNumber);
					DisplayContacts(list);

					break;
				case 5:
					SetConsoleCursor(83, (2 * rowNumber) + 1);
					BackSpace(26);
					list = UpdateDate(list, rowNumber);
					DisplayContacts(list);

					break;
				}
			}			
			break;
		//А тут просто добавить новую память
		case SPACE:
			list = GetMemory(list);
			DisplayFrames(list);
			DisplayContacts(list);
			break;
		}
	}
}

//Выбрать тип действий над контактом
//удаление или изменение
int SelectAction()
{
	int key, rowNumber = 0;
	DisplayActions();
	ChooseAction(rowNumber, 11);
	while (1)
	{
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		switch (key)
		{
		case UP:
			rowNumber = rowNumber - 1;
			if (rowNumber < 0)
			{
				rowNumber = 0;
			}
			//Выделение ячейки
			ChooseAction(rowNumber, 11);
			ChooseAction(rowNumber + 1, 6);
			ChooseAction(rowNumber, 11);
			break;

		case DOWN:
			rowNumber = rowNumber + 1;
			if (rowNumber > 1)
			{
				rowNumber = 1;
			}
			//Выделение ячейки
			ChooseAction(rowNumber, 11);
			ChooseAction(rowNumber - 1, 6);
			ChooseAction(rowNumber, 11);
			break;
			
			//Переход с выбору действия над контактом
		case ENTER:
			if (rowNumber == 0)
			{
				return SeletDeleteAction();
			}
			else
			{
				return SelectUpdateAction();
			}
		}
	}
}

//Выбрать что удалить в контакте
int SeletDeleteAction()
{
	int key, rowNumber = 0;
	DisplayDeleteActions();
	while (1)
	{
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		switch (key)
		{
		case UP:
			rowNumber = rowNumber - 1;
			if (rowNumber < 0)
			{
				rowNumber = 0;
			}
			//Выделение ячейки
			ChooseDeleteAction(rowNumber, 11);
			ChooseDeleteAction(rowNumber + 1, 6);
			ChooseDeleteAction(rowNumber, 11);
			break;


		case DOWN:
			rowNumber = rowNumber + 1;
			if (rowNumber > 2)
			{
				rowNumber = 2;
			}
			//Выделение ячейки
			ChooseDeleteAction(rowNumber, 11);
			ChooseDeleteAction(rowNumber - 1, 6);
			ChooseDeleteAction(rowNumber, 11);
			break;


			//вернуть номер дейтсивя. т.е. 0 = удалить контакт. 1 = удалить номер. 2 = удалить дату
		case ENTER:			
			ClearChooseMenu();   //Убрать менюшку
			return rowNumber;
		}
	}
}

//Выбрать что изменить в контакте
int SelectUpdateAction()
{
	int key, rowNumber = 0;
	DisplayUpdateActions();

	while (1)
	{
		key = getch();
		if (key == 0xE0)
		{
			key = key << 8;
			key = key | getch();
		}

		switch (key)
		{
		case UP:
			rowNumber = rowNumber - 1;
			if (rowNumber < 0)
			{
				rowNumber = 0;
			}
			//Выделение ячейки
			ChooseUpdateAction(rowNumber, 11);
			ChooseUpdateAction(rowNumber + 1, 6);
			ChooseUpdateAction(rowNumber, 11);
			break;

		case DOWN:
			rowNumber = rowNumber + 1;
			if (rowNumber > 2)
			{
				rowNumber = 2;
			}
			//Выделение ячейки
			ChooseUpdateAction(rowNumber, 11);
			ChooseUpdateAction(rowNumber - 1, 6);
			ChooseUpdateAction(rowNumber, 11);
			break;

			//вернуть номер дейтсивя. т.е. 3 = изменить имя. 4 = изменить номер. 5 = изменить дату
		case ENTER:
			ClearChooseMenu();
			return rowNumber + 3;

		}
	}
}

//позиция курсора
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
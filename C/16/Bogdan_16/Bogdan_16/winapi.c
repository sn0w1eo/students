#include "winapi.h"



//глобальная переменная для обращения к БД
database phoneDB;


void createWindowElements(HWND hwnd) {

	//листбокс для списка 
	HWND hwndList = CreateWindowW(L"listbox", NULL, WS_CHILD
		| WS_VISIBLE | LBS_NOTIFY,
		20, 20, 350, 350,
		hwnd,
		(HMENU)ID_LISTBOX, NULL, NULL);

	//кнопка добавления 
	HWND btnAdd = CreateWindowW(L"button", L"Add",
		WS_VISIBLE | WS_CHILD,
		400, 40, 60, 25,
		hwnd, (HMENU)ID_ADD_BUTTON, NULL, NULL);

	//кнопка удаления
	HWND btnDelete = CreateWindowW(L"button", L"Delete",
		WS_VISIBLE | WS_CHILD,
		570, 40, 105, 25,
		hwnd, (HMENU)ID_DELETE_BUTTON, NULL, NULL);

	//кнопка обнавления
	HWND btnUpdate = CreateWindowW(L"button", L"Update",
		WS_VISIBLE | WS_CHILD,
		500, 250, 105, 25,
		hwnd, (HMENU)ID_UPDATE_BUTTON, NULL, NULL);

	//кнопка выхода
	HWND btnExit = CreateWindowW(L"button", L"Exit",
		WS_VISIBLE | WS_CHILD,
		570, 400, 105, 25,
		hwnd, (HMENU)ID_EXIT_BUTTON, NULL, NULL);

	//текстовый редактор для имени
	HWND hwndName = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		450, 150, 200, 20,
		hwnd, (HMENU)ID_NAME_EDIT, NULL, NULL);

	//текстовый редактор для номера
	HWND hwndPhone = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		450, 200, 200, 20,
		hwnd, (HMENU)ID_NUMBER_EDIT, NULL, NULL);

	//надпис для текстового редактора
	HWND staticTextName = CreateWindowW(L"static", L"Name: ",
		WS_CHILD | WS_VISIBLE,
		400, 150, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT_NAME, NULL, NULL);

	//надпист для текстового редактора
	HWND staticTextPhone = CreateWindowW(L"static", L"Phone: ",
		WS_CHILD | WS_VISIBLE,
		400, 200, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT_PHONE, NULL, NULL);

	//текст с данными из БД
	HWND hwndStatic = CreateWindowW(L"static", L"", WS_CHILD | WS_VISIBLE,
		400, 300, 200, 100,
		hwnd, (HMENU)ID_CHANGE_TEXT, NULL, NULL);

}

//открывает и создает БД
void openAndCreateBD() {
	if (openDatabase(&phoneDB, "database.db") != OK) {//открываем (создаём) файл где будет наша БД
		MessageBoxW(NULL, L"fucking WINAPI!", L"Не удалост открыть БД", MB_OK);
		clouseDB(&phoneDB);
	}

	if (createTable(&phoneDB) != OK) {			//создаем таблицу
		MessageBoxW(NULL, L"fucking WINAPI!", L"Не удалост создать таблицу БД", MB_OK);
		clouseDB(&phoneDB);
	}
}

//обрабатывает кнопку add
void addButton(HWND hwnd) {

	//создание буфферов
	wchar_t nameInEdit[255];
	wchar_t phoneInEdit[255];
	char name[255];
	char phone[255];

	//получаем данные с текстовых окон 
	GetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), nameInEdit, ARRAYSIZE(nameInEdit) - 1);
	GetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phoneInEdit, ARRAYSIZE(phoneInEdit) - 1);

	//добавляем имя в listBox
	SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_ADDSTRING, 0, nameInEdit);

	//переводим из wchar_t в char
	wcstombs(name, nameInEdit, ARRAYSIZE(name) - 1);
	wcstombs(phone, phoneInEdit, ARRAYSIZE(phone) - 1);

	//добавляем данные в БД
	addPerson(&phoneDB, name, atoi(phone));

	//очистка текстовых окон
	SendMessageW(GetDlgItem(hwnd, ID_NAME_EDIT), WM_SETTEXT, 0, (L""));
	SendMessageW(GetDlgItem(hwnd, ID_NUMBER_EDIT), WM_SETTEXT, 0, (L""));
}

//выделенные элементы в listBox ищет в БД и выводит данные в главное окно
void printPhoneOfPerson(HWND hwnd) {

	//создаем буфферы
	wchar_t name[255] = { 0 };
	wchar_t phone[255] = { 0 };
	wchar_t buffForText[255] = { 0 };
	char nameFromDB[255];
	char phoneFromDB[255];
	char nameInListBoxC[255];
	wchar_t nameInListBoxW[255] = { 0 };

	//плоучаем ID выделенного элемента в listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);

	//запрашиваем имя с listBox для сравнения в БД
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameInListBoxW);
	wcstombs(nameInListBoxC, nameInListBoxW, ARRAYSIZE(nameInListBoxC) - 1);

	//получаем данные с БД и переводим в wchar_t
	sprintf(nameFromDB, "%s", getInformation(&phoneDB, nameInListBoxC, NAME));
	sprintf(phoneFromDB, "%s", getInformation(&phoneDB, nameInListBoxC, PHONE));
	mbstowcs(name, nameFromDB, ARRAYSIZE(name) - 1);
	mbstowcs(phone, phoneFromDB, ARRAYSIZE(phone) - 1);

	//печатаем данные в главное окно и текстовые редакторы
	StringCbPrintfW(buffForText, ARRAYSIZE(buffForText), L"Name: %ls\nPhone: %s", name, phone);
	SetWindowTextW(GetDlgItem(hwnd, ID_CHANGE_TEXT), buffForText);
	SetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), name);
	SetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phone);
}

//заносит имена в listBox
//взятл у Кирилла
void InitListBox(HWND hwnd) {
	phoneDB.sql = NULL;
	phoneDB.sql = calloc(200, sizeof(char));
	sqlite3_stmt* st;

	phoneDB.sql = "SELECT Name FROM phoneBook";

	char str[200] = { 0 };
	wchar_t listBoxText[200] = { 0 };

	int rc = sqlite3_prepare(phoneDB.db, phoneDB.sql, -1, &st, 0);

	//Проход по строкам в таблице и взятие 0-ого столбца
	while ((rc = sqlite3_step(st)) == SQLITE_ROW) {
		sprintf(str, "%s", sqlite3_column_text(st, 0));
		mbstowcs(listBoxText, str, ARRAYSIZE(str));

		SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_ADDSTRING, 0, (LPARAM)listBoxText);

		memset(listBoxText, 0, sizeof(wchar_t) * 200);
	}
	sqlite3_finalize(st);
}

//обработка кнопки delete
void deleteButton(HWND hwnd) {

	//создаем буфферы
	char nameFromListBoxC[255];
	wchar_t nameFromListBoxW[255] = { 0 };
	char buf[255] = { 0 };

	//плоучаем данне выделенного объекта в listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameFromListBoxW);
	wcstombs(nameFromListBoxC, nameFromListBoxW, ARRAYSIZE(nameFromListBoxC) - 1);

	//удаление с бд
	deletePerson(&phoneDB, NAME, nameFromListBoxC);

	//удаление строки в listBox
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_DELETESTRING, (WPARAM)id, 0);
}

//обработка 
void updateButton(HWND hwnd) {

	//создаем буферы
	wchar_t nameInEditW[255] = { 0 };
	wchar_t phoneInEditW[255] = { 0 };
	char nameInEditC[255] = { 0 };
	char phoneInEditC[255] = { 0 };
	wchar_t nameInListBoxW[255] = { 0 };
	char nameInListBoxC[255] = { 0 };

	//получаем имя с listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameInListBoxW);

	//получаем новые имена с текстовых редакторов
	GetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), nameInEditW, ARRAYSIZE(nameInEditW));
	GetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phoneInEditW, ARRAYSIZE(phoneInEditW));

	//переводим из wchar_t в char
	wcstombs(nameInEditC, nameInEditW, ARRAYSIZE(nameInEditC) - 1);
	wcstombs(phoneInEditC, phoneInEditW, ARRAYSIZE(phoneInEditC) - 1);
	wcstombs(nameInListBoxC, nameInListBoxW, ARRAYSIZE(nameInListBoxC) - 1);

	updatePerson(&phoneDB, PHONE, phoneInEditC, nameInListBoxC);
	updatePerson(&phoneDB, NAME, nameInEditC, nameInListBoxC);

	//добавляем изменения в listBox
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_DELETESTRING, (WPARAM)id, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_INSERTSTRING, (WPARAM)id, (LPARAM)nameInEditW);
}


#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"


//все кнопки и надписи в нашем окне
void InitControlsAndText(HWND hwnd) {
	HWND hwndCombo = CreateWindowW(L"Combobox", NULL,
		WS_VISIBLE | WS_CHILD | CBS_DROPDOWNLIST | CBS_DROPDOWN | CBS_HASSTRINGS | WS_VSCROLL,
		150, 40, 400, 240, hwnd, (HMENU)ID_COMBOBOX_TEXT, NULL, NULL);
	HWND btnAdd = CreateWindowW(L"button", L"Add",
		WS_VISIBLE | WS_CHILD,
		500, 175, 60, 25, hwnd, (HMENU)ID_ADD_NUMBER, NULL, NULL);
	HWND btnDelete = CreateWindowW(L"button", L"Delete",
		WS_VISIBLE | WS_CHILD,
		670, 40, 105, 25, hwnd, (HMENU)ID_DELETE_NUMBER, NULL, NULL);
	HWND btnUpdate = CreateWindowW(L"button", L"Update",
		WS_VISIBLE | WS_CHILD,
		500, 275, 105, 25, hwnd, (HMENU)ID_UPDATE_NUMBER, NULL, NULL);
	HWND btnExit = CreateWindowW(L"button", L"Exit",
		WS_VISIBLE | WS_CHILD,
		670, 400, 105, 25, hwnd, (HMENU)ID_EXIT, NULL, NULL);
	HWND hwndName = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		150, 150, 300, 20, hwnd, (HMENU)ID_NAME,
		NULL, NULL);
	HWND hwndPhone = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		150, 200, 300, 20, hwnd, (HMENU)ID_NUMBER,
		NULL, NULL);
	HWND staticTextName = CreateWindowW(L"static", L"Name: ",
		WS_CHILD | WS_VISIBLE,
		80, 150, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT, NULL, NULL);
	HWND staticTextPhone = CreateWindowW(L"static", L"Phone: ",
		WS_CHILD | WS_VISIBLE,
		80, 200, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT, NULL, NULL);

	HWND hwndNewName = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		150, 250, 300, 20, hwnd, (HMENU)ID_NEWNAME,
		NULL, NULL);
	HWND hwndNewPhone = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_NOTIFY,
		150, 300, 300, 20, hwnd, (HMENU)ID_NEWNUMBER,
		NULL, NULL);
	HWND staticTextNewName = CreateWindowW(L"static", L"New Name: ",
		WS_CHILD | WS_VISIBLE,
		60, 250, 80, 15,
		hwnd, (HMENU)ID_STATIC_TEXT, NULL, NULL);
	HWND staticTextNewPhone = CreateWindowW(L"static", L"New Phone: ",
		WS_CHILD | WS_VISIBLE,
		60, 300, 80, 15,
		hwnd, (HMENU)ID_STATIC_TEXT, NULL, NULL);

	HWND staticUserPhone = CreateWindowW(L"static", L"User : ",
		WS_CHILD | WS_VISIBLE,
		150, 80, 150, 15, hwnd, (HMENU)ID_USER_PHONE, NULL, NULL);
	SetWindowText(staticUserPhone, L"Phone: ");

}

//описание содержания COMBOBOX
void InitComboBox(HWND hwndComboBox, PhoneDB* pdb)
{
	char* sqlQuery = "SELECT Name FROM Phonebook";
	char str[ARRAY_SIZE] = { 0 };
	sqlite3_stmt* st = { 0 };
	wchar_t comboBoxItemText[ARRAY_SIZE] = { 0 };

	int rc = sqlite3_prepare_v2(pdb->db, sqlQuery, -1, &st, 0);

	//Проход по строкам в таблице и взятие 0-ого столбца
	while ((rc = sqlite3_step(st)) == SQLITE_ROW) {
		sprintf(str, "%s", sqlite3_column_text(st, 0));
		mbstowcs(comboBoxItemText, str, strlen(str));

		SendMessageW(hwndComboBox, CB_ADDSTRING, 0, (LPARAM)comboBoxItemText);

		memset(comboBoxItemText, 0, sizeof(wchar_t) * ARRAY_SIZE);
	}
	sqlite3_finalize(st);
}

//добавление контакта
void InitAddButton(HWND hwnd, HWND hwndName, HWND hwndPhone, PhoneDB* pdb)
{
	wchar_t wcsName[ARRAY_SIZE] = { 0 };
	wchar_t wcsPhone[ARRAY_SIZE] = { 0 };
	char mbName[ARRAY_SIZE] = { 0 };
	char mbPhone[ARRAY_SIZE] = { 0 };

	GetWindowTextW(hwndName, wcsName, ARRAY_SIZE);
	GetWindowTextW(hwndPhone, wcsPhone, ARRAY_SIZE);
	SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_ADDSTRING, NULL, wcsName);
	wcstombs(mbName, wcsName, ARRAY_SIZE);
	wcstombs(mbPhone, wcsPhone, ARRAY_SIZE);
	InsertContact(pdb, mbName, mbPhone);
}

//обновление информации о контакте
void InitUpdateButton(HWND hwnd, HWND hwndNewName, HWND hwndNewPhone, PhoneDB* pdb)
{
	wchar_t wcsNewName[ARRAY_SIZE] = { 0 };
	wchar_t wcsNewPhone[ARRAY_SIZE] = { 0 };
	char mbNewName[ARRAY_SIZE] = { 0 };
	char mbNewPhone[ARRAY_SIZE] = { 0 };

	GetWindowTextW(hwndNewName, wcsNewName, ARRAY_SIZE);
	GetWindowTextW(hwndNewPhone, wcsNewPhone, ARRAY_SIZE);
	wcstombs(mbNewName, wcsNewName, ARRAY_SIZE);
	wcstombs(mbNewPhone, wcsNewPhone, ARRAY_SIZE);
	const int ID = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_DELETESTRING, ID, 0);
	SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_ADDSTRING, NULL, wcsNewName);
	UpdateContact(pdb, ID, mbNewName, mbNewPhone);
}

//удаление контакта
void InitDeleteButton(HWND hwndName, const int ID, PhoneDB* pdb)
{
	DeleteContact(&pdb, ID);
}

//вывод номера телефона
void getUsersPhone(HWND hwnd, PhoneDB* db) {
	int id;
	wchar_t* buff = calloc(BUFF_SIZE, sizeof(wchar_t));
	wchar_t* buff2 = calloc(BUFF_SIZE, sizeof(wchar_t));
	id = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_GETCURSEL, 0, 0);
	buff = SelectPhone(&pdb, id + 1);
	swprintf(buff2, BUFF_SIZE, L"Phone: %s", buff);
	SetWindowText(GetDlgItem(hwnd, ID_USER_PHONE), buff2);
}

//удаление строки из COMBOBOX
void deleteFmCB(HWND hwnd, PhoneDB* db)
{
	int id = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_DELETESTRING, id, 0);
	DeleteContact(db, id + 1);
}

void getUsersPhoneD(HWND hwnd, PhoneDB* db) {
	int id;
	wchar_t* buff = calloc(BUFF_SIZE, sizeof(wchar_t));
	wchar_t* buff2 = calloc(BUFF_SIZE, sizeof(wchar_t));
	id = SendMessage(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), CB_GETCURSEL, 0, 0);
	buff = SelectPhone(&pdb, id + 2);
	swprintf(buff2, BUFF_SIZE, L"Phone: %s", buff);
	SetWindowText(GetDlgItem(hwnd, ID_USER_PHONE), buff2);
}
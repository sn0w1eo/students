#include "winapi.h"



//���������� ���������� ��� ��������� � ��
database phoneDB;


void createWindowElements(HWND hwnd) {

	//�������� ��� ������ 
	HWND hwndList = CreateWindowW(L"listbox", NULL, WS_CHILD
		| WS_VISIBLE | LBS_NOTIFY,
		20, 20, 350, 350,
		hwnd,
		(HMENU)ID_LISTBOX, NULL, NULL);

	//������ ���������� 
	HWND btnAdd = CreateWindowW(L"button", L"Add",
		WS_VISIBLE | WS_CHILD,
		400, 40, 60, 25,
		hwnd, (HMENU)ID_ADD_BUTTON, NULL, NULL);

	//������ ��������
	HWND btnDelete = CreateWindowW(L"button", L"Delete",
		WS_VISIBLE | WS_CHILD,
		570, 40, 105, 25,
		hwnd, (HMENU)ID_DELETE_BUTTON, NULL, NULL);

	//������ ����������
	HWND btnUpdate = CreateWindowW(L"button", L"Update",
		WS_VISIBLE | WS_CHILD,
		500, 250, 105, 25,
		hwnd, (HMENU)ID_UPDATE_BUTTON, NULL, NULL);

	//������ ������
	HWND btnExit = CreateWindowW(L"button", L"Exit",
		WS_VISIBLE | WS_CHILD,
		570, 400, 105, 25,
		hwnd, (HMENU)ID_EXIT_BUTTON, NULL, NULL);

	//��������� �������� ��� �����
	HWND hwndName = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		450, 150, 200, 20,
		hwnd, (HMENU)ID_NAME_EDIT, NULL, NULL);

	//��������� �������� ��� ������
	HWND hwndPhone = CreateWindowW(L"Edit", NULL,
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		450, 200, 200, 20,
		hwnd, (HMENU)ID_NUMBER_EDIT, NULL, NULL);

	//������ ��� ���������� ���������
	HWND staticTextName = CreateWindowW(L"static", L"Name: ",
		WS_CHILD | WS_VISIBLE,
		400, 150, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT_NAME, NULL, NULL);

	//������� ��� ���������� ���������
	HWND staticTextPhone = CreateWindowW(L"static", L"Phone: ",
		WS_CHILD | WS_VISIBLE,
		400, 200, 50, 15,
		hwnd, (HMENU)ID_STATIC_TEXT_PHONE, NULL, NULL);

	//����� � ������� �� ��
	HWND hwndStatic = CreateWindowW(L"static", L"", WS_CHILD | WS_VISIBLE,
		400, 300, 200, 100,
		hwnd, (HMENU)ID_CHANGE_TEXT, NULL, NULL);

}

//��������� � ������� ��
void openAndCreateBD() {
	if (openDatabase(&phoneDB, "database.db") != OK) {//��������� (������) ���� ��� ����� ���� ��
		MessageBoxW(NULL, L"fucking WINAPI!", L"�� ������� ������� ��", MB_OK);
		clouseDB(&phoneDB);
	}

	if (createTable(&phoneDB) != OK) {			//������� �������
		MessageBoxW(NULL, L"fucking WINAPI!", L"�� ������� ������� ������� ��", MB_OK);
		clouseDB(&phoneDB);
	}
}

//������������ ������ add
void addButton(HWND hwnd) {

	//�������� ��������
	wchar_t nameInEdit[255];
	wchar_t phoneInEdit[255];
	char name[255];
	char phone[255];

	//�������� ������ � ��������� ���� 
	GetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), nameInEdit, ARRAYSIZE(nameInEdit) - 1);
	GetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phoneInEdit, ARRAYSIZE(phoneInEdit) - 1);

	//��������� ��� � listBox
	SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_ADDSTRING, 0, nameInEdit);

	//��������� �� wchar_t � char
	wcstombs(name, nameInEdit, ARRAYSIZE(name) - 1);
	wcstombs(phone, phoneInEdit, ARRAYSIZE(phone) - 1);

	//��������� ������ � ��
	addPerson(&phoneDB, name, atoi(phone));

	//������� ��������� ����
	SendMessageW(GetDlgItem(hwnd, ID_NAME_EDIT), WM_SETTEXT, 0, (L""));
	SendMessageW(GetDlgItem(hwnd, ID_NUMBER_EDIT), WM_SETTEXT, 0, (L""));
}

//���������� �������� � listBox ���� � �� � ������� ������ � ������� ����
void printPhoneOfPerson(HWND hwnd) {

	//������� �������
	wchar_t name[255] = { 0 };
	wchar_t phone[255] = { 0 };
	wchar_t buffForText[255] = { 0 };
	char nameFromDB[255];
	char phoneFromDB[255];
	char nameInListBoxC[255];
	wchar_t nameInListBoxW[255] = { 0 };

	//�������� ID ����������� �������� � listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);

	//����������� ��� � listBox ��� ��������� � ��
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameInListBoxW);
	wcstombs(nameInListBoxC, nameInListBoxW, ARRAYSIZE(nameInListBoxC) - 1);

	//�������� ������ � �� � ��������� � wchar_t
	sprintf(nameFromDB, "%s", getInformation(&phoneDB, nameInListBoxC, NAME));
	sprintf(phoneFromDB, "%s", getInformation(&phoneDB, nameInListBoxC, PHONE));
	mbstowcs(name, nameFromDB, ARRAYSIZE(name) - 1);
	mbstowcs(phone, phoneFromDB, ARRAYSIZE(phone) - 1);

	//�������� ������ � ������� ���� � ��������� ���������
	StringCbPrintfW(buffForText, ARRAYSIZE(buffForText), L"Name: %ls\nPhone: %s", name, phone);
	SetWindowTextW(GetDlgItem(hwnd, ID_CHANGE_TEXT), buffForText);
	SetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), name);
	SetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phone);
}

//������� ����� � listBox
//����� � �������
void InitListBox(HWND hwnd) {
	phoneDB.sql = NULL;
	phoneDB.sql = calloc(200, sizeof(char));
	sqlite3_stmt* st;

	phoneDB.sql = "SELECT Name FROM phoneBook";

	char str[200] = { 0 };
	wchar_t listBoxText[200] = { 0 };

	int rc = sqlite3_prepare(phoneDB.db, phoneDB.sql, -1, &st, 0);

	//������ �� ������� � ������� � ������ 0-��� �������
	while ((rc = sqlite3_step(st)) == SQLITE_ROW) {
		sprintf(str, "%s", sqlite3_column_text(st, 0));
		mbstowcs(listBoxText, str, ARRAYSIZE(str));

		SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_ADDSTRING, 0, (LPARAM)listBoxText);

		memset(listBoxText, 0, sizeof(wchar_t) * 200);
	}
	sqlite3_finalize(st);
}

//��������� ������ delete
void deleteButton(HWND hwnd) {

	//������� �������
	char nameFromListBoxC[255];
	wchar_t nameFromListBoxW[255] = { 0 };
	char buf[255] = { 0 };

	//�������� ����� ����������� ������� � listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameFromListBoxW);
	wcstombs(nameFromListBoxC, nameFromListBoxW, ARRAYSIZE(nameFromListBoxC) - 1);

	//�������� � ��
	deletePerson(&phoneDB, NAME, nameFromListBoxC);

	//�������� ������ � listBox
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_DELETESTRING, (WPARAM)id, 0);
}

//��������� 
void updateButton(HWND hwnd) {

	//������� ������
	wchar_t nameInEditW[255] = { 0 };
	wchar_t phoneInEditW[255] = { 0 };
	char nameInEditC[255] = { 0 };
	char phoneInEditC[255] = { 0 };
	wchar_t nameInListBoxW[255] = { 0 };
	char nameInListBoxC[255] = { 0 };

	//�������� ��� � listBox
	int id = (int)SendMessageW(GetDlgItem(hwnd, ID_LISTBOX), LB_GETCURSEL, 0, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_GETTEXT, (WPARAM)id, (LPARAM)nameInListBoxW);

	//�������� ����� ����� � ��������� ����������
	GetWindowTextW(GetDlgItem(hwnd, ID_NAME_EDIT), nameInEditW, ARRAYSIZE(nameInEditW));
	GetWindowTextW(GetDlgItem(hwnd, ID_NUMBER_EDIT), phoneInEditW, ARRAYSIZE(phoneInEditW));

	//��������� �� wchar_t � char
	wcstombs(nameInEditC, nameInEditW, ARRAYSIZE(nameInEditC) - 1);
	wcstombs(phoneInEditC, phoneInEditW, ARRAYSIZE(phoneInEditC) - 1);
	wcstombs(nameInListBoxC, nameInListBoxW, ARRAYSIZE(nameInListBoxC) - 1);

	updatePerson(&phoneDB, PHONE, phoneInEditC, nameInListBoxC);
	updatePerson(&phoneDB, NAME, nameInEditC, nameInListBoxC);

	//��������� ��������� � listBox
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_DELETESTRING, (WPARAM)id, 0);
	SendMessage(GetDlgItem(hwnd, ID_LISTBOX), LB_INSERTSTRING, (WPARAM)id, (LPARAM)nameInEditW);
}


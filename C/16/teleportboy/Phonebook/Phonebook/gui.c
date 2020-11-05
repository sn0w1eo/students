#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"

//Инициализация листбокса именами контактов взятых из таблицы БД
void InitListBox(HWND hwndListBox, DBInfo* db)
{
	char* sqlQuery = "SELECT Name FROM Phonebook";
	char str[ARRAY_SIZE] = { 0 };
	wchar_t listBoxItemText[ARRAY_SIZE] = { 0 };

	int rc = sqlite3_prepare_v2(db->dataBase, sqlQuery, -1, &db->statement, 0);

	//Проход по строкам в таблице и взятие 0-ого столбца
	while ((rc = sqlite3_step(db->statement)) == SQLITE_ROW) {
		sprintf(str, "%s", sqlite3_column_text(db->statement, 0));
		mbstowcs(listBoxItemText, str, strlen(str));

		SendMessageW(hwndListBox, LB_ADDSTRING, 0, (LPARAM)listBoxItemText);

		memset(listBoxItemText, 0, sizeof(wchar_t) * ARRAY_SIZE);
	}

	sqlite3_finalize(db->statement);
}

SetFocusToContact(HWND hwnd, int selectedContact)
{
	SetFocus(GetDlgItem(hwnd, IDC_LIST));
	SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_SETCURSEL, (WPARAM)selectedContact, NULL);
}

void DisplayLabels(HWND hwnd)
{
	PAINTSTRUCT ps;
	HDC hDC;

	hDC = BeginPaint(hwnd, &ps);
	TextOutW(hDC, 265, 62, L"Name: ", strlen("Name: "));
	TextOutW(hDC, 265, 112, L"Phone: ", strlen("Phone: "));
	TextOutW(hDC, 265, 162, L"Email: ", strlen("Email: "));
	EndPaint(hwnd, &ps);
}

wchar_t* GetImagePath(HWND hwnd)
{
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH];

	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = hwnd;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = TEXT("All files(*.bmp)\0*.bmp\0");
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	GetOpenFileName(&ofn);

	return ofn.lpstrFile;
}

void DisplayContactPhoto(HWND hwndPhoto, HBITMAP* hBitmap, DBInfo* db, int contactCode)
{
	char mbPhoto[ARRAY_SIZE] = { 0 };
	wchar_t wcsPhotoPath[ARRAY_SIZE] = { 0 };

	sprintf(mbPhoto, "%s", SelectDBRecord(db, contactCode, BY_PHOTO));
	mbstowcs(wcsPhotoPath, mbPhoto, strlen(mbPhoto));

	//Загрузка и отображение изображения
	*hBitmap = (HBITMAP)LoadImageW(NULL, wcsPhotoPath,
		IMAGE_BITMAP, 485, 700, LR_LOADFROMFILE);
	SendMessageW(hwndPhoto, STM_SETIMAGE,
		(WPARAM)IMAGE_BITMAP, (LPARAM)(*hBitmap));
}

//Вывести информацию и таблицы БД в окна ввода
void DisplayContactInfo(HWND hwndName, HWND hwndPhone, HWND hwndEmail, DBInfo* db, int contactCode)
{
	char name[ARRAY_SIZE] = { 0 };
	char phone[ARRAY_SIZE] = { 0 };
	char email[ARRAY_SIZE] = { 0 };
	wchar_t editControlText[ARRAY_SIZE] = { 0 };

	sprintf(name, "%s", SelectDBRecord(db, contactCode, BY_NAME));
	sprintf(phone, "%s", SelectDBRecord(db, contactCode, BY_PHONE));
	sprintf(email, "%s", SelectDBRecord(db, contactCode, BY_EMAIL));

	mbstowcs(editControlText, name, strlen(name));
	SetWindowTextW(hwndName, editControlText);
	memset(editControlText, 0, sizeof(wchar_t) * ARRAY_SIZE);

	mbstowcs(editControlText, phone, strlen(phone));
	SetWindowTextW(hwndPhone, editControlText);
	memset(editControlText, 0, sizeof(wchar_t) * ARRAY_SIZE);

	mbstowcs(editControlText, email, strlen(email));
	SetWindowTextW(hwndEmail, editControlText);
}

void DoLoadPhotoEvent(HWND hwnd, HWND hwndPhoto, DBInfo* db, HBITMAP* hBitmap, int selectedContact)
{
	wchar_t wcsPhoto[ARRAY_SIZE] = { 0 };
	char mbPhoto[ARRAY_SIZE] = { 0 };

	//Получить путь к изображению путём выбора его в окне 
	wsprintfW(wcsPhoto, L"%s", GetImagePath(hwnd));
	wcstombs(mbPhoto, wcsPhoto, ARRAY_SIZE);
	
	UpdatePhotoColumn(db, selectedContact + 1, mbPhoto);

	DisplayContactPhoto(hwndPhoto, hBitmap, db, selectedContact + 1);
	SetFocusToContact(hwnd, selectedContact);
}

//Записывает строки из окон ввода в буфер
void GetInputBoxesStrings(ContactBuffer* contactBuffer, ChildWindows* childWindows)
{
	GetWindowTextW(childWindows->hwndName, contactBuffer->wcsName, ARRAY_SIZE);
	GetWindowTextW(childWindows->hwndPhone, contactBuffer->wcsPhone, ARRAY_SIZE);
	GetWindowTextW(childWindows->hwndEmail, contactBuffer->wcsEmail, ARRAY_SIZE);

	wcstombs(contactBuffer->mbName, contactBuffer->wcsName, ARRAY_SIZE);
	wcstombs(contactBuffer->mbPhone, contactBuffer->wcsPhone, ARRAY_SIZE);
	wcstombs(contactBuffer->mbEmail, contactBuffer->wcsEmail, ARRAY_SIZE);
}

//Функция в зависимости от переданного ей параметра в качестве button
//исполняет соответствующее событие
void DoButtonPressEvent(HWND hwnd, DBInfo* db, int button)
{
	ContactBuffer contactBuffer = { 0 };
	static ChildWindows childWindows = { 0 };
	int listElementsCount, selectedContact;

	//Получение хендлеров дочерних окон
	childWindows.hwndName = GetDlgItem(hwnd, ID_EDIT_NAME);
	childWindows.hwndPhone = GetDlgItem(hwnd, ID_EDIT_PHONE);
	childWindows.hwndEmail = GetDlgItem(hwnd, ID_EDIT_EMAIL);
	childWindows.hwndPhoto = GetDlgItem(hwnd, ID_PHOTO);
	childWindows.hwndList = GetDlgItem(hwnd, IDC_LIST);

	selectedContact = (int)SendMessageW(childWindows.hwndList, LB_GETCURSEL, 0, 0);

	GetInputBoxesStrings(&contactBuffer, &childWindows);

	switch (button)
	{
	case ADD_BUTTON:
		AddRecordToDB(db, contactBuffer.mbName, contactBuffer.mbPhone, contactBuffer.mbEmail, NULL);
		SendMessageW(childWindows.hwndList, LB_ADDSTRING, 0, (LPARAM)contactBuffer.wcsName);
		
		listElementsCount = SendMessageW(childWindows.hwndList, LB_GETCOUNT, 0, 0);
		SetFocusToContact(hwnd, listElementsCount - 1);

		SendMessageW(childWindows.hwndPhoto, STM_SETIMAGE, 0, 0);

		break;

	case DELETE_BUTTON:

		DeleteDBRecord(db, selectedContact + 1);
		SendMessageW(childWindows.hwndList, LB_DELETESTRING, (WPARAM)selectedContact, 0);
		SendMessageW(childWindows.hwndPhoto, STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)0);

		ClearAllInput(childWindows.hwndName, childWindows.hwndPhone, childWindows.hwndEmail);
		
		listElementsCount = SendMessageW(childWindows.hwndList, LB_GETCOUNT, 0, 0);
		if (listElementsCount == 0) break;

		SetFocusToContact(hwnd, selectedContact);

		DisplayContactInfo(childWindows.hwndName, childWindows.hwndPhone, childWindows.hwndEmail, db, selectedContact + 1);

		break;

	case UPDATE_BUTTON:

		UpdateDBRecord(db, selectedContact + 1, contactBuffer.mbName, contactBuffer.mbPhone, contactBuffer.mbEmail);
		
		SendMessageW(childWindows.hwndList, LB_DELETESTRING, (WPARAM)selectedContact, 0);
		SendMessageW(childWindows.hwndList, LB_INSERTSTRING, (WPARAM)selectedContact, (LPARAM)contactBuffer.wcsName);
				
		SetFocusToContact(hwnd, selectedContact);

		break;
	}
}

void ClearAllInput(HWND hwndName, HWND hwndPhone, HWND hwndEmail)
{
	SendMessageW(hwndName, WM_SETTEXT, NULL, (L""));
	SendMessageW(hwndPhone, WM_SETTEXT, NULL, (L""));
	SendMessageW(hwndEmail, WM_SETTEXT, NULL, (L""));
}
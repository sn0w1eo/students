#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"


LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	PWSTR pCmdLine, int nCmdShow) {

	InitDB("phonebook.db", &pdb);
	CreateTable(&pdb);
	InsertContact(&pdb, "Dmitry", "0705770013");
	InsertContact(&pdb, "Kirill", "0555661796");
	InsertContact(&pdb, "Konstantin", "0553233717");
	InsertContact(&pdb, "Bogdan", "0770368836");
	InsertContact(&pdb, "Nurdoolot", "0709233778");
	InsertContact(&pdb, "Safi", "0555123456");
	InsertContact(&pdb, "Anastasiia", "0700436842");

	MSG  msg;
	HWND hwnd;
	WNDCLASSW wc;
	wc.style = CS_HREDRAW | CS_ENABLE;
	wc.cbClsExtra = NULL;
	wc.cbWndExtra = NULL;
	wc.lpszClassName = L"Phone Book";
	wc.hInstance = hInstance;
	wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
	wc.lpszMenuName = NULL;
	wc.lpfnWndProc = WndProc;
	wc.hCursor = LoadCursor(NULL, IDC_HAND);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	RegisterClassW(&wc);

	hwnd = CreateWindowW(wc.lpszClassName, L"Phone Book",
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		100, 100, 900, 600, NULL, NULL, hInstance, NULL);
	if (!hwnd) {
		MessageBox(NULL, L"Couldn't create window", L"Error", MB_OK);
		return NULL; // выходим из приложения
	}

	while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
	WPARAM wParam, LPARAM lParam) {
	static HWND statusLabel;
	int id;
	switch (msg) {
	case WM_CREATE:
		InitControlsAndText(hwnd, &pdb);
		InitComboBox(GetDlgItem(hwnd, ID_COMBOBOX_TEXT), &pdb);
		break;

	case WM_COMMAND:
		if (HIWORD(wParam) == CBN_CLOSEUP) {
			getUsersPhone(hwnd, &pdb);
		}
		//нажатие клавиши DELETE
		if (LOWORD(wParam) == ID_DELETE_NUMBER)
		{
			deleteFmCB(hwnd, &pdb);
			SetWindowText(GetDlgItem(hwnd, ID_USER_PHONE), L"Phone: ");
			getUsersPhoneD(hwnd, &pdb);
			MessageBeep(MB_OK);
		}
		//нажатие клавиши ADD
		if (LOWORD(wParam) == ID_ADD_NUMBER)
		{
			InitAddButton(hwnd, GetDlgItem(hwnd, ID_NAME), GetDlgItem(hwnd, ID_NUMBER), &pdb);
			MessageBeep(MB_OK);
		}
		//нажатие клавиши UPDATE
		if (LOWORD(wParam) == ID_UPDATE_NUMBER)
		{
			InitUpdateButton(hwnd, GetDlgItem(hwnd, ID_NEWNAME), GetDlgItem(hwnd, ID_NEWNUMBER), &pdb);
			getUsersPhone(hwnd, &pdb);
			MessageBeep(MB_OK);
		}
		//нажатие клавиши EXIT
		if (LOWORD(wParam) == ID_EXIT)
		{
			DestroyWindow(hwnd);
			return 0;
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		DropTable(&pdb);
		CloseDB(&pdb);
		break;
	}

	return DefWindowProcW(hwnd, msg, wParam, lParam);
}

#include "winapi.h"




//глобальная переменная для обращения к БД
database phoneDB;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void createWindowElements(HWND hwnd);					//создание всех элементов окна
void openAndCreateBD();									//создание и открытие БД
void addButton(HWND hwnd);								//обработка кнопки add
void printPhoneOfPerson(HWND hwnd);						//показывает данные лежащие в БД			
void InitListBox(HWND hwndListBox);						//заполняет listBox именами
void deleteButton(HWND hwnd);							//обработка кнопки delete
void updateButton(HWND hwnd);							//обработка кнопки update



int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, 
    PWSTR pCmdLine, int nCmdShow) {
	
    MSG  msg;    
    HWND hwnd;
    WNDCLASSW wc;

    wc.style         = CS_HREDRAW | CS_ENABLE;
    wc.cbClsExtra    = NULL;
    wc.cbWndExtra    = NULL;
    wc.lpszClassName = L"Phone Book";
    wc.hInstance     = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName  = NULL;
    wc.lpfnWndProc   = WndProc;
    wc.hCursor       = LoadCursor(NULL, IDC_HAND);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
  
    RegisterClassW(&wc);
    hwnd = CreateWindowW(wc.lpszClassName, L"Phone Book",
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                100, 100, 700, 500, NULL, NULL, hInstance, NULL);  
	if (!hwnd) {
		MessageBox(NULL, L"Couldn't create window", L"Error", MB_OK);
		return NULL; // выходим из приложения
	}
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    while (GetMessage(&msg, NULL, NULL, NULL)) {
		TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int) msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, 
    WPARAM wParam, LPARAM lParam) {

    switch(msg) {

	case WM_CREATE:
		
		openAndCreateBD();				//открывает или создает БД
		createWindowElements(hwnd);		//выводит все элементы окна
		InitListBox(hwnd);				//заполняет listBox данными из БД
		
	case WM_COMMAND:

		//при выделении элемента listBox выводит на экран данные с БД
		if (LOWORD(wParam) == ID_LISTBOX) {
			if (HIWORD(wParam) == LBN_SELCHANGE) {
				printPhoneOfPerson(hwnd);
			}
		}

		if (HIWORD(wParam) == BN_CLICKED) {
			switch (LOWORD(wParam)) {

				//обработка кнопки add
			case ID_ADD_BUTTON:
				addButton(hwnd);
				break;

				//обработка кнопки exit
			case ID_EXIT_BUTTON:
				MessageBoxW(NULL, L"fucking WINAPI!", L"бомбануло", MB_OK);
				PostQuitMessage(0);
				break;

				//обработка кнопки delete
			case ID_DELETE_BUTTON:
					deleteButton(hwnd);
					break;

				//обработка кнопки update
			case ID_UPDATE_BUTTON:
				updateButton(hwnd);
				break;
			}
			break;
		}
		break;

     case WM_DESTROY:
		  MessageBoxW(NULL, L"fucking WINAPI!", L"бомбануло", MB_OK);
		  PostQuitMessage(0);
          break;
    }
    return DefWindowProcW(hwnd, msg, wParam, lParam);
}


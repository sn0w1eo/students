#define _CRT_SECURE_NO_WARNINGS

#include "windows.h"
#include "tchar.h"

//Свойства проекта —> Компоновщик —> Все параметры —> Подсистема: Windows (/SUBSYSTEM:WINDOWS)


LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);      //Оконная функция.
void DisplayMonitorInfo(HDC);                                      //Отобразить размеры монитора.
void DisplayCPUinfo(HDC);                                          //Отобразить информация ЦП.

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreviosInstance, PSTR szCmdLine, int iCmdShow)
{
	static TCHAR szAppName[] = TEXT("suchara");
	HWND hWindow;
	MSG message;
	WNDCLASS windowClass;

	//Запись характеристик класса окна в структуру.
	windowClass.style = CS_HREDRAW | CS_VREDRAW;                        //Стиль окна.
	windowClass.lpfnWndProc = WindowProcedure;                          //Адресс оконной функции.
	windowClass.cbClsExtra = 0;                                         //?
	windowClass.cbWndExtra = 0;                                         //?
	windowClass.hInstance = hInstance;                                  //Хэндл программы.
	windowClass.hIcon = LoadIcon(NULL, IDI_ASTERISK);                   //Иконка.
	windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);                  //Курсор.
	windowClass.hbrBackground = (HBRUSH)GetStockObject(NULL_BRUSH);     //Кисть которой будет закрашен бэкграунд.
	windowClass.lpszMenuName = NULL;                                    //?
	windowClass.lpszClassName = szAppName;                              //Имя класса окна.

	//Регистрация класса окна.
	if (!RegisterClass(&windowClass))
	{
		MessageBox(NULL, TEXT("oh my dog!"), szAppName, MB_ICONERROR);
		return 0;
	}

	//Создание окна.
	hWindow = CreateWindow(
		TEXT("suchara"),               //Указатель на строку с именем класса окна.
		szAppName,               //Текст для заголовка окна
		WS_OVERLAPPEDWINDOW,     //Стиль окна.
		CW_USEDEFAULT,           //Оступы от края экрана.
		CW_USEDEFAULT,           //Оступы от края экрана.
		CW_USEDEFAULT,           //Оступы от края экрана.
		CW_USEDEFAULT,           //Оступы от края экрана.
		NULL,                    //?
		NULL,                    //?
		hInstance,               //Хэндл программы.
		NULL                     //?
	);
	if (!hWindow)
	{
		MessageBox(NULL, TEXT("Window not created"), TEXT("Error"), MB_OK);
	}

	//Отобразить окно нп экране.
	ShowWindow(hWindow, iCmdShow);
	UpdateWindow(hWindow);

	//Цикл обработки сообщений посылаемых определенному окну.
	while (GetMessage(&message, hWindow, 0, 0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return message.wParam;
}

//Функция окна. Обрабатывает сообщения окну.
LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hDC;
	PAINTSTRUCT ps;

	switch (message)
	{
	case WM_PAINT:                       //Сообщение о перерисовке окна.

		hDC = BeginPaint(hwnd, &ps);     //Перерисовать окно.

		DisplayMonitorInfo(hDC);
		DisplayCPUinfo(hDC);

		EndPaint(hwnd, &ps);

		return 0;

	case WM_DESTROY:                     //Сообщение о закрытии окна.
		PostQuitMessage(0);

		return 0;
	}
	return DefWindowProc(hwnd, message, wParam, lParam);
}

void DisplayMonitorInfo(HDC hDC)
{
	TCHAR text[256];
	int cxScreen, cyScreen;

	//Получить размеры экрана.
	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	//Образовать строку для вывода в окно.
	_stprintf(text, TEXT("Ширина экрана %d пикселей и высота экрана %d пикселей"), cxScreen, cyScreen);

	SetTextColor(hDC, RGB(39, 125, 211));         //Установить цвет для текста.
	TextOut(hDC, 30, 50, text, wcslen(text));     //Отобразить текст.
}

void DisplayCPUinfo(HDC hDC)
{
	TCHAR text[256];
	SYSTEM_INFO siSystemInfo;
	
	//Получить некоторую информацию о системе.
	GetSystemInfo(&siSystemInfo);

	//Образовать строку для вывода в окно.
	_stprintf(text, TEXT("Тип процессора — %u"), siSystemInfo.dwProcessorType);

	SetTextColor(hDC, RGB(168, 84, 0));           //Установить цвет для текста.
	TextOut(hDC, 30, 80, text, wcslen(text));     //Отобразить текст.

	//Образовать строку для вывода в окно.
	_stprintf(text, TEXT("Количество ядер процессора — %u"), siSystemInfo.dwNumberOfProcessors);

	SetTextColor(hDC, RGB(0, 207, 0));             //Установить цвет для текста.
	TextOut(hDC, 30, 100, text, wcslen(text));     //Отобразить текст.
}
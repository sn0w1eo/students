#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "tchar.h"

#define MAX_WIDTH 520  // максимальная ширина 
#define MAX_HEIGHT 380 // максимальная высота

LONG WINAPI windowProcess(HWND, UINT, WPARAM, LPARAM);
void DisplayInfo(HDC hDC);//инфа о дисплеях
void CPUinfo(HDC hDC);    //инфа о CPU
void deviceInfo(HDC hDc); //инфа о девайсах
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2);// нарисовать линию


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
   
    TCHAR appName[] = TEXT("EVEREST 1337");
   
    HWND hWindow; // дескриптор окна
    MSG msg; // структура сообщения
    WNDCLASS cWindow; // структура класса окна

    // Регистрация класса окна
    memset(&cWindow, NULL, sizeof(WNDCLASS));//Заполним Null все поля для удобства 

    cWindow.style = CS_HREDRAW | CS_VREDRAW | CS_BYTEALIGNCLIENT | CS_BYTEALIGNWINDOW; //С Т И Л Ь
    cWindow.lpszClassName = appName;// Имечко
    cWindow.lpfnWndProc = windowProcess; // имя оконной функции
    cWindow.hInstance = hInstance;//Хэндл
    cWindow.hIcon = LoadIcon(0, IDI_WARNING);//Иконка
    cWindow.hCursor = LoadCursor(0, IDC_HAND);//Курсорчик
    cWindow.hbrBackground = (HBRUSH)(COLOR_3DDKSHADOW);//Бэкграунд
    cWindow.lpszClassName = "newClass";//Имя класса(Хз нахуя оно тут)

   /* RegisterClass(&cWindow);*/
    if (!RegisterClass(&cWindow))//Если регистрация прошла неудачно
    {
        MessageBox(NULL, TEXT("Все пошло по пизде дядь..."), appName, MB_ICONERROR);
        return -1;
    }
   
    // Создание окна
    hWindow = CreateWindow(
        "newClass",//имя класса(хз если честно)
        appName,//имя окна
        WS_OVERLAPPEDWINDOW, // С Т И Л Ь
        CW_USEDEFAULT,//расположение по дефолту
        CW_USEDEFAULT,//расположение по дефолту
        MAX_WIDTH,//Ширина окна
        MAX_HEIGHT,//Высота окна
        NULL,//Сирота
        NULL,//Меню нет
        hInstance,// Хэндл
        NULL);//нет передаваемых значений
   
    ShowWindow(hWindow, nCmdShow); // отображение
    UpdateWindow(hWindow);          // перерисовка
    // Цикл обработки сообщений
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}

LONG WINAPI windowProcess(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
    PAINTSTRUCT draw;
    TCHAR text[256]; //буфер
    HDC hDC;  // дисплей
    HPEN hPen; //кисть
    
    switch (Message)
    {
    case WM_PAINT:
        
        hDC = BeginPaint(hwnd, &draw);// начинаем рисовать  
        hPen = CreatePen(PS_SOLID, 2, RGB(0xDD,0xD9,0xD0)); //Создаём перо
        SelectObject(hDC, hPen); //Делаем перо текущим
        

        Rectangle(hDC, 0, 0, MAX_WIDTH, 25); //прямоугольник
        Line(hDC, 325, 25, 325, 220); // линия
        Rectangle(hDC, 0, 220, MAX_WIDTH, 245);
        Line(hDC, 325, 50, MAX_WIDTH, 50);

        //Выводим текст интерфейса 
        _stprintf(text, TEXT("Информация о CPU:"));
        SetTextColor(hDC, RGB(0x05, 0x7D, 0x9F));
        TextOut(hDC, 5, 5, text, wcslen(text));

        _stprintf(text, TEXT("Информация об экране: "));
        TextOut(hDC, 180, 225, text, wcslen(text));

        _stprintf(text, TEXT("Устройства:"));
        TextOut(hDC, 350, 30, text, wcslen(text));

        deviceInfo(hDC);  // Инфа о девайсах
        DisplayInfo(hDC); // Инфа о дисплеях
        CPUinfo(hDC);     // Инфо о CPU
        
        ValidateRect(hDC, NULL);
        EndPaint(hwnd, &draw);

        return 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, Message, wparam, lparam);
    }
    return 0;
}

void DisplayInfo(HDC hDC)
{
    TCHAR text[256];
    int screenX, screenY , numberOfMonitors;

    //Cбор инфы
    screenX = GetSystemMetrics(SM_CXSCREEN);
    screenY = GetSystemMetrics(SM_CYSCREEN);
    numberOfMonitors = GetSystemMetrics(SM_CMONITORS);

    //Вывод
    _stprintf(text, TEXT("Количество мониторов : %d"), numberOfMonitors);//Захуяриваем  в буфер
    SetTextColor(hDC, RGB(0x05, 0x7D, 0x9F));// устанавливаем колор
    TextOut(hDC, 35, 260, text, wcslen(text));// Выводим в окно
    _stprintf(text, TEXT("Ширина экрана %d пикселей и высота экрана %d пикселей"), screenX, screenY);    
    TextOut(hDC, 35, 280, text, wcslen(text));     
}


BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
    MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
    return LineTo(hdc, x2, y2);
}

void deviceInfo(HDC hDC) {
    TCHAR text[256];// Буфер
    BOOL result;// Есть мышь чи не?

    result = GetSystemMetrics(SM_MOUSEPRESENT);//сбор инфы
    //Думаю тут все понятно
    if (result == 0) {
        _stprintf(text, TEXT("Мышь проебали ((9("));
        SetTextColor(hDC, RGB(0xF0, 0x5B, 0x54));
        TextOut(hDC, 350, 70, text, wcslen(text));
    }
    else {
        _stprintf(text, TEXT("Мышь подключена ✓"));
        SetTextColor(hDC, RGB(0x16, 0xCC, 0x2F));
        TextOut(hDC, 350, 70, text, wcslen(text));
    }
}

void CPUinfo(HDC hDC)
{
    TCHAR text[256];
    SYSTEM_INFO pcInfo;

    //Сбор инфы
    GetSystemInfo(&pcInfo);
    _stprintf(text, TEXT("Тип процессора — %u"), pcInfo.dwProcessorType);
    SetTextColor(hDC, RGB(0x63,0x73,0x99));       //Установить цвет 
    TextOut(hDC, 10, 60, text, wcslen(text));     //Отобразить текст

    //Дальше по аналогии 
    _stprintf(text, TEXT("Количество ядер процессора — %u"), pcInfo.dwNumberOfProcessors);
           
    TextOut(hDC, 10, 80, text, wcslen(text));    

    _stprintf(text, TEXT("Активная маска процессора - %u "), pcInfo.dwActiveProcessorMask);
    TextOut(hDC, 10, 100, text, wcslen(text));

    SetTextColor(hDC, RGB(0x16,0xCC,0x2F));
    _stprintf(text, TEXT("Минимальный адрес приложения - %lX "), pcInfo.lpMinimumApplicationAddress);
    TextOut(hDC, 10, 120, text, wcslen(text));

    SetTextColor(hDC, RGB(0xF0,0x5B,0x54));
    _stprintf(text, TEXT("Максимальный адрес приложения - %lX "), pcInfo.lpMaximumApplicationAddress);
    TextOut(hDC, 10, 140, text, wcslen(text));
}
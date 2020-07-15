#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "tchar.h"
//http://cppstudio.com/post/9741/ инфу брал здесь

LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);
void computerInformation(HDC hDC);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //создаем нужные переменные и класссы
    TCHAR className[] = L"класс";
    HWND window;
    MSG message;
    WNDCLASSEX wc;

    //регестрируем класс
    wc.cbSize = sizeof(wc);                                       //размер структуры 
    wc.style = CS_HREDRAW | CS_VREDRAW;                           //стиль окна
    wc.lpfnWndProc = WindowProcess;                               //функция для окна
    wc.lpszMenuName = NULL;                                       //имя меню 
    wc.lpszClassName = className;                                 //имя окна
    wc.cbWndExtra = NULL;                                         //количество дополнительных байтов, выделяемых после экземпляра окна
    wc.cbClsExtra = NULL;                                         //количество дополнительных байтов, выделяемых в соответствии со структурой класса окна
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);                       //вид иконы
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);                     //вид маленькой иконки
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                     //вид курсора
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);       //закраска
    wc.hInstance = hInstance;                                     //

    //проверка зарегестрирован ли класс
    if (!RegisterClassEx(&wc)) {
        // в случае отсутствия регистрации класса:
        MessageBox(NULL,
            L"Не получилось зарегистрировать класс!",
            L"Ошибка", MB_OK);
        return NULL; // WinMain
    }

    window = CreateWindow(className, 
        L"Хелло мазафака",                  // имя окна (то что сверху)
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,   // режимы отображения окошка
        CW_USEDEFAULT,                      // положение окна по оси х
        NULL,                               // позиция окна по оси у 
        CW_USEDEFAULT,                      // ширина окошка
        NULL,                               // высота окна 
        NULL,                               // дескриптор родительского окошка 
        NULL,                               // дескриптор меню 
        hInstance,                          // 
        NULL);                              // ничего не передаём из WndProc
        
    if (!window) {
        // если окно создать не получилось
        MessageBox(NULL, L"Не получилось создать окно!", L"Ошибка", MB_OK);
        return NULL; // выходим из приложения
    }
    // проверяли, создано ли окно
    ShowWindow(window, nCmdShow);
    UpdateWindow(window);
   
    while (GetMessage(&message, window, NULL, NULL)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}


//функция для окна
LRESULT CALLBACK WindowProcess(HWND hWnd,     // дескриптор окошка
    UINT uMsg,                                // сообщение, посылаемое ОС
    WPARAM wParam,                            // параметры
    LPARAM lParam)                            // сообщений, для последующего обращения
{
    // создаём нужные переменные
    HDC hDC;                 // создаём дескриптор ориентации текста на экране
    PAINTSTRUCT ps;          // структура, сод-щая информацию о клиентской области (размеры, цвет и тп)
    TCHAR information[255];  //буфер

    // расписываем условия, при которых нужно выполнить нужное действие 
    switch (uMsg) {
    case WM_PAINT:                   // что то рисуем
        hDC = BeginPaint(hWnd, &ps); 
        
        computerInformation(hDC);   //вывводит в окно информацию о PC
        EndPaint(hWnd, &ps);
       
        break;
    case WM_DESTROY:                // условие закрытия окошка
        PostQuitMessage(NULL); 
        break;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam); 
    }
    // Возвращаем значение функции
    return NULL;
}

void computerInformation(HDC hDC)
{
    //создаем нужные переменные
    TCHAR text[256];  
    SYSTEM_INFO info;

    //получаем информацию о PC
    GetSystemInfo(&info);
    
    // архитектура процессора
    switch (info.wProcessorArchitecture) {
    case 0:
        _stprintf(text, TEXT("Архитектура процессора - x86"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    case 9:
        _stprintf(text, TEXT("Архитектура процессора - x64 (AMD или Intel)"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    case 6:
        _stprintf(text, TEXT("Архитектура процессора - Intel Itanium Processor Family (IPF)"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    default :
        _stprintf(text, TEXT("Архитектура процессора - Неизвестна"));
        TextOut(hDC, 0, 0, text, wcslen(text));
    }

    _stprintf(text, TEXT("%d - количество ядер"), info.dwNumberOfProcessors);
    TextOut(hDC, 0, 20, text, wcslen(text));
}
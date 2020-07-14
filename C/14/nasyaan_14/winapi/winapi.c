#define _CRT_SECURE_NO_WARNINGS

#define DIV 1024

#include "windows.h"
#include "tchar.h"

static UINT ID_edit = 3;
static HWND hWndEdit;
// Описание функции главного окна 
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg,
    WPARAM wParam, LPARAM lParam);
// Глобальные переменные 
HINSTANCE hInst; // Дескриптор экземпляра приложения 
static TCHAR ClassName[] = TEXT("Window"); // Название класса окна 
static TCHAR AppTitle[] = TEXT("HELLO, I`M WINAPI"); // Заголовок главного окна 

//основная функция, аналог int main()

void DisplayMemoryInfo(HDC);

int WINAPI WinMain(HINSTANCE hInstance, // дескриптор экземпляра приложения
	HINSTANCE nPrevInstance, // в Win32 не используется
	LPSTR lpCmdLine, // нужен для запуска окна в режиме командной строки
	int nCmdShow) // режим отображения окна
	{

	static TCHAR str[] = TEXT("hello\n");
	/*int MessageBox(HWND hWnd, дескриптор родительского окна
	LPCTSTR lpText, указатель на строку с сообщением
	LPCTSTR plCaption, указатель на строку с текстом заголовка 
	UINT uType)флаги для отображения кнопок, стиля пиктограммы и прочее;*/

	//окно создаёт кнопку с надписью «ОК» и соответствующим действием при её нажатии
	MessageBox(NULL, str, TEXT("WINAPI by nasyaan"), MB_OK | MB_ICONEXCLAMATION);

    WNDCLASS wc; // Структура для информации о класса окна 
    HWND hWnd; // Дескриптор главного окна приложения 
    MSG msg; // Структура для хранения сообщения 
            
    hInst = hInstance;

    hWnd = FindWindow(ClassName, NULL);
    if (hWnd)
    {
        if (IsIconic(hWnd)) ShowWindow(hWnd, SW_RESTORE);
        SetForegroundWindow(hWnd);
        // Найдена работающая копия - работа новой копии прекращается. 
        return FALSE;
    }
    // Работающая копия не найдена - функция WinMain приступает 
    // к инициализации приложения. 
    // Заполнение структуры WNDCLASS для регистрации класса окна. 
    memset(&wc, 0, sizeof(wc));
    wc.lpszClassName = ClassName; // Имя класса окон 
    wc.lpfnWndProc = (WNDPROC)WndProc; // Адрес оконной функции 
    wc.style = CS_HREDRAW | CS_VREDRAW; // Стиль класса окон 
    wc.hInstance = hInstance; // Экземпляр приложения 
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); // Пиктограмма для окон 
    wc.hCursor = LoadCursor(NULL, IDC_ARROW); // Курсор мыши для окон 
    //wc.hbrBackground = GetStockObject(WHITE_BRUSH); // Кисть для окон 
    wc.lpszMenuName = NULL; // Ресурс меню окон 
    wc.cbClsExtra = 0; // Дополнительная память 
    wc.cbWndExtra = 0; // Дополнительная память 
     // Pегистрация класса окна. 
    RegisterClass(&wc);
    // Создаем главное окно приложения. 
    hWnd = CreateWindow(
        ClassName,// Имя класса окон 
        AppTitle, // Заголовок окна 
        WS_OVERLAPPEDWINDOW, // Стиль окна 
        CW_USEDEFAULT, // X-координаты 
        CW_USEDEFAULT, // Y-координаты 
        CW_USEDEFAULT, // Ширина окна 
        CW_USEDEFAULT, // Высота окна 
        NULL, // Дескриптор окна-родителя 
        NULL, // Дескриптор меню окна 
        hInst, // Дескриптор экземпляра приложения 
        NULL); // Дополнительная информация
    if (!hWnd)
    {
        // Окно не создано, выдаем предупреждение. 
        MessageBox(NULL, TEXT("Create: error"), AppTitle, MB_OK | MB_ICONSTOP);
        return FALSE;
    }
    // Отображаем окно. 
    ShowWindow(hWnd, nCmdShow);
    // Обновляем содержимое клиентской области

    UpdateWindow(hWnd);
    // Запускаем цикл обработки очереди сообщений 
    // Функция GetMessage получает сообщение из очереди. 
    // Она выдает false при выборке из очереди сообщения WM_QUIT 
    while (GetMessage(&msg, NULL, 0, 0))
    {
        // Преобразование некоторых сообщений, 
        // полученных с помощью клавиатуры 
        TranslateMessage(&msg);
        // Отправляем сообщение оконной процедуре 
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
// Функция окна 
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg,
    WPARAM wParam, LPARAM lParam)
{
    HDC hDC;
    PAINTSTRUCT ps;
    switch (msg)
    {
    case WM_PAINT:                       //Сообщение о перерисовке окна.

        hDC = BeginPaint(hWnd, &ps);     //Перерисовывать окно.

        DisplayMemoryInfo(hDC);

        EndPaint(hWnd, &ps);

        return 0;
    case WM_DESTROY: // Пользователь удалил окно. 
       
                     // В функции главного окна следует в очередь 
                     // сообщений послать сообщение WM_QUIT 
        PostQuitMessage(0);
        break;
    default:
        // Необработанные сообщения передаем 
        // в функцию обработки сообщений по умолчанию. 
        return DefWindowProc(hWnd, msg, wParam, lParam);
    }
    return 0;
}

//функция отображения информации о памяти
void DisplayMemoryInfo(HDC hDC)
{
    TCHAR text[256];
    MEMORYSTATUSEX MemoryStatus;

    //Получить статус памяти
    GlobalMemoryStatusEx(&MemoryStatus);

    ////Образовать строку для вывода в окно.
    _swprintf(text, TEXT("There are %*I64d free KB of paging file.\n"), MemoryStatus.ullAvailPageFile / DIV);

    TextOut(hDC, 50, 50, text, wcslen(text)); 

    _swprintf(text, TEXT("There are %*I64d total KB of virtual memory.\n"), MemoryStatus.ullTotalVirtual / DIV);

    TextOut(hDC, 50, 100, text, wcslen(text)); 


}
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>

//LRESULT CALLBACK windowFunction(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam); 
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
//    PSTR szCmdLine, int iCmdShow)
//{
//    static TCHAR szAppName[] = TEXT("Win");
//    HWND hwnd;
//    MSG msg;
//    WNDCLASS wndclass;
//    
//    wndclass.style = CS_HREDRAW | CS_VREDRAW;                     
//    wndclass.lpfnWndProc = windowFunction;                      
//    wndclass.cbClsExtra = 0;                                   
//    wndclass.cbWndExtra = 0;                                    
//    wndclass.hInstance = hInstance;                              
//    wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);            
//    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
//    wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//    wndclass.lpszMenuName = NULL;
//    wndclass.lpszClassName = szAppName;
//
//    if (!RegisterClass(&wndclass))
//    {
//        MessageBox(NULL, TEXT("This program requires Windows NT!"), szAppName, MB_ICONERROR);
//        return 0;
//    }
//
//    hwnd = CreateWindow(szAppName, // window class name
//        TEXT("First window"),      // window caption
//        WS_OVERLAPPEDWINDOW,       // window style
//        CW_USEDEFAULT,             // initial x position
//        CW_USEDEFAULT,             // initial y position
//        CW_USEDEFAULT,             // initial x size
//        CW_USEDEFAULT,             // initial y size
//        NULL,                      // parent window handle
//        NULL,                      // window menu handle
//        hInstance,                 // program instance handle
//        NULL);                     // creation parameters
//
//    // display window
//    ShowWindow(hwnd, iCmdShow);
//    UpdateWindow(hwnd);
//
//    while (GetMessage(&msg, NULL, 0, 0))
//    {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//    }
//
//    return msg.wParam;
//}
//
//LRESULT CALLBACK  windowFunction(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    HDC hdc;
//    PAINTSTRUCT ps;
//    RECT rect;
//
//    switch (message)
//    {
//    case WM_PAINT:                      // Paint the window
//
//        hdc = BeginPaint(hwnd, &ps);
//        GetClientRect(hwnd, &rect);
//        DrawText(hdc, TEXT("Hello, world!!!"), -1, &rect,
//        DT_SINGLELINE | DT_CENTER | DT_VCENTER);
//        EndPaint(hwnd, &ps);
//        return 0;
//
//    case WM_DESTROY:                    // Close the window
//        PostQuitMessage(0);
//
//        return 0;
//    }
//    return DefWindowProc(hwnd, message, wParam, lParam);
//}

void set_coord(int x, int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void set_console_bkcolor(int color, int x, int y)
{
	COORD cursor_position = { 0 };
	cursor_position.X = x;
	cursor_position.Y = y;

	int a = 0;

	FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
		color, 1, cursor_position, &a);
}


int main() {
	system("color 02");
	char message[10] = "ABCDEFGHH";
	int i;
	for (i = 0; i < 10; i++) {
		set_coord(10, i);
		printf("%c\n", message[i]);
		set_console_bkcolor(0x70 | 0x0002, 10, i);
		set_console_bkcolor(0x00 | 0x0002, 10, i-1);
		Sleep(100);
	}
	set_coord(10, i - 1);
	printf(" ");
}
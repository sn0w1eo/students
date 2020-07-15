#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "tchar.h"
//http://cppstudio.com/post/9741/ ���� ���� �����

LRESULT CALLBACK WindowProcess(HWND, UINT, WPARAM, LPARAM);
void computerInformation(HDC hDC);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    //������� ������ ���������� � �������
    TCHAR className[] = L"�����";
    HWND window;
    MSG message;
    WNDCLASSEX wc;

    //������������ �����
    wc.cbSize = sizeof(wc);                                       //������ ��������� 
    wc.style = CS_HREDRAW | CS_VREDRAW;                           //����� ����
    wc.lpfnWndProc = WindowProcess;                               //������� ��� ����
    wc.lpszMenuName = NULL;                                       //��� ���� 
    wc.lpszClassName = className;                                 //��� ����
    wc.cbWndExtra = NULL;                                         //���������� �������������� ������, ���������� ����� ���������� ����
    wc.cbClsExtra = NULL;                                         //���������� �������������� ������, ���������� � ������������ �� ���������� ������ ����
    wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);                       //��� �����
    wc.hIconSm = LoadIcon(NULL, IDI_WINLOGO);                     //��� ��������� ������
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);                     //��� �������
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);       //��������
    wc.hInstance = hInstance;                                     //

    //�������� ��������������� �� �����
    if (!RegisterClassEx(&wc)) {
        // � ������ ���������� ����������� ������:
        MessageBox(NULL,
            L"�� ���������� ���������������� �����!",
            L"������", MB_OK);
        return NULL; // WinMain
    }

    window = CreateWindow(className, 
        L"����� ��������",                  // ��� ���� (�� ��� ������)
        WS_OVERLAPPEDWINDOW | WS_VSCROLL,   // ������ ����������� ������
        CW_USEDEFAULT,                      // ��������� ���� �� ��� �
        NULL,                               // ������� ���� �� ��� � 
        CW_USEDEFAULT,                      // ������ ������
        NULL,                               // ������ ���� 
        NULL,                               // ���������� ������������� ������ 
        NULL,                               // ���������� ���� 
        hInstance,                          // 
        NULL);                              // ������ �� ������� �� WndProc
        
    if (!window) {
        // ���� ���� ������� �� ����������
        MessageBox(NULL, L"�� ���������� ������� ����!", L"������", MB_OK);
        return NULL; // ������� �� ����������
    }
    // ���������, ������� �� ����
    ShowWindow(window, nCmdShow);
    UpdateWindow(window);
   
    while (GetMessage(&message, window, NULL, NULL)) {
        TranslateMessage(&message);
        DispatchMessage(&message);
    }
    return message.wParam;
}


//������� ��� ����
LRESULT CALLBACK WindowProcess(HWND hWnd,     // ���������� ������
    UINT uMsg,                                // ���������, ���������� ��
    WPARAM wParam,                            // ���������
    LPARAM lParam)                            // ���������, ��� ������������ ���������
{
    // ������ ������ ����������
    HDC hDC;                 // ������ ���������� ���������� ������ �� ������
    PAINTSTRUCT ps;          // ���������, ���-��� ���������� � ���������� ������� (�������, ���� � ��)
    TCHAR information[255];  //�����

    // ����������� �������, ��� ������� ����� ��������� ������ �������� 
    switch (uMsg) {
    case WM_PAINT:                   // ��� �� ������
        hDC = BeginPaint(hWnd, &ps); 
        
        computerInformation(hDC);   //�������� � ���� ���������� � PC
        EndPaint(hWnd, &ps);
       
        break;
    case WM_DESTROY:                // ������� �������� ������
        PostQuitMessage(NULL); 
        break;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam); 
    }
    // ���������� �������� �������
    return NULL;
}

void computerInformation(HDC hDC)
{
    //������� ������ ����������
    TCHAR text[256];  
    SYSTEM_INFO info;

    //�������� ���������� � PC
    GetSystemInfo(&info);
    
    // ����������� ����������
    switch (info.wProcessorArchitecture) {
    case 0:
        _stprintf(text, TEXT("����������� ���������� - x86"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    case 9:
        _stprintf(text, TEXT("����������� ���������� - x64 (AMD ��� Intel)"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    case 6:
        _stprintf(text, TEXT("����������� ���������� - Intel Itanium Processor Family (IPF)"));
        TextOut(hDC, 0, 0, text, wcslen(text));
        break;
    default :
        _stprintf(text, TEXT("����������� ���������� - ����������"));
        TextOut(hDC, 0, 0, text, wcslen(text));
    }

    _stprintf(text, TEXT("%d - ���������� ����"), info.dwNumberOfProcessors);
    TextOut(hDC, 0, 20, text, wcslen(text));
}
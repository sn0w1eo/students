#include "winCreator.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    RECT screen_rect;
    MSG msg = { 0 };
    HWND mainWin;
    int rCode = 0;
    LPCTSTR appName = TEXT("XXXELUS_pBook");
    HMENU hMenu = 244;

    if (!RegMyWindowClass(hInstance, appName)) {
        return REG_WINCLASS_FAILED;
    }

    GetWindowRect(GetDesktopWindow(), &screen_rect); 
    int x = screen_rect.left + 500;
    int y = screen_rect.top + 220 ;

    mainWin = CreateWindow(appName,
        TEXT("XXXELUS_pBook"),
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        x,
        y,
        WIN_WIDTH,
        WIN_HEIGHT,
        NULL,
        NULL,
        hInstance,
        NULL);

    

    if (!mainWin) return WIN_NOT_CREATED;

  
      
    while ((rCode = GetMessage(&msg, NULL, 0, 0)) != 0) 
    {
        if (rCode == -1) return GETMSG_ERROR;  
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;  
}



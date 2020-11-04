#include "winCreator.h"
#include "msgHandler.h"




ATOM RegMyWindowClass(HINSTANCE hInst, LPCTSTR lpzClassName)
{
    WNDCLASS mainWinClass = { 0 };
    mainWinClass.lpfnWndProc = (WNDPROC)WndProc;
    mainWinClass.style = CS_HREDRAW | CS_VREDRAW;
    mainWinClass.hInstance = hInst;
    mainWinClass.lpszClassName = lpzClassName;
    mainWinClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    mainWinClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(240, 240, 240));;
    return RegisterClass(&mainWinClass); // регистрация класса
}



void InitComponent(HWND mainWin) {
    HWND hListBox;
    HINSTANCE hInstance = GetModuleHandle(NULL);
    HDC hDC;
    

    // LISTBOX //
    hListBox = CreateWindowExW(WS_EX_CLIENTEDGE,
        L"LISTBOX", NULL,
        WS_CHILD | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY,
        10, 20, 690, 555,
        mainWin, (HMENU)LIST_USERS, hInstance, NULL);

    // BUTTONS //
    HWND btnAdduser = CreateWindow(L"BUTTON",
        L"Add user",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        780, 110, 100, 25,
        mainWin, (HMENU)BTN_ADDUSER, hInstance, NULL);

    HWND btnDelUser = CreateWindow(L"BUTTON",
        L"Delete user",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        750, 310, 100, 25,
        mainWin, (HMENU)BTN_DELUSER, hInstance, NULL);

    HWND btnUpdUser = CreateWindow(L"BUTTON",
        L"Update user",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        780, 250, 100, 25,
        mainWin, (HMENU)BTN_UPDUSER, hInstance, NULL);

    HWND btnSelUser = CreateWindow(L"BUTTON",
        L"Select all users",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        742, 350, 120, 25,
        mainWin, (HMENU)BTN_SELUSER, hInstance, NULL);

    // EDIT CONTROLS //

    HWND edtName = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 20, 120, 25,
        mainWin, (HMENU)EDIT_NAME, hInstance, NULL);

    HWND edtAge = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 50, 120, 25,
        mainWin, (HMENU)EDIT_AGE, hInstance, NULL);

    HWND edtPhone = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 80, 120, 25,
        mainWin, (HMENU)EDIT_PHONE, hInstance, NULL);

    HWND edtUpdName = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 160, 120, 25,
        mainWin, (HMENU)EDIT_UPDNAME, hInstance, NULL);

    HWND edtUpdAge = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 190, 120, 25,
        mainWin, (HMENU)EDIT_UPDAGE, hInstance, NULL);

    HWND edtUpdPhone = CreateWindow(L"Edit",
        NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE,
        770, 220, 120, 25,
        mainWin, (HMENU)EDIT_UPDPHONE, hInstance, NULL);

   // LABLES //

    HWND labelUserSelID = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        150, 580, 120, 13,
        mainWin, (HMENU)LABEL_USERSELID, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), L"ID selected: Not ");
    
    HWND labelUserCount = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        20, 580, 120, 13,
        mainWin, (HMENU)LABEL_USERCOUNT, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_USERCOUNT), L"Total users: 0");


    HWND labelName = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 25, 50, 17,
        mainWin, (HMENU)LABEL_NAME, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_NAME), L"Name:");

    HWND labelAge = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 55, 50, 17,
        mainWin, (HMENU)LABEL_AGE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_AGE), L"Age:");

    HWND labelPhone = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 85, 50, 17,
        mainWin, (HMENU)LABEL_PHONE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_PHONE), L"Phone:");

    HWND labelUpdName = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 165, 50, 17,
        mainWin, (HMENU)LABEL_UPD_NAME, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_UPD_NAME), L"Name:");

    HWND labelUpdAge = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 195, 50, 17,
        mainWin, (HMENU)LABEL_UPD_AGE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_UPD_AGE), L"Age:");

    HWND labelUpdPhone = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        720, 225, 50, 17,
        mainWin, (HMENU)LABEL_UPD_PHONE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_UPD_PHONE), L"Phone:");

    HWND labelLstName = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        30, 2, 102, 17,
        mainWin, (HMENU)LABEL_LST_NAME, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_LST_NAME), L"NAME       ");

    HWND labelLstAge = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        150, 2, 50, 17,
        mainWin, (HMENU)LABEL_LST_AGE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_LST_AGE), L"| AGE |");

    HWND labelLstPhone = CreateWindow(L"static", NULL,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        230, 2, 50, 17,
        mainWin, (HMENU)LABEL_LST_PHONE, hInstance, NULL);
    SetWindowText(GetDlgItem(mainWin, LABEL_LST_PHONE), L"PHONE |");

    
 
    // Блокировка компонентов //
    
    EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState);
    EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);
    EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);
    EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);
    EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState);
}


// Отобразить текст //
void shwIDSelLable(HWND mainWin) {
    WCHAR labelTextId[32];
    swprintf(labelTextId, 32, L"ID selected: %d", getUserId(mainWin) + 1);
    SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), labelTextId);
}
// Отобразить текст //
void shwUserCntLabel(HWND mainWin) {
    WCHAR labelTextCount[32];  
    swprintf(labelTextCount, 32, L"Total users: %d", getUsersCount(mainWin));
    SetWindowText(GetDlgItem(mainWin, LABEL_USERCOUNT), labelTextCount);
}
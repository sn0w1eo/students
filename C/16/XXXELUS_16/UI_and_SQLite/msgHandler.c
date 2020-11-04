#include "msgHandler.h"

DBase database;

PAINTSTRUCT ps;
HDC hdc;
HPEN hPen,hShadowPen;
HBRUSH hBrush;

LRESULT CALLBACK WndProc(HWND mainWin, UINT message, WPARAM wParam, LPARAM lParam) {
   

    switch (message)
    {
    case WM_LBUTTONUP:

        btnDelState = FALSE; // �������� ����������� ������ "Delete"
        btnUpdState = FALSE; // �������� ����������� ������ "Update" � � �����

        SetFocus(mainWin);                                                          //
        SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_SETCURSEL, -1, NULL);    // ������ ����� �� �������� ���� � ������� ��������� � ListBox(���� ��� �������)
        SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), L"ID selected: Not ");  //

        EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState);     //
        EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);     //
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);    // ���������� ������ � ����� ��� �����
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);     //
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState);   //
        break;

    case WM_CREATE:
   
        initDB(&database);  // �������������� ���� ������
        createNewTable(&database); // ������� � ��� �������
        InitComponent(mainWin); // �������������� ��� ���������� 
    
	case WM_COMMAND:

        switch (LOWORD(wParam)) {

            // ������ � ListBox
        case LIST_USERS:

            if (HIWORD(wParam) == LBN_DBLCLK) {
                btnDelState = TRUE; // �������� ����������� ������ "Delete"
                btnUpdState = TRUE; // �������� ����������� ������ "Update" � � �����

                if (btnDelState == TRUE && getUsersCount(mainWin) != 0) {
                    EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState); // ��������� ������ "Delete"
                }

                if (btnUpdState == TRUE && getUsersCount(mainWin) != 0) {
                    EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);   // ��������� ������ "Update" � �� �����
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);  //
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);   //
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState); //
                }


                getUserId(mainWin, wParam);  // ������� ��������� ID ���������� ������ � ListBox   
                shwIDSelLable(mainWin, getUserId(mainWin, wParam)); // ������� ����������� ������ "ID selected" 
            } break;


            if (HIWORD(wParam) == BN_CLICKED) {

                // ������ "add" //
            case BTN_ADDUSER:

                setRecord(mainWin, &database); // ������� ���������� ������
                SendMessage(GetDlgItem(mainWin, EDIT_NAME), WM_SETTEXT, NULL, (L""));   // 
                SendMessage(GetDlgItem(mainWin, EDIT_AGE), WM_SETTEXT, NULL, (L""));   // �������� ����� ��� �����
                SendMessage(GetDlgItem(mainWin, EDIT_PHONE), WM_SETTEXT, NULL, (L"")); //
                break;

                // ������ "delete" //
            case BTN_DELUSER:

                btnDelState = FALSE;
                btnUpdState = FALSE;
                EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState); // ����������� ������ "Delete"
                EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState); // ����������� ������ "Update"

            if (delUser(&database, getUserId(mainWin) + 1) != DB_OK) // ������� �������� ������ � DB
            {
                MessageBox(NULL, L"Deleting failed!", L"Error deleting!", MB_OK | MB_ICONERROR);
            }
            else {
                SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_DELETESTRING, getUserId(mainWin), NULL); // �������� ������ �� ListBox
                shwUserCntLabel(mainWin); // ����������� ������ "Total users"
                SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), L"ID selected: Not ");
            }
            break;

                // ������ "Update" //
            case BTN_UPDUSER:

                btnDelState = FALSE;
                btnUpdState = FALSE;

                updateUser(mainWin, &database); // ���������� �������� � DB

                EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState);   //
                EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);   //
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);  // ����������� ������ � �����
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);   //
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState); //

                SendMessage(GetDlgItem(mainWin, EDIT_UPDNAME), WM_SETTEXT, NULL, (L""));  //
                SendMessage(GetDlgItem(mainWin, EDIT_UPDAGE), WM_SETTEXT, NULL, (L""));   // �������� �����
                SendMessage(GetDlgItem(mainWin, EDIT_UPDPHONE), WM_SETTEXT, NULL, (L"")); //
                break;

                // ������ "Select" //
            case BTN_SELUSER:

                if (selUsers(&database) == DB_USELECT_FAILED) {
                    MessageBox(NULL, L"Users selecting failed!", L"Error selecting!", MB_OK | MB_ICONERROR);
                    return DB_USELECT_FAILED;
                }
                else if (getUsersCount(mainWin) == 0) {
                    MessageBox(NULL, L"No users!", L"Error selecting!", MB_OK | MB_ICONEXCLAMATION);
                }
                else {
                    MessageBox(NULL, L"Users selecting complete!", L"Done!", MB_OK | MB_ICONASTERISK);

                }break;

            }break;

        }break;

    case WM_PAINT:

        hdc = BeginPaint(mainWin, &ps); // �������� ��������
        hPen = CreatePen(PS_SOLID, 4, RGB(140, 140, 140)); // ������� ����
        hShadowPen = CreatePen(PS_SOLID, 2, RGB(180, 180, 180)); // � ��� ����
        hBrush = CreateSolidBrush(RGB(240, 240, 240)); // � ��� �� �����

        SelectObject(hdc, hBrush); // �������� ����� 
        SelectObject(hdc, hPen); // �������� ����

        RoundRect(hdc, 716, 11, 901, 144, 20, 20); // ���� adding
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 12, 899, 143, 20, 20);

        SelectObject(hdc, hPen);
        RoundRect(hdc, 716, 151, 901, 285, 20, 20); // ���� updating
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 152, 899, 284, 20, 20);

        SelectObject(hdc, hPen);
        RoundRect(hdc, 716, 295, 901, 390, 20, 20); // ���� delete
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 296, 899, 389, 20, 20);


        EndPaint(mainWin, &ps); // ��������� ��������

        break; 

    case WM_DESTROY:

        PostQuitMessage(0);
        if (delTable(&database) != DB_OK) { // ����� �������� ���������, ������� ��������� 
            MessageBox(NULL, L"Table drop failed!", L"Error!", MB_OK | MB_ICONERROR);
            return DB_DROP_FAILED;
        } 

        break;

    default:
        return DefWindowProc(mainWin, message, wParam, lParam);
    }
    return 0;
}

// �������� � �������� //

void updateUser(HWND mainWin,DBase* db) {
    
    wchar_t* updRecord = calloc(RECORD_SIZE,sizeof(wchar_t));
    WCHAR updName[128];
    WCHAR updAge[128];
    WCHAR updPhone[128];
    char updNameC[128];
    char updAgeC[128];
    char updPhoneC[128];


    if (getLineLen(mainWin, EDIT_UPDNAME) != 0) {                                   //
        GetWindowText(GetDlgItem(mainWin, EDIT_UPDNAME), updName, 128);             // 
        wcstombs(updNameC, updName, 128);                                           // 
        if (updUser(&database, NAME, getUserId(mainWin) + 1, updNameC) != DB_OK)    // ���� � ���� "Name" ���� �����-���� ��������, �� �������� �� �����
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
        }
    }
    if (getLineLen(mainWin, EDIT_UPDAGE) != 0) {                                    //
        GetWindowText(GetDlgItem(mainWin, EDIT_UPDAGE), updAge, 128);               //
        wcstombs(updAgeC, updAge, 128);                                             //
        if (updUser(&database, AGE, getUserId(mainWin) + 1, updAgeC) != DB_OK)      // ���� � ���� "Age" ���� �����-���� ��������, �� �������� �� ��������
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
        }
    }
    if (getLineLen(mainWin, EDIT_UPDPHONE) != 0) {                                  //
        GetWindowText(GetDlgItem(mainWin, EDIT_UPDPHONE), updPhone, 128);           //
        wcstombs(updPhoneC, updPhone, 128);                                         //
        if (updUser(&database, PHONE, getUserId(mainWin) + 1, updPhoneC) != DB_OK)  // ���� � ���� "Phone" ���� �����-���� ��������, �� �������� �� ��������
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
       }
    }


    updRecord = selRecord(&database, getUserId(mainWin) + 1); // �������� ������������ ����� �� DB
    int id = getUserId(mainWin);
    SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_DELETESTRING, id , NULL);      // �������� 
    SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_INSERTSTRING, id, updRecord);  //
    free(updRecord);
}


// �������� ����� //
void setRecord(HWND mainWin,DBase* db) {

    WCHAR bName[128];
    WCHAR bAge[128];
    WCHAR bPhone[128];
    WCHAR fullRecord[385];
    char name[256];
    char phone[256];
    int age = 0;

    GetWindowText(GetDlgItem(mainWin, EDIT_NAME), bName, 128);                 //
    GetWindowText(GetDlgItem(mainWin, EDIT_AGE), bAge, 128);                  // ����� �������� �� ����� � ������� ������ ������
    GetWindowText(GetDlgItem(mainWin, EDIT_PHONE), bPhone, 128);             //
    swprintf(fullRecord,385, L" %-18s  %-3s  %18s ", bName, bAge, bPhone);  //

   
    wcstombs(name, bName, 256);   //
    wcstombs(phone, bPhone, 256); // ������������ 
    age = _wtoi(bAge);            //

    if (addUser(db, name, phone, age) != DB_OK) // ��������� � DB
    {
        MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR);
        exit(0);
    }
    else {
        SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_ADDSTRING, 0, fullRecord); // ��������� ������ ������ � Listbox
        shwUserCntLabel(mainWin);  // ���������� ���������� ������
    }
}

// ����� ���������� ������ //
int getUsersCount(HWND mainWin) {
    int userCount = SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_GETCOUNT, 0, 0);
    return userCount;
}

// ����� ID ����������� ����� //
int getUserId(HWND mainWin) {
   int id = SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_GETCURSEL, NULL, NULL);
   return id;
}
// ����� ����� ������ � ������//
int getLineLen(HWND mainWin, int winID) {
    int lineLenght = SendMessage(GetDlgItem(mainWin, winID), EM_LINELENGTH, -1, NULL);
    return lineLenght;
}
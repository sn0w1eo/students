#define _CRT_SECURE_NO_WARNINGS
#include "gui.h"

DBInfo db;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR lpCmdLine, int nCmdShow)
{
    InitDB(&db);
    CreateTable(&db);

    AddRecordToDB(&db, "Valeria",   "0552789898",  "exorcism@gmail.com",     "photo\\lera.bmp");
    AddRecordToDB(&db, "Liza",      "0553003198",  "azlanilif@gmail.com",    "photo\\liza.bmp");
    AddRecordToDB(&db, "Bogdan",    "0701252666",  "bogdan@gmail.com",       "photo\\bogdan.bmp");
    AddRecordToDB(&db, "Anastasia", "0773665511",  "ladygaga@gmail.com",     "photo\\nastya.bmp");
    AddRecordToDB(&db, "Natali",    "0559309306",  "perseverance@gmail.com", "photo\\natali.bmp");
    AddRecordToDB(&db, "Kostya",    "0555342521",  "xxxelus@gmail.com",      "photo\\kostya.bmp");
    AddRecordToDB(&db, "Aijan",     "0700999999",  "eshete@gmail.com",       "photo\\aijan.bmp");
    AddRecordToDB(&db, "Nurik",     "0777665820",  "brodyaga@gmail.com",     "photo\\nurik.bmp");
    AddRecordToDB(&db, "Alina",     "0559309306",  "balabina@gmail.com",     "photo\\alina.bmp");
    AddRecordToDB(&db, "Elizabeth", "0552171717",  "gustman@gmail.com",      "photo\\gustman.bmp");
    AddRecordToDB(&db, "Dmitry",    "0777434229",  "sn01e0@gmail.com",       "photo\\dima.bmp");

    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"Mystery Phone Book";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);


    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Mystery Phone Book",
        WS_VISIBLE | WS_OVERLAPPED | WS_BORDER | WS_SYSMENU,
        250, 100, 750, 1150, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    CloseDB(&db);

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    int selectedContact = 0;
    static HWND hwndListBox, hwndName, hwndPhone, hwndEmail, hwndPhoto,
        hwndAddButton, hwndDeleteButton, hwndUpdateButton, hwndNewPhotoButton,
        hwndClearAll, hwndClearName, hwndClearPhone, hwndClearEmail;
    static HBITMAP hBitmap = { 0 };

    switch (msg) {

    case WM_CREATE:

        //Создание листбокса
        hwndListBox = CreateWindowW(WC_LISTBOXW, NULL, WS_CHILD
            | WS_VISIBLE | WS_VSCROLL | LBS_NOTIFY, 10, 10, LIST_BOX_WIDTH, LIST_BOX_HEIGHT,
            hwnd, (HMENU)IDC_LIST, NULL, NULL);
        InitListBox(hwndListBox, &db);

        //Создание окон ввода
        hwndName = CreateWindowW(WC_EDITW, NULL, WS_CHILD
            | WS_VISIBLE | WS_BORDER | LBS_NOTIFY, 320, 60, EDIT_WINDOW_WIDTH, EDIT_WINDOW_HEIGHT,
            hwnd, (HMENU)ID_EDIT_NAME, NULL, NULL);

        hwndPhone = CreateWindowW(WC_EDITW, NULL, WS_CHILD
            | WS_VISIBLE | WS_BORDER | LBS_NOTIFY, 320, 110, EDIT_WINDOW_WIDTH, EDIT_WINDOW_HEIGHT,
            hwnd, (HMENU)ID_EDIT_PHONE, NULL, NULL);

        hwndEmail = CreateWindowW(WC_EDITW, NULL, WS_CHILD
            | WS_VISIBLE | WS_BORDER | LBS_NOTIFY, 320, 160, EDIT_WINDOW_WIDTH, EDIT_WINDOW_HEIGHT,
            hwnd, (HMENU)ID_EDIT_EMAIL, NULL, NULL);

        //Создание кнопок
        hwndAddButton = CreateWindowW(L"Button", L"Add",
            WS_VISIBLE | WS_CHILD, 427, 195, ADD_BUTTON_WIDTH, ADD_BUTTON_HEIGHT,
            hwnd, (HMENU)ADD_BUTTON, NULL, NULL);

        hwndUpdateButton = CreateWindowW(L"Button", L"Update",
            WS_VISIBLE | WS_CHILD, 325, 205, DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT,
            hwnd, (HMENU)UPDATE_BUTTON, NULL, NULL);

        hwndDeleteButton = CreateWindowW(L"Button", L"Delete",
            WS_VISIBLE | WS_CHILD, 550, 205, DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT,
            hwnd, (HMENU)DELETE_BUTTON, NULL, NULL);

        hwndNewPhotoButton = CreateWindowW(L"Button", L"Add/Update photo",
            WS_VISIBLE | WS_CHILD, 400, 985, DEFAULT_BUTTON_WIDTH * 2, DEFAULT_BUTTON_HEIGHT * 2,
            hwnd, (HMENU)NEW_PHOTO_BUTTON, NULL, NULL);

        hwndClearAll = CreateWindowW(L"Button", L"Clear All Input",
            WS_VISIBLE | WS_CHILD, 393, 10, DEFAULT_BUTTON_WIDTH * 2, DEFAULT_BUTTON_HEIGHT + 15,
            hwnd, (HMENU)CLEAR_ALL_BUTTON, NULL, NULL);
        //	265 62 112 162
        hwndClearName = CreateWindowW(L"Button", L"Clear name",
            WS_VISIBLE | WS_CHILD, 645, 55, DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT + 5,
            hwnd, (HMENU)CLEAR_NAME_BUTTON, NULL, NULL);

        hwndClearPhone = CreateWindowW(L"Button", L"Clear phone",
            WS_VISIBLE | WS_CHILD, 645, 105, DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT + 5,
            hwnd, (HMENU)CLEAR_PHONE_BUTTON, NULL, NULL);

        hwndClearEmail = CreateWindowW(L"Button", L"Clear email",
            WS_VISIBLE | WS_CHILD, 645, 155, DEFAULT_BUTTON_WIDTH, DEFAULT_BUTTON_HEIGHT + 5,
            hwnd, (HMENU)CLEAR_EMAIL_BUTTON, NULL, NULL);

        //Окно для изображения
        hwndPhoto = CreateWindowW(L"Static", L"",
            WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER,
            235, 255, 485, 700, hwnd, (HMENU)ID_PHOTO, NULL, NULL);

        SetFocusToContact(hwnd, selectedContact);
        DisplayContactInfo(hwndName, hwndPhone, hwndEmail, &db, selectedContact + 1);
        DisplayContactPhoto(hwndPhoto, &hBitmap, &db, selectedContact + 1);
        
        break;

    case WM_COMMAND:
        selectedContact = (int)SendMessageW(hwndListBox, LB_GETCURSEL, 0, 0);
        //Обработка листбокса
        if (LOWORD(wParam) == IDC_LIST) {
            if (HIWORD(wParam) == LBN_SELCHANGE) {
                DisplayContactInfo(hwndName, hwndPhone, hwndEmail, &db, selectedContact + 1);
                DisplayContactPhoto(hwndPhoto, &hBitmap, &db, selectedContact + 1);
            }
        }

        //Обработка кнопки add
        if (LOWORD(wParam) == ADD_BUTTON) {
            DoButtonPressEvent(hwnd, &db, ADD_BUTTON);
        }

        //Обработка кнопки update
        if (LOWORD(wParam) == UPDATE_BUTTON) {
            DoButtonPressEvent(hwnd, &db, UPDATE_BUTTON);
        }

        //Обработка кнопки delete
        if (LOWORD(wParam) == DELETE_BUTTON) {
            DoButtonPressEvent(hwnd, &db, DELETE_BUTTON);
            DisplayContactPhoto(hwndPhoto, &hBitmap, &db, selectedContact + 1);
        }

        //Обработка кнопки add/update photo
        if (LOWORD(wParam) == NEW_PHOTO_BUTTON) {
            DoLoadPhotoEvent(hwnd, hwndPhoto, &db, &hBitmap, selectedContact);
        }

        //Обработка кнопок clear да да это костыль но я уже так заебался это писать так что пусть так и останется
        if (LOWORD(wParam) == CLEAR_ALL_BUTTON) {
            ClearAllInput(hwndName, hwndPhone, hwndEmail);
        } else if (LOWORD(wParam) == CLEAR_NAME_BUTTON) {
            SendMessageW(hwndName, WM_SETTEXT, NULL, (L""));
            SetFocusToContact(hwnd, selectedContact);
        } else if (LOWORD(wParam) == CLEAR_PHONE_BUTTON) {
            SendMessageW(hwndPhone, WM_SETTEXT, NULL, (L""));
            SetFocusToContact(hwnd, selectedContact);
        } else if (LOWORD(wParam) == CLEAR_EMAIL_BUTTON) {
            SendMessageW(hwndEmail, WM_SETTEXT, NULL, (L""));
            SetFocusToContact(hwnd, selectedContact);
        }

        break;

    case WM_PAINT:
        DisplayLabels(hwnd);
        break;

        //Сброс фокуса с листбокса
    case WM_LBUTTONUP:
        SetFocus(hwnd);
        SendMessageW(hwndListBox, LB_SETCURSEL, -1, NULL);
        break;

    case WM_DESTROY:
        DropTable(&db);
        DeleteObject(hBitmap);
        PostQuitMessage(0);
        break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}
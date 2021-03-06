#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "gui.h"
#include "phoneBook.h"
#include "stdio.h"
#include "strsafe.h"
#include "sqlite3.h"

struct phoneDB pdb;
int idDB = 4;
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    PWSTR pCmdLine, int nCmdShow) {
	
	// open DB
	initDB(&pdb, "MyPhoneBook.db");

	// delete if we have a table named "PhoneBook"
	dropTable(&pdb, "DROP TABLE IF EXISTS PhoneBook;");

	// create table named "PhoneBook" if not exists
	createTable(&pdb, "CREATE TABLE IF NOT EXISTS PhoneBook(Id INT, Name TEXT, Phone TEXT);");

	// add contact to .db
	insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(1, 'David', '0709565645');");
	insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(2, 'Almaz', '0555555555');");
	insertPersonToDB(&pdb, "INSERT INTO PhoneBook VALUES(3, 'Daniel', '0789456123');");

    MSG  msg;
    WNDCLASSW wc = { 0 };
    wc.lpszClassName = L"MyListBox";
    wc.hInstance = hInstance;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DSHADOW);
    wc.lpfnWndProc = WndProc;
    wc.hCursor = LoadCursor(0, IDC_ARROW);

    RegisterClassW(&wc);
    CreateWindowW(wc.lpszClassName, L"Contacts",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        100, 100, 650, 350, 0, 0, hInstance, 0);

    while (GetMessage(&msg, NULL, 0, 0)) {

        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {
    // Cursor
    int sel = 0;
    switch (msg) {

    case WM_CREATE:
        createListBox(hwnd);
        // Write all data from DB to listBox
        writeDataToListBox(&pdb);
        // Create Buttons
        createButton(L"Add", hwnd, ID_ADD, 320, 220);
        createButton(L"Delete", hwnd, ID_DELETE, 520, 220);
        createButton(L"UpDate", hwnd, ID_UPDATE, 420, 220);
        createButton(L"Clear", hwnd, ID_CLEAR_NAME, 550, 38);
        createButton(L"Clear", hwnd, ID_CLEAR_PHONE, 550, 78);
        // Create EditControls
        createEditControl(L"Edit", &hwnd, EDIT_NAME, 400, 40);
        createEditControl(L"Edit", &hwnd, EDIT_PHONE, 400, 80);
        // Create static Labels
        createLabels(hwnd, L"static", L"Name: ", LABEL_NAME, 350, 40);
        createLabels(hwnd, L"static", L"Phone: ", LABEL_PHONE, 350, 80);
        // disable Buttons
        disableButton(&hwnd, ID_DELETE);
        disableButton(&hwnd, ID_UPDATE);
        break;

    case WM_COMMAND:
        // Cursor position
        sel = (int)SendMessage(GetDlgItem(hwnd, IDC_LIST), LB_GETCURSEL, (WPARAM)0, (LPARAM)0);
        if (LOWORD(wParam) == IDC_LIST) {
            if (HIWORD(wParam) == LBN_SELCHANGE) {
                wchar_t NameW[ARR_SIZE] = { 0 };
                wchar_t PhoneW[ARR_SIZE] = { 0 };
                wchar_t buffer[ARR_SIZE] = { 0 };
                // Get text from ListBox and Write to buffer
                SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_GETTEXT, (WPARAM)sel, (LPARAM)buffer);
                // Find personal rowid
                int ID = parseID(buffer);
                // Find contact by Rowid
                selectContactFromDB(&pdb, &NameW, &PhoneW, ID);
                // Write data to Edit control
                SetWindowTextW(GetDlgItem(hwnd, EDIT_NAME), NameW);
                SetWindowTextW(GetDlgItem(hwnd, EDIT_PHONE), PhoneW);
                // enable Buttons
                enableButton(&hwnd, ID_DELETE);
                enableButton(&hwnd, ID_UPDATE);
            }
        }

        if (LOWORD(wParam) == ID_ADD) {
            wchar_t NameW[ARR_SIZE] = { 0 };
            wchar_t PhoneW[ARR_SIZE] = { 0 };
            char NameC[ARR_SIZE] = { 0 };
            char PhoneC[ARR_SIZE] = { 0 };
            // Get contact from Edit control
            getContact(hwnd, NameW, PhoneW);
            // Convert wchar_t to char
            convertWcharToChar(NameW, NameC, ARR_SIZE);
            convertWcharToChar(PhoneW, PhoneC, ARR_SIZE);
            // Insert contact to DB
            addContactToDB(&pdb, NameC, PhoneC, &idDB);
            // Add personal Rowid
            addID(NameW, idDB);
            // Write to listBox
            SendMessageW(hwndList, LB_ADDSTRING, 0, (LPARAM)NameW);
            // Clear EDIT control
            SetWindowTextW(GetDlgItem(hwnd, EDIT_NAME), L"");
            SetWindowTextW(GetDlgItem(hwnd, EDIT_PHONE), L"");
            idDB++;
        }

        if (LOWORD(wParam) == ID_UPDATE) {
            wchar_t buffer[ARR_SIZE] = { 0 };
            wchar_t NameW[ARR_SIZE] = { 0 };
            wchar_t PhoneW[ARR_SIZE] = { 0 };
            char NameC[ARR_SIZE] = { 0 };
            char PhoneC[ARR_SIZE] = { 0 };
            // Get text from ListBox and Write to buffer
            SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_GETTEXT, (WPARAM)sel, (LPARAM)buffer);
            // Find personal rowid
            int ID = parseID(buffer);
            // Get contact from Edit control
            getContact(hwnd, NameW, PhoneW);
            // Convert wchar_t to char
            convertWcharToChar(NameW, NameC, ARR_SIZE);
            convertWcharToChar(PhoneW, PhoneC, ARR_SIZE);
            // UpDate contact in DB
            upDateContactDB(&pdb, NameC, PhoneC, &ID);
            // Add personal Rowid
            addID(NameW, ID);
            // Delete old data in listBox
            SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_DELETESTRING, (WPARAM)sel, (LPARAM)0);
            // Write new data to listBox (old rowid)
            SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_INSERTSTRING, (WPARAM)sel, (LPARAM)NameW);
            // Disable Buttons
            disableButton(&hwnd, ID_DELETE);
            disableButton(&hwnd, ID_UPDATE);
            // Clear EDIT control
            SetWindowTextW(GetDlgItem(hwnd, EDIT_NAME), L"");
            SetWindowTextW(GetDlgItem(hwnd, EDIT_PHONE), L"");
        }

        if (LOWORD(wParam) == ID_DELETE) {
            wchar_t buffer[ARR_SIZE] = { 0 };   
            // Get text from ListBox and Write to buffer
            SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_GETTEXT, (WPARAM)sel, (LPARAM)buffer);
            // Find personal rowid
            int ID = parseID(buffer);
            // Delete contact from DB
            deleteContactDB(&pdb, ID);
            // Delete contact from listBox
            SendMessageW(GetDlgItem(hwnd, IDC_LIST), LB_DELETESTRING, (WPARAM)sel, (LPARAM)0);
            // Disable Buttons
            disableButton(&hwnd, ID_DELETE);
            disableButton(&hwnd, ID_UPDATE);
            // Clear EDIT control
            SetWindowTextW(GetDlgItem(hwnd, EDIT_NAME), L"");
            SetWindowTextW(GetDlgItem(hwnd, EDIT_PHONE), L"");
        }

        if (LOWORD(wParam) == ID_CLEAR_NAME) {
            SetWindowTextW(GetDlgItem(hwnd, EDIT_NAME), L"");
        }

        if (LOWORD(wParam) == ID_CLEAR_PHONE) {
            SetWindowTextW(GetDlgItem(hwnd, EDIT_PHONE), L"");
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    }

    return (DefWindowProcW(hwnd, msg, wParam, lParam));
}

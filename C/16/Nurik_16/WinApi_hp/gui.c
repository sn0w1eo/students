#define _CRT_SECURE_NO_WARNINGS
#include "windows.h"
#include "gui.h"
#include "commctrl.h"
#include "sqlite3.h"
#include "stdio.h"
#include "phoneBook.h"

// CREATE 
void createListBox(HWND hwnd) {
    hwndList = CreateWindowW(WC_LISTBOXW, NULL, WS_CHILD 
        | WS_VISIBLE | LBS_NOTIFY, 10, 10, 300, 250, hwnd,
        (HMENU)IDC_LIST, NULL, NULL);
}

void createButton(wchar_t* query, HWND hwnd, int ID_ , int x, int y) {
    CreateWindowW(L"Button", query,
        WS_VISIBLE | WS_CHILD,
        x, y, 80, 25, hwnd, (HMENU)ID_, NULL, NULL);
}

void createEditControl(wchar_t* query, HWND *hwnd, int EDIT_, int x, int y){
     CreateWindowW(query, NULL,
        WS_CHILD | WS_VISIBLE | WS_BORDER,
        x, y, 150, 20, *hwnd, (HMENU)EDIT_,
        NULL, NULL);
}

void createLabels(HWND hwnd, wchar_t* query, wchar_t* name, int LABEL_, int x, int y) {
    CreateWindow(query, name,
        WS_CHILD | WS_VISIBLE | WS_TABSTOP,
        x, y, 50, 17,
        hwnd, (HMENU)LABEL_, NULL, NULL);
}

// WRITE All Data from DB to ListBox
void writeDataToListBox(struct phoneDB* pdb) {
    sqlite3_stmt* st;
    sqlite3_prepare(pdb->db, "SELECT * FROM PhoneBook;", -1, &st, NULL);
    wchar_t buffer[ARR_SIZE] = { 0 };
    wchar_t bufferID[10] = { L"ID " };
    while (1) {
        int rc = sqlite3_step(st);
        if (rc == SQLITE_ROW) {
            swprintf(buffer, ARR_SIZE, L"%hs ", sqlite3_column_text(st, 1));
            swprintf(bufferID + 3, 10, L"%hs", sqlite3_column_text(st, 0));
            wcscat(buffer, bufferID);
            SendMessageW(hwndList, LB_ADDSTRING, 0, (LPARAM)buffer);
        }
        else if (rc == SQLITE_DONE) {
            break;
        }
    }
}
// Select contact from DB
void selectContactFromDB(struct phoneDB* pdb, wchar_t* Name[ARR_SIZE], wchar_t* Phone[ARR_SIZE], int ID) {
    char* query = malloc(100);
    sprintf(query, "SELECT * FROM PhoneBook WHERE Id = %d;", ID);
    sqlite3_stmt* st;
    sqlite3_prepare(pdb->db, query, -1, &st, NULL);
    int rc;
    rc = sqlite3_step(st);
    if (rc == SQLITE_ROW) {
        swprintf(Name, ARR_SIZE, L"%hs ", sqlite3_column_text(st, 1));
        swprintf(Phone, ARR_SIZE, L"%hs", sqlite3_column_text(st, 2));
    }
    free(query);
}
// INSERT Contact to DB
void addContactToDB(struct phoneDB* pdb, char* NameC, char* PhoneC, int* idDB) {
    char* query = malloc(1000);
    sprintf(query, "INSERT INTO PhoneBook VALUES(%d, '%s', '%s');", *idDB, NameC, PhoneC);
    insertPersonToDB(pdb, query);
    free(query);
}
// UPDATE Contact in DB
void upDateContactDB(struct phoneDB* pdb, char* NameC, char* PhoneC, int* ID) {
    char* query = malloc(1000);
    sprintf(query, "UPDATE PhoneBook SET Name = '%s', Phone = '%s' WHERE id = %d; ", NameC, PhoneC, *ID);
    updatePersonFromDB(pdb, query);
}

// DELETE Contact in DB
void deleteContactDB(struct phoneDB* pdb, int ID) {
    char* query = malloc(1000);
    sprintf(query, "DELETE FROM PhoneBook WHERE Id = %d;", ID);
    deletePersonFromDB(pdb, query);
    free(query);
}

// Find Rowid
int	 parseID(wchar_t* buffer) {
    wchar_t value[10];
    int j = 0, k, i = 0, ID;
    for (j = i + 1; ; i++, j++) {
        if (buffer[i] == 'I' && buffer[j] == 'D') {
            break;
        }
    }
    j += 2;
    k = j + 10;
    for (i = 0; j < k; j++, i++) {
        value[i] = buffer[j];
    }
    ID = _wtoi(value);
    return ID;
}

// Add Rowid for new Contact
void  addID(wchar_t* NameW, int idDB) {
    wchar_t buffer[ARR_SIZE] = { 0 };
    swprintf(buffer, ARR_SIZE, L"%s ID %d", NameW, idDB);
    swprintf(NameW, L"%s", buffer);
}

// Get from Edit Control
void getContact(HWND hwnd, wchar_t* NameW, wchar_t* PhoneW) {
    GetWindowText(GetDlgItem(hwnd, EDIT_NAME), NameW, ARR_SIZE);
    GetWindowText(GetDlgItem(hwnd, EDIT_PHONE), PhoneW, ARR_SIZE);
}

// Others
void convertWcharToChar(wchar_t* arg, char* arg1, int len) {
    wcstombs(arg1, arg, len);
}

void disableButton(HWND* hwnd, int ID_) {
    EnableWindow(GetDlgItem(*hwnd, ID_), FALSE);
}

void enableButton(HWND* hwnd, int ID_) {
    EnableWindow(GetDlgItem(*hwnd, ID_), TRUE);
}
#ifndef GUI_H
#define GUI_H

#include "windows.h"
#include "commctrl.h"
#include "strsafe.h"
#include "phonebook.h"

#define LIST_BOX_WIDTH         200
#define LIST_BOX_HEIGHT        950

#define EDIT_WINDOW_WIDTH      315
#define EDIT_WINDOW_HEIGHT     20

#define ADD_BUTTON_WIDTH       100
#define ADD_BUTTON_HEIGHT      40
#define DEFAULT_BUTTON_WIDTH   80
#define DEFAULT_BUTTON_HEIGHT  25


#define IDC_LIST               0
#define ID_EDIT_NAME           1
#define ID_EDIT_PHONE          2
#define ID_EDIT_EMAIL          3
#define ID_PHOTO               4

#define ADD_BUTTON             6
#define UPDATE_BUTTON          7
#define DELETE_BUTTON          8
#define NEW_PHOTO_BUTTON       9
#define CLEAR_ALL_BUTTON       10
#define CLEAR_NAME_BUTTON      11
#define CLEAR_PHONE_BUTTON     12
#define CLEAR_EMAIL_BUTTON     13


#define BY_NAME                "Name"
#define BY_EMAIL               "Email"
#define BY_PHONE               "Phone"
#define BY_PHOTO               "Photo"

typedef struct {
	wchar_t wcsName[ARRAY_SIZE];
	wchar_t wcsPhone[ARRAY_SIZE];
	wchar_t wcsEmail[ARRAY_SIZE];
	wchar_t wcsPhoto[ARRAY_SIZE];

	char mbName[ARRAY_SIZE];
	char mbPhone[ARRAY_SIZE];
	char mbEmail[ARRAY_SIZE];
	char mbPhoto[ARRAY_SIZE];
}ContactBuffer;

typedef struct {
	HWND hwndName;
	HWND hwndPhone;
	HWND hwndEmail;
	HWND hwndPhoto;
	HWND hwndList;
	HWND hwndAddButton;
	HWND hwndUpdateButton;
	HWND hwndDeleteButton;
	HWND hwndNewPhotoButton;
}ChildWindows;

void GetInputBoxesStrings(ContactBuffer* contactBuffer, ChildWindows* childWindows);
void DisplayContactInfo(HWND hwndName, HWND hwndPhone,
	HWND hwndEmail, DBInfo* db, int contactCode);
void DisplayContactPhoto(HWND hwndPhoto, HBITMAP* hBitmap, DBInfo* db, int contactCode);
void DisplayLabels(HWND hwnd);
void DoButtonPressEvent(HWND hwnd, DBInfo* db, int button);
void DoLoadPhotoEvent(HWND hwnd, HWND hwndPhoto, DBInfo* db, HBITMAP* hBitmap, int selectedContact);
void InitListBox(HWND hwndListBox, DBInfo* db);
wchar_t* GetImagePath(HWND hwnd);
SetFocusToContact(HWND hwnd, int selectedContact);
void ClearAllInput(HWND hwndName, HWND hwndPhone, HWND hwndEmail);

#endif // !GUI_H

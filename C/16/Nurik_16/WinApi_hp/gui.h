#ifndef WINAPI_H
#define WINAPI_H

#define IDC_LIST		1
#define IDC_STATIC		2

#define ID_ADD			3
#define ID_DELETE		4
#define ID_UPDATE		5
#define ID_SAVE			6
#define ID_CLEAR_NAME	7
#define ID_CLEAR_PHONE  8

#define EDIT_NAME		9
#define EDIT_PHONE		10

#define LABEL_NAME		11
#define LABEL_PHONE		12

#define DISABLE_DELETE  13
#define DISABLE_UPDATE  14

#define ARR_SIZE	    50

HWND hwndList;
// Create
void	createListBox(HWND hwnd);
void	createButton(wchar_t* query, HWND hwnd, int ID_, int x, int y);
void	createEditControl(wchar_t* query, HWND* hwnd, int EDIT_, int x, int y);
void	createLabels(HWND hwnd, wchar_t* query, wchar_t* name, int LABEL_, int x, int y);
// Select
void	writeDataToListBox(struct phoneDB* pdb);
void	selectContactFromDB(struct phoneDB* pdb, wchar_t* Name[ARR_SIZE], wchar_t* Phone[ARR_SIZE], int ID);
// Delete
void	deleteContactDB(struct phoneDB* pdb, int ID);

// Update
void	upDateContactDB(struct phoneDB* pdb, char* NameC, char* PhoneC, int* ID);

// Add
void	addContactToDB(struct phoneDB* pdb, char* NameC, char* PhoneC, int* idDB);
void	addID(wchar_t* NameW, int idDB);

// Others
void	convertWcharToChar(wchar_t* arg, char* arg1, int len);
void    disableButton(HWND* hwnd, int ID_);
void	enableButton(HWND* hwnd, int ID_);
void	getContact(HWND hwnd, wchar_t* NameW, wchar_t* PhoneW);
int		parseID(wchar_t* buffer);
#endif // !WINAPI_H


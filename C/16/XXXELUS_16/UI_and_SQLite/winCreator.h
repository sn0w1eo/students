#ifndef WINCREATOR_H
#define WINCREATOR_H

#include "DBfunc.h"
#include "windows.h"
#include "tchar.h"

BOOLEAN btnDelState;
BOOLEAN btnUpdState;

// Window Size //
#define WIN_WIDTH  925
#define WIN_HEIGHT 640

// Errors //
#define REG_WINCLASS_FAILED 1
#define WIN_NOT_CREATED		2
#define GETMSG_ERROR		3

// Components //
#define LIST_USERS			0x01
#define BTN_ADDUSER			0x02
#define BTN_DELUSER			0x03
#define BTN_UPDUSER			0x04
#define BTN_SELUSER			0x05
#define EDIT_NAME	        0x06
#define EDIT_AGE			0x07
#define EDIT_PHONE			0x08
#define LABEL_USERSELID		0x09
#define LABEL_USERCOUNT		0x0A
#define LABEL_NAME			0x0B
#define LABEL_AGE			0x0C
#define LABEL_PHONE			0x0D
#define EDIT_UPDNAME		0x0F
#define EDIT_UPDAGE			0x10
#define EDIT_UPDPHONE		0x11
#define LABEL_UPD_NAME		0x12
#define LABEL_UPD_AGE		0x13
#define LABEL_UPD_PHONE		0x14
#define LABEL_LST_NAME      0x15
#define LABEL_LST_AGE		0x16
#define LABEL_LST_PHONE		0x17

ATOM RegMyWindowClass(HINSTANCE, LPCTSTR);
void InitComponent(HWND mainWin);
void shwIDSelLable(HWND mainWin);
void shwUserCntLabel(HWND mainWin);


#endif // WINCREATOR_H
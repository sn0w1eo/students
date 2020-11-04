#ifndef MSGHANDLER_H
#define MSGHANDLER_H

#include "winCreator.h"

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

void setRecord(HWND mainWin,DBase* db);
void updateUser(HWND mainWin, DBase* db);

int getUserId(HWND mainWin);
int getUsersCount(HWND mainWin);
int getLineLen(HWND mainWin, int winID);

#endif 
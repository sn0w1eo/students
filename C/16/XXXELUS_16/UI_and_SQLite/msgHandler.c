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

        btnDelState = FALSE; // Проверка доступности кнопки "Delete"
        btnUpdState = FALSE; // Проверка доступности кнопки "Update" и её полей

        SetFocus(mainWin);                                                          //
        SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_SETCURSEL, -1, NULL);    // Меняем фокус на основное окно и убираем выделение в ListBox(Если оно имеется)
        SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), L"ID selected: Not ");  //

        EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState);     //
        EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);     //
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);    // Блокировка кнопок и полей для ввода
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);     //
        EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState);   //
        break;

    case WM_CREATE:
   
        initDB(&database);  // Инициализируем базу данных
        createNewTable(&database); // Создаем в ней таблицу
        InitComponent(mainWin); // Инициализируем все компоненты 
    
	case WM_COMMAND:

        switch (LOWORD(wParam)) {

            // Работа с ListBox
        case LIST_USERS:

            if (HIWORD(wParam) == LBN_DBLCLK) {
                btnDelState = TRUE; // Проверка доступности кнопки "Delete"
                btnUpdState = TRUE; // Проверка доступности кнопки "Update" и её полей

                if (btnDelState == TRUE && getUsersCount(mainWin) != 0) {
                    EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState); // Активация кнопки "Delete"
                }

                if (btnUpdState == TRUE && getUsersCount(mainWin) != 0) {
                    EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);   // Активация кнопки "Update" и ее полей
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);  //
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);   //
                    EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState); //
                }


                getUserId(mainWin, wParam);  // Функция получения ID выделенной строки в ListBox   
                shwIDSelLable(mainWin, getUserId(mainWin, wParam)); // Функция отображения текста "ID selected" 
            } break;


            if (HIWORD(wParam) == BN_CLICKED) {

                // Кнопка "add" //
            case BTN_ADDUSER:

                setRecord(mainWin, &database); // Функция добавления записи
                SendMessage(GetDlgItem(mainWin, EDIT_NAME), WM_SETTEXT, NULL, (L""));   // 
                SendMessage(GetDlgItem(mainWin, EDIT_AGE), WM_SETTEXT, NULL, (L""));   // Отчистка полей для ввода
                SendMessage(GetDlgItem(mainWin, EDIT_PHONE), WM_SETTEXT, NULL, (L"")); //
                break;

                // Кнопка "delete" //
            case BTN_DELUSER:

                btnDelState = FALSE;
                btnUpdState = FALSE;
                EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState); // Деактивация кнопки "Delete"
                EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState); // Деактивация кнопки "Update"

            if (delUser(&database, getUserId(mainWin) + 1) != DB_OK) // Функция удаления записи в DB
            {
                MessageBox(NULL, L"Deleting failed!", L"Error deleting!", MB_OK | MB_ICONERROR);
            }
            else {
                SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_DELETESTRING, getUserId(mainWin), NULL); // Удаление записи из ListBox
                shwUserCntLabel(mainWin); // Отображение текста "Total users"
                SetWindowText(GetDlgItem(mainWin, LABEL_USERSELID), L"ID selected: Not ");
            }
            break;

                // Кнопка "Update" //
            case BTN_UPDUSER:

                btnDelState = FALSE;
                btnUpdState = FALSE;

                updateUser(mainWin, &database); // Обновление контакта в DB

                EnableWindow(GetDlgItem(mainWin, BTN_DELUSER), btnDelState);   //
                EnableWindow(GetDlgItem(mainWin, BTN_UPDUSER), btnUpdState);   //
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDNAME), btnUpdState);  // Деактивация кнопок и полей
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDAGE), btnUpdState);   //
                EnableWindow(GetDlgItem(mainWin, EDIT_UPDPHONE), btnUpdState); //

                SendMessage(GetDlgItem(mainWin, EDIT_UPDNAME), WM_SETTEXT, NULL, (L""));  //
                SendMessage(GetDlgItem(mainWin, EDIT_UPDAGE), WM_SETTEXT, NULL, (L""));   // Отчистка полей
                SendMessage(GetDlgItem(mainWin, EDIT_UPDPHONE), WM_SETTEXT, NULL, (L"")); //
                break;

                // Кнопка "Select" //
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

        hdc = BeginPaint(mainWin, &ps); // Начинаем рисовать
        hPen = CreatePen(PS_SOLID, 4, RGB(140, 140, 140)); // Создаем перо
        hShadowPen = CreatePen(PS_SOLID, 2, RGB(180, 180, 180)); // И еще одно
        hBrush = CreateSolidBrush(RGB(240, 240, 240)); // А так же кисть

        SelectObject(hdc, hBrush); // Выбираем кисть 
        SelectObject(hdc, hPen); // Выбираем перо

        RoundRect(hdc, 716, 11, 901, 144, 20, 20); // окно adding
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 12, 899, 143, 20, 20);

        SelectObject(hdc, hPen);
        RoundRect(hdc, 716, 151, 901, 285, 20, 20); // окно updating
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 152, 899, 284, 20, 20);

        SelectObject(hdc, hPen);
        RoundRect(hdc, 716, 295, 901, 390, 20, 20); // окно delete
        SelectObject(hdc, hShadowPen);
        RoundRect(hdc, 710, 296, 899, 389, 20, 20);


        EndPaint(mainWin, &ps); // Закончили рисовать

        break; 

    case WM_DESTROY:

        PostQuitMessage(0);
        if (delTable(&database) != DB_OK) { // После закрытия программы, таблица дропается 
            MessageBox(NULL, L"Table drop failed!", L"Error!", MB_OK | MB_ICONERROR);
            return DB_DROP_FAILED;
        } 

        break;

    default:
        return DefWindowProc(mainWin, message, wParam, lParam);
    }
    return 0;
}

// Перейдем к костылям //

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
        if (updUser(&database, NAME, getUserId(mainWin) + 1, updNameC) != DB_OK)    // Если в поле "Name" есть какое-либо значение, то апдейтим по имени
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
        }
    }
    if (getLineLen(mainWin, EDIT_UPDAGE) != 0) {                                    //
        GetWindowText(GetDlgItem(mainWin, EDIT_UPDAGE), updAge, 128);               //
        wcstombs(updAgeC, updAge, 128);                                             //
        if (updUser(&database, AGE, getUserId(mainWin) + 1, updAgeC) != DB_OK)      // Если в поле "Age" есть какое-либо значение, то апдейтим по возрасту
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
        }
    }
    if (getLineLen(mainWin, EDIT_UPDPHONE) != 0) {                                  //
        GetWindowText(GetDlgItem(mainWin, EDIT_UPDPHONE), updPhone, 128);           //
        wcstombs(updPhoneC, updPhone, 128);                                         //
        if (updUser(&database, PHONE, getUserId(mainWin) + 1, updPhoneC) != DB_OK)  // Если в поле "Phone" есть какое-либо значение, то апдейтим по телефону
        {                                                                           //
            MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR); //
            exit(0);                                                                //
       }
    }


    updRecord = selRecord(&database, getUserId(mainWin) + 1); // Получаем обновленного юзера из DB
    int id = getUserId(mainWin);
    SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_DELETESTRING, id , NULL);      // Заменяем 
    SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_INSERTSTRING, id, updRecord);  //
    free(updRecord);
}


// Добавить юзера //
void setRecord(HWND mainWin,DBase* db) {

    WCHAR bName[128];
    WCHAR bAge[128];
    WCHAR bPhone[128];
    WCHAR fullRecord[385];
    char name[256];
    char phone[256];
    int age = 0;

    GetWindowText(GetDlgItem(mainWin, EDIT_NAME), bName, 128);                 //
    GetWindowText(GetDlgItem(mainWin, EDIT_AGE), bAge, 128);                  // Берем значения из полей и создаем полную запись
    GetWindowText(GetDlgItem(mainWin, EDIT_PHONE), bPhone, 128);             //
    swprintf(fullRecord,385, L" %-18s  %-3s  %18s ", bName, bAge, bPhone);  //

   
    wcstombs(name, bName, 256);   //
    wcstombs(phone, bPhone, 256); // Конвертируем 
    age = _wtoi(bAge);            //

    if (addUser(db, name, phone, age) != DB_OK) // Добавляем в DB
    {
        MessageBox(NULL, L"Updating failed!", L"Error!", MB_OK | MB_ICONERROR);
        exit(0);
    }
    else {
        SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_ADDSTRING, 0, fullRecord); // Добавляем полную запись в Listbox
        shwUserCntLabel(mainWin);  // Отобразить количество юзеров
    }
}

// Взять количество юзеров //
int getUsersCount(HWND mainWin) {
    int userCount = SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_GETCOUNT, 0, 0);
    return userCount;
}

// Взять ID выделенного юзера //
int getUserId(HWND mainWin) {
   int id = SendMessage(GetDlgItem(mainWin, LIST_USERS), LB_GETCURSEL, NULL, NULL);
   return id;
}
// Взять длину строки в байтах//
int getLineLen(HWND mainWin, int winID) {
    int lineLenght = SendMessage(GetDlgItem(mainWin, winID), EM_LINELENGTH, -1, NULL);
    return lineLenght;
}
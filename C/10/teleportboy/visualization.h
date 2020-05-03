#ifndef VISUALIZATION_H
#define VISUALIZATION_H

typedef unsigned char uchar;

void DisplayCell(int shiftX, int shiftY, int size, uchar symbol);
void DisplayFrames(uchar** list);
void DisplayActions();
void DisplayCap(uchar** list);
void DisplayContacts(uchar** list);
void BackSpace(int amount);
void ClearInputField(int rowNumber);
void DisplayActions();
void ChooseAction(int rowNumber, int color);
void DisplayDeleteActions();
void ChooseDeleteAction(int rowNumber, int color);
void DisplayUpdateActions();
void ChooseUpdateAction(int rowNumber, int color);
void SelectRow(int rowNumber, int color);
void ChooseRow(int rowNumber, int color);
void SetColor(int color);
void ClearChooseMenu();
void DisplayHotkeys();

#endif // !VISUALIZATION

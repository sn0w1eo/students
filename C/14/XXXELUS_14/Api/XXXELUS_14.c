#include "stdio.h"
#include "windows.h"
#include "locale.h"

#define NAMESIZE 35 // Размер имени

typedef struct {
    INT screenX;//Ширина
    INT screenY;//Высота
    TCHAR namePc[NAMESIZE];//Буфер для имени
    SYSTEM_INFO pcInfo;// структура инфы
    BOOL mouseInstal;// проверка мыши
}FULL_INFO;


int main() {
    setlocale(LC_ALL, "Russian");
    FULL_INFO PC;
    DWORD namesize = 35;
    GetSystemInfo(&PC.pcInfo);// получение инфы 
    if (GetComputerNameA(PC.namePc, &namesize)) {   // Получение имени компа
        printf("---------- PC name: %s ----------\n", PC.namePc);
    }
    else {
        printf("Failed to read PC name..");
    }
    PC.mouseInstal = GetSystemMetrics(SM_MOUSEPRESENT);// получение инфы о подключенной мышке
    PC.screenX = GetSystemMetrics(SM_CXSCREEN);// Ширина экрана в пикселях
    PC.screenY = GetSystemMetrics(SM_CYSCREEN);// Высота экрана в пикселях

    //Отображение структуры SYSTEM_INFO
    printf("----------------------------------------------------------------------\n");
    printf("  OEM ID: %u\n", PC.pcInfo.dwOemId);
    printf("  Number of processors: %u\n", PC.pcInfo.dwNumberOfProcessors);
    printf("  Page size: %u\n", PC.pcInfo.dwPageSize);
    printf("  Processor type: %u\n", PC.pcInfo.dwProcessorType);
    printf("  Minimum application address: %lx\n", PC.pcInfo.lpMinimumApplicationAddress);
    printf("  Maximum application address: %lx\n", PC.pcInfo.lpMaximumApplicationAddress);
    printf("  Active processor mask: %u\n", PC.pcInfo.dwActiveProcessorMask);
    printf("----------------------------------------------------------------------\n");
    printf("Mouse info:\n");
    if (PC.mouseInstal == 0) {
        printf("No mouse installed.\n");
    }
    else {
        printf("Mouse installed.\n");
    }
    printf("----------------------------------------------------------------------\n");
    printf("Screen info: ");
    printf("Width : %d px     Height: %d px\n", PC.screenX, PC.screenY);
    printf("----------------------------------------------------------------------\n");
   
}

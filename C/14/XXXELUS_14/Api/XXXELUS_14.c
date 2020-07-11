#include "stdio.h"
#include "windows.h"
#include "locale.h"

#define NAMESIZE 35 // ������ �����

typedef struct {
    INT screenX;//������
    INT screenY;//������
    TCHAR namePc[NAMESIZE];//����� ��� �����
    SYSTEM_INFO pcInfo;// ��������� ����
    BOOL mouseInstal;// �������� ����
}FULL_INFO;


int main() {
    setlocale(LC_ALL, "Russian");
    FULL_INFO PC;
    DWORD namesize = 35;
    GetSystemInfo(&PC.pcInfo);// ��������� ���� 
    if (GetComputerNameA(PC.namePc, &namesize)) {   // ��������� ����� �����
        printf("---------- PC name: %s ----------\n", PC.namePc);
    }
    else {
        printf("Failed to read PC name..");
    }
    PC.mouseInstal = GetSystemMetrics(SM_MOUSEPRESENT);// ��������� ���� � ������������ �����
    PC.screenX = GetSystemMetrics(SM_CXSCREEN);// ������ ������ � ��������
    PC.screenY = GetSystemMetrics(SM_CYSCREEN);// ������ ������ � ��������

    //����������� ��������� SYSTEM_INFO
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

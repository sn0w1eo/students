#define _CRT_SECURE_NO_WARNINGS
#include "phonebookFunc.h"

int main(void) {
    PhoneDB pdb;
    InitDB("phonebook.db", &pdb);
    DropTable(&pdb);
    CreateTable(&pdb);
    InsertContact(&pdb, "Dmitry", "0705770013");
    InsertContact(&pdb, "Kirill", "0555661796");
    InsertContact(&pdb, "Konstantin", "0553233717");
    InsertContact(&pdb, "Bogdan", "0770368836");
    InsertContact(&pdb, "Nurdoolot", "0709233778");
    InsertContact(&pdb, "Safi", "0555123456");
    InsertContact(&pdb, "Anastasia", "0700436842");
    InsertContact(&pdb, "lalala", "123");
    DeleteContact(&pdb, 7);
    UpdateContact(&pdb, "Safi", "0123456789", "Safii");
    SelectTable(&pdb);
    CloseDB(&pdb);
    return 0;
}
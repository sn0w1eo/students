#define _CRT_SECURE_NO_WARNINGS
#include "phonebook.h"

//инициализация базы данных
int InitDB(const char* filename, PhoneDB* pdb) {
    pdb->rc = sqlite3_open(filename, &pdb->db);
    //проверка на наличие ошибок
    if (pdb->rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", pdb->err_msg);
        CloseDB(pdb->db);
        return 1;
    }
    return 0;
}

//закрытие базы данных
void CloseDB(PhoneDB* pdb) {
    sqlite3_close(pdb->db);
}

//создание таблицы
int CreateTable(PhoneDB* pdb) {
    char* sql = "CREATE TABLE Phonebook(Name TEXT, Phone TEXT)";
    pdb->rc = sqlite3_exec(pdb->db, sql, 0, 0, &pdb->err_msg);
    if (pdb->rc != SQLITE_OK) {
        fprintf(stderr, "Failed to create table\n");
        fprintf(stderr, "SQL error: %s\n", pdb->err_msg);
        sqlite3_free(pdb->err_msg);
        return 1;
    }
    fprintf(stdout, "Table Phonebook created successfully\n");
    return 0;
}

//удаление существующих данных
int DropTable(PhoneDB* pdb) {
    char* sql = "DROP TABLE IF EXISTS Phonebook;";
    pdb->rc = sqlite3_exec(pdb->db, sql, 0, 0, &pdb->err_msg);
    if (pdb->rc != SQLITE_OK) {
        fprintf(stderr, "Failed to create table\n");
        fprintf(stderr, "SQL error: %s\n", pdb->err_msg);
        sqlite3_free(pdb->err_msg);
        return 1;
    }
    fprintf(stdout, "Existed table dropped successfully\n");
    return 0;

}

//добавление контакта
int InsertContact(PhoneDB* pdb, const char* name, const char* phone) {
    sqlite3_stmt* st;
    char* sql = "INSERT INTO Phonebook (Name, Phone) VALUES(?, ?);";
    pdb->rc = sqlite3_prepare(pdb->db, sql, -1, &st, NULL);
    if (pdb->rc != SQLITE_OK) {
        sqlite3_free(pdb->err_msg);
        return 1;
    }
    sqlite3_bind_text(st, 1, name, (int)strlen(name), SQLITE_TRANSIENT);
    sqlite3_bind_text(st, 2, phone, (int)strlen(phone), SQLITE_TRANSIENT);
    sqlite3_step(st);
    return sqlite3_finalize(st);
}

//отображение таблицы
int SelectTable(PhoneDB* pdb) {
    char* sql = "SELECT * FROM Phonebook";
    pdb->rc = sqlite3_exec(pdb->db, sql, callback, 0, &pdb->err_msg);
    if (pdb->rc != SQLITE_OK) {
        fprintf(stderr, "Failed to select data\n");
        fprintf(stderr, "SQL error: %s\n", pdb->err_msg);
        return 1;
    }
    return pdb->rc;
}

//callback функция для sqlite3_exec в функции SelectTable
int callback(void* notUsed, int size, char** value, char** columnName) {
    notUsed = 0;
    for (int i = 0; i < size; i++) {
        printf("\n%s = %s", columnName[i], value[i]);
    }
    printf("\n");
    return 0;
}

//удаление контакта
int DeleteContact(PhoneDB* pdb, const int ID) {
    char sql[100];
    sprintf(sql, "DELETE FROM Phonebook WHERE [rowid] = %d;", ID);
    pdb->rc = sqlite3_exec(pdb->db, sql, 0, 0, &pdb->err_msg);
    if (pdb->rc != SQLITE_OK) {

        fprintf(stderr, "Failed to delete contact\n");
        fprintf(stderr, "SQL error: %s\n", pdb->err_msg);
        sqlite3_free(pdb->err_msg);

    }
    return pdb->rc;
}

//изменение контакта
int UpdateContact(PhoneDB* pdb, const int ID, const char* newName, const char* newPhone) {
    char sql[150];
    sprintf(sql, "UPDATE Phonebook SET Name = \"%s\", Phone = \"%s\" WHERE ID = \"%d\";", newName, newPhone, ID);
    pdb->rc = sqlite3_exec(pdb->db, sql, 0, 0, &pdb->err_msg);
    if (pdb->rc != SQLITE_OK) {
        fprintf(stderr, "Failed to update contact\n");
        fprintf(stderr, "SQL error: %s\n", pdb->err_msg);
        sqlite3_free(pdb->err_msg);
    }
    return pdb->rc;
}

char* SelectContact(PhoneDB* pdb, int ID, char* criterion)
{
    char* query = (char*)calloc(150, sizeof(char));
    static char selectResult[150] = { 0 };
    sqlite3_stmt* st = NULL;
    if (query) {
        sprintf(query, "SELECT %s FROM Phonebook WHERE [rowid] = %d", criterion, ID);

        int rc = sqlite3_prepare_v2(pdb->db, query, -1, &st, 0);
        if (rc != SQLITE_OK) return NULL;

        if (sqlite3_step(st) == SQLITE_ROW) {
            sprintf(selectResult, "%s", sqlite3_column_text(st, 0));
        }

        sqlite3_finalize(st);

        free(query);
        query = NULL;

        return selectResult;

    }
    else return NULL;
}

wchar_t* SelectPhone(PhoneDB* pdb, int id)
{
    sqlite3_stmt* stmt;

    char* query = (char*)calloc(128, sizeof(char));
    wchar_t* selectResult = (wchar_t*)calloc(128, sizeof(wchar_t));

    sprintf(query, "SELECT Phone FROM Phonebook WHERE [rowid] = %d", id);

    int rc = sqlite3_prepare_v2(pdb->db, query, -1, &stmt, 0);
    if (rc != SQLITE_OK) return NULL;

    if (sqlite3_step(stmt) == SQLITE_ROW) {

        swprintf(selectResult, 128, L"%s", (wchar_t*)sqlite3_column_text16(stmt, 0));
    }

    sqlite3_finalize(stmt);

    free(query);
    query = NULL;

    return selectResult;
}

#define _CRT_SECURE_NO_WARNINGS
#include "functions.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//проверка на ошибки
int errorCheck(database* phoneDB) {
	//если ошибка то выводим сообщение, очищаем память
	if (phoneDB->exit != SQLITE_OK) {	
		printf("ERROR: %d %s\n", phoneDB->exit, sqlite3_errmsg(phoneDB->db));
		sqlite3_close(phoneDB->db);	//закрываем дискриптор 
		sqlite3_free(phoneDB->err_msg);	//очищаем сообщение об ошибке
		if (phoneDB->sql != NULL) {
			free(phoneDB->sql);
		}
		return -1;
	}
	return 0;
}


int openDatabase(database* phoneDB, char* nameDatabase) {

	phoneDB->exit = sqlite3_open(nameDatabase, phoneDB);	//открываем или создаем файл 
	//проверка на выполнение SQL команды
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	printf("database created\n\n");
	return 0;
}

int createTable(database* phoneDB) {
	//в буфер вписываем SQL команду
	phoneDB->sql = "CREATE TABLE IF NOT EXISTS phoneBook(Id INTEGER PRIMARY KEY, Name TEXT NOT NULL UNIQUE, Phone INT);";	//создаем таблицу с полями(имя уникальное)
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);			//компилирует SQL команду
	// проверка на добавление в таблицу
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	return 0;
}

//добавить персону в таблицу
int addPerson(database* phoneDB, const char* name, const unsigned int phone) {

	//создаем буфер
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	//заносим в буфер команду SQL
	sprintf(phoneDB->sql, "INSERT OR IGNORE INTO phoneBook (Name, Phone) VALUES('%s', %d);", name,phone);  //если имя повторяется то не заносит в БД

	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);	//компилируем 
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);			//очищаем буфер
	return 0;
}

//функция обратного вызова используемая в функции sqlite3_exec()
//функция выводит в консоль нашу БД
int callback(void* NotUsed,		//обычно не используется (передается 4й аргумент функции sqlite3_exec)
	int numberOfElements,		//количество элементов в строке
	char** arrayOfText,			//массив в который записывается данные строки
	char** azColName)			//массив в который записывается имена полей
{
	NotUsed = 0;
	for (int i = 0; i < numberOfElements; i++) {
		printf("%-10s   ", arrayOfText[i]);
	}
	printf("\n");
	return 0;
}

//выводит в консоль нашу БД
int printPersons(database* phoneDB) {

	phoneDB->sql = "SELECT * FROM phoneBook";
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, callback, 0, phoneDB->err_msg);
	
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	return 0;
}

int dropTable(database* phoneDB) {
	 phoneDB->exit = sqlite3_exec(phoneDB->db, "DROP TABLE IF EXISTS phoneBook;", NULL, NULL, phoneDB->err_msg);
	 if (errorCheck(phoneDB) != 0) {
		 return -1;
	 }
	 sqlite3_close(phoneDB->db);	//закрываем дискриптор 
	 sqlite3_free(phoneDB->err_msg);	//очищаем сообщение об ошибке
	 return 0;
}

int deletePerson(database* phoneDB, enum delet idOrNameOrPhone, const int id, const char* name, const int phone) {
	//создаем буфер
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(100, sizeof(char));
	//заносим в буфер код 
	switch (idOrNameOrPhone)
	{
	case ID:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Id = %d;", id);
		break;

	case NAME:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Name = '%s';\n", name);
		break;

	case PHONE:
		sprintf(phoneDB->sql, "DELETE FROM phoneBook WHERE Phone = %d;\n", phone);
		break;
	}
	//компилируем код
	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);//очищаем буфер
	return 0;
}

int updatePerson(database* phoneDB, const char* nameInDB, const int phoneInDB,
	 const char* nameUpdate, const int phoneUpdate) {

	int stringLength = 0;
	phoneDB->sql = NULL;
	phoneDB->sql = calloc(200, sizeof(char));

	if (nameInDB != NULL) {
		stringLength += sprintf(phoneDB->sql, "UPDATE phoneBook SET Name = '%s' WHERE Name = '%s';\n", nameUpdate, nameInDB);
	}
	
	if (phoneInDB != NULL) {
		stringLength += sprintf(phoneDB->sql + stringLength, "UPDATE phoneBook SET Phone = %d WHERE Phone = %d;", phoneUpdate, phoneInDB);
	}

	phoneDB->exit = sqlite3_exec(phoneDB->db, phoneDB->sql, 0, 0, phoneDB->err_msg);
	if (errorCheck(phoneDB) != 0) {
		return -1;
	}
	free(phoneDB->sql);
	return 0;
}
#include "functions.h"
//http://zetcode.com/db/sqlitec/ инфу брал здесь


int main() {

	database phoneDB;		//создаем структуру в которой всё для SQL кода
	phoneDB.err_msg = NULL;
	phoneDB.sql = NULL;

	
	//всегда выполняем проверку на правильность исполнения программы
	if (openDatabase(&phoneDB, "database.db") != 0) {//открываем (создаём) файл где будет наша БД
		return -1;
	}
	if (createTable(&phoneDB) != 0){			//создаем таблицу
		return -1;
	}

	//в таблицу вносим данные(имя и телефон)
	if (addPerson(&phoneDB, "Dima", 123) != 0) return -1;
	if (addPerson(&phoneDB, "Kril", 156) != 0) return -1;
	if (addPerson(&phoneDB, "Nastya", 8674) != 0) return -1;
	if (addPerson(&phoneDB, "Konstantin", 58557) != 0) return -1;
	if (addPerson(&phoneDB, "Bogdan", 165848) != 0) return -1;
	//если имя повторяется то не заносит в бд
	if (addPerson(&phoneDB, "Nurdoolot", 44574) != 0) return -1;
	if (addPerson(&phoneDB, "Nurdolot", 44574) != 0) return -1;
	if (addPerson(&phoneDB, "Nurdoolot", 44574) != 0) return -1;
	if (addPerson(&phoneDB, "Safi", 598) != 0) return -1;

	//удаляем людей из БД
	//можно удалить по (Id, Name, Phone)
	if (deletePerson(&phoneDB, ID, 5, (const char)NULL, (const int)NULL) !=0) return -1;
	if (deletePerson(&phoneDB, NAME, (const int)NULL, "Bogdan", (const int)NULL) != 0) return -1;
	if (deletePerson(&phoneDB, PHONE, (const int)NULL, (const char)NULL, 123) != 0) return -1;

	//обновляем инфу в БД
	//updatePerson(1. указатель на структуру, 2. имя которое хотим изменить. 3. номер который хотим изменить. 4 и 5 на что хотим изменить)
	if (updatePerson(&phoneDB, "Nastya", 8674, "Anastasiya", 123) != 0) return -1;
	if (updatePerson(&phoneDB, "Kril", 156, "Kirill", (const int)NULL) != 0) return -1;

	//выводим на консоль БД
	if (printPersons(&phoneDB) != 0) return -1;
	
	//удаляем таблицу в БД и очищаем память
	if (dropTable(&phoneDB) != 0) return -1;
	return 0;
}
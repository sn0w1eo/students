
#include "stdio.h"
#include "algorithm.h"




int main() {
	

	data db = initStorage(10);			//выделяем память

	//добавляем персонажей
	addPerson(&db, "Bogdan", 29, 1123);	
	addPerson(&db, "Dima", 13, 13123);
	addPerson(&db, "Artur", 234, 5123);
	addPerson(&db, "Ira", 45, 1233);
	addPerson(&db, "Kirill", 5, 14123);

	//сортируем
	//sortStorage(&db, byName, descending);         // byName, byAge, byEarnings //ascending ,descending 

	//БЛОК КОДА для файлов Txt
	//{
	//	writeToFileTxt(&db);								//создаем и записываем в файл
	//	freeStorage(&db);									//очистить память
	//	size_t numberOfPerson = readNumberFromFileTxt();	//получить количество персонажей в файле
	//	data database = initStorage(numberOfPerson);		//выделяем память 
	//	readPersonsFromFileTxt(&database);					//читаем и заносим в память персонажей с файла
	//	printStorage(&database);							//вывести то что лежит в памяти
	//	freeStorage(&database);								//очистить память
	//}
	//КОНЕЦ БЛОКА
	

	//БЛОК КОДА для файлов bin
	{
		writeToFileBin(&db);				// создаем файл и записываем туда данные с динамической памяти 
		freeStorage(&db);					// очищаем динамическую память 
		data database = initStorage(10);	// выделяем динамическую память 
		readPersonFromFileBin(&database);	// читаем даанные с файла и записываем в динамическую память
		printStorage(&database);			//выводим в консоль что лежит в динамической памяти
		freeStorage(&database);				// очищаем память
	}
	getch();
	return 0;
}
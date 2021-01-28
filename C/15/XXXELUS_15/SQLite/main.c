#include "DBfunc.h"

int main() {
	DBase database;
	initDB(&database);
	createNewTable(&database);
	addUser(&database, "oleg1", "+99655445456", 15);
	addUser(&database, "oleg2", "+99655445456", 15);
	delUser(&database, 2);
	addUser(&database, "oleg3", "+99655445456", 15);
	selUsers(&database);
	updUser(&database, PHONE, 2, "166666");
	closeDB(&database);
}

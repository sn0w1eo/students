#include "Func.h"

/*Did not figure out where to put callback*/

int main() {

	contact* users = initStorage(5);
	FILE* st = NULL;
	users = add(users,"Loqiemean", "+76658522154", "loqie@gmail.com", "7000548");
	users = add(users, "Skriptonite", "+2138123", "skrip@", "1333312");
	users = add(users, "ATL", "+45845441", "uuusd@", "58956665");
	users = add(users, "Markul", "+844255225", "mark@", "121222");
	users = add(users, "OXXXYMIRON", "+7515186", "oxxx@", "41551");
	users = add(users, "Lil Peep", "+84452132", "peep@", "000000");
	show(users);
	wait();

	printf("UPDATING 5 NUMBER:\n");
	update(users, "Zaebal_etot", "korobka_windows", "pivka_by", "ebnut'",5);
	show(users);
	wait();
	
	printf("DELETED 3ht NUMBER:\n");
	delete(users, 3);
	show(users);
	wait();

	printf("SEARCHING:\n");
	srhName(users, "Markul");
	srhNumber(users, "+76658522154");

	printf("READING OR WRITING\n");
	//save(st, users, Binary);   // Text or Binary
	read(st, users, Text);      // Text  of Binary
	freeMemory(users);
	return 0;

}
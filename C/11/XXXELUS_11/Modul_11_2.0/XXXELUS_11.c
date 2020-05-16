#include "Func.h"

/*Did not figure out where to put callback*/

int main() {

	contact* users = initStorage(5);
	users = add(users,"Loqiemean", "+76658522154", "loqie@gmail.com", "7000548");
	users = add(users, "Skriptonite", "+2138123", "skrip@", "1333312");
	users = add(users, "ATL", "+45845441", "uuusd@", "58956665");
	users = add(users, "Markul", "+844255225", "mark@", "121222");
	users = add(users, "OXXXYMIRON", "+7515186", "oxxx@", "41551");
	users = add(users, "Lil Peep", "+84452132", "peep@", "000000");
	show(users);
	wait();

	update(users, "Zaebal etot", "korobka windows", "pivka by", "ebnut'",5);
	show(users);
	wait();

	delete(users, 3);
	show(users);
	wait();

	srhName(users, "Markul");
	srhNumber(users, "+76658522154");
	wait();
}
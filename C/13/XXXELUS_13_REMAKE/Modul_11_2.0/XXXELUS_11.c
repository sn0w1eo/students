#include "Func.h"



int main() {

	contact* users = initStorage(5);
	users = addNewContact(users,"Loqiemean", "+76658522154", "loqie@gmail.com", "7000548");
	users = addNewContact(users, "Skriptonite", "+2138123", "skrip@", "1333312");
	users = addNewContact(users, "ATL", "+45845441", "uuusd@", "58956665");
	users = addNewContact(users, "Markul", "+844255225", "mark@", "121222");
	users = addNewContact(users, "OXXXYMIRON", "+7515186", "oxxx@", "41551");
	users = addNewContact(users, "Lil Peep", "+84452132", "peep@", "000000");
	//show(users);
	//wait();

	//printf("UPDATING 5 NUMBER:\n");
	//update(users, "Zaebal_etot", "korobka_windows", "pivka_by", "ebnut'",5);
	//show(users);
	//wait();
	//
	//printf("DELETED 3ht NUMBER:\n");
	//delete(users, 3);
	//show(users);
	//wait();

	//printf("SEARCHING:\n");
	//srhName(users, "Markul");
	//srhNumber(users, "+76658522154");

	printf("\nREAD BINARY FILE:\n");
	binContact* readDat = calloc(10, sizeof(contact));
	saveToBin(users);
	//readDAT(users, readDat);
	printf("\nREAD TEXT FILE: \n");
	//saveToText(users);
    //readTextFile(users);

	//freeMemory(users);
	return 0;

}
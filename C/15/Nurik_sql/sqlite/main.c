#include "stdio.h"

#include "operations.h"


int main()
{ 
    initDB("MyPhoneBook.db");                                                           // open DB and check our DB Function Result
    createTable("PhoneBook");                                                           // create table named "PhoneBook" if not exists

    insertPersonToDB("David",  "12312323");                                             // add contact to .db
    insertPersonToDB("Thomas", "12332124");                                             // add contact to .db
    insertPersonToDB("Daniel", "99999999");                                             // add contact to .db
    
    deletePersonFromDB(NAME, "David");                                                  // delete contact where NAME = "David"
    updatePersonFromDB("Daniel", PHONE, "88888888");                                    // update PHONE where NAME = "Daniel" 
    selectPersonsFromDB();                                                              // read from BD

   /* dropTable();    */                                                                // delete if we have a table named "PhoneBook"

    sqlite3_close(db);                                                                  //  function closes the database connection

    return 0;
}
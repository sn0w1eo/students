#include "stdio.h"

#include "operations.h"


int main()
{ 
    initDB("MyPhoneBook.db");                                                           // open DB and check our DB Function Result
    createTable("CREATE TABLE IF NOT EXISTS PhoneBook(Id INT, Name TEXT, Age INT);");   // create table named "PhoneBook" if not exists

    insertPersonToDB("INSERT INTO PhoneBook VALUES(1, 'David', 23);");                  // add contact to .db
    insertPersonToDB("INSERT INTO PhoneBook VALUES(2, 'Thomas', 24);");                 // add contact to .db
    insertPersonToDB("INSERT INTO PhoneBook VALUES(3, 'Daniel', 26);");                 // add contact to .db
    
    deletePersonFromDB("DELETE FROM PhoneBook WHERE Id = 2;");                          // delete contact where id = 2
    updatePersonFromDB("UPDATE PhoneBook SET Name = 'Raman', Age = 20 WHERE id = 1;");  // update first value
    selectPersonsFromDB("SELECT * FROM PhoneBook;");                                    // read from BD

    dropTable("DROP TABLE IF EXISTS PhoneBook;");                                       // delete if we have a table named "PhoneBook"

    sqlite3_close(db);                                                                  //  function closes the database connection

    return 0;
}
#ifndef OPERATIONS_H
#define OPERATIONS_H

#define BUFFER_SIZE 100  

typedef	struct
{
	int size;
	char name[10];
	char phone[15];
	char age[5];
}contact;

enum modeFile { 
	Binary,
	Text
};

enum dataOfPerson {
	Name = 1,
	Phone
};


void addPerson(contact* person, char name[10], char phone[15], char age[5]);  // add persons to array of struct

void writeToFile(contact* person, int mode);                                  // write Binary mode and Text mode 

void readFromFileToArray(contact* person, int mode);                          // read Binary mode and Text mode 

void printDataToConsole(contact* person, int mode);                           // write (Binary mode and Text mode) -> TO CONSOLE 

void bufferToArrayStruct(char buffer[BUFFER_SIZE], contact* person);          // write to Array struct from buffer (buffer from text file)

#endif // !OPERATIONS_H

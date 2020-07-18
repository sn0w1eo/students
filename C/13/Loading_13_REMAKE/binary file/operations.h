#ifndef OPERATIONS_H
#define OPERATIONS_H

typedef struct
{
	char* name;    // Имя     30 
	char* number;  // Номер   30
	char* age;      // Возраст 5
}contact;

// Add person to array 
void add(contact* , char name[30], char number[30], char age[5]);

// Change zero '\0' at the end of the string to space ' ' 
void changeZeroToSpace(contact* );

// Change space ' ' at the end of the string to zero '\0'
void changeSpaceToZero(contact*);

// Write persons to binary FILE
void writeToBinary(FILE*, contact* );

// Write persons to text FILE
void writeToText(FILE* , contact* );

// Read from FILE to array
void readFileToArray();

void strcopy(char*, const char*);

#endif // !OPERATIONS_H

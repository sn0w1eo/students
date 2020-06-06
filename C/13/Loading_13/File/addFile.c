#include "addFile.h"

void writeFile(FILE* stream, MyStructFile* contact)
{
	for (int i = 0; i < 5; i++)
	{
		fprintf(stream, "%d)   %s   %5d   %s\n", i, contact[i].name, contact[i].age, contact[i].number);
	}
}

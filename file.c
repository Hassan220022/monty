#include "monty.h"
/**
 * openFile - opens a file
 * @fileName: the name of the file to open
 */
void openFile(char *fileName)
{
	FILE *file = fopen(fileName, "r");

	if (!file || !fileName)
	{
		error(2, fileName);
	}
	readFile(file);
	fclose(file);
}

/**
 * readFile - reads a file
 * @fileName: the file to read
 */
void readFile(FILE *fileName)
{
	int lineNumber, formate = 0;
}
int lenChars(char *);
void parseLine(char *, int, int);
void findFunction(char *, int, int);

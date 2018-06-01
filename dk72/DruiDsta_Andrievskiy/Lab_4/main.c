#include <stdio.h>
#include <stdlib.h>
#include "dru_lib.h"

int main(int argc, char *argv[]) 
{
	CharList *theList = TLCreateCharList();
	
	if (NULL == theList)	return -1;

	FILE *file = fopen("file.txt","r");
	readFileToList(file,theList);
	fclose(file);
	TLPrintList(theList);
	TLDestroyCharList(theList);
	system("pause");
	
	return 0;
}

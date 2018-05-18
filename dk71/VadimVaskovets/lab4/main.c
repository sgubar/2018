#include <stdio.h>
#include <stdlib.h>
#include "dk_tool.h"

int main(int argc, char *argv[]) {
	CharList *theList = TLCreateCharList();
	if (NULL == theList)
	{
		return -1;
	}

	FILE *file = fopen("lab4.txt","r");
	readFileToList(file,theList);
	fclose(file);
	TLPrintFromTheEnd(theList);
	TLDestroyCharList(theList);
	system("PAUSE");
	
	return 0;
}

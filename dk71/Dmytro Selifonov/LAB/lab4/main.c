#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

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

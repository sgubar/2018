#include "l5.h"
#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
	CharList *theList = SLCreateList();
	
	FILE *file = fopen("mmmain.c", "r+");
	rtf(file, theList);

	
	bal_d(theList);
	SLFreeList(theList);

	printf("Done.\n");
	fclose(file);
	system("pause");
	return 0;
}



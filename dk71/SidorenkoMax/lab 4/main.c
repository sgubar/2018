#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "func.h"

int main(int argc, const char * argv[])
{
	int menu, addposition = 0;
	char addvalue;
	CharList *theList = TLCreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	FILE *file = fopen("1.txt", "r+");
	ReadFromFile(file, theList);	
	AmountBrackets(theList);
	DestroyList(theList);
	return 0;
}

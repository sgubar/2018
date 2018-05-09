#include <stdio.h>
#include <stdlib.h>
#include "dz6.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	FloatList *theList = TLCreateFloatList();
	if (NULL == theList)
	{
		return -1;
	}
	
	TLAddFloatValueToList(theList, 34.0);
	TLAddFloatValueToList(theList, 344.0);
	TLAddFloatValueToList(theList, 343.0);
	TLAddFloatValueToList(theList, 342.0);
	TLAddFloatValueToList(theList, 345.0);
	TLAddFloatValueToList(theList, 346.0);
	TLAddFloatValueToList(theList, 347.0);
	TLAddFloatValueToList(theList, 343.0);
	TLAddFloatValueToList(theList, 345.0);
	
	TLPrintList(theList);
	
	printf ("The value at index %d: %f\n", 3, TLFloatValueAtIndex(theList, 3));

	printf ("The value at index %d: %f\n", 100, TLFloatValueAtIndex(theList, 100));
	
	printf ("The count of value in the list: %d\n", theList->count);
	
	TLInsertFloatValueAtIndex(theList, 123456.0, 3);
	TLPrintList(theList);
	shellSort(theList);
	TLPrintList(theList);

	
	TLDestroyFloatList(theList);
	
	// insert code here...
	printf("Hello, World!\n");
	return 0;
}

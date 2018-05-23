#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "TLIntList.h"

int main(int argc, const char * argv[])
{
	int menu, addposition = 0;
	char addvalue;
	CharList *theList = TLCreateIntList();
	if (NULL == theList)
	{
		return -1;
	}
	
	ListValue(theList, 65);
	ListValue(theList, 66);
	ListValue(theList, 67);
	ListValue(theList, 68);
	ListValue(theList, 73);
	ListValue(theList, 69);
	ListValue(theList, 70);
	ListValue(theList, 71);
	ListValue(theList, 72);
	ListValue(theList, 73);
	
	PrintList(theList);	
	printf("Enter Value: ");
	addvalue = getchar();
	printf("Enter Position:");
	scanf("%d", &addposition);
	InsertValue(theList, addvalue, addposition);
	PrintList(theList);
	printf("Select the item to remove \n");
	scanf("%d", &addposition);
	delete_element(theList, addposition);
	PrintList(theList);		
	quickSort(theList, 0, theList -> count - 1);
	PrintList(theList);
	DestroyList(theList);

	printf("Hello, World!\n");
	return 0;
}

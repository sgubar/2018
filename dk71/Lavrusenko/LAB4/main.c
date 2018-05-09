#include <stdlib.h>
#include "ListItem.h"
#include "list.h"





int main()
{

int i;
	printf("Start to demo a single-linked list ...\n");
	
	Item_List *theNode2 = CreateItemOfList(2);
	Item_List *theNode4 = CreateItemOfList(3);
	Item_List *theNode6 = CreateItemOfList(4);
	ListOptions *theList = SLCreateList();
	
	
	
	
	printf("number of elements: %d\n", SLCountList(theList));
	
		SLAddNode(theList, theNode2);
		SLAddNode(theList, theNode4);
		SLAddNode(theList, theNode6);
			printf("number of elements: %d\n", SLCountList(theList));
		
	twiceNode(theList);


	doPrintSLList(theList);
	SLFreeList(theList);
	
	printf("Done.\n");

	return 0;
}




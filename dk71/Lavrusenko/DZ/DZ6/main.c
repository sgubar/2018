#include <stdlib.h>
#include "ListItem.h"
#include "list.h"





int main()
{

int i;
	ListOptions *theList = SLCreateList();	
	Item_List *theNode = CreateItemOfList(0.00);
	
	
	for(i=0;i<21;i++){
		theNode = CreateItemOfList(rand()+0.00);
		
		SLAddNode(theList, theNode);
	}
	printf("number of elements: %d\n", SLCountList(theList));

	shell_sort(theList);
	printf("Done.\n");
	doPrintSLList(theList);
	SLFreeList(theList);
	


	return 0;
}





#include <stdlib.h>
#include "ListItem.h"
#include "list.h"


void doTestSLList();
void doPrintSLList(const ListOptions *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{int i;
	printf("Start to demo a single-linked list ...\n");
	
	Item_List *theNode2 = CreateItemOfList(2);
	Item_List *theNode4 = CreateItemOfList(3);
	Item_List *theNode6 = CreateItemOfList(4);
	ListOptions *theList = SLCreateList();
	
	
	
	
	printf("number of elements: %d\n", SLCountList(theList));
	
		SLAddNode(theList, theNode2);
		SLAddNode(theList, theNode4);
		SLAddNode(theList, theNode6);



	doPrintSLList(theList);
	SLFreeList(theList);
	
	printf("Done.\n");
}

void doPrintSLList(const ListOptions *aList)
{
	int i;
	for (i = 0; i < SLCountList(aList); i++)
	{
		Item_List *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

#include <stdio.h>
#include "Dz_6_SingleLinkedNode.h"
#include "Dz_6_SingleLinkedList.h"
#include "Dz_6_sort.h"

void doTestSLList();
void doPrintSLList(const IntList *aList);

int main(int argc, const char * argv[])
{
	doTestSLList();

	return 0;
}

void doTestSLList()
{
	IntList *theList = SLCreateList();
	int N = 0;
	while(N != -1){
		printf("-add node -----------1 \n");
		printf("-removed node -------2 \n");
		printf("-insert node --------3 \n");
		printf("-free list ----------4 \n");
		printf("-size of list -------5 \n");
		printf("-print list ---------6 \n");
		printf("-sort list ----------7 \n");
		printf("-exit ---------------8 \n");
		scanf("%d",&N);
		 if(N == 1){
			int z;
			printf("enter a node value: ");
			scanf("%d",&z);
			SLAddNode(theList, SLCreateNodeWithIntValue(z));
		} else if(N == 2){
			int x;
			printf("number of the node you want to remove: ");
			scanf("%d",&x);
			SLRemovedNodeAtIndex(theList, x);
		} else if(N == 3){
			int a,b;
			printf("enter a node value: ");
			scanf("%d",&a);
			printf("index: ");
			scanf("%d",&b);
			SLInsertNodeAtIndex(theList, SLCreateNodeWithIntValue(a), b);
		} else if(N == 4){
			SLFreeList(theList);
			printf("the list has been deleted...\n");
		} else if(N == 5){
			printf("size of list = %d nodes \n", SLCountList(theList));
		} else if(N == 6){
			doPrintSLList(theList);
		} else if(N == 7){
			printf("Sorting... \n");
			quickSort(theList, 0, theList->count - 1);
			quickSort(theList, 0, theList->count - 1);
		
		} else if(N == 8){
			N = -1;
		} else {
			printf("select operation number 1-9");
		}
	}
	
	printf("Done.\n");
}

void doPrintSLList(const IntList *aList)
{
	int i;
	for (i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

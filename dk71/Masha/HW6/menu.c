#include <stdio.h>
#include"dk_list.h"
void doTestSLList()
{
	IntList *theList = SLCreateList();
	int N = 0;
	while(N != -1){

		printf("Add node 1 \n");
		printf("Removed node 2 \n");
		printf("Insert node 3 \n");
		printf("Free list 4 \n");
		printf("Size of list 5 \n");
		printf("Print list 6 \n");
		printf("Sort list 7 \n");
		printf("Exit 8 \n");
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

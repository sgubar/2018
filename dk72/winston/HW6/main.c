#include <stdio.h>
#include "list.h"

int main(int argc, const char * argv[])
{

    int index;
    double value;

    DoubleList *theList = SLCreateList();

    DoubleNode *theNode = SLCreateNodeWithDoubleValue(22.5);
    DoubleNode *theNode1 = SLCreateNodeWithDoubleValue(36.8);
    DoubleNode *theNode2 = SLCreateNodeWithDoubleValue(45.1);
    DoubleNode *theNode3 = SLCreateNodeWithDoubleValue(43.9);
    DoubleNode *theNode4 = SLCreateNodeWithDoubleValue(44.3);
    DoubleNode *theNode5 = SLCreateNodeWithDoubleValue(99.0);
    DoubleNode *theNode6 = SLCreateNodeWithDoubleValue(60.7);

    SLAddNode(theList, theNode);
    SLAddNode(theList, theNode1);
    SLAddNode(theList, theNode2);
    SLAddNode(theList, theNode3);
    SLAddNode(theList, theNode4);
    SLAddNode(theList, theNode5);
    SLAddNode(theList, theNode6);

    printf("Number of elements(size of List): %d\n\n", SLCountList(theList));
    doPrintSLList(theList);
    printf("\nList was printed!\n\n");

    printf("Enter VALUE for adding Node: ");
    scanf("%lf", &value);
    theNode = SLCreateNodeWithDoubleValue(value);
    SLAddNode(theList, theNode);
    printf("\nNode was added!\n");

    printf("Enter VALUE for insert: ");
    scanf("%lf", &value);
    printf("Enter INDEX for insert: ");
    scanf("%d", &index);
    theNode = SLCreateNodeWithDoubleValue(value);
    SLInsertNodeAtIndex(theList, theNode, index);
    printf("\nNode was inserted!\n\n");

    printf("Enter INDEX for deleting: ");
    scanf("%d", &index);
    SLRemovedNodeAtIndex(theList, index);
    printf("\nNode was deleted!\n\n");

    doPrintSLList(theList);
    printf("\nList was printed!\n");

    quickSort(theList, 0, theList->count-1);
    printf("\nList was sorted!\n");

    doPrintSLList(theList);

    SLFreeList(theList);
    printf("\nList was deleted!\n");

	return 0;
}

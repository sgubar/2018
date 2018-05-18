#include <stdio.h>
#include <stdlib.h>
#include "list.h"

#define N 50

int main(int argc, const char * argv[])
{
    int index,number=0;
    char value[N];

    CharList *theList = SLCreateList();

    CharNode *theNode = SLCreateNodeWithCharValue("enter");
    CharNode *theNode1 = SLCreateNodeWithCharValue("apple");
    CharNode *theNode2 = SLCreateNodeWithCharValue("tree");
    CharNode *theNode3 = SLCreateNodeWithCharValue("founded");
    CharNode *theNode4 = SLCreateNodeWithCharValue("interesting");
    CharNode *theNode5 = SLCreateNodeWithCharValue("quality");
    CharNode *theNode6 = SLCreateNodeWithCharValue("telephone");

    SLAddNode(theList, theNode);
    SLAddNode(theList, theNode1);
    SLAddNode(theList, theNode2);
    SLAddNode(theList, theNode3);
    SLAddNode(theList, theNode4);
    SLAddNode(theList, theNode5);
    SLAddNode(theList, theNode6);

    printf("Start!\n\n");

    printf("Number of elements(size of List): %d\n\n", SLCountList(theList));
    doPrintSLList(theList);

    quickSort(theList, 0, theList->count-1);
    printf("\nList was sorted!\n\n");

    doPrintSLList(theList);

    theNode = theList->head;

    for(int i=1; i<theList->count; i++)
    {
        if(strlen(theNode->value) <= strlen(SLNodeAtIndex(theList,i)->value))
        {
            theNode = SLNodeAtIndex(theList,i);
            number++;
        }
    }

    printf("\nNode of maximum length:\n");
    printf("node[%d].value = %s\n", number, theNode->value);

    SLFreeList(theList);

    printf("\nList was deleted!\n");

	return 0;
}

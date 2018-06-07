
#include <stdio.h>
#include "dk_tool.h"
#include "Sort.h"
void doTestSLList();
void doPrintSLList(const doubleList *aList);

int main(int argc, const char * argv[])
{
    doTestSLList();

    return 0;
}

void doTestSLList()
{
    printf("Single-linked list:...\n");

    doubleNode *theNode2 = SLCreateNodeWithdoubleValue(2);
    doubleNode *theNode4 = SLCreateNodeWithdoubleValue(4);

    doubleList *theList = SLCreateList();
    printf("number of elements: %d\n", SLCountList(theList));

    SLAddNode(theList, theNode2);
    printf("number of elements: %d\n", SLCountList(theList));

    SLAddNode(theList, theNode4);
    printf("number of elements: %d\n", SLCountList(theList));

    SLAddNode(theList, SLCreateNodeWithdoubleValue(7));
    SLAddNode(theList, SLCreateNodeWithdoubleValue(8));

    doubleNode *theNode = SLCreateNodeWithdoubleValue(5);

    SLInsertNodeAtIndex(theList, theNode, 4);
    SLInsertNodeAtIndex(theList, SLCreateNodeWithdoubleValue(10.321123), 4);

    doPrintSLList(theList);
    theNode = SLRemovedNodeAtIndex(theList, 4);
    SLInsertNodeAtIndex(theList, theNode, 2);


    printf("After removing: \n");
    doPrintSLList(theList);

    printf("Sorting: \n");
    quickSort(theList, 0, theList->count - 1);

    doPrintSLList(theList);

    SLFreeList(theList);

    printf("Done.\n");
}

void doPrintSLList(const doubleList *aList)
{
    for (int i = 0; i < SLCountList(aList); i++)
    {
        doubleNode *theNode = SLNodeAtIndex(aList, i);
        if (NULL != theNode)
        {
            printf("node[%d].value = %lf\n", i, theNode->value);
        }
    }
}

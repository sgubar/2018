#include <stdio.h>
#include "tools.h"

void doTestSLList();
void doPrintSLList(const FloatList *aList);

int main(int argc, const char * argv[])
{
    doTestSLList();
    return 0;
}

void doTestSLList()
{
    printf("Start to demo a single-linked list ...\n");
    FloatNode *theNode2 = SLCreateNodeWithIntValue(4.43);
    FloatNode *theNode4 = SLCreateNodeWithIntValue(2.55);
    FloatList *theList = SLCreateList();
    printf("number of elements: %d\n", SLCountList(theList));
    SLAddNode(theList, theNode2);
    printf("number of elements: %d\n", SLCountList(theList));
    SLAddNode(theList, theNode4);
    SLAddNode(theList, SLCreateNodeWithIntValue(7.000));
    SLAddNode(theList, SLCreateNodeWithIntValue(8.425));
    printf("number of elements: %d\n", SLCountList(theList));
    FloatNode *theNode = SLCreateNodeWithIntValue(100.100);
    SLInsertNodeAtIndex(theList, theNode, 4);
    SLInsertNodeAtIndex(theList, SLCreateNodeWithIntValue(10), 4);
    doPrintSLList(theList);
    theNode = SLRemovedNodeAtIndex(theList, 4);
    SLInsertNodeAtIndex(theList, theNode, 2);
    printf("After removing: \n");
    doPrintSLList(theList);
    printf("Sorting: \n");
    shellSort(theList, theList->count);
    doPrintSLList(theList);
    SLFreeList(theList);
    printf("Done.\n");
}

void doPrintSLList(const FloatList *aList)
{
    for (int i = 0; i < SLCountList(aList); i++)
    {
        FloatNode *theNode = SLNodeAtIndex(aList, i);
        if (NULL != theNode)
        {
            printf("node[%d].value = %.3f\n", i, theNode->value);
        }
    }
}

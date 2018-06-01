#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, const char * argv[])
{
    int index;
    double value;

    DoubleList *theList = SLCreateList();

    DoubleNode *theNode = SLCreateNodeWithDoubleValue(22.5);
    DoubleNode *theNode1 = SLCreateNodeWithDoubleValue(36.8);
    DoubleNode *theNode2 = SLCreateNodeWithDoubleValue(9.12);
    DoubleNode *theNode3 = SLCreateNodeWithDoubleValue(50.4);
    DoubleNode *theNode4 = SLCreateNodeWithDoubleValue(44.3);
    DoubleNode *theNode5 = SLCreateNodeWithDoubleValue(13.3);
    DoubleNode *theNode6 = SLCreateNodeWithDoubleValue(37.9);
    DoubleNode *theNode7 = SLCreateNodeWithDoubleValue(99.0);
    DoubleNode *theNode8 = SLCreateNodeWithDoubleValue(60.7);
    DoubleNode *theNode9 = SLCreateNodeWithDoubleValue(20.1);

    SLAddNode(theList, theNode);
    SLAddNode(theList, theNode1);
    SLAddNode(theList, theNode2);
    SLAddNode(theList, theNode3);
    SLAddNode(theList, theNode4);
    SLAddNode(theList, theNode5);
    SLAddNode(theList, theNode6);
    SLAddNode(theList, theNode7);
    SLAddNode(theList, theNode8);
    SLAddNode(theList, theNode9);

    printf("Number of elements(size of List): %d\n\n", SLCountList(theList));
    doPrintSLList(theList);
    printf("\n");

    printf("Minimum in List = %0.2f\n", MinElem(theList)->value);
    printf("Maximum in List = %0.2f\n\n", MaxElem(theList)->value);

    printf("Number Minimum in List = %d\n", NumberElement (theList, MinElem(theList))-1);
    printf("Number Maximum in List = %d\n\n", NumberElement (theList, MaxElem(theList))-1);

    if(NumberElement (theList, MaxElem(theList))>NumberElement (theList, MinElem(theList)))
    {
        quickSort(theList, NumberElement (theList, MinElem(theList))-1, NumberElement (theList, MaxElem(theList))-1);
    }
    else if(NumberElement (theList, MaxElem(theList))< NumberElement (theList, MinElem(theList)))
    {
        quickSort(theList, NumberElement (theList, MaxElem(theList))-1, NumberElement (theList, MinElem(theList))-1);
    }

    doPrintSLList(theList);

    SLFreeList(theList);
    printf("\nList was deleted!\n");

    return 0;
}

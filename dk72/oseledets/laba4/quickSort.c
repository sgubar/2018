#include "quickSort.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

IntNode *IntValueAtIndex(IntList *aList, int anIndex)
{
    int theResult = -1;
    if ( aList == NULL|| anIndex >= aList -> count)
    {
        return theResult;
    }
    IntNode *theNode = aList -> head;
    int i = 0;
    do
    {
        if (i == anIndex)
        {
            break;
        }
        theNode = theNode->next;
        i++;
    }while (theNode != NULL);
    return theNode;
}


void SwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex)
{
    if (aLeftIndex == aRightIndex) {
        return;
    }
    else {
        IntNode *theLeftNode = IntValueAtIndex(aList, aLeftIndex);
        IntNode *theRightNode = IntValueAtIndex(aList, aRightIndex);
        int theTmp = theLeftNode -> value;
        theLeftNode->value = theRightNode->value;
        theRightNode->value = theTmp;
    }
}


int partitionIt(IntList *aList, int aLeftIndex, int aRightIndex, int aPivot)
{
    int theLeft = aLeftIndex - 1;
    int theRight = aRightIndex + 1;

    while (1)
    {
        while (theLeft < aRightIndex && IntValueAtIndex(aList, ++theLeft
        )->value < aPivot);
        while (theRight > aLeftIndex && IntValueAtIndex(aList,--theRight)->value > aPivot);
        if (theLeft >= theRight)
        {
            break;
        }
        else
        {
            SwapNodesByIndex(aList, theLeft, theRight);
        }
    }
    return theLeft;
}
void quickSort(IntList *aList, int aLeftIndex, int aRightIndex)
{
    if (aRightIndex - aLeftIndex <= 0)
    {
        return;
    }

    int thePivot = IntValueAtIndex(aList, aRightIndex) -> value;
    int thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex, thePivot);


    quickSort(aList, aLeftIndex, thePartitionIndex - 1);

    quickSort(aList, thePartitionIndex + 1, aRightIndex);
}

int FindMin(IntList *aList)
{
    int min = 999999;
    int i = 0;
    int LeftPoz;
    if (aList != NULL) {
        IntNode *theNode = aList->head;
        do {
            if(theNode ->value < min) {
                min = theNode->value;
                LeftPoz = i;
            }
            theNode = theNode->next;
            i++;
        } while (NULL != theNode);
        printf("Min is - %d",min);
        return LeftPoz;
    }
    else
    {
        printf("SomeError");
    }
}
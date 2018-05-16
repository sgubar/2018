
#include "list.h"
#include <stdlib.h>

const double kSLListError = -1;

doubleList *SLCreateList()
{
    doubleList *theList = (doubleList *)malloc(sizeof(doubleList));

    //Clean internal data
    theList->head = NULL;
    theList->tail = NULL;
    theList->count = 0;

    return theList;
}

void SLFreeList(doubleList *aList)
{
    if (NULL == aList)
    {
        return;
    }

    doubleNode *theNode = aList->head;

    while (NULL != theNode)
    {
        doubleNode *theNodeToBeFree = theNode;
        theNode = theNode->nextNode;

        SLFreedoubleNode(theNodeToBeFree);
    }
    free(aList);
}

doubleNode *SLAddNode(doubleList *aList, doubleNode *aNewNode)
{
    if (NULL == aList || NULL == aNewNode)
    {
        return NULL;
    }
    if (NULL == aList->head && NULL == aList->tail)
    {
        aList->head = aList->tail = aNewNode;
    }
    else
    {
        doubleNode *theTail = aList->tail;
        aList->tail = aNewNode;

        if (NULL != theTail)
        {
            theTail->nextNode = aList->tail;
        }
    }

    aList->count += 1;

    return aNewNode;
}

double SLCountList(const doubleList *aList)
{
    double theResult = kSLListError;

    if (NULL != aList)
    {
        theResult = aList->count;
    }

    return theResult;
}

doubleNode *SLNodeAtIndex(const doubleList *aList, int anIndex)
{
    doubleNode *theResult = NULL;

    if (NULL != aList && anIndex < aList->count)
    {
        int i = 0;
        doubleNode *theNode = aList->head;

        do
        {
            if (i == anIndex)
            {
                theResult = theNode;
                break;
            }

            i++;
            theNode = theNode->nextNode;

        } while (NULL != theNode);
    }

    return theResult;
}

doubleNode *SLInsertNodeAtIndex(doubleList *aList, doubleNode *aNewNode, int anIndex)
{
    doubleNode *theResult = NULL;

    if (NULL == aList || NULL == aNewNode)
        return NULL;

    if (anIndex < 0 || aList->count < anIndex)
        return NULL;

    if (0 == anIndex)
    {
        if (NULL == aList->head && NULL == aList->tail)
        {
            SLAddNode(aList, aNewNode);
            theResult = aNewNode;
        }
        else
        {
            doubleNode *theHead = aList->head;
            aList->head = aNewNode;
            aList->head->nextNode = theHead;
            aList->count ++;
            theResult = aNewNode;
        }
    }
    else if (aList->count == anIndex)
    {
        SLAddNode(aList, aNewNode);
        theResult = aNewNode;
    }
    else
    {
        int theOwnerIndex = anIndex - 1;
        doubleNode *theOwnNode = SLNodeAtIndex(aList, theOwnerIndex);

        if (NULL != theOwnNode)
        {
            doubleNode *theNextOwnNode = theOwnNode->nextNode;
            theOwnNode->nextNode = aNewNode;
            aNewNode->nextNode = theNextOwnNode;

            aList->count ++;
            theResult = aNewNode;
        }
    }

    return theResult;
}

doubleNode *SLRemovedNodeAtIndex(doubleList *aList, int anIndex)
{
    doubleNode *theResult = NULL;

    if (NULL == aList)
        return NULL;

    if (anIndex < 0 || aList->count <= anIndex)
        return NULL;

    if (0 == anIndex)
    {
        doubleNode *theHead = aList->head;

        aList->head = aList->head->nextNode;
        if (NULL == aList->head)
            aList->tail = aList->head;

        aList->count --;
        theResult = theHead;
    }
    else
    {
        doubleNode *theOwnNode = SLNodeAtIndex(aList, anIndex - 1);
        if (NULL != theOwnNode)
        {
            theResult = theOwnNode->nextNode;
            theOwnNode->nextNode = theResult->nextNode;

            aList->count --;

            if (theResult == aList->tail)
            {
                aList->tail = theOwnNode;
            }
        }
    }

    return theResult;
}

void SLSwapNodesByIndex(doubleList *aList, int aLeftIndex, int aRightIndex)
{
    if (aLeftIndex == aRightIndex)
        return ;

    doubleNode *theLeftNode = SLNodeAtIndex(aList, aLeftIndex);
    doubleNode *theRightNode = SLNodeAtIndex(aList, aRightIndex);

    double theTmp = theLeftNode->value;
    theLeftNode->value = theRightNode->value;
    theRightNode->value = theTmp;
}
doubleNode *SLCreateNodeWithdoubleValue(double aValue)
{
    doubleNode *theResult = (doubleNode *)malloc(sizeof(doubleNode));

    theResult->value = aValue;
    theResult->nextNode = NULL;

    return theResult;
}

void SLFreedoubleNode(doubleNode *aNode)
{
    if (NULL != aNode)
    {
        free(aNode);
    }
}

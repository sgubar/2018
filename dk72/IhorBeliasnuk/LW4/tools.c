//
// Created by Ihor on 16.05.2018.
//

#include <stdlib.h>
#include "tools.h"

const int kSLListError = -1;

CharNode *SLCreateNodeWithCharValue(char aValue)
{
    CharNode *theResult = (CharNode *)malloc(sizeof(CharNode));

    theResult->value = aValue;
    theResult->nextNode = NULL;

    return theResult;
}

void SLFreeCharNode(CharNode *aNode)
{
    if (NULL != aNode)
    {
        free(aNode);
    }
}

CharList *SLCreateList()
{
    //Allocate memory for the list structure
    CharList *theList = (CharList *)malloc(sizeof(CharList));

    //Clean internal data
    theList->head = NULL; //<!- not head
    theList->tail = NULL; //<!- not tail
    theList->count = 0; //<!- initial value of count is zero - no elements in the list

    return theList;
}

void SLFreeList(CharList *aList)
{
    // Check the input parameter
    if (NULL == aList)
    {
        return;
    }

    //1. Remove all elements
    CharNode *theNode = aList->head;

    while (NULL != theNode)
    {
        CharNode *theNodeToBeFree = theNode;
        theNode = theNode->nextNode;

        SLFreeCharNode(theNodeToBeFree);
    }

    //2. Free memory for the List structure
    free(aList);
}

CharNode *SLAddNode(CharList *aList, CharNode *aNewNode)
{
    // Check the input parameter
    if (NULL == aList || NULL == aNewNode)
    {
        return NULL;
    }

    //Add the new node to end of the list

    // a b c d e + G = a b c d e G

    if (NULL == aList->head && NULL == aList->tail)
    {
        //The list is empty
        aList->head = aList->tail = aNewNode;
    }
    else
    {
        CharNode *theTail = aList->tail;
        aList->tail = aNewNode;

        if (NULL != theTail)
        {
            theTail->nextNode = aList->tail;
        }
    }

    aList->count += 1;

    return aNewNode;
}

int SLCountList(const CharList *aList)
{
    char theResult = kSLListError;

    if (NULL != aList)
    {
        theResult = aList->count;
    }

    return theResult;
}

int BracketBallanceCheck(FILE *aFile) //if all ok returns 0, if brackets did't match returns 1
{
    if(aFile != NULL)
    {
        CharList *openList = SLCreateList();
        CharList *closeList = SLCreateList();

        int checkPoint = 0;
        do
        {
            checkPoint = getc(aFile);
            if(checkPoint == '{')
            {
                CharNode *openBracketNode = SLCreateNodeWithCharValue('{');
                SLAddNode(openList, openBracketNode);
            };

            if(checkPoint == '}')
            {
                CharNode *closeBracketNode = SLCreateNodeWithCharValue('{');
                SLAddNode(closeList, closeBracketNode);
            };

        }
        while(checkPoint != EOF);

        if(SLCountList(openList) == SLCountList(closeList))
        {
            SLFreeList(openList);
            SLFreeList(closeList);
            return 0;
        }

        SLFreeList(openList);
        SLFreeList(closeList);
        return 1;

    }

    return 2;
}
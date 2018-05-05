#include <stdio.h>
#include "spysok.h"

CharNode *SLCreateNodeWithIntValue(char aValue)
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

void SLAddNode(CharList *aList, CharNode *aNewNode)
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
		CharNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
}

CharNode *SLNodeAtIndex(const CharList *aList, int anIndex)
{
	CharNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		CharNode *theNode = aList->head;

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

void SLInsertNodeAtIndex(CharList *alist, CharNode *value, int index)
{
	if ((alist->head == NULL) || (index > alist->count) || (value == NULL))return ;
	CharNode *aNode = alist->head;
	if(index == 0)
    {
		alist->head = value;
		value->nextNode = aNode;
    }
    else if (alist->count == index)
	{
		SLAddNode(alist,value);

	}
	else
    {
		for (int i = 0; i < index-1; ++i)
		{
			aNode = aNode->nextNode;
		}
		value->nextNode = aNode->nextNode;
		aNode->nextNode = value;
    }
	alist->count++;
}

void SLRemovedNodeAtIndex(CharList *alist, int index)
{
	if ((alist->head == NULL) || (index >= alist->count))return;
	CharNode *aNode = alist->head, *temp;
	if(index == 0)
	{
		alist->head = alist->head->nextNode;
		temp = aNode;
        alist->count--;
    }
	else
	{
    for (int i = 0; i < index-1; ++i)
		{
			aNode = aNode->nextNode;
		}
    temp = aNode->nextNode;
    aNode->nextNode = aNode->nextNode->nextNode;
    if (temp == alist->tail)
        {
            alist->tail = aNode;
        }
    alist->count--;

	}
	free(temp);
}

const int kSLListError = -1;

CharList *SLCreateList()
{
	CharList *theList = (CharList *)malloc(sizeof(CharList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;


	return theList;
}

void SLFreeList(CharList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	CharNode *theNode = aList->head;

	for (int i = 0; i < SLCountList(aList); i++)
	{
	    if(NULL==theNode)break;

		CharNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		SLFreeCharNode(theNodeToBeFree);
	}

	free(aList);
}

int SLCountList(const CharList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}



void doPrintSLList(const CharList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		CharNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %c\n", i, theNode->value);
		}
	}
}

void SLSwapNodesByIndex(CharList *aList, int theLeft, int theRight)
{
    if (theLeft == theRight) return ;

    CharNode *theNode_l = SLNodeAtIndex(aList,theLeft);
    CharNode *theNode_r = SLNodeAtIndex(aList,theRight);
    CharNode *theNode_rNext = SLNodeAtIndex(aList,theRight)->nextNode;

    if(theLeft==0)
    {
        aList->head = theNode_r;
        aList->head->nextNode = theNode_l->nextNode;
    }
    else
    {
        SLNodeAtIndex(aList,theLeft-1)->nextNode = theNode_r;
        SLNodeAtIndex(aList,theLeft-1)->nextNode->nextNode = theNode_l->nextNode;
    }

    SLNodeAtIndex(aList,theRight-1)->nextNode = theNode_l;
    SLNodeAtIndex(aList,theRight-1)->nextNode->nextNode = theNode_rNext;

    if(theRight+1 == aList->count)
    {
        aList->tail = SLNodeAtIndex(aList,theRight);
    }
}

int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex)
{
    char thePivot = SLNodeAtIndex(aList, aLeftIndex)->value;
	int theLeft = aLeftIndex;
	int theRight = aRightIndex + 1;

	while (1)
	{
		do theLeft++; while (theLeft <= aRightIndex && SLNodeAtIndex(aList, theLeft)->value <= thePivot);

        do theRight--; while (SLNodeAtIndex(aList, theRight)->value > thePivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
        {
            SLSwapNodesByIndex(aList, theLeft, theRight);
        }
	}
	SLSwapNodesByIndex(aList, aLeftIndex, theRight);

	return theRight;
}

void quickSort(CharList *aList, int aLeftIndex, int aRightIndex)
{
    int thePartitionIndex;

	if ( aLeftIndex <aRightIndex )
	{

	thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex);

	quickSort(aList, aLeftIndex, thePartitionIndex - 1);

	quickSort(aList, thePartitionIndex + 1, aRightIndex);


	}
}


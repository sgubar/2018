#include <stdio.h>
#include "list.h"

DoubleNode *SLCreateNodeWithDoubleValue(double aValue)
{
	DoubleNode *theResult = (DoubleNode *)malloc(sizeof(DoubleNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeDoubleNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

void SLAddNode(DoubleList *aList, DoubleNode *aNewNode)
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
		DoubleNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;
}

DoubleNode *SLNodeAtIndex(const DoubleList *aList, int anIndex)
{
	DoubleNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		DoubleNode *theNode = aList->head;

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

void SLInsertNodeAtIndex(DoubleList *alist, DoubleNode *value, int index)
{
	if ((alist->head == NULL) || (index > alist->count) || (value == NULL))return ;
	DoubleNode *aNode = alist->head;
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

void SLRemovedNodeAtIndex(DoubleList *alist, int index)
{
	if ((alist->head == NULL) || (index >= alist->count))return;
	DoubleNode *aNode = alist->head, *temp;
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

DoubleList *SLCreateList()
{
	DoubleList *theList = (DoubleList *)malloc(sizeof(DoubleList));

	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;


	return theList;
}

void SLFreeList(DoubleList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	DoubleNode *theNode = aList->head;

	for (int i = 0; i < SLCountList(aList); i++)
	{
	    if(NULL==theNode)break;

		DoubleNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		SLFreeDoubleNode(theNodeToBeFree);
	}

	free(aList);
}

int SLCountList(const DoubleList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}



void doPrintSLList(const DoubleList *aList)
{
	for (int i = 0; i < SLCountList(aList); i++)
	{
		DoubleNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %0.2f\n", i, theNode->value);
		}
	}
}

void SLSwapNodesByIndex(DoubleList *aList, int theLeft, int theRight)
{
    if (theLeft == theRight)
		return ;

	DoubleNode *theLeftNode = SLNodeAtIndex(aList, theLeft);
	DoubleNode *theRightNode = SLNodeAtIndex(aList, theRight);

	float theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}

int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
    double thePivot = SLNodeAtIndex(aList, aLeftIndex)->value;
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

void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex)
{
    int thePartitionIndex;

	if ( aLeftIndex <aRightIndex )
	{

	thePartitionIndex = partitionIt(aList, aLeftIndex, aRightIndex);

	quickSort(aList, aLeftIndex, thePartitionIndex - 1);

	quickSort(aList, thePartitionIndex + 1, aRightIndex);


	}
}

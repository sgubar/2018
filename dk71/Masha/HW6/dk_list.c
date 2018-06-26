#include "dk_list.h"
#include "dk_node.h"
#include <stdlib.h>


const int kSLListError = -1;


IntList *SLCreateList()
{

	IntList *theList = (IntList *)malloc(sizeof(IntList));


	theList->head = NULL;
	theList->tail = NULL;
	theList->count = 0;


//	bzero(theList, sizeof(IntList));

	return theList;
}

void SLFreeList(IntList *aList)
{
	// Check the input parameter
	if (NULL == aList)
	{
		return;
	}

	//1. Remove all elements
	IntNode *theNode = aList->head;

	while (NULL != theNode)
	{
		IntNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		SLFreeIntNode(theNodeToBeFree);
	}

	//2. Free memory for the List structure
	free(aList);
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode)
{
	// Check the input parameter
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
		IntNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count += 1;

	return aNewNode;
}

int SLCountList(const IntList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

IntNode *SLNodeAtIndex(const IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		IntNode *theNode = aList->head;

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

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex)
{
	IntNode *theResult = NULL;

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
			IntNode *theHead = aList->head;
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
		IntNode *theOwnNode = SLNodeAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			IntNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;

			aList->count ++;
			theResult = aNewNode;
		}
	}

	return theResult;
}

IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex)
{
	IntNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		IntNode *theHead = aList->head;

		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->count --;
		theResult = theHead;
	}
	else
	{
		IntNode *theOwnNode = SLNodeAtIndex(aList, anIndex - 1);
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

void SLSwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return ;

	IntNode *theLeftNode = SLNodeAtIndex(aList, aLeftIndex);
	IntNode *theRightNode = SLNodeAtIndex(aList, aRightIndex);

	int theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}
void doPrintSLList(const IntList *aList)
{
	int i;
	for (i = 0; i < SLCountList(aList); i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

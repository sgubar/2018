#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>

const int kSLListError = -1;


FloatList *SLCreateList()
{
	FloatList *theList = (FloatList *)malloc(sizeof(FloatList));

	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0; 

	return theList;
}

void SLFreeList(FloatList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	FloatNode *theNode = aList->head;

	while (NULL != theNode)
	{
		FloatNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		SLFreeFloatNode(theNodeToBeFree);
	}

	free(aList);
}

FloatNode *SLAddNode(FloatList *aList, FloatNode *aNewNode)
{
	if (NULL == aList || NULL == aNewNode)
	{
		return NULL;
	}

	//Add the new node to end of the list
	if (NULL == aList->head && NULL == aList->tail)
	{
		aList->head = aList->tail = aNewNode;
	}
	else
	{
		FloatNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count ++;

	return aNewNode;
}

int SLCountList(const FloatList *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

FloatNode *SLNodeAtIndex(const FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		FloatNode *theNode = aList->head;

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

FloatNode *SLInsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex)
{
	FloatNode *theResult = NULL;

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
			FloatNode *theHead = aList->head;
			aList->head = aNewNode;
			aList->head->nextNode = theHead;
			aList->count++;
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
		FloatNode *theOwnNode = SLNodeAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			FloatNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;

			aList->count++;
			theResult = aNewNode;
		}
	}

	return theResult;
}

FloatNode *SLRemovedNodeAtIndex(FloatList *aList, int anIndex)
{
	FloatNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		FloatNode *theHead = aList->head;

		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->count--;
		theResult = theHead;
	}
	else
	{
		FloatNode *theOwnNode = SLNodeAtIndex(aList, anIndex - 1);
		if (NULL != theOwnNode)
		{
			theResult = theOwnNode->nextNode;
			theOwnNode->nextNode = theResult->nextNode;

			aList->count--;

			if (theResult == aList->tail)
			{
				aList->tail = theOwnNode;
			}
		}
	}

	return theResult;
}

void SLSwapNodesByIndex(FloatList *aList, int aLeftIndex, int aRightIndex)
{
	if (aLeftIndex == aRightIndex)
		return;

	FloatNode *theLeftNode = SLNodeAtIndex(aList, aLeftIndex);
	FloatNode *theRightNode = SLNodeAtIndex(aList, aRightIndex);

	float theTmp = theLeftNode->value;
	theLeftNode->value = theRightNode->value;
	theRightNode->value = theTmp;
}
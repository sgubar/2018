#include "SingleLinkedList.h"
#include "SingleLinkedNode.h"
#include <stdlib.h>

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
	if (NULL == aList)
	{
		return;
	}

	CharNode *theNode = aList->head;

	while (NULL != theNode)
	{
		CharNode *theNodeToBeFree = theNode;
		theNode = theNode->nextNode;

		SLFreeCharNode(theNodeToBeFree);
	}

	free(aList);
}

CharNode *SLAddNode(CharList *aList, CharNode *aNewNode)
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
		CharNode *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->nextNode = aList->tail;
		}
	}

	aList->count ++;

	return aNewNode;
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

CharNode *SLInsertNodeAtIndex(CharList *aList, CharNode *aNewNode, int anIndex)
{
	CharNode *theResult = NULL;

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
			CharNode *theHead = aList->head;
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
		CharNode *theOwnNode = SLNodeAtIndex(aList, theOwnerIndex);

		if (NULL != theOwnNode)
		{
			CharNode *theNextOwnNode = theOwnNode->nextNode;
			theOwnNode->nextNode = aNewNode;
			aNewNode->nextNode = theNextOwnNode;

			aList->count++;
			theResult = aNewNode;
		}
	}

	return theResult;
}

CharNode *SLRemovedNodeAtIndex(CharList *aList, int anIndex)
{
	CharNode *theResult = NULL;

	if (NULL == aList)
		return NULL;

	if (anIndex < 0 || aList->count <= anIndex)
		return NULL;

	if (0 == anIndex)
	{
		CharNode *theHead = aList->head;

		aList->head = aList->head->nextNode;
		if (NULL == aList->head)
			aList->tail = aList->head;

		aList->count--;
		theResult = theHead;
	}
	else
	{
		CharNode *theOwnNode = SLNodeAtIndex(aList, anIndex - 1);
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


#include "circular_list.h"
#include <stdlib.h>

// Constants
const int kSLListError = -1;

//Create/delete a list
IntList *SLCreateList()
{
	//Allocate memory for the list structure
	IntList *theList = (IntList *)malloc(sizeof(IntList));

	//Clean internal data
	theList->head = NULL; //<!- not head
	theList->tail = theList->head; //<!- not tail
	theList->count = 0; //<!- initial value of count is zero - no elements in the list
	
// or
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
	return 0;
}

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode)
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

	if (NULL != aList )
	{
		int i = 0;
		IntNode *theNode = aList->head;
	
		do
		{
			
			if (i == anIndex) //<!- index was found
			{
				theResult = theNode; //<! - our node
				break;
			}
		
			i++; 
			
			theNode = theNode->nextNode; //<! - go to next node
		
		} while (NULL != theNode);
	}
	
	return theResult;
}

IntNode *SLCreateNodeWithIntValue(IntList *aList, int aValue)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	
	theResult->value = aValue;
	theResult->nextNode = aList->head;
	
	return theResult;
}
IntNode *SLCreateLastNode(int aValue, IntNode *aNode)
{
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	
	theResult->value = aValue;
	theResult->nextNode = aNode;
	
	return theResult;
}

void SLFreeIntNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

IntNode *minNode(const IntList *aList)
{
	int i=0, min = 0, index = 0;
	IntNode *theResult = (IntNode *)malloc(sizeof(IntNode));
	IntNode *theNode1 = (IntNode *)malloc(sizeof(IntNode));
	IntNode *theNode2 = (IntNode *)malloc(sizeof(IntNode));
	theNode1 = SLNodeAtIndex(aList, i);
	min = theNode1->value;
	for (i = 0; i < SLCountList(aList); i++)
	{		
		theNode2 = SLNodeAtIndex(aList, i);
		if ( NULL != theNode2)
		{
			if(theNode2->value < min){
				min = theNode2->value;
				index = i;
			} 
			
		}
	}
	theResult->index = index;
	theResult->min = min;
	return theResult;
}
void doPrintSLList(const IntList *aList, int first)
{
	int i;
	
	for (i = first ; i < SLCountList(aList)+5+first; i++)
	{
		IntNode *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

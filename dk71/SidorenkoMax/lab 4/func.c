#include "func.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

static CharNode *createIntNodeWithValue(char anIntValue);

#pragma mark -
CharList *TLCreateIntList()
{
	CharList *theList = (CharList *)malloc(sizeof(CharList));
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

char DestroyList(CharList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		CharNode *theNode = aList->head;
	
		do
		{
			CharNode *theNodeToDelete = theNode;
			theNode = theNode->next;
		
			free (theNodeToDelete);
		
		}while (NULL != theNode);
	
		free(aList);
	}
}

char ListValue(CharList *aList, char anIntValue)
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		CharNode *theNode = createIntNodeWithValue(anIntValue);
	
		if (NULL != theNode)
		{
			// lets to add to the end of the list
			//1. The list is empty
			if (NULL == aList->head && aList->head == aList->tail)
			{
				aList->head = aList->tail = theNode;
			}
			else
			{
				// (head) a b c (tail) + d -> (head)a b c=>d (tail)
				CharNode *theTail = aList->tail;
				aList->tail = theNode;
				theTail->next = theNode;
				theNode->prev = theTail;
			}
		
			aList->count ++;
			theResult = 0;
		}
	}
	
	return theResult;
}



char PrintList(CharList *aList)
	{
		printf("[CharList] with count (%d):      ", aList->count);
		CharNode *theNode = aList->head;
		printf("( ");
		do
		{
			
			printf("%c ", theNode->value);
			theNode = theNode->next;
		
		}while (NULL != theNode);
		printf(")");
		
		printf ("\n");
	}

char InsertValue(CharList *aList, char anIntValue, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	CharNode *theNode = aList->head;
	int i = 0;

	do
	{
		if (i == anIndex)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (NULL != theNode);

	
	CharNode *theNewNode = createIntNodeWithValue(anIntValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	CharNode *theBNode = theNode;
	
	if (NULL != theBNode->prev)
	{
		theBNode->prev->next = theNewNode; 
		theNewNode->prev = theBNode->prev;
	}
	
	theNewNode->next = theBNode; 
	theBNode->prev = theNewNode;
	
	aList->count ++;
	theResult = 0;
	
	return theResult;
}


CharNode *createIntNodeWithValue(char anIntValue)
	{
		CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
		if (NULL != theNode)
		{
			theNode->next = NULL;
			theNode->prev = NULL;
			theNode->value = anIntValue;
		}
		
		return theNode;
	}
	



#include "dz6.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>


void shellSort(FloatList *aList)
{
	int in = 0;
	int out = 0;
	int h = 1; // start h = 1
	float tmp,insert;
	
	//1. Calculate start value of h
	while (h <= aList->count/2)
	{
		h = h*2 + 1; 
	}

	//2. Sequental decrease h to 1
	while (h > 0)
	{
		for (out = h; out < aList->count; out ++)
		{
			tmp = TLFloatValueAtIndex(aList,out);
			in = out;
		
			// the first sub-array {0, 4, 8}
			while (in > h-1 && TLFloatValueAtIndex(aList,in-h) >= tmp)
			{
				insert = TLFloatValueAtIndex(aList,in-h);
				TLInsertFloatValueAtIndex(aList,insert,in); 
				in -= h;
			}
		
			TLInsertFloatValueAtIndex(aList,tmp,in);
		}
	
		h = (h - 1) / 2; //decrease h
	}
}
FloatList *TLCreateFloatList()
{
	FloatList *theList = (FloatList *)malloc(sizeof(FloatList));
	
	if (NULL != theList)
	{
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	}
	
	return theList;
}

void TLDestroyFloatList(FloatList *aList)
{
	if (NULL == aList)
	{
		return;
	}

	if (NULL != aList->tail && NULL != aList->head)
	{
		FloatNode *theNode = aList->head;
	
		do
		{
			FloatNode *theNodeToDelete = theNode;
			theNode = theNode->next;
		
			free (theNodeToDelete);
		
		}while (NULL != theNode);
	
		free(aList);
	}
}

int TLAddFloatValueToList(FloatList *aList, float anFloatValue)
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		FloatNode *theNode = createFloatNodeWithValue(anFloatValue);
	
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
				FloatNode *theTail = aList->tail;
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

float TLFloatValueAtIndex(FloatList *aList, int anIndex)
{
	int theResult = NULL;
	
	if (NULL == aList || anIndex >= aList->count)
	{
		return theResult;
	}
	
	FloatNode *theNode = aList->head;
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
	
	return theNode->value;
}

// print list
void TLPrintList(FloatList *aList)
{
	printf("[List] with count (%d):", aList->count);
	FloatNode *theNode = aList->head;
	
	do
	{
		printf("(%.3f) ", theNode->value);
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
	printf ("\n");
}

int TLInsertFloatValueAtIndex(FloatList *aList, float anFloatValue, int anIndex)
{
	int theResult = -1;
	
	if (NULL == aList || anIndex >= aList->count || anIndex < 0)
	{
		return theResult;
	}
	
	FloatNode *theNode = aList->head;
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

	// a b c ^ d(1) => a ->d->b c
	
	FloatNode *theNewNode = createFloatNodeWithValue(anFloatValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	FloatNode *theBNode = theNode;
	
	if (NULL != theBNode->prev)
	{
		theBNode->prev->next = theNewNode; //a->d
		theNewNode->prev = theBNode->prev; //d->a
	}
	
	theNewNode->next = theBNode; //d->b
	theBNode->prev = theNewNode; //b->d
	
	aList->count ++;
	theResult = 0;
	
	return theResult;
}


FloatNode *createFloatNodeWithValue(float anFloatValue)
{
	FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anFloatValue;
	}
	
	return theNode;
}

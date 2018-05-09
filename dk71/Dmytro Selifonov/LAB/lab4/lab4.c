
#include "lab4.h"
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

CharList *TLCreateCharList()
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

void TLDestroyCharList(CharList *aList)
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

int TLAddCharValueToList(CharList *aList, char anCharValue)
{
	int theResult = -1;
	
	if (NULL != aList)
	{
		CharNode *theNode = createCharNodeWithValue(anCharValue);
	
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

char TLCharValueAtIndex(CharList *aList, int anIndex)
{
	int theResult = NULL;
	
	if (NULL == aList || anIndex >= aList->count)
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
	
	return theNode->value;
}

// print list
void TLPrintList(CharList *aList)
{
	printf("[List] with count (%d):", aList->count);
	CharNode *theNode = aList->head;
	
	do
	{
		printf("(%c) ", theNode->value);
		theNode = theNode->next;
	
	}while (NULL != theNode);
	
	printf ("\n");
}

int TLInsertCharValueAtIndex(CharList *aList, char anCharValue, int anIndex)
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

	// a b c ^ d(1) => a ->d->b c
	
	CharNode *theNewNode = createCharNodeWithValue(anCharValue);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	CharNode *theBNode = theNode;
	
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


CharNode *createCharNodeWithValue(char anCharValue)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
	if (NULL != theNode)
	{
		theNode->next = NULL;
		theNode->prev = NULL;
		theNode->value = anCharValue;
	}
	
	return theNode;
}

void readFileToList(FILE *file,CharList *theList)
{
	if(file == NULL){
		printf("ERROR\n");
		return ;
	}
	char tmp;
    while (feof(file) == 0 )
    {
        fscanf (file, "%c", &tmp);
        TLAddCharValueToList(theList,tmp);
    }
	return ;	
}

void TLPrintFromTheEnd(CharList *theList)
{
	printf("[List] with count (%d):", theList->count);
	CharNode *theNode = theList->tail;
	
	do
	{
		printf("(%c) ", theNode->value);
		theNode = theNode->prev;
	
	}while (NULL != theNode);
	
	printf ("\n");
}


#include "TLIntList.h"
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



// print list
char PrintList(CharList *aList)
	{
		printf("[CharList] with count (%d):      ", aList->count);
		CharNode *theNode = aList->head;
		
		do
		{
			printf("(%c) ", theNode->value);
			theNode = theNode->next;
		
		}while (NULL != theNode);
		
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

	// a b c ^ d(1) => a ->d->b c
	
	CharNode *theNewNode = createIntNodeWithValue(anIntValue);
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
	

void delete_element(CharList *thelist, int index)  
	{
		int i = 0;
		if ((thelist->head == NULL) || (index >= thelist->count))return;
		CharNode *theNode = thelist->head, *temp;
			if(index == 0)
		  {
		 	thelist->head = thelist->head->next;
		 	temp = theNode;
	         thelist->count--;
	  	  }
		else
		{
	   	 for (i ; i < index-1; ++i)
	                {
			   if(theNode != NULL)
				theNode = theNode->next;
			}
	    	 temp = theNode->next;
	   	     theNode->next = theNode->next->next;
	   	     
	      if (temp == thelist->tail)
	        {
	            thelist->tail = theNode;
	        }
	    	thelist->count--;
	
		}
		free(temp);
	}


int partition (CharList *thelist, int head, int tail)
	{	
		int j;
	    char pivot = NodeAtIndex(thelist, tail)->value;
	    int i = (head - 1);  
	 
	    for ( j = head; j <= tail - 1; j++)
	    {

	        if (NodeAtIndex(thelist, j)->value  <= pivot)              // here
	        {
	            i++;    
	            swap(thelist, i,  j);
	            
	        }
	    }
	    swap(thelist,  i + 1 , tail);
	    return (i + 1);
	}

void quickSort(CharList *thelist, int head, int tail)
	{
	    if (head < tail)
	    {
	        /* pi is partitioning index, arr[p] is now
	           at right place */
	           printf("here\n");
	        int pi = partition(thelist, head, tail);
	 
	        // Separately sort elements before
	        // partition and after partition
	        quickSort(thelist, head, pi - 1);
	        quickSort(thelist, pi + 1, tail);
	        
	    }
	}

void swap(CharList *thelist, int theLeft, int theRight)
	{
	    if (theLeft == theRight) return;
		
	    CharNode *theNode_l = NodeAtIndex(thelist,theLeft);
	    CharNode *theNode_r = NodeAtIndex(thelist,theRight);
		int temp = theNode_l->value;
		theNode_l->value = theNode_r->value;
		theNode_r->value = temp;
	}

CharNode *NodeAtIndex(CharList *thelist, int index)
	{
		CharNode *theResult = NULL;
	
		if (NULL != thelist && index < thelist->count)
		{
			int i = 0;
			CharNode *theNode = thelist->head;
	
			do
			{
				if (i == index)
				{
					theResult = theNode;
					break;
				}
				theNode = theNode->next;
				i++;
				
			}while(NULL != theNode);
		}
		
		return theResult;
	}


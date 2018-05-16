#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tools.h"

List *create_list()
{
	List *thelist = malloc(sizeof(List));
	if(thelist != NULL)
  {
	thelist->size = 0;
	thelist->first = NULL;
	thelist->last = NULL;
  }
	return thelist;
}

Node *createNodeWithLetter(char letter)
{
  Node *theNode = malloc(sizeof(Node));
  if(theNode != NULL)
  {
    theNode->letter = letter;
    theNode->prev = NULL;
    theNode->next = NULL;
  }
	return theNode;
}

void add_element(List *thelist, char letter) 
{
	if (thelist != NULL)
	{
		Node *theNode = createNodeWithLetter(letter);
	
		if (theNode != NULL)
		{
			
			if ( thelist->first == NULL && thelist->first == thelist->last)
			{
				thelist->first = thelist->last = theNode;
			}
			else
			{
				Node *thelast = thelist->last;
				thelist->last = theNode;
				thelast->next = theNode;
				theNode->prev = thelast;
			}
		
				thelist->size++;
		}
	
	}
}

void print_list(List *thelist)
{
		if(thelist == NULL)
		{
			return;
		}
	Node *theNode = thelist->first;
	
	do
	{
		printf("%c ", theNode->letter);
		theNode = theNode->next;
	
	}while (theNode != NULL);
	
	printf ("\n");
}

void delete_list(List *thelist) 
{
	int i = 0;
	if (thelist == NULL)
	{
		return;
	}

	Node *theNode = thelist->first;

	for (i ; i < thelist->size; i++)
	{
	    if(theNode == NULL)
			
			break;

		Node *theNodeToDelete = theNode;
		theNode = theNode->next;

		free(theNodeToDelete);
	}
	free(thelist);
}

int findMAX(List *thelist)
{
	if (NULL != thelist && 0 < thelist->size)
	{
		int theResult = 0;
		Node *theNode = thelist->first;
		int i = 0;
		char temp = 0;
		
	 		for(i; i < thelist->size; i++)
			{
				if (theNode->letter > temp)
				{
					temp = theNode->letter;
					theResult = i+1;
				}	
		      theNode = theNode->next;
			}	
 	  return theResult;
	}
}

int findMIN(List *thelist)
{
	if (NULL != thelist && 0 < thelist->size)
	{
		int theResult = 0;
		Node *theNode = thelist->first;
		int i = 0;
		char temp = theNode->letter;
		
	 		for(i; i < thelist->size; i++)
			{
				if (theNode->letter < temp)
				{
					temp = theNode->letter;
					theResult = i+1;
				}	
		      theNode = theNode->next;
			}	
	  return theResult;
	}
} 

Node *findAtIndex(List *thelist, int anIndex)
{
	Node *theResult = NULL;

	if (NULL != thelist && anIndex < thelist->size)
	{
		int i = 0;
		Node *theNode = thelist->first;

		do
		{
			if (i == anIndex)
			{
				theResult = theNode;
				break;
			}

			i++;
			theNode = theNode->next;

		} while (NULL != theNode);
	}

	return theResult;
}

void swap(List *thelist, int theLeft, int theRight)
{
    if (theLeft == theRight) return ;

    Node *theNode_l = findAtIndex(thelist,theLeft);
    Node *theNode_r = findAtIndex(thelist,theRight);
    Node *theNode_rNext = findAtIndex(thelist,theRight)->next;

    if(theLeft==0)
    {
        thelist->first = theNode_r;
        thelist->first->next = theNode_l->next;
    }
    else
    {
        findAtIndex(thelist,theLeft-1)->next = theNode_r;
        findAtIndex(thelist,theLeft-1)->next->next = theNode_l->next;
    }

    findAtIndex(thelist,theRight-1)->next = theNode_l;
    findAtIndex(thelist,theRight-1)->next->next = theNode_rNext;

    if(theRight+1 == thelist->size)
    {
        thelist->last = findAtIndex(thelist,theRight);
    }
}

int partition(List *thelist, int aLeftIndex, int aRightIndex)
{
    char thePivot = findAtIndex(thelist, aLeftIndex)->letter;
	int theLeft = aLeftIndex;
	int theRight = aRightIndex + 1;

	while (1)
	{
		do theLeft++; while (theLeft <= aRightIndex && findAtIndex(thelist, theLeft)->letter <= thePivot);

        do theRight--; while (findAtIndex(thelist, theRight)->letter > thePivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
        {
            swap(thelist, theLeft, theRight);
        }
	}
	swap(thelist, aLeftIndex, theRight);

	return theRight;
}

void quickSort(List *thelist, int aLeftIndex, int aRightIndex)
{
    int thePartitionIndex;

	if ( aLeftIndex <aRightIndex )
	{

	thePartitionIndex = partition(thelist, aLeftIndex, aRightIndex);

	quickSort(thelist, aLeftIndex, thePartitionIndex - 1);

	quickSort(thelist, thePartitionIndex + 1, aRightIndex);
	
	}
}


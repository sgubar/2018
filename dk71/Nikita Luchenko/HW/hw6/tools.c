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

void delete_element(List *thelist, int index)  
{
	int i = 0;
	if ((thelist->first == NULL) || (index >= thelist->size))return;
	Node *theNode = thelist->first, *temp;
		if(index == 0)
	  {
	 	thelist->first = thelist->first->next;
	 	temp = theNode;
         thelist->size--;
  	  }
	else
	{
   	 for (i ; i < index-1; ++i)
		{
			theNode = theNode->next;
		}
    	 temp = theNode->next;
   	     theNode->next = theNode->next->next;
   	     
      if (temp == thelist->last)
        {
            thelist->last = theNode;
        }
    	thelist->size--;

	}
	free(temp);
}

void insert_element(List *thelist, int index, char letter) 	
{
    int theResult = -1;
	if (NULL == thelist || index >= thelist->size || index < 0)
	{
		return theResult;
	}
	
	Node *theNode = thelist->first;
	int i = 0;

	do
	{
		if (i == index)
		{
			break;
		}
	
		theNode = theNode->next;
		i++;
	
	}while (NULL != theNode);

	
    Node *theNewNode = createNodeWithLetter(letter);
	if (NULL == theNewNode)
	{
		return theResult;
	}
	
	Node *theBeforeNode = theNode;
	
	if (NULL != theBeforeNode->prev)
	{
		theBeforeNode->prev->next = theNewNode; 
		theNewNode->prev = theBeforeNode->prev;
	}
	
	theNewNode->next = theBeforeNode; 
	theBeforeNode->prev = theNewNode;
	thelist->size ++;
	theResult = 0;
	return theResult;
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

void size_list(List *thelist)
{
	if(thelist != NULL)
		{
			printf("\nThe size of the list = %d", thelist->size);
		}
	
}

void qsort_list(List *thelist, int first, int last)
{
  {
    int thePartitionIndex;

	if (first < last)
	{
		thePartitionIndex = partition(thelist, first, last);

		qsort_list(thelist, first, thePartitionIndex - 1);

		qsort_list(thelist, thePartitionIndex + 1, last);
	}
}

int partition(List *thelist, int first, int last)
{
    char thePivot = NodeAtIndex(thelist, last)->letter;
	int theLeft = first;
	int theRight = last + 1;

	while (1)
	{
		do theLeft++; while (theLeft < last && NodeAtIndex(thelist, theLeft)->letter < thePivot);

        do theRight--; while (NodeAtIndex(thelist, theRight)->letter > thePivot);

		if (theLeft >= theRight)
		{
			break;
		}
		else
        {
            swap(thelist, theLeft, theRight);
        }
	}
	swap(thelist, first, last);

	return theRight;
}

void swap(List *thelist, int theLeft, int theRight)
{
    if (theLeft == theRight) return;

    Node *theNode_l = NodeAtIndex(thelist,theLeft);
    Node *theNode_r = NodeAtIndex(thelist,theRight);
	int temp = theNode_l->letter;
	theNode_l->letter = theNode_r->letter;
	theNode_r->letter = temp;
}

Node *NodeAtIndex(List *thelist, int index)
{
	Node *theResult = NULL;

	if (NULL != thelist && index < thelist->size)
	{
		int i = 0;
		Node *theNode = thelist->first;

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



#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dk_tool.h"

List *create_list()
{
	List *thelist = malloc(sizeof(List));
	if(thelist != NULL)
  	{
		thelist->size = 20;
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
    theNode->value = letter;
    theNode->prev = NULL;
    theNode->next = NULL;
  }
	return theNode;
}

void add_element(List *alist, char letter) 
{
	if (alist != NULL)
	{
		Node *theNode = createNodeWithLetter(letter);
	
		if (theNode != NULL)
		{
			if ( alist->first == NULL && alist->first == alist->last)
			{
				alist->first = alist->last = theNode;
			}
			else
			{
				Node *thelast = alist->last;
				alist->last = theNode;
				thelast->next = theNode;
				theNode->prev = thelast;
			}
				alist->size++;
		}
	}
}

void delete_element(List *alist, int index)  
{
	int i = 0;
	if ((alist->first == NULL) || (index >= alist->size))	return;

	Node *theNode = alist->first, *temp;
	
	if(index == 0)
	{
		alist->first = alist->first->next;
	 	temp = theNode;
        alist->size--;
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

      	if (temp == alist->last)
        {
            alist->last = theNode;
        }
    	alist->size--;
	}
	free(temp);
}

void insert_element(List *alist, int index, char letter) 	
{
    int theResult = -1;
	if (NULL == alist || index >= alist->size || index < 0)
	{
		return theResult;
	}

	Node *theNode = alist->first;
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
	if (NULL == theNewNode)	return theResult;

	Node *theBeforeNode = theNode;
	if (NULL != theBeforeNode->prev)
	{
		theBeforeNode->prev->next = theNewNode; 
		theNewNode->prev = theBeforeNode->prev;
	}

	theNewNode->next = theBeforeNode; 
	theBeforeNode->prev = theNewNode;
	alist->size ++;
	theResult = 0;
}

void delete_list(List *alist) 
{
	int i = 0;
	if (alist == NULL)	return;

	Node *theNode = alist->first;
	for (i ; i < alist->size; i++)
	{
	    if(theNode == NULL)	break;

		Node *theNodeToDelete = theNode;
		theNode = theNode->next;
		free(theNodeToDelete);
	}
	free(alist);
}

void size_list(List *alist)
{
	if(alist!= NULL)	printf("\nSize of list = %d", alist->size);
}

void qsort_list(List *thelist, int first, int last)
{
    int thePartitionIndex;
	if (first < last)
	{
		thePartitionIndex = partition(thelist, first, last);
		qsort_list(thelist, first, thePartitionIndex - 1);
		qsort_list(thelist, thePartitionIndex + 1, last);
	}
}

int partition(List *alist, int first, int last)
{
    char Pivot = NodeAtIndex(alist, last)->value;
	int theLeft = first;
	int theRight = last + 1;

	while (1)
	{
		do
		{
			theLeft++;
		}
		while (theLeft < last && NodeAtIndex(alist, theLeft)->value < Pivot);
		
        do
		{
			theRight--;
		}
		while (NodeAtIndex(alist, theRight)->value > Pivot);

		if (theLeft >= theRight)	break;
		else
        {
            swap(alist, theLeft, theRight);
        }
	}
	swap(alist, first, last);
	
	return theRight;
}

void swap(List *alist, int theLeft, int theRight)
{
    if (theLeft == theRight) return;

    Node *theNode_l = NodeAtIndex(alist,theLeft);
    Node *theNode_r = NodeAtIndex(alist,theRight);
	int temp = theNode_l->value;
	theNode_l->value = theNode_r->value;
	theNode_r->value = temp;
}

Node *NodeAtIndex(List *alist, int index)
{
	Node *theResult = NULL;
	if (NULL != alist && index < alist->size)
	{
		int i = 0;
		Node *theNode = alist->first;
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















































































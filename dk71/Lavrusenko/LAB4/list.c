
#include "ListItem.h"
#include "list.h"
#include <stdlib.h>


const int kSLListError = -1;


ListOptions *SLCreateList()
{
	
	ListOptions *theList = (ListOptions *)malloc(sizeof(ListOptions));


	theList->head = NULL; 
	theList->tail = NULL; 
	theList->count = 0; 	
	
	return theList;
}

void SLFreeList(ListOptions *aList)
{
	
	if (NULL == aList)
	{
		return;
	}

	Item_List *theNode = aList->head;
	
	while (NULL != theNode)
	{
		Item_List *theNodeToBeFree = theNode;
		theNode = theNode->next;
	
		FreeIntNode(theNodeToBeFree);
	}


	free(aList);
}

Item_List  *SLAddNode(ListOptions *aList, Item_List *aNewNode)
{
	
	if (NULL == aList || NULL == aNewNode)
	{ 
		return NULL;
	}
	
	

	if (NULL == aList->head && NULL == aList->tail)
	{
	
		aList->head = aList->tail = aNewNode;
		
	}
	else
{
		Item_List *theTail = aList->tail;
		aList->tail = aNewNode;

		if (NULL != theTail)
		{
			theTail->next = aList->tail;
			
		}
	}

	aList->count += 1;
Item_List *clone = CreateItemOfList(aNewNode->value);
Item_List *clonetail = aList->tail;
		aList->tail = clone;

		if (NULL != clonetail)
		{
			clonetail->next = aList->tail;
			
		}
		aList->count += 1;
	return clone;
}


int SLCountList(const ListOptions *aList)
{
	int theResult = kSLListError;

	if (NULL != aList)
	{
		theResult = aList->count;
	}

	return theResult;
}

Item_List *SLNodeAtIndex(const ListOptions *aList, int anIndex)
{
	Item_List *theResult = NULL;

	if (NULL != aList && anIndex < aList->count)
	{
		int i = 0;
		Item_List *Item = aList->head;
	
		do
		{
			if (i == anIndex) //<!- index was found
			{
				theResult = Item; //<! - our node
				break;
			}
		
			i++; // increase index
			Item = Item->next; //<! - go to next node
		
		} while (NULL != Item);
	}
	
	return theResult;
}

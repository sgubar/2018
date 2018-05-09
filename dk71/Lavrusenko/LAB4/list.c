
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
	return aNewNode;
}

void twiceNode(ListOptions *aList ){
	int i=0;
	int c=SLCountList(aList);	

	Item_List *clone  ;
	Item_List *clonenext  ;
	Item_List *before  ;	
	
	clone = aList->head;
for(i=0;i<c;i++){
			
		


if (clone==aList->tail){ 

clonenext = CreateItemOfList(clone->value);

		clone->next = clonenext;
		clonenext = aList->tail;
		aList->count += 1;
		break;
}
if(clone == aList->head){

	clonenext = CreateItemOfList(clone->value);
before = clone->next;
clone->next = NULL;
clone->next = clonenext;
clonenext->next= before;		
	aList->count += 1;
	clone = before;
	
}else{
clonenext = CreateItemOfList(clone->value);
before = clone->next;
clone->next = NULL;
clonenext->next = before;

clone->next = clonenext;
aList->count += 1;
clone = before;
}

}

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


void doPrintSLList(const ListOptions *aList)
{
	int i;
	for (i = 0; i < SLCountList(aList); i++)
	{
		Item_List *theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			printf("node[%d].value = %d\n", i, theNode->value);
		}
	}
}

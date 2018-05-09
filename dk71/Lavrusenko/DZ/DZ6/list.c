
#include "ListItem.h"
#include "list.h"
#include <stdlib.h>

#include "windows.h"

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
{		FILE *file;
	int i;
	if((file = fopen ("list.txt", "a")) == NULL){
        printf("ERROR");}
         Item_List *theNode;
	for (i = 0; i < SLCountList(aList); i++)
	{
		theNode = SLNodeAtIndex(aList, i);
		if (NULL != theNode)
		{
			fprintf(file,"node[%d].value = %f\n", i, theNode->value);
		}
	}
	fclose(file);
}
void swap(ListOptions *aList, int left ,int right)
{																				
	Item_List *Right = SLNodeAtIndex(aList,right);
	Item_List *Left = SLNodeAtIndex(aList,left);
	Item_List *bufferLeft  ;
	Item_List *bufferRight ;

	bufferRight = SLNodeAtIndex(aList,right)->next;
		
	bufferLeft = SLNodeAtIndex(aList,left)->next;

	Item_List *beforeLeft ;
	Item_List *beforeRight = SLNodeAtIndex(aList,right-1);
			
	if(aList->head == Left){ 
		aList->head = NULL;
		Left->next = NULL;
		Right->next = NULL;
		beforeRight->next = NULL;
		
		aList->head = Right;
		Right->next = bufferLeft;
		beforeRight->next = Left;
		Left->next = bufferRight;
																			
			return;
			
		}
		
	beforeLeft = SLNodeAtIndex(aList,left-1);
		
		
	if(Right->next==aList->tail){
			
		Right->next = NULL;
		beforeRight->next = NULL;
		beforeLeft->next = NULL;
		Left->next = NULL;
		
		Left->next = aList->tail;
		beforeRight->next = Left;
		beforeLeft->next = Right;
		Right->next = bufferLeft;
											
			return;
		}
		
		if(Left->next == Right){
			
		Right->next = NULL;	
		beforeLeft->next = NULL;	
		Left->next = NULL;	
		
		beforeLeft->next = Right;
		Right->next = Left;
		Left->next = bufferRight;
			
		return;	
		}
	
		Left->next = NULL;
		beforeLeft->next = NULL;
		Right->next = NULL;
		beforeRight->next = NULL;
		
		beforeLeft->next = Right;
		Right->next = bufferLeft;
		beforeRight->next = Left;
		Left->next = bufferRight;
											
			return;
}

void shell_sort(ListOptions *aList){

   int i, j, step;
   int count = SLCountList(aList);
   Item_List *buffer;
   
        for (step = count / 2; step > 0; step /= 2){
    	
        for (i = step; i < count; i++)
        { 
        buffer = SLNodeAtIndex(aList,i);
            for (j = i; j >= step; j -= step)
            {
                if (buffer->value < SLNodeAtIndex(aList,j-step)->value){
                
               swap(aList,j-step,j);
               
			 }
                else{
                    break;}
                      }
                      
      }
}
 
    return ;
    	
}

   


#include <stdio.h>
#include "tool.h"
#include <conio.h>

#define MAX_VALUE 10


	int random()
	{
		int array[MAX_VALUE];
		int pos, letter_register;
		
		srand(time(NULL));
	
		for(pos = 0; pos < MAX_VALUE; pos++)
		{	
			
			letter_register = rand() % 2 + 1;
			
			switch(letter_register)
			{
				
				case 1:
					array[pos] = rand() % 26 + 65; 
					break;
				
				case 2:
					array[pos] = rand() % 26 + 97; 
					break;
				
				default: 
					break;
			}
		
		}
		
		return &array;
	}
	
		CharNode *SLCreateNodeWithCharValue(char aValue)
	{
		CharNode *theResult = (CharNode *)malloc(sizeof(CharNode));
	
		theResult->value = aValue;
		theResult->nextNode = NULL;
	
		return theResult;
	}
	
	void SLFreeCharNode(CharNode *aNode)
	{
		if (NULL != aNode)
		{
			free(aNode);
		}
	}
	
	void SLAddNode(CharList *aList, CharNode *aNewNode)
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
			CharNode *theTail = aList->tail;
			aList->tail = aNewNode;
	
			if (NULL != theTail)
			{
				theTail->nextNode = aList->tail;
			}
		}
	
		aList->count += 1;
	}
	
	CharNode *SLNodeAtIndex(const CharList *aList, int anIndex)
	{
		CharNode *theResult = NULL;
	
		if (NULL != aList && anIndex < aList->count)
		{
			int i = 0;
			CharNode *theNode = aList->head;
	
			do
			{
				if (i == anIndex)
				{
					theResult = theNode;
					break;
				}
	
				i++;
				theNode = theNode->nextNode;
	
			} while (NULL != theNode);
		}
	
		return theResult;
	}
	
	void SLInsertNodeAtIndex(CharList *alist, CharNode *value, int index)
	{
		if ((alist->head == NULL) || (index > alist->count) || (value == NULL))return ;
		CharNode *aNode = alist->head;
		if(index == 0)
	    {
			alist->head = value;
			value->nextNode = aNode;
	    }
	    else if (alist->count == index)
		{
			SLAddNode(alist,value);
	
		}
		else
	    {
	    	int i;
			for (i = 0; i < index-1; ++i)
			{
				aNode = aNode->nextNode;
			}
			value->nextNode = aNode->nextNode;
			aNode->nextNode = value;
	    }
		alist->count++;
	}
	
	void SLRemovedNodeAtIndex(CharList *alist, int index)
	{
		if ((alist->head == NULL) || (index >= alist->count))return;
		CharNode *aNode = alist->head, *temp;
		if(index == 0)
		{
			alist->head = alist->head->nextNode;
			temp = aNode;
	        alist->count--;
	    }
		else
		{
		int i;
	    for (i = 0; i < index-1; ++i)
			{
				aNode = aNode->nextNode;
			}
	    temp = aNode->nextNode;
	    aNode->nextNode = aNode->nextNode->nextNode;
	    if (temp == alist->tail)
	        {
	            alist->tail = aNode;
	        }
	    alist->count--;
	
		}
		free(temp);
	}
	
	const int kSLListError = -1;
	
	CharList *SLCreateList()
	{
		CharList *theList = (CharList *)malloc(sizeof(CharList));
	
		theList->head = NULL;
		theList->tail = NULL;
		theList->count = 0;
	
	
		return theList;
	}
	
	void SLFreeList(CharList *aList)
	{
	
		if (NULL == aList)
		{
			return;
		}
	
		CharNode *theNode = aList->head;
		int i;
		for (i = 0; i < SLCountList(aList); i++)
		{
		    if(NULL==theNode)break;
	
			CharNode *theNodeToBeFree = theNode;
			theNode = theNode->nextNode;
	
			SLFreeCharNode(theNodeToBeFree);
		}
	
		free(aList);
	}
	
	int SLCountList(const CharList *aList)
	{
		int theResult = kSLListError;
	
		if (NULL != aList)
		{
			theResult = aList->count;
		}
	
		return theResult;
	}
	
	
	
	void doPrintSLList(const CharList *aList)
	{
		int i;
		for ( i = 0; i < SLCountList(aList); i++)
		{
			CharNode *theNode = SLNodeAtIndex(aList, i);
			if (NULL != theNode)
			{
				printf("%c ", theNode->value);
			}
		}
	}
	
	doPrintSLList_Conversely(const CharList *aList)
	{
		int i;
		for (i = SLCountList(aList); i>=0; i--)
		{
			CharNode *theNode = SLNodeAtIndex(aList, i);
			if (NULL != theNode)
			{
				printf("%c ", theNode->value);
			}
		}
	}
	
	void SLSwapNodesByIndex(CharList *aList, int theLeft, int theRight)
	{
	    if (theLeft == theRight) return ;
	
	    CharNode *theNode_l = SLNodeAtIndex(aList,theLeft);
	    CharNode *theNode_r = SLNodeAtIndex(aList,theRight);
	    CharNode *theNode_rNext = SLNodeAtIndex(aList,theRight)->nextNode;
	
	    if(theLeft==0)
	    {
	        aList->head = theNode_r;
	        aList->head->nextNode = theNode_l->nextNode;
	    }
	    else
	    {
	        SLNodeAtIndex(aList,theLeft-1)->nextNode = theNode_r;
	        SLNodeAtIndex(aList,theLeft-1)->nextNode->nextNode = theNode_l->nextNode;
	    }
	
	    SLNodeAtIndex(aList,theRight-1)->nextNode = theNode_l;
	    SLNodeAtIndex(aList,theRight-1)->nextNode->nextNode = theNode_rNext;
	
	    if(theRight+1 == aList->count)
	    {
	        aList->tail = SLNodeAtIndex(aList,theRight);
	    }
	}
	
	int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex)
	{
	    char thePivot = SLNodeAtIndex(aList, aLeftIndex)->value;
		int theLeft = aLeftIndex;
		int theRight = aRightIndex + 1;
	
		while (1)
		{
			do theLeft++; while (theLeft <= aRightIndex && SLNodeAtIndex(aList, theLeft)->value <= thePivot);
	
	        do theRight--; while (SLNodeAtIndex(aList, theRight)->value > thePivot);
	
			if (theLeft >= theRight)
			{
				break;
			}
			else
	        {
	            SLSwapNodesByIndex(aList, theLeft, theRight);
	        }
		}
		SLSwapNodesByIndex(aList, aLeftIndex, theRight);
	
		return theRight;
	}
	
	void loadFile (char * path, CharList *aList)
	{
	
	  FILE *theFile = fopen(path, "r");
	
	  if (theFile ==NULL)return ;
	
	  char symbol1;
	
	  CharNode *theNode = NULL;
	
	  while(!feof(theFile))
	  {
	      fscanf (theFile, "%c", &symbol1);
	
	      theNode = SLCreateNodeWithCharValue(symbol1);
	      SLAddNode(aList, theNode);
	  }
	
	  fclose(theFile);
	}

#include "dru_lib.h"

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
	
		while(NULL!=theNode)
		{
			CharNode *theNodeToDelete = theNode;
			
			free (theNodeToDelete);
			theNode = theNode->next;
		}
	
		free(aList);
	}
}

void TLAddCharValueToList(CharList *aList, char aCharValue)
{
	if (NULL==aList) return;
	
	CharNode *theNode=createCharNodeWithValue(aCharValue);
	
	if (NULL != theNode)
	{
		if (NULL == aList->head && aList->head == aList->tail)	aList->head=aList->tail=theNode;
		else
		{
			/*CharNode *theTail = aList->tail;
			aList->tail = theNode;
			theTail->next = theNode;
			theNode->prev = theTail;*/
			
			CharNode *temp=aList->head;
			aList->head=theNode;
			temp->prev=theNode;
			theNode->next=temp;
		}
	
		aList->count++;
	}
}

// Print list
void TLPrintList(CharList *aList)
{
	printf("[List] with count (%d):\n", aList->count);
	CharNode *theNode = aList->head;
	
	while (NULL != theNode)
	{
		printf("(%c) ", theNode->value);
		theNode = theNode->next;
	
	}
	
	printf ("\n");
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
	if(file == NULL)
	{
		printf("ERROR\n");
		return ;
	}
	char tmp;
    while(feof(file)==0)
    {
        fscanf(file, "%c",&tmp);
        TLAddCharValueToList(theList,tmp);
    }
}



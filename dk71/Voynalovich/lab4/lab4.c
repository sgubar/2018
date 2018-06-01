#include "lab4.h"

list* CreateList()
{
	list* thelist = malloc(sizeof(list));
	
	thelist->size = 0;
	
	thelist->head  = NULL;
	thelist->tail = NULL;
	
	return thelist;
}

void AddTheElement(list* thelist, float aValue) 
{
    node* theNode = malloc(sizeof(node));

    theNode->Value = aValue;
    theNode->next = NULL;
    theNode->prev = thelist->tail;
    if (thelist->tail) 
    
           thelist->tail->next = theNode;
           thelist->tail = theNode;
 
    if (thelist->head == NULL)
     
           thelist->head = theNode;

    thelist->size++;
}



void PrintTheList(list* thelist) 
{
    node* theNode = thelist->head;
	
	while(theNode)
	{
        printf("%.1f ", theNode->Value);
        theNode = theNode->next;
    }
    printf("\n");

	printf("%.1f ", thelist->head->Value);
	
     theNode = thelist->tail->prev;
	
	while(theNode->prev)
	{
        printf("%.1f ", theNode->Value);
        theNode = theNode->prev;
    }
	printf("%.1f ", thelist->tail->Value);
    printf("\n");
}

void DeleteList(list* thelist) 
{
    node* theNode = thelist->head;
    node* theNextNode = malloc(sizeof(node));
    while (theNode) {
        theNextNode = theNode->next;
        free(theNode);
        theNode = theNextNode;
    }
    free(thelist);
    thelist = NULL;
}


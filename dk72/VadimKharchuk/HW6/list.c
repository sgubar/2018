//
// Created by vadim on 03.05.2018.
//
#include <stdio.h>
#include <stdlib.h>
#include "list.h"


IntNode *createIntNodeWithValue (int anIntValue)
{
    IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
    if (NULL != theNode)
    {
        theNode -> next = NULL;
        theNode -> prev = NULL;
        theNode -> value = anIntValue;
    }
    return theNode;
}

IntList *CreateIntList()
{
    IntList *theList = (IntList *)malloc(sizeof(IntList));

    if(theList != NULL)
    {
        theList -> head = NULL;
        theList -> tail = NULL;
        theList -> count = NULL;
    }
    return theList;
}

void DestroyIntList(IntList *aList)
{
    if(aList == NULL)
    {
        return ;
    }
    if (NULL != aList -> tail && NULL != aList -> head)
    {
        IntNode *theNode = aList -> head;
        do {
            IntNode *theNodeWhatDelete = theNode;
            theNode = theNode -> next;
            free(theNodeWhatDelete);
        }
        while (theNode != NULL);
        free(aList);
    }
}

void PrintList (IntList *aList)
{
    if (aList != NULL) {
        printf("List with value (%d): ", aList->count);
        IntNode *theNode = aList->head;
        do {
            printf("%d  ", theNode->value);
            theNode = theNode->next;
        } while (NULL != theNode);
        printf("\n");
    }
    else
    {
        printf("SomeError");
    }
}


int AddIntValueToList (IntList *aList, int anIntValue) {
    int theRezult = -1;
    if (aList != NULL) {
        IntNode *theNode = createIntNodeWithValue(anIntValue);

        if (theNode != NULL) {
            if (aList->head == NULL && aList->head == aList->tail) {
                aList->head = aList->tail = theNode;
            } else {
                IntNode *theTail = aList->tail;
                aList->tail = theNode;
                theTail->next = theNode;
                theNode->prev = theTail;
            }
            aList->count++;
            theRezult = 0;
        }
    }
    return theRezult;
}


int InsertIntValueAtIndex(IntList *aList, int anIntValue, int anIndex)
{
    int theResult = -1;
    if (NULL == aList || anIndex >= aList->count || anIndex < 0)
        return theResult;

    IntNode *theNode = aList->head;
    int i = 0;
    do
    {
        if (i == anIndex) {
            break;
        }
        theNode = theNode->next;
        i++;
    }while (NULL != theNode);
    IntNode *theNewNode = createIntNodeWithValue(anIntValue);

    if (NULL == theNewNode)
        return theResult;

    IntNode *theBNode = theNode;
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





//
// Created by vadim on 15.05.2018.
//

#include "check.h"
#include <stdlib.h>
#include <stdio.h>
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


IntNode *createIntNodeWithValue (int anIntValue)
{
    IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));
    if (NULL != theNode)
    {
        theNode -> next = NULL;
        theNode -> value = anIntValue;
    }
    return theNode;
}
void addValueToList(IntList *aList,char symbol)
{
    if (aList != NULL) {
        IntNode *theNode = createIntNodeWithValue(symbol);
        if (theNode != NULL) {
            if (aList->head == NULL && aList->head == aList->tail) {
                aList->head = aList->tail = theNode;
            } else {
                IntNode *theTail = aList->tail;
                aList->tail = theNode;
                theTail->next = theNode;
            }
            aList ->symbol = symbol;
            aList->count++;
        }
    }
}

void check(IntList *aList, IntList *bList,FILE *aFile)
{
    int i = 0;
    if (NULL == aList || NULL == aFile)
    {
        return ;
    }
    do
    {
        i = getc(aFile);
        if (i == '{')
        {
            addValueToList(aList,i);

        };
        if (i == '}')
        {
            addValueToList(bList, i);
        };
    } while (i != EOF); // пока не конец файла
    fclose (aFile);
    if(aList -> count == bList ->count)
        printf("allFine");
    else
        printf("You had mistake");
}

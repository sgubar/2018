//
// Created by vadim on 15.05.2018.
//

#include "check.h"
#include <stdlib.h>
#include <stdio.h>
CharList *CreateCharList()
{
    CharList *theList = (CharList *)malloc(sizeof(CharList));

    if(theList != NULL)
    {
        theList -> head = NULL;
        theList -> tail = NULL;
        theList -> count = NULL;
    }
    return theList;
}
void DestroyCharList(CharList *aList)
{
    if(aList == NULL)
    {
        return ;
    }
    if (NULL != aList -> tail && NULL != aList -> head)
    {
        CharNode *theNode = aList -> head;
        do {
            CharNode *theNodeWhatDelete = theNode;
            theNode = theNode -> next;
            free(theNodeWhatDelete);
        }
        while (theNode != NULL);
        free(aList);
    }
}


CharNode *createCharNodeWithValue (int anCharValue)
{
    CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
    if (NULL != theNode)
    {
        theNode -> next = NULL;
        theNode -> value = anCharValue;
    }
    return theNode;
}
void addValueToList(CharList *aList,char symbol)
{
    if (aList != NULL) {
        CharNode *theNode = createCharNodeWithValue(symbol);
        if (theNode != NULL) {
            if (aList->head == NULL && aList->head == aList->tail) {
                aList->head = aList->tail = theNode;
            } else {
                CharNode *theTail = aList->tail;
                aList->tail = theNode;
                theTail->next = theNode;
            }
            aList ->symbol = symbol;
            aList->count++;
        }
    }
}

void check(CharList *aList, CharList *bList,FILE *aFile)
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
    if(aList -> count == bList ->count) {
        printf("allFine\n");
        printf("Count of '{' == '}'");
    }
    else {
        printf("You had mistake");
        printf("Count of '{' =  %d  Count of '}' = %d",aList ->count, bList->count);
    }
}

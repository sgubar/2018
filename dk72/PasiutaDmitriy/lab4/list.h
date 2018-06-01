//
// Created by dima on 01.06.18.
//

#ifndef LABA4_LIST_H
#define LABA4_LIST_H

#include <stdio.h>
#include <stdlib.h>

extern const int kSLListError;

typedef struct __DoubleNode DoubleNode;

struct __DoubleNode
{
    double value;
    DoubleNode *nextNode;
};

typedef struct __DoubleNode DoubleNode;

typedef struct __DoubleList
{
    DoubleNode *head;
    DoubleNode *tail;
    int count;
}DoubleList;

DoubleNode *SLCreateNodeWithDoubleValue(double aValue);
void SLFreeDoubleNode(DoubleNode *aNode);
void SLAddNode(DoubleList *aList, DoubleNode *aNewNode);
DoubleNode *SLNodeAtIndex(const DoubleList *aList, int aIndex);
void SLInsertNodeAtIndex(DoubleList *alist, DoubleNode *value, int index);
void SLRemovedNodeAtIndex(DoubleList *aList, int anIndex);
DoubleNode *MaxElem (DoubleList *alist);
DoubleNode *MinElem (DoubleList *alist);
int NumberElement (DoubleList *alist, DoubleNode *Node);


DoubleList *SLCreateList();
void SLFreeList(DoubleList *aList);
int SLCountList(const DoubleList *aList);
void doPrintSLList(const DoubleList *aList);
void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

void SLSwapNodesByIndex(DoubleList *aList, int theLeft, int theRight);
int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex);
#endif //LABA4_LIST_H

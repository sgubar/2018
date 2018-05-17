#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>

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


DoubleList *SLCreateList();
void SLFreeList(DoubleList *aList);
int SLCountList(const DoubleList *aList);
void doPrintSLList(const DoubleList *aList);
void quickSort(DoubleList *aList, int aLeftIndex, int aRightIndex);

void SLSwapNodesByIndex(DoubleList *aList, int theLeft, int theRight);
int partitionIt(DoubleList *aList, int aLeftIndex, int aRightIndex);

#endif

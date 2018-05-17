#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

typedef struct __FloatNode FloatNode;

typedef struct __FloatList
{
	FloatNode *head;
	FloatNode *tail;
	int count;
}FloatList;

extern const int kSLListError;

FloatList *SLCreateList();
void SLFreeList(FloatList *aList);

FloatNode *SLAddNode(FloatList *aList, FloatNode *aNewNode);

int SLCountList(const FloatList *aList);
FloatNode *SLNodeAtIndex(const FloatList *aList, int aIndex);

FloatNode *SLInsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex);
FloatNode *SLRemovedNodeAtIndex(FloatList *aList, int anIndex);

void SLSwapNodesByIndex(FloatList *aList, int aLeftIndex, int aRightIndex);

#endif // SingleLinkedList_h 

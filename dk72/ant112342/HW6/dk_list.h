#ifndef dk_list_h
#define dk_list_h
#include <stdio.h>


typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
}IntList;

extern const int kSLListError;

IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);

IntNode *SLInsertNodeAtIndex(IntList *aList, IntNode *aNewNode, int anIndex);
IntNode *SLRemovedNodeAtIndex(IntList *aList, int anIndex);

void SLSwapNodesByIndex(IntList *aList, int aLeftIndex, int aRightIndex);
void doPrintSLList(const IntList *aList);

#endif

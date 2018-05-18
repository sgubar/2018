#ifndef SingleLinkedList_h
#define SingleLinkedList_h

#include <stdio.h>

typedef struct __CharNode CharNode;

typedef struct __CharList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

extern const int kSLListError;

CharList *SLCreateList();
void SLFreeList(CharList *aList);

CharNode *SLAddNode(CharList *aList, CharNode *aNewNode);

int SLCountList(const CharList *aList);
CharNode *SLNodeAtIndex(const CharList *aList, int aIndex);

CharNode *SLInsertNodeAtIndex(CharList *aList, CharNode *aNewNode, int anIndex);
CharNode *SLRemovedNodeAtIndex(CharList *aList, int anIndex);

void SLSwapNodesByIndex(CharList *aList, int aLeftIndex, int aRightIndex);

#endif // SingleLinkedList_h 

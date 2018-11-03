#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define N 50

extern const int kSLListError;

typedef struct __CharNode CharNode;

struct __CharNode
{
	char value[N];
	CharNode *nextNode;
};

typedef struct __CharNode CharNode;

typedef struct __CharList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;

CharNode *SLCreateNodeWithCharValue(char aValue[N]);
void SLFreeCharNode(CharNode *aNode);
void SLAddNode(CharList *aList, CharNode *aNewNode);
CharNode *SLNodeAtIndex(const CharList *aList, int aIndex);
void SLInsertNodeAtIndex(CharList *alist, CharNode *value, int index);
void SLRemovedNodeAtIndex(CharList *aList, int anIndex);

CharList *SLCreateList();
void SLFreeList(CharList *aList);
void doPrintSLList(const CharList *aList);
int SLCountList(const CharList *aList);
void quickSort(CharList *aList, int aLeftIndex, int aRightIndex);

void SLSwapNodesByIndex(CharList *aList, int theLeft, int theRight);
int partitionIt(CharList *aList, int aLeftIndex, int aRightIndex);

#endif

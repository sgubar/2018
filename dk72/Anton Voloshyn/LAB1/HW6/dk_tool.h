
#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct __doubleNode doubleNode;

typedef struct __doubleList
{
    doubleNode *head;
    doubleNode *tail;
    double count;
}doubleList;
struct __doubleNode
{
    double value;
    doubleNode *nextNode;//
};
doubleNode *SLCreateNodeWithdoubleValue(double aValue);
void SLFreedoubleNode(doubleNode *aNode);

extern const double kSLListError;

doubleList *SLCreateList();
void SLFreeList(doubleList *aList);

doubleNode *SLAddNode(doubleList *aList, doubleNode *aNewNode);

double SLCountList(const doubleList *aList);
doubleNode *SLNodeAtIndex(const doubleList *aList, int aIndex);

doubleNode *SLInsertNodeAtIndex(doubleList *aList, doubleNode *aNewNode, int anIndex);
doubleNode *SLRemovedNodeAtIndex(doubleList *aList, int anIndex);

void SLSwapNodesByIndex(doubleList *aList, int aLeftIndex, int aRightIndex);

#endif /* list_h */
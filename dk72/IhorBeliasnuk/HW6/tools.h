//
// Created by Ihor on 17.05.2018.
//

#ifndef HW6_TOOLS_H
#define HW6_TOOLS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __FloatNode FloatNode;
struct __FloatNode
{
    float value;
    FloatNode *nextNode;//<! - the reference to next node
};

typedef struct __FloatList
{
    FloatNode *head;
    FloatNode *tail;
    int count;
}FloatList;


FloatNode *SLCreateNodeWithIntValue(float aValue);
void SLFreeFloatNode(FloatNode *aNode);

FloatList *SLCreateList();
void SLFreeList(FloatList *aList);
FloatNode *SLAddNode(FloatList *aList, FloatNode *aNewNode);
int SLCountList(const FloatList *aList);
FloatNode *SLNodeAtIndex(const FloatList *aList, int aIndex);
FloatNode *SLInsertNodeAtIndex(FloatList *aList, FloatNode *aNewNode, int anIndex);
FloatNode *SLRemovedNodeAtIndex(FloatList *aList, int anIndex);
void SLSwapNodesByIndex(FloatList *aList, int aLeftIndex, int aRightIndex);

void shellSort(FloatList *aList, int aCount);


#endif //HW6_TOOLS_H

//
// Created by Ihor on 16.05.2018.
//

#ifndef LW4_TOOLS_H
#define LW4_TOOLS_H

#include <stdio.h>

typedef struct __CharNode CharNode;

struct __CharNode
{
    char value;
    CharNode *nextNode;//<! - the reference to next node
};

typedef struct __CharList
{
    CharNode *head;
    CharNode *tail;
    int count;
}CharList;

//Interface


CharNode *SLCreateNodeWithCharValue(char aValue);
void SLFreeCharNode(CharNode *aNode);

//Create/delete a list
CharList *SLCreateList();
void SLFreeList(CharList *aList);

CharNode *SLAddNode(CharList *aList, CharNode *aNewNode);

int SLCountList(const CharList *aList);

int BracketBallanceCheck(FILE *aFile);





#endif //LW4_TOOLS_H

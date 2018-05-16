//
// Created by vadim on 15.05.2018.
//

#ifndef LAB4_CHECK_H
#define LAB4_CHECK_H
#include <stdlib.h>
#include <stdio.h>

typedef struct __tagCharNode CharNode;
struct __tagCharNode
{
    int value;
    CharNode *next;
};

typedef struct __tagCharList
{
    CharNode *head;
    CharNode *tail;
    char symbol;
    int count;

}CharList;

CharList *CreateCharList();
void DestroyCharList(CharList *aList);
void check(CharList *aList,CharList *bList, FILE *aFile);
void addValueToList(CharList *aList,char counter);
CharNode *createCharNodeWithValue (int anCharValue);
#endif //LAB4_CHECK_H

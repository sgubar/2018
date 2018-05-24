#ifndef func_h
#define func_h

#include <stdio.h>


typedef struct __tagCharNode CharNode;

typedef struct __tagCharNode
{
	char value;
	CharNode *prev;
	CharNode *next;
}CharNode;


typedef struct __tagCharList
{
	CharNode *head;
	CharNode *tail;
	int count;
}CharList;


CharList *TLCreateIntList();
char DestroyList(CharList *aList);
char ListValue(CharList *aList, char anIntValue);
char InsertValue(CharList *aList, char anIntValue, int anIndex);
char PrintList(CharList *aList);
CharNode *SLRemovedNodeAtIndex(CharList *aList, int anIndex);


#endif /* TLIntList_h */

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
void delete_element(CharList *aList, int anIndex);
CharNode *SLRemovedNodeAtIndex(CharList *aList, int anIndex);
void quickSort(CharList *thelist, int head, int tail);
void insert_element(CharList *thelist, int index, char value);
CharNode *NodeAtIndex(CharList *thelist, int index);
void swap(CharList *thelist, int theLeft, int theRight);
int partition(CharList *thelist, int head, int tail);

#endif /* TLIntList_h */

#ifndef list_h
#define list_h

#include <stdio.h>


typedef struct Item_of_list Item_List;

typedef struct __ListOptions
{
	Item_List *head;
	Item_List *tail;
	int count;
}ListOptions;

extern const int kSLListError;

//Interface
//Create/delete a list
ListOptions *SLCreateList();
void SLFreeList(ListOptions *aList);

Item_List *SLAddNode(ListOptions *aList, Item_List *aNewNode);

int SLCountList(const ListOptions *aList);
Item_List *SLNodeAtIndex(const ListOptions *aList, int aIndex);

void doPrintSLList(const ListOptions *aList);
void twiceNode(ListOptions *aList );
#endif 

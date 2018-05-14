#ifndef circular_list_h
#define circular_list_h

#include <stdio.h>

// Predeclaration
typedef struct __IntNode IntNode;

typedef struct __IntList
{
	IntNode *head;
	IntNode *tail;
	int count;
	
	
}IntList;

extern const int kSLListError;

//Interface
//Create/delete a list
IntList *SLCreateList();
void SLFreeList(IntList *aList);

IntNode *SLAddNode(IntList *aList, IntNode *aNewNode);

int SLCountList(const IntList *aList);
IntNode *SLNodeAtIndex(const IntList *aList, int aIndex);

// Predeclaration
typedef struct __IntNode IntNode;

// The node declaration
struct __IntNode
{
	int value;
	int index;
	int min;
	IntNode *nextNode;
	IntNode *node1;
//<! - the reference to next node
};

//Create a new Node with int value
IntNode *SLCreateNodeWithIntValue(IntList *aList, int aValue);
IntNode *SLCreateLastNode(int aValue, IntNode *aNode);
//Free a created node
void SLFreeIntNode(IntNode *aNode);

IntNode *minNode(const IntList *aList);
void doPrintSLList(const IntList *aList, int first);

#endif

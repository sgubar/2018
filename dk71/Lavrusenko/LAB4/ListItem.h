#ifndef ListItem_h
#define ListItem_h
#include <stdio.h>




typedef struct Item_of_list Item_List;
struct Item_of_list
{
	int value;
	Item_List *next;//<! - the reference to next node
} ;

//Create a new Node with int value
Item_List *CreateItemOfList(int aValue);
//Free a created node
void FreeIntNode(Item_List *aNode);

#endif /* SingleLinkedNode_h */

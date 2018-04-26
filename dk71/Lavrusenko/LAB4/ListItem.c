#include "list.h"
#include "ListItem.h"
#include <stdlib.h>

Item_List *CreateItemOfList(int aValue)
{
	Item_List *theResult = (Item_List *)malloc(sizeof(Item_List));
	
	theResult->value = aValue;
	theResult->next = NULL;
	
	return theResult;
}

void FreeIntNode(Item_List *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}

#include "SingleLinkedNode.h"
#include <stdlib.h>


CharNode *SLCreateNodeWithCharValue(char aValue)
{
	CharNode *theResult = (CharNode *)malloc(sizeof(CharNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeCharNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}


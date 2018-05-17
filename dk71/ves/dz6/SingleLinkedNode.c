#include "SingleLinkedNode.h"
#include <stdlib.h>


FloatNode *SLCreateNodeWithFloatValue(float aValue)
{
	FloatNode *theResult = (FloatNode *)malloc(sizeof(FloatNode));

	theResult->value = aValue;
	theResult->nextNode = NULL;

	return theResult;
}

void SLFreeFloatNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		free(aNode);
	}
}


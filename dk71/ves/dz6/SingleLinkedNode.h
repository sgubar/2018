#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __FloatNode FloatNode;

struct __FloatNode
{
	float value;
	FloatNode *nextNode;
};

FloatNode *SLCreateNodeWithFloatValue(float aValue);

void SLFreeIntNode(FloatNode *aNode);

#endif // SingleLinkedNode_h
#ifndef SingleLinkedNode_h
#define SingleLinkedNode_h

#include <stdio.h>
#include <stdlib.h>

typedef struct __CharNode CharNode;

struct __CharNode
{
	char value;
	CharNode *nextNode;
};

CharNode *SLCreateNodeWithCharValue(char aValue);

void SLFreeCharNode(CharNode *aNode);

#endif // SingleLinkedNode_h
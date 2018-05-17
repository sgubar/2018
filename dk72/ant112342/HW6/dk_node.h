#ifndef dk_node_h
#define dk_node_h

#include <stdio.h>


typedef struct __IntNode IntNode;


struct __IntNode
{
	int value;
	IntNode *nextNode;//<! - the reference to next node
};


IntNode *SLCreateNodeWithIntValue(int aValue);

void SLFreeIntNode(IntNode *aNode);

#endif


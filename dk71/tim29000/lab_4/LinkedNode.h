#ifndef LINKEDNODE_H_INCLUDED
#define LINKEDNODE_H_INCLUDED

#include <stdio.h>

typedef struct __IntNode IntNode;

struct __IntNode
{
	int data;
	IntNode *nextNode;
};


IntNode *CreateNode(int adata);

void FreeNode(IntNode *aNode);

#endif // LINKEDNODE_H_INCLUDED

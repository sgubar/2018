#ifndef LAB5_TOOL_H
#define LAB5_TOOL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct __node intNode;

struct __node
	{
	    int value;
	   	intNode *leftChild;
	    intNode *rightChild;
	};

typedef struct __tree
	{
    	intNode *root;
	    int count;
	}
	intTree;

	intTree *createIntTree();
	void deleteIntTree(intTree *aTree);
	void printTree(intNode *aRoot);

	void insertIntValueToTree(intTree *aTree, int aValue);
	int deleteValueFromTree(intTree *aTree, int aValue);

	intNode *searchNodeWithValue(intTree *aTree ,int aValue);

#endif

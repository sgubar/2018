#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct __tagNode
{
    int value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
}intNode;

typedef struct __tagTree
{
    intNode *root;
    int count;
}intTree;

void Symmetry(intNode *aNode);
void printTree (intTree *aTree);
intTree *createIntTree();
void destroyIntTree(intTree *aTree);
void insertIntValueToTree(intTree *aTree, int aValue);
intNode *deleteNodeWithElement(intTree *aTree, intNode* aNode, int aElement);
void destroyNode(intNode *aNode);
intNode *createIntNodeWithValue(int aValue);

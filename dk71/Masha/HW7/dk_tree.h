#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#ifndef tree_h
#define tree_h
#include <stdio.h>

typedef struct __tagNode
{
	int value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode *root;
	int count;
} IntTree;


IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);
void insertIntValueToTree(IntTree *aTree, int aValue);
IntNode *findNodeWithValue(IntTree *aTree, int aValue);
IntNode* deleteNodeWithIntValue(IntTree *aTree, IntNode* aNode, int aValue);
int countNodesWithTree(IntTree *aTree);
void destroyNode(IntNode *aNode);
void postOrder(IntNode *aNode);
void printTree(IntTree *aTree);
int countNodesWithTree(IntTree *aTree);
IntNode *createIntNodeWithValue(int aValue);
IntNode* find_endTree(IntNode* aNode);
#endif
#endif

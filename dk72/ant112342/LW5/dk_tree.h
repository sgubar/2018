#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#ifndef tree_h
#define tree_h
#include <stdio.h>

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;


DoubleTree *createDoubleTree();
void destroyDoubleTree(DoubleTree *aTree);
void insertDoubleValueToTree(DoubleTree *aTree, double aValue);
DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue);
DoubleNode* deleteNodeWithDoubleValue(DoubleTree *aTree, DoubleNode* aNode, double aValue);
int countNodesWithTree(DoubleTree *aTree);
void destroyNode(DoubleNode *aNode);
void postOrder(DoubleNode *aNode);
void printTree(DoubleTree *aTree);
int countNodesWithTree(DoubleTree *aTree);
DoubleNode *createDoubleNodeWithValue(double aValue);
DoubleNode* find_endTree(DoubleNode* aNode);
#endif
#endif


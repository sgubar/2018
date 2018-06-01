#ifndef DR7_V2_H_INCLUDED
#define DR7_V2_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>

typedef struct tag_treeNode treeNode;
typedef struct tag_treeNode
{
	float value;
	treeNode *left;
	treeNode *right;
	treeNode *parent;
}treeNode;

void printTree(treeNode *rootNode);
treeNode *createTreeNode();
void add_BTree_Node_with_value(treeNode *rootNode, float value);
treeNode *findMaxMin(treeNode *rootNode, int V);
treeNode *findValue(treeNode *rootNode, float value);
void deleteNode(treeNode *delNode);
void deleteTree(treeNode *rootNode, float *array_of_values, int num_of_elements);


#endif // DR7_V2_H_INCLUDED

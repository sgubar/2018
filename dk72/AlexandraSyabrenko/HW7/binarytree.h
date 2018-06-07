#ifndef binarytree_h
#define binarytree_h

#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;

struct node
{
    float value;
    Node *leftChild;
    Node *rightChild;
};

typedef struct tree
{
    Node *root;
    float count;
}Tree;

Tree *createTree(void);

void deleteTree(Tree *aTree);

void printTree(Node *aRoot);

void insertFloatValueToTree(Tree *aTree, float aValue);

int deleteValueFromTree(Tree *aTree, float aValue);
Node *reciever(Tree *aTree, Node *aDelNode);

Node *searchNodeWithValue(Tree *aTree, float aValue);

#endif /* binarytree_h */

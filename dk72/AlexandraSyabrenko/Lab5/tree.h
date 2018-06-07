#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>


typedef struct node Node;

struct node
{
    double value;
    Node *leftChild;
    Node *rightChild;
};

typedef struct tree
{
    Node *root;
    double count;
}Tree;

Tree *createTree(void);
void deleteTree(Tree *aTree);
void printTree(Node *aRoot);

void insertDoubleValueToTree(Tree *aTree, double aValue);
int deleteValueFromTree(Tree *aTree, double aValue);
Node *reciever(Tree *aTree, Node *aDelNode);
Node *searchNodeWithValue(Tree *aTree, double aValue);

#endif /* tree_h */

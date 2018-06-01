//
// Created by dima on 01.06.18.
//

#ifndef LABA5_TOOL_H
#define LABA5_TOOL_H


typedef struct aNode
{
    int value;
    struct aNode *left;
    struct aNode *right;
    struct aNode *parent;
}Node;

typedef struct aTree
{
    int aSize;//amount elements in tree
    Node *root;//pointer on higher  element,na vershinu
}Tree;

Tree *createTree();														//create base of tree
void destroyTree(Tree *aTree);											//destroy base of tree
Node *createNode(Node *aParent, int aValue);							//create element with aValue value
void destroyNode(Node *aNode);											//destroy element

void insertElementInTree(Tree *aTree, int aValue);						//insert element with aValue value
void deleteElementInTree(Tree *aTree, Node *aNode);						//delete element
void deleteElementInTreeByValue(Tree *aTree);	//delete element with aValue value

Node *minValue(Node *aNode);											//return min value after aNode pointer
Node *maxValue(Node *aNode);											//return max value after aNode pointer
Node *searchByValue(Node *aNode, int aValue);							//return pointer on element with aValue value
void postorderPrint(Node *aNode);										//print: left, right, root

int checkInput();
void addElement(Tree *aTree);


#endif //LABA5_TOOL_H

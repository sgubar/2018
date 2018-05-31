#ifndef DZ_7_H
#define DZ_7_H
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

void directOrder(IntNode *aNode);
void printTree (IntTree *aTree);

IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);

IntNode *findNodeWithValue(IntTree *aTree, int aValue);


IntNode* FindMin(IntNode* aNode);
IntNode* deleteNodeWithElement(IntTree *aTree,IntNode* aNode, int aElement);

#endif

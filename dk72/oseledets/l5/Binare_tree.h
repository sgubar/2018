#ifndef HW7_BINARE_TREE_H
#define HW7_BINARE_TREE_H
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

void Order(IntNode *aNode);
void printTree (IntTree *aTree);

IntTree *createIntTree();
void destroyIntTree(IntTree *aTree);

void insertIntValueToTree(IntTree *aTree, int aValue);

IntNode *findNodeWithValue(IntTree *aTree, int aValue);


IntNode* FindMin(IntNode* aNode);
IntNode* deleteNodeWithElement(IntTree *aTree,IntNode* aNode, int aElement);

#endif //HW7_BINARE_TREE_H

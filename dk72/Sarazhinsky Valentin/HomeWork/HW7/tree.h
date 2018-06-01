#ifndef TREE_H
#define TREE_H
typedef struct __tagNode
{
    int value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} FloatNode;

typedef struct __tagTree
{
    FloatNode *root;
    int count;
} FloatTree;

void directOrder(FloatNode *aNode);
void printTree (FloatTree *aTree);

FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, int aValue);

FloatNode *findNodeWithValue(FloatTree *aTree, int aValue);


FloatNode* FindMin(FloatNode* aNode);
FloatNode* deleteNodeWithElement(FloatTree *aTree,FloatNode* aNode, int aElement);

#endif

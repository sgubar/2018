#ifndef TREE_H
#define TREE_H
typedef struct __tagNode
{
    float value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} FloatNode;

typedef struct __tagTree
{
    FloatNode *root;
    float count;
} FloatTree;

void directOrder(FloatNode *aNode);
void printTree (FloatTree *aTree);

FloatTree *createFloatTree();
void destroyFloatTree(FloatTree *aTree);

void insertFloatValueToTree(FloatTree *aTree, float aValue);

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue);


FloatNode* FindMin(FloatNode* aNode);
FloatNode* deleteNodeWithElement(FloatTree *aTree,FloatNode* aNode, float aElement);

#endif

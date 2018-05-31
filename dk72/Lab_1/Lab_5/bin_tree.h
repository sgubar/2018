//
// Created by vadim on 20.05.2018.
//

#ifndef bin_tree_h
#define bin_tree_h
typedef struct __tagNode
{
    int value;
    struct __tagNode *leftChild;
    struct __tagNode *rightChild;
} Node;

typedef struct __tagTree
{
    Node *root;
    int count;
} Tree;

Node *createNodeWithValue(int aValue);
Node* FindMin(Node* aNode);
Node* deleteNodeWithElement(Tree *aTree,Node* aNode, int aElement);
Node *findNodeWithValue(Tree *aTree, int aValue);
Tree *createTree();
void postOrder(Node *aNode);
void printTree (Tree *aTree);
void deleteTree(Tree *aTree);
void insertValueToTree(Tree *aTree, int aValue);
void destroyNode(Node *aNode);


#endif

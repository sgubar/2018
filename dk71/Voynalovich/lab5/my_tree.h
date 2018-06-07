#ifndef my_tree_h

#define my_tree_h

typedef struct tagNode

{

    int value;

    struct tagNode *leftChild;

    struct tagNode *rightChild;

} Node;



typedef struct tagTree

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

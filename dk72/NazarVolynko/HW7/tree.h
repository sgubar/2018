#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} IntNode;

typedef struct __tagTree
{
	IntNode *root;
	int count;
} IntTree;


IntNode* create_IntNodeWithValue(double aValue);
void insert_IntValueToTree(IntTree *aTree, double aValue);
IntNode* find_NodeWithIntValue(IntTree *aTree, double aValue);
IntNode* find_endTree(IntNode* aNode);
IntNode* delete_NodeWithIntValue(IntTree *aTree,IntNode* aNode, double aValue);
void print_Node(IntNode *aNode);
void destroy_Node(IntNode *aNode);

IntTree* create_IntTree();
void print_Tree(IntTree *aTree);
int count_NodesInTree(IntTree *aTree);
void destroy_IntTree(IntTree *aTree);

#endif // TREE_H_INCLUDED

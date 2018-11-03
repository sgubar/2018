#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;


DoubleNode* create_FloatNodeWithValue(double aValue);
void insert_FloatValueToTree(DoubleTree *aTree, double aValue);
DoubleNode* find_NodeWithDoubleValue(DoubleTree *aTree, double aValue);
DoubleNode* find_endTree(DoubleNode* aNode);
DoubleNode* delete_NodeWithDoubleValue(DoubleTree *aTree, DoubleNode* aNode, double aValue);
void print_Node(DoubleNode *aNode);
void destroy_Node(DoubleNode *aNode);

DoubleTree* create_DoubleTree();
void print_Tree(DoubleTree *aTree);
int count_NodesInTree(DoubleTree *aTree);
void destroy_DoubleTree(DoubleTree *aTree);

#endif

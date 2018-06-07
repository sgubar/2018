#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct __tagNode
{
	char value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} CharNode;

typedef struct __tagTree
{
	CharNode *root;
	int count;
} CharTree;


CharNode* create_CharNodeWithValue(char aValue);
void insert_CharValueToTree(CharTree *aTree, char aValue);
CharNode* find_NodeWithCharValue(CharTree *aTree, char aValue);
CharNode* find_endTree(CharNode* aNode);
CharNode* delete_NodeWithCharValue(CharTree *aTree,CharNode* aNode, char aValue);
void print_Node(CharNode *aNode);
void destroy_Node(CharNode *aNode);

CharTree* create_CharTree();
void print_Tree(CharTree *aTree);
int count_NodesInTree(CharTree *aTree);
void destroy_CharTree(CharTree *aTree);

#endif // TREE_H_INCLUDED

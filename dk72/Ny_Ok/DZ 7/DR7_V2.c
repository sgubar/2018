#include "DR7_V2.h"

void printTree(treeNode *rootNode)
{
	if(rootNode)
	{
		printf("\n%4.2f",rootNode->value);
		printTree(rootNode->left);
		printTree(rootNode->right);
	}
}

void deleteNode(treeNode *delNode)
{
	if(!delNode->right&& !delNode->left)
	{
		if(delNode == delNode->parent->left)
			delNode->parent->left = NULL;
		else if(delNode == delNode->parent->right)
			delNode->parent->right= NULL;
	}
	else if(delNode->right|| delNode->left)
	{
		if(delNode->right)
		{
			if(delNode == delNode->parent->left)
				delNode->parent->left = delNode->right;
			else if(delNode == delNode->parent->right)
				delNode->parent->right= delNode->right;
		}else if(delNode->left)
		{
			if(delNode == delNode->parent->left)
				delNode->parent->left = delNode->left;
			else if(delNode == delNode->parent->right)
				delNode->parent->right= delNode->left;
		}
	}
	else if(delNode->right&& delNode->left)
	{
		treeNode *swap_Node = findMaxMin(delNode->left, 1);
		delNode->value = swap_Node->value;
		deleteNode(swap_Node);
		return;
	}
	free(delNode);
}

treeNode *findMaxMin(treeNode *rootNode, int V)
{
	treeNode *Node = rootNode;
	if(V== 0)
	{
		while(Node->left)
			Node = Node->left;
		return Node;
	}else if(V == 1)
	{
		while(Node->right)
			Node = Node->right;
		return Node;
	}
	return 0;
}

treeNode *findValue(treeNode *rootNode, float value)
{
	treeNode *Node = rootNode;
	while(Node)
	{
		if(value < Node->value)
		{
			Node = Node->left;
			continue;
		}
		else if(value > Node->value)
		{
			Node = Node->right;
			continue;
		}
		else
		{
			return Node;
		}
	}
	return NULL;
}


void add_BTree_Node_with_value(treeNode *rootNode, float value)
{
	treeNode *added_BTree_Node = createTreeNode();
	if(added_BTree_Node != NULL)
	{
		added_BTree_Node->value = value;
		treeNode *parent_of_Node = rootNode;
		while(parent_of_Node)
		{
			if(value > parent_of_Node->value)
			{
				if(parent_of_Node->right)
				{
					parent_of_Node = parent_of_Node->right;
					continue;
				}else
				{
					added_BTree_Node->parent = parent_of_Node;
					parent_of_Node->right = added_BTree_Node;
					return;
				}
			}else if(value < parent_of_Node->value)
			{
				if(parent_of_Node->left)
				{
					parent_of_Node = parent_of_Node->left;
					continue;
				}else
				{
					added_BTree_Node->parent = parent_of_Node;
					parent_of_Node->left = added_BTree_Node;
					return;
				}
			}else if(value == parent_of_Node->value)
			{
				free(added_BTree_Node);
				return;
			}
		}
	}
}

treeNode *createTreeNode(void)
{
	treeNode *createTreeNode = (treeNode *)malloc(sizeof(treeNode));
	if(createTreeNode != NULL)
	{
		createTreeNode->value = 0;
		createTreeNode->left = NULL;
		createTreeNode->right = NULL;
		createTreeNode->parent = NULL;
	}
	return createTreeNode;
}

void deleteTree(treeNode *rootNode, float *arrayValues, int kolichestvo_znacheniy)

{
	for(int i = kolichestvo_znacheniy - 1; i >= 0; --i)
	{
		treeNode *Node_for_delete = findValue(rootNode, arrayValues[i]);
		if(Node_for_delete)
			deleteNode(Node_for_delete);
		else
			continue;
	}
	free(rootNode);
}

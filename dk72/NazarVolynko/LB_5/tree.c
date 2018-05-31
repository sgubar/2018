#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


IntNode *create_IntNodeWithValue(int aValue)
{
		IntNode *theNode = (IntNode *)malloc(sizeof(IntNode));

if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void insert_IntNodeToTree(IntTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	IntNode *theNode = create_IntNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		IntNode *theCurrent = aTree->root;
		IntNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}

		aTree->count ++;
	}
}

IntNode *find_NodeWithIntValue(IntTree *aTree, int aValue)
{
	IntNode *theCurrentNode = NULL;

	int i = 0;
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
				i = 1;
				break;
			}
		}
	}

	if(i == 1)
	{
		printf("\nNode with %d value ISN'T in aTree\n", aValue);
	}
	else
	{
		printf("\nNode with %d value realy is in aTree\n", aValue);

	}

	return theCurrentNode;
}

IntNode* find_endTree(IntNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

IntNode* delete_NodeWithIntValue(IntTree *aTree, IntNode* aNode, int aValue)
{
    if (aNode == NULL)
    {
        return NULL;
    }
    else if (aValue < aNode->value)
        aNode->leftChild = delete_NodeWithIntValue(aTree, aNode->leftChild, aValue);
    else if (aValue > aNode->value)
        aNode->rightChild = delete_NodeWithIntValue(aTree , aNode->rightChild, aValue);
    else
    {
        if (aNode->leftChild == NULL && aNode->rightChild == NULL)
        {
            free(aNode);
            aNode = NULL;
            aTree->count--;
        }
        else if (aNode->leftChild == NULL)
        {
            IntNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aTree->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            IntNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aTree->count--;
        }
        else
        {
            IntNode *theTmp = find_endTree(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = delete_NodeWithIntValue(aTree, aNode->rightChild,theTmp->value);
            aTree->count--;
        }
    }
    return aNode;
}

void print_Node(IntNode *aNode)
{
	if(NULL != aNode)
	{
		print_Node(aNode->leftChild);
		print_Node(aNode->rightChild);
		printf("%d ",aNode->value);
	}
}

void destroy_Node(IntNode *aNode)
{
	if (aNode != NULL)
	{
		free (aNode);
	}
}

/*-----------------------*/

IntTree *create_IntTree()
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void print_Tree(IntTree *aTree)
{

     printf("\n");
		print_Node(aTree->root);
}

int count_NodesInTree(IntTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->count;
	}
	return size;
}

void destroy_IntTree(IntTree *aTree)
{
	if (NULL != aTree)
	{
		destroy_Node(aTree->root);
		free(aTree);
	}
}

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


DoubleNode *create_DoubleNodeWithValue(double aValue)
{
		DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void insert_DoubleNodeToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = create_DoubleNodeWithValue(aValue);
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
		DoubleNode *theCurrent = aTree->root;
		DoubleNode *theParent = NULL;

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

DoubleNode *find_NodeWithDoubleValue(DoubleTree *aTree, double aValue)
{
	DoubleNode *theCurrentNode = NULL;

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
		printf("\nNode with %.2f value ISN'T in aTree\n", aValue);
	}
	else
	{
		printf("\nNode with %.2f value realy is in aTree\n", aValue);

	}

	return theCurrentNode;
}

DoubleNode* find_endTree(DoubleNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

DoubleNode* delete_NodeWithDoubleValue(DoubleTree *aTree, DoubleNode* aNode, double aValue)
{
    if (aNode == NULL)
    {
        return NULL;
    }
    else if (aValue < aNode->value)
        aNode->leftChild = delete_NodeWithDoubleValue(aTree, aNode->leftChild, aValue);
    else if (aValue > aNode->value)
        aNode->rightChild = delete_NodeWithDoubleValue(aTree , aNode->rightChild, aValue);
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
            DoubleNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aTree->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            DoubleNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aTree->count--;
        }
        else
        {
            DoubleNode *theTmp = find_endTree(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = delete_NodeWithDoubleValue(aTree, aNode->rightChild,theTmp->value);
            aTree->count--;
        }
    }
    return aNode;
}

void print_Node(DoubleNode *aNode)
{
	if(NULL != aNode)
	{
		print_Node(aNode->leftChild);
		printf("%.2f ",aNode->value);
		print_Node(aNode->rightChild);
	}
}

void destroy_Node(DoubleNode *aNode)
{
	if (aNode != NULL)
	{
		free (aNode);
	}
}

/*-----------------------*/

DoubleTree *create_DoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void print_Tree(DoubleTree *aTree)
{
    printf("\n");
    print_Node(aTree->root);
}

int count_NodesInTree(DoubleTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->count;
	}
	return size;
}

void destroy_DoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroy_Node(aTree->root);
		free(aTree);
	}
}

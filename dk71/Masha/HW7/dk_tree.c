#include"dk_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include"dk_tree.h"
#include "menu.h"
IntTree *createIntTree()
{
	IntTree *theTree = (IntTree *)malloc(sizeof(IntTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyIntTree(IntTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertIntValueToTree(IntTree *aTree, int aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	IntNode *theNode = createIntNodeWithValue(aValue);
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

IntNode *findNodeWithValue(IntTree *aTree, int aValue)
{
    int i = 0;
    IntNode *theCurrentNode=NULL;
	if (NULL != aTree)
	{
		theCurrentNode = aTree->root;
		while (aValue != theCurrentNode->value)
		{
			 if(aValue < theCurrentNode->value)
                theCurrentNode=theCurrentNode->leftChild;
            else
                theCurrentNode=theCurrentNode->rightChild;

			if (NULL == theCurrentNode)
			{
			    i = 1;
				return NULL;
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

IntNode* deleteNodeWithIntValue(IntTree *aTree, IntNode* aNode, int aValue)
{
    if (aNode == NULL)
    {
        return NULL;
    }
    else if (aValue < aNode->value)
        aNode->leftChild = deleteNodeWithIntValue(aTree, aNode->leftChild, aValue);
    else if (aValue > aNode->value)
        aNode->rightChild = deleteNodeWithIntValue(aTree , aNode->rightChild, aValue);
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
            aNode->rightChild = deleteNodeWithIntValue(aTree, aNode->rightChild,theTmp->value);
            aTree->count--;
        }
    }
    return aNode;
}

void printTree(IntTree *aTree)
{
    printf("\n");
		postOrder(aTree->root);
}
int countNodesWithTree(IntTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->count;
	}
	return size;
}

void destroyNode(IntNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}
void postOrder(IntNode *aNode)
{
	if(NULL != aNode)
	{
		postOrder(aNode->leftChild);
		postOrder(aNode->rightChild);
		printf("%d ",aNode->value);
	}
}

IntNode *createIntNodeWithValue(int aValue)
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
IntNode* find_endTree(IntNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

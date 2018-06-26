#include"dk_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include"dk_tree.h"
#include "menu.h"
DoubleTree *createDoubleTree()
{
	DoubleTree *theTree = (DoubleTree *)malloc(sizeof(DoubleTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyDoubleTree(DoubleTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertDoubleValueToTree(DoubleTree *aTree, double aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	DoubleNode *theNode = createDoubleNodeWithValue(aValue);
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

DoubleNode *findNodeWithValue(DoubleTree *aTree, double aValue)
{
    int i = 0;
    DoubleNode *theCurrentNode=NULL;
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
		printf("\nNode with %f value ISN'T in aTree\n", aValue);
	}
	else
	{
		printf("\nNode with %f value realy is in aTree\n", aValue);

	}
	return theCurrentNode;
}

DoubleNode* deleteNodeWithDoubleValue(DoubleTree *aTree, DoubleNode* aNode, double aValue)
{
    if (aNode == NULL)
    {
        return NULL;
    }
    else if (aValue < aNode->value)
        aNode->leftChild = deleteNodeWithDoubleValue(aTree, aNode->leftChild, aValue);
    else if (aValue > aNode->value)
        aNode->rightChild = deleteNodeWithDoubleValue(aTree , aNode->rightChild, aValue);
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
            aNode->rightChild = deleteNodeWithDoubleValue(aTree, aNode->rightChild,theTmp->value);
            aTree->count--;
        }
    }
    return aNode;
}

void printTree(DoubleTree *aTree)
{
    printf("\n");
		postOrder(aTree->root);
}
int countNodesWithTree(DoubleTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->count;
	}
	return size;
}

void destroyNode(DoubleNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}
void postOrder(DoubleNode *aNode)
{
	if(NULL != aNode)
	{
		postOrder(aNode->leftChild);
		postOrder(aNode->rightChild);
		printf("%1f ",aNode->value);
	}
}

DoubleNode *createDoubleNodeWithValue(double aValue)
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
DoubleNode* find_endTree(DoubleNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

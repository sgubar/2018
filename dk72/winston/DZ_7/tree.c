#include <stdio.h>
#include <stdlib.h>
#include "tree.h"


CharNode *create_CharNodeWithValue(char aValue)
{
		CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));

if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

void insert_CharNodeToTree(CharTree *aTree, char aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	CharNode *theNode = create_CharNodeWithValue(aValue);
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
		CharNode *theCurrent = aTree->root;
		CharNode *theParent = NULL;

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

CharNode *find_NodeWithCharValue(CharTree *aTree, char aValue)
{
	CharNode *theCurrentNode = NULL;

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
		printf("\nNode with %c value ISN'T in aTree\n", aValue);
	}
	else
	{
		printf("\nNode with %c value realy is in aTree\n", aValue);

	}

	return theCurrentNode;
}

CharNode* find_endTree(CharNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

CharNode* delete_NodeWithCharValue(CharTree *aTree, CharNode* aNode, char aValue)
{
    if (aNode == NULL)
    {
        return NULL;
    }
    else if (aValue < aNode->value)
        aNode->leftChild = delete_NodeWithCharValue(aTree, aNode->leftChild, aValue);
    else if (aValue > aNode->value)
        aNode->rightChild = delete_NodeWithCharValue(aTree , aNode->rightChild, aValue);
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
            CharNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aTree->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            CharNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aTree->count--;
        }
        else
        {
            CharNode *theTmp = find_endTree(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = delete_NodeWithCharValue(aTree, aNode->rightChild,theTmp->value);
            aTree->count--;
        }
    }
    return aNode;
}

void print_Node(CharNode *aNode)
{
	if(NULL != aNode)
	{
		printf("%c ",aNode->value);
		print_Node(aNode->leftChild);
		print_Node(aNode->rightChild);
	}
}

void destroy_Node(CharNode *aNode)
{
	if (aNode != NULL)
	{
		free (aNode);
	}
}

/*-----------------------*/

CharTree *create_CharTree()
{
	CharTree *theTree = (CharTree *)malloc(sizeof(CharTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void print_Tree(CharTree *aTree)
{
    printf("\n");
    print_Node(aTree->root);
}

int count_NodesInTree(CharTree *aTree)
{
	int size = 0;
	if (aTree != NULL)
	{
		size = aTree->count;
	}
	return size;
}

void destroy_CharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		destroy_Node(aTree->root);
		free(aTree);
	}
}

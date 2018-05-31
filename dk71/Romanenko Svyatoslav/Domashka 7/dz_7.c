#include "dz_7.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

static void destroyNode(IntNode *aNode);
static IntNode *createIntNodeWithValue(float aValue);

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
    IntNode *theCurrentNode = NULL;
    if (NULL != aTree)
    {
        IntNode *theCurrentNode = aTree->root;
        while (aValue != theCurrentNode->value)
        {
            if(aValue < theCurrentNode->value){
            	theCurrentNode = theCurrentNode->leftChild;
			} else {
				theCurrentNode = theCurrentNode->rightChild;
			}
            if (NULL == theCurrentNode)
            {
                break;
            }
            
        }
        return theCurrentNode;
    }
    return theCurrentNode;
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

void directOrder(IntNode *aNode)
{
    if(aNode != NULL)
    {
    	printf("%f ",aNode ->value);
        directOrder(aNode ->leftChild);
        directOrder(aNode -> rightChild);
		
    }
}
void printTree (IntTree *aTree)
{
	
    IntNode *theCurrentNode = aTree->root;
    if(aTree != NULL)
    {
        directOrder(theCurrentNode);
    }
}

IntNode* FindMin(IntNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

IntNode* deleteNodeWithElement(IntTree *aDrevo,IntNode* aNode, int aElement)
{
    if (aNode == NULL) {
        return NULL;
    }
    else if (aElement < aNode->value)
        aNode->leftChild = deleteNodeWithElement(aDrevo,aNode->leftChild, aElement);
    else if (aElement > aNode->value)
        aNode->rightChild = deleteNodeWithElement(aDrevo , aNode->rightChild, aElement);
    else
    {
        if (aNode->leftChild == NULL && aNode->rightChild == NULL)
        {
            free(aNode);
            aNode = NULL;
            aDrevo->count--;
        }
        else if (aNode->leftChild == NULL)
        {
            IntNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aDrevo->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            IntNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aDrevo->count--;
        }
        else
        {
            IntNode *theTmp = FindMin(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->value);
            aDrevo->count--;
        }
    }
    return aNode;
}

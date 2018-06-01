
#include "Binare_tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

static void destroyNode(FloatNode *aNode);
static FloatNode *createFloatNodeWithValue(float aValue);

FloatTree *createFloatTree()
{
    FloatTree *theTree = (FloatTree *)malloc(sizeof(FloatTree));

    if (NULL != theTree)
    {
        theTree->root = NULL;
        theTree->count = 0;
    }
    return theTree;
}

void destroyFloatTree(FloatTree *aTree)
{
    if (NULL != aTree)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

void insertFloatValueToTree(FloatTree *aTree, float aValue)
{
    if (NULL == aTree)
    {
        return;
    }

    FloatNode *theNode = createFloatNodeWithValue(aValue);
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
        FloatNode *theCurrent = aTree->root;
        FloatNode *theParent = NULL;

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

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{
    FloatNode *theCurrentNode = NULL;
    if (NULL != aTree)
    {
        FloatNode *theCurrentNode = aTree->root;
        while (aValue != theCurrentNode->value)
        {
            theCurrentNode = (aValue < theCurrentNode->value)
                             ? theCurrentNode->leftChild
                             : theCurrentNode->rightChild;
            if (NULL == theCurrentNode)
            {
                break;
            }
        }
        return theCurrentNode;
    }
    return theCurrentNode;
}


void destroyNode(FloatNode *aNode)
{
    if (NULL != aNode)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);

        free(aNode);
    }
}

FloatNode *createFloatNodeWithValue(float aValue)
{
    FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));

    if (NULL != theNode)
    {
        theNode->leftChild = NULL;
        theNode->rightChild = NULL;
        theNode->value = aValue;
    }
    return theNode;
}

void Order(FloatNode *aNode)
{
    if(aNode != NULL)
    {
        Order(aNode ->leftChild);
        printf("%lf ",aNode ->value);
        Order(aNode -> rightChild);

    }
}
void printTree (FloatTree *aTree)
{
    FloatNode *theCurrentNode = aTree->root;
    if(aTree != NULL)
    {
        Order(theCurrentNode);
    }
}

FloatNode* FindMin(FloatNode* aNode)
{
    while (aNode->leftChild != NULL) aNode = aNode->leftChild;
    return aNode;
}

FloatNode* deleteNodeWithElement(FloatTree *aDrevo,FloatNode* aNode, float aElement)
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
            FloatNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aDrevo->count--;
        }
        else if (aNode->rightChild == NULL)
        {
            FloatNode *theTmp = aNode;
            aNode = aNode->leftChild;
            free(theTmp);
            aDrevo->count--;
        }
        else
        {
            FloatNode *theTmp = FindMin(aNode->rightChild);
            aNode->value = theTmp->value;
            aNode->rightChild = deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->value);
            aDrevo->count--;
        }
    }
    return aNode;
}

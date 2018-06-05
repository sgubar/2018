//
// Created by Ihor on 30.05.2018.
//

#include "tools.h"

static void deleteNode(intNode *aNode);
static intNode *createNodeWithIntValue(int value);

intTree *createIntTree()
{
    intTree *newTree = (intTree*)malloc(sizeof(intTree));

    if(newTree != NULL)
    {
        newTree->root = NULL;
        newTree->count = 0;
    }

    return newTree;
}

void deleteIntTree(intTree *aTree)
{
    deleteNode(aTree->root);
    free(aTree);
}

static void deleteNode(intNode *aNode)
{
    if (NULL != aNode)
    {
        deleteNode(aNode->leftChild);
        deleteNode(aNode->rightChild);

        free(aNode);
    }
}

static intNode *createNodeWithIntValue(int value)
{
    intNode *newNode = (intNode*)malloc(sizeof(intNode));

    if(NULL != newNode)
    {
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->value = value;
    }

    return newNode;
}

void insertIntValueToTree(intTree *aTree, int aValue)
{
    if (NULL == aTree)
    {
        return;
    }

    intNode *theNode = createNodeWithIntValue(aValue);
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
        intNode *theCurrent = aTree->root;
        intNode *theParent = NULL;

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



intNode *searchNodeWithValue(intTree *aTree, int aValue)
{
    intNode *theCurrentNode = NULL;

    if (NULL != aTree)
    {
        theCurrentNode = aTree->root; //<! - start from root
        while (aValue != theCurrentNode->value) //<! - walk through the tree
        {
            theCurrentNode = (aValue < theCurrentNode->value)
                             ? theCurrentNode->leftChild
                             : theCurrentNode->rightChild;

            if (NULL == theCurrentNode)
            {
                break;
            }
        }
    }

    return theCurrentNode;
}

intNode *getRecipient(intTree *aTree, intNode *aDelNode)
{
    intNode *theRecipientParent = aDelNode;
    intNode *theRecipient = aDelNode;
    intNode *theCurrent = aDelNode->rightChild; //<! - at first go to right child while left children are present

    while (NULL != theCurrent)
    {
        theRecipientParent = theRecipient;
        theRecipient = theCurrent;
        theCurrent = theCurrent->leftChild;
    }

    if (theRecipient != aDelNode->rightChild)
    {
        theRecipientParent->leftChild = theRecipient->rightChild;
        theRecipient->rightChild = aDelNode->rightChild;
    }

    return theRecipient;
}

int deleteValueFromTree(intTree *aTree, int aValue)
{
    int theResult = 1;

    //1. Find assumed node to delete
    intNode * theCurrent = aTree->root;
    intNode * theParent = aTree->root;

    int isLeftChild = 1;
    
    while (aValue != theCurrent->value)
    {
        theParent = theCurrent;
        if (aValue < theCurrent->value)
        {
            isLeftChild = 1; //<!- go to the left
            theCurrent = theCurrent->leftChild;
        }
        else
        {
            isLeftChild = 0; //<!- right node
            theCurrent = theCurrent->rightChild;
        }

        if (NULL == theCurrent)
        {
            // the node is node found
            return 0;
        }
    }

    //if the node does not have children then just remove it
    if (NULL == theCurrent->leftChild && NULL == theCurrent->rightChild)
    {
        if (aTree->root == theCurrent)
        {
            aTree->root = NULL;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = NULL;
        }
        else
        {
            theParent->rightChild = NULL;
        }
    }
    else if (NULL == theCurrent->rightChild)
    {
        if (aTree->root == theCurrent)
        {
            aTree->root = theCurrent->leftChild;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theCurrent->leftChild;
        }
        else
        {
            theParent->rightChild = theCurrent->leftChild;
        }
    }
    else if (NULL == theCurrent->leftChild)
    {
        if (aTree->root == theCurrent)
        {
            aTree->root = theCurrent->rightChild;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theCurrent->rightChild;
        }
        else
        {
            theParent->rightChild = theCurrent->rightChild;
        }
    }
    else
    {
        intNode * theRecipient = getRecipient(aTree, theCurrent);
        if (aTree->root == theRecipient)
        {
            aTree->root = NULL;
        }
        else if (isLeftChild)
        {
            theParent->leftChild = theRecipient;
        }
        else
        {
            theParent->rightChild = theRecipient;
        }

    }

    free(theCurrent);
    theResult = 1;

    return theResult;
}

void printTree(intNode *aRoot)
{
    if(NULL == aRoot)
    {
        return;
    }

    printf("%d " , aRoot->value);


    printTree(aRoot->leftChild);
    printTree(aRoot->rightChild);


}

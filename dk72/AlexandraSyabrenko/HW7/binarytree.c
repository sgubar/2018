#include "binarytree.h"
#include <stdio.h>
#include <stdlib.h>

static void deleteNode(Node *aNode);
static Node *createNodeWithFloatValue(float value);

Tree *createTree()
{
    Tree *newTree = (Tree*)malloc(sizeof(Tree));
    
    if(newTree != NULL)
    {
        newTree->root = NULL;
        newTree->count = 0;
    }
    
    return newTree;
}

void deleteTree(Tree *aTree)
{
    deleteNode(aTree->root);
    free(aTree);
}

static void deleteNode(Node *aNode)
{
    if (aNode != NULL)
    {
        deleteNode(aNode->leftChild);
        deleteNode(aNode->rightChild);
        free(aNode);
    }
}

static Node *createNodeWithFloatValue(float value)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if(newNode != NULL)
    {
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->value = value;
    }
    
    return newNode;
}

void insertFloatValueToTree(Tree *aTree, float aValue)
{
    if (aTree == NULL)
    {
        return;
    }
    
    Node *theNode = createNodeWithFloatValue(aValue);
    if (theNode == NULL)
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
        Node *aCurrent = aTree->root;
        Node *aParent = NULL;
        
        while (1)
        {
            aParent = aCurrent;
            
            if (aValue < aCurrent->value)
            {
                aCurrent = aCurrent->leftChild;
                if (aCurrent == NULL)
                {
                    aParent->leftChild = theNode;
                    break;
                }
            }
            else
            {
                aCurrent = aCurrent->rightChild;
                if (aCurrent == NULL)
                {
                    aParent->rightChild = theNode;
                    break;
                }
            }
        }
        
        aTree->count ++;
    }
}



Node *searchNodeWithValue(Tree *aTree, float aValue)
{
    Node *aCurrentNode = NULL;
    
    if (aTree != NULL)
    {
        aCurrentNode = aTree->root;
        while (aValue != aCurrentNode->value)
        {
            if (aValue < aCurrentNode->value)
            {
                aCurrentNode=aCurrentNode->leftChild;
            }
            else
            {
                aCurrentNode=aCurrentNode->rightChild;
            }
            
            if (aCurrentNode == NULL)
            {
                break;
            }
        }
    }
    return aCurrentNode;
}
Node *getRecipient(Tree *aTree, Node *aDelNode)
{
    Node *aRecipientParent = aDelNode;
    Node *aRecipient = aDelNode;
    Node *aCurrent = aDelNode->rightChild;
    
    while (aCurrent != NULL)
    {
        aRecipientParent = aRecipient;
        aRecipient = aCurrent;
        aCurrent = aCurrent->leftChild;
    }
    
    if (aRecipient != aDelNode->rightChild)
    {
        aRecipientParent->leftChild = aRecipient->rightChild;
        aRecipient->rightChild = aDelNode->rightChild;
    }
    
    return aRecipient;
}

int deleteValueFromTree(Tree *aTree, float aValue)
{
    int theResult = 1;
    
    Node * aCurrent = aTree->root;
    Node * aParent = aTree->root;
    
    int isLeftChild = 1;
    
    while (aValue != aCurrent->value)
    {
        aParent = aCurrent;
        if (aValue < aCurrent->value)
        {
            isLeftChild = 1; //
            aCurrent = aCurrent->leftChild;
        }
        else
        {
            isLeftChild = 0; //
            aCurrent = aCurrent->rightChild;
        }
        
        if (aCurrent == NULL)
        {
            return 0;
        }
    }
    
    if (NULL == aCurrent->leftChild && NULL == aCurrent->rightChild)
    {
        if (aTree->root == aCurrent)
        {
            aTree->root = NULL;
        }
        else if (isLeftChild)
        {
            aParent->leftChild = NULL;
        }
        else
        {
            aParent->rightChild = NULL;
        }
    }
    else if (NULL == aCurrent->rightChild)
    {
        if (aTree->root == aCurrent)
        {
            aTree->root = aCurrent->leftChild;
        }
        else if (isLeftChild)
        {
            aParent->leftChild = aCurrent->leftChild;
        }
        else
        {
            aParent->rightChild = aCurrent->leftChild;
        }
    }
    else if (NULL == aCurrent->leftChild)
    {
        if (aTree->root == aCurrent)
        {
            aTree->root = aCurrent->rightChild;
        }
        else if (isLeftChild)
        {
            aParent->leftChild = aCurrent->rightChild;
        }
        else
        {
            aParent->rightChild = aCurrent->rightChild;
        }
    }
    else
    {
        Node * aRecipient = getRecipient(aTree, aCurrent);
        if (aTree->root == aRecipient)
        {
            aTree->root = NULL;
        }
        else if (isLeftChild)
        {
            aParent->leftChild = aRecipient;
        }
        else
        {
            aParent->rightChild = aRecipient;
        }
        
    }
    
    free(aCurrent);
    theResult = 1;
    
    return theResult;
}

void printTree(Node *aRoot)
{
    if(aRoot == NULL)
    {
        return;
    }
    
    printf("%.3f\n", aRoot->value);
    
    
    printTree(aRoot->leftChild);
    printTree(aRoot->rightChild);
    
    
}

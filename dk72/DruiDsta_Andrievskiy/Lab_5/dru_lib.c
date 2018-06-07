#include "dru_lib.h"


intTree *createIntTree()
{
    intTree *theTree=(intTree *)malloc(sizeof(intTree));

    if (NULL != theTree)
    {
        theTree->root=NULL;
        theTree->count=0;
    }
    return theTree;
}

void destroyIntTree(intTree *aTree)
{
    if (NULL!=aTree)
    {
        destroyNode(aTree->root);
        free(aTree);
    }
}

void insertIntValueToTree(intTree *aTree, int aValue)
{
    if (NULL==aTree)
    {
        return;
    }

    intNode *theNode=createIntNodeWithValue(aValue);
    if (NULL==theNode)
    {
        return;
    }

    if (NULL==aTree->root)
    {
        aTree->root=theNode;
        aTree->count++;
    }
    else
    {
        intNode *theCurrent=aTree->root;
        intNode *theParent=NULL;

        while (1)
        {
            theParent=theCurrent;

            if (aValue<theCurrent->value)
            {
                theCurrent=theCurrent->leftChild;
                if (NULL==theCurrent)
                {
                    theParent->leftChild=theNode;
                    break;
                }
            }
            else
            {
                theCurrent=theCurrent->rightChild;
                if (NULL==theCurrent)
                {
                    theParent->rightChild=theNode;
                    break;
                }
            }
        }
        aTree->count++;
    }
    return;
}


void destroyNode(intNode *aNode)
{
    if (NULL!=aNode)
    {
        destroyNode(aNode->leftChild);
        destroyNode(aNode->rightChild);

        free(aNode);
    }
}

intNode *createIntNodeWithValue(int aValue)
{
    intNode *theNode=(intNode *)malloc(sizeof(intNode));

    if (NULL != theNode)
    {
        theNode->leftChild=NULL;
        theNode->rightChild=NULL;
        theNode->value=aValue;
    }
    return theNode;
}

void Symmetry(intNode *aNode)
{
    if(aNode != NULL)
    {
        if(aNode->leftChild!=NULL)	Symmetry(aNode->leftChild);
        printf("%d\t",aNode->value);
        if(aNode->rightChild!=NULL)	Symmetry(aNode->rightChild);
    }
    return;
}
void printTree (intTree *aTree)
{
    intNode *theCurrentNode=aTree->root;
    if(aTree!=NULL)
    {
        Symmetry(theCurrentNode);
    }
    return;
}

intNode* FindMin(intNode* aNode)
{
    while (aNode->leftChild!=NULL) aNode=aNode->leftChild;
    return aNode;
}

intNode* deleteNodeWithElement(intTree *aDrevo, intNode* aNode, int aElement)
{
    if (aNode==NULL) 
	{
        return NULL;
    }
    else if (aElement<aNode->value)	aNode->leftChild=deleteNodeWithElement(aDrevo,aNode->leftChild, aElement);
    else if (aElement>aNode->value)	aNode->rightChild=deleteNodeWithElement(aDrevo , aNode->rightChild, aElement);
    else
    {
        if (aNode->leftChild == NULL && aNode->rightChild == NULL)
        {
            free(aNode);
            aNode=NULL;
            aDrevo->count--;
        }
        else if (aNode->leftChild == NULL)
        {
            intNode *theTmp = aNode;
            aNode = aNode->rightChild;
            free(theTmp);
            aDrevo->count--;
        }
        else if (aNode->rightChild==NULL)
        {
            intNode *theTmp=aNode;
            aNode=aNode->leftChild;
            free(theTmp);
            aDrevo->count--;
        }
        else
        {
            intNode *theTmp=FindMin(aNode->rightChild);
            aNode->value=theTmp->value;
            aNode->rightChild=deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->value);
            aDrevo->count--;
        }
    }
    return aNode;
}

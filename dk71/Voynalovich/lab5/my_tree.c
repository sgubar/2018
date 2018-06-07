#include "my_tree.h"

#include <stdio.h>

#include <stdlib.h>

#include <stdlib.h>





Tree *createTree()

{

    Tree *theTree = (Tree *)malloc(sizeof(Tree));



    if (NULL != theTree)

    {

        theTree->root = NULL;

        theTree->count = 0;

    }

    return theTree;

}



void deleteTree(Tree *aTree)

{

    if (NULL != aTree)

    {

        destroyNode(aTree->root);

        free(aTree);

    }

}



void insertValueToTree(Tree *aTree, int aValue)

{

    if (NULL == aTree)

    {

        return;

    }



    Node *theNode = createNodeWithValue(aValue);

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

        Node *theCurrent = aTree->root;

        Node *theParent = NULL;



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



Node *findNodeWithValue(Tree *aTree, int aValue)

{

    Node *theCurrentNode = NULL;

    if (NULL != aTree)

    {

        Node *theCurrentNode = aTree->root;

        while (aValue != theCurrentNode->value)

        {

            theCurrentNode = (aValue < theCurrentNode->value)

                             ? theCurrentNode->leftChild

                             : theCurrentNode->rightChild;

            if (NULL == theCurrentNode) break;

        }

        return theCurrentNode;

    }

    return theCurrentNode;

}





void destroyNode(Node *aNode)

{

    if (NULL != aNode)

    {

        destroyNode(aNode->leftChild);

        destroyNode(aNode->rightChild);



        free(aNode);

    }

}



Node *createNodeWithValue(int aValue)

{

    Node *theNode = (Node *)malloc(sizeof(Node));



    if (NULL != theNode)

    {

        theNode->leftChild = NULL;

        theNode->rightChild = NULL;

        theNode->value = aValue;

    }

    return theNode;

}



void postOrder(Node *aNode)

{

    if(aNode != NULL)

    {

        postOrder(aNode ->leftChild);

        postOrder(aNode -> rightChild);

        printf("%c ",aNode ->value);



    }

}



void printTree (Tree *aTree)

{

    Node *theCurrentNode = aTree->root;

    if(aTree != NULL)

    {

        postOrder(theCurrentNode);

    }

}



Node* FindMin(Node* aNode)

{

    while (aNode->leftChild != NULL) aNode = aNode->leftChild;

    return aNode;

}



Node* deleteNodeWithElement(Tree *aDrevo, Node* aNode, int aElement)

{

    if (aNode == NULL) return NULL;

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

            Node *theTmp = aNode;

            aNode = aNode->rightChild;

            free(theTmp);

            aDrevo->count--;

        }

        else if (aNode->rightChild == NULL)

        {

            Node *theTmp = aNode;

            aNode = aNode->leftChild;

            free(theTmp);

            aDrevo->count--;

        }

        else

        {

            Node *theTmp = FindMin(aNode->rightChild);

            aNode->value = theTmp->value;

            aNode->rightChild = deleteNodeWithElement(aDrevo, aNode->rightChild,theTmp->value);

            aDrevo->count--;

        }

    }

    return aNode;

}


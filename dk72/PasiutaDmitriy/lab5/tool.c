//
// Created by dima on 01.06.18.
//

#include "tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <values.h>

Tree *createTree()
{
    Tree *aTree = (Tree *)malloc(sizeof(Tree));
    if(!aTree)
        exit(1);

    aTree->aSize = 0;
    aTree->root = NULL;
    return aTree;
}

void destroyTree(Tree *aTree)
{
    if(!aTree)
        return;

    if(aTree->root)
        destroyNode(aTree->root);

    free(aTree);
}

Node *createNode(Node *aParent, int aValue)//create every element binary tree
{
    Node *aNode = (Node *)malloc(sizeof(Node));
    if(!aNode)
        exit(2);

    aNode->parent = aParent;// pointer to the previous element,parent is needed in order to remove elements of the tree selectively
    aNode->left = NULL;
    aNode->right = NULL;
    aNode->value = aValue;

    return aNode;
}

void destroyNode(Node *aNode)//delete nodu,we can delete only left or right nodu
{
    if(aNode)
    {
        destroyNode(aNode->left);
        destroyNode(aNode->right);
        free(aNode);
    }
}

void insertElementInTree(Tree *aTree, int aValue)
{
    if(!aTree->root)
    {
        Node *aNode = createNode(aTree->root, aValue);
        if(!aNode)
            return;

        aTree->root = aNode;
        aTree->aSize++;
    }
    else
    {
        Node *first = aTree->root;
        Node *second = NULL;

        while(true)
        {
            second = first;

            if(aValue == first->value)
            {
                printf("\n \n"
                               "this element has already been added\n");
                break;
            }

            if(aValue < first->value)
            {
                first = first->left;
                if(!first)
                {
                    Node *aNode = createNode(second, aValue);
                    second->left = aNode;
                    aTree->aSize++;
                    break;
                }
            }

            else
            {
                first = first->right;
                if(!first)
                {
                    Node *aNode = createNode(second, aValue);
                    second->right = aNode;
                    aTree->aSize++;
                    break;
                }
            }
        }
    }
}

void postorderPrint(Node *aNode)
{
    if(!aNode)
        return;

    postorderPrint(aNode->left);
    postorderPrint(aNode->right);
    printf("%i ", aNode->value);
}

void deleteElementInTree(Tree *aTree, Node *aNode)//sent element which need a delete,3 variants: when element last and ne ssilaentsya ni na kogo,when we have left and right element we take max value from left and delete
{
    if(aNode->left && aNode->right)
    {
        Node *max = maxValue(aNode->left);
        aNode->value = max->value;
        deleteElementInTree(aTree, max);
        return;
    }

    else if(aNode->parent)//when we have pointer to myself,=>higher somebody is,we have if is left element ,if after element 1 element left,to pereprisvoenie left side,s prava tak zhe right side same
    {
        if(aNode->left)
        {
            if(aNode == aNode->parent->left)
                aNode->parent->left = aNode->left;
            else
                aNode->parent->right = aNode->left;
        }

        else if(aNode->right)
        {
            if(aNode == aNode->parent->right)
                aNode->parent->right = aNode->right;
            else
                aNode->parent->left = aNode->right;
        }

        else
        {
            if(aNode == aNode->parent->left)
                aNode->parent->left = NULL;
            else
                aNode->parent->right = NULL;
        }
    }

    else if(aTree->root == aNode)
    {
        if(aNode->left)
        {
            Node *tmp1 = maxValue(aNode->left);
            aTree->root->value = tmp1->value;
            deleteElementInTree(aTree, tmp1);
            return;
        }

        else if(aNode->right)
        {
            Node *tmp2 = minValue(aNode->right);
            aTree->root->value = tmp2->value;
            deleteElementInTree(aTree, tmp2);
            return;
        }

        else
        {
            aTree->root = NULL;//when need delete kornevoy element
        }
    }

    free(aNode);
    aTree->aSize--;
}

Node *minValue(Node *aNode) //
go to the very last element
{
    while(aNode->left)
        aNode = aNode->left;

    return aNode;
}

Node *maxValue(Node *aNode)
{
    while(aNode->right)
        aNode = aNode->right;

    return aNode;
}

Node *searchByValue(Node *aNode, int aValue)
{
    if(!aNode)
        return NULL;

    else if(aValue < aNode->value) //value is less than in the node, then continue the search from the left side, if more then right
        return searchByValue(aNode->left, aValue);

    else if(aValue > aNode->value)
        return searchByValue(aNode->right, aValue);

    else//kogda znachenie ravno
        return aNode;
}

void deleteElementInTreeByValue(Tree *aTree)
{
    printf("enter the value of the element to delete ");
    int aValue = checkInput();
    Node *toDelete = searchByValue(aTree->root, aValue);

    if(toDelete)
        deleteElementInTree(aTree, toDelete);

    else
    {
        printf("ERROR!\n");
        return;
    }
}

int checkInput()
{
    while(true)
    {
        char *line = (char *)malloc(sizeof(char) * 20);
        fflush(stdin);
        fgets(line, 20, stdin);
        fflush(stdin);

        if(!line)
            goto pointer;

        int d;
        char c;

        if((sscanf(line, "%i %c", &d, &c) == 1) && d < INT_MAX)/ check string on right input
        {
            free(line);
            return d;
        }

        pointer:
        free(line);
        printf("repeat ");
    }
}

void addElement(Tree *aTree)
{
    printf("enter the value of the element ");
    int aValue = checkInput();
    insertElementInTree(aTree, aValue);
}

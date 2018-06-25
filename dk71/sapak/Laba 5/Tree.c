#include "Tree.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>








Node* CreateNode(double value, Node *parent)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}


void insert(Node **head, double value)
{   
    Node *tmp = NULL;
    Node *ins = NULL;
    if (*head == NULL) {
        *head = CreateNode(value, NULL);
        return;
    }
        tmp = *head;

    while (tmp) {
        if (value>tmp->data) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = CreateNode(value, tmp);
                return;
            }
        } else if (value < tmp->data) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = CreateNode(value,tmp);
                return;
            }
        } else {
            exit(2);
        }
    }
}


Node *getNodeByValue(Node *root, double value)
{

    while (root) {
        if (value > root->data) {
            root = root->left;
            continue;
        } else if (value < root->data) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}







Node* getMinNode(Node *root)
{
    while (root->left)
	{
        root = root->left;
    }
    return root;
}



Node* getMaxNode(Node *root)
{
    while (root->right)
	{
        root = root->right;
    }
    return root;
}


void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%f ", root->data);
        inOrderTravers(root->right);
    }
}

void deleteTree(Node **root)
{
    if (*root) {
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
    }
}











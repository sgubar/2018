#include "Tree.h"

Node* CreateNode(int value, Node *parent)
{
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->a = value;
    tmp->parent = parent;
    return tmp;
}

void insert(Node **head, int value)
{   
    Node *tmp = NULL;
    if (*head == NULL) {
        *head = CreateNode(value, NULL);
        return;
    }
        tmp = *head;
        
    while (tmp != NULL) {
        if (value>tmp->a) {
            if (tmp->right) {
                tmp = tmp->right;
                continue;
            } else {
                tmp->right = CreateNode(value, tmp);
                return;
            }
        } else if (value < tmp->a) {
            if (tmp->left) {
                tmp = tmp->left;
                continue;
            } else {
                tmp->left = CreateNode(value,tmp);
                return;
            }
        } else {
            exit(1);
        }
    }
}

void DirectBypass(Node* root) {
    if (root) {
        printf("%d\n", root->a);
        DirectBypass(root->left);
        DirectBypass(root->right);
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



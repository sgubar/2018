#include "My_Tree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>




Node* CreateNode(char *value, Node *parent)

{

    Node* tmp = (Node*) malloc(sizeof(Node));

    tmp->left = tmp->right = NULL;

    tmp->data = value;

    tmp->parent = parent;

    return tmp;

}





void insert(Node **head, char *value)

{   char *buff;

    Node *tmp = NULL;
    Node *ins = NULL;

    if (*head == NULL) {

        *head = CreateNode(value, NULL);

        return;

    }

        tmp = *head;



    while (tmp) {

        if (charcmp(value,tmp->data)>0) {

            if (tmp->right) {

                tmp = tmp->right;

                continue;

            } else {

                tmp->right = CreateNode(value, tmp);

                return;

            }

        } else if ((charcmp(value,tmp->data))<0) {

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





Node *getNodeByValue(Node *root, char *value)

{



    while (root) {

        if ((charcmp(root->data,value))>0) {

            root = root->left;

            continue;

        } else if ((charcmp(root->data,value))<0) {

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



void inOrder(Node* root)

{

    if (root) {

        inOrder(root->left);

        printf("%c \n", root->data);

        inOrder(root->right);

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







int charcmp (char *a, char *b){



int x = a;

int y = b;

if(y>x){

   return -1;



}

if(x>y){



    return 1;

}



return 0;

	

}









   











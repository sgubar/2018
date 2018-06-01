#include "func.h"
#include <stdio.h>
#include <stdlib.h>

#define CMP_EQ(a, b) ((a) == (b))
#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))



Node* getFreeNode(int *value, Node *parent) 
	{
	    Node* tmp = (Node*) malloc(sizeof(Node));
	    tmp->left = tmp->right = NULL;
	    tmp->data = value;
	    tmp->parent = parent;
	    return tmp;
	}
	
void insert(Node **head, int value) 
	{
	    Node *tmp = NULL;
	    Node *ins = NULL;
	    if (*head == NULL) {
	        *head = getFreeNode(value, NULL);
	        return;
	    }
	     
	    tmp = *head;
	    while (tmp) {
	        if (CMP_GT(value, tmp->data)) {
	            if (tmp->right) {
	                tmp = tmp->right;
	                continue;
	            } else {
	                tmp->right = getFreeNode(value, tmp);
	                return;
	            }
	        } else if (CMP_LT(value, tmp->data)) {
	            if (tmp->left) {
	                tmp = tmp->left;
	                continue;
	            } else {
	                tmp->left = getFreeNode(value, tmp);
	                return;
	            }
	        } else {
	            exit(2);
	        }
	    }
	}
	
void printTree(Node *root, const char *dir, int level) 
	{
	    if (root) {
	        printf("lvl %d %s = %d\n", level, dir, root->data);
	        printTree(root->left, "left", level+1);
	        printTree(root->right, "right", level+1);
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
	
void removeNodeByPtr(Node *target)
	 {
	    if (target->left && target->right) {
	        Node *localMax = findMaxNode(target->left);
	        target->data = localMax->data;
	        removeNodeByPtr(localMax);
	        return;
	    } else if (target->left) {
	        if (target == target->parent->left) {
	            target->parent->left = target->left;
	        } else {
	            target->parent->right = target->left;
	        }
	    } else if (target->right) {
	        if (target == target->parent->right) {
	            target->parent->right = target->right;
	        } else {
	            target->parent->left = target->right;
	        }
	    } else {
	        if (target == target->parent->left) {
	            target->parent->left = NULL;
	        } else {
	            target->parent->right = NULL;
	        }
	    }
	    free(target);
	}
	

void deleteValue(Node *root, int value)
	{
	    Node *target = getNodeByValue(root, value);
	    removeNodeByPtr(target);
	}


Node* findMinNode(Node *root) 
	{
	    while (root->left) {
	        root = root->left;
	    }
	    return root;
	}
	
Node* findMaxNode(Node *root) 
	{
	    while (root->right) {
	        root = root->right;
	    }
	    return root;
	}

	
Node *getNodeByValue(Node *root, int value) 
	{
	    while (root) {
	        if (CMP_GT(root->data, value)) {
	            root = root->left;
	            continue;
	            printf("+");
	        } else if (CMP_LT(root->data, value)) {
	            root = root->right;
	            continue;
	            printf("+");
	            
	        } else {
	            return root;
	        }
	    }
	    return NULL;
	}




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
    if (*head == NULL) 
	{
        *head = CreateNode(value, NULL);
        return;
    }
        tmp = *head;
        
    while (tmp != NULL) {
        if (value>tmp->a) 
		{
            if (tmp->right) 
			{
                tmp = tmp->right;
                continue;
            } 
			else 
			{
                tmp->right = CreateNode(value, tmp);
                return;
            }
        } 
		else if (value < tmp->a) 
		{
            if (tmp->left) 
			{
                tmp = tmp->left;
                continue;
            } 
			else 
			{
                tmp->left = CreateNode(value,tmp);
                return;
            }
        } 
		else 
		{
            exit(1);
        }
    }
}

void DirectBypass(Node* root) {
    if (root) 
	{
        printf("%d\n", root->a);
        DirectBypass(root->right);
        DirectBypass(root->left);
    }
}

void deleteTree(Node **root)
{
    if (*root) 
	{
        deleteTree(&((*root)->left));
        deleteTree(&((*root)->right));
        free(*root);
    }
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

Node *getNodeByValue(Node *root,  int value) {
    while (root) {
        if (root->a>value) {
            root = root->left;
            continue;
        } else if (root->a<value) {
            root = root->right;
            continue;
        } else {
            return root;
        }
    }
    return NULL;
}

void removeNodeByPtr(Node *target) {
    if (target->left && target->right) {
        Node *localMax = getMaxNode(target->left);
        target->a = localMax->a;
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
void deleteValue(Node *root, int value) {
    Node *target = getNodeByValue(root, value);
    removeNodeByPtr(target);
}
void printTree(Node *root, const char *dir, int level) {
    if (root) {
        printf("lvl %d %s = %d\n", level, dir, root->a);
        printTree(root->left, "left", level+1);
        printTree(root->right, "right", level+1);
    }
}

#ifndef My_Tree_h

#define My_Tree_h

#include <stdio.h>

#include <string.h>









typedef struct aNode  Node;

struct aNode

{

	char *data;

    Node *left;

    Node *right;

    Node *parent;



} ;



Node* CreateNode(char *value, Node *parent);

void insert(Node **head, char  *value);

Node *getNodeByValue(Node *root, char  *value);

void removeNodeByPtr(Node *target);

void deleteValue(Node *root, char  *value);

Node* getMinNode(Node *root);

Node* getMaxNode(Node *root);

void inOrder(Node* root);

void deleteTree(Node **root);













#endif

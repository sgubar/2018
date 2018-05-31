#ifndef Tree_h
#define Tree_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aNode  Node;
struct aNode
{
	int a;
    Node *left;
    Node *right;
    Node *parent;

} ;

Node* CreateNode(int value, Node *parent);
void insert(Node **head, int value);
void DirectBypass(Node* root);
void deleteTree(Node **root);
#endif

#ifndef Tree_h
#define Tree_h
#include <windows.h>
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
Node* getMaxNode(Node *root);
Node* getMinNode(Node *root);
Node *getNodeByValue(Node *root,  int value);
void removeNodeByPtr(Node *target);
void deleteValue(Node *root, int value);
void printTree(Node *root, const char *dir, int level);
#endif

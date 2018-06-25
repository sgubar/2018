#ifndef Tree_h
#define Tree_h
#include <stdio.h>
#include <string.h>




typedef struct aNode  Node;
struct aNode
{
	double data;
    Node *left;
    Node *right;
    Node *parent;

} ;

Node* CreateNode(double value, Node *parent);
void insert(Node **head, double value);
Node *getNodeByValue(Node *root, double value);
Node* getMinNode(Node *root);
Node* getMaxNode(Node *root);
void inOrderTravers(* root);
void deleteTree(Node **root);







#endif

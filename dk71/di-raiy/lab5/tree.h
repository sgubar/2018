#include <stdio.h>


typedef struct aNode  Node;
struct aNode
{
	double data;
    Node *left;
    Node *right;
    Node *parent;

} ;

int steps (Node *first, int count);
Node* createNode (double ins);
void printTree (Node *first);
Node* createTree (double ins);
void deleteTree (Node *first);
void insElem (Node *first, double IE);
void delElem (Node *first, double DE);
Node* findElem (Node *first, double FE);

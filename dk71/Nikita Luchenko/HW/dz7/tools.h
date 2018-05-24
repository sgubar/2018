#ifndef tools.h
#define tools.h
#include <stdlib.h>
#include <stdio.h>

typedef struct intNode Node;

typedef struct intNode
{
  double value;
  Node *left;
  Node *right;
}Node;

typedef struct intTree
{	
  int size;
  Node *root;
}Tree;

Tree* create_tree();
Node *create_node(double val);
Node *search(Tree *thetree, double val);
void add_node(Tree *thetree, double val);
Node *delete_node(Tree *thetree, double val);
void node_print(Node *thetree);
void tree_print(Tree *thetree);
void node_free(Node *thetree);
void tree_free(Tree *thetree);
#endif

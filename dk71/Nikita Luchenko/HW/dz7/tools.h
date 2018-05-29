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
  Node *root;
}Node;

Node *create_node(Node *root, double val);
Node *search(Node *thetree, double val);
void add_node(Node *thetree, double val);
void delete_node(Node *root, double val);
Node *find_max_min(Node *root, int val);
Node *get_node_by_value(Node *root, double val);
void delete_target(Node *target);
int size(Node* root);
int height(Node* root);
void node_print(Node *thetree);
void tree_print(Node *thetree);
void node_free(Node *thetree);
void tree_free(Node *thetree);
#endif

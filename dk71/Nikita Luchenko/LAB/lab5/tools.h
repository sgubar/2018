#ifndef tools.h
#define tools.h
#include <stdlib.h>
#include <stdio.h>

typedef struct intNode Node;

typedef struct intNode
{
  int value;
  Node *left;
  Node *right;
  Node *root;
}Node;

Node *create_node(Node *root, int *val);
int search(Node *thetree, int val);
void add_node(Node **thetree, int *val);
void delete_node(Node *root, int val);
Node *find_max_min(Node *root, int val);
Node *get_node_by_value(Node *root, int val);
void delete_target(Node *target);
int size(Node* root);
int height(Node* root);
void print_level(Node* root, int level);
void levels_tree_print(Node* thetree);
void tree_print(Node *thetree);
void tree_free(Node *thetree);
#endif

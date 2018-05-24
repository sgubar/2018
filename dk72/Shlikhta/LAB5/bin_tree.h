#ifndef bin_tree_h
#define bin_tree_h

#include "libs.h"

typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}node, *pnode;


typedef struct bin_tree
{
	pnode root;
	int size;
}bin_tree, *pbin_tree;

pbin_tree create_tree();

void add_el(pbin_tree ae_tree, char ae_data);

int find_el(pbin_tree se_tree, char se_data);

void delete_tree(pbin_tree dt_tree);

void print_tree(pnode pt_temp);

int remove_node(pbin_tree search_tree, char item);

#endif
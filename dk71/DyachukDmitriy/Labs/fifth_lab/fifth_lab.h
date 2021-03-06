#ifndef fifth_lab
#define fifth_lab
#include <stdio.h>

typedef struct binary_tree_Node_tag BTNode;
typedef struct binary_tree_Node_tag
{
	float Value;
	BTNode *Left_Child;
	BTNode *Right_Child;
	BTNode *Parent;
}BTNode;

float check_value(void);
BTNode *create_BTree_Node(void);
void add_BTree_Node_with_value(BTNode *Root_Node, float value);
BTNode *find_max_min_values(BTNode *Root_Node, float value);
BTNode *find_value_in_BTree(BTNode *Root_Node, float value);
void delete_BTree_Node(BTNode *Node_for_delete);
void print_BTree(BTNode *Root_Node);
void delete_BTree(BTNode *Root_Node, float *array_of_values, int num_of_elements);

#endif
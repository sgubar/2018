#ifndef fourth_lab
#define fourth_lab
#include <stdio.h>

typedef struct Node_of_int_type int_Node;

typedef struct Node_of_int_type
{
	int value;
	int_Node *previous_Node;
	int_Node *next_Node;
}int_Node;

typedef struct List_of_int_type_Nodes
{
	int_Node *first_Node_of_List;
	int_Node *last_Node_of_List;
	int count_of_Nodes_in_List;
}int_Node_List;

int_Node_List *Create_Circle_int_Node_List_func(void);
int check_value_func(void);
void Add_int_value_to_Circle_List_func(int_Node_List *current_List, int int_value);
int_Node_List *Create_int_Node_with_value_func(int int_value);
int Delete_int_Node_from_Circle_List_by_index_func(int_Node_List *current_List, int current_index);
void Print_int_Node_List_func(int_Node_List *current_List);
void Size_of_int_Node_List_func(int_Node_List *current_List);
void Destroy_Circle_int_Node_List_func(int_Node_List *current_List);

#endif
#ifndef hometask_6
#define hometask_6
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

int check_value_func(void);
int_Node_List *Create_int_Node_with_value_func(int int_value);
int_Node_List *Create_int_Node_List_func(void);
void Destroy_int_Node_List_func(int_Node_List *current_List);
void Add_int_value_to_List_func(int_Node_List *current_List, int int_value);
void Insert_int_value_to_List_by_index_func(int_Node_List *current_List, int income_int_value, int index_for_the_value);
int Delete_int_Node_from_List_by_index_func(int_Node_List *current_List, int current_index);
void Quick_sorting_of_List_func(int_Node_List *current_List, int first, int last);
int partition_List_of_Nodes_func(int_Node_List *current_List, int first, int last);
void swap_Nodes_func(int_Node_List *current_List, int left_index, int right_index);
int_Node *Get_Node_at_index_func(int_Node_List *current_List, int index_of_Node);
void Print_int_Node_List_func(int_Node_List *current_List);
void Size_of_int_Node_List_func(int_Node_List *current_List);

#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "fourth_lab.h"


int_Node_List *Create_Circle_int_Node_List_func(void)
{
	int_Node_List *created_Circle_int_Node_List = (int_Node_List *)malloc(sizeof(int_Node_List));
	if(NULL != created_Circle_int_Node_List)
	{
		created_Circle_int_Node_List->first_Node_of_List = NULL;
		created_Circle_int_Node_List->last_Node_of_List = NULL;
		created_Circle_int_Node_List->count_of_Nodes_in_List = 0;
	}
	return created_Circle_int_Node_List;
}

int check_value_func(void)
{
    fflush(stdin);
    int value;
    int check_result;
     do
    {
        check_result = 0;
        check_result = scanf("%i", &value);
        fflush(stdin);
        if (check_result != 1)
        {
           printf("\n- The value was not defined by integer value.\n\n- Please try again:\n\n- Your value:");
        }
    }while(check_result != 1);
    return value;
}

void Add_int_value_to_Circle_List_func(int_Node_List *current_List, int int_value)
{
	if(NULL != current_List)
	{
		int_Node *new_last_Node = Create_int_Node_with_value_func(int_value);
		if(NULL != new_last_Node)
		{
			if(NULL == current_List->first_Node_of_List && NULL == current_List->last_Node_of_List)
			{
				current_List->first_Node_of_List = current_List->last_Node_of_List = new_last_Node;
			}else
			{
				int_Node *old_last_Node_of_List = current_List->last_Node_of_List;
				current_List->last_Node_of_List = new_last_Node;
				old_last_Node_of_List->next_Node = new_last_Node;
				new_last_Node->previous_Node = old_last_Node_of_List;
				current_List->first_Node_of_List->previous_Node = current_List->last_Node_of_List;
				current_List->last_Node_of_List->next_Node = current_List->first_Node_of_List;
			}
			current_List->count_of_Nodes_in_List++;
		}
	}
}

int_Node_List *Create_int_Node_with_value_func(int int_value)
{
	int_Node *created_Node = (int_Node *)malloc(sizeof(int_Node));
	if(NULL != created_Node)
	{
		created_Node->value = int_value;
		created_Node->previous_Node = NULL;
		created_Node->next_Node = NULL;
	}
	return created_Node;
}

int Delete_int_Node_from_Circle_List_by_index_func(int_Node_List *current_List, int index_for_the_value)
{
	int index_value = 2023;
	if(NULL == current_List)
		return index_value;
	int_Node *the_Node = current_List->first_Node_of_List;
	int counter = 0;
	do
	{
		the_Node = the_Node->next_Node;
		counter++;
	}while(counter != index_for_the_value);
	if(the_Node == current_List->first_Node_of_List)
	{
		current_List->last_Node_of_List->next_Node = the_Node->next_Node;
		current_List->first_Node_of_List = the_Node->next_Node;
		current_List->first_Node_of_List->previous_Node = current_List->last_Node_of_List;
	}else if (the_Node == current_List->last_Node_of_List)
	{
		current_List->first_Node_of_List->previous_Node = the_Node->previous_Node;
		current_List->last_Node_of_List = the_Node->previous_Node;
		current_List->last_Node_of_List->next_Node = current_List->first_Node_of_List;
	}else
	{
		the_Node->next_Node->previous_Node = the_Node->previous_Node;
		the_Node->previous_Node->next_Node = the_Node->next_Node;
	}
	free(the_Node);
	current_List->count_of_Nodes_in_List--;
}

void Print_int_Node_List_func(int_Node_List *current_List)
{
    int counter = 0;
	int_Node *the_Node = current_List->first_Node_of_List;
	printf("- You have next elements in your list: \n\n");
	while(counter != current_List->count_of_Nodes_in_List)
	{
		printf("(%d)\t", the_Node->value);
		the_Node = the_Node->next_Node;
		counter++;
	}
}

void Size_of_int_Node_List_func(int_Node_List *current_List)
{
	printf("\n- In result list you have %d elements.\n\n", current_List->count_of_Nodes_in_List);
}

void Destroy_Circle_int_Node_List_func(int_Node_List *current_List)
{
	if(current_List == NULL)
		return;
	int_Node *the_Node = current_List->first_Node_of_List;
	if(NULL != current_List->last_Node_of_List && NULL != current_List->first_Node_of_List)
	{
		do
		{
			int_Node *delete_Node = the_Node;
			the_Node = the_Node->next_Node;
			free(delete_Node);
			current_List->count_of_Nodes_in_List = 0;
		}while(NULL != the_Node);
		free(current_List);
	}
}
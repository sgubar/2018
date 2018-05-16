#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>
#include "hometask_6.h"

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

int_Node_List *Create_int_Node_List_func(void)
{
	int_Node_List *created_int_Node_List = (int_Node_List *)malloc(sizeof(int_Node_List));
	if(NULL != created_int_Node_List)
	{
		created_int_Node_List->first_Node_of_List = NULL;
		created_int_Node_List->last_Node_of_List = NULL;
		created_int_Node_List->count_of_Nodes_in_List = 0;
	}
	return created_int_Node_List;
}

void Destroy_int_Node_List_func(int_Node_List *current_List)
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

void Add_int_value_to_List_func(int_Node_List *current_List, int int_value)
{
	if(NULL != current_List)
	{
		int_Node *new_Node = Create_int_Node_with_value_func(int_value);
		if(NULL != new_Node)
		{
			if(NULL == current_List->first_Node_of_List && NULL == current_List->last_Node_of_List)
			{
				current_List->first_Node_of_List = current_List->last_Node_of_List = new_Node;
			}else
			{
				int_Node *last_Node_of_List = current_List->last_Node_of_List;
				current_List->last_Node_of_List = new_Node;
				last_Node_of_List->next_Node = new_Node;
				new_Node->previous_Node = last_Node_of_List;
			}
			current_List->count_of_Nodes_in_List++;
		}
	}
}

void Insert_int_value_to_List_by_index_func(int_Node_List *current_List, int income_int_value, int index_for_the_value)
{
	if(NULL == current_List)
		return;
	int_Node *the_new_Node = Create_int_Node_with_value_func(income_int_value);
	if(NULL == the_new_Node)
		return;
	if(index_for_the_value == 0)
	{
		the_new_Node->previous_Node = NULL;
		the_new_Node->next_Node = current_List->first_Node_of_List;
		current_List->first_Node_of_List->previous_Node = the_new_Node;
		current_List->first_Node_of_List = the_new_Node;
	}else if(index_for_the_value == current_List->count_of_Nodes_in_List)
	{
		the_new_Node->next_Node = NULL;
		the_new_Node->previous_Node = current_List->last_Node_of_List;
		current_List->last_Node_of_List->next_Node = the_new_Node;
		current_List->last_Node_of_List = the_new_Node;
	}else
	{
		int_Node *the_Node = current_List->first_Node_of_List;
		int counter = 0;
		do
		{
			if(counter == index_for_the_value)
				break;
			the_Node = the_Node->next_Node;
			++counter;
		}while(NULL != the_Node);
		the_new_Node->next_Node = the_Node;
		the_new_Node->previous_Node = the_Node->previous_Node;
		the_Node->previous_Node = the_new_Node;
		the_new_Node->previous_Node->next_Node = the_new_Node;
	}
	current_List->count_of_Nodes_in_List++;
}

int Delete_int_Node_from_List_by_index_func(int_Node_List *current_List, int index_for_the_value)
{
	int index_value = 2023;
	if(NULL == current_List)
		return index_value;
	if(current_List->count_of_Nodes_in_List == 1 && index_for_the_value == 0)
	{
		Destroy_int_Node_List_func(current_List);
		return index_value;
	}
	if(index_for_the_value == 0)
	{
		int_Node *the_Node = current_List->first_Node_of_List;
		current_List->first_Node_of_List = the_Node->next_Node;
		the_Node->next_Node->previous_Node = NULL;
		free(the_Node);
	}else if(index_for_the_value == current_List->count_of_Nodes_in_List - 1)
	{
		int_Node *the_Node = current_List->last_Node_of_List;
		current_List->last_Node_of_List = the_Node->previous_Node;
		the_Node->previous_Node->next_Node = NULL;
		free(the_Node);
	}else
	{
		int_Node *the_Node = current_List->first_Node_of_List;
		int counter = 0;
		do
		{
			if (counter == index_for_the_value)
			break;
			the_Node = the_Node->next_Node;
			counter++;
		}while(NULL != the_Node);
		the_Node->next_Node->previous_Node = the_Node->previous_Node;
		the_Node->previous_Node->next_Node = the_Node->next_Node;
		free(the_Node);
	}
	current_List->count_of_Nodes_in_List--;
}

void Quick_sorting_of_List_func(int_Node_List *current_List, int first, int last)
{
    int partition_index = 0;
	if (first < last)
	{
		partition_index = partition_List_of_Nodes_func(current_List, first, last);

		Quick_sorting_of_List_func(current_List, first, partition_index - 1);

		Quick_sorting_of_List_func(current_List, partition_index + 1, last);
	}
}

int partition_List_of_Nodes_func(int_Node_List *current_List, int first, int last)
{
    int pivot_value = Get_Node_at_index_func(current_List, last)->value;
	int left = first;
	int right = last + 1;
	while(1)
	{
		do
		{
			left++;
		}while(left < last && Get_Node_at_index_func(current_List, left)->value < pivot_value);

        do
        {
			right++;
        }while(Get_Node_at_index_func(current_List, right)->value > pivot_value);
		if (left >= right)
		{
			break;
		}
		else
        {
            swap_Nodes_func(current_List, left, right);
        }
	}
	swap_Nodes_func(current_List, first, last);
	return right;
}

void swap_Nodes_func(int_Node_List *current_List, int left_index, int right_index)
{
	if (left_index == right_index)
    	return;
	int_Node *left_Node = Get_Node_at_index_func(current_List, left_index);
    int_Node *right_Node = Get_Node_at_index_func(current_List, right_index);
	int value_of_left_Node = left_Node->value;
	left_Node->value = right_Node->value;
	right_Node->value = value_of_left_Node;
}

int_Node *Get_Node_at_index_func(int_Node_List *current_List, int index_of_Node)
{
    int_Node *the_Node = NULL;
	if (NULL != current_List && index_of_Node < current_List->count_of_Nodes_in_List)
	{
		int counter = 0;
		int_Node *the_Node = current_List->first_Node_of_List;
		do
		{
			if (counter == index_of_Node)
			{
				break;
			}
			the_Node = the_Node->next_Node;
			counter++;
		}while(NULL != the_Node);
	}
	return the_Node;
}

void Print_int_Node_List_func(int_Node_List *current_List)
{
	int_Node *the_Node = current_List->first_Node_of_List;
	printf("- You have next elements in your list: \n\n");
	while(NULL != the_Node)
	{
		printf("(%d)\t", the_Node->value);
		the_Node = the_Node->next_Node;
	}
}

void Size_of_int_Node_List_func(int_Node_List *current_List)
{
	printf("\n- In result list you have %d elements.\n\n", current_List->count_of_Nodes_in_List);
}

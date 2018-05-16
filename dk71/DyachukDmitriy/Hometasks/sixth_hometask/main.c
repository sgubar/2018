#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "hometask_6.h"

int main(void)
{
	int current_value = 0;
	int current_index = 0;
	int decision = 1;
	int_Node_List *current_List_of_int_Nodes = Create_int_Node_List_func();
	if(NULL == current_List_of_int_Nodes)
	{
		return 2023;
	}
	printf("- You have to fill current list by values of integer numbers ...\n\n");
	printf("- Please enter the first value for the list: ");
	current_value = check_value_func();
	Add_int_value_to_List_func(current_List_of_int_Nodes, current_value);
	printf("\n- Do you want to add more values to the list?\n\n");
	printf("- Please enter 0 if you want to add more values or you can enter any other key to interrupt entering values ...\n\n- Your decision: ");
	scanf("%i", &decision);
	while(decision == 0)
	{
		printf("\n- Please enter next value for the list: ");
		current_value = check_value_func();
		Add_int_value_to_List_func(current_List_of_int_Nodes, current_value);
		decision = 1;
		printf("\n- Please enter 0 if you want to add more values or you can enter any other key to interrupt entering values ...\n\n- Your decision: ");
		fflush(stdin);
		scanf("%i", &decision);
	}
	Size_of_int_Node_List_func(current_List_of_int_Nodes);
	Print_int_Node_List_func(current_List_of_int_Nodes);
	if(current_List_of_int_Nodes->count_of_Nodes_in_List == 1)
	{
		printf("\n\n- You have only one element to delete ...\n\n- Do you want to delete it?\n\n- Enter '0' if you want to delete it or enter any another integer value to interrupt deleting ...\n\n- Your decision: ");
		fflush(stdin);
		decision = check_value_func();
		if(decision == 0)
		{
			Delete_int_Node_from_List_by_index_func(current_List_of_int_Nodes, 0);
			printf("\n\n- Your list has been fully deleted ...\n\n- The program is closing ...");
			return 0;
		}else
		{
			goto skip;
		}
	}
	printf("\n\n- Please enter the index of the value which you want to delete: ");
    current_index = check_value_func();
	while(current_index > current_List_of_int_Nodes->count_of_Nodes_in_List - 1 || current_index < 0)
	{
		printf("\n\n- Your index is incorrect ...\n\n- Please try again ...\n\n- Your value: ");
		current_index = check_value_func();
	}
	Delete_int_Node_from_List_by_index_func(current_List_of_int_Nodes, 0);
	Size_of_int_Node_List_func(current_List_of_int_Nodes);
	Print_int_Node_List_func(current_List_of_int_Nodes);
	printf("\n\n- Do you want to delete more nodes from the list?\n\n");
	printf("- Please enter 0 if you want to delete more nodes or you can enter any other key to interrupt deleting values ...\n\n- Your decision: ");
	scanf("%i", &decision);
	while(decision == 0)
	{
	    if(current_List_of_int_Nodes->count_of_Nodes_in_List == 1)
        {

            printf("\n\n- You have only one element to delete ...\n\n- Do you want to delete it?\n\n- Enter '0' if you want to delete it or enter any another key to interrupt deleting ...\n\n- Your decision: ");
            fflush(stdin);
            scanf("%i", &decision);
            if(decision == 0)
            {
                Delete_int_Node_from_List_by_index_func(current_List_of_int_Nodes, 0);
                printf("\n\n- Your list has been fully deleted ...\n\n- The program is closing ...");
                return 0;
            }else
            {
                    goto skip;
            }
        }
		printf("\n- Please enter next index of value to delete from the list: ");
		current_index = check_value_func();
		while(current_index > current_List_of_int_Nodes->count_of_Nodes_in_List - 1 || current_index < 0)
        {
            printf("\n\n- Your index is incorrect ...\n\n- Please try again ...\n\n- Your value: ");
            current_index = check_value_func();
        }
        Delete_int_Node_from_List_by_index_func(current_List_of_int_Nodes, 0);
		Size_of_int_Node_List_func(current_List_of_int_Nodes);
		Print_int_Node_List_func(current_List_of_int_Nodes);
		decision = 1;
		printf("\n- Please enter 0 if you want to delete more nodes or you can enter any other key to interrupt deleting valuess ...\n\n- Your decision: ");
		scanf("%i", &decision);
	}
	skip:
	printf("\n- Please enter the index for the value which you want to add and which is equal or bigger than index of the first node - (0) - and equal or lower then index of the last node - (%i) -  : ", current_List_of_int_Nodes->count_of_Nodes_in_List - 1);
	current_index = check_value_func();
	while(current_index < 0 || current_index > current_List_of_int_Nodes->count_of_Nodes_in_List)
	{
		printf("- You have entered incorrect index ...\n\n- Please enter correct index ...\n\n- Your index:");
		current_index = check_value_func();
	}
	printf("\n- Please enter the value for the your index - (%d) - : ", current_index);
	current_value = check_value_func();
	Insert_int_value_to_List_by_index_func(current_List_of_int_Nodes, current_value, current_index);
	Size_of_int_Node_List_func(current_List_of_int_Nodes);
	Print_int_Node_List_func(current_List_of_int_Nodes);
	printf("\n\n- Do you want to add more values with your index?\n\n");
	printf("\n- Please enter 0 if you want to add more values or you can enter any other key to interrupt adding values ...\n\n- Your decision: ");
	fflush(stdin);
	scanf("%i", &decision);
	while(decision == 0)
	{
		printf("\n- Please enter next index for the value which you want to add: ");
		current_index = check_value_func();
		while(current_index < 0 || current_index > current_List_of_int_Nodes->count_of_Nodes_in_List)
        {
		printf("- You have entered incorrect index ...\n\n- Please enter correct index ...\n\n- Your index:");
		current_index = check_value_func();
        }
		printf("\n- Please enter the value for the your index %d: ", current_index);
		current_value = check_value_func();
		Insert_int_value_to_List_by_index_func(current_List_of_int_Nodes, current_value, current_index);
		Size_of_int_Node_List_func(current_List_of_int_Nodes);
		Print_int_Node_List_func(current_List_of_int_Nodes);
		decision = 1;
		printf("\n- Please enter 0 if you want to add more values or you can enter any other key to interrupt adding values ...\n\n- Your decision: ");
		fflush(stdin);
		scanf("%i", &decision);
	}
	Size_of_int_Node_List_func(current_List_of_int_Nodes);
	Print_int_Node_List_func(current_List_of_int_Nodes);
	int first = 0;
	int last = current_List_of_int_Nodes->count_of_Nodes_in_List - 1;
	Quick_sorting_of_List_func(current_List_of_int_Nodes, first, last);
	Size_of_int_Node_List_func(current_List_of_int_Nodes);
	Print_int_Node_List_func(current_List_of_int_Nodes);
	Destroy_int_Node_List_func(current_List_of_int_Nodes);
	return 0;
}
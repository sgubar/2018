#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "fourth_lab.h"


int main(void)
{
	int current_value = 0;
	int current_index = 0;
	int decision = 1;
	int counter = 0;
	int_Node_List *current_Circle_List_of_int_Nodes = Create_Circle_int_Node_List_func();
	if(NULL == current_Circle_List_of_int_Nodes)
	{
		return 2023;
	}
	printf("- You have to fill current circle list by at least four values of integer numbers ...");
	while(counter <= 3)
	{
		printf("\n\n- Please enter value #(%i) for your circle list: ", counter);
		current_value = check_value_func();
		Add_int_value_to_Circle_List_func(current_Circle_List_of_int_Nodes, current_value);
		counter++;
	}
	Size_of_int_Node_List_func(current_Circle_List_of_int_Nodes);
	Print_int_Node_List_func(current_Circle_List_of_int_Nodes);
	printf("\n\n- Do you want to add more values to the list?\n\n");
	printf("- Please enter 0 if you want to add more values or you can enter any other key to interrupt entering values ...\n\n- Your decision: ");
	scanf("%i", &decision);
	while(decision == 0)
	{
		printf("\n- Please enter next value for the list: ");
		current_value = check_value_func();
		Add_int_value_to_Circle_List_func(current_Circle_List_of_int_Nodes, current_value);
		Size_of_int_Node_List_func(current_Circle_List_of_int_Nodes);
		Print_int_Node_List_func(current_Circle_List_of_int_Nodes);
		decision = 1;
		printf("\n- Please enter 0 if you want to add more values or you can enter any other key to interrupt entering values ...\n\n- Your decision: ");
		fflush(stdin);
		scanf("%i", &decision);
	}
	Size_of_int_Node_List_func(current_Circle_List_of_int_Nodes);
	Print_int_Node_List_func(current_Circle_List_of_int_Nodes);
	do
	{
		current_index += 2;
		Delete_int_Node_from_Circle_List_by_index_func(current_Circle_List_of_int_Nodes, current_index);
		Size_of_int_Node_List_func(current_Circle_List_of_int_Nodes);
        Print_int_Node_List_func(current_Circle_List_of_int_Nodes);
	}while(current_Circle_List_of_int_Nodes->count_of_Nodes_in_List >= 3);
	printf("\n------------------------------------------\n");
	Destroy_Circle_int_Node_List_func(current_Circle_List_of_int_Nodes);
	return 0;
}
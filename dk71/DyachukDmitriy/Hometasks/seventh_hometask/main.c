#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "hometask_7.h"

int main(void)
{
	int decision = 0;
	int value = 0;
	int *array_of_values = NULL;
	printf("\t\t- PROGRAM OF CREATING BINARY TREE -\n\n");
	BTNode *Root_Node = create_BTree_Node();
	printf("\n\n- Please define number of elements in your binary tree by integer value...\n\n- Your value: ");
	int num_of_elements = (check_value()) - 1;
	array_of_values = (int *)malloc(sizeof(int) * num_of_elements);
	printf("\n\n- Please enter an integer value for the root of your tree ...\n\n- Your value: ");
	Root_Node->Value = check_value();
	for(int i = 0; i < num_of_elements - 1; ++i)
	{
	    printf("\n\n- Enter next value for node in your binary tree ...\n\n- Your value: ");
		value = array_of_values[i] = check_value();
		add_BTree_Node_with_value(Root_Node, value);
	}
	print_BTree(Root_Node);
	BTNode *max_value_Node = find_max_min_values(Root_Node, 1);
	BTNode *min_value_Node = find_max_min_values(Root_Node, 0);
	printf("\n\n- The lowest value in your binary tree is (%i) ...", min_value_Node->Value);
	printf("\n\n- The largest value in your binary tree is (%i) ...", max_value_Node->Value);
	do
	{
		printf("\n\n - Please enter the value you want to find in your binary tree ...\n\n- Your value: ");
		value = check_value();
		BTNode *Node = find_value_in_BTree(Root_Node, value);
		if(Node != NULL)
		{
			printf("\n\n- Value which you search: %i",Node->Value);
			if(Node->Parent)
				printf("\n\n- Previous value: %i", Node->Parent->Value);
			else
				printf("\n\n- Your value is a root of your binary tree ...");
			if(Node->Left_Child)
				printf("\n\n- Lowest value %i", Node->Left_Child->Value);
			if(Node->Right_Child)
				printf("\n\n- Highest value: %i", Node->Right_Child->Value);
		}else
		{
			printf("\n\n- Value which you search does not exist in your binary tree ...");
		}
		printf("\n\n- Do you want to find more nodes in your binary tree?\n\n- Please enter '0' to continue searching nodes or any other key to interrupt searching ...\n\n- Your decision: ");
		scanf("%i", &decision);
		}while(decision == 0);
	while(decision == 0)
	{
		printf("\n\n - Please enter the value of node you want to delete in your binary tree ...\n\n- Your value: ");
		if((value = check_value()) == Root_Node->Value)
		{
			printf("\n\n- You can't delete root node ...\n\n- Please try again ...");
			continue;
		}
		BTNode *Node_for_delete = find_value_in_BTree(Root_Node, value);
		delete_BTree_Node(Node_for_delete);
		printf("\n\n- Do you want to delete more nodes from your binary tree?\n\n- Please enter '0' to continue deleting nodes or any other key to interrupt deleting ...\n\n- Your decision: ");
		scanf("%i", &decision);
	}
	print_BTree(Root_Node);
	max_value_Node = find_max_min_values(Root_Node, 1);
	min_value_Node = find_max_min_values(Root_Node, 0);
	printf("\n\n- The lowest value in your binary tree is (%i) ...", min_value_Node->Value);
	printf("\n\n- The largest value in your binary tree is (%i) ...", max_value_Node->Value);
	delete_BTree(Root_Node, array_of_values, num_of_elements);
	return 0;
}
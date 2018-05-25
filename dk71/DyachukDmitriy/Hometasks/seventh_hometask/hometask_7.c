#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include "hometask_7.h"

void print_BTree(BTNode *Root_Node)
{
	if(Root_Node)
	{
		printf("\n%i",Root_Node->Value);
		print_BTree(Root_Node->Left_Child);
		print_BTree(Root_Node->Right_Child);
	}
}

void delete_BTree_Node(BTNode *Node_for_delete)
{
	if(!Node_for_delete->Right_Child && !Node_for_delete->Left_Child)
	{
		if(Node_for_delete == Node_for_delete->Parent->Left_Child)
			Node_for_delete->Parent->Left_Child = NULL;
		else if(Node_for_delete == Node_for_delete->Parent->Right_Child)
			Node_for_delete->Parent->Right_Child = NULL;
	}
	else if(Node_for_delete->Right_Child || Node_for_delete->Left_Child)
	{
		if(Node_for_delete->Right_Child)
		{
			if(Node_for_delete == Node_for_delete->Parent->Left_Child)
				Node_for_delete->Parent->Left_Child = Node_for_delete->Right_Child;
			else if(Node_for_delete == Node_for_delete->Parent->Right_Child)
				Node_for_delete->Parent->Right_Child = Node_for_delete->Right_Child;
		}else if(Node_for_delete->Left_Child)
		{
			if(Node_for_delete == Node_for_delete->Parent->Left_Child)
				Node_for_delete->Parent->Left_Child = Node_for_delete->Left_Child;
			else if(Node_for_delete == Node_for_delete->Parent->Right_Child)
				Node_for_delete->Parent->Right_Child = Node_for_delete->Left_Child;
		}
	}else if(Node_for_delete->Right_Child && Node_for_delete->Left_Child)
	{
		BTNode *swap_Node = find_max_min_values(Node_for_delete->Left_Child, 1);
		Node_for_delete->Value = swap_Node->Value;
		delete_BTree_Node(swap_Node);
		return;
	}
	free(Node_for_delete);
}

BTNode *find_max_min_values(BTNode *Root_Node, int value)
{
	BTNode *Node = Root_Node;
	if(value == 0)
	{
		while(Node->Left_Child)
			Node = Node->Left_Child;
		return Node;
	}else if(value == 1)
	{
		while(Node->Right_Child)
			Node = Node->Right_Child;
		return Node;
	}
}

BTNode *find_value_in_BTree(BTNode *Root_Node, int value)
{
	BTNode *Node = Root_Node;
	while(Node)
	{
		if(value < Node->Value)
		{
			Node = Node->Left_Child;
			continue;
		}
		else if(value > Node->Value)
		{
			Node = Node->Right_Child;
			continue;
		}
		else
		{
			return Node;
		}
	}
	return NULL;
}


void add_BTree_Node_with_value(BTNode *Root_Node, int value)
{
	BTNode *added_BTree_Node = create_BTree_Node();
	if(added_BTree_Node != NULL)
	{
		added_BTree_Node->Value = value;
		BTNode *Parent_of_Node = Root_Node;
		while(Parent_of_Node)
		{
			if(value > Parent_of_Node->Value)
			{
				if(Parent_of_Node->Right_Child)
				{
					Parent_of_Node = Parent_of_Node->Right_Child;
					continue;
				}else
				{
					added_BTree_Node->Parent = Parent_of_Node;
					Parent_of_Node->Right_Child = added_BTree_Node;
					return;
				}
			}else if(value < Parent_of_Node->Value)
			{
				if(Parent_of_Node->Left_Child)
				{
					Parent_of_Node = Parent_of_Node->Left_Child;
					continue;
				}else
				{
					added_BTree_Node->Parent = Parent_of_Node;
					Parent_of_Node->Left_Child = added_BTree_Node;
					return;
				}
			}else if(value == Parent_of_Node->Value)
			{
				free(added_BTree_Node);
				return;
			}
		}
	}
}

BTNode *create_BTree_Node(void)
{
	BTNode *created_BTree_Node = (BTNode *)malloc(sizeof(BTNode));
	if(created_BTree_Node != NULL)
	{
		created_BTree_Node->Value = 0;
		created_BTree_Node->Left_Child = NULL;
		created_BTree_Node->Right_Child = NULL;
		created_BTree_Node->Parent = NULL;
	}
	return created_BTree_Node;
}

void delete_BTree(BTNode *Root_Node, int *array_of_values, int num_of_elements)
{
	for(int i = num_of_elements - 1; i >= 0; --i)
	{
		BTNode *Node_for_delete = find_value_in_BTree(Root_Node, array_of_values[i]);
		if(Node_for_delete)
			delete_BTree_Node(Node_for_delete);
		else
			continue;
	}
	free(Root_Node);
}

int check_value(void)
{
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

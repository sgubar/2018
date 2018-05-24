#include "libs.h"

int choose_a_num_of_act()
{
	int canoa_tmp;
	
	printf("1 - Add element to tree\n2 - Find an element\n3 - Print tree\n4 - Delete an element from tree\n5 - Get a number of elements in tree\n6 - Add some random numbers to tree\n7 - Delete tree and exit\n");
	
	printf("**Choose a number of action: ");
	scanf("%d", &canoa_tmp);
	
	while(canoa_tmp < 1 || canoa_tmp > 7)
	{
		printf("\n***->Invalid number of action<-:(\nPlease try again.\n");
		printf("**Choose a number of action: ");
		scanf("%d", &canoa_tmp);
	}
	return canoa_tmp;
}

void add_element_to_tree(pbin_tree aetl_tree)
{
	float aetl_data;
	
	printf("Enter a data: ");
	scanf("%f", &aetl_data);
	
	add_el(aetl_tree, aetl_data);
	
	printf("\n*Element has added to list successfully:)\n\n");
}

void find_an_element_in_tree(pbin_tree faeit_tree)
{
	float faeit_data;
	
	printf("Enter a data for search: ");
	scanf("%f", &faeit_data);
	
	if(find_el(faeit_tree, faeit_data) == 1)
		printf("\n*Element has found in tree successfully:)\n\n");
		else
			printf("\n*Element has not found in tree:(\n\n");	
}

void print_the_tree(pbin_tree ptt_tree)
{
	printf("\nThe tree:\n");
	print_tree(ptt_tree->root);
	printf("\n");
}

void delete_an_element_from_tree(pbin_tree daeft_tree)
{
	float faeft_data;
	
	printf("Enter a data for deleting: ");
	scanf("%f", &faeft_data);
	
	if(remove_node(daeft_tree, faeft_data) == 1)
		printf("\n*Element has deleted from tree successfully:)\n\n");
		else
			printf("\n*Element has not found in tree:(\n\n");	
}

void number_of_elements_in_tree(pbin_tree noeit_tree)
{
	printf("\nA number of elements in tree: %d\n", noeit_tree->size);
}

void add_random_numbers_to_tree(pbin_tree arntt_tree)
{
	int arntt_ammount;
	printf("**Enter an amount of random numbers: ");
	scanf("%d", &arntt_ammount);
	
	while(arntt_ammount < 1)
	{
		printf("\n***->Invalid amount<-:(\nPlease try again.\n");
		printf("**Enter an amount of random numbers: ");
		scanf("%d", &arntt_ammount);
	}
	
	for(int arntt_i = 0; arntt_i < arntt_ammount; arntt_i++) 
		add_el(arntt_tree, (float)(rand()%64));
	
	printf("\n*A random elements has added to tree successfully:)\n\n");
}

void delete_the_tree(pbin_tree dtt_tree)
{
	delete_tree(dtt_tree);
	printf("*The binary tree has deleted succesfuly:)\nGood luck:))");
}
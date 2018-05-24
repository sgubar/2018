#include "libs.h"

int main(void)
{
	pbin_tree atree = create_tree();
	printf("\n***A binary tree has created successfully:)\n\n");
	
	int number_of_act;
	
	while(1)
	{
		number_of_act = choose_a_num_of_act();
		
		switch(number_of_act)
		{
			case 1:
				add_element_to_tree(atree);
			break;
			
			case 2:
				find_an_element_in_tree(atree);
			break;
			
			case 3:
				print_the_tree(atree);
			break;
			
			case 4:
				delete_an_element_from_tree(atree);
			break;
			
			case 5:
				number_of_elements_in_tree(atree);
			break;
			
			case 6:
				add_random_numbers_to_tree(atree);
			break;
			
			case 7:
				delete_the_tree(atree);
				return 0;
			break;
		}
	}
}

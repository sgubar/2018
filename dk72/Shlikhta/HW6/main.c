#include "libs.h"

#include "menu.h"

#include "hw_6.h"

int main(void)
{
	plist alist = create_list();
	int num_of_act;
	
	while(1)
	{
		num_of_act = choose_a_num_of_act();
	
		switch(num_of_act)
		{
			case 1:
				add_element_to_list(alist);
			break;
			
				case 2:
					sort_list(alist);
				break;
		
			case 3:
				print_the_list(alist);
			break;
		
				case 4:
					delete_an_element_from_list(alist);
				break;
		
			case 5:
				printf("\nA size of list is: %d elements\n\n", alist->size); //print a size of list
			break;
		
				case 6:
					insert_an_element_to_list(alist);
				break;
		
			case 7:
				print_an_element(alist);
			break;
		
				case 8:
					add_random_numbers_to_list(alist);
				break;
			
			case 9:
				delete_list(alist);
				printf("The list has deleted succesfuly:)\nGood luck:))");
				return 1;
			break;
		}
	}
	
	
	return 0;
}

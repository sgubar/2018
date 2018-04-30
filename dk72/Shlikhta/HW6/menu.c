#include "menu.h"

int choose_a_num_of_act()
{
	int canoa_tmp;
	
	printf("1 - Add element to list\n2 - Sort list\n3 - Print list\n4 - Delete an element from list\n5 - Get a size of list\n6 - Insert an element to list\n7 - Print an element\n8 - Add some random numbers to list\n9 - Delete list and exit\n");
	
	printf("**Choose a number of action: ");
	scanf("%d", &canoa_tmp);
	
	while(canoa_tmp < 1 || canoa_tmp > 9)
	{
		printf("\n***->Invalid number of action<-:(\nPlease try again.\n");
		printf("**Choose a number of action: ");
		scanf("%d", &canoa_tmp);
	}
	return canoa_tmp;
}

void add_element_to_list(plist aetl_list)
{
	float aetl_data;
	
	printf("Enter a data: ");
	scanf("%f", &aetl_data);
	
	add_el(aetl_list, aetl_data);
	
	printf("\n*Element has added to list succesfuly:)\n\n");
}

void sort_list(plist sl_list)
{
	shell_sort(sl_list);
	
	printf("\n*The list has sorted succesfuly:)\n\n");
}

void print_the_list(plist ptl_list)
{
	printf("\nThe list: ");
	print_list(ptl_list);
	printf("\n");
}

void delete_an_element_from_list(plist daefl_list)
{
	if(daefl_list->size == 0)
	{
		printf("\n***Err. The list don't have an elements\n");
		return;
	}
	int daefl_ind;
	printf("**Enter an index of element which you want to delete(max = %d): ", daefl_list->size - 1);
	scanf("%d", &daefl_ind);
	
	while(daefl_ind < 0 || daefl_ind > daefl_list->size - 1)
	{
		printf("\n***->Invalid index<-:(\nPlease try again.\n");
		printf("**Enter an index of element which you want to delete(max = %d): ", daefl_list->size - 1);
		scanf("%d", &daefl_ind);
	}
	
	delete_el(daefl_list, daefl_ind);
	
	printf("\n*Element has deleted from list succesfuly:)\n\n");
}

void insert_an_element_to_list(plist iaetl_list)
{
	int iaetl_ind, iaetl_tmp;
	float iaetl_data;
	
	if(iaetl_list->size == 0)
		iaetl_tmp = 0;
		else
			iaetl_tmp = iaetl_list->size-1;
	
	printf("**Enter an index of element which you want to insert(max = %d): ", iaetl_tmp);
	scanf("%d", &iaetl_ind);
	
	while(iaetl_ind < 0 || iaetl_ind > iaetl_tmp)
	{
		printf("\n***->Invalid index<-:(\nPlease try again.\n");
		printf("**Enter an index of element which you want to insert(max = %d): ", iaetl_tmp);
		scanf("%d", &iaetl_ind);
	}
	
	printf("\n**Enter a data: ");
	scanf("%f", &iaetl_data);
	
	insert_el(iaetl_list, iaetl_ind, iaetl_data);
	
	printf("\n*Element has inserted to list succesfuly:)\n\n");
}

void print_an_element(plist pal_list)
{
	if(pal_list->size == 0)
	{
		printf("\n***Err. The list don't have an elements\n");
		return;
	}
	int pal_ind;
	printf("**Enter an index of element which you want to print(max = %d): ", pal_list->size - 1);
	scanf("%d", &pal_ind);
	
	while(pal_ind < 0 || pal_ind > pal_list->size - 1)
	{
		printf("\n***->Invalid index<-:(\nPlease try again.\n");
		printf("**Enter an index of element which you want to print(max = %d): ", pal_list->size - 1);
		scanf("%d", &pal_ind);
	}
	
	printf("\n\n*The element with index %d is %.2f\n\n",pal_ind, get_el_data(pal_list, pal_ind));
}

void add_random_numbers_to_list(plist arntl_list)
{
	int arntl_ammount;
	printf("**Enter an amount of random numbers: ");
	scanf("%d", &arntl_ammount);
	
	while(arntl_ammount < 1)
	{
		printf("\n***->Invalid amount<-:(\nPlease try again.\n");
		printf("**Enter an amount of random numbers: ");
		scanf("%d", &arntl_ammount);
	}
	
	for(int arntl_i = 0; arntl_i < arntl_ammount; arntl_i++) 
		add_el(arntl_list, (float)(rand()%128 - 64));
	
	printf("\n*A random elements has added to list succesfuly:)\n\n");
}

void delete_the_list(plist dtl_list)
{
	delete_list(dtl_list);
	printf("*The list has deleted succesfuly:)\nGood luck:))");
}
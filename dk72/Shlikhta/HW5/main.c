#include "dk_arr_rect.h"

int main(void)
{
	int arr_size, num_of_act;
	float f_sq;
	
	printf("Enter a number elements of array: ");
	scanf("%d", &arr_size);
	
	//entering and checking for valid size of array
	while(arr_size < 1)
	{
		printf("#ERR n_arr < 1 :(\n");
		
		printf("Enter a number elements of array: ");
		scanf("%d", &arr_size);
	}
	
	prect_arr rect = create_arr(arr_size); //creating of array
	printf("###Array has created succesfuly:)\n");
	rect->count = 0;
	
	while(1)
	{
		printf("1 - Add element to array\n2 - Sort array\n3 - Find an element\n4 - write in JSON\n5 - Delete array\n");
		printf("Choose a number of action: ");
		scanf("%d", &num_of_act);
		
		while(num_of_act < 1 || num_of_act > 5)
		{
			printf("\n*->Invalid number of action<-:(\nPlease try again.\n");
			printf("Choose a number of action: ");
			scanf("%d", &num_of_act);
		}
			
		switch(num_of_act)
		{
			case 1:
				if(rect->count == rect->size)
				{
					printf("*Array is full:)\n");
					break;
				}
				rect->cell[rect->count] = enter_data(); //writing data to cell
				rect->count++;
			break;
			
			case 2:
					printf("\nSorting \\...\n");
					shell_sort(rect); //sorting array
					printf("*Array has sorted:)\n\n");
			break;
			
			case 3:
				printf("Enter a square of element which I must find: ");
				scanf("%f", &f_sq);
				while(f_sq < 0)
				{
					printf("*->Invalid square<-:(\nPlease try again.\n");
					printf("Enter a square of element which I must find: ");
					scanf("%f", &f_sq);
				}
				shell_sort(rect);
				bin_search(rect, f_sq);
				
			break;
			
			case 4:
				write_in_JSON(rect, "1");
				printf("\nWriting to file succesfuly:))\n\n");
			break;
			
			case 5:
				printf("\nDeleting \\...\n");
				delete_arr(rect); //deleting array
				printf("Good luck :)\n");
				return 0;
			break;
		}	
	}
	
	return 0;
}

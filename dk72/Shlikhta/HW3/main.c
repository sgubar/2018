#include "dk_arr_rect.h"

int main(void)
{
	int arr_size, num_of_cell;
	
	printf("Enter a number elements of array: ");
	scanf("%d", &arr_size);
	
	while(arr_size < 1)
	{
		printf("#ERR n_arr < 1 :(\n");
		
		printf("Enter a number elements of array: ");
		scanf("%d", &arr_size);
	}
	
	prect_arr rect = create_arr(arr_size);
	printf("###Array has created succesfuly:)\n");
	
	while(1)
	{
		int noa = num_of_act();
	
		switch(noa)
		{
			case 1: //write to free cell
				rect->count = 0;
				
				while(rect->free_cell[rect->count] != 1) rect->count++;
				
				rect->cell[rect->count] = enter_data();
				rect->free_cell[rect->count] = 0;
				rect->count = 0;
				printf("Element has written to array succesfuly:)");
			
			break;
		
			case 2: //write to my cell
				num_of_cell = fnum_of_cell(rect->size);
				rect->cell[num_of_cell] = enter_data();
				rect->free_cell[num_of_cell] = 0;
				printf("Element has written to your cell in array succesfuly:)");
			break;
		
			case 3: //write array to file into JSON
				write_in_JSON(rect, "b");
				printf("Array has written to file in JSON succesfuly:)");
			break;
		
			case 4: //delete array
				delete_arr(rect);
				printf("Good luk:))");
				return 1;
			break;
		
		}
	}
	
	return 0;
}

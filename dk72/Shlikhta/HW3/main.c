#include "dk_arr_rect.h"

int main(void)
{
	int arr_size, num_of_cell;
	
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
	
	while(1)
	{
		int noa = num_of_act(); //entering a number of action
	
		switch(noa)
		{
			case 1: //write to free cell
				rect->count = 0;
				
				while(rect->free_cell[rect->count] != 1) rect->count++; //search a free cell
				
				rect->cell[rect->count] = enter_data(); //writing data to cell
				rect->free_cell[rect->count] = 0; //check that this cell isn't free
				rect->count = 0;
				printf("Element has written to array succesfuly:)");
			
			break;
		
			case 2: //write to my cell
				num_of_cell = fnum_of_cell(rect->size); //entering an index of cell
				rect->cell[num_of_cell] = enter_data(); //writing data to cell
				rect->free_cell[num_of_cell] = 0; //check that this cell isn't free
				printf("Element has written to your cell in array succesfuly:)");
			break;
		
			case 3: //write array to file into JSON
				write_in_JSON(rect, "b");
				printf("Array has written to file in JSON succesfuly:)");
			break;
		
			case 4: //delete array and exit
				delete_arr(rect);
				printf("Good luck:))");
				return 1;
			break;
		
		}
	}
	
	return 0;
}

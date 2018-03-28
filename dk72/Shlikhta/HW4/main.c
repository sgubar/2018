#include "dk_arr_rect.h"

int main(void)
{
	int arr_size;
	
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
	
	//entering data to array
	for(rect->count = 0; rect->count < rect->size; rect->count++)
	{
		printf("%dth figure:", rect->count+1);
		rect->cell[rect->count] = enter_data(); //writing data to cell
		rect->square[rect->count] = calc_square(rect->cell[rect->count]);
	}

	printf("Array is full:)\n");
	
	write_in_JSON(rect, "before_sort"); //writing array to file before sort
	
	printf("Sorting \\...\n");
	
	insertion_sort(rect); //sorting array
	
	printf("Array has sorted:)\n");
	
	write_in_JSON(rect, "after_sort"); //writing array to file after sort
	
	delete_arr(rect); //deleting array

	printf("Good luck :0\n");
	
	return 0;
}

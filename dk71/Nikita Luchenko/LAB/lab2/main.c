#include "dk_tools.h"

#include <stdio.h>


int main(void)
{
	int ar_size; 
	ar_size = enter_arr_size();
	double start;
	
	int *array = malloc(sizeof(int)*ar_size); 
	
	read_from_file(array, "text"); 

		start = clock();
	 bubbleSort(array, ar_size);
		printf("Time of bubble sorting is %.5f sec\n", (clock() - start) / CLOCKS_PER_SEC);
	write_to_file(array, ar_size, "bubble");
		
		
		start = clock();
	insertionSort(array, ar_size);
		printf("Time of insertion sorting is %.5f sec\n", (clock() - start) / CLOCKS_PER_SEC); 
	write_to_file(array, ar_size, "insertion");
	

		start = clock();
	selectionSort(array, ar_size); 
		printf("Time of selection sorting is %.5f sec\n", (clock() - start) / CLOCKS_PER_SEC); 
	write_to_file(array, ar_size, "selection"); 
	
	return 0;
}

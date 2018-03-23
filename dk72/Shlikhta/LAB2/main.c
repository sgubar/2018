#include "l2.h"

int main(void)
{
	int ar_size = enter_arr_size(); // entering a size of future array
	
	int array[ar_size]; //creating an array
	
	ent_data_to_arr(array, ar_size); //entering data to array
	write_to_file(array, ar_size, "bubble_b"); // writing to file an array before sorting
		double start = clock();
	bubble_sort(array, ar_size); // sorting an array
		printf("Time of bubble sorting is %.4lf sec\n", (clock() - start) / CLOCKS_PER_SEC); //printing a time of making sorting
	write_to_file(array, ar_size, "bubble_a"); // writing to file an array after sorting
		
	
	ent_data_to_arr(array, ar_size);//entering new data to array
	write_to_file(array, ar_size, "insertion_b"); // writing to file an array before sorting
		start = clock();
	insertion_sort(array, ar_size); // sorting an array
		printf("Time of insertion sorting is %.4lf sec\n", (clock() - start) / CLOCKS_PER_SEC); //printing a time of making sorting
	write_to_file(array, ar_size, "insertion_a"); // writing to file an array after sorting
		
	
	ent_data_to_arr(array, ar_size); //entering new data to array	
	write_to_file(array, ar_size, "chousen_b"); // writing to file an array before sorting
		start = clock();
	chousen_sort(array, ar_size); // sorting an array
		printf("Time of chousen sorting is %.4lf sec\n", (clock() - start) / CLOCKS_PER_SEC); //printing a time of making sorting
	write_to_file(array, ar_size, "chousen_a"); // writing to file an array after sorting
		
	
	return 0;
}

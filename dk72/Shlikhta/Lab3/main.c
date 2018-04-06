#include "l2.h"


int main(void)
{
	int ar_size = enter_arr_size(); // entering a size of future array
	
	int search, b;
	
	int *array = malloc(sizeof(int)*ar_size); //creating an array
	
	ent_data_to_arr(array, ar_size); //entering data to array
	write_to_file(array, ar_size, "Quick_b"); // writing to file an array before sorting
		double start = clock();
	quick_sort(array, 0, ar_size-1); // sorting an array
		printf("Time of Shell sorting is %.4lf sec\n", (clock() - start) / CLOCKS_PER_SEC); //printing a time of making sorting
	write_to_file(array, ar_size, "Quick_a"); // writing to file an array after sorting
	
	while(1)
	{
		
		printf("Enter data for search "); //entering a data for search
		scanf("%s", &search);
			start = clock();
		b = bin_search(array, ar_size, search);	//searching a data
			printf("Time of binary search is %f sec\n", (clock() - start) / CLOCKS_PER_SEC); //printing a time of making sorting
		printf("********************************************************%d\n", b);//print the result of search 1 - element has found 0 - element hasn't found
	}

	return 0;
}

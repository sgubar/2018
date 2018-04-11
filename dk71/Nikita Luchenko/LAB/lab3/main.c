#include "dk_tools.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
	int arr_size; 
	arr_size = enter_arr_size();
	double start;
	char search;
	int position;
	char *array = malloc(sizeof(char)*arr_size); 
	
	read_from_file(array, "text"); 
	start = clock();
	quick_sort(array, 0, arr_size-1);
	printf("Time of quick sorting is %.5f sec\n", (clock() - start) / CLOCKS_PER_SEC);
	write_to_file(array, arr_size, "quick");
		
	
	while(1)
		{
		printf("\tEnter the letter:"); 
		scanf("\n%c", &search);
		start = clock();
		position = line_search(array, search, arr_size);
		printf("\n\nTime of search = %.10f sec\n", (clock() - start) / CLOCKS_PER_SEC); 
		printf("Position of a letter = %d\n\n", position);
		}
	return 0;
}

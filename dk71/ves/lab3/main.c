#define _CRT_SECURE_NO_WARNINGS
#include "laba.h"

int main(void) {

	int size_ar = size_f();
	int  a;
	int search;
	int start_t, end_t;
	char *array = malloc(sizeof(int)*size_ar); //creating an array
	enter_array(array, size_ar);
    write_to_file(array, size_ar, "sort");
	start_t = clock();
	QuickSort(array, 0, size_ar - 1);
	end_t = clock();
	printf("time QuickSort: %d s\n", end_t - start_t);
	write_to_file(array, size_ar, "sortt");
	while (1)
	{

		printf("Enter data for search "); //entering a data for search
		scanf("%s", &search);
		start_t = clock();
		a = bin_search(array, size_ar, search);	//searching a data
		end_t = clock();
		printf("Time of binary search is %d s\n", end_t - start_t); //printing a time of making sorting
		printf("%d\n", a);//print the result of search 1 - element has found 0 - element hasn't found
	}
		system("PAUSE");
	return 0;
}
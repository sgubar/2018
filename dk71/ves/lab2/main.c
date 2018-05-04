#define _CRT_SECURE_NO_WARNINGS
#include "laba.h"

int main(void) {

	int size_ar = size_f();
	int start_t, end_t;
	char *array = malloc(sizeof(int)*size_ar); //creating an array
	enter_array(array, size_ar);
	write_to_file(array, size_ar, "bub_arr");
	start_t = clock();
	buble_sort(array, size_ar);
	end_t = clock();
	printf("time buble_sort: %d ms\n\n\n", end_t - start_t);
	write_to_file(array, size_ar, "bub_sort");

	enter_array(array, size_ar);
	write_to_file(array, size_ar, "is_arr");
	start_t = clock();
	insertion_sort(array, size_ar);
	end_t = clock();
	printf("time insertion_ort: %d ms\n\n\n", end_t - start_t);
	write_to_file(array, size_ar, "is_sort");

	enter_array(array, size_ar);
	write_to_file(array, size_ar, "sc_arr");
	start_t = clock();
	sort_chose(array, size_ar);
	end_t = clock();
	printf("time insertion_ort: %d ms\n\n\n", end_t - start_t);
	write_to_file(array, size_ar, "sc_sort");

	system("PAUSE");
	return 0;
}
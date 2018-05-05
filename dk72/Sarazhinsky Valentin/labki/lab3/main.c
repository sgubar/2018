#include <stdio.h>
#include <stdlib.h>
#include "lab2.h"
#include "lab3.h"

int main(int argc, char *argv[]) {
	
	float TimeStart,TimeStop;
	int size=0, number=0;
	char search_value[2];
	size = enter_size_array();
	char *arr = malloc (sizeof (char) * (size));
	enter_data_to_array(arr, size);
	write_array_in_fail(arr, size, "lab3.txt");
	char * array = loadFile("lab3.txt" , size);

	printf("Sorting.....\n");

	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	shellSort(array, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nSorting shell: %f secund!\n", TimeStop-TimeStart);
	
	write_array_in_fail(array, size, "lab3_res.txt");	
	
	printf("\nEnter the value to search: ");
	scanf("%s",&search_value[0]);
	
	TimeStart = clock()/(float)CLOCKS_PER_SEC;
	number = binary_search(array, search_value, size);
	TimeStop = clock()/(float)CLOCKS_PER_SEC;
	printf("\nBinary search: %f secund!\n", TimeStop-TimeStart);
	if(number == -1){
		printf("value is not found \n");
	} else {
		printf("value is found! index : %d",number);
	}
	
	free(array);
	free(arr);

	return 0;
}

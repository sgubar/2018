#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dk_tool.h"

int main() {
	double start;
	char str [100]= "";
	int count = read("read.txt", str);
	  
	start = clock();
	bubbleSort(str, count);
	printf("%s\n", str);
	printf("Time of bubble sorting is %.5f sec\n\n", (clock() - start) / CLOCKS_PER_SEC);
	  
	start = clock();
	count = read("read.txt", str);
	selectionSort(str, count);
	printf("%s\n\n", str);
	printf("Time of selection sorting is %.5f sec\n\n", (clock() - start) / CLOCKS_PER_SEC);
	  
	start = clock();
	count = read("read.txt", str);
	insertionSort(str, count);
	printf("%s\n\n", str);
	printf("Time of insertion sorting is %.5f sec\n\n", (clock() - start) / CLOCKS_PER_SEC);
}

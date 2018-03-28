#ifndef dk_tools
#define dk_tools

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int enter_arr_size();

void write_to_file(int *wtf_arr, int size, char wtf_tname[10]);

void read_from_file(int *rff_arr, char rff_tname[10]);

void bubbleSort(int *array, int aSize);

void insertionSort(int *array, int aSize);

void selectionSort(int *array, int aSize);



#endif

#ifndef dk_tools
#define dk_tools
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int enter_arr_size();

void write_to_file(char *wtf_arr, int size, char wtf_tname[10]);

void read_from_file(char *rff_arr, char rff_tname[10]);

void swap(char *one, char *two);

void quick_sort(char *array, int first, int last);

int line_search(char *array, char key, int size);
#endif

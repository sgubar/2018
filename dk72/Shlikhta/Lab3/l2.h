#ifndef L2_h
#define L2_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int enter_arr_size();

void ent_data_to_arr(int *edta_arr, int edta_size);

void swap(int *a, int *b);

void write_to_file(int *wtf_arr, int wtf_size, char wtf_tname[10]);

void read_from_file(char rff_tname[10]);

//void shell_sort(int *ss_arr, int ss_size);

int bin_search(int *bs_arr, int bs_size, int bs_el);

void quick_sort(int *qs_arr, int first, int last);


#endif
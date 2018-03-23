#ifndef L2_h
#define L2_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int enter_arr_size();

int ent_data_to_arr1();

void ent_data_to_arr(int *edta_arr, int edta_size);

void bubble_sort(int *bs_arr, int bs_size);

void swap(int *a, int *b);

void write_to_file(int *wtf_arr, int wtf_size, char wtf_tname[10]);

void read_from_file(char rff_tname[10]);

void insertion_sort(int *is_arr, int is_size);

void chousen_sort(int *cs_arr, int cs_size);

int find_min(int *fm_arr, int fm_min_broad, int fm_max_board);


#endif